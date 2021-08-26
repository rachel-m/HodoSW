void RawTDCdrawR(Int_t Ch){

  // gPad->SetLogy();

  TString hnameLE = "hRawLe_Bar";
  hnameLE += Ch;
  hnameLE +="_R";
  TH1D *hRawLE = (TH1D*)gDirectory->Get(hnameLE);
  hRawLE->SetLineColor(2);
  hRawLE->GetXaxis()->SetLabelSize(0.06);
  hRawLE->Draw();
  
  TString hnameTE = "hRawTe_Bar";
  hnameTE += Ch;
  hnameTE +="_R";
  TH1D *hRawTE = (TH1D*)gDirectory->Get(hnameTE);
  hRawTE->SetLineColor(4);
  hRawTE->GetXaxis()->SetLabelSize(0.06);
  hRawTE->Draw("sames");
  

}// macro end
