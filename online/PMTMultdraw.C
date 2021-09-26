void PMTMultdraw(){

  // gPad->SetLogy();

  TString hnameR = "hpmultR_py";
  TH1F *hR = (TH1F*)gDirectory->Get(hnameR);
  hR->SetLineWidth(2);
  hR->SetLineColor(4);
  hR->Draw("");

  TString hnameL = "hpmultL_py";
  TH1F *hL = (TH1F*)gDirectory->Get(hnameL);
  hL->SetLineWidth(2);
  hL->SetLineColor(2);
  hL->Draw("sames");
  
  TString hnameBar = "hbt2";
  TH1F *hB = (TH1F*)gDirectory->Get(hnameBar);
  hB->SetLineWidth(2);
  hB->SetLineColor(1);
  hB->Draw("sames");

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
  
}// macro end
