//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Sep  7 14:32:18 2022 by ROOT version 6.22/06
// from TTree T/Hall A Analyzer Output DST
// found on file: /volatile/halla/sbs/gpenman/Rootfiles/e1209019_bbhodo_11590_50000.root
//////////////////////////////////////////////////////////

#ifndef SBSTree_h
#define SBSTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class SBSTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           Ndata_bb_hodoadc_Ref_a;
   Double_t        bb_hodoadc_Ref_a[1];   //[Ndata.bb.hodoadc.Ref.a]
   Int_t           Ndata_bb_hodoadc_Ref_a_amp;
   Double_t        bb_hodoadc_Ref_a_amp[1];   //[Ndata.bb.hodoadc.Ref.a_amp]
   Int_t           Ndata_bb_hodoadc_Ref_a_amp_c;
   Double_t        bb_hodoadc_Ref_a_amp_c[1];   //[Ndata.bb.hodoadc.Ref.a_amp_c]
   Int_t           Ndata_bb_hodoadc_Ref_a_amp_p;
   Double_t        bb_hodoadc_Ref_a_amp_p[1];   //[Ndata.bb.hodoadc.Ref.a_amp_p]
   Int_t           Ndata_bb_hodoadc_Ref_a_c;
   Double_t        bb_hodoadc_Ref_a_c[1];   //[Ndata.bb.hodoadc.Ref.a_c]
   Int_t           Ndata_bb_hodoadc_Ref_a_mult;
   Double_t        bb_hodoadc_Ref_a_mult[1];   //[Ndata.bb.hodoadc.Ref.a_mult]
   Int_t           Ndata_bb_hodoadc_Ref_a_p;
   Double_t        bb_hodoadc_Ref_a_p[1];   //[Ndata.bb.hodoadc.Ref.a_p]
   Int_t           Ndata_bb_hodoadc_Ref_a_time;
   Double_t        bb_hodoadc_Ref_a_time[1];   //[Ndata.bb.hodoadc.Ref.a_time]
   Int_t           Ndata_bb_hodoadc_Ref_adcelemID;
   Double_t        bb_hodoadc_Ref_adcelemID[1];   //[Ndata.bb.hodoadc.Ref.adcelemID]
   Int_t           Ndata_bb_hodoadc_Ref_ped;
   Double_t        bb_hodoadc_Ref_ped[1];   //[Ndata.bb.hodoadc.Ref.ped]
   Int_t           Ndata_bb_hodoadc_a;
   Double_t        bb_hodoadc_a[40];   //[Ndata.bb.hodoadc.a]
   Int_t           Ndata_bb_hodoadc_a_amp;
   Double_t        bb_hodoadc_a_amp[40];   //[Ndata.bb.hodoadc.a_amp]
   Int_t           Ndata_bb_hodoadc_a_amp_c;
   Double_t        bb_hodoadc_a_amp_c[40];   //[Ndata.bb.hodoadc.a_amp_c]
   Int_t           Ndata_bb_hodoadc_a_amp_p;
   Double_t        bb_hodoadc_a_amp_p[40];   //[Ndata.bb.hodoadc.a_amp_p]
   Int_t           Ndata_bb_hodoadc_a_amptrig_c;
   Double_t        bb_hodoadc_a_amptrig_c[40];   //[Ndata.bb.hodoadc.a_amptrig_c]
   Int_t           Ndata_bb_hodoadc_a_amptrig_p;
   Double_t        bb_hodoadc_a_amptrig_p[40];   //[Ndata.bb.hodoadc.a_amptrig_p]
   Int_t           Ndata_bb_hodoadc_a_c;
   Double_t        bb_hodoadc_a_c[40];   //[Ndata.bb.hodoadc.a_c]
   Int_t           Ndata_bb_hodoadc_a_mult;
   Double_t        bb_hodoadc_a_mult[40];   //[Ndata.bb.hodoadc.a_mult]
   Int_t           Ndata_bb_hodoadc_a_p;
   Double_t        bb_hodoadc_a_p[40];   //[Ndata.bb.hodoadc.a_p]
   Int_t           Ndata_bb_hodoadc_a_time;
   Double_t        bb_hodoadc_a_time[40];   //[Ndata.bb.hodoadc.a_time]
   Int_t           Ndata_bb_hodoadc_adccol;
   Double_t        bb_hodoadc_adccol[40];   //[Ndata.bb.hodoadc.adccol]
   Int_t           Ndata_bb_hodoadc_adcelemID;
   Double_t        bb_hodoadc_adcelemID[40];   //[Ndata.bb.hodoadc.adcelemID]
   Int_t           Ndata_bb_hodoadc_adclayer;
   Double_t        bb_hodoadc_adclayer[40];   //[Ndata.bb.hodoadc.adclayer]
   Int_t           Ndata_bb_hodoadc_adcrow;
   Double_t        bb_hodoadc_adcrow[40];   //[Ndata.bb.hodoadc.adcrow]
   Int_t           Ndata_bb_hodoadc_allclus_id;
   Double_t        bb_hodoadc_allclus_id[1];   //[Ndata.bb.hodoadc.allclus.id]
   Int_t           Ndata_bb_hodoadc_allclus_itrack;
   Double_t        bb_hodoadc_allclus_itrack[1];   //[Ndata.bb.hodoadc.allclus.itrack]
   Int_t           Ndata_bb_hodoadc_allclus_size;
   Double_t        bb_hodoadc_allclus_size[1];   //[Ndata.bb.hodoadc.allclus.size]
   Int_t           Ndata_bb_hodoadc_allclus_tdiff;
   Double_t        bb_hodoadc_allclus_tdiff[1];   //[Ndata.bb.hodoadc.allclus.tdiff]
   Int_t           Ndata_bb_hodoadc_allclus_tmean;
   Double_t        bb_hodoadc_allclus_tmean[1];   //[Ndata.bb.hodoadc.allclus.tmean]
   Int_t           Ndata_bb_hodoadc_allclus_totmean;
   Double_t        bb_hodoadc_allclus_totmean[1];   //[Ndata.bb.hodoadc.allclus.totmean]
   Int_t           Ndata_bb_hodoadc_allclus_xmean;
   Double_t        bb_hodoadc_allclus_xmean[1];   //[Ndata.bb.hodoadc.allclus.xmean]
   Int_t           Ndata_bb_hodoadc_allclus_ymean;
   Double_t        bb_hodoadc_allclus_ymean[1];   //[Ndata.bb.hodoadc.allclus.ymean]
   Int_t           Ndata_bb_hodoadc_bar_adc_L_a;
   Double_t        bb_hodoadc_bar_adc_L_a[20];   //[Ndata.bb.hodoadc.bar.adc.L.a]
   Int_t           Ndata_bb_hodoadc_bar_adc_L_ac;
   Double_t        bb_hodoadc_bar_adc_L_ac[20];   //[Ndata.bb.hodoadc.bar.adc.L.ac]
   Int_t           Ndata_bb_hodoadc_bar_adc_L_ap;
   Double_t        bb_hodoadc_bar_adc_L_ap[20];   //[Ndata.bb.hodoadc.bar.adc.L.ap]
   Int_t           Ndata_bb_hodoadc_bar_adc_R_a;
   Double_t        bb_hodoadc_bar_adc_R_a[20];   //[Ndata.bb.hodoadc.bar.adc.R.a]
   Int_t           Ndata_bb_hodoadc_bar_adc_R_ac;
   Double_t        bb_hodoadc_bar_adc_R_ac[20];   //[Ndata.bb.hodoadc.bar.adc.R.ac]
   Int_t           Ndata_bb_hodoadc_bar_adc_R_ap;
   Double_t        bb_hodoadc_bar_adc_R_ap[20];   //[Ndata.bb.hodoadc.bar.adc.R.ap]
   Int_t           Ndata_bb_hodoadc_bar_adc_id;
   Double_t        bb_hodoadc_bar_adc_id[20];   //[Ndata.bb.hodoadc.bar.adc.id]
   Int_t           Ndata_bb_hodoadc_bar_adc_mean;
   Double_t        bb_hodoadc_bar_adc_mean[20];   //[Ndata.bb.hodoadc.bar.adc.mean]
   Int_t           Ndata_bb_hodoadc_clus_bar_tdc_id;
   Double_t        bb_hodoadc_clus_bar_tdc_id[1];   //[Ndata.bb.hodoadc.clus.bar.tdc.id]
   Int_t           Ndata_bb_hodoadc_clus_bar_tdc_itrack;
   Double_t        bb_hodoadc_clus_bar_tdc_itrack[1];   //[Ndata.bb.hodoadc.clus.bar.tdc.itrack]
   Int_t           Ndata_bb_hodoadc_clus_bar_tdc_meantime;
   Double_t        bb_hodoadc_clus_bar_tdc_meantime[1];   //[Ndata.bb.hodoadc.clus.bar.tdc.meantime]
   Int_t           Ndata_bb_hodoadc_clus_bar_tdc_meantot;
   Double_t        bb_hodoadc_clus_bar_tdc_meantot[1];   //[Ndata.bb.hodoadc.clus.bar.tdc.meantot]
   Int_t           Ndata_bb_hodoadc_clus_bar_tdc_timediff;
   Double_t        bb_hodoadc_clus_bar_tdc_timediff[1];   //[Ndata.bb.hodoadc.clus.bar.tdc.timediff]
   Int_t           Ndata_bb_hodoadc_clus_bar_tdc_timehitpos;
   Double_t        bb_hodoadc_clus_bar_tdc_timehitpos[1];   //[Ndata.bb.hodoadc.clus.bar.tdc.timehitpos]
   Int_t           Ndata_bb_hodoadc_clus_bar_tdc_vpos;
   Double_t        bb_hodoadc_clus_bar_tdc_vpos[1];   //[Ndata.bb.hodoadc.clus.bar.tdc.vpos]
   Int_t           Ndata_bb_hodoadc_clus_id;
   Double_t        bb_hodoadc_clus_id[1];   //[Ndata.bb.hodoadc.clus.id]
   Int_t           Ndata_bb_hodoadc_clus_size;
   Double_t        bb_hodoadc_clus_size[1];   //[Ndata.bb.hodoadc.clus.size]
   Int_t           Ndata_bb_hodoadc_clus_tdiff;
   Double_t        bb_hodoadc_clus_tdiff[1];   //[Ndata.bb.hodoadc.clus.tdiff]
   Int_t           Ndata_bb_hodoadc_clus_tmean;
   Double_t        bb_hodoadc_clus_tmean[1];   //[Ndata.bb.hodoadc.clus.tmean]
   Int_t           Ndata_bb_hodoadc_clus_totmean;
   Double_t        bb_hodoadc_clus_totmean[1];   //[Ndata.bb.hodoadc.clus.totmean]
   Int_t           Ndata_bb_hodoadc_clus_trackindex;
   Double_t        bb_hodoadc_clus_trackindex[1];   //[Ndata.bb.hodoadc.clus.trackindex]
   Int_t           Ndata_bb_hodoadc_clus_xmean;
   Double_t        bb_hodoadc_clus_xmean[1];   //[Ndata.bb.hodoadc.clus.xmean]
   Int_t           Ndata_bb_hodoadc_clus_ymean;
   Double_t        bb_hodoadc_clus_ymean[1];   //[Ndata.bb.hodoadc.clus.ymean]
   Int_t           Ndata_bb_hodoadc_ped;
   Double_t        bb_hodoadc_ped[40];   //[Ndata.bb.hodoadc.ped]
   Int_t           Ndata_bb_hodotdc_Ref_tdc;
   Double_t        bb_hodotdc_Ref_tdc[2];   //[Ndata.bb.hodotdc.Ref.tdc]
   Int_t           Ndata_bb_hodotdc_Ref_tdc_mult;
   Double_t        bb_hodotdc_Ref_tdc_mult[2];   //[Ndata.bb.hodotdc.Ref.tdc_mult]
   Int_t           Ndata_bb_hodotdc_Ref_tdc_te;
   Double_t        bb_hodotdc_Ref_tdc_te[2];   //[Ndata.bb.hodotdc.Ref.tdc_te]
   Int_t           Ndata_bb_hodotdc_Ref_tdc_tot;
   Double_t        bb_hodotdc_Ref_tdc_tot[2];   //[Ndata.bb.hodotdc.Ref.tdc_tot]
   Int_t           Ndata_bb_hodotdc_Ref_tdcelemID;
   Double_t        bb_hodotdc_Ref_tdcelemID[2];   //[Ndata.bb.hodotdc.Ref.tdcelemID]
   Int_t           Ndata_bb_hodotdc_allclus_id;
   Double_t        bb_hodotdc_allclus_id[9];   //[Ndata.bb.hodotdc.allclus.id]
   Int_t           Ndata_bb_hodotdc_allclus_itrack;
   Double_t        bb_hodotdc_allclus_itrack[9];   //[Ndata.bb.hodotdc.allclus.itrack]
   Int_t           Ndata_bb_hodotdc_allclus_size;
   Double_t        bb_hodotdc_allclus_size[9];   //[Ndata.bb.hodotdc.allclus.size]
   Int_t           Ndata_bb_hodotdc_allclus_tdiff;
   Double_t        bb_hodotdc_allclus_tdiff[9];   //[Ndata.bb.hodotdc.allclus.tdiff]
   Int_t           Ndata_bb_hodotdc_allclus_tmean;
   Double_t        bb_hodotdc_allclus_tmean[9];   //[Ndata.bb.hodotdc.allclus.tmean]
   Int_t           Ndata_bb_hodotdc_allclus_totmean;
   Double_t        bb_hodotdc_allclus_totmean[9];   //[Ndata.bb.hodotdc.allclus.totmean]
   Int_t           Ndata_bb_hodotdc_allclus_xmean;
   Double_t        bb_hodotdc_allclus_xmean[9];   //[Ndata.bb.hodotdc.allclus.xmean]
   Int_t           Ndata_bb_hodotdc_allclus_ymean;
   Double_t        bb_hodotdc_allclus_ymean[9];   //[Ndata.bb.hodotdc.allclus.ymean]
   Int_t           Ndata_bb_hodotdc_bar_tdc_L_le;
   Double_t        bb_hodotdc_bar_tdc_L_le[15];   //[Ndata.bb.hodotdc.bar.tdc.L.le]
   Int_t           Ndata_bb_hodotdc_bar_tdc_L_leW;
   Double_t        bb_hodotdc_bar_tdc_L_leW[15];   //[Ndata.bb.hodotdc.bar.tdc.L.leW]
   Int_t           Ndata_bb_hodotdc_bar_tdc_L_te;
   Double_t        bb_hodotdc_bar_tdc_L_te[15];   //[Ndata.bb.hodotdc.bar.tdc.L.te]
   Int_t           Ndata_bb_hodotdc_bar_tdc_L_teW;
   Double_t        bb_hodotdc_bar_tdc_L_teW[15];   //[Ndata.bb.hodotdc.bar.tdc.L.teW]
   Int_t           Ndata_bb_hodotdc_bar_tdc_L_tot;
   Double_t        bb_hodotdc_bar_tdc_L_tot[15];   //[Ndata.bb.hodotdc.bar.tdc.L.tot]
   Int_t           Ndata_bb_hodotdc_bar_tdc_L_totW;
   Double_t        bb_hodotdc_bar_tdc_L_totW[15];   //[Ndata.bb.hodotdc.bar.tdc.L.totW]
   Int_t           Ndata_bb_hodotdc_bar_tdc_R_le;
   Double_t        bb_hodotdc_bar_tdc_R_le[15];   //[Ndata.bb.hodotdc.bar.tdc.R.le]
   Int_t           Ndata_bb_hodotdc_bar_tdc_R_leW;
   Double_t        bb_hodotdc_bar_tdc_R_leW[15];   //[Ndata.bb.hodotdc.bar.tdc.R.leW]
   Int_t           Ndata_bb_hodotdc_bar_tdc_R_te;
   Double_t        bb_hodotdc_bar_tdc_R_te[15];   //[Ndata.bb.hodotdc.bar.tdc.R.te]
   Int_t           Ndata_bb_hodotdc_bar_tdc_R_teW;
   Double_t        bb_hodotdc_bar_tdc_R_teW[15];   //[Ndata.bb.hodotdc.bar.tdc.R.teW]
   Int_t           Ndata_bb_hodotdc_bar_tdc_R_tot;
   Double_t        bb_hodotdc_bar_tdc_R_tot[15];   //[Ndata.bb.hodotdc.bar.tdc.R.tot]
   Int_t           Ndata_bb_hodotdc_bar_tdc_R_totW;
   Double_t        bb_hodotdc_bar_tdc_R_totW[15];   //[Ndata.bb.hodotdc.bar.tdc.R.totW]
   Int_t           Ndata_bb_hodotdc_bar_tdc_id;
   Double_t        bb_hodotdc_bar_tdc_id[15];   //[Ndata.bb.hodotdc.bar.tdc.id]
   Int_t           Ndata_bb_hodotdc_bar_tdc_meantime;
   Double_t        bb_hodotdc_bar_tdc_meantime[15];   //[Ndata.bb.hodotdc.bar.tdc.meantime]
   Int_t           Ndata_bb_hodotdc_bar_tdc_timediff;
   Double_t        bb_hodotdc_bar_tdc_timediff[15];   //[Ndata.bb.hodotdc.bar.tdc.timediff]
   Int_t           Ndata_bb_hodotdc_bar_tdc_timehitpos;
   Double_t        bb_hodotdc_bar_tdc_timehitpos[15];   //[Ndata.bb.hodotdc.bar.tdc.timehitpos]
   Int_t           Ndata_bb_hodotdc_bar_tdc_vpos;
   Double_t        bb_hodotdc_bar_tdc_vpos[15];   //[Ndata.bb.hodotdc.bar.tdc.vpos]
   Int_t           Ndata_bb_hodotdc_clus_bar_tdc_id;
   Double_t        bb_hodotdc_clus_bar_tdc_id[1];   //[Ndata.bb.hodotdc.clus.bar.tdc.id]
   Int_t           Ndata_bb_hodotdc_clus_bar_tdc_itrack;
   Double_t        bb_hodotdc_clus_bar_tdc_itrack[1];   //[Ndata.bb.hodotdc.clus.bar.tdc.itrack]
   Int_t           Ndata_bb_hodotdc_clus_bar_tdc_meantime;
   Double_t        bb_hodotdc_clus_bar_tdc_meantime[1];   //[Ndata.bb.hodotdc.clus.bar.tdc.meantime]
   Int_t           Ndata_bb_hodotdc_clus_bar_tdc_meantot;
   Double_t        bb_hodotdc_clus_bar_tdc_meantot[1];   //[Ndata.bb.hodotdc.clus.bar.tdc.meantot]
   Int_t           Ndata_bb_hodotdc_clus_bar_tdc_timediff;
   Double_t        bb_hodotdc_clus_bar_tdc_timediff[1];   //[Ndata.bb.hodotdc.clus.bar.tdc.timediff]
   Int_t           Ndata_bb_hodotdc_clus_bar_tdc_timehitpos;
   Double_t        bb_hodotdc_clus_bar_tdc_timehitpos[1];   //[Ndata.bb.hodotdc.clus.bar.tdc.timehitpos]
   Int_t           Ndata_bb_hodotdc_clus_bar_tdc_vpos;
   Double_t        bb_hodotdc_clus_bar_tdc_vpos[1];   //[Ndata.bb.hodotdc.clus.bar.tdc.vpos]
   Int_t           Ndata_bb_hodotdc_clus_id;
   Double_t        bb_hodotdc_clus_id[1];   //[Ndata.bb.hodotdc.clus.id]
   Int_t           Ndata_bb_hodotdc_clus_size;
   Double_t        bb_hodotdc_clus_size[1];   //[Ndata.bb.hodotdc.clus.size]
   Int_t           Ndata_bb_hodotdc_clus_tdiff;
   Double_t        bb_hodotdc_clus_tdiff[1];   //[Ndata.bb.hodotdc.clus.tdiff]
   Int_t           Ndata_bb_hodotdc_clus_tmean;
   Double_t        bb_hodotdc_clus_tmean[1];   //[Ndata.bb.hodotdc.clus.tmean]
   Int_t           Ndata_bb_hodotdc_clus_totmean;
   Double_t        bb_hodotdc_clus_totmean[1];   //[Ndata.bb.hodotdc.clus.totmean]
   Int_t           Ndata_bb_hodotdc_clus_trackindex;
   Double_t        bb_hodotdc_clus_trackindex[1];   //[Ndata.bb.hodotdc.clus.trackindex]
   Int_t           Ndata_bb_hodotdc_clus_xmean;
   Double_t        bb_hodotdc_clus_xmean[1];   //[Ndata.bb.hodotdc.clus.xmean]
   Int_t           Ndata_bb_hodotdc_clus_ymean;
   Double_t        bb_hodotdc_clus_ymean[1];   //[Ndata.bb.hodotdc.clus.ymean]
   Int_t           Ndata_bb_hodotdc_tdc;
   Double_t        bb_hodotdc_tdc[180];   //[Ndata.bb.hodotdc.tdc]
   Int_t           Ndata_bb_hodotdc_tdc_mult;
   Double_t        bb_hodotdc_tdc_mult[180];   //[Ndata.bb.hodotdc.tdc_mult]
   Int_t           Ndata_bb_hodotdc_tdc_te;
   Double_t        bb_hodotdc_tdc_te[180];   //[Ndata.bb.hodotdc.tdc_te]
   Int_t           Ndata_bb_hodotdc_tdc_tot;
   Double_t        bb_hodotdc_tdc_tot[180];   //[Ndata.bb.hodotdc.tdc_tot]
   Int_t           Ndata_bb_hodotdc_tdccol;
   Double_t        bb_hodotdc_tdccol[180];   //[Ndata.bb.hodotdc.tdccol]
   Int_t           Ndata_bb_hodotdc_tdcelemID;
   Double_t        bb_hodotdc_tdcelemID[180];   //[Ndata.bb.hodotdc.tdcelemID]
   Int_t           Ndata_bb_hodotdc_tdclayer;
   Double_t        bb_hodotdc_tdclayer[180];   //[Ndata.bb.hodotdc.tdclayer]
   Int_t           Ndata_bb_hodotdc_tdcrow;
   Double_t        bb_hodotdc_tdcrow[180];   //[Ndata.bb.hodotdc.tdcrow]
   Double_t        bb_hodoadc_nclus;
   Double_t        bb_hodoadc_ngoodADChits;
   Double_t        bb_hodoadc_ngoodTDChits;
   Double_t        bb_hodoadc_nhits;
   Double_t        bb_hodoadc_nrefhits;
   Double_t        bb_hodotdc_bar_ngoodbars;
   Double_t        bb_hodotdc_nclus;
   Double_t        bb_hodotdc_ngoodADChits;
   Double_t        bb_hodotdc_ngoodTDChits;
   Double_t        bb_hodotdc_nhits;
   Double_t        bb_hodotdc_nrefhits;
 //THaEvent        *Event_Branch;
   ULong64_t       fEvtHdr_fEvtTime;
   UInt_t          fEvtHdr_fEvtNum;
   UInt_t          fEvtHdr_fEvtType;
   UInt_t          fEvtHdr_fEvtLen;
   Int_t           fEvtHdr_fHelicity;
   UInt_t          fEvtHdr_fTrigBits;
   UInt_t          fEvtHdr_fRun;

   // List of branches
   TBranch        *b_Ndata_bb_hodoadc_Ref_a;   //!
   TBranch        *b_bb_hodoadc_Ref_a;   //!
   TBranch        *b_Ndata_bb_hodoadc_Ref_a_amp;   //!
   TBranch        *b_bb_hodoadc_Ref_a_amp;   //!
   TBranch        *b_Ndata_bb_hodoadc_Ref_a_amp_c;   //!
   TBranch        *b_bb_hodoadc_Ref_a_amp_c;   //!
   TBranch        *b_Ndata_bb_hodoadc_Ref_a_amp_p;   //!
   TBranch        *b_bb_hodoadc_Ref_a_amp_p;   //!
   TBranch        *b_Ndata_bb_hodoadc_Ref_a_c;   //!
   TBranch        *b_bb_hodoadc_Ref_a_c;   //!
   TBranch        *b_Ndata_bb_hodoadc_Ref_a_mult;   //!
   TBranch        *b_bb_hodoadc_Ref_a_mult;   //!
   TBranch        *b_Ndata_bb_hodoadc_Ref_a_p;   //!
   TBranch        *b_bb_hodoadc_Ref_a_p;   //!
   TBranch        *b_Ndata_bb_hodoadc_Ref_a_time;   //!
   TBranch        *b_bb_hodoadc_Ref_a_time;   //!
   TBranch        *b_Ndata_bb_hodoadc_Ref_adcelemID;   //!
   TBranch        *b_bb_hodoadc_Ref_adcelemID;   //!
   TBranch        *b_Ndata_bb_hodoadc_Ref_ped;   //!
   TBranch        *b_bb_hodoadc_Ref_ped;   //!
   TBranch        *b_Ndata_bb_hodoadc_a;   //!
   TBranch        *b_bb_hodoadc_a;   //!
   TBranch        *b_Ndata_bb_hodoadc_a_amp;   //!
   TBranch        *b_bb_hodoadc_a_amp;   //!
   TBranch        *b_Ndata_bb_hodoadc_a_amp_c;   //!
   TBranch        *b_bb_hodoadc_a_amp_c;   //!
   TBranch        *b_Ndata_bb_hodoadc_a_amp_p;   //!
   TBranch        *b_bb_hodoadc_a_amp_p;   //!
   TBranch        *b_Ndata_bb_hodoadc_a_amptrig_c;   //!
   TBranch        *b_bb_hodoadc_a_amptrig_c;   //!
   TBranch        *b_Ndata_bb_hodoadc_a_amptrig_p;   //!
   TBranch        *b_bb_hodoadc_a_amptrig_p;   //!
   TBranch        *b_Ndata_bb_hodoadc_a_c;   //!
   TBranch        *b_bb_hodoadc_a_c;   //!
   TBranch        *b_Ndata_bb_hodoadc_a_mult;   //!
   TBranch        *b_bb_hodoadc_a_mult;   //!
   TBranch        *b_Ndata_bb_hodoadc_a_p;   //!
   TBranch        *b_bb_hodoadc_a_p;   //!
   TBranch        *b_Ndata_bb_hodoadc_a_time;   //!
   TBranch        *b_bb_hodoadc_a_time;   //!
   TBranch        *b_Ndata_bb_hodoadc_adccol;   //!
   TBranch        *b_bb_hodoadc_adccol;   //!
   TBranch        *b_Ndata_bb_hodoadc_adcelemID;   //!
   TBranch        *b_bb_hodoadc_adcelemID;   //!
   TBranch        *b_Ndata_bb_hodoadc_adclayer;   //!
   TBranch        *b_bb_hodoadc_adclayer;   //!
   TBranch        *b_Ndata_bb_hodoadc_adcrow;   //!
   TBranch        *b_bb_hodoadc_adcrow;   //!
   TBranch        *b_Ndata_bb_hodoadc_allclus_id;   //!
   TBranch        *b_bb_hodoadc_allclus_id;   //!
   TBranch        *b_Ndata_bb_hodoadc_allclus_itrack;   //!
   TBranch        *b_bb_hodoadc_allclus_itrack;   //!
   TBranch        *b_Ndata_bb_hodoadc_allclus_size;   //!
   TBranch        *b_bb_hodoadc_allclus_size;   //!
   TBranch        *b_Ndata_bb_hodoadc_allclus_tdiff;   //!
   TBranch        *b_bb_hodoadc_allclus_tdiff;   //!
   TBranch        *b_Ndata_bb_hodoadc_allclus_tmean;   //!
   TBranch        *b_bb_hodoadc_allclus_tmean;   //!
   TBranch        *b_Ndata_bb_hodoadc_allclus_totmean;   //!
   TBranch        *b_bb_hodoadc_allclus_totmean;   //!
   TBranch        *b_Ndata_bb_hodoadc_allclus_xmean;   //!
   TBranch        *b_bb_hodoadc_allclus_xmean;   //!
   TBranch        *b_Ndata_bb_hodoadc_allclus_ymean;   //!
   TBranch        *b_bb_hodoadc_allclus_ymean;   //!
   TBranch        *b_Ndata_bb_hodoadc_bar_adc_L_a;   //!
   TBranch        *b_bb_hodoadc_bar_adc_L_a;   //!
   TBranch        *b_Ndata_bb_hodoadc_bar_adc_L_ac;   //!
   TBranch        *b_bb_hodoadc_bar_adc_L_ac;   //!
   TBranch        *b_Ndata_bb_hodoadc_bar_adc_L_ap;   //!
   TBranch        *b_bb_hodoadc_bar_adc_L_ap;   //!
   TBranch        *b_Ndata_bb_hodoadc_bar_adc_R_a;   //!
   TBranch        *b_bb_hodoadc_bar_adc_R_a;   //!
   TBranch        *b_Ndata_bb_hodoadc_bar_adc_R_ac;   //!
   TBranch        *b_bb_hodoadc_bar_adc_R_ac;   //!
   TBranch        *b_Ndata_bb_hodoadc_bar_adc_R_ap;   //!
   TBranch        *b_bb_hodoadc_bar_adc_R_ap;   //!
   TBranch        *b_Ndata_bb_hodoadc_bar_adc_id;   //!
   TBranch        *b_bb_hodoadc_bar_adc_id;   //!
   TBranch        *b_Ndata_bb_hodoadc_bar_adc_mean;   //!
   TBranch        *b_bb_hodoadc_bar_adc_mean;   //!
   TBranch        *b_Ndata_bb_hodoadc_clus_bar_tdc_id;   //!
   TBranch        *b_bb_hodoadc_clus_bar_tdc_id;   //!
   TBranch        *b_Ndata_bb_hodoadc_clus_bar_tdc_itrack;   //!
   TBranch        *b_bb_hodoadc_clus_bar_tdc_itrack;   //!
   TBranch        *b_Ndata_bb_hodoadc_clus_bar_tdc_meantime;   //!
   TBranch        *b_bb_hodoadc_clus_bar_tdc_meantime;   //!
   TBranch        *b_Ndata_bb_hodoadc_clus_bar_tdc_meantot;   //!
   TBranch        *b_bb_hodoadc_clus_bar_tdc_meantot;   //!
   TBranch        *b_Ndata_bb_hodoadc_clus_bar_tdc_timediff;   //!
   TBranch        *b_bb_hodoadc_clus_bar_tdc_timediff;   //!
   TBranch        *b_Ndata_bb_hodoadc_clus_bar_tdc_timehitpos;   //!
   TBranch        *b_bb_hodoadc_clus_bar_tdc_timehitpos;   //!
   TBranch        *b_Ndata_bb_hodoadc_clus_bar_tdc_vpos;   //!
   TBranch        *b_bb_hodoadc_clus_bar_tdc_vpos;   //!
   TBranch        *b_Ndata_bb_hodoadc_clus_id;   //!
   TBranch        *b_bb_hodoadc_clus_id;   //!
   TBranch        *b_Ndata_bb_hodoadc_clus_size;   //!
   TBranch        *b_bb_hodoadc_clus_size;   //!
   TBranch        *b_Ndata_bb_hodoadc_clus_tdiff;   //!
   TBranch        *b_bb_hodoadc_clus_tdiff;   //!
   TBranch        *b_Ndata_bb_hodoadc_clus_tmean;   //!
   TBranch        *b_bb_hodoadc_clus_tmean;   //!
   TBranch        *b_Ndata_bb_hodoadc_clus_totmean;   //!
   TBranch        *b_bb_hodoadc_clus_totmean;   //!
   TBranch        *b_Ndata_bb_hodoadc_clus_trackindex;   //!
   TBranch        *b_bb_hodoadc_clus_trackindex;   //!
   TBranch        *b_Ndata_bb_hodoadc_clus_xmean;   //!
   TBranch        *b_bb_hodoadc_clus_xmean;   //!
   TBranch        *b_Ndata_bb_hodoadc_clus_ymean;   //!
   TBranch        *b_bb_hodoadc_clus_ymean;   //!
   TBranch        *b_Ndata_bb_hodoadc_ped;   //!
   TBranch        *b_bb_hodoadc_ped;   //!
   TBranch        *b_Ndata_bb_hodotdc_Ref_tdc;   //!
   TBranch        *b_bb_hodotdc_Ref_tdc;   //!
   TBranch        *b_Ndata_bb_hodotdc_Ref_tdc_mult;   //!
   TBranch        *b_bb_hodotdc_Ref_tdc_mult;   //!
   TBranch        *b_Ndata_bb_hodotdc_Ref_tdc_te;   //!
   TBranch        *b_bb_hodotdc_Ref_tdc_te;   //!
   TBranch        *b_Ndata_bb_hodotdc_Ref_tdc_tot;   //!
   TBranch        *b_bb_hodotdc_Ref_tdc_tot;   //!
   TBranch        *b_Ndata_bb_hodotdc_Ref_tdcelemID;   //!
   TBranch        *b_bb_hodotdc_Ref_tdcelemID;   //!
   TBranch        *b_Ndata_bb_hodotdc_allclus_id;   //!
   TBranch        *b_bb_hodotdc_allclus_id;   //!
   TBranch        *b_Ndata_bb_hodotdc_allclus_itrack;   //!
   TBranch        *b_bb_hodotdc_allclus_itrack;   //!
   TBranch        *b_Ndata_bb_hodotdc_allclus_size;   //!
   TBranch        *b_bb_hodotdc_allclus_size;   //!
   TBranch        *b_Ndata_bb_hodotdc_allclus_tdiff;   //!
   TBranch        *b_bb_hodotdc_allclus_tdiff;   //!
   TBranch        *b_Ndata_bb_hodotdc_allclus_tmean;   //!
   TBranch        *b_bb_hodotdc_allclus_tmean;   //!
   TBranch        *b_Ndata_bb_hodotdc_allclus_totmean;   //!
   TBranch        *b_bb_hodotdc_allclus_totmean;   //!
   TBranch        *b_Ndata_bb_hodotdc_allclus_xmean;   //!
   TBranch        *b_bb_hodotdc_allclus_xmean;   //!
   TBranch        *b_Ndata_bb_hodotdc_allclus_ymean;   //!
   TBranch        *b_bb_hodotdc_allclus_ymean;   //!
   TBranch        *b_Ndata_bb_hodotdc_bar_tdc_L_le;   //!
   TBranch        *b_bb_hodotdc_bar_tdc_L_le;   //!
   TBranch        *b_Ndata_bb_hodotdc_bar_tdc_L_leW;   //!
   TBranch        *b_bb_hodotdc_bar_tdc_L_leW;   //!
   TBranch        *b_Ndata_bb_hodotdc_bar_tdc_L_te;   //!
   TBranch        *b_bb_hodotdc_bar_tdc_L_te;   //!
   TBranch        *b_Ndata_bb_hodotdc_bar_tdc_L_teW;   //!
   TBranch        *b_bb_hodotdc_bar_tdc_L_teW;   //!
   TBranch        *b_Ndata_bb_hodotdc_bar_tdc_L_tot;   //!
   TBranch        *b_bb_hodotdc_bar_tdc_L_tot;   //!
   TBranch        *b_Ndata_bb_hodotdc_bar_tdc_L_totW;   //!
   TBranch        *b_bb_hodotdc_bar_tdc_L_totW;   //!
   TBranch        *b_Ndata_bb_hodotdc_bar_tdc_R_le;   //!
   TBranch        *b_bb_hodotdc_bar_tdc_R_le;   //!
   TBranch        *b_Ndata_bb_hodotdc_bar_tdc_R_leW;   //!
   TBranch        *b_bb_hodotdc_bar_tdc_R_leW;   //!
   TBranch        *b_Ndata_bb_hodotdc_bar_tdc_R_te;   //!
   TBranch        *b_bb_hodotdc_bar_tdc_R_te;   //!
   TBranch        *b_Ndata_bb_hodotdc_bar_tdc_R_teW;   //!
   TBranch        *b_bb_hodotdc_bar_tdc_R_teW;   //!
   TBranch        *b_Ndata_bb_hodotdc_bar_tdc_R_tot;   //!
   TBranch        *b_bb_hodotdc_bar_tdc_R_tot;   //!
   TBranch        *b_Ndata_bb_hodotdc_bar_tdc_R_totW;   //!
   TBranch        *b_bb_hodotdc_bar_tdc_R_totW;   //!
   TBranch        *b_Ndata_bb_hodotdc_bar_tdc_id;   //!
   TBranch        *b_bb_hodotdc_bar_tdc_id;   //!
   TBranch        *b_Ndata_bb_hodotdc_bar_tdc_meantime;   //!
   TBranch        *b_bb_hodotdc_bar_tdc_meantime;   //!
   TBranch        *b_Ndata_bb_hodotdc_bar_tdc_timediff;   //!
   TBranch        *b_bb_hodotdc_bar_tdc_timediff;   //!
   TBranch        *b_Ndata_bb_hodotdc_bar_tdc_timehitpos;   //!
   TBranch        *b_bb_hodotdc_bar_tdc_timehitpos;   //!
   TBranch        *b_Ndata_bb_hodotdc_bar_tdc_vpos;   //!
   TBranch        *b_bb_hodotdc_bar_tdc_vpos;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_bar_tdc_id;   //!
   TBranch        *b_bb_hodotdc_clus_bar_tdc_id;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_bar_tdc_itrack;   //!
   TBranch        *b_bb_hodotdc_clus_bar_tdc_itrack;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_bar_tdc_meantime;   //!
   TBranch        *b_bb_hodotdc_clus_bar_tdc_meantime;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_bar_tdc_meantot;   //!
   TBranch        *b_bb_hodotdc_clus_bar_tdc_meantot;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_bar_tdc_timediff;   //!
   TBranch        *b_bb_hodotdc_clus_bar_tdc_timediff;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_bar_tdc_timehitpos;   //!
   TBranch        *b_bb_hodotdc_clus_bar_tdc_timehitpos;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_bar_tdc_vpos;   //!
   TBranch        *b_bb_hodotdc_clus_bar_tdc_vpos;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_id;   //!
   TBranch        *b_bb_hodotdc_clus_id;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_size;   //!
   TBranch        *b_bb_hodotdc_clus_size;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_tdiff;   //!
   TBranch        *b_bb_hodotdc_clus_tdiff;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_tmean;   //!
   TBranch        *b_bb_hodotdc_clus_tmean;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_totmean;   //!
   TBranch        *b_bb_hodotdc_clus_totmean;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_trackindex;   //!
   TBranch        *b_bb_hodotdc_clus_trackindex;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_xmean;   //!
   TBranch        *b_bb_hodotdc_clus_xmean;   //!
   TBranch        *b_Ndata_bb_hodotdc_clus_ymean;   //!
   TBranch        *b_bb_hodotdc_clus_ymean;   //!
   TBranch        *b_Ndata_bb_hodotdc_tdc;   //!
   TBranch        *b_bb_hodotdc_tdc;   //!
   TBranch        *b_Ndata_bb_hodotdc_tdc_mult;   //!
   TBranch        *b_bb_hodotdc_tdc_mult;   //!
   TBranch        *b_Ndata_bb_hodotdc_tdc_te;   //!
   TBranch        *b_bb_hodotdc_tdc_te;   //!
   TBranch        *b_Ndata_bb_hodotdc_tdc_tot;   //!
   TBranch        *b_bb_hodotdc_tdc_tot;   //!
   TBranch        *b_Ndata_bb_hodotdc_tdccol;   //!
   TBranch        *b_bb_hodotdc_tdccol;   //!
   TBranch        *b_Ndata_bb_hodotdc_tdcelemID;   //!
   TBranch        *b_bb_hodotdc_tdcelemID;   //!
   TBranch        *b_Ndata_bb_hodotdc_tdclayer;   //!
   TBranch        *b_bb_hodotdc_tdclayer;   //!
   TBranch        *b_Ndata_bb_hodotdc_tdcrow;   //!
   TBranch        *b_bb_hodotdc_tdcrow;   //!
   TBranch        *b_bb_hodoadc_nclus;   //!
   TBranch        *b_bb_hodoadc_ngoodADChits;   //!
   TBranch        *b_bb_hodoadc_ngoodTDChits;   //!
   TBranch        *b_bb_hodoadc_nhits;   //!
   TBranch        *b_bb_hodoadc_nrefhits;   //!
   TBranch        *b_bb_hodotdc_bar_ngoodbars;   //!
   TBranch        *b_bb_hodotdc_nclus;   //!
   TBranch        *b_bb_hodotdc_ngoodADChits;   //!
   TBranch        *b_bb_hodotdc_ngoodTDChits;   //!
   TBranch        *b_bb_hodotdc_nhits;   //!
   TBranch        *b_bb_hodotdc_nrefhits;   //!
   TBranch        *b_Event_Branch_fEvtHdr_fEvtTime;   //!
   TBranch        *b_Event_Branch_fEvtHdr_fEvtNum;   //!
   TBranch        *b_Event_Branch_fEvtHdr_fEvtType;   //!
   TBranch        *b_Event_Branch_fEvtHdr_fEvtLen;   //!
   TBranch        *b_Event_Branch_fEvtHdr_fHelicity;   //!
   TBranch        *b_Event_Branch_fEvtHdr_fTrigBits;   //!
   TBranch        *b_Event_Branch_fEvtHdr_fRun;   //!

   SBSTree(TTree *tree=0);
   virtual ~SBSTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef SBSTree_cxx
