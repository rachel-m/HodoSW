void PMTMultdraw(){

  // gPad->SetLogy();

  TString hnameR = "hHitPMTR";
  TH1F *hR = (TH1F*)gDirectory->Get(hnameR);
  hR->Sumw2();
  hR->SetLineWidth(2);
  hR->SetLineColor(4);
  hR->Draw("");

  TString hnameL = "hHitPMTL";
  TH1F *hL = (TH1F*)gDirectory->Get(hnameL);
  hL->Sumw2();
  hL->SetLineWidth(2);
  hL->SetLineColor(2);
  hL->Draw("sames");
  
  TString hnameBar = "h1d_BarMT";
  TH1F *hB = (TH1F*)gDirectory->Get(hnameBar);
  hB->SetLineWidth(2);
  hB->SetLineColor(1);
  hB->Draw("sames");

  TLatex* tex = new TLatex( 0.5, 0.25, "Bar");
  tex->SetNDC(1);
  tex->SetTextFont(42);
  tex->SetTextColor(1);
  tex->SetTextSize(0.05);
  tex->Draw();

  tex = new TLatex( 0.5, 0.20, "Left PMT");
  tex->SetNDC(1);
  tex->SetTextFont(42);
  tex->SetTextColor(2);
  tex->SetTextSize(0.05);
  tex->Draw();

  tex = new TLatex( 0.5, 0.15, "Right PMT");
  tex->SetNDC(1);
  tex->SetTextFont(42);
  tex->SetTextColor(4);
  tex->SetTextSize(0.05);
  tex->Draw();
  
}// macro end
