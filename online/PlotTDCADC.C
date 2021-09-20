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
const Int_t nRef = 2;
const Int_t nBarsTDC = 90;
const Int_t nBarsADC = 32;
const Double_t ADCCUT = 150.;//100.0;

const TString REPLAYED_DIR = "/adaqfs/home/a-onl/sbs/Rootfiles";
const TString ANALYSED_DIR = "/adaqfs/home/a-onl/sbs/Rootfiles/bbhodo_hist";

// for local analysis at uog (please leave in comments)
//TString REPLAYED_DIR = "/w/work0/home/rachel/HallA/BB_Hodo/FallRun2021/Replayed";
//TString ANALYSED_DIR = "/w/work0/home/rachel/HallA/BB_Hodo/FallRun2021/Analysed";


namespace Thodo {
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
  Int_t NdataTeL;
  Double_t TDCTeL[nBarsTDC];
  Int_t NdataTeR;
  Double_t TDCTeR[nBarsTDC];

  Int_t NdataMult;
  Double_t TDCmult[nTdc];
  Int_t NdataRawElID;
  Double_t RawElID[nTdc*2];
  Int_t NdataRawLE;
  Double_t RawElLE[nTdc*2];
  Int_t NdataRawTE;
  Double_t RawElTE[nTdc*2];
  Int_t NdataRawTot;
  Double_t RawElTot[nTdc*2];

  // ref hits
  Int_t NdataRawRefHitID;
  Double_t RawRefID[nRef];
  Int_t NdataRawRefHitLE;
  Double_t RawRefLE[nTdc*2];
  Int_t NdataRawRefHitTE;
  Double_t RawRefTE[nTdc*2];
  Int_t NdataRefMult;
  Double_t RefMult[nTdc*2];

  Int_t NdataGoodRefHitID;
  Double_t GoodRefID[nRef];
  Int_t NdataGoodRefHitLE;
  Double_t GoodRefLE[nTdc*2];
  Int_t NdataGoodRefHitTE;
  Double_t GoodRefTE[nTdc*2];
  // Int_t NdataGoodRefMult;
  // Double_t GoodRefMult[nTdc*2];

  //adc
  Int_t NdataAdcBar;
  Double_t ADCBar[nBarsADC];
  Int_t NdataAdcL;
  Double_t ADCValL[nBarsADC];
  Int_t NdataAdcR;
  Double_t ADCValR[nBarsADC];
};

TChain *T = 0;

using namespace std;

