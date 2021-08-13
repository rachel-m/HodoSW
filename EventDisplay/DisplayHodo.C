#include <TCanvas.h>
#include <TButton.h>
#include <TFile.h>
#include <TLine.h>

#include "bbhodo_tree.h"

void DisplayHodo(TString fname="bbhodo_307_500000.root")
{

  // --------------------------------------------------------------------------
  // Set up canvas for bars, PMTs and hits
  // --------------------------------------------------------------------------
  
  TCanvas* c1 = new TCanvas("canvas", "BB Hodoscope Display", 0, 0, 600, 800);
  c1->Range(0,0,1,1);

  TBox*    bar[90];
  TBox*    pmtL[90];
  TBox*    pmtR[90];
  TMarker* hit[90];

  // Canvas positions
  double ymin       = 0.05;
  double barxmin    = 0.2;
  double barxmax    = 0.8;
  double height     = 0.008;
  double separation = 0.01;
  double pmtLxmin   = 0.10;
  double pmtLxmax   = 0.19;
  double pmtRxmin   = 0.81;
  double pmtRxmax   = 0.90;

  for(int i = 0; i<90; i++ ) {
    bar[i]  = new TBox(barxmin, (ymin + i*separation), barxmax, (ymin + height + i*separation));
    pmtL[i] = new TBox(pmtLxmin,(ymin + i*separation), pmtLxmax,(ymin + height + i*separation));
    pmtR[i] = new TBox(pmtRxmin,(ymin + i*separation), pmtRxmax,(ymin + height + i*separation));
    hit[i]  = new TMarker();
  }

  c1->Update();
  gSystem->ProcessEvents();

  // --------------------------------------------------------------------------
  // Get tree
  // --------------------------------------------------------------------------

  TChain *fChain = new TChain("T");
  fChain->Add(fname);

  //Declaration of leaves types
  Int_t           Ndata_bb_hodoadc_L_a;
  Double_t        bb_hodoadc_L_a[32];
  Int_t           Ndata_bb_hodoadc_L_ac;
  Double_t        bb_hodoadc_L_ac[32];
  Int_t           Ndata_bb_hodoadc_L_ap;
  Double_t        bb_hodoadc_L_ap[32];
  Int_t           Ndata_bb_hodoadc_R_a;
  Double_t        bb_hodoadc_R_a[32];
  Int_t           Ndata_bb_hodoadc_R_ac;
  Double_t        bb_hodoadc_R_ac[32];
  Int_t           Ndata_bb_hodoadc_R_ap;
  Double_t        bb_hodoadc_R_ap[32];
  Int_t           Ndata_bb_hodoadc_a;
  Double_t        bb_hodoadc_a[64];
  Int_t           Ndata_bb_hodoadc_a_c;
  Double_t        bb_hodoadc_a_c[64];
  Int_t           Ndata_bb_hodoadc_a_mult;
  Double_t        bb_hodoadc_a_mult[64];
  Int_t           Ndata_bb_hodoadc_a_p;
  Double_t        bb_hodoadc_a_p[64];
  Int_t           Ndata_bb_hodoadc_adcbarid;
  Double_t        bb_hodoadc_adcbarid[32];
  Int_t           Ndata_bb_hodoadc_adcmean;
  Double_t        bb_hodoadc_adcmean[32];
  Int_t           Ndata_bb_hodoadc_col;
  Double_t        bb_hodoadc_col[64];
  Int_t           Ndata_bb_hodoadc_elemID;
  Double_t        bb_hodoadc_elemID[64];
  Int_t           Ndata_bb_hodoadc_layer;
  Double_t        bb_hodoadc_layer[64];
  Int_t           Ndata_bb_hodoadc_ped;
  Double_t        bb_hodoadc_ped[64];
  Int_t           Ndata_bb_hodoadc_row;
  Double_t        bb_hodoadc_row[64];
  Int_t           Ndata_bb_hodotdc_L_le;
  Double_t        bb_hodotdc_L_le[89];
  Int_t           Ndata_bb_hodotdc_L_leW;
  Double_t        bb_hodotdc_L_leW[89];
  Int_t           Ndata_bb_hodotdc_L_te;
  Double_t        bb_hodotdc_L_te[89];
  Int_t           Ndata_bb_hodotdc_L_teW;
  Double_t        bb_hodotdc_L_teW[89];
  Int_t           Ndata_bb_hodotdc_L_tot;
  Double_t        bb_hodotdc_L_tot[89];
  Int_t           Ndata_bb_hodotdc_L_totW;
  Double_t        bb_hodotdc_L_totW[89];
  Int_t           Ndata_bb_hodotdc_R_le;
  Double_t        bb_hodotdc_R_le[89];
  Int_t           Ndata_bb_hodotdc_R_leW;
  Double_t        bb_hodotdc_R_leW[89];
  Int_t           Ndata_bb_hodotdc_R_te;
  Double_t        bb_hodotdc_R_te[89];
  Int_t           Ndata_bb_hodotdc_R_teW;
  Double_t        bb_hodotdc_R_teW[89];
  Int_t           Ndata_bb_hodotdc_R_tot;
  Double_t        bb_hodotdc_R_tot[89];
  Int_t           Ndata_bb_hodotdc_R_totW;
  Double_t        bb_hodotdc_R_totW[89];
  Int_t           Ndata_bb_hodotdc_Ref_tdc;
  Double_t        bb_hodotdc_Ref_tdc[2];
  Int_t           Ndata_bb_hodotdc_Ref_tdc_mult;
  Double_t        bb_hodotdc_Ref_tdc_mult[2];
  Int_t           Ndata_bb_hodotdc_Ref_tdc_te;
  Double_t        bb_hodotdc_Ref_tdc_te[2];
  Int_t           Ndata_bb_hodotdc_Ref_tdc_tot;
  Double_t        bb_hodotdc_Ref_tdc_tot[2];
  Int_t           Ndata_bb_hodotdc_barmeantime;
  Double_t        bb_hodotdc_barmeantime[89];
  Int_t           Ndata_bb_hodotdc_bartimediff;
  Double_t        bb_hodotdc_bartimediff[89];
  Int_t           Ndata_bb_hodotdc_bartimehitpos;
  Double_t        bb_hodotdc_bartimehitpos[89];
  Int_t           Ndata_bb_hodotdc_col;
  Double_t        bb_hodotdc_col[180];
  Int_t           Ndata_bb_hodotdc_elemID;
  Double_t        bb_hodotdc_elemID[180];
  Int_t           Ndata_bb_hodotdc_layer;
  Double_t        bb_hodotdc_layer[180];
  Int_t           Ndata_bb_hodotdc_row;
  Double_t        bb_hodotdc_row[180];
  Int_t           Ndata_bb_hodotdc_tdc;
  Double_t        bb_hodotdc_tdc[180];
  Int_t           Ndata_bb_hodotdc_tdc_mult;
  Double_t        bb_hodotdc_tdc_mult[180];
  Int_t           Ndata_bb_hodotdc_tdc_te;
  Double_t        bb_hodotdc_tdc_te[180];
  Int_t           Ndata_bb_hodotdc_tdc_tot;
  Double_t        bb_hodotdc_tdc_tot[180];
  Int_t           Ndata_bb_hodotdc_tdcbarid;
  Double_t        bb_hodotdc_tdcbarid[89];
  Double_t        bb_hodoadc_adcbaroff;
  Double_t        bb_hodoadc_ngoodhits;
  Double_t        bb_hodoadc_nhits;
  Double_t        bb_hodoadc_nrefhits;
  Double_t        bb_hodotdc_ngoodhits;
  Double_t        bb_hodotdc_nhits;
  Double_t        bb_hodotdc_nrefhits;
  Double_t        bb_hodotdc_tdcbaroff;
  
  // Set branch addresses.
  fChain->SetBranchAddress("Ndata.bb.hodoadc.L.a",&Ndata_bb_hodoadc_L_a);
  fChain->SetBranchAddress("bb.hodoadc.L.a",bb_hodoadc_L_a);
  fChain->SetBranchAddress("Ndata.bb.hodoadc.L.ac",&Ndata_bb_hodoadc_L_ac);
  fChain->SetBranchAddress("bb.hodoadc.L.ac",bb_hodoadc_L_ac);
  fChain->SetBranchAddress("Ndata.bb.hodoadc.L.ap",&Ndata_bb_hodoadc_L_ap);
  fChain->SetBranchAddress("bb.hodoadc.L.ap",bb_hodoadc_L_ap);
  fChain->SetBranchAddress("Ndata.bb.hodoadc.R.a",&Ndata_bb_hodoadc_R_a);
  fChain->SetBranchAddress("bb.hodoadc.R.a",bb_hodoadc_R_a);
  fChain->SetBranchAddress("Ndata.bb.hodoadc.R.ac",&Ndata_bb_hodoadc_R_ac);
  fChain->SetBranchAddress("bb.hodoadc.R.ac",bb_hodoadc_R_ac);
  fChain->SetBranchAddress("Ndata.bb.hodoadc.R.ap",&Ndata_bb_hodoadc_R_ap);
  fChain->SetBranchAddress("bb.hodoadc.R.ap",bb_hodoadc_R_ap);
  fChain->SetBranchAddress("Ndata.bb.hodoadc.a",&Ndata_bb_hodoadc_a);
  fChain->SetBranchAddress("bb.hodoadc.a",bb_hodoadc_a);
  fChain->SetBranchAddress("Ndata.bb.hodoadc.a_c",&Ndata_bb_hodoadc_a_c);
  fChain->SetBranchAddress("bb.hodoadc.a_c",bb_hodoadc_a_c);
  fChain->SetBranchAddress("Ndata.bb.hodoadc.a_mult",&Ndata_bb_hodoadc_a_mult);
  fChain->SetBranchAddress("bb.hodoadc.a_mult",bb_hodoadc_a_mult);
  fChain->SetBranchAddress("Ndata.bb.hodoadc.a_p",&Ndata_bb_hodoadc_a_p);
  fChain->SetBranchAddress("bb.hodoadc.a_p",bb_hodoadc_a_p);
  fChain->SetBranchAddress("Ndata.bb.hodoadc.adcbarid",&Ndata_bb_hodoadc_adcbarid);
  fChain->SetBranchAddress("bb.hodoadc.adcbarid",bb_hodoadc_adcbarid);
  fChain->SetBranchAddress("Ndata.bb.hodoadc.adcmean",&Ndata_bb_hodoadc_adcmean);
  fChain->SetBranchAddress("bb.hodoadc.adcmean",bb_hodoadc_adcmean);
  fChain->SetBranchAddress("Ndata.bb.hodoadc.col",&Ndata_bb_hodoadc_col);
  fChain->SetBranchAddress("bb.hodoadc.col",bb_hodoadc_col);
  fChain->SetBranchAddress("Ndata.bb.hodoadc.elemID",&Ndata_bb_hodoadc_elemID);
  fChain->SetBranchAddress("bb.hodoadc.elemID",bb_hodoadc_elemID);
  fChain->SetBranchAddress("Ndata.bb.hodoadc.layer",&Ndata_bb_hodoadc_layer);
  fChain->SetBranchAddress("bb.hodoadc.layer",bb_hodoadc_layer);
  fChain->SetBranchAddress("Ndata.bb.hodoadc.ped",&Ndata_bb_hodoadc_ped);
  fChain->SetBranchAddress("bb.hodoadc.ped",bb_hodoadc_ped);
  fChain->SetBranchAddress("Ndata.bb.hodoadc.row",&Ndata_bb_hodoadc_row);
  fChain->SetBranchAddress("bb.hodoadc.row",bb_hodoadc_row);
  fChain->SetBranchAddress("Ndata.bb.hodotdc.L.le",&Ndata_bb_hodotdc_L_le);
  fChain->SetBranchAddress("bb.hodotdc.L.le",bb_hodotdc_L_le);
  fChain->SetBranchAddress("Ndata.bb.hodotdc.L.leW",&Ndata_bb_hodotdc_L_leW);
  fChain->SetBranchAddress("bb.hodotdc.L.leW",bb_hodotdc_L_leW);
  fChain->SetBranchAddress("Ndata.bb.hodotdc.L.te",&Ndata_bb_hodotdc_L_te);
  fChain->SetBranchAddress("bb.hodotdc.L.te",bb_hodotdc_L_te);
  fChain->SetBranchAddress("Ndata.bb.hodotdc.L.teW",&Ndata_bb_hodotdc_L_teW);
  fChain->SetBranchAddress("bb.hodotdc.L.teW",bb_hodotdc_L_teW);
  fChain->SetBranchAddress("Ndata.bb.hodotdc.L.tot",&Ndata_bb_hodotdc_L_tot);
  fChain->SetBranchAddress("bb.hodotdc.L.tot",bb_hodotdc_L_tot);
  fChain->SetBranchAddress("Ndata.bb.hodotdc.L.totW",&Ndata_bb_hodotdc_L_totW);
  fChain->SetBranchAddress("bb.hodotdc.L.totW",bb_hodotdc_L_totW);
  fChain->SetBranchAddress("Ndata.bb.hodotdc.R.le",&Ndata_bb_hodotdc_R_le);
  fChain->SetBranchAddress("bb.hodotdc.R.le",bb_hodotdc_R_le);
  fChain->SetBranchAddress("Ndata.bb.hodotdc.R.leW",&Ndata_bb_hodotdc_R_leW);
  fChain->SetBranchAddress("bb.hodotdc.R.leW",bb_hodotdc_R_leW);
  fChain->SetBranchAddress("Ndata.bb.hodotdc.R.te",&Ndata_bb_hodotdc_R_te);
  fChain->SetBranchAddress("bb.hodotdc.R.te",bb_hodotdc_R_te);
  fChain->SetBranchAddress("Ndata.bb.hodotdc.R.teW",&Ndata_bb_hodotdc_R_teW);
  fChain->SetBranchAddress("bb.hodotdc.R.teW",bb_hodotdc_R_teW);
  fChain->SetBranchAddress("Ndata.bb.hodotdc.R.tot",&Ndata_bb_hodotdc_R_tot);
  fChain->SetBranchAddress("bb.hodotdc.R.tot",bb_hodotdc_R_tot);
  fChain->SetBranchAddress("Ndata.bb.hodotdc.R.totW",&Ndata_bb_hodotdc_R_totW);
  fChain->SetBranchAddress("bb.hodotdc.R.totW",bb_hodotdc_R_totW);
  fChain->SetBranchAddress("Ndata.bb.hodotdc.Ref.tdc",&Ndata_bb_hodotdc_Ref_tdc);
  fChain->SetBranchAddress("bb.hodotdc.Ref.tdc",bb_hodotdc_Ref_tdc);
  fChain->SetBranchAddress("Ndata.bb.hodotdc.Ref.tdc_mult",&Ndata_bb_hodotdc_Ref_tdc_mult);
  fChain->SetBranchAddress("bb.hodotdc.Ref.tdc_mult",bb_hodotdc_Ref_tdc_mult);
  fChain->SetBranchAddress("Ndata.bb.hodotdc.Ref.tdc_te",&Ndata_bb_hodotdc_Ref_tdc_te);
  fChain->SetBranchAddress("bb.hodotdc.Ref.tdc_te",bb_hodotdc_Ref_tdc_te);
  fChain->SetBranchAddress("Ndata.bb.hodotdc.Ref.tdc_tot",&Ndata_bb_hodotdc_Ref_tdc_tot);
  fChain->SetBranchAddress("bb.hodotdc.Ref.tdc_tot",bb_hodotdc_Ref_tdc_tot);
  fChain->SetBranchAddress("Ndata.bb.hodotdc.barmeantime",&Ndata_bb_hodotdc_barmeantime);
  fChain->SetBranchAddress("bb.hodotdc.barmeantime",bb_hodotdc_barmeantime);
  fChain->SetBranchAddress("Ndata.bb.hodotdc.bartimediff",&Ndata_bb_hodotdc_bartimediff);
  fChain->SetBranchAddress("bb.hodotdc.bartimediff",bb_hodotdc_bartimediff);
  fChain->SetBranchAddress("Ndata.bb.hodotdc.bartimehitpos",&Ndata_bb_hodotdc_bartimehitpos);
  fChain->SetBranchAddress("bb.hodotdc.bartimehitpos",bb_hodotdc_bartimehitpos);
  fChain->SetBranchAddress("Ndata.bb.hodotdc.col",&Ndata_bb_hodotdc_col);
  fChain->SetBranchAddress("bb.hodotdc.col",bb_hodotdc_col);
  fChain->SetBranchAddress("Ndata.bb.hodotdc.elemID",&Ndata_bb_hodotdc_elemID);
  fChain->SetBranchAddress("bb.hodotdc.elemID",bb_hodotdc_elemID);
  fChain->SetBranchAddress("Ndata.bb.hodotdc.layer",&Ndata_bb_hodotdc_layer);
  fChain->SetBranchAddress("bb.hodotdc.layer",bb_hodotdc_layer);
  fChain->SetBranchAddress("Ndata.bb.hodotdc.row",&Ndata_bb_hodotdc_row);
  fChain->SetBranchAddress("bb.hodotdc.row",bb_hodotdc_row);
  fChain->SetBranchAddress("Ndata.bb.hodotdc.tdc",&Ndata_bb_hodotdc_tdc);
  fChain->SetBranchAddress("bb.hodotdc.tdc",bb_hodotdc_tdc);
  fChain->SetBranchAddress("Ndata.bb.hodotdc.tdc_mult",&Ndata_bb_hodotdc_tdc_mult);
  fChain->SetBranchAddress("bb.hodotdc.tdc_mult",bb_hodotdc_tdc_mult);
  fChain->SetBranchAddress("Ndata.bb.hodotdc.tdc_te",&Ndata_bb_hodotdc_tdc_te);
  fChain->SetBranchAddress("bb.hodotdc.tdc_te",bb_hodotdc_tdc_te);
  fChain->SetBranchAddress("Ndata.bb.hodotdc.tdc_tot",&Ndata_bb_hodotdc_tdc_tot);
  fChain->SetBranchAddress("bb.hodotdc.tdc_tot",bb_hodotdc_tdc_tot);
  fChain->SetBranchAddress("Ndata.bb.hodotdc.tdcbarid",&Ndata_bb_hodotdc_tdcbarid);
  fChain->SetBranchAddress("bb.hodotdc.tdcbarid",bb_hodotdc_tdcbarid);
  fChain->SetBranchAddress("bb.hodoadc.adcbaroff",&bb_hodoadc_adcbaroff);
  fChain->SetBranchAddress("bb.hodoadc.ngoodhits",&bb_hodoadc_ngoodhits);
  fChain->SetBranchAddress("bb.hodoadc.nhits",&bb_hodoadc_nhits);
  fChain->SetBranchAddress("bb.hodoadc.nrefhits",&bb_hodoadc_nrefhits);
  fChain->SetBranchAddress("bb.hodotdc.ngoodhits",&bb_hodotdc_ngoodhits);
  fChain->SetBranchAddress("bb.hodotdc.nhits",&bb_hodotdc_nhits);
  fChain->SetBranchAddress("bb.hodotdc.nrefhits",&bb_hodotdc_nrefhits);
  fChain->SetBranchAddress("bb.hodotdc.tdcbaroff",&bb_hodotdc_tdcbaroff);
  
  Long64_t nentries = fChain->GetEntriesFast();
  
  // --------------------------------------------------------------------------
  // Get tree
  // --------------------------------------------------------------------------

  for (Long64_t ev=0; ev<nentries;ev++) {
    fChain->GetEntry(ev);
    
    // reset canvas
    c1->Clear();
    c1->Update();
    gSystem->ProcessEvents();
    
    for(int j=0; j<90; j++){
      // reset bar and pmt colours for each event
      if( j == 0 ) {
	bar[j]->SetFillColor(18);
	bar[j]->Draw("same");
	pmtL[j]->SetFillColor(17);
	pmtL[j]->Draw("same");
	pmtR[j]->SetFillColor(17);
	pmtR[j]->Draw("same");
      }
      else {
	bar[j]->SetFillColor(18);
	bar[j]->Draw("same");
	pmtL[j]->SetFillColor(17);
	pmtL[j]->Draw("same");
	pmtR[j]->SetFillColor(17);
	pmtR[j]->Draw("same");
      }

      hit[j]->SetMarkerStyle(28);
      hit[j]->SetMarkerColor(1);
      hit[j]->SetMarkerSize(1.0);

      // use GenericDetector variables for PMT display (blue if a "good" tdc hit)
      if( fabs(bb_hodotdc_tdc[j]) < 10000. ) {
	pmtL[j]->SetFillColor(4);
	pmtL[j]->Draw("same");
      }
      if(fabs(bb_hodotdc_tdc[j+90]) < 10000. ) {
	pmtR[j]->SetFillColor(4);
	pmtR[j]->Draw("same");
      }
    }

    // use TimingHodoscope variables for bar display (red if a "good" hit)
    for(int j=0; j<(Int_t)Ndata_bb_hodotdc_tdcbarid; j++) {
      bar[(Int_t)bb_hodotdc_tdcbarid[j]]->SetFillColor(2);
      bar[(Int_t)bb_hodotdc_tdcbarid[j]]->Draw("same") ;

      // draw hitpos if it is between -0.3 and 0.3 m
      if ( fabs(bb_hodotdc_bartimehitpos[(Int_t)Ndata_bb_hodotdc_bartimehitpos]) < 0.3 ) {
	cout << bb_hodotdc_bartimehitpos[(Int_t)Ndata_bb_hodotdc_bartimehitpos] << endl;
	hit[j]->SetX(0.5+bb_hodotdc_bartimehitpos[(Int_t)Ndata_bb_hodotdc_bartimehitpos]);
	hit[j]->SetY(ymin+height/2. + (Int_t)bb_hodotdc_tdcbarid[j]*separation);
	hit[j]->Draw("same");
      }
    }
    
    // wait for user command line input before displaying next event
    do {
      c1->Update();
      gSystem->ProcessEvents();
      cout << '\n' << "Press a key to continue...";
    } while (cin.get() != '\n');
  }

}
