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
#include <TLatex.h>

#include "plot2D.C"

const Int_t nTdc = 180;
const Int_t nRef = 2;
const Int_t nBarsTDC = 90;
const Int_t nBarsADC = 32;
const Double_t ADCCUT = 150.;//100.0;

// const TString REPLAYED_DIR = "/adaqfs/home/a-onl/sbs/Rootfiles";
// const TString ANALYSED_DIR = "/adaqfs/home/a-onl/sbs/Rootfiles/bbhodo_hist";

// // for local analysis at uog (please leave in comments)
// TString REPLAYED_DIR = "/w/work0/home/rachel/HallA/BB_Hodo/FallRun2021/Replayed";
TString REPLAYED_DIR = "/w/work2/jlab/halla/sbs_hodo/Rootfiles";
TString ANALYSED_DIR = "/w/work0/home/rachel/HallA/BB_Hodo/FallRun2021/Analysed";


namespace Thodo {
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
};

TChain *T = 0;

using namespace std;

void PlotRawTDC2D(const TString InFile="bbhodo_311_1000000", Int_t nevents=-1){
  // InFile is the input file without absolute path and without .root suffix
  // nevents is how many events to analyse, -1 for all
  
  // To execute
  // root -l
  // .L PlotRawTDC2D.C+
  // PlotRawTDC2D("filename", -1)


    TString sInFile = REPLAYED_DIR + "/" + InFile + ".root";
  //========================================================= Get data from tree
  if(!T) { 
    // TString sInFile = REPLAYED_DIR + "/" + InFile + ".root";
    cout << "Adding " << sInFile << endl;
    T = new TChain("T");
    T->Add(sInFile);
    
    // disable all branches
    T->SetBranchStatus("*",0);
    // enable branches
    T->SetBranchStatus("bb.hodotdc.*",1);
    T->SetBranchAddress("bb.hodotdc.tdc_mult",Thodo::TDCmult);
    T->SetBranchAddress("bb.hodotdc.hits.TDCelemID",Thodo::RawElID);
    T->SetBranchAddress("bb.hodotdc.hits.t",Thodo::RawElLE);
    T->SetBranchAddress("bb.hodotdc.hits.t_te",Thodo::RawElTE);
    T->SetBranchAddress("bb.hodotdc.hits.t_tot",Thodo::RawElTot);
    T->SetBranchAddress("bb.hodotdc.Ref.hits.TDCelemID",Thodo::RawRefID);
    T->SetBranchAddress("bb.hodotdc.Ref.hits.t",Thodo::RawRefLE);
    T->SetBranchAddress("bb.hodotdc.Ref.hits.t_te",Thodo::RawRefTE);
    T->SetBranchAddress("bb.hodotdc.Ref.tdc_mult",Thodo::RefMult);

    // enable vector size branches
    T->SetBranchAddress("Ndata.bb.hodotdc.tdc_mult",&Thodo::NdataMult); 
    T->SetBranchAddress("Ndata.bb.hodotdc.hits.TDCelemID",&Thodo::NdataRawElID); 
    T->SetBranchAddress("Ndata.bb.hodotdc.hits.t",&Thodo::NdataRawLE); 
    T->SetBranchAddress("Ndata.bb.hodotdc.hits.t_te",&Thodo::NdataRawTE); 
    T->SetBranchAddress("Ndata.bb.hodotdc.hits.t_tot",&Thodo::NdataRawTot); 
    T->SetBranchAddress("Ndata.bb.hodotdc.Ref.hits.TDCelemID",&Thodo::NdataRawRefHitID); 
    T->SetBranchAddress("Ndata.bb.hodotdc.Ref.hits.t",&Thodo::NdataRawRefHitLE); 
    T->SetBranchAddress("Ndata.bb.hodotdc.Ref.hits.t_te",&Thodo::NdataRawRefHitTE); 
    T->SetBranchAddress("Ndata.bb.hodotdc.Ref.tdc_mult",&Thodo::NdataRefMult); 

  }//setting tree
  
  
  //========================================================= Check no of events
  Int_t Nev = T->GetEntries();
  cout << "N entries in tree is " << Nev << endl;
  Int_t NEventsAnalysis;
  if(nevents==-1) NEventsAnalysis = Nev;
  else NEventsAnalysis = nevents;
  cout << "Running analysis for " << NEventsAnalysis << " events" << endl;
  

  
  //==================================================== Create output root file
  // root file for viewing fits
  TString outrootfile = ANALYSED_DIR + "/RawTDC_" + InFile + ".root";
  TFile *f = new TFile(outrootfile, "RECREATE");



  //===================================================== Histogram Declarations
  // number of histo bins
  Int_t NTDCBins = 100;
  Double_t TDCBinLow = -100;//-400.;
  Double_t TDCBinHigh = 700;//400.;
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
  // reference hits
  TH1F *hRawRefLE[nRef];
  TH1F *hRawRefTE[nRef];
  TH1F *hRefMult[nRef];
  TString side[nRef]={"L","R"};
  for(Int_t ref=0; ref<nRef; ref++){
    hRawRefLE[ref] = new TH1F(TString::Format("hRawRefLE_%s",side[ref].Data()),
			      TString::Format("hRawRefLE_%s",side[ref].Data()),
			      400,0,1000);
    hRawRefTE[ref] = new TH1F(TString::Format("hRawRefTE_%s",side[ref].Data()),
			      TString::Format("hRawRefTE_%s",side[ref].Data()),
			      400,0,1000);
    hRefMult[ref] =  new TH1F(TString::Format("hRefMult_%s",side[ref].Data()),
			       TString::Format("hRefMult_%s",side[ref].Data()),
			       10,0,10);
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
      for(Int_t el=0; el<Thodo::NdataRawElID; el++){
      	if(Thodo::RawElID[el]<90){//left
      	  hRawLeL[(Int_t)Thodo::RawElID[el]]->Fill(Thodo::RawElLE[el]);
      	  hRawTeL[(Int_t)Thodo::RawElID[el]]->Fill(Thodo::RawElTE[el]);
      	  hRawTotL[(Int_t)Thodo::RawElID[el]]->Fill(Thodo::RawElTot[el]);
	  hHitPMTL->Fill((Int_t)Thodo::RawElID[el]);
      	}
      	else{//right
      	  hRawLeR[(Int_t)Thodo::RawElID[el]-90]->Fill(Thodo::RawElLE[el]);
      	  hRawTeR[(Int_t)Thodo::RawElID[el]-90]->Fill(Thodo::RawElTE[el]);
      	  hRawTotR[(Int_t)Thodo::RawElID[el]-90]->Fill(Thodo::RawElTot[el]);
	  hHitPMTR->Fill((Int_t)Thodo::RawElID[el]-90);
      	}
      }// all raw tdc hit loop
      for(Int_t tdc=0; tdc<Thodo::NdataMult; tdc++){
      	hMultiplicity->Fill(Thodo::TDCmult[tdc]);
      	if((Int_t)Thodo::RawElID[tdc]<90)//left
      	  hMultiplicityL[(Int_t)Thodo::RawElID[tdc]]->Fill(Thodo::TDCmult[tdc]);
      	else
      	  hMultiplicityR[(Int_t)Thodo::RawElID[tdc]-90]->Fill(Thodo::TDCmult[tdc]);
      }// element loop
      //ref
      for(Int_t ref=0; ref<(Int_t)Thodo::NdataRawRefHitLE; ref++){
      	Int_t side = (Int_t)Thodo::RawRefID[ref];
      	if(side==0 || side==1){
      	  hRawRefLE[side]->Fill(Thodo::RawRefLE[ref]);
      	  hRawRefTE[side]->Fill(Thodo::RawRefTE[ref]);
      	}
      }// ref raw hit loop
      for(Int_t p=0; p<(Int_t)Thodo::NdataRefMult; p++){
	hRefMult[p]->Fill(Thodo::RefMult[p]);
      }
  }// event loop



  //========================================================== Write histos
  for(Int_t b=0; b<nBarsTDC; b++){
    // hRawLeL[b]->GetXaxis()->SetLabelSize(0.06);
    hRawLeL[b]->GetXaxis()->SetTitle("time (ns)");
    // hRawLeL[b]->GetXaxis()->SetTitleSize(0.05);
    hRawLeL[b]->Write();
    // hRawLeR[b]->GetXaxis()->SetLabelSize(0.06);
    hRawLeR[b]->GetXaxis()->SetTitle("time (ns)");
    // hRawLeR[b]->GetXaxis()->SetTitleSize(0.05);
    hRawLeR[b]->Write();
    // hRawTeL[b]->GetXaxis()->SetLabelSize(0.06);
    hRawTeL[b]->GetXaxis()->SetTitle("time (ns)");
    // hRawTeL[b]->GetXaxis()->SetTitleSize(0.05);
    hRawTeL[b]->Write();
    // hRawTeR[b]->GetXaxis()->SetLabelSize(0.06);
    hRawTeR[b]->GetXaxis()->SetTitle("time (ns)");
    // hRawTeR[b]->GetXaxis()->SetTitleSize(0.05);
    hRawTeR[b]->Write();
    // hRawTotL[b]->GetXaxis()->SetLabelSize(0.06);
    hRawTotL[b]->GetXaxis()->SetTitle("tot (ns)");
    // hRawTotL[b]->GetXaxis()->SetTitleSize(0.05);
    hRawTotL[b]->Write();
    // hRawTotR[b]->GetXaxis()->SetLabelSize(0.06);
    hRawTotR[b]->GetXaxis()->SetTitle("tot (ns)");
    // hRawTotR[b]->GetXaxis()->SetTitleSize(0.05);
    hRawTotR[b]->Write();
    // hMultiplicityL[b]->GetXaxis()->SetLabelSize(0.06);
    hMultiplicityL[b]->GetXaxis()->SetTitle("left tdc ref hit mult");
    hMultiplicityL[b]->Write();
    // hMultiplicityR[b]->GetXaxis()->SetLabelSize(0.06);
    hMultiplicityR[b]->GetXaxis()->SetTitle("right tdc ref hit mult");
    hMultiplicityR[b]->Write();
  }
  // hMultiplicity->GetXaxis()->SetLabelSize(0.06);
  hMultiplicity->GetXaxis()->SetTitle("tdc hit multiplicity");
  hMultiplicity->Write();
  // hHitPMTL->GetXaxis()->SetLabelSize(0.06);
  hHitPMTL->GetXaxis()->SetTitle("Bar ID of Left PMT Hit");
  hHitPMTL->SetTitle("");
  hHitPMTL->Write();
  // hHitPMTR->GetXaxis()->SetLabelSize(0.06);
  hHitPMTR->GetXaxis()->SetTitle("Bar ID of Right PMT Hit");
  hHitPMTR->SetTitle("");
  hHitPMTR->Write();
  // ref histos
  for(Int_t rr=0; rr<nRef; rr++){
    if(rr==0)
      hRawRefLE[rr]->GetXaxis()->SetTitle("Left TDC Ref LE Time (ns)");
    else 
      hRawRefLE[rr]->GetXaxis()->SetTitle("Right TDC Ref LE Time (ns)");
    // hRawRefLE[rr]->GetXaxis()->SetLabelSize(0.06);
    hRawRefLE[rr]->SetTitle("");
    hRawRefLE[rr]->Write();
    if(rr==0)
      hRawRefTE[rr]->GetXaxis()->SetTitle("Left TDC Ref TE Time (ns)");
    else 
      hRawRefTE[rr]->GetXaxis()->SetTitle("Right TDC Ref TE Time (ns)");
    // hRawRefTE[rr]->GetXaxis()->SetLabelSize(0.06);
    hRawRefTE[rr]->SetTitle("");
    hRawRefTE[rr]->Write();
    if(rr==0)
      hRefMult[rr]->GetXaxis()->SetTitle("Left TDC Ref Multiplicity");
    else
      hRefMult[rr]->GetXaxis()->SetTitle("Right TDC Ref Multiplicity");
    // hRefMult[rr]->GetXaxis()->SetLabelSize(0.06);
    hRefMult[rr]->SetTitle("");
    hRefMult[rr]->Write();
  }

  // TString soptions = ;
  // gROOT->ProcessLine(.x plot2D.C);
  //========================================================== Plot 2D graphs
  // process the plot2D macro to add in the 2D graphs
  plot2D(sInFile,nevents);
  TH2F *hptL;
  gDirectory->GetObject("hptL",hptL);
  TH2F *hptR;
  gDirectory->GetObject("hptR",hptR);
  TH2F *hptotL;
  gDirectory->GetObject("hptotL",hptotL);
  TH2F *hptotR;
  gDirectory->GetObject("hptotR",hptotR);
  TH2F *hpmultL;
  gDirectory->GetObject("hpmultL",hpmultL);
  TH2F *hpmultR;
  gDirectory->GetObject("hpmultR",hpmultR);
  TH2F *hbtL;
  gDirectory->GetObject("hbtL",hbtL);


  TH1F* hbt1cop = new TH1F("hbt1cop","", 95,0,94);
  // // TH1F* hbt2 = new TH1F("hbt2","", 95,0,94);
  TH1F* hbt3cop = new TH1F("hbt3cop","", 95,0,94);
  hbt1cop = (TH1F*)hpmultR->ProjectionY();
  hbt1cop->SetLineWidth(2);
  hbt1cop->SetLineColor(4);
  // // hbt1->Draw("");
  hbt1cop->GetXaxis()->SetTitle("Paddle / PMT Number");
  hbt1cop->Sumw2();
  TH1F *hbt2;
  gDirectory->GetObject("hbt2",hbt2);
  hbt3cop = (TH1F*)hpmultL->ProjectionY();
  hbt3cop->SetLineColor(2);
  hbt3cop->SetLineWidth(2);
  // hbt3->Draw("same");
  hbt3cop->Sumw2();


  // TH1F *hbt1;
  // gDirectory->GetObject("hbt1",hbt1);
  // TH1F *hbt2;
  // gDirectory->GetObject("hbt2",hbt2);
  // TH1F *hbt3;
  // gDirectory->GetObject("hbt3",hbt3);

  f->cd();
  hptL->Write();
  hptR->Write();
  hptotL->Write();
  hptotR->Write();
  hpmultL->Write();
  hpmultR->Write();
  hbtL->Write();
  hbt1cop->Write();
  hbt2->Write();
  hbt3cop->Write();



  //========================================================== Close output file
  f->Close();



  //================================================================== End Macro
}// end main