SBSTree::SBSTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/volatile/halla/sbs/gpenman/Rootfiles/e1209019_bbhodo_11590_50000.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/volatile/halla/sbs/gpenman/Rootfiles/e1209019_bbhodo_11590_50000.root");
      }
      f->GetObject("T",tree);

   }
   Init(tree);
}

SBSTree::~SBSTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t SBSTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t SBSTree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void SBSTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Ndata.bb.hodoadc.Ref.a", &Ndata_bb_hodoadc_Ref_a, &b_Ndata_bb_hodoadc_Ref_a);
   fChain->SetBranchAddress("bb.hodoadc.Ref.a", &bb_hodoadc_Ref_a, &b_bb_hodoadc_Ref_a);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.Ref.a_amp", &Ndata_bb_hodoadc_Ref_a_amp, &b_Ndata_bb_hodoadc_Ref_a_amp);
   fChain->SetBranchAddress("bb.hodoadc.Ref.a_amp", &bb_hodoadc_Ref_a_amp, &b_bb_hodoadc_Ref_a_amp);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.Ref.a_amp_c", &Ndata_bb_hodoadc_Ref_a_amp_c, &b_Ndata_bb_hodoadc_Ref_a_amp_c);
   fChain->SetBranchAddress("bb.hodoadc.Ref.a_amp_c", &bb_hodoadc_Ref_a_amp_c, &b_bb_hodoadc_Ref_a_amp_c);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.Ref.a_amp_p", &Ndata_bb_hodoadc_Ref_a_amp_p, &b_Ndata_bb_hodoadc_Ref_a_amp_p);
   fChain->SetBranchAddress("bb.hodoadc.Ref.a_amp_p", &bb_hodoadc_Ref_a_amp_p, &b_bb_hodoadc_Ref_a_amp_p);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.Ref.a_c", &Ndata_bb_hodoadc_Ref_a_c, &b_Ndata_bb_hodoadc_Ref_a_c);
   fChain->SetBranchAddress("bb.hodoadc.Ref.a_c", &bb_hodoadc_Ref_a_c, &b_bb_hodoadc_Ref_a_c);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.Ref.a_mult", &Ndata_bb_hodoadc_Ref_a_mult, &b_Ndata_bb_hodoadc_Ref_a_mult);
   fChain->SetBranchAddress("bb.hodoadc.Ref.a_mult", &bb_hodoadc_Ref_a_mult, &b_bb_hodoadc_Ref_a_mult);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.Ref.a_p", &Ndata_bb_hodoadc_Ref_a_p, &b_Ndata_bb_hodoadc_Ref_a_p);
   fChain->SetBranchAddress("bb.hodoadc.Ref.a_p", &bb_hodoadc_Ref_a_p, &b_bb_hodoadc_Ref_a_p);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.Ref.a_time", &Ndata_bb_hodoadc_Ref_a_time, &b_Ndata_bb_hodoadc_Ref_a_time);
   fChain->SetBranchAddress("bb.hodoadc.Ref.a_time", &bb_hodoadc_Ref_a_time, &b_bb_hodoadc_Ref_a_time);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.Ref.adcelemID", &Ndata_bb_hodoadc_Ref_adcelemID, &b_Ndata_bb_hodoadc_Ref_adcelemID);
   fChain->SetBranchAddress("bb.hodoadc.Ref.adcelemID", &bb_hodoadc_Ref_adcelemID, &b_bb_hodoadc_Ref_adcelemID);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.Ref.ped", &Ndata_bb_hodoadc_Ref_ped, &b_Ndata_bb_hodoadc_Ref_ped);
   fChain->SetBranchAddress("bb.hodoadc.Ref.ped", &bb_hodoadc_Ref_ped, &b_bb_hodoadc_Ref_ped);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.a", &Ndata_bb_hodoadc_a, &b_Ndata_bb_hodoadc_a);
   fChain->SetBranchAddress("bb.hodoadc.a", bb_hodoadc_a, &b_bb_hodoadc_a);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.a_amp", &Ndata_bb_hodoadc_a_amp, &b_Ndata_bb_hodoadc_a_amp);
   fChain->SetBranchAddress("bb.hodoadc.a_amp", bb_hodoadc_a_amp, &b_bb_hodoadc_a_amp);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.a_amp_c", &Ndata_bb_hodoadc_a_amp_c, &b_Ndata_bb_hodoadc_a_amp_c);
   fChain->SetBranchAddress("bb.hodoadc.a_amp_c", bb_hodoadc_a_amp_c, &b_bb_hodoadc_a_amp_c);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.a_amp_p", &Ndata_bb_hodoadc_a_amp_p, &b_Ndata_bb_hodoadc_a_amp_p);
   fChain->SetBranchAddress("bb.hodoadc.a_amp_p", bb_hodoadc_a_amp_p, &b_bb_hodoadc_a_amp_p);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.a_amptrig_c", &Ndata_bb_hodoadc_a_amptrig_c, &b_Ndata_bb_hodoadc_a_amptrig_c);
   fChain->SetBranchAddress("bb.hodoadc.a_amptrig_c", bb_hodoadc_a_amptrig_c, &b_bb_hodoadc_a_amptrig_c);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.a_amptrig_p", &Ndata_bb_hodoadc_a_amptrig_p, &b_Ndata_bb_hodoadc_a_amptrig_p);
   fChain->SetBranchAddress("bb.hodoadc.a_amptrig_p", bb_hodoadc_a_amptrig_p, &b_bb_hodoadc_a_amptrig_p);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.a_c", &Ndata_bb_hodoadc_a_c, &b_Ndata_bb_hodoadc_a_c);
   fChain->SetBranchAddress("bb.hodoadc.a_c", bb_hodoadc_a_c, &b_bb_hodoadc_a_c);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.a_mult", &Ndata_bb_hodoadc_a_mult, &b_Ndata_bb_hodoadc_a_mult);
   fChain->SetBranchAddress("bb.hodoadc.a_mult", bb_hodoadc_a_mult, &b_bb_hodoadc_a_mult);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.a_p", &Ndata_bb_hodoadc_a_p, &b_Ndata_bb_hodoadc_a_p);
   fChain->SetBranchAddress("bb.hodoadc.a_p", bb_hodoadc_a_p, &b_bb_hodoadc_a_p);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.a_time", &Ndata_bb_hodoadc_a_time, &b_Ndata_bb_hodoadc_a_time);
   fChain->SetBranchAddress("bb.hodoadc.a_time", bb_hodoadc_a_time, &b_bb_hodoadc_a_time);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.adccol", &Ndata_bb_hodoadc_adccol, &b_Ndata_bb_hodoadc_adccol);
   fChain->SetBranchAddress("bb.hodoadc.adccol", bb_hodoadc_adccol, &b_bb_hodoadc_adccol);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.adcelemID", &Ndata_bb_hodoadc_adcelemID, &b_Ndata_bb_hodoadc_adcelemID);
   fChain->SetBranchAddress("bb.hodoadc.adcelemID", bb_hodoadc_adcelemID, &b_bb_hodoadc_adcelemID);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.adclayer", &Ndata_bb_hodoadc_adclayer, &b_Ndata_bb_hodoadc_adclayer);
   fChain->SetBranchAddress("bb.hodoadc.adclayer", bb_hodoadc_adclayer, &b_bb_hodoadc_adclayer);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.adcrow", &Ndata_bb_hodoadc_adcrow, &b_Ndata_bb_hodoadc_adcrow);
   fChain->SetBranchAddress("bb.hodoadc.adcrow", bb_hodoadc_adcrow, &b_bb_hodoadc_adcrow);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.allclus.id", &Ndata_bb_hodoadc_allclus_id, &b_Ndata_bb_hodoadc_allclus_id);
   fChain->SetBranchAddress("bb.hodoadc.allclus.id", &bb_hodoadc_allclus_id, &b_bb_hodoadc_allclus_id);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.allclus.itrack", &Ndata_bb_hodoadc_allclus_itrack, &b_Ndata_bb_hodoadc_allclus_itrack);
   fChain->SetBranchAddress("bb.hodoadc.allclus.itrack", &bb_hodoadc_allclus_itrack, &b_bb_hodoadc_allclus_itrack);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.allclus.size", &Ndata_bb_hodoadc_allclus_size, &b_Ndata_bb_hodoadc_allclus_size);
   fChain->SetBranchAddress("bb.hodoadc.allclus.size", &bb_hodoadc_allclus_size, &b_bb_hodoadc_allclus_size);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.allclus.tdiff", &Ndata_bb_hodoadc_allclus_tdiff, &b_Ndata_bb_hodoadc_allclus_tdiff);
   fChain->SetBranchAddress("bb.hodoadc.allclus.tdiff", &bb_hodoadc_allclus_tdiff, &b_bb_hodoadc_allclus_tdiff);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.allclus.tmean", &Ndata_bb_hodoadc_allclus_tmean, &b_Ndata_bb_hodoadc_allclus_tmean);
   fChain->SetBranchAddress("bb.hodoadc.allclus.tmean", &bb_hodoadc_allclus_tmean, &b_bb_hodoadc_allclus_tmean);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.allclus.totmean", &Ndata_bb_hodoadc_allclus_totmean, &b_Ndata_bb_hodoadc_allclus_totmean);
   fChain->SetBranchAddress("bb.hodoadc.allclus.totmean", &bb_hodoadc_allclus_totmean, &b_bb_hodoadc_allclus_totmean);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.allclus.xmean", &Ndata_bb_hodoadc_allclus_xmean, &b_Ndata_bb_hodoadc_allclus_xmean);
   fChain->SetBranchAddress("bb.hodoadc.allclus.xmean", &bb_hodoadc_allclus_xmean, &b_bb_hodoadc_allclus_xmean);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.allclus.ymean", &Ndata_bb_hodoadc_allclus_ymean, &b_Ndata_bb_hodoadc_allclus_ymean);
   fChain->SetBranchAddress("bb.hodoadc.allclus.ymean", &bb_hodoadc_allclus_ymean, &b_bb_hodoadc_allclus_ymean);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.bar.adc.L.a", &Ndata_bb_hodoadc_bar_adc_L_a, &b_Ndata_bb_hodoadc_bar_adc_L_a);
   fChain->SetBranchAddress("bb.hodoadc.bar.adc.L.a", bb_hodoadc_bar_adc_L_a, &b_bb_hodoadc_bar_adc_L_a);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.bar.adc.L.ac", &Ndata_bb_hodoadc_bar_adc_L_ac, &b_Ndata_bb_hodoadc_bar_adc_L_ac);
   fChain->SetBranchAddress("bb.hodoadc.bar.adc.L.ac", bb_hodoadc_bar_adc_L_ac, &b_bb_hodoadc_bar_adc_L_ac);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.bar.adc.L.ap", &Ndata_bb_hodoadc_bar_adc_L_ap, &b_Ndata_bb_hodoadc_bar_adc_L_ap);
   fChain->SetBranchAddress("bb.hodoadc.bar.adc.L.ap", bb_hodoadc_bar_adc_L_ap, &b_bb_hodoadc_bar_adc_L_ap);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.bar.adc.R.a", &Ndata_bb_hodoadc_bar_adc_R_a, &b_Ndata_bb_hodoadc_bar_adc_R_a);
   fChain->SetBranchAddress("bb.hodoadc.bar.adc.R.a", bb_hodoadc_bar_adc_R_a, &b_bb_hodoadc_bar_adc_R_a);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.bar.adc.R.ac", &Ndata_bb_hodoadc_bar_adc_R_ac, &b_Ndata_bb_hodoadc_bar_adc_R_ac);
   fChain->SetBranchAddress("bb.hodoadc.bar.adc.R.ac", bb_hodoadc_bar_adc_R_ac, &b_bb_hodoadc_bar_adc_R_ac);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.bar.adc.R.ap", &Ndata_bb_hodoadc_bar_adc_R_ap, &b_Ndata_bb_hodoadc_bar_adc_R_ap);
   fChain->SetBranchAddress("bb.hodoadc.bar.adc.R.ap", bb_hodoadc_bar_adc_R_ap, &b_bb_hodoadc_bar_adc_R_ap);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.bar.adc.id", &Ndata_bb_hodoadc_bar_adc_id, &b_Ndata_bb_hodoadc_bar_adc_id);
   fChain->SetBranchAddress("bb.hodoadc.bar.adc.id", bb_hodoadc_bar_adc_id, &b_bb_hodoadc_bar_adc_id);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.bar.adc.mean", &Ndata_bb_hodoadc_bar_adc_mean, &b_Ndata_bb_hodoadc_bar_adc_mean);
   fChain->SetBranchAddress("bb.hodoadc.bar.adc.mean", bb_hodoadc_bar_adc_mean, &b_bb_hodoadc_bar_adc_mean);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.clus.bar.tdc.id", &Ndata_bb_hodoadc_clus_bar_tdc_id, &b_Ndata_bb_hodoadc_clus_bar_tdc_id);
   fChain->SetBranchAddress("bb.hodoadc.clus.bar.tdc.id", &bb_hodoadc_clus_bar_tdc_id, &b_bb_hodoadc_clus_bar_tdc_id);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.clus.bar.tdc.itrack", &Ndata_bb_hodoadc_clus_bar_tdc_itrack, &b_Ndata_bb_hodoadc_clus_bar_tdc_itrack);
   fChain->SetBranchAddress("bb.hodoadc.clus.bar.tdc.itrack", &bb_hodoadc_clus_bar_tdc_itrack, &b_bb_hodoadc_clus_bar_tdc_itrack);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.clus.bar.tdc.meantime", &Ndata_bb_hodoadc_clus_bar_tdc_meantime, &b_Ndata_bb_hodoadc_clus_bar_tdc_meantime);
   fChain->SetBranchAddress("bb.hodoadc.clus.bar.tdc.meantime", &bb_hodoadc_clus_bar_tdc_meantime, &b_bb_hodoadc_clus_bar_tdc_meantime);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.clus.bar.tdc.meantot", &Ndata_bb_hodoadc_clus_bar_tdc_meantot, &b_Ndata_bb_hodoadc_clus_bar_tdc_meantot);
   fChain->SetBranchAddress("bb.hodoadc.clus.bar.tdc.meantot", &bb_hodoadc_clus_bar_tdc_meantot, &b_bb_hodoadc_clus_bar_tdc_meantot);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.clus.bar.tdc.timediff", &Ndata_bb_hodoadc_clus_bar_tdc_timediff, &b_Ndata_bb_hodoadc_clus_bar_tdc_timediff);
   fChain->SetBranchAddress("bb.hodoadc.clus.bar.tdc.timediff", &bb_hodoadc_clus_bar_tdc_timediff, &b_bb_hodoadc_clus_bar_tdc_timediff);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.clus.bar.tdc.timehitpos", &Ndata_bb_hodoadc_clus_bar_tdc_timehitpos, &b_Ndata_bb_hodoadc_clus_bar_tdc_timehitpos);
   fChain->SetBranchAddress("bb.hodoadc.clus.bar.tdc.timehitpos", &bb_hodoadc_clus_bar_tdc_timehitpos, &b_bb_hodoadc_clus_bar_tdc_timehitpos);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.clus.bar.tdc.vpos", &Ndata_bb_hodoadc_clus_bar_tdc_vpos, &b_Ndata_bb_hodoadc_clus_bar_tdc_vpos);
   fChain->SetBranchAddress("bb.hodoadc.clus.bar.tdc.vpos", &bb_hodoadc_clus_bar_tdc_vpos, &b_bb_hodoadc_clus_bar_tdc_vpos);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.clus.id", &Ndata_bb_hodoadc_clus_id, &b_Ndata_bb_hodoadc_clus_id);
   fChain->SetBranchAddress("bb.hodoadc.clus.id", &bb_hodoadc_clus_id, &b_bb_hodoadc_clus_id);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.clus.size", &Ndata_bb_hodoadc_clus_size, &b_Ndata_bb_hodoadc_clus_size);
   fChain->SetBranchAddress("bb.hodoadc.clus.size", &bb_hodoadc_clus_size, &b_bb_hodoadc_clus_size);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.clus.tdiff", &Ndata_bb_hodoadc_clus_tdiff, &b_Ndata_bb_hodoadc_clus_tdiff);
   fChain->SetBranchAddress("bb.hodoadc.clus.tdiff", &bb_hodoadc_clus_tdiff, &b_bb_hodoadc_clus_tdiff);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.clus.tmean", &Ndata_bb_hodoadc_clus_tmean, &b_Ndata_bb_hodoadc_clus_tmean);
   fChain->SetBranchAddress("bb.hodoadc.clus.tmean", &bb_hodoadc_clus_tmean, &b_bb_hodoadc_clus_tmean);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.clus.totmean", &Ndata_bb_hodoadc_clus_totmean, &b_Ndata_bb_hodoadc_clus_totmean);
   fChain->SetBranchAddress("bb.hodoadc.clus.totmean", &bb_hodoadc_clus_totmean, &b_bb_hodoadc_clus_totmean);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.clus.trackindex", &Ndata_bb_hodoadc_clus_trackindex, &b_Ndata_bb_hodoadc_clus_trackindex);
   fChain->SetBranchAddress("bb.hodoadc.clus.trackindex", &bb_hodoadc_clus_trackindex, &b_bb_hodoadc_clus_trackindex);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.clus.xmean", &Ndata_bb_hodoadc_clus_xmean, &b_Ndata_bb_hodoadc_clus_xmean);
   fChain->SetBranchAddress("bb.hodoadc.clus.xmean", &bb_hodoadc_clus_xmean, &b_bb_hodoadc_clus_xmean);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.clus.ymean", &Ndata_bb_hodoadc_clus_ymean, &b_Ndata_bb_hodoadc_clus_ymean);
   fChain->SetBranchAddress("bb.hodoadc.clus.ymean", &bb_hodoadc_clus_ymean, &b_bb_hodoadc_clus_ymean);
   fChain->SetBranchAddress("Ndata.bb.hodoadc.ped", &Ndata_bb_hodoadc_ped, &b_Ndata_bb_hodoadc_ped);
   fChain->SetBranchAddress("bb.hodoadc.ped", bb_hodoadc_ped, &b_bb_hodoadc_ped);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.Ref.tdc", &Ndata_bb_hodotdc_Ref_tdc, &b_Ndata_bb_hodotdc_Ref_tdc);
   fChain->SetBranchAddress("bb.hodotdc.Ref.tdc", bb_hodotdc_Ref_tdc, &b_bb_hodotdc_Ref_tdc);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.Ref.tdc_mult", &Ndata_bb_hodotdc_Ref_tdc_mult, &b_Ndata_bb_hodotdc_Ref_tdc_mult);
   fChain->SetBranchAddress("bb.hodotdc.Ref.tdc_mult", bb_hodotdc_Ref_tdc_mult, &b_bb_hodotdc_Ref_tdc_mult);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.Ref.tdc_te", &Ndata_bb_hodotdc_Ref_tdc_te, &b_Ndata_bb_hodotdc_Ref_tdc_te);
   fChain->SetBranchAddress("bb.hodotdc.Ref.tdc_te", bb_hodotdc_Ref_tdc_te, &b_bb_hodotdc_Ref_tdc_te);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.Ref.tdc_tot", &Ndata_bb_hodotdc_Ref_tdc_tot, &b_Ndata_bb_hodotdc_Ref_tdc_tot);
   fChain->SetBranchAddress("bb.hodotdc.Ref.tdc_tot", bb_hodotdc_Ref_tdc_tot, &b_bb_hodotdc_Ref_tdc_tot);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.Ref.tdcelemID", &Ndata_bb_hodotdc_Ref_tdcelemID, &b_Ndata_bb_hodotdc_Ref_tdcelemID);
   fChain->SetBranchAddress("bb.hodotdc.Ref.tdcelemID", bb_hodotdc_Ref_tdcelemID, &b_bb_hodotdc_Ref_tdcelemID);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.allclus.id", &Ndata_bb_hodotdc_allclus_id, &b_Ndata_bb_hodotdc_allclus_id);
   fChain->SetBranchAddress("bb.hodotdc.allclus.id", bb_hodotdc_allclus_id, &b_bb_hodotdc_allclus_id);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.allclus.itrack", &Ndata_bb_hodotdc_allclus_itrack, &b_Ndata_bb_hodotdc_allclus_itrack);
   fChain->SetBranchAddress("bb.hodotdc.allclus.itrack", bb_hodotdc_allclus_itrack, &b_bb_hodotdc_allclus_itrack);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.allclus.size", &Ndata_bb_hodotdc_allclus_size, &b_Ndata_bb_hodotdc_allclus_size);
   fChain->SetBranchAddress("bb.hodotdc.allclus.size", bb_hodotdc_allclus_size, &b_bb_hodotdc_allclus_size);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.allclus.tdiff", &Ndata_bb_hodotdc_allclus_tdiff, &b_Ndata_bb_hodotdc_allclus_tdiff);
   fChain->SetBranchAddress("bb.hodotdc.allclus.tdiff", bb_hodotdc_allclus_tdiff, &b_bb_hodotdc_allclus_tdiff);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.allclus.tmean", &Ndata_bb_hodotdc_allclus_tmean, &b_Ndata_bb_hodotdc_allclus_tmean);
   fChain->SetBranchAddress("bb.hodotdc.allclus.tmean", bb_hodotdc_allclus_tmean, &b_bb_hodotdc_allclus_tmean);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.allclus.totmean", &Ndata_bb_hodotdc_allclus_totmean, &b_Ndata_bb_hodotdc_allclus_totmean);
   fChain->SetBranchAddress("bb.hodotdc.allclus.totmean", bb_hodotdc_allclus_totmean, &b_bb_hodotdc_allclus_totmean);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.allclus.xmean", &Ndata_bb_hodotdc_allclus_xmean, &b_Ndata_bb_hodotdc_allclus_xmean);
   fChain->SetBranchAddress("bb.hodotdc.allclus.xmean", bb_hodotdc_allclus_xmean, &b_bb_hodotdc_allclus_xmean);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.allclus.ymean", &Ndata_bb_hodotdc_allclus_ymean, &b_Ndata_bb_hodotdc_allclus_ymean);
   fChain->SetBranchAddress("bb.hodotdc.allclus.ymean", bb_hodotdc_allclus_ymean, &b_bb_hodotdc_allclus_ymean);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.L.le", &Ndata_bb_hodotdc_bar_tdc_L_le, &b_Ndata_bb_hodotdc_bar_tdc_L_le);
   fChain->SetBranchAddress("bb.hodotdc.bar.tdc.L.le", bb_hodotdc_bar_tdc_L_le, &b_bb_hodotdc_bar_tdc_L_le);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.L.leW", &Ndata_bb_hodotdc_bar_tdc_L_leW, &b_Ndata_bb_hodotdc_bar_tdc_L_leW);
   fChain->SetBranchAddress("bb.hodotdc.bar.tdc.L.leW", bb_hodotdc_bar_tdc_L_leW, &b_bb_hodotdc_bar_tdc_L_leW);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.L.te", &Ndata_bb_hodotdc_bar_tdc_L_te, &b_Ndata_bb_hodotdc_bar_tdc_L_te);
   fChain->SetBranchAddress("bb.hodotdc.bar.tdc.L.te", bb_hodotdc_bar_tdc_L_te, &b_bb_hodotdc_bar_tdc_L_te);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.L.teW", &Ndata_bb_hodotdc_bar_tdc_L_teW, &b_Ndata_bb_hodotdc_bar_tdc_L_teW);
   fChain->SetBranchAddress("bb.hodotdc.bar.tdc.L.teW", bb_hodotdc_bar_tdc_L_teW, &b_bb_hodotdc_bar_tdc_L_teW);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.L.tot", &Ndata_bb_hodotdc_bar_tdc_L_tot, &b_Ndata_bb_hodotdc_bar_tdc_L_tot);
   fChain->SetBranchAddress("bb.hodotdc.bar.tdc.L.tot", bb_hodotdc_bar_tdc_L_tot, &b_bb_hodotdc_bar_tdc_L_tot);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.L.totW", &Ndata_bb_hodotdc_bar_tdc_L_totW, &b_Ndata_bb_hodotdc_bar_tdc_L_totW);
   fChain->SetBranchAddress("bb.hodotdc.bar.tdc.L.totW", bb_hodotdc_bar_tdc_L_totW, &b_bb_hodotdc_bar_tdc_L_totW);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.R.le", &Ndata_bb_hodotdc_bar_tdc_R_le, &b_Ndata_bb_hodotdc_bar_tdc_R_le);
   fChain->SetBranchAddress("bb.hodotdc.bar.tdc.R.le", bb_hodotdc_bar_tdc_R_le, &b_bb_hodotdc_bar_tdc_R_le);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.R.leW", &Ndata_bb_hodotdc_bar_tdc_R_leW, &b_Ndata_bb_hodotdc_bar_tdc_R_leW);
   fChain->SetBranchAddress("bb.hodotdc.bar.tdc.R.leW", bb_hodotdc_bar_tdc_R_leW, &b_bb_hodotdc_bar_tdc_R_leW);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.R.te", &Ndata_bb_hodotdc_bar_tdc_R_te, &b_Ndata_bb_hodotdc_bar_tdc_R_te);
   fChain->SetBranchAddress("bb.hodotdc.bar.tdc.R.te", bb_hodotdc_bar_tdc_R_te, &b_bb_hodotdc_bar_tdc_R_te);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.R.teW", &Ndata_bb_hodotdc_bar_tdc_R_teW, &b_Ndata_bb_hodotdc_bar_tdc_R_teW);
   fChain->SetBranchAddress("bb.hodotdc.bar.tdc.R.teW", bb_hodotdc_bar_tdc_R_teW, &b_bb_hodotdc_bar_tdc_R_teW);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.R.tot", &Ndata_bb_hodotdc_bar_tdc_R_tot, &b_Ndata_bb_hodotdc_bar_tdc_R_tot);
   fChain->SetBranchAddress("bb.hodotdc.bar.tdc.R.tot", bb_hodotdc_bar_tdc_R_tot, &b_bb_hodotdc_bar_tdc_R_tot);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.R.totW", &Ndata_bb_hodotdc_bar_tdc_R_totW, &b_Ndata_bb_hodotdc_bar_tdc_R_totW);
   fChain->SetBranchAddress("bb.hodotdc.bar.tdc.R.totW", bb_hodotdc_bar_tdc_R_totW, &b_bb_hodotdc_bar_tdc_R_totW);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.id", &Ndata_bb_hodotdc_bar_tdc_id, &b_Ndata_bb_hodotdc_bar_tdc_id);
   fChain->SetBranchAddress("bb.hodotdc.bar.tdc.id", bb_hodotdc_bar_tdc_id, &b_bb_hodotdc_bar_tdc_id);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.meantime", &Ndata_bb_hodotdc_bar_tdc_meantime, &b_Ndata_bb_hodotdc_bar_tdc_meantime);
   fChain->SetBranchAddress("bb.hodotdc.bar.tdc.meantime", bb_hodotdc_bar_tdc_meantime, &b_bb_hodotdc_bar_tdc_meantime);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.timediff", &Ndata_bb_hodotdc_bar_tdc_timediff, &b_Ndata_bb_hodotdc_bar_tdc_timediff);
   fChain->SetBranchAddress("bb.hodotdc.bar.tdc.timediff", bb_hodotdc_bar_tdc_timediff, &b_bb_hodotdc_bar_tdc_timediff);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.timehitpos", &Ndata_bb_hodotdc_bar_tdc_timehitpos, &b_Ndata_bb_hodotdc_bar_tdc_timehitpos);
   fChain->SetBranchAddress("bb.hodotdc.bar.tdc.timehitpos", bb_hodotdc_bar_tdc_timehitpos, &b_bb_hodotdc_bar_tdc_timehitpos);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.vpos", &Ndata_bb_hodotdc_bar_tdc_vpos, &b_Ndata_bb_hodotdc_bar_tdc_vpos);
   fChain->SetBranchAddress("bb.hodotdc.bar.tdc.vpos", bb_hodotdc_bar_tdc_vpos, &b_bb_hodotdc_bar_tdc_vpos);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.bar.tdc.id", &Ndata_bb_hodotdc_clus_bar_tdc_id, &b_Ndata_bb_hodotdc_clus_bar_tdc_id);
   fChain->SetBranchAddress("bb.hodotdc.clus.bar.tdc.id", &bb_hodotdc_clus_bar_tdc_id, &b_bb_hodotdc_clus_bar_tdc_id);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.bar.tdc.itrack", &Ndata_bb_hodotdc_clus_bar_tdc_itrack, &b_Ndata_bb_hodotdc_clus_bar_tdc_itrack);
   fChain->SetBranchAddress("bb.hodotdc.clus.bar.tdc.itrack", &bb_hodotdc_clus_bar_tdc_itrack, &b_bb_hodotdc_clus_bar_tdc_itrack);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.bar.tdc.meantime", &Ndata_bb_hodotdc_clus_bar_tdc_meantime, &b_Ndata_bb_hodotdc_clus_bar_tdc_meantime);
   fChain->SetBranchAddress("bb.hodotdc.clus.bar.tdc.meantime", &bb_hodotdc_clus_bar_tdc_meantime, &b_bb_hodotdc_clus_bar_tdc_meantime);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.bar.tdc.meantot", &Ndata_bb_hodotdc_clus_bar_tdc_meantot, &b_Ndata_bb_hodotdc_clus_bar_tdc_meantot);
   fChain->SetBranchAddress("bb.hodotdc.clus.bar.tdc.meantot", &bb_hodotdc_clus_bar_tdc_meantot, &b_bb_hodotdc_clus_bar_tdc_meantot);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.bar.tdc.timediff", &Ndata_bb_hodotdc_clus_bar_tdc_timediff, &b_Ndata_bb_hodotdc_clus_bar_tdc_timediff);
   fChain->SetBranchAddress("bb.hodotdc.clus.bar.tdc.timediff", &bb_hodotdc_clus_bar_tdc_timediff, &b_bb_hodotdc_clus_bar_tdc_timediff);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.bar.tdc.timehitpos", &Ndata_bb_hodotdc_clus_bar_tdc_timehitpos, &b_Ndata_bb_hodotdc_clus_bar_tdc_timehitpos);
   fChain->SetBranchAddress("bb.hodotdc.clus.bar.tdc.timehitpos", &bb_hodotdc_clus_bar_tdc_timehitpos, &b_bb_hodotdc_clus_bar_tdc_timehitpos);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.bar.tdc.vpos", &Ndata_bb_hodotdc_clus_bar_tdc_vpos, &b_Ndata_bb_hodotdc_clus_bar_tdc_vpos);
   fChain->SetBranchAddress("bb.hodotdc.clus.bar.tdc.vpos", &bb_hodotdc_clus_bar_tdc_vpos, &b_bb_hodotdc_clus_bar_tdc_vpos);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.id", &Ndata_bb_hodotdc_clus_id, &b_Ndata_bb_hodotdc_clus_id);
   fChain->SetBranchAddress("bb.hodotdc.clus.id", &bb_hodotdc_clus_id, &b_bb_hodotdc_clus_id);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.size", &Ndata_bb_hodotdc_clus_size, &b_Ndata_bb_hodotdc_clus_size);
   fChain->SetBranchAddress("bb.hodotdc.clus.size", &bb_hodotdc_clus_size, &b_bb_hodotdc_clus_size);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.tdiff", &Ndata_bb_hodotdc_clus_tdiff, &b_Ndata_bb_hodotdc_clus_tdiff);
   fChain->SetBranchAddress("bb.hodotdc.clus.tdiff", &bb_hodotdc_clus_tdiff, &b_bb_hodotdc_clus_tdiff);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.tmean", &Ndata_bb_hodotdc_clus_tmean, &b_Ndata_bb_hodotdc_clus_tmean);
   fChain->SetBranchAddress("bb.hodotdc.clus.tmean", &bb_hodotdc_clus_tmean, &b_bb_hodotdc_clus_tmean);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.totmean", &Ndata_bb_hodotdc_clus_totmean, &b_Ndata_bb_hodotdc_clus_totmean);
   fChain->SetBranchAddress("bb.hodotdc.clus.totmean", &bb_hodotdc_clus_totmean, &b_bb_hodotdc_clus_totmean);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.trackindex", &Ndata_bb_hodotdc_clus_trackindex, &b_Ndata_bb_hodotdc_clus_trackindex);
   fChain->SetBranchAddress("bb.hodotdc.clus.trackindex", &bb_hodotdc_clus_trackindex, &b_bb_hodotdc_clus_trackindex);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.xmean", &Ndata_bb_hodotdc_clus_xmean, &b_Ndata_bb_hodotdc_clus_xmean);
   fChain->SetBranchAddress("bb.hodotdc.clus.xmean", &bb_hodotdc_clus_xmean, &b_bb_hodotdc_clus_xmean);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.clus.ymean", &Ndata_bb_hodotdc_clus_ymean, &b_Ndata_bb_hodotdc_clus_ymean);
   fChain->SetBranchAddress("bb.hodotdc.clus.ymean", &bb_hodotdc_clus_ymean, &b_bb_hodotdc_clus_ymean);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.tdc", &Ndata_bb_hodotdc_tdc, &b_Ndata_bb_hodotdc_tdc);
   fChain->SetBranchAddress("bb.hodotdc.tdc", bb_hodotdc_tdc, &b_bb_hodotdc_tdc);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.tdc_mult", &Ndata_bb_hodotdc_tdc_mult, &b_Ndata_bb_hodotdc_tdc_mult);
   fChain->SetBranchAddress("bb.hodotdc.tdc_mult", bb_hodotdc_tdc_mult, &b_bb_hodotdc_tdc_mult);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.tdc_te", &Ndata_bb_hodotdc_tdc_te, &b_Ndata_bb_hodotdc_tdc_te);
   fChain->SetBranchAddress("bb.hodotdc.tdc_te", bb_hodotdc_tdc_te, &b_bb_hodotdc_tdc_te);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.tdc_tot", &Ndata_bb_hodotdc_tdc_tot, &b_Ndata_bb_hodotdc_tdc_tot);
   fChain->SetBranchAddress("bb.hodotdc.tdc_tot", bb_hodotdc_tdc_tot, &b_bb_hodotdc_tdc_tot);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.tdccol", &Ndata_bb_hodotdc_tdccol, &b_Ndata_bb_hodotdc_tdccol);
   fChain->SetBranchAddress("bb.hodotdc.tdccol", bb_hodotdc_tdccol, &b_bb_hodotdc_tdccol);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.tdcelemID", &Ndata_bb_hodotdc_tdcelemID, &b_Ndata_bb_hodotdc_tdcelemID);
   fChain->SetBranchAddress("bb.hodotdc.tdcelemID", bb_hodotdc_tdcelemID, &b_bb_hodotdc_tdcelemID);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.tdclayer", &Ndata_bb_hodotdc_tdclayer, &b_Ndata_bb_hodotdc_tdclayer);
   fChain->SetBranchAddress("bb.hodotdc.tdclayer", bb_hodotdc_tdclayer, &b_bb_hodotdc_tdclayer);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.tdcrow", &Ndata_bb_hodotdc_tdcrow, &b_Ndata_bb_hodotdc_tdcrow);
   fChain->SetBranchAddress("bb.hodotdc.tdcrow", bb_hodotdc_tdcrow, &b_bb_hodotdc_tdcrow);
   fChain->SetBranchAddress("bb.hodoadc.nclus", &bb_hodoadc_nclus, &b_bb_hodoadc_nclus);
   fChain->SetBranchAddress("bb.hodoadc.ngoodADChits", &bb_hodoadc_ngoodADChits, &b_bb_hodoadc_ngoodADChits);
   fChain->SetBranchAddress("bb.hodoadc.ngoodTDChits", &bb_hodoadc_ngoodTDChits, &b_bb_hodoadc_ngoodTDChits);
   fChain->SetBranchAddress("bb.hodoadc.nhits", &bb_hodoadc_nhits, &b_bb_hodoadc_nhits);
   fChain->SetBranchAddress("bb.hodoadc.nrefhits", &bb_hodoadc_nrefhits, &b_bb_hodoadc_nrefhits);
   fChain->SetBranchAddress("bb.hodotdc.bar.ngoodbars", &bb_hodotdc_bar_ngoodbars, &b_bb_hodotdc_bar_ngoodbars);
   fChain->SetBranchAddress("bb.hodotdc.nclus", &bb_hodotdc_nclus, &b_bb_hodotdc_nclus);
   fChain->SetBranchAddress("bb.hodotdc.ngoodADChits", &bb_hodotdc_ngoodADChits, &b_bb_hodotdc_ngoodADChits);
   fChain->SetBranchAddress("bb.hodotdc.ngoodTDChits", &bb_hodotdc_ngoodTDChits, &b_bb_hodotdc_ngoodTDChits);
   fChain->SetBranchAddress("bb.hodotdc.nhits", &bb_hodotdc_nhits, &b_bb_hodotdc_nhits);
   fChain->SetBranchAddress("bb.hodotdc.nrefhits", &bb_hodotdc_nrefhits, &b_bb_hodotdc_nrefhits);
   fChain->SetBranchAddress("fEvtHdr.fEvtTime", &fEvtHdr_fEvtTime, &b_Event_Branch_fEvtHdr_fEvtTime);
   fChain->SetBranchAddress("fEvtHdr.fEvtNum", &fEvtHdr_fEvtNum, &b_Event_Branch_fEvtHdr_fEvtNum);
   fChain->SetBranchAddress("fEvtHdr.fEvtType", &fEvtHdr_fEvtType, &b_Event_Branch_fEvtHdr_fEvtType);
   fChain->SetBranchAddress("fEvtHdr.fEvtLen", &fEvtHdr_fEvtLen, &b_Event_Branch_fEvtHdr_fEvtLen);
   fChain->SetBranchAddress("fEvtHdr.fHelicity", &fEvtHdr_fHelicity, &b_Event_Branch_fEvtHdr_fHelicity);
   fChain->SetBranchAddress("fEvtHdr.fTrigBits", &fEvtHdr_fTrigBits, &b_Event_Branch_fEvtHdr_fTrigBits);
   fChain->SetBranchAddress("fEvtHdr.fRun", &fEvtHdr_fRun, &b_Event_Branch_fEvtHdr_fRun);
   Notify();
}

Bool_t SBSTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void SBSTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t SBSTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef SBSTree_cxx
