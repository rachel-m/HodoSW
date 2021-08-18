// rmontgom@jlab.org - 08/21
// updated landau fit for sbs offline using generic detector
// macro to fit landau part of adc spectra and write results to text file
// works using the replayed file from sbs offline
// assumes that the pedestal callibration has already been done
// assumes the pedestal cuts in the db file are up to date
// uses the branch ap, which has pedestal subtracted
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
#include <TFile.h>
#include <TTree.h>
#include <TChain.h>
#include <TCanvas.h>
#include <TLine.h>
#include <TLegend.h>


const Int_t nAdc = 64;
const Int_t nBars = 32;
const Int_t nSide = 2;

TString REPLAYED_DIR = "/home/rachel/HodoSWDev/replayed_files";
TString ANALYSED_DIR = "/home/rachel/HodoSWDev/AnalysisOut";

namespace Thodo {
  Int_t NdataAdcBar;
  Double_t ADCBar[nBars];
  Int_t NdataAdcL;
  Double_t ADCValL[nBars];
  Int_t NdataAdcR;
  Double_t ADCValR[nBars];
};

TChain *T = 0;

using namespace std;

void GetLandau(const TString InFile="bbhodo_307_1000", Int_t nevents=-1,
	       Double_t FitStart=150.0, Double_t FitStop = 1000.0,
	       Double_t Width=40.0, Int_t HistRange=3000){
  // InFile is the input file without absolute path and without .root suffix
  // nevents is how many events to analyse, -1 for all
  // FitStart is the guess for the valley position, will be fit start range
  // FitStop is the upper limit of the fit range
  // Width if initial guess for the width of the landaus
  // HistRange is the upper limit of the histogram to plot


  //========================================================= Get data from tree
  if(!T) { 
    TString sInFile = REPLAYED_DIR + "/" + InFile + ".root";
    cout << "Adding " << sInFile << endl;
    T = new TChain("T");
    T->Add(sInFile);
    // T->Add(TString::Format("replayed/replayed_bbhodo_%d.evio.0.root",RunNo));
    
    // disable all branches
    T->SetBranchStatus("*",0);
    // enable adc branches
    T->SetBranchStatus("bb.hodoadc.*",1);
    T->SetBranchAddress("bb.hodoadc.adcbarid",Thodo::ADCBar);
    T->SetBranchAddress("bb.hodoadc.L.ap",Thodo::ADCValL);
    T->SetBranchAddress("bb.hodoadc.R.ap",Thodo::ADCValR);
    // enable vector size branches
    T->SetBranchStatus("Ndata.bb.hodoadc.*",1);
    T->SetBranchAddress("Ndata.bb.hodoadc.adcbarid",&Thodo::NdataAdcBar);
    T->SetBranchAddress("Ndata.bb.hodoadc.L.ap",&Thodo::NdataAdcL);
    T->SetBranchAddress("Ndata.bb.hodoadc.R.ap",&Thodo::NdataAdcR);  
    
  }//setting tree
  
  
  
  //========================================================= Check no of events
  Int_t Nev = T->GetEntries();
  cout << "N entries in tree is " << Nev << endl;
  Int_t NEventsAnalysis;
  if(nevents==-1) NEventsAnalysis = Nev;
  else NEventsAnalysis = nevents;
  cout << "Running analysis for " << NEventsAnalysis << " events" << endl;
  
  
  
  //========================================================= Check the bars
  T->GetEntry(0);
  const Int_t nobars = Thodo::NdataAdcBar;
  if(nobars!=nBars){
    cout << "ERROR - the number of bars in tree is not 32 as ecpected" << endl;
    exit;
  }
  Double_t Bars[nBars];
  for(Int_t b=0; b<nBars; b++){
    Bars[b] = Thodo::ADCBar[b];
  }
  
  
  
  //==================================================== Create output root file
  // root file for viewing fits
  TString outrootfile = ANALYSED_DIR + "/LandauFits_" + InFile + ".root";
  TFile *f = new TFile(outrootfile, "RECREATE");
  // TFile * f = new TFile(TString::Format("AnalysedFiles/PedFits_replayed_bbhodo_%d.evio.0.root",RunNo),"RECREATE");



  //==================================================== Create output text file
  // text file for recording fit results
  ofstream landautextfile;
  TString outtxtfile = ANALYSED_DIR + "/LandauFits_" + InFile + ".txt";
  landautextfile.open(outtxtfile);
  // landautextfile.open( TString::Format("AnalysedFiles/PedFits_replayed_bbhodo_%d.evio.0.txt", RunNo));



  //===================================================== Histogram Declarations
  // number of adc bins
  Int_t NAdcBins = HistRange;//4096;
  Double_t AdcBinLow = -0.5;
  Double_t AdcBinHigh = HistRange+0.5;//4095;

  // ADC histos
  TH1F *hADCL[nBars];
  for(Int_t bar=0; bar<(nBars); bar++){
    hADCL[bar] = new TH1F(TString::Format("hADC_Bar%d_L",(Int_t)Bars[bar]),
			  TString::Format("hADC_Bar%d_L",(Int_t)Bars[bar]),
			      NAdcBins, AdcBinLow, AdcBinHigh);
  }
  TH1F *hADCR[nBars];
  for(Int_t bar=0; bar<(nBars); bar++){
    hADCR[bar] = new TH1F(TString::Format("hADC_Bar%d_R",(Int_t)Bars[bar]),
			      TString::Format("hADC_Bar%d_R",(Int_t)Bars[bar]),
			      NAdcBins, AdcBinLow, AdcBinHigh);
  }
  TH1F *hADCConstantsL = new TH1F("hADCConstantsL",
				   "Constants of landau fits",
				   nBars,
				   0.0,
				   nBars);
  TH1F *hADCConstantsR = new TH1F("hADCConstantsR",
				   "Amplitudes of landau fits",
				   nBars,
				   0.0,
				   nBars);
  TH1F *hADCMPVsL = new TH1F("hADCMPVsL",
			      "MPVs of landau fits",
			      nBars,
			      0.0,
			      nBars);
  TH1F *hADCMPVsR = new TH1F("hADCMPVsR",
			     "MPVs of landau fits",
			      nBars,
			      0.0,
			      nBars);
  TH1F *hADCWidthsL = new TH1F("hADCWidthsL",
			       "Widths of landau fits",
			       nBars,
			       0.0,
			       nBars);
  TH1F *hADCWidthsR = new TH1F("hADCWidthsR",
			       "Widths of landau fits",
			       nBars,
			       0.0,
			       nBars);
  


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
    if(Thodo::NdataAdcBar!=nBars){
      cout << "ERROR - the number of bars in the sbs-offline root file is not 90"
	   << endl;
      exit;
    }
    // fill the adc histograms
    for(Int_t bar=0; bar<nBars; bar++){
      hADCL[bar]->Fill(Thodo::ADCValL[bar]);
      hADCR[bar]->Fill(Thodo::ADCValR[bar]);
    }//bar
    
  }// event loop
  


  //==================================================================== Fitting
  //start fitting
  TF1 *fLandauL[nBars];
  TF1 *fLandauR[nBars];
  
  // some variables for storing fit results etc
  Double_t LaundauConstL[nBars];
  Double_t LaundauMPVL[nBars];
  Double_t LaundauWidthL[nBars];
  Double_t LaundauConstR[nBars];
  Double_t LaundauMPVR[nBars];
  Double_t LaundauWidthR[nBars];
  Double_t LaundauConstErrorsL[nBars];
  Double_t LaundauMPVErrorsL[nBars];
  Double_t LaundauWidthErrorsL[nBars];
  Double_t LaundauConstErrorsR[nBars];
  Double_t LaundauMPVErrorsR[nBars];
  Double_t LaundauWidthErrorsR[nBars];

  // loop over all bars
  for(Int_t bar=0; bar<(nBars); bar++){

    //get info on histogram to set initial pars
    Int_t nBinsL = hADCL[bar]->GetNbinsX();
    Int_t nBinsR = hADCR[bar]->GetNbinsX();
    if(nBinsL!=nBinsR){
      cout << "WARNING - check the hADCL and hADCR nbins matches" << endl;
      exit;
    }

    // find landau max position  
    hADCL[bar]->GetXaxis()->SetRangeUser(FitStart,FitStop);
    hADCR[bar]->GetXaxis()->SetRangeUser(FitStart,FitStop);
    Int_t maxbinL = hADCL[bar]->GetMaximumBin();
    Int_t maxbincentreL = hADCL[bar]->GetBinCenter(maxbinL);
    // Int_t maxbincontentL = hADCL[bar]->GetBinContent(maxbinL);
    Int_t maxbinR = hADCR[bar]->GetMaximumBin();
    Int_t maxbincentreR = hADCR[bar]->GetBinCenter(maxbinR);
    // Int_t maxbincontentR = hADCR[bar]->GetBinContent(maxbinR);
    hADCL[bar]->GetXaxis()->SetRangeUser(0.0,FitStop);
    hADCR[bar]->GetXaxis()->SetRangeUser(0.0,FitStop);
    
    // left
    fLandauL[bar] = new TF1(TString::Format("fLandau_Bar%d_L",(Int_t)Bars[bar]),
			    "landau",FitStart, FitStop);
    // fLandauL[bar]->SetParameter(0, binmaxcontentL);
    fLandauL[bar]->SetParameter(1, maxbincentreL);
    fLandauL[bar]->SetParameter(2, Width);
    // right
    fLandauR[bar] = new TF1(TString::Format("fLandau_Bar%d_R",(Int_t)Bars[bar]),
			    "landau",FitStart, FitStop);
    // fLandauR[bar]->SetParameter(0, binmaxcontentR);
    fLandauR[bar]->SetParameter(1, maxbincentreR);
    fLandauR[bar]->SetParameter(2, Width);
    // do the fits
    hADCL[bar]->Fit(fLandauL[bar],"QR");
    hADCR[bar]->Fit(fLandauR[bar],"QR");
    // copy fit results to arrays
    LaundauConstL[bar] = fLandauL[bar]->GetParameter(0);
    LaundauMPVL[bar] = fLandauL[bar]->GetParameter(1);
    LaundauWidthL[bar] = fLandauL[bar]->GetParameter(2);
    LaundauConstR[bar] = fLandauR[bar]->GetParameter(0);
    LaundauMPVR[bar] = fLandauR[bar]->GetParameter(1);
    LaundauWidthR[bar] = fLandauR[bar]->GetParameter(2);
    LaundauConstErrorsL[bar] = fLandauL[bar]->GetParError(0);
    LaundauMPVErrorsL[bar] = fLandauL[bar]->GetParError(1);
    LaundauWidthErrorsL[bar] = fLandauL[bar]->GetParError(2);
    LaundauConstErrorsR[bar] = fLandauR[bar]->GetParError(0);
    LaundauMPVErrorsR[bar] = fLandauR[bar]->GetParError(1);
    LaundauWidthErrorsR[bar] = fLandauR[bar]->GetParError(2);
  }// bar loop

  // // write to text file
  for(Int_t bar=0; bar<nBars; bar++ ){
    landautextfile << Bars[bar] << "\t" << LaundauMPVL[bar]
		   << "\t" << LaundauMPVErrorsL[bar]
		   << "\t" << LaundauMPVR[bar]
		   << "\t" << LaundauMPVErrorsR[bar] << "\n";
    // fill the histograms for displaying
    hADCConstantsL->Fill(bar, LaundauConstL[bar]);
    hADCMPVsL->Fill(bar, LaundauMPVL[bar]);
    hADCWidthsL->Fill(bar, LaundauWidthL[bar]);
    hADCConstantsR->Fill(bar, LaundauConstL[bar]);
    hADCMPVsR->Fill(bar, LaundauMPVL[bar]);
    hADCWidthsR->Fill(bar, LaundauWidthL[bar]);
  }
  // close text file
  landautextfile.close();



  //========================================================== Graph Fit Results
  Double_t xerrors[nBars];
  Double_t bars[nBars];
  for(Int_t bar=0; bar<(nBars); bar++){
    xerrors[bar] = 0.0;
    bars[bar] = bar;
  }
  // landau constants
  // left
 TGraphErrors *gConstantsL = new TGraphErrors(nBars,
  					       bars,
  					       LaundauConstL,
  					       xerrors,
  					       LaundauConstErrorsL);
  gConstantsL->SetTitle("Landau Fit Constants");
  gConstantsL->SetName("ConstantsL");
  gConstantsL->GetXaxis()->SetTitle("Bar");
  gConstantsL->GetYaxis()->SetTitle("constant of landau fit");
  gConstantsL->SetMarkerColor(kGreen); gConstantsL->SetMarkerStyle(21);
  // right
 TGraphErrors *gConstantsR = new TGraphErrors(nBars,
  					       bars,
  					       LaundauConstR,
  					       xerrors,
  					       LaundauConstErrorsR);
  gConstantsR->SetTitle("Landau Fit Constants");
  gConstantsR->SetName("ConstantsR");
  gConstantsR->GetXaxis()->SetTitle("Bar");
  gConstantsR->GetYaxis()->SetTitle("constant of landau fit");
  gConstantsR->SetMarkerColor(kBlue); gConstantsR->SetMarkerStyle(21);
  // landau mpvs
  // left
  TGraphErrors *gMPVL = new TGraphErrors(nBars,
					 bars,
					 LaundauConstL,
					 xerrors,
					 LaundauConstErrorsL);
  gMPVL->SetTitle("Landau Fit MPV");
  gMPVL->SetName("MPVL");
  gMPVL->GetXaxis()->SetTitle("Bar");
  gMPVL->GetYaxis()->SetTitle("mpv of landau fit");
  gMPVL->SetMarkerColor(kGreen); gMPVL->SetMarkerStyle(21);
  // right
  TGraphErrors *gMPVR = new TGraphErrors(nBars,
					 bars,
					 LaundauConstR,
					 xerrors,
					 LaundauConstErrorsR);
  gMPVR->SetTitle("Landau Fit MPV");
  gMPVR->SetName("MPVR");
  gMPVR->GetXaxis()->SetTitle("Bar");
  gMPVR->GetYaxis()->SetTitle("mpv of landau fit");
  gMPVR->SetMarkerColor(kBlue); gMPVR->SetMarkerStyle(21);
  // landau widths
  // left
  TGraphErrors *gWidthL = new TGraphErrors(nBars,
					 bars,
					 LaundauConstL,
					 xerrors,
					 LaundauConstErrorsL);
  gWidthL->SetTitle("Landau Fit Width");
  gWidthL->SetName("WidthL");
  gWidthL->GetXaxis()->SetTitle("Bar");
  gWidthL->GetYaxis()->SetTitle("width of landau fit");
  gWidthL->SetMarkerColor(kGreen); gWidthL->SetMarkerStyle(21);
  // right
  TGraphErrors *gWidthR = new TGraphErrors(nBars,
					 bars,
					 LaundauConstR,
					 xerrors,
					 LaundauConstErrorsR);
  gWidthR->SetTitle("Landau Fit Width");
  gWidthR->SetName("WidthR");
  gWidthR->GetXaxis()->SetTitle("Bar");
  gWidthR->GetYaxis()->SetTitle("width of landau fit");
  gWidthR->SetMarkerColor(kBlue); gWidthR->SetMarkerStyle(21);
  // draw graphs
  // constants
  TCanvas *cConstants = new TCanvas();
  cConstants->SetName("cConstantsLeftVRight");
  cConstants->cd();
  gConstantsL->Draw("AP");
  gConstantsR->Draw("SAMEP");
  TLegend *lConstants = new TLegend(0.1,0.1,0.3,0.3);
  lConstants->SetHeader("pmt sides");
  lConstants->AddEntry("ConstantsL","Left");
  lConstants->AddEntry("ConstantsR","Right");
  lConstants->Draw();
  // MPVs
  TCanvas *cMPV = new TCanvas();
  cMPV->SetName("cMPVLeftVRight");
  cMPV->cd();
  gMPVL->Draw("AP");
  gMPVR->Draw("SAMEP");
  TLegend *lMPV = new TLegend(0.1,0.1,0.3,0.3);
  lMPV->SetHeader("pmt sides");
  lMPV->AddEntry("MPVL","Left");
  lMPV->AddEntry("MPVR","Right");
  lMPV->Draw();
  // Widths
  TCanvas *cWidth = new TCanvas();
  cWidth->SetName("cWidthLeftVRight");
  cWidth->cd();
  gWidthL->Draw("AP");
  gWidthR->Draw("SAMEP");
  TLegend *lWidth = new TLegend(0.1,0.1,0.3,0.3);
  lWidth->SetHeader("pmt sides");
  lWidth->AddEntry("WidthL","Left");
  lWidth->AddEntry("WidthR","Right");
  lWidth->Draw();



 //========================================================== Draw Fit Results
  TCanvas *cLeft = new TCanvas("cLeft",
  			       "Left PMTs, ADC spectra",
  			       900,700);
  cLeft->Divide(8,4);
  for(Int_t b=0; b<nBars; b++){
    cLeft->cd(b+1);
    gPad->SetLogy();
    hADCL[b]->Draw();
    // gPad->Modified();
    // // cLeft->Modified();
    // gPad->Modified();
    // cLeft->Update();
  }

  TCanvas *cRight = new TCanvas("cRight",
  			       "Right PMTs, ADC spectra",
  			       900,700);
  cRight->Divide(8,4);
  for(Int_t b=0; b<nBars; b++){
    cRight->cd(b+1);
    gPad->SetLogy();
    hADCR[b]->Draw();
    // gPad->Modified();
    // gPad->Modified();
    // // cRight->Modified();
    // cRight->Update();
  }
  // cLeft->Update();
  // cRight->Update();



  //=============================================== Write/Draw Histograms/Graphs
  f->cd();
  gDirectory->mkdir("ADC");
  f->cd("ADC");
  // write the canvases with multiplots
  cLeft->Write();
  cRight->Write();
  TCanvas *cadc = new TCanvas();
  cadc->cd();
  for(Int_t bar=0; bar<(nBars); bar++){
    hADCL[bar]->GetXaxis()->SetTitle("ADC bin");
    hADCL[bar]->Write();
    hADCR[bar]->GetXaxis()->SetTitle("ADC bin");
    hADCR[bar]->Write();
  }
  f->cd();
  gDirectory->mkdir("FitResults");
  f->cd("FitResults");
  // hists and graphs of results
  hADCConstantsL->GetXaxis()->SetTitle("Bar");
  hADCConstantsL->GetYaxis()->SetTitle("Landau fit constant");
  hADCConstantsL->Write();
  hADCConstantsR->GetXaxis()->SetTitle("Bar");
  hADCConstantsR->GetYaxis()->SetTitle("Landau fit constant");
  hADCConstantsR->Write();
  hADCMPVsL->GetXaxis()->SetTitle("Bar");
  hADCMPVsL->GetYaxis()->SetTitle("Landau fit MPV");
  hADCMPVsL->Write();
  hADCMPVsR->GetXaxis()->SetTitle("Bar");
  hADCMPVsR->GetYaxis()->SetTitle("Landau fit MPV");
  hADCMPVsR->Write();
  hADCWidthsL->GetXaxis()->SetTitle("Bar");
  hADCWidthsL->GetYaxis()->SetTitle("Landau fit Width");
  hADCWidthsL->Write();
  hADCWidthsR->GetXaxis()->SetTitle("Bar");
  hADCWidthsR->GetYaxis()->SetTitle("Landau fit Width");
  hADCWidthsR->Write();
  // graphs of results - not for use with hall a online gui
  cConstants->Write();
  gConstantsL->Write();
  gConstantsR->Write();
  cMPV->Write();
  gMPVL->Write();
  gMPVR->Write();
  cWidth->Write();
  gWidthL->Write();
  gWidthR->Write();



  //========================================================== Close output file
  f->Close();
  // tidy up canvases
  delete cConstants;
  delete cMPV;
  delete cWidth;

  

  //================================================================== End Macro
}// end macro



