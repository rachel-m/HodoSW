{

TH2F *hpqdcl = new TH2F("hpqdcl","",400,50,300,35,0,34);
TH2F *hpqdcr = new TH2F("hpqdcr","",400,50,300,35,0,34);

 TCanvas *cfADC = new TCanvas("cfADC","cfADC",500,600);
 cfADC->Divide(2,1);
 cfADC->cd(1)->SetLogz(1);
 T->Draw("bb.hodoadc.adccol:bb.hodoadc.a_amp>>hpqdcl","bb.hodoadc.row==0","colz",nplot);

 cfADC->cd(2)->SetLogz(1);
 T->Draw("bb.hodoadc.adccol:bb.hodoadc.a_amp>>hpqdcl","bb.hodoadc.row==0","colz",nplot);

}
