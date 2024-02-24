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

//TString REPLAYED_DIR = "/adaqfs/home/a-onl/sbs/Rootfiles/";
//TString ANALYSED_DIR = "/adaqfs/home/a-onl/sbs/Rootfiles/bbhodo_hist";

// for local analysis at uog (please leave in comments)
//TString REPLAYED_DIR = "/w/work0/home/rachel/HallA/BB_Hodo/FallRun2021/Replayed";
//TString ANALYSED_DIR = "/w/work0/home/rachel/HallA/BB_Hodo/FallRun2021/Analysed";

// for local analysis at jlab (please leave in comments)
TString REPLAYED_DIR = "/volatile/halla/sbs/gpenman/Rootfiles";
TString ANALYSED_DIR = "/volatile/halla/sbs/gpenman/Analysed";


TChain *C;
SBSTree *T;

using namespace std;


void GetLandau(const Int_t RunNum=14032, Double_t ADCcut=2.0, Int_t nevents=-1, bool DoBars=true,
	       Int_t HistRange=1000.0){
  //ADC Cut Values [700V,800V,900V,1000V] = [?,?,?,200]
  // RunNum is the run number to analyze
  // nevents is how many events to analyse, -1 for all
  // DoBars is to use generic detector variables or hodoscope class bar variables
  // FitStart is the guess for the valley position before the landau, will be fit start range, in adc bins
  // FitStop is the upper limit of the fit range
  // Width if initial guess for the width of the landau in adc bins
  // HistRange is the upper limit of the histogram to plot in adc bins

  // To execute
  // .L GetLandau.C+
  // GetLandau("RunNumber",-1,150.0,1000.0,40.0,3000)

  TString prefix, sRunNum, sInFile;
  //========================================================= Get data from tree
  if(!C) { 
    prefix = "e1209019_bbhodo_";
    sRunNum = std::to_string(RunNum);
    //TString sInFile = REPLAYED_DIR + "/" + InFile + ".root";
    sInFile = REPLAYED_DIR + "/" + prefix + sRunNum;
    cout << "Adding " << sInFile << endl;
    C = new TChain("T");
    C->Add(sInFile+"*");
  }
  
  if(!T){
    T = new  SBSTree(C);
  }//setting tree
  
  
 
  //========================================================= Check no of events
  Int_t Nev = C->GetEntries();
  cout << "N entries in tree is " << Nev << endl;
  Int_t NEventsAnalysis;
  if(nevents==-1) NEventsAnalysis = Nev;
  else NEventsAnalysis = nevents;
  cout << "Running analysis for " << NEventsAnalysis << " events" << endl;
  

  
  //==================================================== Check the bar offset
  //T->GetEntry(0);
  //Int_t adcbarstart = (Int_t)Thodo::ADCBar[0];
  //cout << "adcbarstart " << adcbarstart << endl;

  
  
  //==================================================== Create output root file
  // root file for viewing fits
  TString outrootfile = ANALYSED_DIR + "/ADCSpectra_" + prefix + sRunNum + "_" + DoBars + ".root";
  TFile *f = new TFile(outrootfile, "RECREATE");

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
			    

  //================================================================= Event Loop
  for(Int_t event=0; event<NEventsAnalysis; event++){
    
    T->GetEntry(event);
    
    if (event % 100000 == 0) 
      cout << event << "/" << NEventsAnalysis << endl;
    
    if (!DoBars){
      //assumming mapping goes 0-31 L, 32-64 R.
      Int_t NadcelemID = T->Ndata_bb_hodoadc_adcelemID;
      //cout << "Number of adc hits: " << NadcelemID << endl;
      for (Int_t i=0; i<NadcelemID; i++){
	Int_t adcID = (int)T->bb_hodoadc_adcelemID[i];
	Double_t a_p = T->bb_hodoadc_a[i]; //no ped sub
	//Double_t a_p = T->bb_hodoadc_a_p[i]; //pedestal corrected integral	    
	//Double_t a_p = T->bb_hodoadc_a_amp_p[i]; //pedestal corrected amplitude
 
	//cout for debugging
	//cout << "id: " <<  adcID << " a_p: " << a_p << endl;
	
	//LEFT LOOP
	if (adcID >= 0 && adcID <= 31){
	  if(adcID == 0 && T->bb_hodoadc_a[i+1]>ADCcut && T->bb_hodoadc_a[i+NadcelemID/2+1]>ADCcut){
	    hADCL[adcID]->Fill(a_p);
	  }
	  else if(adcID == 31 && T->bb_hodoadc_a[i-1]>ADCcut && T->bb_hodoadc_a[i+NadcelemID/2-1]>ADCcut){
	    hADCL[adcID]->Fill(a_p);
	  }
	  else if(T->bb_hodoadc_a[i+1]>ADCcut && T->bb_hodoadc_a[i-1]>ADCcut
		  && T->bb_hodoadc_a[i+NadcelemID/2+1]>ADCcut && T->bb_hodoadc_a[i+NadcelemID/2-1]>ADCcut){
	    hADCL[adcID]->Fill(a_p);
	  }
	  hBarVsADC->Fill(a_p,adcID+adcbarstart);
	}
	//RIGHT LOOP
	else if (adcID >= 32 && adcID <= 63){
	  if(adcID == 32 && T->bb_hodoadc_a[i+1]>ADCcut && T->bb_hodoadc_a[i-NadcelemID/2+1]>ADCcut){
	    hADCR[adcID-32]->Fill(a_p);
	  }
	  else if(adcID == 63 && T->bb_hodoadc_a[i-1]>ADCcut && T->bb_hodoadc_a[i-NadcelemID/2-1]>ADCcut){
	    hADCR[adcID-32]->Fill(a_p);
	  }
	  else if(T->bb_hodoadc_a[i+1]>ADCcut && T->bb_hodoadc_a[i-1]>ADCcut && T->bb_hodoadc_a[i-NadcelemID/2-1]>ADCcut && T->bb_hodoadc_a[i-NadcelemID/2+1]>ADCcut){
	    hADCR[adcID-32]->Fill(a_p);
	  }
	  hBarVsADC->Fill(a_p,adcID+adcbarstart);
	}
	else{
	   cout << "Bar value out of range 0-63, check offset value! " << adcID << endl;
	   continue;
	}
      }
    }else if (DoBars){
      Int_t NadcbarID = floor(T->Ndata_bb_hodoadc_bar_adc_id);
      for (Int_t i=0; i<NadcbarID; i++){
	Double_t DadcbarID = T->bb_hodoadc_bar_adc_id[i];
	Int_t adcbarID = floor(T->bb_hodoadc_bar_adc_id[i]);
	Double_t L_a_p = T->bb_hodoadc_bar_adc_L_ap[i];
	Double_t R_a_p = T->bb_hodoadc_bar_adc_R_ap[i];
	
	//cout  << "id: " << adcbarID << " L_a_p: " << L_a_p << " R_a_p: " << R_a_p <<   endl;
      
	if (adcbarID - adcbarstart > 31) {
	  cout << "Error: adcbarID = " << adcbarID << " is > 31. Before cast to Int_t, value is " << DadcbarID << ". Skipping this event" << endl;
	  continue;
	}
	else{
	  hADCL[adcbarID - adcbarstart]->Fill(L_a_p);
	  hADCR[adcbarID - adcbarstart]->Fill(R_a_p);
	  hBarVsADC->Fill(L_a_p, adcbarID);
	  hBarVsADC->Fill(R_a_p, adcbarID+adcbarstart);
	}      
      }
    }
  }// event loop
 
  //Left Bars
  TCanvas *cLeft1 = new TCanvas("cLeft1",
  			       "Left PMTs, ADC spectra",
  			       900,700);
  cLeft1->Divide(4,4);
  for(Int_t b=0; b<nBars/2; b++){
    cLeft1->cd(b+1);
    gPad->SetLogy();
    hADCL[b]->Draw();
  }
  
  TCanvas *cLeft2 = new TCanvas("cLeft2",
  			       "Left PMTs, ADC spectra",
  			       900,700);
  cLeft2->Divide(4,4);
  for(Int_t b=(nBars/2); b<nBars; b++){
    cLeft2->cd(b+1-nBars/2);
    gPad->SetLogy();
    hADCL[b]->Draw();
  }
  

  //Right Bars
  TCanvas *cRight1 = new TCanvas("cRight1",
				"Right1 PMTs, ADC spectra",
				900,700);
  cRight1->Divide(4,4);
  for(Int_t b=0; b<nBars/2; b++){
    cRight1->cd(b+1);
    gPad->SetLogy();
    hADCR[b]->Draw();
  }

  TCanvas *cRight2 = new TCanvas("cRight2",
  			       "Right2 PMTs, ADC spectra",
  			       900,700);
  cRight2->Divide(4,4);
  for(Int_t b=nBars/2; b<nBars; b++){
    cRight2->cd(b+1-nBars/2);
    gPad->SetLogy();
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
  hBarVsADC->Write();
  for(Int_t bar=0; bar<(nBars); bar++){
    hADCL[bar]->GetXaxis()->SetTitle("ADC bin");
    hADCL[bar]->Write();
    hADCR[bar]->GetXaxis()->SetTitle("ADC bin");
    hADCR[bar]->Write();
  }
  
 

  gSystem->Exec(Form("pdfunite temp*.pdf RawADC_%i.pdf",RunNum));
  gSystem->Exec("rm temp*.pdf");
  
  //========================================================== Close output file
  //f->Close();
  // tidy up canvases
  cLeft1->Close();
  cLeft2->Close();
  cRight1->Close();
  cRight2->Close();
  c2D->Close();
  //================================================================== End Macro
}


