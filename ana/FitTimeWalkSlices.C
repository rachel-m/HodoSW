// rmontgom@jlab.org - 08/21
// macro to fit tot v le time
// will be used for all tdc channels simultaneously
// uses fitslicey to do the fit
#include <TROOT.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <iostream>
#include <fstream>
#include <TMath.h>
#include <TH1.h>
#include <TH1D.h>
#include <TH2.h>
#include <TF1.h>
#include <TF2.h>
#include <TFile.h>
#include <TTree.h>
#include <TChain.h>
#include <TCanvas.h>
#include <TLegend.h>

const Int_t nTdc = 180;
const Int_t nBarsTDC = 90;
const Int_t nBarsADC = 32;
const Double_t ADCCUT = 100.0;

const TString REPLAYED_DIR = "/w/work0/home/rachel/HallA/BB_Hodo/cosmicdata/replayed";
const TString ANALYSED_DIR = "/w/work0/home/rachel/HallA/BB_Hodo/cosmicdata/analysisout";

namespace Thodo {
  // this assumes one tdc hit per bar was selected in sbsoffline(!)
  Int_t NdataTdcBar;
  Double_t TDCBar[nBarsTDC];
  Int_t NdataTotL;
  Double_t TDCTotL[nBarsTDC];
  Int_t NdataTotR;
  Double_t TDCTotR[nBarsTDC];
  Int_t NdataLeL;
  Double_t TDCLeL[nBarsTDC];
  Int_t NdataLeR;
  Double_t TDCLeR[nBarsTDC];
  Int_t NdataAdcBar;
  Double_t ADCBar[nBarsADC];
  Int_t NdataAdcL;
  Double_t ADCValL[nBarsADC];
  Int_t NdataAdcR;
  Double_t ADCValR[nBarsADC];
  Int_t ADCBarOff[nBarsADC];
};

TChain *T = 0;

using namespace std;

