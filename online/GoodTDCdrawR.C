void GoodTDCdrawR(Int_t Ch){

  gPad->SetLogy();

  TString hnameLE = "hGoodLe_Bar";
  hnameLE += Ch;
  hnameLE +="_R";
  TH1F *hLE = (TH1F*)gDirectory->Get(hnameLE);
  hLE->SetLineColor(2);
  TString title = "Bar ";
  title += Ch;
  hLE->SetTitle(title);
  hLE->SetTitleSize(19);
  // hLE->GetXaxis()->SetLabelSize(0.04);
  hLE->GetXaxis()->SetTitle("Time (ns)");
  hLE->GetXaxis()->SetTitleSize(0.04);
  hLE->Draw();
  
  TString hnameTE = "hGoodTe_Bar";
  hnameTE += Ch;
  hnameTE +="_R";
  TH1F *hTE = (TH1F*)gDirectory->Get(hnameTE);
  hTE->SetLineColor(4);
  hTE->Draw("sames");
  
}// macro end
