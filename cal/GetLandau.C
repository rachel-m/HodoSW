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

#include "SBSTree.C"

const Int_t nAdc = 64;
const Int_t nBars = 32;
const Int_t nSide = 2;

const Int_t adcbarstart = 32;

//TString REPLAYED_DIR = "/adaqfs/home/a-onl/sbs/Rootfiles/";
//TString ANALYSED_DIR = "/adaqfs/home/a-onl/sbs/Rootfiles/bbhodo_hist";

// for local analysis at uog (please leave in comments)
//TString REPLAYED_DIR = "/w/work0/home/rachel/HallA/BB_Hodo/FallRun2021/Replayed";
//TString ANALYSED_DIR = "/w/work0/home/rachel/HallA/BB_Hodo/FallRun2021/Analysed";

// for local analysis at jlab (please leave in comments)
TString REPLAYED_DIR = "/volatile/halla/sbs/gpenman/Rootfiles";
TString ANALYSED_DIR = "/volatile/halla/sbs/gpenman/Analysed";

/*
namespace Thodo {
  Int_t NdataAdcBar;
  Double_t ADCBar[nBars];
  Int_t NdataAdcL;
  Double_t ADCValL[nBars];
  Int_t NdataAdcR;
  Double_t ADCValR[nBars];
  //  Int_t ADCBarOff[nBars];
};
*/

TChain *C;

using namespace std;

