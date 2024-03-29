// rmontgom@jlab.org - 08/21
// macro to fit tot v adc
// will be used for subsets of 32 bars at a time - require adc and tdc info
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
#include <TPad.h>

const Int_t nAdc = 64;
const Int_t nBarsADC = 32;
const Int_t nTdc = 180;
const Int_t nBarsTDC = 90;
const Int_t nSide = 2;

const TString REPLAYED_DIR = "/w/work0/home/rachel/HallA/BB_Hodo/cosmicdata/replayed";
const TString ANALYSED_DIR = "/w/work0/home/rachel/HallA/BB_Hodo/cosmicdata/analysisout";

namespace Thodo {
  Int_t NdataAdcBar;
  Double_t ADCBar[nBarsADC];
  Int_t NdataAdcL;
  Double_t ADCValL[nBarsADC];
  Int_t NdataAdcR;
  Double_t ADCValR[nBarsADC];
  Int_t ADCBarOff[nBarsADC];

// this assumes one tdc hit per bar was selected in sbsoffline(!)
  Int_t NdataTdcBar;
  Double_t TDCBar[nBarsTDC];
  Int_t NdataTotL;
  Double_t TDCTotL[nBarsTDC];
  Int_t NdataTotR;
  Double_t TDCTotR[nBarsTDC];
};

TChain *T = 0;

using namespace std;

Double_t fitfunc(Double_t *val, Double_t *par);

