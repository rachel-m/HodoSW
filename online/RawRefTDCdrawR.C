void RawRefTDCdrawR(){

  gPad->SetLogy();

  TString hnameLE = "hRawRefLE_R";
  TH1F *hRawLE = (TH1F*)gDirectory->Get(hnameLE);
  hRawLE->SetLineColor(2);
  hRawLE->GetXaxis()->SetLabelSize(0.07);
  hRawLE->SetTitleSize(16);
  hRawLE->Draw();
  
  TString hnameTE = "hRawRefTE_R";
  TH1F *hRawTE = (TH1F*)gDirectory->Get(hnameTE);
  hRawTE->SetLineColor(4);
  hRawTE->GetXaxis()->SetLabelSize(0.07);
  hRawTE->SetTitleSize(16);
  hRawTE->Draw("sames");
  
}// macro end
