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


TString REPLAYED_DIR = "/adaqfs/home/a-onl/sbs/Rootfiles";
TString ANALYSED_DIR = "/adaqfs/home/a-onl/sbs/Rootfiles/bbhodo_hist";
//TString REPLAYED_DIR = "$OUT_DIR";
//TString ANALYSED_DIR = "$OUT_DIR/bbhodo_hist"; 

// for local analysis at uog (please leave in comments)
//TString REPLAYED_DIR = "/w/work0/home/rachel/HallA/BB_Hodo/FallRun2021/Replayed";
//TString ANALYSED_DIR = "/w/work0/home/rachel/HallA/BB_Hodo/FallRun2021/Analysed";

namespace Thodo {
  Int_t NdataAdcBar;
  Double_t ADCBar[nBars];
  Int_t NdataAdcL;
  Double_t ADCValL[nBars];
  Int_t NdataAdcR;
  Double_t ADCValR[nBars];
  //  Int_t ADCBarOff[nBars];
};

TChain *T = 0;

using namespace std;

void GetPed(const TString InFile="bbhodo_307_1000", Int_t nevents=-1,
	    Double_t GaussSigma=7.0, Double_t FitRange=10.0, Double_t Cut = 3.0,
	    Int_t HistRange=300){
  // InFile is the input file without absolute path and without .root suffix
  // nevents is how many events to analyse, -1 for all
  // GaussSigma is initial guess in adc bins for sigma of gauss fit
  // FitRange is how many +-sigma the fit range convers
  // Cut is how many sigma above the pedestal mean you want the pedestal correction value to lie
  // HistRange is the upper value to plot on x axis of adc spectrum

  // to execute
  // root -l
  // .L GetPed.C+
  // GetPed("filename",-1,7.0,3.0,3.0,300)



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
  T->SetBranchAddress("bb.hodoadc.L.a",Thodo::ADCValL);
  T->SetBranchAddress("bb.hodoadc.R.a",Thodo::ADCValR);
  //  T->SetBranchAddress("bb.hodoadc.adcbaroff",Thodo::ADCBarOff);
  // enable vector size branches
  T->SetBranchStatus("Ndata.bb.hodoadc.*",1);
  T->SetBranchAddress("Ndata.bb.hodoadc.adcbarid",&Thodo::NdataAdcBar);
  T->SetBranchAddress("Ndata.bb.hodoadc.L.a",&Thodo::NdataAdcL);
  T->SetBranchAddress("Ndata.bb.hodoadc.R.a",&Thodo::NdataAdcR);  
  
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
  Int_t adcbarstart = (Int_t)Thodo::ADCBar[0];
  cout << "adcbarstart " << adcbarstart << endl;



  //==================================================== Create output root file
  // root file for viewing fits
  TString outrootfile = ANALYSED_DIR + "/PedFits_" + InFile + ".root";
  TFile *f = new TFile(outrootfile, "RECREATE");



  //==================================================== Create output text file
  // text file for recording fit results
  ofstream pedtextfile;
  TString outtxtfile = ANALYSED_DIR + "/PedFits_" + InFile + ".txt";
  pedtextfile.open(outtxtfile);



  //===================================================== Histogram Declarations
  // number of adc bins
  Int_t NAdcBins = HistRange;//4096;
  Double_t AdcBinLow = -0.5;
  Double_t AdcBinHigh = HistRange+0.5;//4095;

  // ADC histos
  TH1F *hADCL[nBars];
  for(Int_t bar=0; bar<(nBars); bar++){
    Int_t al = adcbarstart+bar;
    hADCL[bar] = new TH1F(TString::Format("hADC_Bar%d_L",al),
			  TString::Format("hADC_Bar%d_L",al),
			  NAdcBins, AdcBinLow, AdcBinHigh);
  }
  TH1F *hADCR[nBars];
  for(Int_t bar=0; bar<(nBars); bar++){
    Int_t ar = adcbarstart+bar;
    hADCR[bar] = new TH1F(TString::Format("hADC_Bar%d_R",ar),
			  TString::Format("hADC_Bar%d_R",ar),
			  NAdcBins, AdcBinLow, AdcBinHigh);
  }
  TH1F *hADCAmplitudesL = new TH1F("hADC_PedFit_AmplitudesL",
				   "Amplitudes of ped fits",
				   nBars,
				   0.0,
				   nBars);
  TH1F *hADCAmplitudesR = new TH1F("hADC_PedFit_AmplitudesR",
				   "Amplitudes of ped fits",
				   nBars,
				   0.0,
				   nBars);
  TH1F *hADCMeansL = new TH1F("hADC_PedFit_MeansL",
			      "Means of ped fits",
			      nBars,
			      0.0,
			      nBars);
  TH1F *hADCMeansR = new TH1F("hADC_PedFit_MeansR",
			      "Means of ped fits",
			      nBars,
			      0.0,
			      nBars);
  TH1F *hADCSigmasL = new TH1F("hADC_PedFit_SigmasL",
			       "Sigmas of ped fits",
			       nBars,
			       0.0,
			       nBars);
  TH1F *hADCSigmasR = new TH1F("hADC_PedFit_SigmasR",
			       "Sigmas of ped fits",
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
      exit(0);
    }
    // fill the adc histograms
    for(Int_t bar=0; bar<nBars; bar++){
      hADCL[bar]->Fill(Thodo::ADCValL[bar]);
      hADCR[bar]->Fill(Thodo::ADCValR[bar]);
    }//bar
    
  }// event loop
  


  //==================================================================== Fitting
  //start fitting
  TF1 *fGaussL[nBars];
  TF1 *fGaussR[nBars];
  // some variables for fits etc
  Double_t fitlow;
  Double_t fithigh;
  Int_t nBinsL;
  Int_t nBinsR;
  Int_t binmax;
  Double_t binmaxcentre;
  Int_t binmaxcontent;
  Double_t PedRange = FitRange;
  Double_t PedAmpsL[nBars];
  Double_t PedAmpsR[nBars];
  Double_t PedMeansL[nBars];
  Double_t PedMeansR[nBars];
  Double_t PedSigmasL[nBars];
  Double_t PedSigmasR[nBars];
  Double_t PedAmpErrorsL[nBars];
  Double_t PedAmpErrorsR[nBars];
  Double_t PedMeanErrorsL[nBars];
  Double_t PedMeanErrorsR[nBars];
  Double_t PedSigmaErrorsL[nBars];
  Double_t PedSigmaErrorsR[nBars];

  // loop over all bars
  for(Int_t bar=0; bar<(nBars); bar++){
    Int_t abar = adcbarstart+bar;

    //get info on histogram to set initial pars
    nBinsL = hADCL[bar]->GetNbinsX();
    nBinsR = hADCR[bar]->GetNbinsX();
    if(nBinsL!=nBinsR){
      cout << "WARNING - check the hADCL and hADCR nbins matches" << endl;
      exit(0);
    }
    // left
    binmax =  hADCL[bar]->GetMaximumBin();
    binmaxcentre = hADCL[bar]->GetXaxis()->GetBinCenter(binmax);
    binmaxcontent = hADCL[bar]->GetBinContent(binmax);
    fitlow = binmaxcentre - PedRange*GaussSigma;
    fithigh = binmaxcentre + PedRange*GaussSigma;
    // define the fits
    fGaussL[bar] = new TF1(TString::Format("fGaus_Bar%d_L",abar),
  			      "gaus", fitlow, fithigh);
    // ped fit parameters
    fGaussL[bar]->SetParameter(0, binmaxcontent);
    fGaussL[bar]->SetParameter(1, binmaxcentre);
    fGaussL[bar]->SetParameter(2, GaussSigma);
    // do the fits
    hADCL[bar]->Fit(fGaussL[bar],"QR");
    // right
    binmax =  hADCR[bar]->GetMaximumBin();
    binmaxcentre = hADCR[bar]->GetXaxis()->GetBinCenter(binmax);
    binmaxcontent = hADCR[bar]->GetBinContent(binmax);
    fitlow = binmaxcentre - PedRange*GaussSigma;
    fithigh = binmaxcentre + PedRange*GaussSigma;
    // define the fits
    fGaussR[bar] = new TF1(TString::Format("fGaus_Bar%d_R",bar),
  			      "gaus", fitlow, fithigh);
    // ped fit parameters
    fGaussR[bar]->SetParameter(0, binmaxcontent);
    fGaussR[bar]->SetParameter(1, binmaxcentre);
    fGaussR[bar]->SetParameter(2, GaussSigma);
    // do the fit
    hADCR[bar]->Fit(fGaussR[bar],"QR");

    // fill arrays of fit results
    // left pmts
    PedAmpsL[bar] = fGaussL[bar]->GetParameter(0);
    PedMeansL[bar] = fGaussL[bar]->GetParameter(1);
    PedSigmasL[bar] = fGaussL[bar]->GetParameter(2);
    PedAmpErrorsL[bar] = fGaussL[bar]->GetParError(0);
    PedMeanErrorsL[bar] = fGaussL[bar]->GetParError(1);
    PedSigmaErrorsL[bar] = fGaussL[bar]->GetParError(2);
    // right pmts
    PedAmpsR[bar] = fGaussR[bar]->GetParameter(0);
    PedMeansR[bar] = fGaussR[bar]->GetParameter(1);
    PedSigmasR[bar] = fGaussR[bar]->GetParameter(2);
    PedAmpErrorsR[bar] = fGaussR[bar]->GetParError(0);
    PedMeanErrorsR[bar] = fGaussR[bar]->GetParError(1);
    PedSigmaErrorsR[bar] = fGaussR[bar]->GetParError(2);
  }// bar loop

  // write to text file
  pedtextfile << "bb.hodoadc.adc.pedestal = " << "\n";
  for(Int_t barincL=0; barincL<nBars; barincL++ ){
    if(barincL==7 || barincL==15 || barincL==23 || barincL==31)
      pedtextfile << (PedMeansL[barincL]+Cut*PedSigmasL[barincL]) << "\t\n";
    else
      pedtextfile << (PedMeansL[barincL]+Cut*PedSigmasL[barincL]) << "\t";
    // fill the histograms for displaying
    hADCAmplitudesL->Fill(barincL, PedAmpsL[barincL]);
    hADCMeansL->Fill(barincL, PedMeansL[barincL]);
    hADCSigmasL->Fill(barincL, PedSigmasL[barincL]);
  }
  for(Int_t barincR=0; barincR<nBars; barincR++ ){
    if(barincR==7 || barincR==15 || barincR==23 || barincR==31)
      pedtextfile << (PedMeansR[barincR]+Cut*PedSigmasR[barincR]) << "\t\n";
    else
      pedtextfile << (PedMeansR[barincR]+Cut*PedSigmasR[barincR]) << "\t";
    // fill the histograms for displaying
    hADCAmplitudesR->Fill(barincR, PedAmpsR[barincR]);
    hADCMeansR->Fill(barincR, PedMeansR[barincR]);
    hADCSigmasR->Fill(barincR, PedSigmasR[barincR]);
  }
  // close text file
  pedtextfile.close();



  //========================================================== Graph Fit Results
  Double_t xerrors[nBars];
  Double_t bars[nBars];
  for(Int_t bar=0; bar<(nBars); bar++){
    Int_t b =adcbarstart+bar;
    xerrors[bar] = 0.0;
    bars[bar] = b;
  }
  // gaus amplitudes
  // left
  TGraphErrors *gAmplitudesL = new TGraphErrors(nBars,
  					       bars,
  					       PedAmpsL,
  					       xerrors,
  					       PedAmpErrorsL);
  gAmplitudesL->SetTitle("Gauss Fit Amplitudes");
  gAmplitudesL->SetName("AmplitudesL");
  gAmplitudesL->GetXaxis()->SetTitle("Bar");
  gAmplitudesL->GetYaxis()->SetTitle("Amplitude of Gauss Fit to Pedestal");
  gAmplitudesL->SetMarkerColor(kBlue); gAmplitudesL->SetMarkerStyle(21);
  // right
  TGraphErrors *gAmplitudesR = new TGraphErrors(nBars,
  					       bars,
  					       PedAmpsR,
  					       xerrors,
  					       PedAmpErrorsR);
  gAmplitudesR->SetTitle("Gauss Fit Amplitudes");
  gAmplitudesR->SetName("AmplitudesR");
  gAmplitudesR->GetXaxis()->SetTitle("Bar");
  gAmplitudesR->GetYaxis()->SetTitle("Amplitude of Gauss Fit to Pedestal");
  gAmplitudesR->SetMarkerColor(kGreen); gAmplitudesR->SetMarkerStyle(21);
  // gaus means
  // left
  TGraphErrors *gMeansL = new TGraphErrors(nBars,
  					       bars,
  					       PedMeansL,
  					       xerrors,
  					       PedMeanErrorsL);
  gMeansL->SetTitle("Gauss Fit Means");
  gMeansL->SetName("MeansL");
  gMeansL->GetXaxis()->SetTitle("Bar");
  gMeansL->GetYaxis()->SetTitle("Amplitude of Gauss Fit to Pedestal");
  gMeansL->SetMarkerColor(kBlue); gMeansL->SetMarkerStyle(21);
  // right
  TGraphErrors *gMeansR = new TGraphErrors(nBars,
  					       bars,
  					       PedMeansR,
  					       xerrors,
  					       PedMeanErrorsR);
  gMeansR->SetTitle("Gauss Fit Means");
  gMeansR->SetName("MeansR");
  gMeansR->GetXaxis()->SetTitle("Bar");
  gMeansR->GetYaxis()->SetTitle("Amplitude of Gauss Fit to Pedestal");
  gMeansR->SetMarkerColor(kGreen); gMeansR->SetMarkerStyle(21);
  // gaus sigmas
  // left
  TGraphErrors *gSigmasL = new TGraphErrors(nBars,
  					       bars,
  					       PedSigmasL,
  					       xerrors,
  					       PedSigmaErrorsL);
  gSigmasL->SetTitle("Gauss Fit Sigmas");
  gSigmasL->SetName("SigmasL");
  gSigmasL->GetXaxis()->SetTitle("Bar");
  gSigmasL->GetYaxis()->SetTitle("Amplitude of Gauss Fit to Pedestal");
  gSigmasL->SetMarkerColor(kBlue); gSigmasL->SetMarkerStyle(21);
  // right
  TGraphErrors *gSigmasR = new TGraphErrors(nBars,
  					       bars,
  					       PedSigmasR,
  					       xerrors,
  					       PedSigmaErrorsR);
  gSigmasR->SetTitle("Gauss Fit Sigmas");
  gSigmasR->SetName("SigmasR");
  gSigmasR->GetXaxis()->SetTitle("Bar");
  gSigmasR->GetYaxis()->SetTitle("Amplitude of Gauss Fit to Pedestal");
  gSigmasR->SetMarkerColor(kGreen); gSigmasR->SetMarkerStyle(21);

  // draw graphs
  // amps
  TCanvas *cAmplitudes = new TCanvas();
  cAmplitudes->SetName("cAmplitudesLeftVRight");
  cAmplitudes->cd();
  gAmplitudesL->Draw("AP");
  gAmplitudesR->Draw("SAMEP");
  TLegend *lAmps = new TLegend(0.1,0.1,0.3,0.3);
  lAmps->SetHeader("pmt sides");
  lAmps->AddEntry("AmplitudesL","Left");
  lAmps->AddEntry("AmplitudesR","Right");
  lAmps->Draw();
  // means
  TCanvas *cMeans = new TCanvas();
  cMeans->SetName("cMeansLeftVRight");
  cMeans->cd();
  gMeansL->Draw("AP");
  gMeansR->Draw("SAMEP");
  TLegend *lMeans = new TLegend(0.1,0.1,0.3,0.3);
  lMeans->SetHeader("pmt sides");
  lMeans->AddEntry("MeansL","Left");
  lMeans->AddEntry("MeansR","Right");
  lMeans->Draw();
  // sigmas
  TCanvas *cSigmas = new TCanvas();
  cSigmas->SetName("cSigmasLeftVRight");
  cSigmas->cd();
  gSigmasL->Draw("AP");
  gSigmasR->Draw("SAMEP");
  TLegend *lSigmas = new TLegend(0.1,0.1,0.3,0.3);
  lSigmas->SetHeader("pmt sides");
  lSigmas->AddEntry("SigmasL","Left");
  lSigmas->AddEntry("SigmasR","Right");
  lSigmas->Draw();


 //========================================================== Draw Fit Results
  TCanvas *cLeft = new TCanvas("cLeft",
  			       "Left PMTs, ADC spectra",
  			       900,700);
  cLeft->Divide(8,4);
  for(Int_t b=0; b<nBars; b++){
    cLeft->cd(b+1);
    gPad->SetLogy();
    hADCL[b]->Draw();
    TLine *lL = new TLine(PedMeansL[b]+Cut*PedSigmasL[b],
    			  0.,
    			  PedMeansL[b]+Cut*PedSigmasL[b],
    			  PedAmpsL[b]);
    lL->SetLineColor(kGreen);
    lL->Draw("SAMES");
  }

  TCanvas *cRight = new TCanvas("cRight",
  			       "Right PMTs, ADC spectra",
  			       900,700);
  cRight->Divide(8,4);
  for(Int_t b=0; b<nBars; b++){
    cRight->cd(b+1);
    gPad->SetLogy();
    hADCR[b]->Draw();
    TLine *lR = new TLine(PedMeansR[b]+Cut*PedSigmasR[b],
    			  0.,
    			  PedMeansR[b]+Cut*PedSigmasR[b],
    			  PedAmpsR[b]);
    lR->SetLineColor(kGreen);
    lR->Draw("SAMES");
  }



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
  hADCAmplitudesL->GetXaxis()->SetTitle("Bar");
  hADCAmplitudesL->GetYaxis()->SetTitle("Ped Fit Amplitude");
  hADCAmplitudesL->Write();
  hADCMeansL->GetXaxis()->SetTitle("Bar");
  hADCMeansL->GetYaxis()->SetTitle("Ped Fit Mean");
  hADCMeansL->Write();
  hADCSigmasL->GetXaxis()->SetTitle("Bar");
  hADCSigmasL->GetYaxis()->SetTitle("Ped Fit Sigma");
  hADCSigmasL->Write();
  // graphs of results not for use with online gui
  cAmplitudes->Write();
  gAmplitudesL->Write();
  gAmplitudesR->Write();
  cMeans->Write();
  gMeansL->Write();
  gMeansR->Write();
  cSigmas->Write();
  gSigmasL->Write();
  gSigmasR->Write();



  //========================================================== Close output file
  f->Close();
  // tidy up canvases
  delete cLeft;
  delete cRight;
  delete cAmplitudes;
  delete cMeans;
  delete cSigmas;

  

  //================================================================== End Macro
}// end macro



