#include "TStyle.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TString.h"
#include "TH2.h"

void plot2D( TString fname = "bbhodo_143_-1.root", Int_t nplot = 5000000000 )
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

  TH2F* hptL = new TH2F("hptL","", 100,0,75,95,0,94);
  TH2F* hptR = new TH2F("hptR","", 100,0,75,95,0,94);
  
  c1->Divide(2,1);
  c1->cd(1);//->SetLogz(1);
  T->Draw("bb.hodotdc.tdccol:bb.hodotdc.tdc >>hptL","bb.hodotdc.tdc_mult>=1&&bb.hodotdc.tdcrow==0","colz",nplot);
  hptL->GetXaxis()->SetTitle("TDC Leading Edge Time [ns]");
  hptL->GetYaxis()->SetTitle("PMT number (Left)");

  c1->cd(2);//->SetLogz(1);
  T->Draw("bb.hodotdc.tdccol:bb.hodotdc.tdc>>hptR","bb.hodotdc.tdc_mult>=1&&bb.hodotdc.tdcrow==1","colz",nplot);
  hptR->GetXaxis()->SetTitle("TDC Leading Edge Time [ns]");
  hptR->GetYaxis()->SetTitle("PMT number (Right)");

  // ---------------------------------------------------------------------------------------------

  TCanvas* c2 = new TCanvas("c2","",1200,800);

  TH2F* hptotL = new TH2F("hptotL","", 100,0,50,95,0,94);
  TH2F* hptotR = new TH2F("hptotR","", 100,0,50,95,0,94);
  
  c2->Divide(2,1);
  c2->cd(1);//->SetLogz(1);
  T->Draw("bb.hodotdc.tdccol:bb.hodotdc.tdc_tot >>hptotL","bb.hodotdc.tdc_mult>=1&&bb.hodotdc.tdcrow==0","colz",nplot);
  hptotL->GetXaxis()->SetTitle("TDC TOT [ns]");
  hptotL->GetYaxis()->SetTitle("PMT number (Left)");

  c2->cd(2);//->SetLogz(1);
  T->Draw("bb.hodotdc.tdccol:bb.hodotdc.tdc_tot>>hptotR","bb.hodotdc.tdc_mult>=1&&bb.hodotdc.tdcrow==1","colz",nplot);
  hptotR->GetXaxis()->SetTitle("TDC TOT [ns]");
  hptotR->GetYaxis()->SetTitle("PMT number (Right)");

  // ---------------------------------------------------------------------------------------------

  TCanvas* c3 = new TCanvas("c3","",1200,800);

  TH2F* hpmultL = new TH2F("hpmultL","", 5,0,5,95,0,94);
  TH2F* hpmultR = new TH2F("hpmultR","", 5,0,5,95,0,94);
  
  c3->Divide(2,1);
  c3->cd(1);//->SetLogz(1);
  T->Draw("bb.hodotdc.tdccol:bb.hodotdc.tdc_mult >>hpmultL","bb.hodotdc.tdc_mult>=1&&bb.hodotdc.tdcrow==0","colz",nplot);
  hpmultL->GetXaxis()->SetTitle("TDC Mutiplicity");
  hpmultL->GetYaxis()->SetTitle("PMT number (Left)");

  c3->cd(2);//->SetLogz(1);
  T->Draw("bb.hodotdc.tdccol:bb.hodotdc.tdc_mult>>hpmultR","bb.hodotdc.tdc_mult>=1&&bb.hodotdc.tdcrow==1","colz",nplot);
  //  T->Draw("bb.hodotdc.tdccol:bb.hodotdc.tdc_mult>>hpmultR","bb.hodotdc.tdc_mult>=1&&bb.hodotdc.tdcrow==1&&bb.hodotdc.tdccol<78","colz",nplot);
  hpmultR->GetXaxis()->SetTitle("TDC Mutliplicty");
  hpmultR->GetYaxis()->SetTitle("PMT number (Right)");

  // ---------------------------------------------------------------------------------------------

  TCanvas* c4 = new TCanvas("c4","",1200,800);

  TH2F* hbtL = new TH2F("hbtL","", 100,0,75,95,0,94);
  TH1F* hbt1 = new TH1F("hbt1","", 95,0,94);
  TH1F* hbt2 = new TH1F("hbt2","", 95,0,94);
  TH1F* hbt3 = new TH1F("hbt3","", 95,0,94);
  
  c4->Divide(2,1);
  c4->cd(1);//->SetLogz(1);
  T->Draw("bb.hodotdc.tdcbarid:bb.hodotdc.barmeantime >>hbtL","Ndata.bb.hodotdc.tdcbarid!=0","colz",nplot);
  hbtL->GetXaxis()->SetTitle("Bar Mean Time [ns]");
  hbtL->GetYaxis()->SetTitle("Bar Number");

  c4->cd(2);
  hbt1 = (TH1F*)hpmultR->ProjectionY();
  hbt1->SetLineWidth(2);
  hbt1->SetLineColor(4);
  hbt1->Draw("");
  hbt1->GetXaxis()->SetTitle("Bar / PMT Number");
  hbt1->Sumw2();

  T->Draw("bb.hodotdc.tdcbarid >>hbt2","Ndata.bb.hodotdc.tdcbarid!=0","same",nplot);
  hbt2->SetLineColor(1);
  hbt2->SetLineWidth(2);
  hbt2->Sumw2();
 
  hbt3 = (TH1F*)hpmultL->ProjectionY();
  hbt3->SetLineColor(2);
  hbt3->SetLineWidth(2);
  hbt3->Draw("same");
  hbt3->Sumw2();

  cout << "Non-zero mutiplicty (Left) = " << (Double_t)hpmultL->ProjectionX()->GetMean() << endl;
  cout << "Non-zero mutiplicty (Right) = " << (Double_t)hpmultR->ProjectionX()->GetMean() << endl;

  TLatex* tex = new TLatex( 0.5, 0.5, "Bar");
  tex->SetNDC(1);
  tex->SetTextFont(42);
  tex->SetTextColor(1);
  tex->SetTextSize(0.05);
  tex->Draw();

  tex = new TLatex( 0.5, 0.4, "Left PMT");
  tex->SetNDC(1);
  tex->SetTextFont(42);
  tex->SetTextColor(2);
  tex->SetTextSize(0.05);
  tex->Draw();

  tex = new TLatex( 0.5, 0.3, "Right PMT");
  tex->SetNDC(1);
  tex->SetTextFont(42);
  tex->SetTextColor(4);
  tex->SetTextSize(0.05);
  tex->Draw();

  // ---------------------------------------------------------------------------------------------

