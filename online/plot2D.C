#include "TStyle.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TString.h"
#include "TH2.h"

void plot2D( TString fname = "bbhodo_82_50000.root", Int_t nplot = 50000 )
{

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

  TFile* f = new TFile( fname );
  TTree* T = (TTree*)f->Get("T");

  TCanvas* c1 = new TCanvas("c1","",1200,800);

  TH2F* hptL = new TH2F("hptL","", 100,-70,70,95,0,94);
  TH2F* hptR = new TH2F("hptR","", 100,-70,70,95,0,94);
  
  c1->Divide(2,1);
  c1->cd(1)->SetLogz(1);
  T->Draw("bb.hodotdc.tdccol:bb.hodotdc.tdc >>hptL","bb.hodotdc.tdc_mult>=1&&bb.hodotdc.tdcrow==0","colz",nplot);
  hptL->GetXaxis()->SetTitle("TDC Leading Edge Time [channels]");
  hptL->GetYaxis()->SetTitle("PMT number (Left)");

  c1->cd(2)->SetLogz(1);
  T->Draw("bb.hodotdc.tdccol:bb.hodotdc.tdc>>hptR","bb.hodotdc.tdc_mult>=1&&bb.hodotdc.tdcrow==1","colz",nplot);
  hptR->GetXaxis()->SetTitle("TDC Leading Edge Time [channels]");
  hptR->GetYaxis()->SetTitle("PMT number (Right)");

  // ---------------------------------------------------------------------------------------------

  TCanvas* c2 = new TCanvas("c2","",1200,800);

  TH2F* hptotL = new TH2F("hptotL","", 100,0,70,95,0,94);
  TH2F* hptotR = new TH2F("hptotR","", 100,0,70,95,0,94);
  
  c2->Divide(2,1);
  c2->cd(1)->SetLogz(1);
  T->Draw("bb.hodotdc.tdccol:bb.hodotdc.tdc_tot >>hptotL","bb.hodotdc.tdc_mult>=1&&bb.hodotdc.tdcrow==0","colz",nplot);
  hptotL->GetXaxis()->SetTitle("TDC TOT [channels]");
  hptotL->GetYaxis()->SetTitle("PMT number (Left)");

  c2->cd(2)->SetLogz(1);
  T->Draw("bb.hodotdc.tdccol:bb.hodotdc.tdc_tot>>hptotR","bb.hodotdc.tdc_mult>=1&&bb.hodotdc.tdcrow==1","colz",nplot);
  hptotR->GetXaxis()->SetTitle("TDC TOT [channels]");
  hptotR->GetYaxis()->SetTitle("PMT number (Right)");

  // ---------------------------------------------------------------------------------------------

  TCanvas* c3 = new TCanvas("c3","",1200,800);

  TH2F* hpmultL = new TH2F("hpmultL","", 10,0,10,95,0,94);
  TH2F* hpmultR = new TH2F("hpmultR","", 10,0,10,95,0,94);
  
  c3->Divide(2,1);
  c3->cd(1)->SetLogz(1);
  T->Draw("bb.hodotdc.tdccol:bb.hodotdc.tdc_mult >>hpmultL","bb.hodotdc.tdc_mult>=1&&bb.hodotdc.tdcrow==0","colz",nplot);
  hpmultL->GetXaxis()->SetTitle("TDC Mutiplicity");
  hpmultL->GetYaxis()->SetTitle("PMT number (Left)");

  c3->cd(2)->SetLogz(1);
  T->Draw("bb.hodotdc.tdccol:bb.hodotdc.tdc_mult>>hpmultR","bb.hodotdc.tdc_mult>=1&&bb.hodotdc.tdcrow==1","colz",nplot);
  hpmultR->GetXaxis()->SetTitle("TDC Mutliplicty");
  hpmultR->GetYaxis()->SetTitle("PMT number (Right)");

  // ---------------------------------------------------------------------------------------------

  TCanvas* c4 = new TCanvas("c4","",1200,800);

  TH2F* hbtL = new TH2F("hbtL","", 100,-70,70,95,0,94);
  TH1F* hbtR = new TH1F("hbtR","", 95,0,94);
  
  c4->Divide(2,1);
  c4->cd(1)->SetLogz(1);
  T->Draw("bb.hodotdc.tdcbarid:bb.hodotdc.barmeantime >>hbtL","Ndata.bb.hodotdc.tdcbarid!=0","colz",nplot);
  hbtL->GetXaxis()->SetTitle("Bar Mean Time [channels]");
  hbtL->GetYaxis()->SetTitle("Paddle number");

  c4->cd(2)->SetLogz(1);
  T->Draw("bb.hodotdc.tdcbarid >>hbtR","Ndata.bb.hodotdc.tdcbarid!=0","",nplot);
  hbtR->GetXaxis()->SetTitle("Paddle Number");

  // ---------------------------------------------------------------------------------------------

  c1->Print("bbhodo1.pdf");
  c2->Print("bbhodo2.pdf");
  c3->Print("bbhodo3.pdf");
  c4->Print("bbhodo4.pdf");
  gSystem->Exec("pdfunite bbhodo*.pdf OnlineBBHodo2D.pdf"); 
  gSystem->Exec("rm bbhodo*.pdf"); 


}
