#include "Riostream.h"
#include <TFile.h>
#include <TF1.h>
#include <TH1.h>
#include <TH2.h>
#include <TGraphErrors.h>
#include <TTree.h>
#include <TROOT.h>
#include <TLegend.h>
#include <string>
#include <array>
#include <vector>

#include "TCanvas.h"
#include "TString.h"
#include "TH2.h"
#include "TStyle.h"
#include "TChain.h"



//==================================================== FILE DIRECTORIES

// for local analysis at uog (please leave in comments)
TString REPLAYED_DIR = "/w/work0/home/rachel/HallA/BB_Hodo/FallRun2021/Replayed/";
TString ANALYSED_DIR = "/w/work0/home/rachel/HallA/BB_Hodo/FallRun2021/Analysed/";
// TString REPLAYED_DIR = "/w/work2/jlab/halla/sbs_hodo/Rootfiles";
// TString ANALYSED_DIR = "/w/work2/jlab/halla/sbs_hodo/Rootfiles/bbhodo_hist";



//==================================================== GLOBAL VARIABLES
const Int_t nADC = 64;
const Int_t nBarsADC = 32;
// runs 344 -349 bottom 1/3 ie bar start =0
const Int_t adcbarstart = 0;

//==================================================== MAIN
void HodofADC(const char* filename = "bbhodo_349_-1", Int_t nplot=-1){
  //	      Int_t nSeg=0){



  //==================================================== STYLE
  gStyle->SetOptFit(1111);
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  gStyle->SetPalette(1);

  gStyle->SetCanvasColor(0);
  gStyle->SetFrameFillColor(0);

  gStyle->SetPadTopMargin(.05);
  gStyle->SetPadLeftMargin(.15);
  gStyle->SetPadRightMargin(.15);
  gStyle->SetPadBottomMargin(.1);

  gStyle->SetTitleOffset(1.1, "X");
  gStyle->SetTitleOffset(1.2, "Y");
  gStyle->SetTitleFont(42,"X");
  gStyle->SetTitleFont(42,"Y");
  gStyle->SetTitleSize(0.035,"X");
  gStyle->SetTitleSize(0.035,"Y");

  gStyle->SetLabelOffset(0.01, "X");
  gStyle->SetLabelOffset(0.01, "Y");
  gStyle->SetLabelFont(42,"X");
  gStyle->SetLabelFont(42,"Y");
  gStyle->SetLabelSize(0.035,"X");
  gStyle->SetLabelSize(0.035,"Y");
  gStyle->SetLabelSize(0.035,"Z");

  gStyle->SetNdivisions(105,"X");
  gStyle->SetNdivisions(110,"Y");

  gStyle->SetStripDecimals(kFALSE);



  //==================================================== OPEN FILE
  TString fname = REPLAYED_DIR;
  fname += filename;
  fname += ".root";
  TFile* f = new TFile( fname );
  // TChain* T;
  // TChain *C = new TChain("T");
  // C->Add(fname);
  TTree* T = (TTree*)f->Get("T");
  // if(nSeg>0){
  //   for(Int_t i=1; i<nSeg; i++){
  //     TString fnameseg = "";
  //     fnameseg += REPLAYED_DIR;
  //     fnameseg += filename;
  //     fnameseg += "_";
  //     fnameseg += i;
  //     fnameseg += ".root";
  //     C->Add(fnameseg);
  //   }// loop over nSeg
  // }// if nSeg>0
  // get number of events to run for
  Int_t nEv = 0;
  if(nplot==-1)
    nEv = T->GetEntries();
  else
    nEv = nplot;
  cout << "N events in data file is " << T->GetEntries() << endl;
  cout << "Plotting for " << nEv << " events" << endl;



  //==================================================== OUTPUT FILE
  // root file for viewing fits
  TString outfname = ANALYSED_DIR;
  outfname += "TOTFits_";
  outfname += filename;
  outfname += ".root";
  TFile *fout = new TFile(outfname, "RECREATE");



  //==================================================== GLOBAL CUTS
  // TCut globalcut = "";
  // globalcut += "bb.hodoadc.a_time>0 && bb.hodoadc.a_mult>0";
  // TString globalcut = bb.hodoadc.a_time>0 && bb.hodoadc.a_mult;



  //==================================================== a_p
  // a_p is the integral in pC with the pedestal subtracted
  // canvas
  TCanvas* c1 = new TCanvas("c1","",800,600);
  c1->Divide(2,1);
  // histogram
  TH2F* ha_pL = new TH2F("ha_pL", "", 100,-100,100, 90,-0.5,89.5);
  TH2F* ha_pR = new TH2F("ha_pR", "", 100,-100,100, 90,-0.5,89.5);
  // Left pmts
  c1->cd(1);//->SetLogz(1);
  ha_pL->GetXaxis()->SetTitle("fADC a_p (a_time>0 && a_mult>0) [pC]");
  ha_pL->GetYaxis()->SetTitle("PMT number (Left)");
  T->Draw("bb.hodoadc.adccol:bb.hodoadc.a_p>>ha_pL",
  	  "bb.hodoadc.adcrow==0 && bb.hodoadc.a_time>0 && bb.hodoadc.a_mult>0",
  	  "colz",nEv);
  // Right pmts
  c1->cd(2);//->SetLogz(1);
  ha_pR->GetXaxis()->SetTitle("fADC a_p (a_time>0 && a_mult>0) [pC]");
  ha_pR->GetYaxis()->SetTitle("PMT number (Right)");
  T->Draw("bb.hodoadc.adccol:bb.hodoadc.a_p>>ha_pR",
	  "bb.hodoadc.adcrow==1 && bb.hodoadc.a_time>0 && bb.hodoadc.a_mult>0",
	  "colz",nEv);

  ha_pL->Write();
  ha_pR->Write();


  //==================================================== a_amp_p
  // a_amp_p is the pedestal subtracted amplitude in mV
  // canvas
  TCanvas* c2 = new TCanvas("c2","",800,600);
  c2->Divide(2,1);
  // histogram
  TH2F* ha_amp_pL = new TH2F("ha_amp_pL", "", 100,-100,100, 90,-0.5,89.5);
  TH2F* ha_amp_pR = new TH2F("ha_amp_pR", "", 100,-100,100, 90,-0.5,89.5);
  // Left pmts
  c2->cd(1);//->SetLogz(1);
  ha_amp_pL->GetXaxis()->SetTitle("fADC a_amp_p (a_time>0 && a_mult>0) [mV]");
  ha_amp_pL->GetYaxis()->SetTitle("PMT number (Left)");
  T->Draw("bb.hodoadc.adccol:bb.hodoadc.a_amp_p>>ha_amp_pL",
  	  "bb.hodoadc.adcrow==0 && bb.hodoadc.a_time>0 && bb.hodoadc.a_mult>0",
  	  "colz",nEv);
  // Right pmts
  c2->cd(2);//->SetLogz(1);
  ha_amp_pR->GetXaxis()->SetTitle("fADC a_amp_p (a_time>0 && a_mult>0) [mV]");
  ha_amp_pR->GetYaxis()->SetTitle("PMT number (Right)");
  T->Draw("bb.hodoadc.adccol:bb.hodoadc.a_amp_p>>ha_amp_pR",
	  "bb.hodoadc.adcrow==1 && bb.hodoadc.a_time>0 && bb.hodoadc.a_mult>0",
	  "colz",nEv);

  ha_amp_pL->Write();
  ha_amp_pR->Write();



  //==================================================== ped
  // a_ped is the fadc ped
  // canvas
  TCanvas* c3 = new TCanvas("c3","",800,600);
  c3->Divide(2,1);
  // histogram
  TH2F* ha_pedL = new TH2F("ha_pedL", "", 125,-50,200, 90,-0.5,89.5);
  TH2F* ha_pedR = new TH2F("ha_pedR", "", 125,-50,200, 90,-0.5,89.5);
  // Left pmts
  c3->cd(1);//->SetLogz(1);
  ha_pedL->GetXaxis()->SetTitle("fADC ped (a_time>0 && a_mult>0)");
  ha_pedL->GetYaxis()->SetTitle("PMT number (Left)");
  T->Draw("bb.hodoadc.adccol:bb.hodoadc.ped>>ha_pedL",
  	  "bb.hodoadc.adcrow==0 && bb.hodoadc.a_time>0 && bb.hodoadc.a_mult>0",
  	  "colz",nEv);
  // Right pmts
  c3->cd(2);//->SetLogz(1);
  ha_pedR->GetXaxis()->SetTitle("fADC ped (a_time>0 && a_mult>0)");
  ha_pedR->GetYaxis()->SetTitle("PMT number (Right)");
  T->Draw("bb.hodoadc.adccol:bb.hodoadc.ped>>ha_pedR",
	  "bb.hodoadc.adcrow==1 && bb.hodoadc.a_time>0 && bb.hodoadc.a_mult>0",
	  "colz",nEv);

  ha_pedL->Write();
  ha_pedR->Write();

 //==================================================== tot
  // selecting right tdc for fadc
  // Int_t tdcstartleft = adcbarstart;
  // Int_t tdcstartright = adcbarstart+90;
  // canvas
  TCanvas* c8 = new TCanvas("c8","",800,600);
  c8->Divide(2,1);
  // histogram
  TH2F* htotL = new TH2F("htotL", "", 100,0,50, 180,-0.5,179.5);
  TH2F* htotR = new TH2F("htotR", "", 100,0,50, 180,-0.5,179.5);
  // Left pmts
  c8->cd(1);//->SetLogz(1);
  htotL->GetXaxis()->SetTitle("raw hit tot (ns)");
  htotL->GetYaxis()->SetTitle("PMT number (Left)");
  // T->Draw("bb.hodotdc.hits.TDCelemID:bb.hodotdc.hits.t_tot>>htotL",
  // 	  "bb.hodotdc.hits.TDCelemID<90","colz",nEv);
  T->Draw("bb.hodotdc.hits.TDCelemID:bb.hodotdc.hits.t_tot>>htotL","","colz",nEv);
  // Right pmts
  c8->cd(2);//->SetLogz(1);
  htotR->GetXaxis()->SetTitle("raw hit tot (ns)");
  htotR->GetYaxis()->SetTitle("PMT number (Right)");
  T->Draw("bb.hodotdc.hits.TDCelemID:bb.hodotdc.hits.t_tot>>htotL",
  	  "bb.hodotdc.hits.TDCelemID>89 && bb.hodoadc.a_time>0 && bb.hodoadc.a_mult>0",
  	  "colz",nEv);
  htotL->Write();
  htotR->Write();



  //==================================================== a_amp_p vs tot
  // a_amp_p versus tot
  // LEFT
  // canvas
  TCanvas* c4 = new TCanvas("c4","",800,600);
  c4->Divide(6,6);
  TCanvas* c5 = new TCanvas("c5","",800,600);
  c5->Divide(6,6);
  // selecting right tdc for fadc
  Int_t tdcstartleft = adcbarstart;
  Int_t tdcstartright = adcbarstart+90;
  // histograms
  TH2F *hTOTvAmppL[nBarsADC];
  TH2F *hTOTvAmppR[nBarsADC];
  // bar loop
  for(Int_t bar=0; bar<(nBarsADC); bar++){
    Int_t adcbar = adcbarstart + bar;

    // left
    // switch canvas pad
    c4->cd(bar+1);//->SetLogz(1);
    hTOTvAmppL[bar] = new TH2F(TString::Format("hTOTvAmppL_Bar%d",adcbar),
			       TString::Format("hTOTvAmppL_Bar%d",adcbar),
			       100, -100, 100,
			       100, 0, 50
			       );
    // get the cuts to plot
    Int_t tdcL = tdcstartleft+bar;
    TString cutleft = "";
    cutleft += "bb.hodoadc.adcrow==0 && bb.hodoadc.a_time>0 && bb.hodoadc.a_mult>0&&bb.hodoadc.adccol==";
    cutleft += adcbar;
    cutleft += "&&bb.hodotdc.hits.TDCelemID==";
    // cutleft += "&&bb.hodotdc.hits.tdccol==";
    cutleft +=tdcL;
    // get the draw command
    TString drawleft = "";
    drawleft += "bb.hodotdc.hits.t_tot:bb.hodoadc.a_amp_p>>hTOTvAmppL_Bar";
    drawleft += adcbar;
    // do the draw
    T->Draw(drawleft,cutleft,"colz",nEv);
    hTOTvAmppL[bar]->Write();
    cutleft.Clear();
    drawleft.Clear();

    // right
    // switch canvas pad
    c5->cd(bar+1);//->SetLogz(1);
    hTOTvAmppR[bar] = new TH2F(TString::Format("hTOTvAmppR_Bar%d",adcbar),
			       TString::Format("hTOTvAmppR_Bar%d",adcbar),
			       100, -100, 100,
			       100, 0, 50
			       );
    // get the cuts to plot
    Int_t tdcR = tdcstartright+bar;
    TString cutright = "";
    cutright += "bb.hodoadc.adcrow==1 && bb.hodoadc.a_time>0 && bb.hodoadc.a_mult>0&&bb.hodoadc.adccol==";
    cutright += adcbar;
    cutright += "&&bb.hodotdc.hits.TDCelemID==";
    // cutright += "&&bb.hodotdc.hits.tdccol==";
    cutright +=tdcR;
    // get the draw command
    TString drawright = "";
    drawright += "bb.hodotdc.hits.t_tot:bb.hodoadc.a_amp_p>>hTOTvAmppR_Bar";
    drawright += adcbar;
    // do the draw
    T->Draw(drawright,cutright,"colz",nEv);
    hTOTvAmppR[bar]->Write();
    cutright.Clear();
    drawright.Clear();

  }//bar loop



  //==================================================== a_p vs tot
  // a_p versus tot
  // LEFT
  // canvas
  TCanvas* c6 = new TCanvas("c6","",800,600);
  c6->Divide(6,6);
  TCanvas* c7 = new TCanvas("c7","",800,600);
  c7->Divide(6,6);
  // histograms
  TH2F *hTOTvApL[nBarsADC];
  TH2F *hTOTvApR[nBarsADC];
  // bar loop
  for(Int_t bar=0; bar<(nBarsADC); bar++){
    Int_t adcbar = adcbarstart + bar;

    // left
    // switch canvas pad
    c6->cd(bar+1);//->SetLogz(1);
    hTOTvApL[bar] = new TH2F(TString::Format("hTOTvApL_Bar%d",adcbar),
			     TString::Format("hTOTvApL_Bar%d",adcbar),
			     100, -100, 100,
			     100, 0, 50
			     );
    // get the cuts to plot
    Int_t tdcLAp = tdcstartleft+bar;
    TString cutleftAp = "";
    cutleftAp += "bb.hodoadc.adcrow==0 && bb.hodoadc.a_time>0 && bb.hodoadc.a_mult>0&&bb.hodoadc.adccol==";
    cutleftAp += adcbar;
    cutleftAp += "&&bb.hodotdc.hits.TDCelemID==";
    // cutleftAp += "&&bb.hodotdc.hits.tdccol==";
    cutleftAp +=tdcLAp;
    // get the draw command
    TString drawleftAp = "";
    drawleftAp += "bb.hodotdc.hits.t_tot:bb.hodoadc.a_p>>hTOTvApL_Bar";
    drawleftAp += adcbar;
    // do the draw
    T->Draw(drawleftAp,cutleftAp,"colz",nEv);
    hTOTvApL[bar]->Write();
    cutleftAp.Clear();
    drawleftAp.Clear();

    // right
    // switch canvas pad
    c7->cd(bar+1);//->SetLogz(1);
    hTOTvApR[bar] = new TH2F(TString::Format("hTOTvApR_Bar%d",adcbar),
			     TString::Format("hTOTvApR_Bar%d",adcbar),
			     100, -100, 100,
			     100, 0, 50
			     );
    // get the cuts to plot
    Int_t tdcRAp = tdcstartright+bar;
    TString cutrightAp = "";
    cutrightAp += "bb.hodoadc.adcrow==1 && bb.hodoadc.a_time>0 && bb.hodoadc.a_mult>0&&bb.hodoadc.adccol==";
    cutrightAp += adcbar;
    cutrightAp += "&&bb.hodotdc.hits.TDCelemID==";
    // cutrightAp += "&&bb.hodotdc.hits.tdccol==";
    cutrightAp +=tdcRAp;
    // get the draw command
    TString drawrightAp = "";
    drawrightAp += "bb.hodotdc.hits.t_tot:bb.hodoadc.a_p>>hTOTvApR_Bar";
    drawrightAp += adcbar;
    // do the draw
    T->Draw(drawrightAp,cutrightAp,"colz",nEv);
    hTOTvApR[bar]->Write();
    cutrightAp.Clear();
    drawrightAp.Clear();

  }//bar loop



 



  //==================================================== END MAIN
  fout->Close();
}
