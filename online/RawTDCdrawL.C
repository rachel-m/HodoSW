void RawTDCdrawL(Int_t Ch){

  gPad->SetLogy();

  TString hnameLE = "hRawLe_Bar";
  hnameLE += Ch;
  hnameLE +="_L";
  TH1F *hRawLE = (TH1F*)gDirectory->Get(hnameLE);
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
  hnameTE +="_L";
  TH1F *hRawTE = (TH1F*)gDirectory->Get(hnameTE);
  hRawTE->SetLineColor(4);
  hRawTE->Draw("sames");
  
}// macro end
