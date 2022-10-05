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
#include <TSpectrum.h>

#include "SBSTree.C"

const Int_t nAdc = 64;
const Int_t nBars = 32;
const Int_t nSide = 2;

const Int_t adcbarstart = 32;

// for local analysis at jlab (please leave in comments)
TString REPLAYED_DIR = "/volatile/halla/sbs/gpenman/Rootfiles";
TString ANALYSED_DIR = "/volatile/halla/sbs/gpenman/Analysed";


TChain *C;
SBSTree *T;

using namespace std;

void FitLandau(const Int_t RunNum = 14032, bool DoBars=true, Double_t FitStart=0.0, Double_t FitStop=80.0, Double_t Width=40.0, Int_t HistRange=1000.0){
   // RunNum is the run number to analyze
   // DoBars is to use generic detector variables or hodoscope class bar variables
  // FitStart is the guess for the valley position before the landau, will be fit start range, in adc bins
  // FitStop is the upper limit of the fit range
  // Width if initial guess for the width of the landau in adc bins
  
  TString prefix = "e1209019_bbhodo_";
  TString sRunNum = std::to_string(RunNum);
  
  TString inrootfile = ANALYSED_DIR + "/ADCSpectra_" + prefix + sRunNum + "_" + DoBars + ".root";
  
  TString outrootfile = ANALYSED_DIR + "/LandauFits_" + prefix + sRunNum + "_" + DoBars + ".root";
  TFile *f = new TFile(inrootfile, "READ");
  TFile *fout = new TFile(outrootfile, "RECREATE");
  
  //==================================================== Create output text file
  // text file for recording fit results
  ofstream landautextfile;
  TString outtxtfile = ANALYSED_DIR + "/LandauFits_" + prefix + sRunNum + "_" + DoBars + ".txt";
  landautextfile.open(outtxtfile);

  //===================================================== Histogram Declarations
  // number of adc bins
  Int_t NAdcBins = HistRange;//4096;
  Double_t AdcBinLow = -0.5;
  Double_t AdcBinHigh = HistRange+0.5;//4095;

  TH1D *hADCL[nBars];
  TH1D *hADCR[nBars];
  
  for(int i=0; i<nBars; i++){
    int b = i + adcbarstart;
    hADCL[i] = (TH1D*)f->Get(Form("ADC/hADC_Bar%i_L",b));
    hADCR[i] = (TH1D*)f->Get(Form("ADC/hADC_Bar%i_R",b));
  }
  
  //new histo to look at 2d plot (like online plots)
  TH2F *hBarVsADC = (TH2F*)f->Get("ADC/hBarVsADC");
  
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
  
  

  //start fitting
  TF1 *fLandauL[nBars];
  TF1 *fLandauR[nBars];
  
  //Try TSpectrum for unremoved pedestals
  TSpectrum *sLeft[nBars];
  TSpectrum *sRight[nBars];
  
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
    Int_t b = adcbarstart+bar;

    //get info on histogram to set initial pars    Int_t nBinsL = hADCL[bar]->GetNbinsX();
    
    Int_t nBinsR = hADCR[bar]->GetNbinsX();
    Int_t nBinsL = hADCL[bar]->GetNbinsX();
    if(nBinsL!=nBinsR){
      cout << "WARNING - check the hADCL and hADCR nbins matches" << endl;
      exit;
    }
    
    // find landau max position  
    Int_t maxbinL = hADCL[bar]->GetMaximumBin();
    Int_t maxbincentreL = hADCL[bar]->GetBinCenter(maxbinL);
    Double_t maxbincontentL = hADCL[bar]->GetBinContent(maxbinL);
    Int_t maxbinR = hADCR[bar]->GetMaximumBin();
    Int_t maxbincentreR = hADCR[bar]->GetBinCenter(maxbinR);
    Double_t maxbincontentR = hADCR[bar]->GetBinContent(maxbinR);
   
    Int_t nFirstBinL = hADCL[bar]->FindFirstBinAbove(0);
    Int_t nFirstBinR = hADCR[bar]->FindFirstBinAbove(0);
    Int_t nLastBinL = hADCL[bar]->FindLastBinAbove(0);
    Int_t nLastBinR = hADCR[bar]->FindLastBinAbove(0);
    
    Double_t FitStartL = hADCL[bar]->GetBinCenter(nFirstBinL);
    Double_t FitStartR = hADCR[bar]->GetBinCenter(nFirstBinR);
    Double_t FitStopL = hADCL[bar]->GetBinCenter(nLastBinL);
    Double_t FitStopR = hADCR[bar]->GetBinCenter(nLastBinR);
    
    hADCL[bar]->Rebin(5);
    hADCR[bar]->Rebin(5);
    
    Double_t newRange = 600;
    
    hADCL[bar]->GetXaxis()->SetRangeUser(0,newRange);
    hADCR[bar]->GetXaxis()->SetRangeUser(0,newRange);
    
    //Search for multiple peaks
    Int_t nfoundL = 0;
    Int_t nfoundR = 0;
    Double_t threshL = 0.025;
    Double_t threshR = 0.025;
    sLeft[bar] = new TSpectrum(2);
    sRight[bar] = new TSpectrum(2);
   
    nfoundL= sLeft[bar]->Search(hADCL[bar],2,"",threshL);
    nfoundR = sRight[bar]->Search(hADCR[bar],2,"",threshR);
    cout << bar << " "  << nfoundL << " " << nfoundR << endl;
    
    double *xpeaksL = sLeft[bar]->GetPositionX();
    double *xpeaksR = sRight[bar]->GetPositionX();
    
    double xL1 = hADCL[bar]->FindBin(xpeaksL[0]);
    double aL1 = hADCL[bar]->GetBinContent(xL1); 
    double bL1 = hADCL[bar]->GetBinCenter(xL1);
            
    // left
    if(nfoundL == 2){
      double xL2 = hADCL[bar]->FindBin(xpeaksL[1]);
      double aL2 = hADCL[bar]->GetBinContent(xL2); 
      double bL2 = hADCL[bar]->GetBinCenter(xL2);
      
      //FitStopL = hADCL[bar]->FindBin(xpeaksL[1]+3*Width);
      
      fLandauL[bar] = new TF1(TString::Format("fLandau_Bar%d_L",b),
			      "landau(0)+gaus(3)",FitStartL, FitStopL);
      fLandauL[bar]->SetParameter(0, aL2);
      fLandauL[bar]->SetParameter(1, bL2);
      fLandauL[bar]->SetParameter(2, Width);
      fLandauL[bar]->SetParameter(3, aL1);
      fLandauL[bar]->SetParameter(4, bL1);
      fLandauL[bar]->SetParameter(5, Width/2);
      hADCL[bar]->Fit(fLandauL[bar],"QR");
    }else{
      fLandauL[bar] = new TF1(TString::Format("fLandau_Bar%d_L",b),
			      "gaus",FitStartL, FitStopL);
      //fLandauL[bar]->SetParameter(0, aL1);
      //fLandauL[bar]->SetParameter(1, bL1);
      //fLandauL[bar]->SetParameter(2, Width/2);
      hADCL[bar]->Fit(fLandauL[bar],"QR");
    }
    
    double xR1 = hADCR[bar]->FindBin(xpeaksR[0]);
    double aR1 = hADCR[bar]->GetBinContent(xR1); 
    double bR1 = hADCR[bar]->GetBinCenter(xR1);
     
    // right
    if(nfoundR == 2){
      double xR2 = hADCR[bar]->FindBin(xpeaksR[1]);
      double aR2 = hADCR[bar]->GetBinContent(xR2); 
      double bR2 = hADCR[bar]->GetBinCenter(xR2);

      fLandauR[bar] = new TF1(TString::Format("fLandau_Bar%d_L",b),
			      "landau(0)+gaus(3)",FitStartR, FitStopR);
      fLandauR[bar]->SetParameter(0, aR2); 
      fLandauR[bar]->SetParameter(1, bR2); 
      fLandauR[bar]->SetParameter(2, Width);
      fLandauR[bar]->SetParameter(3, aR1); 
      fLandauR[bar]->SetParameter(4, bR1); 
      fLandauR[bar]->SetParameter(5, Width/2);
      hADCR[bar]->Fit(fLandauR[bar],"QR");
      
    }else{
      fLandauR[bar] = new TF1(TString::Format("fLandau_Bar%d_R",b),
			      "gaus",FitStartR, FitStopR);
      fLandauR[bar]->SetParameter(0, aR1);
      fLandauR[bar]->SetParameter(1, bR1);
      fLandauR[bar]->SetParameter(2, Width/2);
      hADCR[bar]->Fit(fLandauR[bar],"QR");
    }
    
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
    Int_t b = adcbarstart+bar;
    landautextfile << b << "\t" << LaundauMPVL[bar]
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
    Int_t b = adcbarstart+bar;
    
    xerrors[bar] = 0.0;
    bars[bar] = b;
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
  cConstants->Print("temp1.pdf");
  
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
  cMPV->Print("temp2.pdf");
  
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
  cWidth->Print("temp3.pdf");
  
 //========================================================== Draw Fit Results
  //Left Bars
  TCanvas *cLeft1 = new TCanvas("cLeft1",
  			       "Left1 PMTs, ADC spectra",
  			       900,700);
  cLeft1->Divide(4,4);
  for(Int_t b=0; b<nBars/2; b++){
    cLeft1->cd(b+1);
    gPad->SetLogy(0);
    hADCL[b]->Draw();
  }
  
  TCanvas *cLeft2 = new TCanvas("cLeft2",
  			       "Left2 PMTs, ADC spectra",
  			       900,700);
  cLeft2->Divide(4,4);
  for(Int_t b=(nBars/2); b<nBars; b++){
    cLeft2->cd(b+1-nBars/2);
    gPad->SetLogy(0);
    hADCL[b]->Draw();
  }
  

  //Right Bars
  TCanvas *cRight1 = new TCanvas("cRight1",
				"Right1 PMTs, ADC spectra",
				900,700);
  cRight1->Divide(4,4);
  for(Int_t b=0; b<nBars/2; b++){
    cRight1->cd(b+1);
    gPad->SetLogy(0);
    hADCR[b]->Draw();
  }

  TCanvas *cRight2 = new TCanvas("cRight2",
  			       "Right2 PMTs, ADC spectra",
  			       900,700);
  cRight2->Divide(4,4);
  for(Int_t b=nBars/2; b<nBars; b++){
    cRight2->cd(b+1-nBars/2);
    gPad->SetLogy(0);
    hADCR[b]->Draw();
  }

  cLeft1->Print("temp41.pdf");
  cLeft2->Print("temp42.pdf");
  cRight1->Print("temp51.pdf");
  cRight2->Print("temp52.pdf");
  
  TCanvas *c2D = new TCanvas("c2D",
			     "2D Online Plot",
			     900, 700);
  c2D->cd();
  hBarVsADC->GetXaxis()->SetTitle("ADC Value");
  hBarVsADC->GetYaxis()->SetTitle("ADC ID");
  hBarVsADC->Draw("colz");
  c2D->Print("temp6.pdf");
  
  //=============================================== Write/Draw Histograms/Graphs
  fout->cd();
  gDirectory->mkdir("ADC");
  fout->cd("ADC");
  // write the canvases with multiplots
  cLeft1->Write();
  cLeft2->Write();
  cRight1->Write();
  cRight2->Write();
  c2D->Write();
  TCanvas *cadc = new TCanvas();
  cadc->cd();
  for(Int_t bar=0; bar<(nBars); bar++){
    hADCL[bar]->GetXaxis()->SetTitle("ADC bin");
    hADCL[bar]->Write();
    hADCR[bar]->GetXaxis()->SetTitle("ADC bin");
    hADCR[bar]->Write();
  }
  
  fout->cd();
  gDirectory->mkdir("FitResults");
  fout->cd("FitResults");
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

  gSystem->Exec(Form("pdfunite temp*.pdf LandauPlots_%i_%d.pdf",RunNum,DoBars));
  gSystem->Exec("rm temp*.pdf");

  //========================================================== Close output file
  //fout->Close();
  // tidy up canvases
  delete cConstants;
  delete cMPV;
  delete cWidth;
  delete cadc;
  //cLeft1->Close();
  //cLeft2->Close();
  //cRight1->Close();
  //cRight2->Close();
  c2D->Close();
  //================================================================== End Macro
  
}//END OF MACRO

