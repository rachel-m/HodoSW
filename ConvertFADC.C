#include "GMnTree.C"
using namespace std;
void ConvertFADC(){

  //setup chain
  TChain *C = new TChain("T");
  //C->Add("/volatile/halla/sbs/gpenman/Rootfiles/GMn/*14008*");
  //C->Add("/volatile/halla/sbs/gpenman/Rootfiles/GMn/*14015*");
  C->Add("/volatile/halla/sbs/gpenman/Rootfiles/GMn/*14016*");
  //C->Add("/volatile/halla/sbs/gpenman/Rootfiles/GMn/*14032*");
  GMnTree *T = new GMnTree(C);

  //histograms
  TH1D *hHiL = new TH1D("hHiL","",50,0,5);
  TH1D *hHiR = new TH1D("hHiR","",50,0,5);
  TH1D *hLoL = new TH1D("hLoL","",50,0,5);
  TH1D *hLoR = new TH1D("hLoR","",50,0,5);

  //event loop
  Long64_t Nev = C->GetEntries();
  cout << "Processing " << Nev << endl;

  C->Draw("bb.hodoadc.a_amp","bb.hodotdc.bar.tdc.id == 45");
  /*
  for (Long64_t ev=0; ev<Nev; ev++){

    if( ev%10000 == 0 )
      cout << ev << endl;

    T->GetEntry(ev);
    
    Int_t Ntdcbar = T->Ndata_bb_hodotdc_bar_tdc_id;
    Int_t Nadcbar = T->Ndata_bb_hodoadc_bar_adc_id;
    
    Int_t ngoodhits = T->bb_hodotdc_bar_ngoodbars;
    if (ngoodhits == 0) continue;
    //cout << ngoodhits << endl;

    if (Ntdcbar != ngoodhits) cout << "weirdness" << endl;
    if (Nadcbar > Ntdcbar) cout << "how???" << endl;
    //if (goodbar != 45) continue;
    
    Int_t Ntdc = T->Ndata_bb_hodotdc_tdcelemID;
    Int_t Nadc = T->Ndata_bb_hodoadc_adcelemID;
    
    //cout << "N good bar tdc/adc " << Ntdcbar << " / " << Nadcbar << endl;
    //cout << Nadc << " " << Ntdc << endl;
    
    
    for (Int_t i=1; i<Nadc; i++){
      if (T->bb_hodoadc_adcelemID[i] == 45  &&  T->bb_hodoadc_adcelemID[i] == 45  &&  T->bb_hodoadc_adcelemID[i+1] == 46){
	
	hHiL->Fill(T->bb_hodoadc_adc_a_amp[i]);
	hHiR->Fill(T->bb_hodoadc_adc_a_amp[i]);
	hLoL->Fill(T->bb_hodoadc_adc_a_amp[i]);
	hLoR->Fill(T->bb_hodoadc_adc_a_amp[i]);
      }
    
  }
    
    }
  */



}
