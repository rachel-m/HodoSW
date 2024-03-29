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

#include "SBSTree.C"

const Int_t nAdc = 64;
const Int_t nBarsADC = 32;
const Int_t nTdc = 180;
const Int_t nBarsTDC = 90;
const Int_t nSide = 2;

const Int_t adcbarstart = 32;

//const TString REPLAYED_DIR = "/adaqfs/home/a-onl/sbs/Rootfiles";
//const TString ANALYSED_DIR = "/adaqfs/home/a-onl/sbs/Rootfiles/bbhodo_hist";

// for local analysis at uog (please leave in comments)
//TString REPLAYED_DIR = "/w/work0/home/rachel/HallA/BB_Hodo/FallRun2021/Replayed";
//TString ANALYSED_DIR = "/w/work0/home/rachel/HallA/BB_Hodo/FallRun2021/Analysed";

// for local analysis at jlab (please leave in comments)
TString REPLAYED_DIR = "/volatile/halla/sbs/gpenman/Rootfiles";
TString ANALYSED_DIR = "/volatile/halla/sbs/gpenman/Analysed";

TChain *C;
SBSTree *T;

using namespace std;


void FitTOT(const Int_t RunNum=14032, Int_t nevents=-1, bool DoBars=false, Int_t DoFitTOT=1){
  // RunNum is the run number to analyze
  // nevents is how many events to analyse, -1 for all
  // DoFitTOT set this to 1 if you want to fit TOT v ADC

  // To execute script
  // root -l
  // .L FitTOT.C+
  // FitTOT("RunNumber",-1,1)
  
  TString prefix, sRunNum, sInFile;
  //========================================================= Get data from tree
  if(!C) { 
    prefix = "e1209019_bbhodo_";
    sRunNum = std::to_string(RunNum);
    sInFile = REPLAYED_DIR + "/" + prefix + sRunNum;
    cout << "Adding " << sInFile << endl;
    C = new TChain("T");
    C->Add(sInFile+"*");
  }
  
  if(!T){
    T = new SBSTree(C);
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
  // Float_t adcbarstart = Thodo::ADCBarOff[0];
  //cout << "Thodo::ADCBar[adcbar] " << Thodo::ADCBar[0] << endl;
  //Int_t adcbarstart = Thodo::ADCBar[0];
  

  //==================================================== Create output root file
  // root file for viewing fits
  TString outrootfile = ANALYSED_DIR + "/TOTFits_" + prefix + sRunNum + "_" + ".root";
  TFile *f = new TFile(outrootfile, "RECREATE");
  

  //===================================================== Histogram Declarations
  // number of adc bins
  Int_t NAdcBins = 200;//4096;
  Double_t AdcBinLow = 0.;
  Double_t AdcBinHigh = 1000;//4095.;
  Int_t NTdcBins = 80;
  Double_t TdcBinLow = 0.;
  Double_t TdcBinHigh = 40;//0.;

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
    Int_t adcbar = adcbarstart + bar;
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

    Int_t NdataAdcBar = T->Ndata_bb_hodoadc_bar_adc_id;
    Int_t NdataTdcBar = T->Ndata_bb_hodotdc_bar_tdc_id;
    Int_t NdataAdc = T->Ndata_bb_hodoadc_adcelemID;
    Int_t NdataTdc = T->Ndata_bb_hodotdc_tdcelemID;
    
    Int_t ADCBar, TDCBar, adcid; 
    Double_t ADCValL, ADCValR, TDCTotL, TDCTotR;
    if (!DoBars){
      for(Int_t adc=0; adc<NdataAdc; adc++){
	ADCBar = (int) T->bb_hodoadc_adcelemID[adc];
	if (ADCBar >= 0 && ADCBar < 32) ADCBar += adcbarstart;
	else if (ADCBar >= 32 && ADCBar < 64) ADCBar += 90;
	else {
	  cout << "Bar value out of range 0-63, check offset value! " << ADCBar << endl;
	  continue;
	}
	for(Int_t tdc=0; tdc<NdataTdc; tdc++){
	  TDCBar = (int) T->bb_hodotdc_tdcelemID[tdc];
	  if( ADCBar == TDCBar ){
	    ADCBar = (int) T->bb_hodoadc_adcelemID[adc];
	    if (ADCBar >= 0 && ADCBar < 32){
	      ADCValL = T->bb_hodoadc_a_p[adc];
	      TDCTotL = T->bb_hodotdc_tdc_tot[tdc];
	      hTOTvADCL[ADCBar]->Fill(ADCValL,TDCTotL);
	    }else if(ADCBar >= 32 && ADCBar < 64){
	      ADCValR = T->bb_hodoadc_a_p[adc];
	      TDCTotR = T->bb_hodotdc_tdc_tot[tdc];
	      hTOTvADCR[ADCBar-adcbarstart]->Fill(ADCValR,TDCTotR);
	    }
	  }
	}
      }
    }else if (DoBars){
      // check for tdc hits in the bars that match the adc bars instrumented
      for(Int_t adcbar=0; adcbar<NdataAdcBar; adcbar++){
	Double_t dADCBar = T->bb_hodoadc_bar_adc_id[adcbar]; 
	ADCBar = (int) T->bb_hodoadc_bar_adc_id[adcbar]; 
	if (ADCBar - adcbarstart > 31) {
	  cout << "Error: ADCBar = " << ADCBar << " is > 31. Before cast to Int_t, value is " << dADCBar << ". Skipping this event" << endl;
	  continue;
	}
	for(Int_t tdcbar=0; tdcbar<NdataTdcBar; tdcbar++){
	  TDCBar = T->bb_hodotdc_bar_tdc_id[tdcbar];
	  if( ADCBar == TDCBar ){
	    ADCValL = T->bb_hodoadc_bar_adc_L_ap[adcbar];
	    ADCValR = T->bb_hodoadc_bar_adc_R_ap[adcbar];
	    TDCTotL = T->bb_hodotdc_bar_tdc_L_tot[tdcbar];
	    TDCTotR = T->bb_hodotdc_bar_tdc_R_tot[tdcbar];
	  
	    hTOTvADCL[adcbar-adcbarstart]->Fill(ADCValL,TDCTotL);
	    hTOTvADCR[adcbar]->Fill(ADCValR,TDCTotR);
	  }// if adc==tdc bar
	}// tdc bar loop
      }// adc bar loop
    }else cout << "WTF?!" << endl;
    
    
  }// event loop
  

  //==================================================================== Fitting
  // FitSlicesY(f1,firstbin,lastbin,cut,option,arr)
  // if f1=0 it is a gauss
  // defualt option is QNR
  // cut means only fits x bins where the corresponding projection in y has >cut bins filled
  // generated histograms returned in arr
  // eg FitSlicesY(0,7,32,20) = fit gaussian in y for bins 7 to 32 with >20 counts in y proj

  if(DoFitTOT==1){
    // make a directory in output file
    f->cd();
    gDirectory->mkdir("FitResults");
    f->cd("FitResults");
    
    // text file for output
    ofstream tottextfile;
    TString outtxtfiletot = ANALYSED_DIR + "/TOTFits_TOT_" + sRunNum + ".txt";
    tottextfile.open(outtxtfiletot);
    
    //===================== fit for y direction
    // fit a combination fit to the mean values form fitslicey
    // combination fit is due to non linearity/slew of timing near threshold
    // [0]*x + [1] - ([2]/(x-[3]))
    
    // parameters outside loop below
    Int_t TOTStatCut = 8;//how many counts in y-proj we want for fit
    TF1 *fLeftTOT[nBarsADC];
    TF1 *fRightTOT[nBarsADC];
    
    for(Int_t b=0; b<nBarsADC; b++){
      Int_t adcbar = adcbarstart + b;

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
      hTOTvADCL[b]->Draw("COLZ");
      // do the fit slices y
      hTOTvADCL[b]->FitSlicesY(0,1,NAdcBins-1,TOTStatCut);
      // draw results
      // constant of each slice gauss
      leftPadTOT->cd(2);
      TH1D *hTOTvADCL_0 = (TH1D*)gDirectory->Get(TString::Format("hTOTvADC_Bar%d_L_%d",adcbar,0));
      hTOTvADCL_0->Draw();
      // mean of each slice gauss
      TPad *rightPadTOT = (TPad*)cleftTOT->cd(2);
      rightPadTOT->Divide(1,2);
      rightPadTOT->cd(1);
      gPad->SetTopMargin(0.12);
      gPad->SetLeftMargin(0.15);
      TH1D *hTOTvADCL_1 = (TH1D*)gDirectory->Get(TString::Format("hTOTvADC_Bar%d_L_%d",adcbar,1));
      hTOTvADCL_1->Draw();
      // fit the means - this callibrates the tot
      Double_t minFitRangeTOT = 0.0;
      Double_t maxFitRangeTOT = 0.0;
      Int_t nbins = hTOTvADCL_1->GetNbinsX();
      vector<Double_t> vbincontents;
      vbincontents.clear();
      for(Int_t bin=1; bin<nbins; bin++){
      	if(hTOTvADCL_1->GetBinContent(bin)>0)
      	  vbincontents.push_back(bin);
      }
      if(vbincontents.size()>0){
      	minFitRangeTOT = ((TAxis*)hTOTvADCL_1->GetXaxis())->GetBinCenter(vbincontents[0]);
      	maxFitRangeTOT = ((TAxis*)hTOTvADCL_1->GetXaxis())->GetBinCenter(vbincontents[vbincontents.size()-1]);
      }
      else{
      	minFitRangeTOT = ((TAxis*)hTOTvADCL_1->GetXaxis())->GetBinCenter(1);
      	maxFitRangeTOT = ((TAxis*)hTOTvADCL_1->GetXaxis())->GetBinCenter(nbins-1);
      	}
      // fLeftTOT[b] = new TF1(TString::Format("fTOT_Bar%d_L",adcbar),
      // 		      "[0]*sqrt(x-[1]) + [2]",
      // 		      minFitRangeTOT, maxFitRangeTOT);// sqrt fit
      // fLeftTOT[b] = new TF1(TString::Format("fTOT_Bar%f_L",adcbar),
      // 		      "[0]*x + [1] - ([2]/(x-[3]))",
      // 		      minFitRangeTOT, maxFitRangeTOT);// fit from timepix studies
      fLeftTOT[b] = new TF1(TString::Format("fTOT_Bar%d_L",adcbar),
      			    "[0]*([1]-[2]/x)",
      			    minFitRangeTOT, maxFitRangeTOT);//fit from torch studies
      fLeftTOT[b]->SetParameter(0,0.1);
      fLeftTOT[b]->SetParameter(1,160.);
      fLeftTOT[b]->SetParameter(2,5.);
      // fLeftTOT[b]->SetParameter(3,4000);
      hTOTvADCL_1->Fit(TString::Format("fTOT_Bar%d_L",adcbar),"QR","",minFitRangeTOT, maxFitRangeTOT);
      // output fit results to text file
      // left pmts indicated by 0
      tottextfile << b << "\t" << 0 << "\t"
      		  << fLeftTOT[b]->GetParameter(0) << "\t" << fLeftTOT[b]->GetParError(0) << "\t"
      		  << fLeftTOT[b]->GetParameter(1) << "\t" << fLeftTOT[b]->GetParError(1) << "\t"
      		  << fLeftTOT[b]->GetParameter(2) << "\t" << fLeftTOT[b]->GetParError(2) << "\t"
      	// << fLeftTOT[b]->GetParameter(3) << "\t" << fLeftTOT[b]->GetParError(3) << "\t"
      		  << "\n";
      // sigma of each slice gauss
      rightPadTOT->cd(2);
      gPad->SetTopMargin(0.12);
      gPad->SetLeftMargin(0.15);
      TH1D *hTOTvADCL_2 = (TH1D*)gDirectory->Get(TString::Format("hTOTvADC_Bar%d_L_%d",adcbar,2));
      hTOTvADCL_2->Draw();
      // set attributes
      hTOTvADCL_0->SetLineColor(1);
      hTOTvADCL_0->SetMarkerColor(1);
      hTOTvADCL_0->SetMarkerStyle(21);
      hTOTvADCL_0->SetMarkerSize(0.6);
      hTOTvADCL_1->SetLineColor(1);
      hTOTvADCL_1->SetMarkerColor(1);
      hTOTvADCL_1->SetMarkerStyle(21);
      hTOTvADCL_1->SetMarkerSize(0.6);
      hTOTvADCL_2->SetLineColor(1);
      hTOTvADCL_2->SetMarkerColor(1);
      hTOTvADCL_2->SetMarkerStyle(21);
      hTOTvADCL_2->SetMarkerSize(0.6);
      
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
      hTOTvADCR[b]->Draw("COLZ");
      // do the fit slices y
      hTOTvADCR[b]->FitSlicesY(0,1,NAdcBins-1,TOTStatCut);//,"QNR",0);
      // draw results
      // constant of each slice gauss
      leftPadTOTr->cd(2);
      TH1D *hTOTvADCR_0 = (TH1D*)gDirectory->Get(TString::Format("hTOTvADC_Bar%d_R_%d",adcbar,0));
      hTOTvADCR_0->Draw();
      // mean of each slice gauss
      TPad *rightPadTOTr = (TPad*)crightTOT->cd(2);
      rightPadTOTr->Divide(1,2);
      rightPadTOTr->cd(1);
      gPad->SetTopMargin(0.12);
      gPad->SetLeftMargin(0.15);
      TH1D *hTOTvADCR_1 = (TH1D*)gDirectory->Get(TString::Format("hTOTvADC_Bar%d_R_%d",adcbar,1));
      hTOTvADCR_1->Draw();
      // fit the means - this callibrates the tot
      Double_t minFitRangeTOTr = 0.0;
      Double_t maxFitRangeTOTr = 0.0;
      Int_t nbinsr = hTOTvADCR_1->GetNbinsX();
      vector<Double_t> vbincontentsr;
      vbincontentsr.clear();
      for(Int_t binr=1; binr<nbinsr; binr++){
      	if(hTOTvADCL_1->GetBinContent(binr)>0)
      	  vbincontentsr.push_back(binr);
      }
      if(vbincontentsr.size()>0){
      	minFitRangeTOTr = ((TAxis*)hTOTvADCR_1->GetXaxis())->GetBinCenter(vbincontentsr[0]);
      	maxFitRangeTOTr = ((TAxis*)hTOTvADCR_1->GetXaxis())->GetBinCenter(vbincontentsr[vbincontentsr.size()-1]);
      }
      else{
      	minFitRangeTOTr = ((TAxis*)hTOTvADCR_1->GetXaxis())->GetBinCenter(1);
      	maxFitRangeTOTr = ((TAxis*)hTOTvADCR_1->GetXaxis())->GetBinCenter(nbinsr-1);
      }
      // fRightTOT[b] = new TF1(TString::Format("fTOT_Bar%f_R",adcbar),
      // 		      "[0]*sqrt(x-[1]) + [2]",
      // 		      minFitRangeTOTr, maxFitRangeTOTr);// sqrt fit
      // fRightTOT[b] = new TF1(TString::Format("fTOT_Bar%f_R",adcbar),
      // 		      "[0]*x + [1] - ([2]/(x-[3]))",
      // 		      minFitRangeTOTr, maxFitRangeTOTr);// fit from timepix studies
      fRightTOT[b] = new TF1(TString::Format("fTOT_Bar%d_R",adcbar),
      			     "[0]*([1]-[2]/x)",
      			     minFitRangeTOTr, maxFitRangeTOTr);//fit from torch studies
      fRightTOT[b]->SetParameter(0,0.1);
      fRightTOT[b]->SetParameter(1,160.);
      fRightTOT[b]->SetParameter(2,5.);
      hTOTvADCR_1->Fit(TString::Format("fTOT_Bar%d_R",adcbar),"QR","",minFitRangeTOTr, maxFitRangeTOTr);
      // output fit results to text file
      // right pmts indicated by 1
      tottextfile << b << "\t" << 1 << "\t"
      		  << fRightTOT[b]->GetParameter(0) << "\t" << fRightTOT[b]->GetParError(0) << "\t"
      		  << fRightTOT[b]->GetParameter(1) << "\t" << fRightTOT[b]->GetParError(1) << "\t"
      		  << fRightTOT[b]->GetParameter(2) << "\t" << fRightTOT[b]->GetParError(2) << "\t"
      	// << fRightTOT[b]->GetParameter(3) << "\t" << fRightTOT[b]->GetParError(3) << "\t"
      		  << "\n";
      // sigma of each slice
      // sigma of each slice gauss
      rightPadTOTr->cd(2);
      gPad->SetTopMargin(0.12);
      gPad->SetLeftMargin(0.15);
      TH1D *hTOTvADCR_2 = (TH1D*)gDirectory->Get(TString::Format("hTOTvADC_Bar%d_R_%d",adcbar,2));
      hTOTvADCR_2->Draw();
      // set attributes
      hTOTvADCR_0->SetLineColor(1);
      hTOTvADCR_0->SetMarkerColor(1);
      hTOTvADCR_0->SetMarkerStyle(21);
      hTOTvADCR_0->SetMarkerSize(0.6);
      hTOTvADCR_1->SetLineColor(1);
      hTOTvADCR_1->SetMarkerColor(1);
      hTOTvADCR_1->SetMarkerStyle(21);
      hTOTvADCR_1->SetMarkerSize(0.6);
      hTOTvADCR_2->SetLineColor(1);
      hTOTvADCR_2->SetMarkerColor(1);
      hTOTvADCR_2->SetMarkerStyle(21);
      hTOTvADCR_2->SetMarkerSize(0.6);
      
      crightTOT->Write();
      delete crightTOT;
      
    }//bar loop
  } //  if doing fitting to tot



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
    hTOTvADCL[bar]->GetXaxis()->SetTitle("ADC bin");
    hTOTvADCL[bar]->GetYaxis()->SetTitle("TOT");
    hTOTvADCL[bar]->Write();
    hTOTvADCR[bar]->GetXaxis()->SetTitle("ADC bin");
    hTOTvADCR[bar]->GetYaxis()->SetTitle("TOT");
    hTOTvADCR[bar]->Write();
  }



  //========================================================== Close output file
  //f->Close();
  // tidy up canvases
  //delete cLeft;
  //delete cRight;

  

  //================================================================== End Macro
}// end main



