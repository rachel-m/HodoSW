void RawTDCdrawR(Int_t Ch){

  gPad->SetLogy();

  TString hnameLE = "hRawLe_Bar";
  hnameLE += Ch;
  hnameLE +="_R";
  TH1D *hRawLE = (TH1D*)gDirectory->Get(hnameLE);
  hRawLE->SetLineColor(2);
  // hRawLE->SetTitle("");
  TString title = "Bar ";
  title += Ch;
  hRawLE->SetTitle(title);
  hRawLE->SetTitleSize(19);
  // hRawLE->GetXaxis()->SetLabelSize(0.04);
  hRawLE->GetXaxis()->SetTitle("Time (ns)");
  hRawLE->GetXaxis()->SetTitleSize(0.04);
  hRawLE->Draw();
  
  TString hnameTE = "hRawTe_Bar";
  hnameTE += Ch;
  hnameTE +="_R";
  TH1D *hRawTE = (TH1D*)gDirectory->Get(hnameTE);
  hRawTE->SetLineColor(4);
  hRawTE->GetXaxis()->SetLabelSize(0.06);
  hRawTE->Draw("sames");
  

}// macro end