void GetLandau(const Int_t RunNum=14015, Int_t nevents=-1, bool DoBar=false,
	       Double_t FitStart=0.0, Double_t FitStop = 80.0,
	       Double_t Width=40.0, Int_t HistRange=1000){
  // InFile is the input file without absolute path and without .root suffix
  // nevents is how many events to analyse, -1 for all
  // FitStart is the guess for the valley position before the landau, will be fit start range, in adc bins
  // FitStop is the upper limit of the fit range
  // Width if initial guess for the width of the landau in adc bins
  // HistRange is the upper limit of the histogram to plot in adc bins

  // To execute
  // .L GetLandau.C+
  // GetLandau("filename",-1,150.0,1000.0,40.0,3000)

  TString prefix, sRunNum, snevents, sInFile;
  //========================================================= Get data from tree
  if(!C) { 
    prefix = "e1209019_bbhodo_";
    sRunNum = std::to_string(RunNum);
    snevents = std::to_string(nevents);
    //TString sInFile = REPLAYED_DIR + "/" + InFile + ".root";
    sInFile = REPLAYED_DIR + "/" + prefix + sRunNum;
    cout << "Adding " << sInFile << endl;
    C = new TChain("T");
    C->Add(sInFile+"*");
    
    // disable all branches
    //C->SetBranchStatus("*",0);
    // enable adc branches
    //C->SetBranchStatus("bb.hodoadc.*",1);
    //C->SetBranchAddress("bb.hodoadc.bar.adc.id",Thodo::ADCBar);
    //C->SetBranchAddress("bb.hodoadc.bar.adc.L.ap",Thodo::ADCValL);
    //C->SetBranchAddress("bb.hodoadc.bar.adc.R.ap",Thodo::ADCValR);
    // C->SetBranchAddress("bb.hodoadc.adcbaroff",Thodo::ADCBarOff);
    // enable vector size branches
    //C->SetBranchStatus("Ndata.bb.hodoadc.*",1);
    //C->SetBranchAddress("Ndata.bb.hodoadc.bar.adc.id",&Thodo::NdataAdcBar);
    //C->SetBranchAddress("Ndata.bb.hodoadc.bar.adc.L.ap",&Thodo::NdataAdcL);
    //C->SetBranchAddress("Ndata.bb.hodoadc.bar.adc.R.ap",&Thodo::NdataAdcR);  
    
  }//setting tree
  
  
  
  //========================================================= Check no of events
  SBSTree *T = new  SBSTree(C);
  
  Int_t Nev = C->GetEntries();
  cout << "N entries in tree is " << Nev << endl;
  Int_t NEventsAnalysis;
  if(nevents==-1) NEventsAnalysis = Nev;
  else NEventsAnalysis = nevents;
  //NEventsAnalysis = 500000;
  cout << "Running analysis for " << NEventsAnalysis << " events" << endl;
  

  
  //==================================================== Check the bar offset
  //T->GetEntry(0);
  //Int_t adcbarstart = (Int_t)Thodo::ADCBar[0];
  //cout << "adcbarstart " << adcbarstart << endl;

  
  
  //==================================================== Create output root file
  // root file for viewing fits
  TString outrootfile = ANALYSED_DIR + "/LandauFits_" + prefix + sRunNum + "_" + DoBar + ".root";
  TFile *f = new TFile(outrootfile, "RECREATE");



  //==================================================== Create output text file
  // text file for recording fit results
  ofstream landautextfile;
  TString outtxtfile = ANALYSED_DIR + "/LandauFits_" + prefix + sRunNum + "_" + DoBar + ".txt";
  landautextfile.open(outtxtfile);



  //===================================================== Histogram Declarations
  // number of adc bins
  Int_t NAdcBins = HistRange;//4096;
  Double_t AdcBinLow = -0.5;
  Double_t AdcBinHigh = HistRange+0.5;//4095;

  // ADC histos
  TH1F *hADCL[nBars];
  TH1F *hADCR[nBars];

  for(Int_t bar=0; bar<nBars; bar++){
    Int_t b = adcbarstart+bar;
    hADCL[bar] = new TH1F(TString::Format("hADC_Bar%d_L",b),
			  TString::Format("hADC_Bar%d_L",b),
			  NAdcBins, AdcBinLow, AdcBinHigh);
    
    hADCR[bar] = new TH1F(TString::Format("hADC_Bar%d_R",b),
			  TString::Format("hADC_Bar%d_R",b),
			  NAdcBins, AdcBinLow, AdcBinHigh);
  }
  
  //new histo to look at 2d plot (like online plots)
  TH2F *hBarVsADC = new TH2F("hBarVsADC","",
			     //NAdcBins, AdcBinLow, AdcBinHigh,
			     NAdcBins, AdcBinLow, 400,
			     nBars, 0.0+adcbarstart, nAdc+adcbarstart);
			     
  
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
  for(Int_t event=0; event<NEventsAnalysis; event++){
    
    C->GetEntry(event);
    
    if (event % 100000 == 0) 
      cout << event << "/" << NEventsAnalysis << endl;
    
    if (DoBar == false){
      //assumming mapping goes 0-31 L, 32-64 R.
      Int_t NadcelemID = T->Ndata_bb_hodoadc_adcelemID;
      //cout << "Number of adc hits: " << NadcelemID << endl;
      for (Int_t i=0; i<NadcelemID; i++){
	Int_t adcID = (int)T->bb_hodoadc_adcelemID[i];
	Double_t a_p = T->bb_hodoadc_a_p[i]; //pedestal corrected integral	    
	//Double_t a_p = T->bb_hodoadc_a_amp_p[i]; //pedestal corrected amplitude
 
	//cout for debugging
	//cout << "id: " <<  adcID << " a_p: " << a_p << endl;
	
	if (adcID >= 0 && adcID <= 31){ 
	  hADCL[adcID]->Fill(a_p);
	  hBarVsADC->Fill(a_p,adcID+adcbarstart);
	}else if (adcID >= 32 && adcID <= 63){
	  hADCR[adcID-32]->Fill(a_p);
	  hBarVsADC->Fill(a_p,adcID+adcbarstart);
	}
	else{
	   cout << "WTF?" << endl;
	   continue;
	}
      }
    }else if (DoBar == true){
      Int_t NadcbarID = (int)T->Ndata_bb_hodoadc_bar_adc_id;
      //cout << "Number of bar entries: " << NadcbarID << endl;
      for (Int_t i=0; i<NadcbarID; i++){
	Double_t DadcbarID = T->bb_hodoadc_bar_adc_id[i];
	Int_t adcbarID = (int)T->bb_hodoadc_bar_adc_id[i];
	Double_t L_a_p = T->bb_hodoadc_bar_adc_L_ap[i];
	Double_t R_a_p = T->bb_hodoadc_bar_adc_R_ap[i];
	
	//cout  << "id: " << adcbarID << " L_a_p: " << L_a_p << " R_a_p: " << R_a_p <<   endl;
      
	if (adcbarID - adcbarstart > 31) {
	  cout << "Error: adcbarID = " << adcbarID << " is > 31. Before cast to Int_t, value is " << DadcbarID << ". Skipping this event" << endl;
	  continue;
	}
	else{
	  hADCL[adcbarID]->Fill(L_a_p);
	  hADCR[adcbarID]->Fill(R_a_p);
	  hBarVsADC->Fill(L_a_p, adcbarID);
	  hBarVsADC->Fill(R_a_p, adcbarID);
	}      
      }
    }
  }// event loop
  

  //exit(0);
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
    Int_t b = adcbarstart+bar;

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
    fLandauL[bar] = new TF1(TString::Format("fLandau_Bar%d_L",b),
			    "landau",FitStart, FitStop);
    // fLandauL[bar]->SetParameter(0, binmaxcontentL);
    fLandauL[bar]->SetParameter(1, maxbincentreL);
    fLandauL[bar]->SetParameter(2, Width);
    // right
    fLandauR[bar] = new TF1(TString::Format("fLandau_Bar%d_R",b),
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
  			       "Left PMTs, ADC spectra",
  			       900,700);
  cLeft1->Divide(4,4);
  for(Int_t b=0; b<nBars/2; b++){
    cLeft1->cd(b+1);
    //gPad->SetLogy();
    hADCL[b]->Draw();
  }
  
  TCanvas *cLeft2 = new TCanvas("cLeft2",
  			       "Left PMTs, ADC spectra",
  			       900,700);
  cLeft2->Divide(4,4);
  for(Int_t b=(nBars/2); b<nBars; b++){
    cLeft2->cd(b+1-nBars/2);
    //gPad->SetLogy();
    hADCL[b]->Draw();
  }
  

  //Right Bars
  TCanvas *cRight1 = new TCanvas("cRight1",
				"Right1 PMTs, ADC spectra",
				900,700);
  cRight1->Divide(4,4);
  for(Int_t b=0; b<nBars/2; b++){
    cRight1->cd(b+1);
    //gPad->SetLogy();
    hADCR[b]->Draw();
  }

  TCanvas *cRight2 = new TCanvas("cRight2",
  			       "Right2 PMTs, ADC spectra",
  			       900,700);
  cRight2->Divide(4,4);
  for(Int_t b=nBars/2; b<nBars; b++){
    cRight2->cd(b+1-nBars/2);
    //gPad->SetLogy();
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
  f->cd();
  gDirectory->mkdir("ADC");
  f->cd("ADC");
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

  gSystem->Exec(Form("pdfunite temp*.pdf LandauPlots_%i_%d.pdf",RunNum,DoBar));
  gSystem->Exec("rm temp*.pdf");

  //========================================================== Close output file
  //f->Close();
  // tidy up canvases
  //delete cConstants;
  //delete cMPV;
  //delete cWidth;
  //delete cadc;
  //cLeft1->Close();
  //cLeft2->Close();
  //cRight1->Close();
  //cRight2->Close();
  //cConstants->Close();

  //================================================================== End Macro
}// end macro



