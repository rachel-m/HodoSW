#include <TROOT.h>

#include <TGraph.h>
#include <TGraphErrors.h>

#include <iostream>
#include <fstream>

#include <TMath.h>

#include <TH1.h>
#include <TH1D.h>
#include <TH2.h>
#include <TF1.h>
#include <TF2.h>

#include <TFile.h>
#include <TTree.h>
#include <TChain.h>

#include <TCanvas.h>
#include <TLegend.h>

#include <TSystem.h>

#include <TCut.h>

#include <TTreeReader.h>
#include <TTreeReaderArray.h>

#include "GEnTree.C"

using namespace std;

double GetRF(double rftime, double time0, const double bunch = 4.008){
  double time1 = fmod(rftime-time0,bunch);
  double time2 = fmod(time1+bunch,bunch);
  return time2;
}

void RFSearch(){

  TChain *C = new TChain("T");
  C->Add("/w/work5/home/garyp/sbs/rootfiles/GEn/hodocalib/GEMcalib/*.root");
  //C->Add("/w/work5/home/garyp/sbs/rootfiles/GEn/hodocalib/GEMcalib/e1209016_fullreplay_2008_stream0_2_seg0_0.root");
  //GEnTree *T = new GEnTree(C);
  
  Long64_t nev = C->GetEntries();
  
  TTreeReader rd (C);
  
  int nbins = 100;
  
  double rfLO = 20.;
  double rfHI = 36.;

  double modLO = 0.;
  double modHI = 4.0;
  
  //rf versus variables
  TH2D *hRF_tdiff = new TH2D("hRF_tdiff","",
			     nbins,rfLO,rfHI,
			     nbins,modLO,modHI);

  TH2D *hRF_tmean = new TH2D("hRF_tmean","",
			     nbins,rfLO,rfHI,
			     nbins,modLO,modHI);

  TH2D *hRF_tmeanc = new TH2D("hRF_tmeanc","",
			      nbins,rfLO,rfHI,
			      nbins,modLO,modHI);
  
  TH2D *hRF_gr = new TH2D("hRF_gr","",
			  nbins,rfLO,rfHI,
			  nbins,modLO,modHI);
  
  TH2D *hRF_ps = new TH2D("hRF_ps","",
			  nbins,rfLO,rfHI,
			  nbins,modLO,modHI);
  
  TH2D *hRF_sh = new TH2D("hRF_sh","",
			  nbins,rfLO,rfHI,
			  nbins,modLO,modHI);
  
  //rf versus variables minus hodo
  TH2D *hRF_gr_hodo = new TH2D("hRF_gr_hodo","",
			       nbins,rfLO,rfHI,
			       nbins,modLO,modHI);
  
  TH2D *hRF_ps_hodo = new TH2D("hRF_ps_hodo","",
			       nbins,rfLO,rfHI,
			       nbins,modLO,modHI);
  
  TH2D *hRF_sh_hodo = new TH2D("hRF_sh_hodo","",
			       nbins,rfLO,rfHI,
			       nbins,modLO,modHI);
  
  
  //hodo tmean vs variables
  TH2D *htmean_gr = new TH2D("htmean_gr","",
				  nbins,-1,-1,
				  nbins,-1,-1);

  TH2D *htmean_ps = new TH2D("htmean_ps","",
			     nbins,-1,-1,
			     nbins,-1,-1);
  
  TH2D *htmean_sh = new TH2D("htmean_sh","",
			     nbins,-1,-1,
			     nbins,-1,-1);
  
  
  //test 
  TH2D *hRF_hodomult = new TH2D("hRF_hodomult","",
			       100,rfLO,rfHI,
			       100,modLO,modHI);
  
  TH2D *hSH_GR_Trig = new TH2D("hSH_GR_Trig","",
			       100,-1,-1,
			       100,-1,-1);
  
  TH2D *hRF_SH_Hodo_Trig = new TH2D("hRF_SH_Hodo_Trig","",
				    100,-1,-1,
				    100,-1,-1);

  TH2D *hRF_GR_Hodo_Trig = new TH2D("hRF_GR_Hodo_Trig","",
				    100,-1,-1,
				    100,-1,-1);

  
  //hodo clus
  TTreeReaderArray<double> bb_hodotdc_clus_tmean(rd,"bb.hodotdc.clus.tmean");
  //hodo clus_bar
  TTreeReaderArray<double> bb_hodotdc_clus_bar_tdc_meantime{rd,"bb.hodotdc.clus.bar.tdc.meantime"};
  TTreeReaderArray<double> bb_hodotdc_clus_bar_tdc_timediff{rd,"bb.hodotdc.clus.bar.tdc.timediff"};
  
  //grinch_clus
  TTreeReaderArray<double> bb_grinch_tdc_clus_t_mean{rd,"bb.grinch_tdc.clus.t_mean"};
  TTreeReaderValue<double> bb_grinch_tdc_clus_size{rd,"bb.grinch_tdc.clus.size"};
  TTreeReaderValue<double> bb_grinch_tdc_clus_trackindex{rd,"bb.grinch_tdc.clus.trackindex"};
  
  //grinch_hit
  TTreeReaderArray<double> bb_grinch_tdc_hit_time(rd,"bb.grinch_tdc.hit.time");
  
  //tdctrig
  TTreeReaderArray<double> bb_tdctrig_tdcelemID{rd,"bb.tdctrig.tdcelemID"};
  TTreeReaderArray<double> bb_tdctrig_tdc{rd,"bb.tdctrig.tdc"};
  
  //track
  TTreeReaderValue<double> bb_tr_n{rd,"bb.tr.n"};
  TTreeReaderArray<double> bb_tr_p{rd,"bb.tr.p"};

  //
  TTreeReaderArray<double> bb_ps_clus_atime{rd,"bb.ps.clus.atime"};
  TTreeReaderValue<double> bb_ps_e{rd,"bb.ps.e"};
  
  TTreeReaderArray<double> bb_sh_clus_atime{rd,"bb.sh.clus.atime"};
  TTreeReaderValue<double> bb_sh_e{rd,"bb.ps.e"};
  
  TTreeReaderValue<double> bb_sh_atimeblk(rd,"bb.sh.atimeblk");
  
 
  int badRF = 0;
  int badTRIG = 0;
  int multiclus = 0;
  double bunch_space = 4.008;
  for (Long64_t ev=0; ev<nev; ev++){
    
    rd.SetEntry(ev);
    if(ev%100000==0) cout << ev << " / " << nev << endl;
    
    if (*bb_tr_n <= 0.) continue;
    if (*bb_ps_e / bb_tr_p[0] < 0.1) continue;
    
    //if (*bb_grinch_tdc_clus_size <= 0.) continue;
    //if (*bb_grinch_tdc_clus_trackindex == -1.) continue;
    
    //if (bb_grinch_tdc_clus_t_tmean.GetSize() == 0) continue;
    //if (bb_hodotdc_clus_bar_tdc_meantime.GetSize() == 0) continue;
    
    int Ntdctrig = bb_tdctrig_tdcelemID.GetSize();
    
    bool haveRF=false;
    bool haveTRIG=false;
    
    double rftime=0.;
    double trigtime=0.;
    double tdctrig=0.;
    
    for (int ihit=0; ihit<Ntdctrig; ihit++){
      tdctrig = bb_tdctrig_tdcelemID[ihit];
      if (tdctrig == 4.){
	haveRF=true;
	rftime = bb_tdctrig_tdc[ihit];
      }
      if (tdctrig == 5.){
	haveTRIG=true;
	trigtime = bb_tdctrig_tdc[ihit];
      }
    }
    
    if(!haveRF){
      badRF++;
      //continue;
    }

    if(!haveTRIG){
      badTRIG++;
      //continue;
    }

    if(!haveRF || !haveTRIG) continue;
    
    //cluster level
    double hodotm = bb_hodotdc_clus_bar_tdc_meantime[0];
    double hodotd = bb_hodotdc_clus_bar_tdc_timediff[0];
    double grinchtm = bb_grinch_tdc_clus_t_mean[0];
    double ps_time = bb_ps_clus_atime[0];
    double sh_time = bb_sh_clus_atime[0];

    //raw hits 
    double sh_atime = *bb_sh_atimeblk;
    
    double hodotm_rf = GetRF(rftime, hodotm);
    double hodotd_rf = GetRF(rftime, hodotd);
    double grinchtm_rf = GetRF(rftime, grinchtm);
    double ps_time_rf = GetRF(rftime, ps_time);
    double sh_time_rf = GetRF(rftime, sh_time);
    
    int Grinch_hits = bb_grinch_tdc_hit_time.GetSize();
    for(int ihit=0; ihit<Grinch_hits; ihit++){
      //if(bb_grinch_tdc_hit_trackindex[ihit] != 0) continue;
      double gr_time = bb_grinch_tdc_hit_time[ihit];
      hSH_GR_Trig->Fill(sh_atime - hodotm - trigtime, gr_time - hodotm - trigtime);
      if(bb_hodotdc_clus_bar_tdc_meantime.GetSize() > 1){
	double hodotmc = bb_hodotdc_clus_bar_tdc_meantime[0] - bb_hodotdc_clus_bar_tdc_meantime[1];
	double hodotmc_rf = GetRF(rftime, hodotmc);
	hRF_GR_Hodo_Trig->Fill(gr_time - hodotm - trigtime, hodotmc_rf);
      }
    }
    
    if(bb_hodotdc_clus_bar_tdc_meantime.GetSize() > 1){
      double hodotmc = bb_hodotdc_clus_bar_tdc_meantime[0] - bb_hodotdc_clus_bar_tdc_meantime[1];
      double hodotmc_rf = GetRF(rftime, hodotmc);
      hRF_tmeanc->Fill(rftime, hodotmc_rf);
      hRF_tmeanc->Fill(rftime, hodotmc_rf);
      hRF_SH_Hodo_Trig->Fill(sh_atime - hodotm - trigtime, hodotmc_rf);
      //keep in mind the above line is sh_blk_atime not just sh_time
    }
    
    double hodoclusdiff;
    if(bb_hodotdc_clus_tmean.GetSize() > 1){
      multiclus++;
      hodoclusdiff = bb_hodotdc_clus_tmean[0] - bb_hodotdc_clus_tmean[1];
      hodoclusdiff = fmod(rftime-hodoclusdiff,bunch_space);
      hodoclusdiff = fmod(hodoclusdiff+bunch_space,bunch_space);
      hRF_hodomult->Fill(rftime,hodoclusdiff);
    }
    
    hRF_tmean->Fill(rftime, hodotm_rf);
    hRF_tdiff->Fill(rftime, hodotd_rf);
   
    hRF_gr->Fill(rftime,grinchtm_rf);
    hRF_ps->Fill(rftime,ps_time_rf);
    hRF_sh->Fill(rftime,sh_time_rf);
	
    double gr_hodo_rf = GetRF(rftime, grinchtm - hodotm);
    double ps_hodo_rf = GetRF(rftime, ps_time - hodotm);
    double sh_hodo_rf = GetRF(rftime, sh_time - hodotm);
    
    hRF_gr_hodo->Fill(rftime, gr_hodo_rf);
    hRF_ps_hodo->Fill(rftime, ps_hodo_rf);
    hRF_sh_hodo->Fill(rftime, sh_hodo_rf);
	
    htmean_ps->Fill(ps_time,hodotm);
    htmean_sh->Fill(sh_time,hodotm);
    htmean_gr->Fill(grinchtm,hodotm);
    
    
  }
  
  cout << "Events missing tdctrig 4: " << badRF << endl;
  cout << "Events missing tdctrig 5: " << badTRIG << endl;
  cout << "Hodoscope multi cluster events: " << multiclus << endl;

  /*
  TCanvas *c1 = new TCanvas("c1","",1920,1080);
  c1->Divide(3,2);
  c1->cd(1);
  hRF_tmean->GetXaxis()->SetTitle("RF Time (tdc trig 4)");
  hRF_tmean->GetYaxis()->SetTitle("fmod(RF Time - Hodoscope tmean, 4008) [ns]");
  hRF_tmean->Draw("colz");
  c1->cd(2);
  hRF_tdiff->GetXaxis()->SetTitle("RF Time (tdc trig 4)");
  hRF_tdiff->GetYaxis()->SetTitle("fmod(RF Time - Hodoscope tdiff, 4.008) [ns]");
  hRF_tdiff->Draw("colz");
  c1->cd(3);
  hRF_tmeanc->GetXaxis()->SetTitle("RF Time (tdc trig 4)");
  hRF_tmeanc->GetYaxis()->SetTitle("fmod(RF Time - Hodoscope tmean bar1 - bar2, 4.008) [ns]");
  hRF_tmeanc->Draw("colz");
  c1->cd(4);
  hRF_ps->GetXaxis()->SetTitle("RF Time (tdc trig 4)");
  hRF_ps->GetYaxis()->SetTitle("fmod(RF Time - Preshower ADC Time, 4.008) [ns]");
  hRF_ps->Draw("colz");
  c1->cd(5);
  hRF_sh->GetXaxis()->SetTitle("RF Time (tdc trig 4)");
  hRF_sh->GetYaxis()->SetTitle("fmod(RF Time - Shower ADC Time, 4.008) [ns]");
  hRF_sh->Draw("colz");
  c1->cd(6);
  hRF_gr->GetXaxis()->SetTitle("RF Time (tdc trig 4)");
  hRF_gr->GetYaxis()->SetTitle("fmod(RF Time - Grinch tmean, 4.008) [ns]");
  hRF_gr->Draw("colz");
  c1->Print("RF_2D.png");
  c1->Close();
  
  TCanvas *c2 = new TCanvas("c2","",1920,1080);
  c2->Divide(3,2);
  c2->cd(1);
  htmean_ps->GetXaxis()->SetTitle("Preshower ADC Time [ns]");
  htmean_ps->GetYaxis()->SetTitle("Hodoscope tmean [ns]");
  htmean_ps->Draw("colz");
  c2->cd(2);
  htmean_sh->GetXaxis()->SetTitle("Shower ADC Time [ns]");
  htmean_sh->GetYaxis()->SetTitle("Hodoscope tmean [ns]");
  htmean_sh->Draw("colz");
  c2->cd(3);
  htmean_gr->GetXaxis()->SetTitle("Grinch tmean [ns]");
  htmean_gr->GetYaxis()->SetTitle("Hodoscope tmean [ns]");
  htmean_gr->Draw("colz");
  c2->cd(4);
  hRF_ps_hodo->GetXaxis()->SetTitle("RF Time (tdc trig 4)");
  hRF_ps_hodo->GetYaxis()->SetTitle("Preshower ADC Time - Hodo tmean [ns]");
  hRF_ps_hodo->Draw("colz");
  c2->cd(5);
  hRF_sh_hodo->GetXaxis()->SetTitle("RF Time (tdc trig 4)");
  hRF_sh_hodo->GetYaxis()->SetTitle("Shower ADC Time - Hodo tmean [ns]");
  hRF_sh_hodo->Draw("colz");
  c2->cd(6);
  hRF_gr_hodo->GetXaxis()->SetTitle("RF Time (tdc trig 4)");
  hRF_gr_hodo->GetYaxis()->SetTitle("Grinch tmean - Hodo tmean");
  hRF_gr_hodo->Draw("colz");
  c2->Print("Hodo_RF_2D.png");
  c2->Close();
  */

  hRF_hodomult->GetXaxis()->SetTitle("RF Time (tdc trig 4)");
  hRF_hodomult->GetYaxis()->SetTitle("fmod(RF Time - Hodoscope tmean clus1 - clus2, 4.008) [ns]");
  hRF_hodomult->Draw("colz");
  
  TCanvas *c3 = new TCanvas("c3","",1920,1080);
  c3->Divide(2,2);
  c3->cd(1);
  hRF_tmeanc->GetXaxis()->SetTitle("RF Time (tdc trig 4)");
  hRF_tmeanc->GetYaxis()->SetTitle("fmod(RF Time - Hodoscope tmean bar1 - bar2, 4.008) [ns]");
  hRF_tmeanc->Draw("colz");
  
  c3->cd(2);
  hSH_GR_Trig->GetXaxis()->SetTitle("sh blk time - hodo clus tmean - trigger [ns]");
  hSH_GR_Trig->GetYaxis()->SetTitle("grinch hit time - hodo clus tmean - trigger [ns]");
  hSH_GR_Trig->Draw("colz");
  
  c3->cd(3);
  hRF_SH_Hodo_Trig->GetXaxis()->SetTitle("sh blk time - hodo clus tmean - trigger [ns]");
  hRF_SH_Hodo_Trig->GetYaxis()->SetTitle("fmod(RF Time - Hodoscope tmean bar1 - bar2, 4.008) [ns]");
  hRF_SH_Hodo_Trig->Draw("colz");
  
  c3->cd(4);
  hRF_GR_Hodo_Trig->GetXaxis()->SetTitle("grinch hit time - hodo clus tmean - trigger [ns]");
  hRF_GR_Hodo_Trig->GetYaxis()->SetTitle("fmod(RF Time - Hodoscope tmean bar1 - bar2, 4.008) [ns]");
  hRF_GR_Hodo_Trig->Draw("colz");
  //c3->Close();
}
