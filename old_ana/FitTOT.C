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

void FitTOT(const TString InFile="bbhodo_307_500000", Int_t nevents=-1){
  // InFile is the input file without absolute path and without .root suffix
  // nevents is how many events to analyse, -1 for all


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
  ofstream tottextfile;
  TString outtxtfile = ANALYSED_DIR + "/TOTFits_" + InFile + ".txt";
  tottextfile.open(outtxtfile);



  //===================================================== Histogram Declarations
  // number of adc bins
  Int_t NAdcBins = 500;//4096;
  Double_t AdcBinLow = 0.;
  Double_t AdcBinHigh = 1000;//4095.;
  Int_t NTdcBins = 25;
  Double_t TdcBinLow = 0.;
  Double_t TdcBinHigh = 50.;

  // TOT vs ADC histos
  TH2F *hTOTvADCL[nBarsADC];
  for(Int_t bar=0; bar<(nBarsADC); bar++){
    Int_t adcbar = adcbarstart+ bar;
    hTOTvADCL[bar] = new TH2F(TString::Format("hTOTvADC_Bar%d_L",adcbar),
			      TString::Format("hTOTvADC_Bar%d_L",adcbar),
			      NAdcBins, AdcBinLow, AdcBinHigh,
			      NTdcBins, TdcBinLow, TdcBinHigh
			      );
  }
  TH2F *hTOTvADCR[nBarsADC];
  for(Int_t bar=0; bar<(nBarsADC); bar++){
    Int_t adcbar = adcbarstart+ bar;
    hTOTvADCR[bar] = new TH2F(TString::Format("hTOTvADC_Bar%d_R",adcbar),
			      TString::Format("hTOTvADC_Bar%d_R",adcbar),
			      NAdcBins, AdcBinLow, AdcBinHigh,
			      NTdcBins, TdcBinLow, TdcBinHigh
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
	  hTOTvADCL[adcbar]->Fill(Thodo::ADCValL[adcbar],Thodo::TDCTotL[tdcbar]);
	  hTOTvADCR[adcbar]->Fill(Thodo::ADCValR[adcbar],Thodo::TDCTotL[tdcbar]);
	}// if adc==tdc bar
      }// tdc bar loop
    }// adc bar loop
    
    
  }// event loop
  


  //==================================================================== Fitting




 //=========================================================== Draw any canvases
 TCanvas *cLeft = new TCanvas("cLeft","Left PMTs",900,700);
  cLeft->Divide(8,4);
  for(Int_t b=0; b<nBarsADC; b++){
    cLeft->cd(b+1);
    hTOTvADCL[b]->Draw("COLZ");
    // gPad->Modified();
    // // cLeft->Modified();
    // cLeft->Update();
  }
 TCanvas *cRight = new TCanvas("cRight","Right PMTs",900,700);
  cRight->Divide(8,4);
  for(Int_t b=0; b<nBarsADC; b++){
    cRight->cd(b+1);
    hTOTvADCR[b]->Draw("COLZ");
    // gPad->Modified();
    // // cRight->Modified();
    // cRight->Update();
  }

  //=============================================== Write/Draw Histograms/Graphs
  f->cd();
  // multiplot canvases
  cLeft->Write();
  cRight->Write();
  // individual plots
  for(Int_t bar=0; bar<nBarsADC; bar++){
    hTOTvADCL[bar]->GetXaxis()->SetTitle("ADC bin");
    hTOTvADCL[bar]->GetYaxis()->SetTitle("TOT");
    hTOTvADCL[bar]->Write();
    hTOTvADCR[bar]->GetXaxis()->SetTitle("ADC bin");
    hTOTvADCR[bar]->GetYaxis()->SetTitle("TOT");
    hTOTvADCR[bar]->Write();
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