//   TCanvas* c5 = new TCanvas("c5","",1200,800);

//   TH2F* hpqdcL = new TH2F("hpqdcL","", 400,0,1000,35,0,34);
//   TH2F* hpqdcR = new TH2F("hpqdcR","", 400,0,1000,35,0,34);
  
//   c5->Divide(2,1);
//   c5->cd(1)->SetLogz(1);
//   T->Draw("bb.hodoadc.adccol:bb.hodoadc.a >>hpqdcL","bb.hodoadc.adcrow==0","colz",nplot);
//   hpqdcL->GetXaxis()->SetTitle("QDC [channels]");
//   hpqdcL->GetYaxis()->SetTitle("PMT number (Left)");

//   c5->cd(2)->SetLogz(1);
//   T->Draw("bb.hodoadc.adccol:bb.hodoadc.a >>hpqdcR","bb.hodoadc.adcrow==1","colz",nplot);
//   hpqdcR->GetXaxis()->SetTitle("QDC [channels]");
//   hpqdcR->GetYaxis()->SetTitle("PMT number (Right)");

  // ---------------------------------------------------------------------------------------------

  // c1->Print("bbhodo1.pdf");
  // c2->Print("bbhodo2.pdf");
  // c3->Print("bbhodo3.pdf");
  // c4->Print("bbhodo4.pdf");
  // //  c5->Print("bbhodo5.pdf");
  // gSystem->Exec("pdfunite bbhodo*.pdf OnlineBBHodo2D.pdf"); 
  // gSystem->Exec("rm bbhodo*.pdf"); 


}
