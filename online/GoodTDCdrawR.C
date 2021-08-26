void GoodTDCdrawR(Int_t Ch){

  // gPad->SetLogy();

  TString hnameLE = "hGoodLe_Bar";
  hnameLE += Ch;
  hnameLE +="_R";
  TH1F *hLE = (TH1F*)gDirectory->Get(hnameLE);
  hLE->SetLineColor(2);
  hLE->GetXaxis()->SetLabelSize(0.07);
  hLE->SetTitleSize(16);
  hLE->Draw();
  
  TString hnameTE = "hGoodTe_Bar";
  hnameTE += Ch;
  hnameTE +="_R";
  TH1F *hTE = (TH1F*)gDirectory->Get(hnameTE);
  hTE->SetLineColor(4);
  hTE->GetXaxis()->SetLabelSize(0.07);
  hTE->SetTitleSize(16);
  hTE->Draw("sames");
  
}// macro end