void FitTOTSlicesExpFit(const TString InFile="bbhodo_307_500000",
			     Int_t nevents=-1,Int_t DoFitTOT=0,
			     Int_t DoFitADC=0){
  // InFile is the input file without absolute path and without .root suffix
  // nevents is how many events to analyse, -1 for all
  // DoFitTOT set this to 1 if you want to do fitslicesy to TOT v ADC and callibrate TOT
  // DoFitADC set this to 1 if you want to do fitslicesx to TOT v ADC and callibrate ADC


  //========================================================= Get data from tree
  if(!T) { 
    TString sInFile = REPLAYED_DIR + "/" + InFile + ".root";
    cout << "Adding " << sInFile << endl;
    T = new TChain("T");
    T->Add(sInFile);
    
    // disable all branches
    T->SetBranchStatus("*",0);
    // enable adc branches
    T->SetBranchStatus("bb.hodoadc.*",1);
    T->SetBranchAddress("bb.hodoadc.adcbarid",Thodo::ADCBar);
    T->SetBranchAddress("bb.hodoadc.L.ap",Thodo::ADCValL);
    T->SetBranchAddress("bb.hodoadc.R.ap",Thodo::ADCValR);
    T->SetBranchAddress("bb.hodoadc.adcbaroff",Thodo::ADCBarOff);
    T->SetBranchStatus("bb.hodotdc.*",1);
    T->SetBranchAddress("bb.hodotdc.tdcbarid",Thodo::TDCBar);
    T->SetBranchAddress("bb.hodotdc.L.tot",Thodo::TDCTotL);
    T->SetBranchAddress("bb.hodotdc.R.tot",Thodo::TDCTotR);
    // T->SetBranchAddress("bb.hodotdc.L.leW",Thodo::TDCTotL); // walk corrected
    // T->SetBranchAddress("bb.hodotdc.R.leW",Thodo::TDCTotR); // walk corrected

    // enable vector size branches
    T->SetBranchStatus("Ndata.bb.hodoadc.*",1);
    T->SetBranchAddress("Ndata.bb.hodoadc.adcbarid",&Thodo::NdataAdcBar);
    T->SetBranchAddress("Ndata.bb.hodoadc.L.ap",&Thodo::NdataAdcL);
    T->SetBranchAddress("Ndata.bb.hodoadc.R.ap",&Thodo::NdataAdcR); 
    T->SetBranchAddress("Ndata.bb.hodotdc.tdcbarid",&Thodo::NdataTdcBar);
    T->SetBranchAddress("Ndata.bb.hodotdc.L.tot",&Thodo::NdataTotL);
    T->SetBranchAddress("Ndata.bb.hodotdc.R.tot",&Thodo::NdataTotR);  
    // T->SetBranchAddress("Ndata.bb.hodotdc.L.totW",&Thodo::NdataTdcL); // walk corrected
    // T->SetBranchAddress("Ndata.bb.hodotdc.R.totW",&Thodo::NdataATdcR); // walk corrected    
  }//setting tree
  
  
  
  //========================================================= Check no of events
  Int_t Nev = T->GetEntries();
  cout << "N entries in tree is " << Nev << endl;
  Int_t NEventsAnalysis;
  if(nevents==-1) NEventsAnalysis = Nev;
  else NEventsAnalysis = nevents;
  cout << "Running analysis for " << NEventsAnalysis << " events" << endl;
  
  
  
  //==================================================== Check the bar offset
  T->GetEntry(0);
  Int_t adcbarstart = Thodo::ADCBarOff[0];
  cout << "adcbarstart " << adcbarstart << endl;
  
  
  //==================================================== Create output root file
  // root file for viewing fits
  TString outrootfile = ANALYSED_DIR + "/TOTFits_" + InFile + ".root";
  TFile *f = new TFile(outrootfile, "RECREATE");



  //==================================================== Create output text file
  // text file for recording fit results
  // ofstream tottextfile;
  // TString outtxtfile = ANALYSED_DIR + "/TOTFits_" + InFile + ".txt";
  // tottextfile.open(outtxtfile);



  //===================================================== Histogram Declarations
  // number of adc bins
  Int_t NAdcBins = 100;//4096;
  Double_t AdcBinLow = 0.;
  Double_t AdcBinHigh = 800;//4095.;
  Int_t NTdcBins = 40;
  Double_t TdcBinLow = 0.;
  Double_t TdcBinHigh = 40.;

  // TOT vs ADC histos
  TH2F *hADCvTOTL[nBarsADC];
  for(Int_t bar=0; bar<(nBarsADC); bar++){
    Int_t adcbar = adcbarstart+ bar;
    hADCvTOTL[bar] = new TH2F(TString::Format("hADCvTOT_Bar%d_L",adcbar),
			      TString::Format("hADCvTOT_Bar%d_L",adcbar),
			      NTdcBins, TdcBinLow, TdcBinHigh,
			      NAdcBins, AdcBinLow, AdcBinHigh
			      );
  }
  TH2F *hADCvTOTR[nBarsADC];
  for(Int_t bar=0; bar<(nBarsADC); bar++){
    Int_t adcbar = adcbarstart+ bar;
    hADCvTOTR[bar] = new TH2F(TString::Format("hADCvTOT_Bar%d_R",adcbar),
			      TString::Format("hADCvTOT_Bar%d_R",adcbar),
			      NTdcBins, TdcBinLow, TdcBinHigh,
			      NAdcBins, AdcBinLow, AdcBinHigh
			      );
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

    // check for tdc hits in the bars that match the adc bars instrumented
    for(Int_t adcbar=0; adcbar<Thodo::NdataAdcBar; adcbar++){
      for(Int_t tdcbar=0; tdcbar<Thodo::NdataTdcBar; tdcbar++){
	if(Thodo::ADCBar[adcbar]==Thodo::TDCBar[tdcbar]){
	  hADCvTOTL[adcbar]->Fill(Thodo::TDCTotL[tdcbar],
				  Thodo::ADCValL[adcbar]);
	  hADCvTOTR[adcbar]->Fill(Thodo::TDCTotL[tdcbar],
				  Thodo::ADCValR[adcbar]);
	}// if adc==tdc bar
      }// tdc bar loop
    }// adc bar loop
    
    
  }// event loop
  


  //==================================================================== Fitting
  // FitSlicesY(f1,firstbin,lastbin,cut,option,arr)
  // if f1=0 it is a gauss
  // defualt option is QNR
  // cut means only fits x bins where the corresponding projection in y has >cut bins filled
  // generated histograms returned in arr
  // eg FitSlicesY(0,7,32,20) = fit gaussian in y for bins 7 to 32 with >20 counts in y proj

  if(DoFitTOT==1 || DoFitADC==1){
    // make a directory in output file
    f->cd();
    gDirectory->mkdir("FitResults");
    f->cd("FitResults");
    
    if(DoFitTOT==1){
      // text file for output
      ofstream tottextfile;
      TString outtxtfiletot = ANALYSED_DIR + "/TOTFits_TOT_" + InFile + ".txt";
      tottextfile.open(outtxtfiletot);

      //===================== fit for x direction
      // fit an gauss along x to the adc v tot? not sure we expect a certain distribution in x-slices
      
      // parameters outside loop below
      // Double_t UpperADC = 600.0; // for finding upper x bin of fit slices
      // Double_t LowerADC = 0.0; // for finding lower x bin of fit slices
      Int_t TOTStatCut = 2;//1; //how many counts in y-proj we want for fit
      TF1 *fLeftTOT[nBarsADC];
      TF1 *fRightTOT[nBarsADC];
      
      for(Int_t b=0; b<nBarsADC; b++){
	Int_t adcbar = adcbarstart+ b;
	
	//left pmts
	// set up canvas for this pmt
	TCanvas *cleftTOT = new TCanvas(TString::Format("cTOTFits_Bar%d_L",adcbar),
					TString::Format("cTOTFits_Bar%d_L",adcbar),
					700, 500);
	cleftTOT->Divide(2,1);
	TPad *leftPadTOT = (TPad*)cleftTOT->cd(1);
	leftPadTOT->Divide(1,2);
	leftPadTOT->cd(1);
	gPad->SetTopMargin(0.12);
	hADCvTOTL[b]->Draw("COLZ");
	// do the fit slices x
	hADCvTOTL[b]->FitSlicesX(0,1,NAdcBins-1,TOTStatCut);
	// draw results
	// constant of each slice gauss
	leftPadTOT->cd(2);
	TH1D *hADCvTOTL_0 = (TH1D*)gDirectory->Get(TString::Format("hADCvTOT_Bar%d_L_%d",adcbar,0));
	hADCvTOTL_0->Draw();
	// mean of each slice gauss
	TPad *rightPadTOT = (TPad*)cleftTOT->cd(2);
	rightPadTOT->Divide(1,2);
	rightPadTOT->cd(1);
	gPad->SetTopMargin(0.12);
	gPad->SetLeftMargin(0.15);
	TH1D *hADCvTOTL_1 = (TH1D*)gDirectory->Get(TString::Format("hADCvTOT_Bar%d_L_%d",adcbar,1));
	hADCvTOTL_1->Draw();
	// fit the means - this callibrates the tot
	Double_t minFitRangeTOT = ((TAxis*)hADCvTOTL[b]->GetXaxis())->GetBinCenter(1);
	Double_t maxFitRangeTOT = ((TAxis*)hADCvTOTL[b]->GetXaxis())->GetBinCenter(NAdcBins-1);
	fLeftTOT[b] = new TF1(TString::Format("fTOT_Bar%d_L",adcbar),
			      "gaus",
			      minFitRangeTOT, maxFitRangeTOT);
	hADCvTOTL_1->Fit(TString::Format("fTOT_Bar%d_L",adcbar),"QR","",minFitRangeTOT, maxFitRangeTOT);
	// output fit results to text file
	// left pmts indicated by 0
	tottextfile << b << "\t" << 0 << "\t"
		    << fLeftTOT[b]->GetParameter(0) << "\t" << fLeftTOT[b]->GetParError(0) << "\t"
		    << fLeftTOT[b]->GetParameter(1) << "\t" << fLeftTOT[b]->GetParError(1) << "\t"
		    << fLeftTOT[b]->GetParameter(2) << "\t" << fLeftTOT[b]->GetParError(2) << "\t"
		    << "\n";
	// sigma of each slice gauss
	rightPadTOT->cd(2);
	gPad->SetTopMargin(0.12);
	gPad->SetLeftMargin(0.15);
	TH1D *hADCvTOTL_2 = (TH1D*)gDirectory->Get(TString::Format("hADCvTOT_Bar%d_L_%d",adcbar,2));
	hADCvTOTL_2->Draw();
	// set attributes
	hADCvTOTL_0->SetLineColor(1);
	hADCvTOTL_0->SetMarkerColor(1);
	hADCvTOTL_0->SetMarkerStyle(21);
	hADCvTOTL_0->SetMarkerSize(0.6);
	hADCvTOTL_1->SetLineColor(1);
	hADCvTOTL_1->SetMarkerColor(1);
	hADCvTOTL_1->SetMarkerStyle(21);
	hADCvTOTL_1->SetMarkerSize(0.6);
	hADCvTOTL_2->SetLineColor(1);
	hADCvTOTL_2->SetMarkerColor(1);
	hADCvTOTL_2->SetMarkerStyle(21);
	hADCvTOTL_2->SetMarkerSize(0.6);
	
	cleftTOT->Write();
	delete cleftTOT;
	
	//right pmts
	// set up canvas for this pmt
	TCanvas *crightTOT = new TCanvas(TString::Format("cTOTFits_Bar%d_R",adcbar),
					 TString::Format("cTOTFits_Bar%d_R",adcbar),
					 700, 500);
	crightTOT->Divide(2,1);
	TPad *leftPadTOTr = (TPad*)crightTOT->cd(1);
	leftPadTOTr->Divide(1,2);
	leftPadTOTr->cd(1);
	gPad->SetTopMargin(0.12);
	hADCvTOTR[b]->Draw("COLZ");
	// do the fit slices x
	hADCvTOTR[b]->FitSlicesX(0,1,NAdcBins-1,TOTStatCut);
	// draw results
	// constant of each slice gauss
	leftPadTOTr->cd(2);
	TH1D *hADCvTOTR_0 = (TH1D*)gDirectory->Get(TString::Format("hADCvTOT_Bar%d_R_%d",adcbar,0));
	hADCvTOTR_0->Draw();
	// mean of each slice gauss
	TPad *rightPadTOTr = (TPad*)crightTOT->cd(2);
	rightPadTOTr->Divide(1,2);
	rightPadTOTr->cd(1);
	gPad->SetTopMargin(0.12);
	gPad->SetLeftMargin(0.15);
	TH1D *hADCvTOTR_1 = (TH1D*)gDirectory->Get(TString::Format("hADCvTOT_Bar%d_R_%d",adcbar,1));
	hADCvTOTR_1->Draw();
	// fit the means - this callibrates the tot
	Double_t minFitRangeTOTr = ((TAxis*)hADCvTOTR[b]->GetXaxis())->GetBinCenter(1);
	Double_t maxFitRangeTOTr = ((TAxis*)hADCvTOTR[b]->GetXaxis())->GetBinCenter(NAdcBins-1);
	fRightTOT[b] = new TF1(TString::Format("fTOT_Bar%d_R",adcbar),
			       "gaus",
			       minFitRangeTOTr, maxFitRangeTOTr);
	hADCvTOTR_1->Fit(TString::Format("fTOT_Bar%d_R",adcbar),"QR","",minFitRangeTOTr, maxFitRangeTOTr);
	// output fit results to text file
	// right pmts indicated by 1
	tottextfile << b << "\t" << 1 << "\t"
		    << fRightTOT[b]->GetParameter(0) << "\t" << fRightTOT[b]->GetParError(0) << "\t"
		    << fRightTOT[b]->GetParameter(1) << "\t" << fRightTOT[b]->GetParError(1) << "\t"
		    << fRightTOT[b]->GetParameter(2) << "\t" << fRightTOT[b]->GetParError(2) << "\t"
		    << "\n";
	// sigma of each slice gauss
	rightPadTOTr->cd(2);
	gPad->SetTopMargin(0.12);
	gPad->SetLeftMargin(0.15);
	TH1D *hADCvTOTR_2 = (TH1D*)gDirectory->Get(TString::Format("hADCvTOT_Bar%d_R_%d",adcbar,2));
	hADCvTOTR_2->Draw();
	// set attributes
	hADCvTOTR_0->SetLineColor(1);
	hADCvTOTR_0->SetMarkerColor(1);
	hADCvTOTR_0->SetMarkerStyle(21);
	hADCvTOTR_0->SetMarkerSize(0.6);
	hADCvTOTR_1->SetLineColor(1);
	hADCvTOTR_1->SetMarkerColor(1);
	hADCvTOTR_1->SetMarkerStyle(21);
	hADCvTOTR_1->SetMarkerSize(0.6);
	hADCvTOTR_2->SetLineColor(1);
	hADCvTOTR_2->SetMarkerColor(1);
	hADCvTOTR_2->SetMarkerStyle(21);
	hADCvTOTR_2->SetMarkerSize(0.6);
	
	crightTOT->Write();
	delete crightTOT;
	
      }//bar loop
    } //  if doing fitting to tot


    if(DoFitADC==1){
      //===================== fits for y direction
      // fit an exponential to the adc in adc v tot
      // from  arxiv 1412.1743v1

      // text file for output
      ofstream adctextfile;
      TString outtxtfileadc = ANALYSED_DIR + "/TOTFits_ADC_" + InFile + ".txt";
      adctextfile.open(outtxtfileadc);
      
      // parameters outside loop below
      Int_t ADCStatCut = 2;//1; //how many counts in y-proj we want for fit
      TF1 *fLeftADC[nBarsADC];
      TF1 *fRightADC[nBarsADC];
      
      for(Int_t b=0; b<nBarsADC; b++){
	Int_t adcbar = adcbarstart+ b;
	
	//left pmts
	// set up canvas for this pmt
	TCanvas *cleftADC = new TCanvas(TString::Format("cADCFits_Bar%d_L",adcbar),
					TString::Format("cADCFits_Bar%d_L",adcbar),
					700, 500);
	cleftADC->Divide(2,1);
	TPad *leftPadADC = (TPad*)cleftADC->cd(1);
	leftPadADC->Divide(1,2);
	leftPadADC->cd(1);
	gPad->SetTopMargin(0.12);
	hADCvTOTL[b]->Draw("COLZ");
	// do the fit slices y
	hADCvTOTL[b]->FitSlicesY(0,1,NAdcBins-1,ADCStatCut);
	// draw results
	// constant of each slice gauss
	leftPadADC->cd(2);
	TH1D *hADCvTOTL_0 = (TH1D*)gDirectory->Get(TString::Format("hADCvTOT_Bar%d_L_%d",adcbar,0));
	hADCvTOTL_0->Draw();
	// mean of each slice gauss
	TPad *rightPadADC = (TPad*)cleftADC->cd(2);
	rightPadADC->Divide(1,2);
	rightPadADC->cd(1);
	gPad->SetTopMargin(0.12);
	gPad->SetLeftMargin(0.15);
	TH1D *hADCvTOTL_1 = (TH1D*)gDirectory->Get(TString::Format("hADCvTOT_Bar%d_L_%d",adcbar,1));
	hADCvTOTL_1->Draw();
	// fit the means - this callibrates the tot
	Double_t minFitRangeADC = ((TAxis*)hADCvTOTL[b]->GetXaxis())->GetBinCenter(1);
	// Double_t maxFitRangeADC = ((TAxis*)hADCvTOTL[b]->GetXaxis())->GetBinCenter(NAdcBins-1);
	Int_t maxbin = hADCvTOTL_1->GetMaximumBin();
	Double_t maxFitRangeADC = hADCvTOTL_1->GetXaxis()->GetBinCenter(maxbin);
	fLeftADC[b] = new TF1(TString::Format("fADC_Bar%d_L",adcbar),
			      "[0]*exp([1]*x)+[2]",
			      minFitRangeADC, maxFitRangeADC);
	fLeftADC[b]->SetParameter(0,0.6);
	fLeftADC[b]->SetParameter(1,0.1);
	fLeftADC[b]->SetParameter(2,-96.);
	hADCvTOTL_1->Fit(TString::Format("fADC_Bar%d_L",adcbar),"QR","",minFitRangeADC, maxFitRangeADC);
	// output fit results to text file
	// left pmts indicated by 0
	adctextfile << b << "\t" << 0 << "\t"
		    << fLeftADC[b]->GetParameter(0) << "\t" << fLeftADC[b]->GetParError(0) << "\t"
		    << fLeftADC[b]->GetParameter(1) << "\t" << fLeftADC[b]->GetParError(1) << "\t"
		    << fLeftADC[b]->GetParameter(2) << "\t" << fLeftADC[b]->GetParError(2) << "\t"
		    << "\n";
	// sigma of each slice gauss
	rightPadADC->cd(2);
	gPad->SetTopMargin(0.12);
	gPad->SetLeftMargin(0.15);
	TH1D *hADCvTOTL_2 = (TH1D*)gDirectory->Get(TString::Format("hADCvTOT_Bar%d_L_%d",adcbar,2));
	hADCvTOTL_2->Draw();
	// set attributes
	hADCvTOTL_0->SetLineColor(1);
	hADCvTOTL_0->SetMarkerColor(1);
	hADCvTOTL_0->SetMarkerStyle(21);
	hADCvTOTL_0->SetMarkerSize(0.6);
	hADCvTOTL_1->SetLineColor(1);
	hADCvTOTL_1->SetMarkerColor(1);
	hADCvTOTL_1->SetMarkerStyle(21);
	hADCvTOTL_1->SetMarkerSize(0.6);
	hADCvTOTL_2->SetLineColor(1);
	hADCvTOTL_2->SetMarkerColor(1);
	hADCvTOTL_2->SetMarkerStyle(21);
	hADCvTOTL_2->SetMarkerSize(0.6);
	
	cleftADC->Write();
	delete cleftADC;

	//right pmts
	// set up canvas for this pmt
	TCanvas *crightADC = new TCanvas(TString::Format("cADCFits_Bar%d_R",adcbar),
					TString::Format("cADCFits_Bar%d_R",adcbar),
					700, 500);
	crightADC->Divide(2,1);
	TPad *leftPadADCr = (TPad*)crightADC->cd(1);
	leftPadADCr->Divide(1,2);
	leftPadADCr->cd(1);
	gPad->SetTopMargin(0.12);
	hADCvTOTR[b]->Draw("COLZ");
	// do the fit slices y
	hADCvTOTR[b]->FitSlicesY(0,1,NAdcBins-1,ADCStatCut);
	// draw results
	// constant of each slice gauss
	leftPadADCr->cd(2);
	TH1D *hADCvTOTR_0 = (TH1D*)gDirectory->Get(TString::Format("hADCvTOT_Bar%d_R_%d",adcbar,0));
	hADCvTOTR_0->Draw();
	// mean of each slice gauss
	TPad *rightPadADCr = (TPad*)crightADC->cd(2);
	rightPadADCr->Divide(1,2);
	rightPadADCr->cd(1);
	gPad->SetTopMargin(0.12);
	gPad->SetLeftMargin(0.15);
	TH1D *hADCvTOTR_1 = (TH1D*)gDirectory->Get(TString::Format("hADCvTOT_Bar%d_R_%d",adcbar,1));
	hADCvTOTR_1->Draw();
	// fit the means - this callibrates the tot
	Double_t minFitRangeADCr = ((TAxis*)hADCvTOTR[b]->GetXaxis())->GetBinCenter(1);
	// Double_t maxFitRangeADCr = ((TAxis*)hADCvTOTR[b]->GetXaxis())->GetBinCenter(NAdcBins-1);
	Int_t maxbinr = hADCvTOTR_1->GetMaximumBin();
	Double_t maxFitRangeADCr = hADCvTOTR_1->GetXaxis()->GetBinCenter(maxbinr);
	fRightADC[b] = new TF1(TString::Format("fADC_Bar%d_R",adcbar),
			      "[0]*exp([1]*x)+[2]",
			      minFitRangeADC, maxFitRangeADC);
	fRightADC[b]->SetParameter(0,0.6);
	fRightADC[b]->SetParameter(1,0.1);
	fRightADC[b]->SetParameter(2,-96.);
	hADCvTOTR_1->Fit(TString::Format("fADC_Bar%d_R",adcbar),"QR","",minFitRangeADC, maxFitRangeADC);
	// output fit results to text file
	// right pmts indicated by 1
	adctextfile << b << "\t" << 1 << "\t"
		    << fRightADC[b]->GetParameter(0) << "\t" << fRightADC[b]->GetParError(0) << "\t"
		    << fRightADC[b]->GetParameter(1) << "\t" << fRightADC[b]->GetParError(1) << "\t"
		    << fRightADC[b]->GetParameter(2) << "\t" << fRightADC[b]->GetParError(2) << "\t"
		    << "\n";
	// sigma of each slice gauss
	rightPadADCr->cd(2);
	gPad->SetTopMargin(0.12);
	gPad->SetLeftMargin(0.15);
	TH1D *hADCvTOTR_2 = (TH1D*)gDirectory->Get(TString::Format("hADCvTOT_Bar%d_R_%d",adcbar,2));
	hADCvTOTR_2->Draw();
	// set attributes
	hADCvTOTR_0->SetLineColor(1);
	hADCvTOTR_0->SetMarkerColor(1);
	hADCvTOTR_0->SetMarkerStyle(21);
	hADCvTOTR_0->SetMarkerSize(0.6);
	hADCvTOTR_1->SetLineColor(1);
	hADCvTOTR_1->SetMarkerColor(1);
	hADCvTOTR_1->SetMarkerStyle(21);
	hADCvTOTR_1->SetMarkerSize(0.6);
	hADCvTOTR_2->SetLineColor(1);
	hADCvTOTR_2->SetMarkerColor(1);
	hADCvTOTR_2->SetMarkerStyle(21);
	hADCvTOTR_2->SetMarkerSize(0.6);
	
	crightADC->Write();
	delete crightADC;
	
      }//bar loop
    }// if fitting adc
    
  }// if fitting



  //=========================================================== Draw any canvases
  TCanvas *cLeft = new TCanvas("cLeft","Left PMTs",900,700);
  cLeft->Divide(8,4);
  for(Int_t b=0; b<nBarsADC; b++){
    cLeft->cd(b+1);
    hADCvTOTL[b]->Draw("COLZ");
    // gPad->Modified();
    // // cLeft->Modified();
    // cLeft->Update();
  }
 TCanvas *cRight = new TCanvas("cRight","Right PMTs",900,700);
  cRight->Divide(8,4);
  for(Int_t b=0; b<nBarsADC; b++){
    cRight->cd(b+1);
    hADCvTOTR[b]->Draw("COLZ");
    // gPad->Modified();
    // // cRight->Modified();
    // cRight->Update();
  }

  //=============================================== Write/Draw Histograms/Graphs
  f->cd();
  gDirectory->mkdir("RawHistos");
  f->cd("RawHistos");
  // multiplot canvases
  cLeft->Write();
  cRight->Write();
  // individual plots
  for(Int_t bar=0; bar<nBarsADC; bar++){
    hADCvTOTL[bar]->GetXaxis()->SetTitle("ADC bin");
    hADCvTOTL[bar]->GetYaxis()->SetTitle("TOT");
    hADCvTOTL[bar]->Write();
    hADCvTOTR[bar]->GetXaxis()->SetTitle("ADC bin");
    hADCvTOTR[bar]->GetYaxis()->SetTitle("TOT");
    hADCvTOTR[bar]->Write();
  }



  //========================================================== Close output file
  f->Close();
  // tidy up canvases
  delete cLeft;
  delete cRight;

  

  //================================================================== End Macro
}// end main


Double_t fitfunc(Double_t *val, Double_t *par){

  // add 2d fit
  // gaussian in adc
  // polynomial in tot

  return 0.0;


}