void PlotTDCADC(const TString InFile="bbhodo_311_1000000", Int_t nevents=-1){
  // InFile is the input file without absolute path and without .root suffix
  // nevents is how many events to analyse, -1 for all
  
  // To execute
  // root -l
  // .L PlotRawTDC.C+
  // PlotRawTDC("filename", -1)



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
    T->SetBranchAddress("bb.hodotdc.L.te",Thodo::TDCTeL);
    T->SetBranchAddress("bb.hodotdc.R.te",Thodo::TDCTeR);
    T->SetBranchAddress("bb.hodotdc.tdc_mult",Thodo::TDCmult);
    T->SetBranchAddress("bb.hodotdc.hits.elemID",Thodo::RawElID);
    T->SetBranchAddress("bb.hodotdc.hits.t",Thodo::RawElLE);
    T->SetBranchAddress("bb.hodotdc.hits.t_te",Thodo::RawElTE);
    T->SetBranchAddress("bb.hodotdc.hits.t_tot",Thodo::RawElTot);
    T->SetBranchAddress("bb.hodotdc.Ref.hits.TDCelemID",Thodo::RawRefID);
    T->SetBranchAddress("bb.hodotdc.Ref.hits.t",Thodo::RawRefLE);
    T->SetBranchAddress("bb.hodotdc.Ref.hits.t_te",Thodo::RawRefTE);
    T->SetBranchAddress("bb.hodotdc.Ref.tdc_mult",Thodo::RefMult);
    T->SetBranchAddress("bb.hodoadc.adcbarid",Thodo::ADCBar);
    T->SetBranchAddress("bb.hodoadc.L.a",Thodo::ADCValL);
    T->SetBranchAddress("bb.hodoadc.R.a",Thodo::ADCValR);
    T->SetBranchAddress("bb.hodotdc.Ref.tdcelemID",Thodo::GoodRefID);
    T->SetBranchAddress("bb.hodotdc.Ref.tdc",Thodo::GoodRefLE);
    T->SetBranchAddress("bb.hodotdc.Ref.tdc_te",Thodo::GoodRefTE);
    // T->SetBranchAddress("bb.hodotdc.Ref.tdc_mult",Thodo::GoodRefMult);

    T->SetBranchAddress("Ndata.bb.hodotdc.tdcbarid",&Thodo::NdataTdcBar);
    T->SetBranchAddress("Ndata.bb.hodotdc.L.tot",&Thodo::NdataTotL);
    T->SetBranchAddress("Ndata.bb.hodotdc.R.tot",&Thodo::NdataTotR);   
    T->SetBranchAddress("Ndata.bb.hodotdc.L.le",&Thodo::NdataLeL);
    T->SetBranchAddress("Ndata.bb.hodotdc.R.le",&Thodo::NdataLeR); 
    T->SetBranchAddress("Ndata.bb.hodotdc.L.te",&Thodo::NdataTeL);
    T->SetBranchAddress("Ndata.bb.hodotdc.R.te",&Thodo::NdataTeR); 
    T->SetBranchAddress("Ndata.bb.hodotdc.tdc_mult",&Thodo::NdataMult); 
    T->SetBranchAddress("Ndata.bb.hodotdc.hits.elemID",&Thodo::NdataRawElID); 
    T->SetBranchAddress("Ndata.bb.hodotdc.hits.t",&Thodo::NdataRawLE); 
    T->SetBranchAddress("Ndata.bb.hodotdc.hits.t_te",&Thodo::NdataRawTE); 
    T->SetBranchAddress("Ndata.bb.hodotdc.hits.t_tot",&Thodo::NdataRawTot); 
    T->SetBranchAddress("Ndata.bb.hodotdc.Ref.hits.TDCelemID",&Thodo::NdataRawRefHitID); 
    T->SetBranchAddress("Ndata.bb.hodotdc.Ref.hits.t",&Thodo::NdataRawRefHitLE); 
    T->SetBranchAddress("Ndata.bb.hodotdc.Ref.hits.t_te",&Thodo::NdataRawRefHitTE); 
    T->SetBranchAddress("Ndata.bb.hodotdc.Ref.tdc_mult",&Thodo::NdataRefMult);
    T->SetBranchAddress("Ndata.bb.hodotdc.Ref.tdcelemID",&Thodo::NdataGoodRefHitID); 
    T->SetBranchAddress("Ndata.bb.hodotdc.Ref.tdc",&Thodo::NdataGoodRefHitLE); 
    T->SetBranchAddress("Ndata.bb.hodotdc.Ref.tdc_te",&Thodo::NdataGoodRefHitTE); 
    // T->SetBranchAddress("Ndata.bb.hodotdc.Ref.tdc_mult",&Thodo::NdataGoodRefMult); 
    T->SetBranchStatus("Ndata.bb.hodoadc.*",1);
    T->SetBranchAddress("Ndata.bb.hodoadc.adcbarid",&Thodo::NdataAdcBar);
    // T->SetBranchAddress("Ndata.bb.hodoadc.L.ap",&Thodo::NdataAdcL);
      // T->SetBranchAddress("Ndata.bb.hodoadc.R.ap",&Thodo::NdataAdcR);
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
  TString outrootfile = ANALYSED_DIR + "/TDCADC_" + InFile + ".root";
  TFile *f = new TFile(outrootfile, "RECREATE");



  //===================================================== Histogram Declarations
  // number of histo bins
  Int_t NTDCBins = 100;
  Double_t TDCBinLow = -400.;
  Double_t TDCBinHigh = 400.;
  Int_t NTotBins = 50;
  Double_t TotBinLow = 0.;
  Double_t TotBinHigh = 200.;

  // Raw hits ie all hits
  TH1F *hRawLeL[nBarsTDC];
  TH1F *hRawLeR[nBarsTDC];
  TH1F *hRawTeL[nBarsTDC];
  TH1F *hRawTeR[nBarsTDC];
  TH1F *hRawTotL[nBarsTDC];
  TH1F *hRawTotR[nBarsTDC];
  TH1F *hGoodLeL[nBarsTDC];
  TH1F *hGoodLeR[nBarsTDC];
  TH1F *hGoodTeL[nBarsTDC];
  TH1F *hGoodTeR[nBarsTDC];
  TH1F *hGoodTotL[nBarsTDC];
  TH1F *hGoodTotR[nBarsTDC];
  for(Int_t bar=0; bar<(nBarsTDC); bar++){
    // raw hits
    // leading edge
    hRawLeL[bar] = new TH1F(TString::Format("hRawLe_Bar%d_L",bar),
			    TString::Format("hRawLe_Bar%d_L",bar),
			    NTDCBins, TDCBinLow, TDCBinHigh);
    hRawLeR[bar] = new TH1F(TString::Format("hRawLe_Bar%d_R",bar),
			    TString::Format("hRawLe_Bar%d_R",bar),
			    NTDCBins, TDCBinLow, TDCBinHigh);
    // trailing edge 
    hRawTeL[bar] = new TH1F(TString::Format("hRawTe_Bar%d_L",bar),
			    TString::Format("hRawTe_Bar%d_L",bar),
			    NTDCBins, TDCBinLow, TDCBinHigh);
    hRawTeR[bar] = new TH1F(TString::Format("hRawTe_Bar%d_R",bar),
			    TString::Format("hRawTe_Bar%d_R",bar),
			    NTDCBins, TDCBinLow, TDCBinHigh);
    // tot 
    hRawTotL[bar] = new TH1F(TString::Format("hRawTot_Bar%d_L",bar),
			     TString::Format("hRawTot_Bar%d_L",bar),
			     NTotBins, TotBinLow, TotBinHigh);
    hRawTotR[bar] = new TH1F(TString::Format("hRawTot_Bar%d_R",bar),
			     TString::Format("hRawTot_Bar%d_R",bar),
			     NTotBins, TotBinLow, TotBinHigh);
    //good bars
    hGoodLeL[bar] = new TH1F(TString::Format("hGoodLe_Bar%d_L",bar),
			    TString::Format("hGoodLe_Bar%d_L",bar),
			    NTDCBins, 0.0, 800.0);
    hGoodLeR[bar] = new TH1F(TString::Format("hGoodLe_Bar%d_R",bar),
			    TString::Format("hGoodLe_Bar%d_R",bar),
			    NTDCBins, 0.0, 800.0);
    // trailing edge 
    hGoodTeL[bar] = new TH1F(TString::Format("hGoodTe_Bar%d_L",bar),
			    TString::Format("hGoodTe_Bar%d_L",bar),
			    NTDCBins, 0.0, 800.0);
    hGoodTeR[bar] = new TH1F(TString::Format("hGoodTe_Bar%d_R",bar),
			    TString::Format("hGoodTe_Bar%d_R",bar),
			    NTDCBins, 0.0, 800.0);
    // tot 
    hGoodTotL[bar] = new TH1F(TString::Format("hGoodTot_Bar%d_L",bar),
			     TString::Format("hGoodTot_Bar%d_L",bar),
			     NTotBins, TotBinLow, TotBinHigh);
    hGoodTotR[bar] = new TH1F(TString::Format("hGoodTot_Bar%d_R",bar),
			     TString::Format("hGoodTot_Bar%d_R",bar),
			     NTotBins, TotBinLow, TotBinHigh);
  }// bar loop
  TH1F *hMultiplicityL[nBarsTDC];
  TH1F *hMultiplicityR[nBarsTDC];
  TH1F *hMultiplicity = new TH1F("hMultiplicity","hMultiplicity",20,0,20);
  for(Int_t tdc=0; tdc<nBarsTDC; tdc++){
      hMultiplicityL[tdc] =  new TH1F(TString::Format("hMultiplicity_Bar%d_L",tdc),
				      TString::Format("hMultiplicity_Bar%d_L",tdc),
				      10, 0, 10);
      hMultiplicityR[tdc] =  new TH1F(TString::Format("hMultiplicity_Bar%d_R",tdc),
					 TString::Format("hMultiplicity_Bar%d_R",tdc),
					 10, 0, 10);
  }// 180 element loop
  // hit channel id
  TH1F *hHitPMTL = new TH1F("hHitPMTL","hHitPMTL",88,0,88);
  TH1F *hHitPMTR = new TH1F("hHitPMTR","hHitPMTR",88,0,88);
  TH1F *hHitBar = new TH1F("hHitBar","hHitBar",88,0,88);
  // reference hits
  TH1F *hRawRefLE[nRef];
  TH1F *hRawRefTE[nRef];
  TH1F *hRefMult[nRef];
  TString side[nRef]={"L","R"};
  for(Int_t ref=0; ref<nRef; ref++){
    hRawRefLE[ref] = new TH1F(TString::Format("hRawRefLE_%s",side[ref].Data()),
			      TString::Format("hRawRefLE_%s",side[ref].Data()),
			      150,200,500);
    hRawRefTE[ref] = new TH1F(TString::Format("hRawRefTE_%s",side[ref].Data()),
			      TString::Format("hRawRefTE_%s",side[ref].Data()),
			      150,200,500);
    hRefMult[ref] =  new TH1F(TString::Format("hRefMult_%s",side[ref].Data()),
			       TString::Format("hRefMult_%s",side[ref].Data()),
			       10,0,10);
  }
  TH1F *hGoodRefLE[nRef];
  TH1F *hGoodRefTE[nRef];
  TH1F *hGoodRefMult[nRef];
  for(Int_t ref=0; ref<nRef; ref++){
    hGoodRefLE[ref] = new TH1F(TString::Format("hGoodRefLE_%s",side[ref].Data()),
			       TString::Format("hGoodRefLE_%s",side[ref].Data()),
			       150,200,500);
    hGoodRefTE[ref] = new TH1F(TString::Format("hGoodRefTE_%s",side[ref].Data()),
			       TString::Format("hGoodRefTE_%s",side[ref].Data()),
			       150,200,500);
    hGoodRefMult[ref] =  new TH1F(TString::Format("hGoodRefMult_%s",side[ref].Data()),
			       TString::Format("hGoodRefMult_%s",side[ref].Data()),
			       10,0,10);
  }

  // adc histos to check if cutting on adc
  // number of adc bins
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

    for(Int_t adcbar=0; adcbar<nBarsADC; adcbar++){
      Int_t bar = Thodo::ADCBar[adcbar];
      // fill adc histos without any cuts
      Double_t adcl = Thodo::ADCValL[adcbar];
      Double_t adcr = Thodo::ADCValR[adcbar];
      hADCL[adcbar]->Fill(adcl);
      hADCR[adcbar]->Fill(adcr);

      // good bars
      for(Int_t tdc=0; tdc<(Int_t)Thodo::NdataTdcBar; tdc++){
	Int_t tdcbar = Thodo::TDCBar[tdc];
    
	if(bar==tdcbar){
	  if(adcl>ADCCUT){
	      hGoodLeL[bar]->Fill(Thodo::TDCLeL[tdc]);
	      hGoodTeL[bar]->Fill(Thodo::TDCTeL[tdc]);
	      hGoodTotL[bar]->Fill(Thodo::TDCTotL[tdc]);
	  }
	  if(adcr>ADCCUT){
	      hGoodLeR[bar]->Fill(Thodo::TDCLeR[tdc]);
	      hGoodTeR[bar]->Fill(Thodo::TDCTeR[tdc]);
	      hGoodTotR[bar]->Fill(Thodo::TDCTotR[tdc]);
	  }
	  if(adcl>ADCCUT && adcr>ADCCUT)
	      hHitBar->Fill(bar);
	}//if bars are same
      }//tdc bar loop
    
      // raw hits
      for(Int_t el=0; el<Thodo::NdataRawElID; el++){
	if(Thodo::RawElID[el]<90 && (Int_t)Thodo::RawElID[el]==bar){//left
	  if(adcl>ADCCUT){
	    hRawLeL[(Int_t)Thodo::RawElID[el]]->Fill(Thodo::RawElLE[el]);
	    hRawTeL[(Int_t)Thodo::RawElID[el]]->Fill(Thodo::RawElTE[el]);
	    hRawTotL[(Int_t)Thodo::RawElID[el]]->Fill(Thodo::RawElTot[el]);
	    hHitPMTL->Fill((Int_t)Thodo::RawElID[el]);
	  }
	}
	else if(Thodo::RawElID[el]>=90 && ((Int_t)Thodo::RawElID[el]-90)==bar){//right
	  if(adcr>ADCCUT){
	    hRawLeR[(Int_t)Thodo::RawElID[el]-90]->Fill(Thodo::RawElLE[el]);
	    hRawTeR[(Int_t)Thodo::RawElID[el]-90]->Fill(Thodo::RawElTE[el]);
	    hRawTotR[(Int_t)Thodo::RawElID[el]-90]->Fill(Thodo::RawElTot[el]);
	    hHitPMTR->Fill((Int_t)Thodo::RawElID[el]-90);
	  }
	}
      }// all raw tdc hit loop
      for(Int_t tdc=0; tdc<Thodo::NdataMult; tdc++){
	hMultiplicity->Fill(Thodo::TDCmult[tdc]);
	if((Int_t)Thodo::RawElID[tdc]<90 && (Int_t)Thodo::RawElID[tdc]==bar){//left
	  if(adcl>ADCCUT){
	    Int_t ch = (Int_t)Thodo::RawElID[tdc];
	    hMultiplicityL[ch]->Fill(Thodo::TDCmult[tdc]);
	  }
	}
	else if((Int_t)Thodo::RawElID[tdc]>=90 && ((Int_t)Thodo::RawElID[tdc]-90)==bar){//right
	  if(adcr>ADCCUT){
	    Int_t ch = (Int_t)Thodo::RawElID[tdc] - 90;
	    hMultiplicityR[ch]->Fill(Thodo::TDCmult[tdc]);
	  }
	}
      }// element loop
      //ref raw
      for(Int_t ref=0; ref<(Int_t)Thodo::NdataRawRefHitLE; ref++){
	Int_t side = (Int_t)Thodo::RawRefID[ref];
	if(side==0 && adcl>ADCCUT){
	  hRawRefLE[side]->Fill(Thodo::RawRefLE[ref]);
	  hRawRefTE[side]->Fill(Thodo::RawRefTE[ref]);
	}
	else if(side==1 && adcr>ADCCUT){
	  hRawRefLE[side]->Fill(Thodo::RawRefLE[ref]);
	  hRawRefTE[side]->Fill(Thodo::RawRefTE[ref]);
	}
      }// ref raw hit loop
      for(Int_t p=0; p<(Int_t)Thodo::NdataRefMult; p++){
	if(p==0){
	  if(adcl>ADCCUT){
	    hRefMult[p]->Fill(Thodo::RefMult[p]);
	  }
	}
	if(p==1){
	  if(adcr>ADCCUT){
	    hRefMult[p]->Fill(Thodo::RefMult[p]);
	  }
	}
      }
      //ref
      for(Int_t r=0; r<(Int_t)Thodo::NdataGoodRefHitLE; r++){
      	Int_t side2 = (Int_t)Thodo::GoodRefID[r];
      	if(side2==0 || side2==1){
	  if(side2==0 && adcl>ADCCUT){
	    hGoodRefLE[side2]->Fill(Thodo::GoodRefLE[r]);
	    hGoodRefTE[side2]->Fill(Thodo::GoodRefTE[r]);
	  }
	  else if(side2==1 && adcr>ADCCUT){
	    hGoodRefLE[side2]->Fill(Thodo::GoodRefLE[r]);
	    hGoodRefTE[side2]->Fill(Thodo::GoodRefTE[r]);
	  } 
      	}
      }// good ref hit loop
      for(Int_t p=0; p<(Int_t)Thodo::NdataRefMult; p++){
	if(p==0){
	  if(adcl>ADCCUT){
	    hGoodRefMult[p]->Fill(Thodo::RefMult[p]);
	  }
	}
	if(p==1){
	  if(adcr>ADCCUT){
	    hGoodRefMult[p]->Fill(Thodo::RefMult[p]);
	  }
	}
      }
      
    }// adc bar loop	  
    
    
  }// event loop



  //========================================================== Write histos
  for(Int_t b=0; b<nBarsTDC; b++){
    hRawLeL[b]->GetXaxis()->SetLabelSize(0.06);
    hRawLeL[b]->GetXaxis()->SetTitle("time (ns)");
    hRawLeL[b]->GetXaxis()->SetTitleSize(0.05);
    hRawLeL[b]->Write();
    hRawLeR[b]->GetXaxis()->SetLabelSize(0.06);
    hRawLeR[b]->GetXaxis()->SetTitle("time (ns)");
    hRawLeR[b]->GetXaxis()->SetTitleSize(0.05);
    hRawLeR[b]->Write();
    hRawTeL[b]->GetXaxis()->SetLabelSize(0.06);
    hRawTeL[b]->GetXaxis()->SetTitle("time (ns)");
    hRawTeL[b]->GetXaxis()->SetTitleSize(0.05);
    hRawTeL[b]->Write();
    hRawTeR[b]->GetXaxis()->SetLabelSize(0.06);
    hRawTeR[b]->GetXaxis()->SetTitle("time (ns)");
    hRawTeR[b]->GetXaxis()->SetTitleSize(0.05);
    hRawTeR[b]->Write();
    hRawTotL[b]->GetXaxis()->SetLabelSize(0.06);
    hRawTotL[b]->GetXaxis()->SetTitle("tot (ns)");
    hRawTotL[b]->GetXaxis()->SetTitleSize(0.05);
    hRawTotL[b]->Write();
    hRawTotR[b]->GetXaxis()->SetLabelSize(0.06);
    hRawTotR[b]->GetXaxis()->SetTitle("tot (ns)");
    hRawTotR[b]->GetXaxis()->SetTitleSize(0.05);
    hRawTotR[b]->Write();

    hGoodLeL[b]->GetXaxis()->SetLabelSize(0.06);
    hGoodLeL[b]->GetXaxis()->SetTitle("time (ns)");
    hGoodLeL[b]->GetXaxis()->SetTitleSize(0.05);
    hGoodLeL[b]->Write();
    hGoodLeR[b]->GetXaxis()->SetLabelSize(0.06);
    hGoodLeR[b]->GetXaxis()->SetTitle("time (ns)");
    hGoodLeR[b]->GetXaxis()->SetTitleSize(0.05);
    hGoodLeR[b]->Write();
    hGoodTeL[b]->GetXaxis()->SetLabelSize(0.06);
    hGoodTeL[b]->GetXaxis()->SetTitle("time (ns)");
    hGoodTeL[b]->GetXaxis()->SetTitleSize(0.05);
    hGoodTeL[b]->Write();
    hGoodTeR[b]->GetXaxis()->SetLabelSize(0.06);
    hGoodTeR[b]->GetXaxis()->SetTitle("time (ns)");
    hGoodTeR[b]->GetXaxis()->SetTitleSize(0.05);
    hGoodTeR[b]->Write();
    hGoodTotL[b]->GetXaxis()->SetLabelSize(0.06);
    hGoodTotL[b]->GetXaxis()->SetTitle("tot (ns)");
    hGoodTotL[b]->GetXaxis()->SetTitleSize(0.05);
    hGoodTotL[b]->Write();
    hGoodTotR[b]->GetXaxis()->SetLabelSize(0.06);
    hGoodTotR[b]->GetXaxis()->SetTitle("tot (ns)");
    hGoodTotR[b]->GetXaxis()->SetTitleSize(0.05);
    hGoodTotR[b]->Write();

    hMultiplicityL[b]->GetXaxis()->SetLabelSize(0.06);
    hMultiplicityL[b]->GetXaxis()->SetTitle("tdc hit multiplicity");
    hMultiplicityL[b]->Write();
    hMultiplicityR[b]->GetXaxis()->SetLabelSize(0.06);
    hMultiplicityR[b]->GetXaxis()->SetTitle("tdc hit multiplicity");
    hMultiplicityR[b]->Write();
  }
  hMultiplicity->GetXaxis()->SetLabelSize(0.06);
  hMultiplicity->GetXaxis()->SetTitle("tdc hit multiplicity");
  hMultiplicity->Write();
  hHitPMTL->GetXaxis()->SetLabelSize(0.06);
  hHitPMTL->GetXaxis()->SetTitle("Bar");
  hHitPMTL->Write();
  hHitPMTR->GetXaxis()->SetLabelSize(0.06);
  hHitPMTR->GetXaxis()->SetTitle("Bar");
  hHitPMTR->Write();
  // ref histos
  for(Int_t rr=0; rr<nRef; rr++){
    hRawRefLE[rr]->GetXaxis()->SetTitle("time (ns)");
    hRawRefLE[rr]->GetXaxis()->SetLabelSize(0.06);
    hRawRefLE[rr]->Write();
    hRawRefTE[rr]->GetXaxis()->SetTitle("time (ns)");
    hRawRefTE[rr]->GetXaxis()->SetLabelSize(0.06);
    hRawRefTE[rr]->Write();
    hRefMult[rr]->GetXaxis()->SetTitle("tdc hit multiplicity");
    hRefMult[rr]->GetXaxis()->SetLabelSize(0.06);
    hRefMult[rr]->Write();
    hGoodRefLE[rr]->GetXaxis()->SetTitle("time (ns)");
    hGoodRefLE[rr]->GetXaxis()->SetLabelSize(0.06);
    hGoodRefLE[rr]->Write();
    hGoodRefTE[rr]->GetXaxis()->SetTitle("time (ns)");
    hGoodRefTE[rr]->GetXaxis()->SetLabelSize(0.06);
    hGoodRefTE[rr]->Write();
    hGoodRefMult[rr]->GetXaxis()->SetTitle("tdc hit multiplicity");
    hGoodRefMult[rr]->GetXaxis()->SetLabelSize(0.06);
    hGoodRefMult[rr]->Write();
  }
  hHitBar->Write();
  for(Int_t bar=0; bar<nBarsADC; bar++){
    hADCL[bar]->Write();
    hADCR[bar]->Write();
  }
  
  //========================================================== Close output file
  f->Close();



  //================================================================== End Macro
}// end main