void FitTimeWalkSlices(const TString InFile="bbhodo_306_1000000", Int_t nevents=-1,
		       Int_t DoFit=0,
		       Int_t CutADC=0, Double_t Fitmin=-999., Double_t Fitmax=-999.){
  // InFile is the input file without absolute path and without .root suffix
  // nevents is how many events to analyse, -1 for all
  // DoFit==1 means it will try to fit tot v le and write out txt file of results
  // CutADC==1 will demand a hit above pedestal if this data file had adc info
  // Fitmin and Fitmax are start and end limits for linear fit to tot v le


  //========================================================= Get data from tree
  if(!T) { 
    TString sInFile = REPLAYED_DIR + "/" + InFile + ".root";
    cout << "Adding " << sInFile << endl;
    T = new TChain("T");
    T->Add(sInFile);
    
    // disable all branches
    T->SetBranchStatus("*",0);
    // enable branches
    T->SetBranchStatus("bb.hodotdc.*",1);
    T->SetBranchAddress("bb.hodotdc.tdcbarid",Thodo::TDCBar);
    T->SetBranchAddress("bb.hodotdc.L.tot",Thodo::TDCTotL);
    T->SetBranchAddress("bb.hodotdc.R.tot",Thodo::TDCTotR);
    T->SetBranchAddress("bb.hodotdc.L.le",Thodo::TDCLeL);
    T->SetBranchAddress("bb.hodotdc.R.le",Thodo::TDCLeR);
    if(CutADC==1){
      T->SetBranchStatus("bb.hodoadc.*",1);
      T->SetBranchAddress("bb.hodoadc.adcbarid",Thodo::ADCBar);
      T->SetBranchAddress("bb.hodoadc.L.ap",Thodo::ADCValL);
      T->SetBranchAddress("bb.hodoadc.R.ap",Thodo::ADCValR);
      T->SetBranchAddress("bb.hodoadc.adcbaroff",Thodo::ADCBarOff);
    }

    // enable vector size branches
    T->SetBranchAddress("Ndata.bb.hodotdc.tdcbarid",&Thodo::NdataTdcBar);
    T->SetBranchAddress("Ndata.bb.hodotdc.L.tot",&Thodo::NdataTotL);
    T->SetBranchAddress("Ndata.bb.hodotdc.R.tot",&Thodo::NdataTotR);   
    T->SetBranchAddress("Ndata.bb.hodotdc.L.le",&Thodo::NdataLeL);
    T->SetBranchAddress("Ndata.bb.hodotdc.R.le",&Thodo::NdataLeR);    
    if(CutADC==1){
      T->SetBranchStatus("Ndata.bb.hodoadc.*",1);
      T->SetBranchAddress("Ndata.bb.hodoadc.adcbarid",&Thodo::NdataAdcBar);
      T->SetBranchAddress("Ndata.bb.hodoadc.L.ap",&Thodo::NdataAdcL);
      T->SetBranchAddress("Ndata.bb.hodoadc.R.ap",&Thodo::NdataAdcR); 
    }
  }//setting tree
  
  
  
  //========================================================= Check no of events
  Int_t Nev = T->GetEntries();
  cout << "N entries in tree is " << Nev << endl;
  Int_t NEventsAnalysis;
  if(nevents==-1) NEventsAnalysis = Nev;
  else NEventsAnalysis = nevents;
  cout << "Running analysis for " << NEventsAnalysis << " events" << endl;
  

  
  //==================================================== Create output root file
  // root file for viewing fits
  TString outrootfile = ANALYSED_DIR + "/LEFits_" + InFile + ".root";
  TFile *f = new TFile(outrootfile, "RECREATE");


  
  //==================================================== Check the bar offset
  // run 311 offset 64
  // run 307 offset 32
  // run 306 offset 0
  T->GetEntry(0);
  Int_t adcbarstart = 0;//Thodo::ADCBarOff[0];
  cout << "adcbarstart " << adcbarstart << endl;



  //===================================================== Histogram Declarations
  // number of histo bins
  Int_t NTotBins = 80;//200;
  Double_t TotBinLow = 0.;
  Double_t TotBinHigh = 400.;
  Int_t NLEBins = 120;
  Double_t LEBinLow = -800.0;//-100.;
  Double_t LEBinHigh = 0.0;//100.;

  // TOT vs LE histos
  TH2F *hLeVTOTL[nBarsTDC];
  TH2F *hLeVTOTR[nBarsTDC];
  for(Int_t bar=0; bar<(nBarsTDC); bar++){
    hLeVTOTL[bar] = new TH2F(TString::Format("hLeVTOT_Bar%d_L",bar),
			     TString::Format("hLeVTOT_Bar%d_L",bar),
			     NTotBins, TotBinLow, TotBinHigh,
			     NLEBins, LEBinLow, LEBinHigh
			     );
    hLeVTOTR[bar] = new TH2F(TString::Format("hLeVTOT_Bar%d_R",bar),
			     TString::Format("hLeVTOT_Bar%d_R",bar),
			     NTotBins, TotBinLow, TotBinHigh,
			     NLEBins, LEBinLow, LEBinHigh
			     );
  }

  // adc histos to check if cutting on adc
  // number of adc bins
  Int_t NAdcBins = 100;//4096;
  Double_t AdcBinLow = 0.;
  Double_t AdcBinHigh = 800;//4095.;
  TH1F *hADCL[nBarsADC];
  TH1F *hADCR[nBarsADC];
  for(Int_t bar=0; bar<nBarsADC; bar++){
    Int_t b = adcbarstart+bar;
    hADCL[bar] = new TH1F(TString::Format("hADC_Bar%d_L",b),
			  TString::Format("hADC_Bar%d_L",b),
			      NAdcBins, AdcBinLow, AdcBinHigh);
    hADCR[bar] = new TH1F(TString::Format("hADC_Bar%d_R",b),
			      TString::Format("hADC_Bar%d_R",b),
			      NAdcBins, AdcBinLow, AdcBinHigh);
  }



  //================================================================= Event Loop
  // variables outside event loop
  Int_t EventCounter = 0;

  // event loop start
  for(Int_t event=0; event<NEventsAnalysis; event++){
    
    T->GetEntry(event);
    // cout << "event " << event << endl;
    EventCounter++;
    if (EventCounter % 100000 == 0) cout <<
				      EventCounter << "/" <<
				      NEventsAnalysis << endl;
    for(Int_t tdc=0; tdc<(Int_t)Thodo::NdataTdcBar; tdc++){
      Int_t tdcbar = Thodo::TDCBar[tdc];
      if(CutADC==1){
	for(Int_t adcbar=0; adcbar<nBarsADC; adcbar++){
	  Int_t bar = adcbarstart+adcbar;
	  if(bar==tdcbar){
	    if(Thodo::ADCValL[adcbar]>=ADCCUT){
	      hLeVTOTL[tdcbar]->Fill(Thodo::TDCTotL[tdc],Thodo::TDCLeL[tdc]);
	      hADCL[adcbar]->Fill(Thodo::ADCValL[adcbar]);
	    }
	    if(Thodo::ADCValR[adcbar]>=ADCCUT){
	      hLeVTOTR[tdcbar]->Fill(Thodo::TDCTotR[tdc],Thodo::TDCLeR[tdc]);
	      hADCR[adcbar]->Fill(Thodo::ADCValR[adcbar]);
	    }
	  }//if bar matches
	}//adc bar loop
      }// adc cut
      else if(CutADC!=1){
	hLeVTOTL[tdcbar]->Fill(Thodo::TDCTotL[tdc],Thodo::TDCLeL[tdc]);
	hLeVTOTR[tdcbar]->Fill(Thodo::TDCTotR[tdc],Thodo::TDCLeR[tdc]);
      }//else
    }// tdc bar loop
    
    
  }// event loop



  //==================================================================== Fitting
  if(DoFit==1){
    
    // parameters outside loop below
    f->cd();
    f->mkdir("Fits");
    f->cd("Fits");
    Int_t StatCut = 10; //how many counts in y-proj we want for fit
    TF1 *fLeft[nBarsTDC];
    TF1 *fRight[nBarsTDC];
    Double_t par0L[nBarsTDC];
    Double_t par1L[nBarsTDC];
    Double_t par0R[nBarsTDC];
    Double_t par1R[nBarsTDC];
    for(Int_t tdcbar=0; tdcbar<nBarsTDC; tdcbar++){
      par0L[tdcbar] = 0.0;
      par1L[tdcbar] = 0.0;
      par0R[tdcbar] = 0.0;
      par1R[tdcbar] = 0.0;
      if(hLeVTOTL[tdcbar]->GetEntries()==0)
      	continue;
      else{
	// set up canvas for left pmt
	TCanvas *cleft = new TCanvas(TString::Format("cFits_Bar%d_L",tdcbar),
				     TString::Format("cFits_Bar%d_L",tdcbar),
				     700, 500);
	cleft->Divide(2,1);
	TPad *leftPad = (TPad*)cleft->cd(1);
	leftPad->Divide(1,2);
	leftPad->cd(1);
	gPad->SetTopMargin(0.12);
	hLeVTOTL[tdcbar]->Draw("COLZ");
	// do the fit slices y
	hLeVTOTL[tdcbar]->FitSlicesY(0,1,NTotBins-1,StatCut);
	// draw results
	// constant of each slice gauss
	leftPad->cd(2);
	TH1D *hLeVTOTL_0 = (TH1D*)gDirectory->Get(TString::Format("hLeVTOT_Bar%d_L_%d",tdcbar,0));
	hLeVTOTL_0->Draw();
	// mean of each slice gauss
	TPad *rightPad = (TPad*)cleft->cd(2);
	rightPad->Divide(1,2);
	rightPad->cd(1);
	gPad->SetTopMargin(0.12);
	gPad->SetLeftMargin(0.15);
	TH1D *hLeVTOTL_1 = (TH1D*)gDirectory->Get(TString::Format("hLeVTOT_Bar%d_L_%d",tdcbar,1));
	hLeVTOTL_1->Draw();
	// fit the means - this callibrates the tot
	Double_t minFitRange = 0.0;
	Double_t maxFitRange = 0.0;
	if(Fitmin==-999.0 || Fitmax==-999.0){
	  Int_t nbins = hLeVTOTL_1->GetNbinsX();
	  vector<Double_t> vbincontents;
	  vbincontents.clear();
	  for(Int_t bin=1; bin<nbins; bin++){
	    if(hLeVTOTL_1->GetBinContent(bin)!=0.)
	      vbincontents.push_back(bin);
	  }
	  if(vbincontents.size()>0){
	    minFitRange = ((TAxis*)hLeVTOTL_1->GetXaxis())->GetBinCenter(vbincontents[0]);
	    maxFitRange = ((TAxis*)hLeVTOTL_1->GetXaxis())->GetBinCenter(vbincontents[vbincontents.size()-1]);
	  }
	  else{
	    minFitRange = ((TAxis*)hLeVTOTL[tdcbar]->GetXaxis())->GetBinCenter(1);
	    maxFitRange = ((TAxis*)hLeVTOTL[tdcbar]->GetXaxis())->GetBinCenter(NTotBins-1);
	  }
	}
	else{
	  minFitRange = Fitmin;
	  maxFitRange = Fitmax;
	}
	fLeft[tdcbar] = new TF1(TString::Format("f_Bar%d_L",tdcbar),
				"[0]*x + [1]",
				minFitRange, maxFitRange);
	// fLeft[tdcbar] = new TF1(TString::Format("f_Bar%d_L",tdcbar),
      	// 		      "[0]*x + [1]*x*x + [2]",
      	// 		      minFitRange, maxFitRange);
	hLeVTOTL_1->Fit(TString::Format("f_Bar%d_L",tdcbar),"QR","",minFitRange, maxFitRange);
	par0L[tdcbar] = fLeft[tdcbar]->GetParameter(0);
	par1L[tdcbar] = fLeft[tdcbar]->GetParameter(1);
	// draw the fit to check
	TF1 *fcheckL = new TF1("fcheckL","[0]*x + [1]",minFitRange,maxFitRange);
	fcheckL->SetParameter(0,fLeft[tdcbar]->GetParameter(0));
	fcheckL->SetParameter(1,fLeft[tdcbar]->GetParameter(1));
	// TF1 *fcheckL = new TF1("fcheckL","[0]*x + [1]*x*x + [2]",minFitRange,maxFitRange);
	// fcheckL->SetParameter(0,fLeft[tdcbar]->GetParameter(0));
	// fcheckL->SetParameter(1,fLeft[tdcbar]->GetParameter(1));
	// fcheckL->SetParameter(2,fLeft[tdcbar]->GetParameter(2));
	leftPad->cd(1);
	fcheckL->Draw("SAME");
	// sigma of each slice gauss
	rightPad->cd(2);
	gPad->SetTopMargin(0.12);
	gPad->SetLeftMargin(0.15);
	TH1D *hLeVTOTL_2 = (TH1D*)gDirectory->Get(TString::Format("hLeVTOT_Bar%d_L_%d",tdcbar,2));
	hLeVTOTL_2->Draw();
	// set attributes
	hLeVTOTL_0->SetLineColor(1);
	hLeVTOTL_0->SetMarkerColor(1);
	hLeVTOTL_0->SetMarkerStyle(21);
	hLeVTOTL_0->SetMarkerSize(0.6);
	hLeVTOTL_1->SetLineColor(1);
	hLeVTOTL_1->SetMarkerColor(1);
	hLeVTOTL_1->SetMarkerStyle(21);
	hLeVTOTL_1->SetMarkerSize(0.6);
	hLeVTOTL_2->SetLineColor(1);
	hLeVTOTL_2->SetMarkerColor(1);
	hLeVTOTL_2->SetMarkerStyle(21);
	hLeVTOTL_2->SetMarkerSize(0.6);
	
	cleft->Write();
	delete cleft;
	delete fcheckL;
	
	// set up canvas for right pmt
	TCanvas *cright = new TCanvas(TString::Format("cFits_Bar%d_R",tdcbar),
				      TString::Format("cFits_Bar%d_R",tdcbar),
				      700, 500);
	cright->Divide(2,1);
	TPad *leftPadr = (TPad*)cright->cd(1);
	leftPadr->Divide(1,2);
	leftPadr->cd(1);
	gPad->SetTopMargin(0.12);
	hLeVTOTR[tdcbar]->Draw("COLZ");
	// do the fit slices y
	hLeVTOTR[tdcbar]->FitSlicesY(0,1,NTotBins-1,StatCut);
	// draw results
	// constant of each slice gauss
	leftPadr->cd(2);
	TH1D *hLeVTOTR_0 = (TH1D*)gDirectory->Get(TString::Format("hLeVTOT_Bar%d_R_%d",tdcbar,0));
	hLeVTOTR_0->Draw();
	// mean of each slice gauss
	TPad *rightPadr = (TPad*)cright->cd(2);
	rightPadr->Divide(1,2);
	rightPadr->cd(1);
	gPad->SetTopMargin(0.12);
	gPad->SetLeftMargin(0.15);
	TH1D *hLeVTOTR_1 = (TH1D*)gDirectory->Get(TString::Format("hLeVTOT_Bar%d_R_%d",tdcbar,1));
	hLeVTOTR_1->Draw();
	// fit the means - this callibrates the tot
	Double_t minFitRanger = 0.0;
	Double_t maxFitRanger = 0.0;
	if(Fitmin==-999.0 || Fitmax==-999.0){
	  
	  Int_t nbinsr = hLeVTOTR_1->GetNbinsX();
	  vector<Double_t> vbincontentsr;
	  vbincontentsr.clear();
	  for(Int_t binr=1; binr<nbinsr; binr++){
	    if(hLeVTOTR_1->GetBinContent(binr)!=0.)
	      vbincontentsr.push_back(binr);
	  }
	  if(vbincontentsr.size()>0){
	    minFitRanger = ((TAxis*)hLeVTOTR_1->GetXaxis())->GetBinCenter(vbincontentsr[0]);
	    maxFitRanger = ((TAxis*)hLeVTOTR_1->GetXaxis())->GetBinCenter(vbincontentsr[vbincontentsr.size()-1]);
	  }
	  else{
	    minFitRanger = ((TAxis*)hLeVTOTR[tdcbar]->GetXaxis())->GetBinCenter(1);
	    maxFitRanger = ((TAxis*)hLeVTOTR[tdcbar]->GetXaxis())->GetBinCenter(NTotBins-1);
	  }
	}
	else{
	  minFitRanger = Fitmin;
	  maxFitRanger = Fitmax;
	}
	fRight[tdcbar] = new TF1(TString::Format("f_Bar%d_R",tdcbar),
				 "[0]*x + [1]",
				 minFitRanger, maxFitRanger);
	// fRight[tdcbar] = new TF1(TString::Format("f_Bar%d_R",tdcbar),
	// 			      "[0]*x + [1]*x*x + [2]",
	// 			      minFitRanger, maxFitRanger);
	hLeVTOTR_1->Fit(TString::Format("f_Bar%d_R",tdcbar),"QR","",minFitRanger, maxFitRanger);
	par0R[tdcbar] = fRight[tdcbar]->GetParameter(0);
	par1R[tdcbar] = fRight[tdcbar]->GetParameter(1);
	// draw the fit to check
	TF1 *fcheckR = new TF1("fcheckR","[0]*x + [1]",minFitRanger,maxFitRanger);
	fcheckR->SetParameter(0,fRight[tdcbar]->GetParameter(0));
	fcheckR->SetParameter(1,fRight[tdcbar]->GetParameter(1));
	// TF1 *fcheckR = new TF1("fcheckR","[0]*x + [1]*x*x + [2]",minFitRange,maxFitRange);
	// fcheckR->SetParameter(0,fRight[tdcbar]->GetParameter(0));
	// fcheckR->SetParameter(1,fRight[tdcbar]->GetParameter(1));
	// fcheckR->SetParameter(2,fRight[tdcbar]->GetParameter(2));
	leftPadr->cd(1);
	fcheckR->Draw("SAME");
	// sigma of each slice gauss
	rightPadr->cd(2);
	gPad->SetTopMargin(0.12);
	gPad->SetLeftMargin(0.15);
	TH1D *hLeVTOTR_2 = (TH1D*)gDirectory->Get(TString::Format("hLeVTOT_Bar%d_R_%d",tdcbar,2));
	hLeVTOTR_2->Draw();
	// set attributes
	hLeVTOTR_0->SetLineColor(1);
	hLeVTOTR_0->SetMarkerColor(1);
	hLeVTOTR_0->SetMarkerStyle(21);
	hLeVTOTR_0->SetMarkerSize(0.6);
	hLeVTOTR_1->SetLineColor(1);
	hLeVTOTR_1->SetMarkerColor(1);
	hLeVTOTR_1->SetMarkerStyle(21);
	hLeVTOTR_1->SetMarkerSize(0.6);
	hLeVTOTR_2->SetLineColor(1);
	hLeVTOTR_2->SetMarkerColor(1);
	hLeVTOTR_2->SetMarkerStyle(21);
	hLeVTOTR_2->SetMarkerSize(0.6);
	
	cright->Write();
	delete cright;
	delete fcheckR;
	
      }// if we have entries in the tot v le histo
    }// tdc bar loop

    // write to text file
    ofstream textfile;
    TString outtxtfile = ANALYSED_DIR + "/LEFits_" + InFile + ".txt";
    textfile.open(outtxtfile);
    textfile << "bb.hodotdc.timewalk0map = " << "\n";
    for(Int_t tdcbarL=0; tdcbarL<nBarsTDC; tdcbarL++){
    if(tdcbarL==7 || tdcbarL==15 || tdcbarL==23 || tdcbarL==31 || tdcbarL==39 || tdcbarL==47 || tdcbarL==55 || tdcbarL==63 || tdcbarL==71 || tdcbarL==79 || tdcbarL==87 || tdcbarL==89)
      textfile << par0L[tdcbarL] << "\t\n";
    else
      textfile << par0L[tdcbarL] << "\t";
   }
    for(Int_t tdcbarR=0; tdcbarR<nBarsTDC; tdcbarR++){
    if(tdcbarR==7 || tdcbarR==15 || tdcbarR==23 || tdcbarR==31 || tdcbarR==39 || tdcbarR==47 || tdcbarR==55 || tdcbarR==63 || tdcbarR==71 || tdcbarR==79 || tdcbarR==87 || tdcbarR==89)
      textfile << par0R[tdcbarR] << "\t\n";
    else
      textfile << par0R[tdcbarR] << "\t";
   }
    textfile << "bb.hodotdc.timewalk1map = " << "\n";
    for(Int_t tdcbarL2=0; tdcbarL2<nBarsTDC; tdcbarL2++){
    if(tdcbarL2==7 || tdcbarL2==15 || tdcbarL2==23 || tdcbarL2==31 || tdcbarL2==39 || tdcbarL2==47 || tdcbarL2==55 || tdcbarL2==63 || tdcbarL2==71 || tdcbarL2==79 || tdcbarL2==87 || tdcbarL2==89)
      textfile << par1L[tdcbarL2] << "\t\n";
    else
      textfile << par1L[tdcbarL2] << "\t";
   }
    for(Int_t tdcbarR2=0; tdcbarR2<nBarsTDC; tdcbarR2++){
    if(tdcbarR2==7 || tdcbarR2==15 || tdcbarR2==23 || tdcbarR2==31 || tdcbarR2==39 || tdcbarR2==47 || tdcbarR2==55 || tdcbarR2==63 || tdcbarR2==71 || tdcbarR2==79 || tdcbarR2==87 || tdcbarR2==89)
      textfile << par1R[tdcbarR2] << "\t\n";
    else
      textfile << par1R[tdcbarR2] << "\t";
   }
    textfile.close();

  }// if DoFit==1



 //=========================================================== Draw any canvases
  TCanvas *cLeft1 = new TCanvas("cLeft1","Left PMTs 0-44",900,700);
  cLeft1->Divide(10,5);
  TCanvas *cLeft2 = new TCanvas("cLeft2","Left PMTs 45-90",900,700);
  cLeft2->Divide(10,5);
  for(Int_t b=0; b<nBarsTDC; b++){
    if(b<45){
      cLeft1->cd(b+1);
      hLeVTOTL[b]->Draw("COLZ");
    }
    else{
      cLeft2->cd(b-45+1);
      hLeVTOTL[b]->Draw("COLZ");
    }
  }
  TCanvas *cRight1 = new TCanvas("cRight1","Right PMTs 0-44",900,700);
  cRight1->Divide(10,5);
  TCanvas *cRight2 = new TCanvas("cRight2","Right PMTs 45-90",900,700);
  cRight2->Divide(10,5);
  for(Int_t b=0; b<nBarsTDC; b++){
    if(b<45){
      cRight1->cd(b+1);
      hLeVTOTR[b]->Draw("COLZ");
    }
    else{
      cRight2->cd(b-45+1);
      hLeVTOTR[b]->Draw("COLZ");
    }
  }
 
  //=============================================== Write/Draw Histograms/Graphs
  f->cd();
  f->mkdir("RawDist");
  f->cd("RawDist");
  // multiplot canvases
  cLeft1->Write();
  cLeft2->Write();
  cRight1->Write();
  cRight2->Write();
  // individual plots
  for(Int_t bar=0; bar<nBarsTDC; bar++){
    hLeVTOTL[bar]->GetYaxis()->SetTitle("LE Time");
    hLeVTOTL[bar]->GetXaxis()->SetTitle("TOT");
    hLeVTOTL[bar]->Write();
    hLeVTOTR[bar]->GetYaxis()->SetTitle("LE Time");
    hLeVTOTR[bar]->GetXaxis()->SetTitle("TOT");
    hLeVTOTR[bar]->Write();
  }
  if(CutADC==1){
    f->mkdir("adc");
    f->cd("adc");
    for(Int_t bar=0; bar<nBarsADC; bar++){
      hADCL[bar]->Write();
      hADCR[bar]->Write();
    }
  }

  //========================================================== Close output file
  f->Close();
  // tidy up canvases
  delete cLeft1;
  delete cLeft2;
  delete cRight1;
  delete cRight2;

  

  //================================================================== End Macro
}// end main
