void GoodRefTDCdrawL(){

  // gPad->SetLogy();

  TString hnameLE = "hGoodRefLE_L";
  TH1F *hGoodLE = (TH1F*)gDirectory->Get(hnameLE);
  hGoodLE->SetLineColor(2);
  hGoodLE->GetXaxis()->SetLabelSize(0.07);
  hGoodLE->SetTitleSize(16);
  hGoodLE->Draw();
  
  TString hnameTE = "hGoodRefTE_L";
  TH1F *hGoodTE = (TH1F*)gDirectory->Get(hnameTE);
  hGoodTE->SetLineColor(4);
  hGoodTE->GetXaxis()->SetLabelSize(0.07);
  hGoodTE->SetTitleSize(16);
  hGoodTE->Draw("sames");
  
}// macro end
