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
#include <TSystem.h>
#include <TStyle.h>

const Int_t nTdc = 180;
const Int_t nBarsTDC = 90;
const Int_t nBarsADC = 32;
const Double_t ADCCUT = 150.;//100.0;

//for local analysis at uog (please leave in comments)
//TString REPLAYED_DIR = "/w/work0/home/rachel/HallA/BB_Hodo/FallRun2021/Replayed";
//TString ANALYSED_DIR = "/w/work0/home/rachel/HallA/BB_Hodo/FallRun2021/Analysed";

//TString REPLAYED_DIR = "/volatile/halla/sbs/gpenman/GEN_REPLAY/rootfiles/GEN2/H2/";
//TString ANALYSED_DIR = "/work/halla/sbs/gpenman/results/hodocalib/";

TString REPLAYED_DIR = "/volatile/halla/sbs/sbs-gen/GEN_REPLAYS/Rootfiles/GEN2/He3/rootfiles/";
TString ANALYSED_DIR = "./";

using namespace std;

void FitTimeWalk(const TString InFile="e1209016", Int_t nevents=-1, Int_t cosmic=0, Int_t DoFit=1, Int_t CutADC=0, Double_t Fitmin=7., Double_t Fitmax=25.)
{
  //InFile is the input file without absolute path and without .root suffix
  //nevents is how many events to analyse, -1 for all
  //DoFit==1 means fit tot v le and write out txt file of results
  //CutADC==1 will demand an ADC hit above a specified threshold (ADCCUT)
  //Fitmin and Fitmax are start and end limits for linear fit to tot v le, leave them at -999.0 if you want the script to find these limits itself. This is the preferred option.

  //To execute
  //root -l
  //.L FitTimeWalk.C+
  //FitTimeWalk("filename", -1, 0, 1, 0, -999., -999.)

  Double_t min_gradient, max_gradient, min_offset, max_offset, default_gradient, default_offset;
  min_gradient = -0.01;
  max_gradient = -0.5;
  min_offset = 0.0;
  max_offset = 10.0;
  default_gradient = -0.2;
  default_offset = 5.0; 
  
  //Get data from tree
  TString sInFile = REPLAYED_DIR + "/" + InFile + "*.root";
  cout << "Adding " << sInFile << endl;
  TChain *T = new TChain("T");
  T->Add(sInFile);
    
  Int_t NdataTDC;
  Double_t TDCBar[nBarsTDC];
  Double_t TDCleL[nBarsTDC], TDCleR[nBarsTDC], TDCtotL[nBarsTDC], TDCtotR[nBarsTDC];
  Int_t NdataADC;
  Double_t ADCBar[nBarsADC], ADCValL[nBarsADC], ADCValR[nBarsADC];
  //Int_t ADCBarOff[nBarsADC];
     
  Double_t tr_p[3], tr_n, ps_e;
     
  //disable all branches
  T->SetBranchStatus("*",0);
  //enable branches
  T->SetBranchStatus("Ndata.bb.hodotdc.bar.tdc.id",1);
  T->SetBranchStatus("bb.hodotdc.*",1);
    
  T->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.id",&NdataTDC);
  T->SetBranchAddress("bb.hodotdc.bar.tdc.id",TDCBar);
  T->SetBranchAddress("bb.hodotdc.bar.tdc.L.tot",TDCtotL);
  T->SetBranchAddress("bb.hodotdc.bar.tdc.R.tot",TDCtotR);
  T->SetBranchAddress("bb.hodotdc.bar.tdc.L.le",TDCleL);
  T->SetBranchAddress("bb.hodotdc.bar.tdc.R.le",TDCleR);
     
  if(CutADC==1){
    T->SetBranchStatus("Ndata.bb.hodoadc.bar.adc.id",1);
    T->SetBranchStatus("bb.hodoadc.bar.adc.*",1);
    T->SetBranchAddress("Ndata.bb.hodoadc.bar.adc.id",&NdataADC);
    T->SetBranchAddress("bb.hodoadc.bar.adc.id",ADCBar);
    T->SetBranchAddress("bb.hodoadc.bar.adc.L.ap",ADCValL);
    T->SetBranchAddress("bb.hodoadc.bar.adc.R.ap",ADCValR);
    //T->SetBranchAddress("bb.hodoadc.bar.adc.L.a",ADCValL);
    //T->SetBranchAddress("bb.hodoadc.bar.adc.R.a",ADCValR);
    //T->SetBranchAddress("bb.hodoadc.adcbaroff",ADCBarOff);
    //T->SetBranchAddress("Ndata.bb.hodoadc.bar.adc.L.ap",&NdataADCL);
    //T->SetBranchAddress("Ndata.bb.hodoadc.bar.adc.R.ap",&NdataADCR);
    //T->SetBranchAddress("Ndata.bb.hodoadc.bar.adc.L.a",&NdataADCL);
    //T->SetBranchAddress("Ndata.bb.hodoadc.bar.adc.R.a",&NdataADCR);  
  }

  if(!cosmic){
    T->SetBranchStatus("bb.tr.p",1);
    T->SetBranchStatus("bb.ps.e",1);
    T->SetBranchStatus("bb.tr.n",1);
      
    T->SetBranchAddress("bb.tr.p",&tr_p);
    T->SetBranchAddress("bb.tr.n",&tr_n);
    T->SetBranchAddress("bb.ps.e",&ps_e);
  }
  
  
  //Check no of events
  Int_t Nev = T->GetEntries();
  if (Nev==0)
    cout << "Tree empty. Check Paths! Exiting!" << endl;
  else
    cout << "N entries in tree is " << Nev << endl;
  
  Int_t NEventsAnalysis;
  if(nevents==-1) 
    NEventsAnalysis = Nev;
  else 
    NEventsAnalysis = nevents;
  
  cout << "Running analysis for " << NEventsAnalysis << " events" << endl;
  

  
  //Create output root file for viewing fits
  TString outrootfile = ANALYSED_DIR + "TWFits.root";
  TFile *f = new TFile(outrootfile, "RECREATE");
  if (!f->IsOpen()){
    cout << "Couldn't open output root file. Exiting";
    exit(2);
  }
  
  //Create output text file for TW database parameters
  ofstream textfile;
  TString outtxtfile = ANALYSED_DIR + "TWFits.txt";
  textfile.open(outtxtfile);
  if (!textfile.is_open()){
    cout << "Couldn't open output text file. Exiting";
    exit(2);
  }
  
  //Check the bar offset
  Int_t adcbarstart=32;
  if (CutADC==1){
  T->GetEntry(0);
  adcbarstart = (Int_t)ADCBar[0];
  cout << "adcbarstart " << adcbarstart << endl;
  }


  //Histogram Declarations
  //number of histo bins
  Int_t NTotBins = 100;//200;
  Double_t TotBinLow = 0.;
  Double_t TotBinHigh = 30;//400.;
  Int_t NLEBins = 100;
  Double_t LEBinLow = -20.0;//-800.0;//-100.;
  Double_t LEBinHigh = 20.0;//100.;

  //TOT vs LE histos
  TH2F *hLeVTOTL[nBarsTDC];
  TH2F *hLeVTOTR[nBarsTDC];
  for(Int_t bar=0; bar<(nBarsTDC); bar++){
    hLeVTOTL[bar] = new TH2F(TString::Format("hLeVTOT_Bar%d_L",bar),
			     TString::Format("hLeVTOT_Bar%d_L",bar),
			     NTotBins, TotBinLow, TotBinHigh,
			     NLEBins, LEBinLow, LEBinHigh
			     );
    hLeVTOTL[bar]->GetXaxis()->SetTitle("Time Over Threshold [ns]");
    hLeVTOTL[bar]->GetYaxis()->SetTitle("Leading Edge [ns]");
	
    hLeVTOTR[bar] = new TH2F(TString::Format("hLeVTOT_Bar%d_R",bar),
			     TString::Format("hLeVTOT_Bar%d_R",bar),
			     NTotBins, TotBinLow, TotBinHigh,
			     NLEBins, LEBinLow, LEBinHigh
			     );
    hLeVTOTR[bar]->GetXaxis()->SetTitle("Time Over Threshold [ns]");
    hLeVTOTR[bar]->GetYaxis()->SetTitle("Leading Edge [ns]");
  }

  //adc histos to check if cutting on adc
  //number of adc bins
  Int_t NAdcBins = 200;//4096;
  Double_t AdcBinLow = 0.;
  Double_t AdcBinHigh = 2000;//4095.;
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



  //Event Loop
  for(Int_t ev=0; ev<NEventsAnalysis; ev++){
    
    if(ev%10000==0) cout << ev << " / " << NEventsAnalysis << endl;
    T->GetEntry(ev);
    

    //very loose elastic electron cut if not cosmic run
    if (!cosmic){
      if(tr_n <= 0) continue;
      if(ps_e < 0.2) continue;
      if(tr_p[0] < 2.0) continue;
    }
    
    for(Int_t tdc=0; tdc<NdataTDC; tdc++){
      Int_t tdcbar = TDCBar[tdc];
      
      //check for good cosmic bar i.e one neighbouring hit
      if(cosmic){
	if( tdc==0 ){
	  if( TDCBar[tdc+1] != tdcbar+1 )
	    continue;
	}
	else if( tdc==(Int_t)NdataTDC-1 ){
	  if( TDCBar[tdc-1] != tdcbar-1 )
	    continue;
	}
	else{ 
	  if( TDCBar[tdc+1] != tdcbar+1 || TDCBar[tdc-1] != tdcbar-1 )
	    continue;
	}
      }
      
      if(CutADC==1){
	for(Int_t adcbar=0; adcbar<nBarsADC; adcbar++){
	  Int_t bar = ADCBar[adcbar];//adcbarstart+adcbar;
	  if(bar==tdcbar){
	    if(ADCValL[adcbar]>=ADCCUT){
	      hLeVTOTL[tdcbar]->Fill(TDCtotL[tdc],TDCleL[tdc]);
	      hADCL[adcbar]->Fill(ADCValL[adcbar]);
	    }
	    if(ADCValR[adcbar]>=ADCCUT){
	      hLeVTOTR[tdcbar]->Fill(TDCtotR[tdc],TDCleR[tdc]);
	      hADCR[adcbar]->Fill(ADCValR[adcbar]);
	    }
	  }//if bar matches
	}//adc bar loop
      }//adc cut
      else if(CutADC!=1){
	hLeVTOTL[tdcbar]->Fill(TDCtotL[tdc],TDCleL[tdc]);
	hLeVTOTR[tdcbar]->Fill(TDCtotR[tdc],TDCleR[tdc]);
      }//else
    }//tdc bar loop
  }//event loop



  //Fitting
  if(DoFit==1){
    
    //parameters outside loop below
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
	//set up canvas for left pmt
	TCanvas *cleft = new TCanvas(TString::Format("cFits_Bar%d_L",tdcbar),
				     TString::Format("cFits_Bar%d_L",tdcbar),
				     700, 500);
	cleft->Divide(2,1);
	TPad *leftPad = (TPad*)cleft->cd(1);
	leftPad->Divide(1,2);
	leftPad->cd(1);
	gPad->SetTopMargin(0.12);
	hLeVTOTL[tdcbar]->Draw("COLZ");
	//do the fit slices y
	hLeVTOTL[tdcbar]->FitSlicesY(0,1,NTotBins-1,StatCut);
	//draw results
	//constant of each slice gauss
	leftPad->cd(2);
	TH1D *hLeVTOTL_0 = (TH1D*)gDirectory->Get(TString::Format("hLeVTOT_Bar%d_L_%d",tdcbar,0));
	hLeVTOTL_0->GetYaxis()->SetTitle("Leading Edge [ns]");
	hLeVTOTL_0->GetXaxis()->SetTitle("Time Over Threshold [ns]");
	hLeVTOTL_0->Draw();
	//mean of each slice gauss
	TPad *rightPad = (TPad*)cleft->cd(2);
	rightPad->Divide(1,2);
	rightPad->cd(1);
	gPad->SetTopMargin(0.12);
	gPad->SetLeftMargin(0.15);
	TH1D *hLeVTOTL_1 = (TH1D*)gDirectory->Get(TString::Format("hLeVTOT_Bar%d_L_%d",tdcbar,1));
	hLeVTOTL_1->Draw();
	//fit the means - this callibrates the tot
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
	    minFitRange = ((TAxis*)hLeVTOTL_1->GetXaxis())->GetBinCenter(1);
	    maxFitRange = ((TAxis*)hLeVTOTL_1->GetXaxis())->GetBinCenter(NTotBins-1);
	  }
	}
	else{
	  minFitRange = Fitmin;
	  maxFitRange = Fitmax;
	}
	fLeft[tdcbar] = new TF1(TString::Format("f_Bar%d_L",tdcbar),
				"[0]*x + [1]",
				minFitRange, maxFitRange);
	fLeft[tdcbar]->SetParLimits(0,min_gradient,max_gradient);
	fLeft[tdcbar]->SetParLimits(1, min_offset, max_offset);
	//fLeft[tdcbar] = new TF1(TString::Format("f_Bar%d_L",tdcbar),
      	//		      "[0]*x + [1]*x*x + [2]",
      	//		      minFitRange, maxFitRange);
	hLeVTOTL_1->Fit(TString::Format("f_Bar%d_L",tdcbar),"QR","",minFitRange, maxFitRange);
	par0L[tdcbar] = fLeft[tdcbar]->GetParameter(0);
	par1L[tdcbar] = fLeft[tdcbar]->GetParameter(1);
	//draw the fit to check
	TF1 *fcheckL = new TF1("fcheckL","[0]*x + [1]",minFitRange,maxFitRange);
	fcheckL->SetParameter(0,fLeft[tdcbar]->GetParameter(0));
	fcheckL->SetParameter(1,fLeft[tdcbar]->GetParameter(1));
	//TF1 *fcheckL = new TF1("fcheckL","[0]*x + [1]*x*x + [2]",minFitRange,maxFitRange);
	//fcheckL->SetParameter(0,fLeft[tdcbar]->GetParameter(0));
	//fcheckL->SetParameter(1,fLeft[tdcbar]->GetParameter(1));
	//fcheckL->SetParameter(2,fLeft[tdcbar]->GetParameter(2));
	leftPad->cd(1);
	fcheckL->Draw("SAME");
	//sigma of each slice gauss
	rightPad->cd(2);
	gPad->SetTopMargin(0.12);
	gPad->SetLeftMargin(0.15);
	TH1D *hLeVTOTL_2 = (TH1D*)gDirectory->Get(TString::Format("hLeVTOT_Bar%d_L_%d",tdcbar,2));
	hLeVTOTL_2->Draw();
	//set attributes
	hLeVTOTL_0->SetLineColor(1);
	hLeVTOTL_0->SetMarkerColor(1);
	hLeVTOTL_0->SetMarkerStyle(21);
	hLeVTOTL_0->SetMarkerSize(0.6);
	hLeVTOTL_1->SetLineColor(1);
	hLeVTOTL_1->SetMarkerColor(1);
	hLeVTOTL_1->SetMarkerStyle(21);
	hLeVTOTL_1->SetMarkerSize(0.6);
	hLeVTOTL_1->SetMinimum(LEBinLow);
	hLeVTOTL_1->SetMaximum(LEBinHigh);
	hLeVTOTL_2->SetLineColor(1);
	hLeVTOTL_2->SetMarkerColor(1);
	hLeVTOTL_2->SetMarkerStyle(21);
	hLeVTOTL_2->SetMarkerSize(0.6);
	
	cleft->Write();
	cleft->Print(Form("left_%d.pdf",tdcbar));
	delete cleft;
	delete fcheckL;
	
	//set up canvas for right pmt
	TCanvas *cright = new TCanvas(TString::Format("cFits_Bar%d_R",tdcbar),
				      TString::Format("cFits_Bar%d_R",tdcbar),
				      700, 500);
	cright->Divide(2,1);
	TPad *leftPadr = (TPad*)cright->cd(1);
	leftPadr->Divide(1,2);
	leftPadr->cd(1);
	gPad->SetTopMargin(0.12);
	hLeVTOTR[tdcbar]->Draw("COLZ");
	//do the fit slices y
	hLeVTOTR[tdcbar]->FitSlicesY(0,1,NTotBins-1,StatCut);
	//draw results
	//constant of each slice gauss
	leftPadr->cd(2);
	TH1D *hLeVTOTR_0 = (TH1D*)gDirectory->Get(TString::Format("hLeVTOT_Bar%d_R_%d",tdcbar,0));
	hLeVTOTR_0->GetYaxis()->SetTitle("Leading Edge [ns]");
	hLeVTOTR_0->GetXaxis()->SetTitle("Time Over Threshold [ns]");
	hLeVTOTR_0->Draw();
	//mean of each slice gauss
	TPad *rightPadr = (TPad*)cright->cd(2);
	rightPadr->Divide(1,2);
	rightPadr->cd(1);
	gPad->SetTopMargin(0.12);
	gPad->SetLeftMargin(0.15);
	TH1D *hLeVTOTR_1 = (TH1D*)gDirectory->Get(TString::Format("hLeVTOT_Bar%d_R_%d",tdcbar,1));
	hLeVTOTR_1->Draw();
	//fit the means - this callibrates the tot
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
	    minFitRanger = ((TAxis*)hLeVTOTR_1->GetXaxis())->GetBinCenter(1);
	    maxFitRanger = ((TAxis*)hLeVTOTR_1->GetXaxis())->GetBinCenter(NTotBins-1);
	  }
	}
	else{
	  minFitRanger = Fitmin;
	  maxFitRanger = Fitmax;
	}
	fRight[tdcbar] = new TF1(TString::Format("f_Bar%d_R",tdcbar),
				 "[0]*x + [1]",
				 minFitRanger, maxFitRanger);
	fRight[tdcbar]->SetParLimits(0,min_gradient,max_gradient);
	fRight[tdcbar]->SetParLimits(1, min_offset, max_offset);
	//fRight[tdcbar] = new TF1(TString::Format("f_Bar%d_R",tdcbar),
	//			      "[0]*x + [1]*x*x + [2]",
	//			      minFitRanger, maxFitRanger);
	hLeVTOTR_1->Fit(TString::Format("f_Bar%d_R",tdcbar),"QR","",minFitRanger, maxFitRanger);
	par0R[tdcbar] = fRight[tdcbar]->GetParameter(0);
	par1R[tdcbar] = fRight[tdcbar]->GetParameter(1);
	//draw the fit to check
	TF1 *fcheckR = new TF1("fcheckR","[0]*x + [1]",minFitRanger,maxFitRanger);
	fcheckR->SetParameter(0,fRight[tdcbar]->GetParameter(0));
	fcheckR->SetParameter(1,fRight[tdcbar]->GetParameter(1));
	//TF1 *fcheckR = new TF1("fcheckR","[0]*x + [1]*x*x + [2]",minFitRange,maxFitRange);
	//fcheckR->SetParameter(0,fRight[tdcbar]->GetParameter(0));
	//fcheckR->SetParameter(1,fRight[tdcbar]->GetParameter(1));
	//fcheckR->SetParameter(2,fRight[tdcbar]->GetParameter(2));
	leftPadr->cd(1);
	fcheckR->Draw("SAME");
	//sigma of each slice gauss
	rightPadr->cd(2);
	gPad->SetTopMargin(0.12);
	gPad->SetLeftMargin(0.15);
	TH1D *hLeVTOTR_2 = (TH1D*)gDirectory->Get(TString::Format("hLeVTOT_Bar%d_R_%d",tdcbar,2));
	hLeVTOTR_2->Draw();
	//set attributes
	hLeVTOTR_0->SetLineColor(1);
	hLeVTOTR_0->SetMarkerColor(1);
	hLeVTOTR_0->SetMarkerStyle(21);
	hLeVTOTR_0->SetMarkerSize(0.6);
	hLeVTOTR_1->SetLineColor(1);
	hLeVTOTR_1->SetMarkerColor(1);
	hLeVTOTR_1->SetMarkerStyle(21);
	hLeVTOTR_1->SetMarkerSize(0.6);
	hLeVTOTR_1->SetMinimum(LEBinLow);
	hLeVTOTR_1->SetMaximum(LEBinHigh);
	hLeVTOTR_2->SetLineColor(1);
	hLeVTOTR_2->SetMarkerColor(1);
	hLeVTOTR_2->SetMarkerStyle(21);
	hLeVTOTR_2->SetMarkerSize(0.6);
	
	cright->Write();
	cright->Print(Form("right_%d.pdf",tdcbar));
	delete cright;
	delete fcheckR;
	
      }//if we have entries in the tot v le histo
    }//tdc bar loop
    
    gSystem->Exec("pdfunite left*.pdf right*.pdf TWFits.pdf");
    gSystem->Exec("rm left*.pdf right*.pdf");
    gSystem->Exec(Form("mv TWFits.pdf %s",ANALYSED_DIR.Data()));
    
    cout << "Writing text files" << endl;
    //write to text file
    textfile << "bb.hodotdc.timewalk0map = " << "\n";
    for(Int_t tdcbarL=0; tdcbarL<nBarsTDC; tdcbarL++){
      textfile << par0L[tdcbarL] << "\t\n";
   }
    for(Int_t tdcbarR=0; tdcbarR<nBarsTDC; tdcbarR++){
      textfile << par0R[tdcbarR] << "\t\n";
   }
    textfile << "bb.hodotdc.timewalk1map = " << "\n";
    for(Int_t tdcbarL2=0; tdcbarL2<nBarsTDC; tdcbarL2++){
      textfile << par1L[tdcbarL2] << "\t\n";
   }
    for(Int_t tdcbarR2=0; tdcbarR2<nBarsTDC; tdcbarR2++){
      textfile << par1R[tdcbarR2] << "\t\n";
   }
    textfile.close();

  }//if DoFit==1
  cout << "Finished writing text files" << endl;
  

 //Draw any canvases
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
 
  //Write/Draw Histograms/Graphs
  f->cd();
  f->mkdir("RawDist");
  f->cd("RawDist");
  //multiplot canvases
  cLeft1->Write();
  cLeft2->Write();
  cRight1->Write();
  cRight2->Write();
  //individual plots
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

  //Close output file
  f->Close();
  //tidy up canvases
  delete cLeft1;
  delete cLeft2;
  delete cRight1;
  delete cRight2;

  
  cout << "Getting here before seg fault?" << endl;
}//end main
