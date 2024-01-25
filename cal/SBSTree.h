//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Nov 13 08:18:59 2023 by ROOT version 6.26/10
// from TTree T/Hall A Analyzer Output DST
// found on file: /volatile/halla/sbs/gpenman/GEN_REPLAY/rootfiles/Bad_EncodeTDC/e1209016_fullreplay_2095_stream0_2_seg0_0.root
//////////////////////////////////////////////////////////

#ifndef SBSTree_h
#define SBSTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "THaEvent.h"
#include "THaEvent.h"

class SBSTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Double_t        rast12x;
   Double_t        rast12y;
   Double_t        rast12xmm;
   Double_t        rast12ymm;
   Double_t        ax_new;
   Double_t        bx_new;
   Double_t        ay_new;
   Double_t        by_new;
   Double_t        targx;
   Double_t        targy;
   Double_t        scalhel_true_hel;
   Double_t        scalhel_hel_stable;
   Int_t           Ndata_bb_bbtrig_a_amp_p;
   Double_t        bb_bbtrig_a_amp_p[12];   //[Ndata.bb.bbtrig.a_amp_p]
   Int_t           Ndata_bb_bbtrig_a_time;
   Double_t        bb_bbtrig_a_time[12];   //[Ndata.bb.bbtrig.a_time]
   Int_t           Ndata_bb_bbtrig_adcelemID;
   Double_t        bb_bbtrig_adcelemID[12];   //[Ndata.bb.bbtrig.adcelemID]
   Int_t           Ndata_bb_bbtrig_tdc;
   Double_t        bb_bbtrig_tdc[8];   //[Ndata.bb.bbtrig.tdc]
   Int_t           Ndata_bb_bbtrig_tdcelemID;
   Double_t        bb_bbtrig_tdcelemID[8];   //[Ndata.bb.bbtrig.tdcelemID]
   Int_t           Ndata_bb_eps_over_etot;
   Double_t        bb_eps_over_etot[1];   //[Ndata.bb.eps_over_etot]
   Int_t           Ndata_bb_etot_over_p;
   Double_t        bb_etot_over_p[3];   //[Ndata.bb.etot_over_p]
   Int_t           Ndata_bb_gem_hit_ADCU;
   Double_t        bb_gem_hit_ADCU[11];   //[Ndata.bb.gem.hit.ADCU]
   Int_t           Ndata_bb_gem_hit_ADCU_deconv;
   Double_t        bb_gem_hit_ADCU_deconv[11];   //[Ndata.bb.gem.hit.ADCU_deconv]
   Int_t           Ndata_bb_gem_hit_ADCV;
   Double_t        bb_gem_hit_ADCV[11];   //[Ndata.bb.gem.hit.ADCV]
   Int_t           Ndata_bb_gem_hit_ADCV_deconv;
   Double_t        bb_gem_hit_ADCV_deconv[11];   //[Ndata.bb.gem.hit.ADCV_deconv]
   Int_t           Ndata_bb_gem_hit_ADCasym;
   Double_t        bb_gem_hit_ADCasym[11];   //[Ndata.bb.gem.hit.ADCasym]
   Int_t           Ndata_bb_gem_hit_ADCasym_deconv;
   Double_t        bb_gem_hit_ADCasym_deconv[11];   //[Ndata.bb.gem.hit.ADCasym_deconv]
   Int_t           Ndata_bb_gem_hit_ADCavg;
   Double_t        bb_gem_hit_ADCavg[11];   //[Ndata.bb.gem.hit.ADCavg]
   Int_t           Ndata_bb_gem_hit_ADCavg_deconv;
   Double_t        bb_gem_hit_ADCavg_deconv[11];   //[Ndata.bb.gem.hit.ADCavg_deconv]
   Int_t           Ndata_bb_gem_hit_ADCfrac0_Umax;
   Double_t        bb_gem_hit_ADCfrac0_Umax[11];   //[Ndata.bb.gem.hit.ADCfrac0_Umax]
   Int_t           Ndata_bb_gem_hit_ADCfrac0_Vmax;
   Double_t        bb_gem_hit_ADCfrac0_Vmax[11];   //[Ndata.bb.gem.hit.ADCfrac0_Vmax]
   Int_t           Ndata_bb_gem_hit_ADCfrac1_Umax;
   Double_t        bb_gem_hit_ADCfrac1_Umax[11];   //[Ndata.bb.gem.hit.ADCfrac1_Umax]
   Int_t           Ndata_bb_gem_hit_ADCfrac1_Vmax;
   Double_t        bb_gem_hit_ADCfrac1_Vmax[11];   //[Ndata.bb.gem.hit.ADCfrac1_Vmax]
   Int_t           Ndata_bb_gem_hit_ADCfrac2_Umax;
   Double_t        bb_gem_hit_ADCfrac2_Umax[11];   //[Ndata.bb.gem.hit.ADCfrac2_Umax]
   Int_t           Ndata_bb_gem_hit_ADCfrac2_Vmax;
   Double_t        bb_gem_hit_ADCfrac2_Vmax[11];   //[Ndata.bb.gem.hit.ADCfrac2_Vmax]
   Int_t           Ndata_bb_gem_hit_ADCfrac3_Umax;
   Double_t        bb_gem_hit_ADCfrac3_Umax[11];   //[Ndata.bb.gem.hit.ADCfrac3_Umax]
   Int_t           Ndata_bb_gem_hit_ADCfrac3_Vmax;
   Double_t        bb_gem_hit_ADCfrac3_Vmax[11];   //[Ndata.bb.gem.hit.ADCfrac3_Vmax]
   Int_t           Ndata_bb_gem_hit_ADCfrac4_Umax;
   Double_t        bb_gem_hit_ADCfrac4_Umax[11];   //[Ndata.bb.gem.hit.ADCfrac4_Umax]
   Int_t           Ndata_bb_gem_hit_ADCfrac4_Vmax;
   Double_t        bb_gem_hit_ADCfrac4_Vmax[11];   //[Ndata.bb.gem.hit.ADCfrac4_Vmax]
   Int_t           Ndata_bb_gem_hit_ADCfrac5_Umax;
   Double_t        bb_gem_hit_ADCfrac5_Umax[11];   //[Ndata.bb.gem.hit.ADCfrac5_Umax]
   Int_t           Ndata_bb_gem_hit_ADCfrac5_Vmax;
   Double_t        bb_gem_hit_ADCfrac5_Vmax[11];   //[Ndata.bb.gem.hit.ADCfrac5_Vmax]
   Int_t           Ndata_bb_gem_hit_ADCmaxcomboUclust_deconv;
   Double_t        bb_gem_hit_ADCmaxcomboUclust_deconv[11];   //[Ndata.bb.gem.hit.ADCmaxcomboUclust_deconv]
   Int_t           Ndata_bb_gem_hit_ADCmaxcomboVclust_deconv;
   Double_t        bb_gem_hit_ADCmaxcomboVclust_deconv[11];   //[Ndata.bb.gem.hit.ADCmaxcomboVclust_deconv]
   Int_t           Ndata_bb_gem_hit_ADCmaxsampU;
   Double_t        bb_gem_hit_ADCmaxsampU[11];   //[Ndata.bb.gem.hit.ADCmaxsampU]
   Int_t           Ndata_bb_gem_hit_ADCmaxsampUclust;
   Double_t        bb_gem_hit_ADCmaxsampUclust[11];   //[Ndata.bb.gem.hit.ADCmaxsampUclust]
   Int_t           Ndata_bb_gem_hit_ADCmaxsampUclust_deconv;
   Double_t        bb_gem_hit_ADCmaxsampUclust_deconv[11];   //[Ndata.bb.gem.hit.ADCmaxsampUclust_deconv]
   Int_t           Ndata_bb_gem_hit_ADCmaxsampV;
   Double_t        bb_gem_hit_ADCmaxsampV[11];   //[Ndata.bb.gem.hit.ADCmaxsampV]
   Int_t           Ndata_bb_gem_hit_ADCmaxsampVclust;
   Double_t        bb_gem_hit_ADCmaxsampVclust[11];   //[Ndata.bb.gem.hit.ADCmaxsampVclust]
   Int_t           Ndata_bb_gem_hit_ADCmaxsampVclust_deconv;
   Double_t        bb_gem_hit_ADCmaxsampVclust_deconv[11];   //[Ndata.bb.gem.hit.ADCmaxsampVclust_deconv]
   Int_t           Ndata_bb_gem_hit_ADCmaxstripU;
   Double_t        bb_gem_hit_ADCmaxstripU[11];   //[Ndata.bb.gem.hit.ADCmaxstripU]
   Int_t           Ndata_bb_gem_hit_ADCmaxstripV;
   Double_t        bb_gem_hit_ADCmaxstripV[11];   //[Ndata.bb.gem.hit.ADCmaxstripV]
   Int_t           Ndata_bb_gem_hit_BUILD_ALL_SAMPLES_U;
   Double_t        bb_gem_hit_BUILD_ALL_SAMPLES_U[11];   //[Ndata.bb.gem.hit.BUILD_ALL_SAMPLES_U]
   Int_t           Ndata_bb_gem_hit_BUILD_ALL_SAMPLES_V;
   Double_t        bb_gem_hit_BUILD_ALL_SAMPLES_V[11];   //[Ndata.bb.gem.hit.BUILD_ALL_SAMPLES_V]
   Int_t           Ndata_bb_gem_hit_CM_GOOD_U;
   Double_t        bb_gem_hit_CM_GOOD_U[11];   //[Ndata.bb.gem.hit.CM_GOOD_U]
   Int_t           Ndata_bb_gem_hit_CM_GOOD_V;
   Double_t        bb_gem_hit_CM_GOOD_V[11];   //[Ndata.bb.gem.hit.CM_GOOD_V]
   Int_t           Ndata_bb_gem_hit_DeconvADC0_Umax;
   Double_t        bb_gem_hit_DeconvADC0_Umax[11];   //[Ndata.bb.gem.hit.DeconvADC0_Umax]
   Int_t           Ndata_bb_gem_hit_DeconvADC0_Vmax;
   Double_t        bb_gem_hit_DeconvADC0_Vmax[11];   //[Ndata.bb.gem.hit.DeconvADC0_Vmax]
   Int_t           Ndata_bb_gem_hit_DeconvADC1_Umax;
   Double_t        bb_gem_hit_DeconvADC1_Umax[11];   //[Ndata.bb.gem.hit.DeconvADC1_Umax]
   Int_t           Ndata_bb_gem_hit_DeconvADC1_Vmax;
   Double_t        bb_gem_hit_DeconvADC1_Vmax[11];   //[Ndata.bb.gem.hit.DeconvADC1_Vmax]
   Int_t           Ndata_bb_gem_hit_DeconvADC2_Umax;
   Double_t        bb_gem_hit_DeconvADC2_Umax[11];   //[Ndata.bb.gem.hit.DeconvADC2_Umax]
   Int_t           Ndata_bb_gem_hit_DeconvADC2_Vmax;
   Double_t        bb_gem_hit_DeconvADC2_Vmax[11];   //[Ndata.bb.gem.hit.DeconvADC2_Vmax]
   Int_t           Ndata_bb_gem_hit_DeconvADC3_Umax;
   Double_t        bb_gem_hit_DeconvADC3_Umax[11];   //[Ndata.bb.gem.hit.DeconvADC3_Umax]
   Int_t           Ndata_bb_gem_hit_DeconvADC3_Vmax;
   Double_t        bb_gem_hit_DeconvADC3_Vmax[11];   //[Ndata.bb.gem.hit.DeconvADC3_Vmax]
   Int_t           Ndata_bb_gem_hit_DeconvADC4_Umax;
   Double_t        bb_gem_hit_DeconvADC4_Umax[11];   //[Ndata.bb.gem.hit.DeconvADC4_Umax]
   Int_t           Ndata_bb_gem_hit_DeconvADC4_Vmax;
   Double_t        bb_gem_hit_DeconvADC4_Vmax[11];   //[Ndata.bb.gem.hit.DeconvADC4_Vmax]
   Int_t           Ndata_bb_gem_hit_DeconvADC5_Umax;
   Double_t        bb_gem_hit_DeconvADC5_Umax[11];   //[Ndata.bb.gem.hit.DeconvADC5_Umax]
   Int_t           Ndata_bb_gem_hit_DeconvADC5_Vmax;
   Double_t        bb_gem_hit_DeconvADC5_Vmax[11];   //[Ndata.bb.gem.hit.DeconvADC5_Vmax]
   Int_t           Ndata_bb_gem_hit_DeconvADCmaxcomboU;
   Double_t        bb_gem_hit_DeconvADCmaxcomboU[11];   //[Ndata.bb.gem.hit.DeconvADCmaxcomboU]
   Int_t           Ndata_bb_gem_hit_DeconvADCmaxcomboV;
   Double_t        bb_gem_hit_DeconvADCmaxcomboV[11];   //[Ndata.bb.gem.hit.DeconvADCmaxcomboV]
   Int_t           Ndata_bb_gem_hit_DeconvADCmaxsampU;
   Double_t        bb_gem_hit_DeconvADCmaxsampU[11];   //[Ndata.bb.gem.hit.DeconvADCmaxsampU]
   Int_t           Ndata_bb_gem_hit_DeconvADCmaxsampV;
   Double_t        bb_gem_hit_DeconvADCmaxsampV[11];   //[Ndata.bb.gem.hit.DeconvADCmaxsampV]
   Int_t           Ndata_bb_gem_hit_DeconvADCmaxstripU;
   Double_t        bb_gem_hit_DeconvADCmaxstripU[11];   //[Ndata.bb.gem.hit.DeconvADCmaxstripU]
   Int_t           Ndata_bb_gem_hit_DeconvADCmaxstripV;
   Double_t        bb_gem_hit_DeconvADCmaxstripV[11];   //[Ndata.bb.gem.hit.DeconvADCmaxstripV]
   Int_t           Ndata_bb_gem_hit_ENABLE_CM_U;
   Double_t        bb_gem_hit_ENABLE_CM_U[11];   //[Ndata.bb.gem.hit.ENABLE_CM_U]
   Int_t           Ndata_bb_gem_hit_ENABLE_CM_V;
   Double_t        bb_gem_hit_ENABLE_CM_V[11];   //[Ndata.bb.gem.hit.ENABLE_CM_V]
   Int_t           Ndata_bb_gem_hit_TSchi2_Umax;
   Double_t        bb_gem_hit_TSchi2_Umax[11];   //[Ndata.bb.gem.hit.TSchi2_Umax]
   Int_t           Ndata_bb_gem_hit_TSchi2_Vmax;
   Double_t        bb_gem_hit_TSchi2_Vmax[11];   //[Ndata.bb.gem.hit.TSchi2_Vmax]
   Int_t           Ndata_bb_gem_hit_TSprob_Umax;
   Double_t        bb_gem_hit_TSprob_Umax[11];   //[Ndata.bb.gem.hit.TSprob_Umax]
   Int_t           Ndata_bb_gem_hit_TSprob_Vmax;
   Double_t        bb_gem_hit_TSprob_Vmax[11];   //[Ndata.bb.gem.hit.TSprob_Vmax]
   Int_t           Ndata_bb_gem_hit_Tavg;
   Double_t        bb_gem_hit_Tavg[11];   //[Ndata.bb.gem.hit.Tavg]
   Int_t           Ndata_bb_gem_hit_Tavg_corr;
   Double_t        bb_gem_hit_Tavg_corr[11];   //[Ndata.bb.gem.hit.Tavg_corr]
   Int_t           Ndata_bb_gem_hit_Tavg_deconv;
   Double_t        bb_gem_hit_Tavg_deconv[11];   //[Ndata.bb.gem.hit.Tavg_deconv]
   Int_t           Ndata_bb_gem_hit_Tavg_fit;
   Double_t        bb_gem_hit_Tavg_fit[11];   //[Ndata.bb.gem.hit.Tavg_fit]
   Int_t           Ndata_bb_gem_hit_Ugain;
   Double_t        bb_gem_hit_Ugain[11];   //[Ndata.bb.gem.hit.Ugain]
   Int_t           Ndata_bb_gem_hit_Utime;
   Double_t        bb_gem_hit_Utime[11];   //[Ndata.bb.gem.hit.Utime]
   Int_t           Ndata_bb_gem_hit_UtimeDeconv;
   Double_t        bb_gem_hit_UtimeDeconv[11];   //[Ndata.bb.gem.hit.UtimeDeconv]
   Int_t           Ndata_bb_gem_hit_UtimeFit;
   Double_t        bb_gem_hit_UtimeFit[11];   //[Ndata.bb.gem.hit.UtimeFit]
   Int_t           Ndata_bb_gem_hit_UtimeMaxStrip;
   Double_t        bb_gem_hit_UtimeMaxStrip[11];   //[Ndata.bb.gem.hit.UtimeMaxStrip]
   Int_t           Ndata_bb_gem_hit_UtimeMaxStripDeconv;
   Double_t        bb_gem_hit_UtimeMaxStripDeconv[11];   //[Ndata.bb.gem.hit.UtimeMaxStripDeconv]
   Int_t           Ndata_bb_gem_hit_UtimeMaxStripFit;
   Double_t        bb_gem_hit_UtimeMaxStripFit[11];   //[Ndata.bb.gem.hit.UtimeMaxStripFit]
   Int_t           Ndata_bb_gem_hit_Vgain;
   Double_t        bb_gem_hit_Vgain[11];   //[Ndata.bb.gem.hit.Vgain]
   Int_t           Ndata_bb_gem_hit_Vtime;
   Double_t        bb_gem_hit_Vtime[11];   //[Ndata.bb.gem.hit.Vtime]
   Int_t           Ndata_bb_gem_hit_VtimeDeconv;
   Double_t        bb_gem_hit_VtimeDeconv[11];   //[Ndata.bb.gem.hit.VtimeDeconv]
   Int_t           Ndata_bb_gem_hit_VtimeFit;
   Double_t        bb_gem_hit_VtimeFit[11];   //[Ndata.bb.gem.hit.VtimeFit]
   Int_t           Ndata_bb_gem_hit_VtimeMaxStrip;
   Double_t        bb_gem_hit_VtimeMaxStrip[11];   //[Ndata.bb.gem.hit.VtimeMaxStrip]
   Int_t           Ndata_bb_gem_hit_VtimeMaxStripDeconv;
   Double_t        bb_gem_hit_VtimeMaxStripDeconv[11];   //[Ndata.bb.gem.hit.VtimeMaxStripDeconv]
   Int_t           Ndata_bb_gem_hit_VtimeMaxStripFit;
   Double_t        bb_gem_hit_VtimeMaxStripFit[11];   //[Ndata.bb.gem.hit.VtimeMaxStripFit]
   Int_t           Ndata_bb_gem_hit_ccor_clust;
   Double_t        bb_gem_hit_ccor_clust[11];   //[Ndata.bb.gem.hit.ccor_clust]
   Int_t           Ndata_bb_gem_hit_ccor_clust_deconv;
   Double_t        bb_gem_hit_ccor_clust_deconv[11];   //[Ndata.bb.gem.hit.ccor_clust_deconv]
   Int_t           Ndata_bb_gem_hit_ccor_strip;
   Double_t        bb_gem_hit_ccor_strip[11];   //[Ndata.bb.gem.hit.ccor_strip]
   Int_t           Ndata_bb_gem_hit_ccor_strip_deconv;
   Double_t        bb_gem_hit_ccor_strip_deconv[11];   //[Ndata.bb.gem.hit.ccor_strip_deconv]
   Int_t           Ndata_bb_gem_hit_deltat;
   Double_t        bb_gem_hit_deltat[11];   //[Ndata.bb.gem.hit.deltat]
   Int_t           Ndata_bb_gem_hit_deltat_deconv;
   Double_t        bb_gem_hit_deltat_deconv[11];   //[Ndata.bb.gem.hit.deltat_deconv]
   Int_t           Ndata_bb_gem_hit_deltat_fit;
   Double_t        bb_gem_hit_deltat_fit[11];   //[Ndata.bb.gem.hit.deltat_fit]
   Int_t           Ndata_bb_gem_hit_eresidu;
   Double_t        bb_gem_hit_eresidu[11];   //[Ndata.bb.gem.hit.eresidu]
   Int_t           Ndata_bb_gem_hit_eresidv;
   Double_t        bb_gem_hit_eresidv[11];   //[Ndata.bb.gem.hit.eresidv]
   Int_t           Ndata_bb_gem_hit_icombomaxUclustDeconv;
   Double_t        bb_gem_hit_icombomaxUclustDeconv[11];   //[Ndata.bb.gem.hit.icombomaxUclustDeconv]
   Int_t           Ndata_bb_gem_hit_icombomaxUstripDeconv;
   Double_t        bb_gem_hit_icombomaxUstripDeconv[11];   //[Ndata.bb.gem.hit.icombomaxUstripDeconv]
   Int_t           Ndata_bb_gem_hit_icombomaxVclustDeconv;
   Double_t        bb_gem_hit_icombomaxVclustDeconv[11];   //[Ndata.bb.gem.hit.icombomaxVclustDeconv]
   Int_t           Ndata_bb_gem_hit_icombomaxVstripDeconv;
   Double_t        bb_gem_hit_icombomaxVstripDeconv[11];   //[Ndata.bb.gem.hit.icombomaxVstripDeconv]
   Int_t           Ndata_bb_gem_hit_isampmaxUclust;
   Double_t        bb_gem_hit_isampmaxUclust[11];   //[Ndata.bb.gem.hit.isampmaxUclust]
   Int_t           Ndata_bb_gem_hit_isampmaxUclustDeconv;
   Double_t        bb_gem_hit_isampmaxUclustDeconv[11];   //[Ndata.bb.gem.hit.isampmaxUclustDeconv]
   Int_t           Ndata_bb_gem_hit_isampmaxUstrip;
   Double_t        bb_gem_hit_isampmaxUstrip[11];   //[Ndata.bb.gem.hit.isampmaxUstrip]
   Int_t           Ndata_bb_gem_hit_isampmaxUstripDeconv;
   Double_t        bb_gem_hit_isampmaxUstripDeconv[11];   //[Ndata.bb.gem.hit.isampmaxUstripDeconv]
   Int_t           Ndata_bb_gem_hit_isampmaxVclust;
   Double_t        bb_gem_hit_isampmaxVclust[11];   //[Ndata.bb.gem.hit.isampmaxVclust]
   Int_t           Ndata_bb_gem_hit_isampmaxVclustDeconv;
   Double_t        bb_gem_hit_isampmaxVclustDeconv[11];   //[Ndata.bb.gem.hit.isampmaxVclustDeconv]
   Int_t           Ndata_bb_gem_hit_isampmaxVstrip;
   Double_t        bb_gem_hit_isampmaxVstrip[11];   //[Ndata.bb.gem.hit.isampmaxVstrip]
   Int_t           Ndata_bb_gem_hit_isampmaxVstripDeconv;
   Double_t        bb_gem_hit_isampmaxVstripDeconv[11];   //[Ndata.bb.gem.hit.isampmaxVstripDeconv]
   Int_t           Ndata_bb_gem_hit_layer;
   Double_t        bb_gem_hit_layer[11];   //[Ndata.bb.gem.hit.layer]
   Int_t           Ndata_bb_gem_hit_module;
   Double_t        bb_gem_hit_module[11];   //[Ndata.bb.gem.hit.module]
   Int_t           Ndata_bb_gem_hit_nstripu;
   Double_t        bb_gem_hit_nstripu[11];   //[Ndata.bb.gem.hit.nstripu]
   Int_t           Ndata_bb_gem_hit_nstripv;
   Double_t        bb_gem_hit_nstripv[11];   //[Ndata.bb.gem.hit.nstripv]
   Int_t           Ndata_bb_gem_hit_residu;
   Double_t        bb_gem_hit_residu[11];   //[Ndata.bb.gem.hit.residu]
   Int_t           Ndata_bb_gem_hit_residv;
   Double_t        bb_gem_hit_residv[11];   //[Ndata.bb.gem.hit.residv]
   Int_t           Ndata_bb_gem_hit_trackindex;
   Double_t        bb_gem_hit_trackindex[11];   //[Ndata.bb.gem.hit.trackindex]
   Int_t           Ndata_bb_gem_hit_u;
   Double_t        bb_gem_hit_u[11];   //[Ndata.bb.gem.hit.u]
   Int_t           Ndata_bb_gem_hit_umoment;
   Double_t        bb_gem_hit_umoment[11];   //[Ndata.bb.gem.hit.umoment]
   Int_t           Ndata_bb_gem_hit_usigma;
   Double_t        bb_gem_hit_usigma[11];   //[Ndata.bb.gem.hit.usigma]
   Int_t           Ndata_bb_gem_hit_ustriphi;
   Double_t        bb_gem_hit_ustriphi[11];   //[Ndata.bb.gem.hit.ustriphi]
   Int_t           Ndata_bb_gem_hit_ustriplo;
   Double_t        bb_gem_hit_ustriplo[11];   //[Ndata.bb.gem.hit.ustriplo]
   Int_t           Ndata_bb_gem_hit_ustripmax;
   Double_t        bb_gem_hit_ustripmax[11];   //[Ndata.bb.gem.hit.ustripmax]
   Int_t           Ndata_bb_gem_hit_v;
   Double_t        bb_gem_hit_v[11];   //[Ndata.bb.gem.hit.v]
   Int_t           Ndata_bb_gem_hit_vmoment;
   Double_t        bb_gem_hit_vmoment[11];   //[Ndata.bb.gem.hit.vmoment]
   Int_t           Ndata_bb_gem_hit_vsigma;
   Double_t        bb_gem_hit_vsigma[11];   //[Ndata.bb.gem.hit.vsigma]
   Int_t           Ndata_bb_gem_hit_vstriphi;
   Double_t        bb_gem_hit_vstriphi[11];   //[Ndata.bb.gem.hit.vstriphi]
   Int_t           Ndata_bb_gem_hit_vstriplo;
   Double_t        bb_gem_hit_vstriplo[11];   //[Ndata.bb.gem.hit.vstriplo]
   Int_t           Ndata_bb_gem_hit_vstripmax;
   Double_t        bb_gem_hit_vstripmax[11];   //[Ndata.bb.gem.hit.vstripmax]
   Int_t           Ndata_bb_gem_hit_xglobal;
   Double_t        bb_gem_hit_xglobal[11];   //[Ndata.bb.gem.hit.xglobal]
   Int_t           Ndata_bb_gem_hit_xlocal;
   Double_t        bb_gem_hit_xlocal[11];   //[Ndata.bb.gem.hit.xlocal]
   Int_t           Ndata_bb_gem_hit_yglobal;
   Double_t        bb_gem_hit_yglobal[11];   //[Ndata.bb.gem.hit.yglobal]
   Int_t           Ndata_bb_gem_hit_ylocal;
   Double_t        bb_gem_hit_ylocal[11];   //[Ndata.bb.gem.hit.ylocal]
   Int_t           Ndata_bb_gem_hit_zglobal;
   Double_t        bb_gem_hit_zglobal[11];   //[Ndata.bb.gem.hit.zglobal]
   Int_t           Ndata_bb_gem_n2Dhit_layer;
   Double_t        bb_gem_n2Dhit_layer[5];   //[Ndata.bb.gem.n2Dhit_layer]
   Int_t           Ndata_bb_gem_nclustu_layer;
   Double_t        bb_gem_nclustu_layer[5];   //[Ndata.bb.gem.nclustu_layer]
   Int_t           Ndata_bb_gem_nclustv_layer;
   Double_t        bb_gem_nclustv_layer[5];   //[Ndata.bb.gem.nclustv_layer]
   Int_t           Ndata_bb_gem_nstripsu_layer;
   Double_t        bb_gem_nstripsu_layer[5];   //[Ndata.bb.gem.nstripsu_layer]
   Int_t           Ndata_bb_gem_nstripsv_layer;
   Double_t        bb_gem_nstripsv_layer[5];   //[Ndata.bb.gem.nstripsv_layer]
   Int_t           Ndata_bb_gem_track_chi2ndf;
   Double_t        bb_gem_track_chi2ndf[3];   //[Ndata.bb.gem.track.chi2ndf]
   Int_t           Ndata_bb_gem_track_chi2ndf_hitquality;
   Double_t        bb_gem_track_chi2ndf_hitquality[3];   //[Ndata.bb.gem.track.chi2ndf_hitquality]
   Int_t           Ndata_bb_gem_track_ngoodhits;
   Double_t        bb_gem_track_ngoodhits[3];   //[Ndata.bb.gem.track.ngoodhits]
   Int_t           Ndata_bb_gem_track_nhits;
   Double_t        bb_gem_track_nhits[3];   //[Ndata.bb.gem.track.nhits]
   Int_t           Ndata_bb_gem_track_t0;
   Double_t        bb_gem_track_t0[3];   //[Ndata.bb.gem.track.t0]
   Int_t           Ndata_bb_gem_track_x;
   Double_t        bb_gem_track_x[3];   //[Ndata.bb.gem.track.x]
   Int_t           Ndata_bb_gem_track_xp;
   Double_t        bb_gem_track_xp[3];   //[Ndata.bb.gem.track.xp]
   Int_t           Ndata_bb_gem_track_y;
   Double_t        bb_gem_track_y[3];   //[Ndata.bb.gem.track.y]
   Int_t           Ndata_bb_gem_track_yp;
   Double_t        bb_gem_track_yp[3];   //[Ndata.bb.gem.track.yp]
   Int_t           Ndata_bb_grinch_tdc_allclus_adc;
   Double_t        bb_grinch_tdc_allclus_adc[28];   //[Ndata.bb.grinch_tdc.allclus.adc]
   Int_t           Ndata_bb_grinch_tdc_allclus_dx;
   Double_t        bb_grinch_tdc_allclus_dx[28];   //[Ndata.bb.grinch_tdc.allclus.dx]
   Int_t           Ndata_bb_grinch_tdc_allclus_dy;
   Double_t        bb_grinch_tdc_allclus_dy[28];   //[Ndata.bb.grinch_tdc.allclus.dy]
   Int_t           Ndata_bb_grinch_tdc_allclus_mirrorindex;
   Double_t        bb_grinch_tdc_allclus_mirrorindex[28];   //[Ndata.bb.grinch_tdc.allclus.mirrorindex]
   Int_t           Ndata_bb_grinch_tdc_allclus_size;
   Double_t        bb_grinch_tdc_allclus_size[28];   //[Ndata.bb.grinch_tdc.allclus.size]
   Int_t           Ndata_bb_grinch_tdc_allclus_t_mean;
   Double_t        bb_grinch_tdc_allclus_t_mean[28];   //[Ndata.bb.grinch_tdc.allclus.t_mean]
   Int_t           Ndata_bb_grinch_tdc_allclus_t_rms;
   Double_t        bb_grinch_tdc_allclus_t_rms[28];   //[Ndata.bb.grinch_tdc.allclus.t_rms]
   Int_t           Ndata_bb_grinch_tdc_allclus_tot_mean;
   Double_t        bb_grinch_tdc_allclus_tot_mean[28];   //[Ndata.bb.grinch_tdc.allclus.tot_mean]
   Int_t           Ndata_bb_grinch_tdc_allclus_trackindex;
   Double_t        bb_grinch_tdc_allclus_trackindex[28];   //[Ndata.bb.grinch_tdc.allclus.trackindex]
   Int_t           Ndata_bb_grinch_tdc_allclus_x_mean;
   Double_t        bb_grinch_tdc_allclus_x_mean[28];   //[Ndata.bb.grinch_tdc.allclus.x_mean]
   Int_t           Ndata_bb_grinch_tdc_allclus_y_mean;
   Double_t        bb_grinch_tdc_allclus_y_mean[28];   //[Ndata.bb.grinch_tdc.allclus.y_mean]
   Int_t           Ndata_bb_grinch_tdc_hit_amp;
   Double_t        bb_grinch_tdc_hit_amp[60];   //[Ndata.bb.grinch_tdc.hit.amp]
   Int_t           Ndata_bb_grinch_tdc_hit_clustindex;
   Double_t        bb_grinch_tdc_hit_clustindex[60];   //[Ndata.bb.grinch_tdc.hit.clustindex]
   Int_t           Ndata_bb_grinch_tdc_hit_col;
   Double_t        bb_grinch_tdc_hit_col[60];   //[Ndata.bb.grinch_tdc.hit.col]
   Int_t           Ndata_bb_grinch_tdc_hit_pmtnum;
   Double_t        bb_grinch_tdc_hit_pmtnum[60];   //[Ndata.bb.grinch_tdc.hit.pmtnum]
   Int_t           Ndata_bb_grinch_tdc_hit_row;
   Double_t        bb_grinch_tdc_hit_row[60];   //[Ndata.bb.grinch_tdc.hit.row]
   Int_t           Ndata_bb_grinch_tdc_hit_time;
   Double_t        bb_grinch_tdc_hit_time[60];   //[Ndata.bb.grinch_tdc.hit.time]
   Int_t           Ndata_bb_grinch_tdc_hit_trackindex;
   Double_t        bb_grinch_tdc_hit_trackindex[60];   //[Ndata.bb.grinch_tdc.hit.trackindex]
   Int_t           Ndata_bb_grinch_tdc_hit_xhit;
   Double_t        bb_grinch_tdc_hit_xhit[60];   //[Ndata.bb.grinch_tdc.hit.xhit]
   Int_t           Ndata_bb_grinch_tdc_hit_yhit;
   Double_t        bb_grinch_tdc_hit_yhit[60];   //[Ndata.bb.grinch_tdc.hit.yhit]
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
   Double_t        bb_hodoadc_a[55];   //[Ndata.bb.hodoadc.a]
   Int_t           Ndata_bb_hodoadc_a_amp;
   Double_t        bb_hodoadc_a_amp[55];   //[Ndata.bb.hodoadc.a_amp]
   Int_t           Ndata_bb_hodoadc_a_amp_c;
   Double_t        bb_hodoadc_a_amp_c[55];   //[Ndata.bb.hodoadc.a_amp_c]
   Int_t           Ndata_bb_hodoadc_a_amp_p;
   Double_t        bb_hodoadc_a_amp_p[55];   //[Ndata.bb.hodoadc.a_amp_p]
   Int_t           Ndata_bb_hodoadc_a_amptrig_c;
   Double_t        bb_hodoadc_a_amptrig_c[55];   //[Ndata.bb.hodoadc.a_amptrig_c]
   Int_t           Ndata_bb_hodoadc_a_amptrig_p;
   Double_t        bb_hodoadc_a_amptrig_p[55];   //[Ndata.bb.hodoadc.a_amptrig_p]
   Int_t           Ndata_bb_hodoadc_a_c;
   Double_t        bb_hodoadc_a_c[55];   //[Ndata.bb.hodoadc.a_c]
   Int_t           Ndata_bb_hodoadc_a_mult;
   Double_t        bb_hodoadc_a_mult[55];   //[Ndata.bb.hodoadc.a_mult]
   Int_t           Ndata_bb_hodoadc_a_p;
   Double_t        bb_hodoadc_a_p[55];   //[Ndata.bb.hodoadc.a_p]
   Int_t           Ndata_bb_hodoadc_a_time;
   Double_t        bb_hodoadc_a_time[55];   //[Ndata.bb.hodoadc.a_time]
   Int_t           Ndata_bb_hodoadc_adccol;
   Double_t        bb_hodoadc_adccol[55];   //[Ndata.bb.hodoadc.adccol]
   Int_t           Ndata_bb_hodoadc_adcelemID;
   Double_t        bb_hodoadc_adcelemID[55];   //[Ndata.bb.hodoadc.adcelemID]
   Int_t           Ndata_bb_hodoadc_adclayer;
   Double_t        bb_hodoadc_adclayer[55];   //[Ndata.bb.hodoadc.adclayer]
   Int_t           Ndata_bb_hodoadc_adcrow;
   Double_t        bb_hodoadc_adcrow[55];   //[Ndata.bb.hodoadc.adcrow]
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
   Double_t        bb_hodoadc_bar_adc_L_a[27];   //[Ndata.bb.hodoadc.bar.adc.L.a]
   Int_t           Ndata_bb_hodoadc_bar_adc_L_ac;
   Double_t        bb_hodoadc_bar_adc_L_ac[27];   //[Ndata.bb.hodoadc.bar.adc.L.ac]
   Int_t           Ndata_bb_hodoadc_bar_adc_L_ap;
   Double_t        bb_hodoadc_bar_adc_L_ap[27];   //[Ndata.bb.hodoadc.bar.adc.L.ap]
   Int_t           Ndata_bb_hodoadc_bar_adc_R_a;
   Double_t        bb_hodoadc_bar_adc_R_a[27];   //[Ndata.bb.hodoadc.bar.adc.R.a]
   Int_t           Ndata_bb_hodoadc_bar_adc_R_ac;
   Double_t        bb_hodoadc_bar_adc_R_ac[27];   //[Ndata.bb.hodoadc.bar.adc.R.ac]
   Int_t           Ndata_bb_hodoadc_bar_adc_R_ap;
   Double_t        bb_hodoadc_bar_adc_R_ap[27];   //[Ndata.bb.hodoadc.bar.adc.R.ap]
   Int_t           Ndata_bb_hodoadc_bar_adc_id;
   Double_t        bb_hodoadc_bar_adc_id[27];   //[Ndata.bb.hodoadc.bar.adc.id]
   Int_t           Ndata_bb_hodoadc_bar_adc_mean;
   Double_t        bb_hodoadc_bar_adc_mean[27];   //[Ndata.bb.hodoadc.bar.adc.mean]
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
   Double_t        bb_hodoadc_ped[55];   //[Ndata.bb.hodoadc.ped]
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
   Double_t        bb_hodotdc_allclus_id[1];   //[Ndata.bb.hodotdc.allclus.id]
   Int_t           Ndata_bb_hodotdc_allclus_itrack;
   Double_t        bb_hodotdc_allclus_itrack[1];   //[Ndata.bb.hodotdc.allclus.itrack]
   Int_t           Ndata_bb_hodotdc_allclus_size;
   Double_t        bb_hodotdc_allclus_size[1];   //[Ndata.bb.hodotdc.allclus.size]
   Int_t           Ndata_bb_hodotdc_allclus_tdiff;
   Double_t        bb_hodotdc_allclus_tdiff[1];   //[Ndata.bb.hodotdc.allclus.tdiff]
   Int_t           Ndata_bb_hodotdc_allclus_tmean;
   Double_t        bb_hodotdc_allclus_tmean[1];   //[Ndata.bb.hodotdc.allclus.tmean]
   Int_t           Ndata_bb_hodotdc_allclus_totmean;
   Double_t        bb_hodotdc_allclus_totmean[1];   //[Ndata.bb.hodotdc.allclus.totmean]
   Int_t           Ndata_bb_hodotdc_allclus_xmean;
   Double_t        bb_hodotdc_allclus_xmean[1];   //[Ndata.bb.hodotdc.allclus.xmean]
   Int_t           Ndata_bb_hodotdc_allclus_ymean;
   Double_t        bb_hodotdc_allclus_ymean[1];   //[Ndata.bb.hodotdc.allclus.ymean]
   Int_t           Ndata_bb_hodotdc_bar_tdc_L_le;
   Double_t        bb_hodotdc_bar_tdc_L_le[1];   //[Ndata.bb.hodotdc.bar.tdc.L.le]
   Int_t           Ndata_bb_hodotdc_bar_tdc_L_leW;
   Double_t        bb_hodotdc_bar_tdc_L_leW[1];   //[Ndata.bb.hodotdc.bar.tdc.L.leW]
   Int_t           Ndata_bb_hodotdc_bar_tdc_L_te;
   Double_t        bb_hodotdc_bar_tdc_L_te[1];   //[Ndata.bb.hodotdc.bar.tdc.L.te]
   Int_t           Ndata_bb_hodotdc_bar_tdc_L_teW;
   Double_t        bb_hodotdc_bar_tdc_L_teW[1];   //[Ndata.bb.hodotdc.bar.tdc.L.teW]
   Int_t           Ndata_bb_hodotdc_bar_tdc_L_tot;
   Double_t        bb_hodotdc_bar_tdc_L_tot[1];   //[Ndata.bb.hodotdc.bar.tdc.L.tot]
   Int_t           Ndata_bb_hodotdc_bar_tdc_L_totW;
   Double_t        bb_hodotdc_bar_tdc_L_totW[1];   //[Ndata.bb.hodotdc.bar.tdc.L.totW]
   Int_t           Ndata_bb_hodotdc_bar_tdc_R_le;
   Double_t        bb_hodotdc_bar_tdc_R_le[1];   //[Ndata.bb.hodotdc.bar.tdc.R.le]
   Int_t           Ndata_bb_hodotdc_bar_tdc_R_leW;
   Double_t        bb_hodotdc_bar_tdc_R_leW[1];   //[Ndata.bb.hodotdc.bar.tdc.R.leW]
   Int_t           Ndata_bb_hodotdc_bar_tdc_R_te;
   Double_t        bb_hodotdc_bar_tdc_R_te[1];   //[Ndata.bb.hodotdc.bar.tdc.R.te]
   Int_t           Ndata_bb_hodotdc_bar_tdc_R_teW;
   Double_t        bb_hodotdc_bar_tdc_R_teW[1];   //[Ndata.bb.hodotdc.bar.tdc.R.teW]
   Int_t           Ndata_bb_hodotdc_bar_tdc_R_tot;
   Double_t        bb_hodotdc_bar_tdc_R_tot[1];   //[Ndata.bb.hodotdc.bar.tdc.R.tot]
   Int_t           Ndata_bb_hodotdc_bar_tdc_R_totW;
   Double_t        bb_hodotdc_bar_tdc_R_totW[1];   //[Ndata.bb.hodotdc.bar.tdc.R.totW]
   Int_t           Ndata_bb_hodotdc_bar_tdc_id;
   Double_t        bb_hodotdc_bar_tdc_id[1];   //[Ndata.bb.hodotdc.bar.tdc.id]
   Int_t           Ndata_bb_hodotdc_bar_tdc_meantime;
   Double_t        bb_hodotdc_bar_tdc_meantime[1];   //[Ndata.bb.hodotdc.bar.tdc.meantime]
   Int_t           Ndata_bb_hodotdc_bar_tdc_timediff;
   Double_t        bb_hodotdc_bar_tdc_timediff[1];   //[Ndata.bb.hodotdc.bar.tdc.timediff]
   Int_t           Ndata_bb_hodotdc_bar_tdc_timehitpos;
   Double_t        bb_hodotdc_bar_tdc_timehitpos[1];   //[Ndata.bb.hodotdc.bar.tdc.timehitpos]
   Int_t           Ndata_bb_hodotdc_bar_tdc_vpos;
   Double_t        bb_hodotdc_bar_tdc_vpos[1];   //[Ndata.bb.hodotdc.bar.tdc.vpos]
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
   Double_t        bb_hodotdc_tdc[164];   //[Ndata.bb.hodotdc.tdc]
   Int_t           Ndata_bb_hodotdc_tdc_mult;
   Double_t        bb_hodotdc_tdc_mult[164];   //[Ndata.bb.hodotdc.tdc_mult]
   Int_t           Ndata_bb_hodotdc_tdc_te;
   Double_t        bb_hodotdc_tdc_te[164];   //[Ndata.bb.hodotdc.tdc_te]
   Int_t           Ndata_bb_hodotdc_tdc_tot;
   Double_t        bb_hodotdc_tdc_tot[164];   //[Ndata.bb.hodotdc.tdc_tot]
   Int_t           Ndata_bb_hodotdc_tdccol;
   Double_t        bb_hodotdc_tdccol[164];   //[Ndata.bb.hodotdc.tdccol]
   Int_t           Ndata_bb_hodotdc_tdcelemID;
   Double_t        bb_hodotdc_tdcelemID[164];   //[Ndata.bb.hodotdc.tdcelemID]
   Int_t           Ndata_bb_hodotdc_tdclayer;
   Double_t        bb_hodotdc_tdclayer[164];   //[Ndata.bb.hodotdc.tdclayer]
   Int_t           Ndata_bb_hodotdc_tdcrow;
   Double_t        bb_hodotdc_tdcrow[164];   //[Ndata.bb.hodotdc.tdcrow]
   Int_t           Ndata_bb_ps_clus_again;
   Double_t        bb_ps_clus_again[8];   //[Ndata.bb.ps.clus.again]
   Int_t           Ndata_bb_ps_clus_atime;
   Double_t        bb_ps_clus_atime[8];   //[Ndata.bb.ps.clus.atime]
   Int_t           Ndata_bb_ps_clus_col;
   Double_t        bb_ps_clus_col[8];   //[Ndata.bb.ps.clus.col]
   Int_t           Ndata_bb_ps_clus_e;
   Double_t        bb_ps_clus_e[8];   //[Ndata.bb.ps.clus.e]
   Int_t           Ndata_bb_ps_clus_eblk;
   Double_t        bb_ps_clus_eblk[8];   //[Ndata.bb.ps.clus.eblk]
   Int_t           Ndata_bb_ps_clus_id;
   Double_t        bb_ps_clus_id[8];   //[Ndata.bb.ps.clus.id]
   Int_t           Ndata_bb_ps_clus_nblk;
   Double_t        bb_ps_clus_nblk[8];   //[Ndata.bb.ps.clus.nblk]
   Int_t           Ndata_bb_ps_clus_row;
   Double_t        bb_ps_clus_row[8];   //[Ndata.bb.ps.clus.row]
   Int_t           Ndata_bb_ps_clus_tdctime;
   Double_t        bb_ps_clus_tdctime[8];   //[Ndata.bb.ps.clus.tdctime]
   Int_t           Ndata_bb_ps_clus_x;
   Double_t        bb_ps_clus_x[8];   //[Ndata.bb.ps.clus.x]
   Int_t           Ndata_bb_ps_clus_y;
   Double_t        bb_ps_clus_y[8];   //[Ndata.bb.ps.clus.y]
   Int_t           Ndata_bb_ps_clus_blk_again;
   Double_t        bb_ps_clus_blk_again[7];   //[Ndata.bb.ps.clus_blk.again]
   Int_t           Ndata_bb_ps_clus_blk_atime;
   Double_t        bb_ps_clus_blk_atime[7];   //[Ndata.bb.ps.clus_blk.atime]
   Int_t           Ndata_bb_ps_clus_blk_col;
   Double_t        bb_ps_clus_blk_col[7];   //[Ndata.bb.ps.clus_blk.col]
   Int_t           Ndata_bb_ps_clus_blk_e;
   Double_t        bb_ps_clus_blk_e[7];   //[Ndata.bb.ps.clus_blk.e]
   Int_t           Ndata_bb_ps_clus_blk_id;
   Double_t        bb_ps_clus_blk_id[7];   //[Ndata.bb.ps.clus_blk.id]
   Int_t           Ndata_bb_ps_clus_blk_row;
   Double_t        bb_ps_clus_blk_row[7];   //[Ndata.bb.ps.clus_blk.row]
   Int_t           Ndata_bb_ps_clus_blk_tdctime;
   Double_t        bb_ps_clus_blk_tdctime[7];   //[Ndata.bb.ps.clus_blk.tdctime]
   Int_t           Ndata_bb_ps_clus_blk_x;
   Double_t        bb_ps_clus_blk_x[7];   //[Ndata.bb.ps.clus_blk.x]
   Int_t           Ndata_bb_ps_clus_blk_y;
   Double_t        bb_ps_clus_blk_y[7];   //[Ndata.bb.ps.clus_blk.y]
   Int_t           Ndata_bb_sh_clus_again;
   Double_t        bb_sh_clus_again[10];   //[Ndata.bb.sh.clus.again]
   Int_t           Ndata_bb_sh_clus_atime;
   Double_t        bb_sh_clus_atime[10];   //[Ndata.bb.sh.clus.atime]
   Int_t           Ndata_bb_sh_clus_col;
   Double_t        bb_sh_clus_col[10];   //[Ndata.bb.sh.clus.col]
   Int_t           Ndata_bb_sh_clus_e;
   Double_t        bb_sh_clus_e[10];   //[Ndata.bb.sh.clus.e]
   Int_t           Ndata_bb_sh_clus_eblk;
   Double_t        bb_sh_clus_eblk[10];   //[Ndata.bb.sh.clus.eblk]
   Int_t           Ndata_bb_sh_clus_id;
   Double_t        bb_sh_clus_id[10];   //[Ndata.bb.sh.clus.id]
   Int_t           Ndata_bb_sh_clus_nblk;
   Double_t        bb_sh_clus_nblk[10];   //[Ndata.bb.sh.clus.nblk]
   Int_t           Ndata_bb_sh_clus_row;
   Double_t        bb_sh_clus_row[10];   //[Ndata.bb.sh.clus.row]
   Int_t           Ndata_bb_sh_clus_tdctime;
   Double_t        bb_sh_clus_tdctime[10];   //[Ndata.bb.sh.clus.tdctime]
   Int_t           Ndata_bb_sh_clus_x;
   Double_t        bb_sh_clus_x[10];   //[Ndata.bb.sh.clus.x]
   Int_t           Ndata_bb_sh_clus_y;
   Double_t        bb_sh_clus_y[10];   //[Ndata.bb.sh.clus.y]
   Int_t           Ndata_bb_sh_clus_blk_again;
   Double_t        bb_sh_clus_blk_again[17];   //[Ndata.bb.sh.clus_blk.again]
   Int_t           Ndata_bb_sh_clus_blk_atime;
   Double_t        bb_sh_clus_blk_atime[17];   //[Ndata.bb.sh.clus_blk.atime]
   Int_t           Ndata_bb_sh_clus_blk_col;
   Double_t        bb_sh_clus_blk_col[17];   //[Ndata.bb.sh.clus_blk.col]
   Int_t           Ndata_bb_sh_clus_blk_e;
   Double_t        bb_sh_clus_blk_e[17];   //[Ndata.bb.sh.clus_blk.e]
   Int_t           Ndata_bb_sh_clus_blk_id;
   Double_t        bb_sh_clus_blk_id[17];   //[Ndata.bb.sh.clus_blk.id]
   Int_t           Ndata_bb_sh_clus_blk_row;
   Double_t        bb_sh_clus_blk_row[17];   //[Ndata.bb.sh.clus_blk.row]
   Int_t           Ndata_bb_sh_clus_blk_tdctime;
   Double_t        bb_sh_clus_blk_tdctime[17];   //[Ndata.bb.sh.clus_blk.tdctime]
   Int_t           Ndata_bb_sh_clus_blk_x;
   Double_t        bb_sh_clus_blk_x[17];   //[Ndata.bb.sh.clus_blk.x]
   Int_t           Ndata_bb_sh_clus_blk_y;
   Double_t        bb_sh_clus_blk_y[17];   //[Ndata.bb.sh.clus_blk.y]
   Int_t           Ndata_bb_tdctrig_tdc;
   Double_t        bb_tdctrig_tdc[5];   //[Ndata.bb.tdctrig.tdc]
   Int_t           Ndata_bb_tdctrig_tdcelemID;
   Double_t        bb_tdctrig_tdcelemID[5];   //[Ndata.bb.tdctrig.tdcelemID]
   Int_t           Ndata_bb_tr_beta;
   Double_t        bb_tr_beta[3];   //[Ndata.bb.tr.beta]
   Int_t           Ndata_bb_tr_chi2;
   Double_t        bb_tr_chi2[3];   //[Ndata.bb.tr.chi2]
   Int_t           Ndata_bb_tr_d_ph;
   Double_t        bb_tr_d_ph[3];   //[Ndata.bb.tr.d_ph]
   Int_t           Ndata_bb_tr_d_th;
   Double_t        bb_tr_d_th[3];   //[Ndata.bb.tr.d_th]
   Int_t           Ndata_bb_tr_d_x;
   Double_t        bb_tr_d_x[3];   //[Ndata.bb.tr.d_x]
   Int_t           Ndata_bb_tr_d_y;
   Double_t        bb_tr_d_y[3];   //[Ndata.bb.tr.d_y]
   Int_t           Ndata_bb_tr_dbeta;
   Double_t        bb_tr_dbeta[3];   //[Ndata.bb.tr.dbeta]
   Int_t           Ndata_bb_tr_dtime;
   Double_t        bb_tr_dtime[3];   //[Ndata.bb.tr.dtime]
   Int_t           Ndata_bb_tr_flag;
   Double_t        bb_tr_flag[3];   //[Ndata.bb.tr.flag]
   Int_t           Ndata_bb_tr_ndof;
   Double_t        bb_tr_ndof[3];   //[Ndata.bb.tr.ndof]
   Int_t           Ndata_bb_tr_p;
   Double_t        bb_tr_p[3];   //[Ndata.bb.tr.p]
   Int_t           Ndata_bb_tr_pathl;
   Double_t        bb_tr_pathl[3];   //[Ndata.bb.tr.pathl]
   Int_t           Ndata_bb_tr_ph;
   Double_t        bb_tr_ph[3];   //[Ndata.bb.tr.ph]
   Int_t           Ndata_bb_tr_px;
   Double_t        bb_tr_px[3];   //[Ndata.bb.tr.px]
   Int_t           Ndata_bb_tr_py;
   Double_t        bb_tr_py[3];   //[Ndata.bb.tr.py]
   Int_t           Ndata_bb_tr_pz;
   Double_t        bb_tr_pz[3];   //[Ndata.bb.tr.pz]
   Int_t           Ndata_bb_tr_r_ph;
   Double_t        bb_tr_r_ph[3];   //[Ndata.bb.tr.r_ph]
   Int_t           Ndata_bb_tr_r_th;
   Double_t        bb_tr_r_th[3];   //[Ndata.bb.tr.r_th]
   Int_t           Ndata_bb_tr_r_x;
   Double_t        bb_tr_r_x[3];   //[Ndata.bb.tr.r_x]
   Int_t           Ndata_bb_tr_r_y;
   Double_t        bb_tr_r_y[3];   //[Ndata.bb.tr.r_y]
   Int_t           Ndata_bb_tr_tg_dp;
   Double_t        bb_tr_tg_dp[3];   //[Ndata.bb.tr.tg_dp]
   Int_t           Ndata_bb_tr_tg_ph;
   Double_t        bb_tr_tg_ph[3];   //[Ndata.bb.tr.tg_ph]
   Int_t           Ndata_bb_tr_tg_th;
   Double_t        bb_tr_tg_th[3];   //[Ndata.bb.tr.tg_th]
   Int_t           Ndata_bb_tr_tg_x;
   Double_t        bb_tr_tg_x[3];   //[Ndata.bb.tr.tg_x]
   Int_t           Ndata_bb_tr_tg_y;
   Double_t        bb_tr_tg_y[3];   //[Ndata.bb.tr.tg_y]
   Int_t           Ndata_bb_tr_th;
   Double_t        bb_tr_th[3];   //[Ndata.bb.tr.th]
   Int_t           Ndata_bb_tr_time;
   Double_t        bb_tr_time[3];   //[Ndata.bb.tr.time]
   Int_t           Ndata_bb_tr_vx;
   Double_t        bb_tr_vx[3];   //[Ndata.bb.tr.vx]
   Int_t           Ndata_bb_tr_vy;
   Double_t        bb_tr_vy[3];   //[Ndata.bb.tr.vy]
   Int_t           Ndata_bb_tr_vz;
   Double_t        bb_tr_vz[3];   //[Ndata.bb.tr.vz]
   Int_t           Ndata_bb_tr_x;
   Double_t        bb_tr_x[3];   //[Ndata.bb.tr.x]
   Int_t           Ndata_bb_tr_y;
   Double_t        bb_tr_y[3];   //[Ndata.bb.tr.y]
   Int_t           Ndata_bb_x_bcp;
   Double_t        bb_x_bcp[1];   //[Ndata.bb.x_bcp]
   Int_t           Ndata_bb_x_fcp;
   Double_t        bb_x_fcp[1];   //[Ndata.bb.x_fcp]
   Int_t           Ndata_bb_y_bcp;
   Double_t        bb_y_bcp[1];   //[Ndata.bb.y_bcp]
   Int_t           Ndata_bb_y_fcp;
   Double_t        bb_y_fcp[1];   //[Ndata.bb.y_fcp]
   Int_t           Ndata_bb_z_bcp;
   Double_t        bb_z_bcp[1];   //[Ndata.bb.z_bcp]
   Int_t           Ndata_bb_z_fcp;
   Double_t        bb_z_fcp[1];   //[Ndata.bb.z_fcp]
   Int_t           Ndata_sbs_hcal_clus_again;
   Double_t        sbs_hcal_clus_again[10];   //[Ndata.sbs.hcal.clus.again]
   Int_t           Ndata_sbs_hcal_clus_atime;
   Double_t        sbs_hcal_clus_atime[10];   //[Ndata.sbs.hcal.clus.atime]
   Int_t           Ndata_sbs_hcal_clus_col;
   Double_t        sbs_hcal_clus_col[10];   //[Ndata.sbs.hcal.clus.col]
   Int_t           Ndata_sbs_hcal_clus_e;
   Double_t        sbs_hcal_clus_e[10];   //[Ndata.sbs.hcal.clus.e]
   Int_t           Ndata_sbs_hcal_clus_eblk;
   Double_t        sbs_hcal_clus_eblk[10];   //[Ndata.sbs.hcal.clus.eblk]
   Int_t           Ndata_sbs_hcal_clus_id;
   Double_t        sbs_hcal_clus_id[10];   //[Ndata.sbs.hcal.clus.id]
   Int_t           Ndata_sbs_hcal_clus_nblk;
   Double_t        sbs_hcal_clus_nblk[10];   //[Ndata.sbs.hcal.clus.nblk]
   Int_t           Ndata_sbs_hcal_clus_row;
   Double_t        sbs_hcal_clus_row[10];   //[Ndata.sbs.hcal.clus.row]
   Int_t           Ndata_sbs_hcal_clus_tdctime;
   Double_t        sbs_hcal_clus_tdctime[10];   //[Ndata.sbs.hcal.clus.tdctime]
   Int_t           Ndata_sbs_hcal_clus_x;
   Double_t        sbs_hcal_clus_x[10];   //[Ndata.sbs.hcal.clus.x]
   Int_t           Ndata_sbs_hcal_clus_y;
   Double_t        sbs_hcal_clus_y[10];   //[Ndata.sbs.hcal.clus.y]
   Int_t           Ndata_sbs_hcal_clus_blk_again;
   Double_t        sbs_hcal_clus_blk_again[22];   //[Ndata.sbs.hcal.clus_blk.again]
   Int_t           Ndata_sbs_hcal_clus_blk_atime;
   Double_t        sbs_hcal_clus_blk_atime[22];   //[Ndata.sbs.hcal.clus_blk.atime]
   Int_t           Ndata_sbs_hcal_clus_blk_col;
   Double_t        sbs_hcal_clus_blk_col[22];   //[Ndata.sbs.hcal.clus_blk.col]
   Int_t           Ndata_sbs_hcal_clus_blk_e;
   Double_t        sbs_hcal_clus_blk_e[22];   //[Ndata.sbs.hcal.clus_blk.e]
   Int_t           Ndata_sbs_hcal_clus_blk_id;
   Double_t        sbs_hcal_clus_blk_id[22];   //[Ndata.sbs.hcal.clus_blk.id]
   Int_t           Ndata_sbs_hcal_clus_blk_row;
   Double_t        sbs_hcal_clus_blk_row[22];   //[Ndata.sbs.hcal.clus_blk.row]
   Int_t           Ndata_sbs_hcal_clus_blk_tdctime;
   Double_t        sbs_hcal_clus_blk_tdctime[22];   //[Ndata.sbs.hcal.clus_blk.tdctime]
   Int_t           Ndata_sbs_hcal_clus_blk_x;
   Double_t        sbs_hcal_clus_blk_x[22];   //[Ndata.sbs.hcal.clus_blk.x]
   Int_t           Ndata_sbs_hcal_clus_blk_y;
   Double_t        sbs_hcal_clus_blk_y[22];   //[Ndata.sbs.hcal.clus_blk.y]
   Int_t           Ndata_sbs_hcal_goodblock_atime;
   Double_t        sbs_hcal_goodblock_atime[30];   //[Ndata.sbs.hcal.goodblock.atime]
   Int_t           Ndata_sbs_hcal_goodblock_cid;
   Double_t        sbs_hcal_goodblock_cid[30];   //[Ndata.sbs.hcal.goodblock.cid]
   Int_t           Ndata_sbs_hcal_goodblock_col;
   Double_t        sbs_hcal_goodblock_col[30];   //[Ndata.sbs.hcal.goodblock.col]
   Int_t           Ndata_sbs_hcal_goodblock_e;
   Double_t        sbs_hcal_goodblock_e[30];   //[Ndata.sbs.hcal.goodblock.e]
   Int_t           Ndata_sbs_hcal_goodblock_id;
   Double_t        sbs_hcal_goodblock_id[30];   //[Ndata.sbs.hcal.goodblock.id]
   Int_t           Ndata_sbs_hcal_goodblock_row;
   Double_t        sbs_hcal_goodblock_row[30];   //[Ndata.sbs.hcal.goodblock.row]
   Int_t           Ndata_sbs_hcal_goodblock_tdctime;
   Double_t        sbs_hcal_goodblock_tdctime[30];   //[Ndata.sbs.hcal.goodblock.tdctime]
   Int_t           Ndata_sbs_hcal_goodblock_x;
   Double_t        sbs_hcal_goodblock_x[30];   //[Ndata.sbs.hcal.goodblock.x]
   Int_t           Ndata_sbs_hcal_goodblock_y;
   Double_t        sbs_hcal_goodblock_y[30];   //[Ndata.sbs.hcal.goodblock.y]
   Int_t           Ndata_sbs_trig_a_amp_p;
   Double_t        sbs_trig_a_amp_p[8];   //[Ndata.sbs.trig.a_amp_p]
   Int_t           Ndata_sbs_trig_a_p;
   Double_t        sbs_trig_a_p[8];   //[Ndata.sbs.trig.a_p]
   Int_t           Ndata_sbs_trig_a_time;
   Double_t        sbs_trig_a_time[8];   //[Ndata.sbs.trig.a_time]
   Int_t           Ndata_sbs_trig_adcelemID;
   Double_t        sbs_trig_adcelemID[8];   //[Ndata.sbs.trig.adcelemID]
   Double_t        BB_gold_beta;
   Double_t        BB_gold_dp;
   Double_t        BB_gold_index;
   Double_t        BB_gold_ok;
   Double_t        BB_gold_p;
   Double_t        BB_gold_ph;
   Double_t        BB_gold_px;
   Double_t        BB_gold_py;
   Double_t        BB_gold_pz;
   Double_t        BB_gold_th;
   Double_t        BB_gold_x;
   Double_t        BB_gold_y;
   Double_t        Lrb_BPMA_rawcur_1;
   Double_t        Lrb_BPMA_rawcur_2;
   Double_t        Lrb_BPMA_rawcur_3;
   Double_t        Lrb_BPMA_rawcur_4;
   Double_t        Lrb_BPMA_rotpos1;
   Double_t        Lrb_BPMA_rotpos2;
   Double_t        Lrb_BPMA_x;
   Double_t        Lrb_BPMA_y;
   Double_t        Lrb_BPMA_z;
   Double_t        Lrb_BPMB_rawcur_1;
   Double_t        Lrb_BPMB_rawcur_2;
   Double_t        Lrb_BPMB_rawcur_3;
   Double_t        Lrb_BPMB_rawcur_4;
   Double_t        Lrb_BPMB_rotpos1;
   Double_t        Lrb_BPMB_rotpos2;
   Double_t        Lrb_BPMB_x;
   Double_t        Lrb_BPMB_y;
   Double_t        Lrb_BPMB_z;
   Double_t        Lrb_Raster_bpma_x;
   Double_t        Lrb_Raster_bpma_y;
   Double_t        Lrb_Raster_bpma_z;
   Double_t        Lrb_Raster_bpmb_x;
   Double_t        Lrb_Raster_bpmb_y;
   Double_t        Lrb_Raster_bpmb_z;
   Double_t        Lrb_Raster_rawcur_x;
   Double_t        Lrb_Raster_rawcur_y;
   Double_t        Lrb_Raster_rawslope_x;
   Double_t        Lrb_Raster_rawslope_y;
   Double_t        Lrb_Raster_target_dir_x;
   Double_t        Lrb_Raster_target_dir_y;
   Double_t        Lrb_Raster_target_dir_z;
   Double_t        Lrb_Raster_target_x;
   Double_t        Lrb_Raster_target_y;
   Double_t        Lrb_Raster_target_z;
   Double_t        Lrb_Raster2_bpma_x;
   Double_t        Lrb_Raster2_bpma_y;
   Double_t        Lrb_Raster2_bpma_z;
   Double_t        Lrb_Raster2_bpmb_x;
   Double_t        Lrb_Raster2_bpmb_y;
   Double_t        Lrb_Raster2_bpmb_z;
   Double_t        Lrb_Raster2_rawcur_x;
   Double_t        Lrb_Raster2_rawcur_y;
   Double_t        Lrb_Raster2_rawslope_x;
   Double_t        Lrb_Raster2_rawslope_y;
   Double_t        Lrb_Raster2_target_dir_x;
   Double_t        Lrb_Raster2_target_dir_y;
   Double_t        Lrb_Raster2_target_dir_z;
   Double_t        Lrb_Raster2_target_x;
   Double_t        Lrb_Raster2_target_y;
   Double_t        Lrb_Raster2_target_z;
   Double_t        SBSrb_BPMA_rawcur_1;
   Double_t        SBSrb_BPMA_rawcur_2;
   Double_t        SBSrb_BPMA_rawcur_3;
   Double_t        SBSrb_BPMA_rawcur_4;
   Double_t        SBSrb_BPMA_rotpos1;
   Double_t        SBSrb_BPMA_rotpos2;
   Double_t        SBSrb_BPMA_x;
   Double_t        SBSrb_BPMA_y;
   Double_t        SBSrb_BPMA_z;
   Double_t        SBSrb_BPMB_rawcur_1;
   Double_t        SBSrb_BPMB_rawcur_2;
   Double_t        SBSrb_BPMB_rawcur_3;
   Double_t        SBSrb_BPMB_rawcur_4;
   Double_t        SBSrb_BPMB_rotpos1;
   Double_t        SBSrb_BPMB_rotpos2;
   Double_t        SBSrb_BPMB_x;
   Double_t        SBSrb_BPMB_y;
   Double_t        SBSrb_BPMB_z;
   Double_t        SBSrb_Raster_bpma_x;
   Double_t        SBSrb_Raster_bpma_y;
   Double_t        SBSrb_Raster_bpma_z;
   Double_t        SBSrb_Raster_bpmb_x;
   Double_t        SBSrb_Raster_bpmb_y;
   Double_t        SBSrb_Raster_bpmb_z;
   Double_t        SBSrb_Raster_rawcur_x;
   Double_t        SBSrb_Raster_rawcur_y;
   Double_t        SBSrb_Raster_rawslope_x;
   Double_t        SBSrb_Raster_rawslope_y;
   Double_t        SBSrb_Raster_target_dir_x;
   Double_t        SBSrb_Raster_target_dir_y;
   Double_t        SBSrb_Raster_target_dir_z;
   Double_t        SBSrb_Raster_target_x;
   Double_t        SBSrb_Raster_target_y;
   Double_t        SBSrb_Raster_target_z;
   Double_t        SBSrb_Raster2_bpma_x;
   Double_t        SBSrb_Raster2_bpma_y;
   Double_t        SBSrb_Raster2_bpma_z;
   Double_t        SBSrb_Raster2_bpmb_x;
   Double_t        SBSrb_Raster2_bpmb_y;
   Double_t        SBSrb_Raster2_bpmb_z;
   Double_t        SBSrb_Raster2_rawcur_x;
   Double_t        SBSrb_Raster2_rawcur_y;
   Double_t        SBSrb_Raster2_rawslope_x;
   Double_t        SBSrb_Raster2_rawslope_y;
   Double_t        SBSrb_Raster2_target_dir_x;
   Double_t        SBSrb_Raster2_target_dir_y;
   Double_t        SBSrb_Raster2_target_dir_z;
   Double_t        SBSrb_Raster2_target_x;
   Double_t        SBSrb_Raster2_target_y;
   Double_t        SBSrb_Raster2_target_z;
   Double_t        bb_gem_hit_ngoodhits;
   Double_t        bb_gem_m0_clust_nclustu;
   Double_t        bb_gem_m0_clust_nclustu_tot;
   Double_t        bb_gem_m0_clust_nclustv;
   Double_t        bb_gem_m0_clust_nclustv_tot;
   Double_t        bb_gem_m0_strip_nstrips_keep;
   Double_t        bb_gem_m0_strip_nstrips_keepU;
   Double_t        bb_gem_m0_strip_nstrips_keepV;
   Double_t        bb_gem_m0_strip_nstrips_keep_lmax;
   Double_t        bb_gem_m0_strip_nstrips_keep_lmaxU;
   Double_t        bb_gem_m0_strip_nstrips_keep_lmaxV;
   Double_t        bb_gem_m0_strip_nstripsfired;
   Double_t        bb_gem_m1_clust_nclustu;
   Double_t        bb_gem_m1_clust_nclustu_tot;
   Double_t        bb_gem_m1_clust_nclustv;
   Double_t        bb_gem_m1_clust_nclustv_tot;
   Double_t        bb_gem_m1_strip_nstrips_keep;
   Double_t        bb_gem_m1_strip_nstrips_keepU;
   Double_t        bb_gem_m1_strip_nstrips_keepV;
   Double_t        bb_gem_m1_strip_nstrips_keep_lmax;
   Double_t        bb_gem_m1_strip_nstrips_keep_lmaxU;
   Double_t        bb_gem_m1_strip_nstrips_keep_lmaxV;
   Double_t        bb_gem_m1_strip_nstripsfired;
   Double_t        bb_gem_m2_clust_nclustu;
   Double_t        bb_gem_m2_clust_nclustu_tot;
   Double_t        bb_gem_m2_clust_nclustv;
   Double_t        bb_gem_m2_clust_nclustv_tot;
   Double_t        bb_gem_m2_strip_nstrips_keep;
   Double_t        bb_gem_m2_strip_nstrips_keepU;
   Double_t        bb_gem_m2_strip_nstrips_keepV;
   Double_t        bb_gem_m2_strip_nstrips_keep_lmax;
   Double_t        bb_gem_m2_strip_nstrips_keep_lmaxU;
   Double_t        bb_gem_m2_strip_nstrips_keep_lmaxV;
   Double_t        bb_gem_m2_strip_nstripsfired;
   Double_t        bb_gem_m3_clust_nclustu;
   Double_t        bb_gem_m3_clust_nclustu_tot;
   Double_t        bb_gem_m3_clust_nclustv;
   Double_t        bb_gem_m3_clust_nclustv_tot;
   Double_t        bb_gem_m3_strip_nstrips_keep;
   Double_t        bb_gem_m3_strip_nstrips_keepU;
   Double_t        bb_gem_m3_strip_nstrips_keepV;
   Double_t        bb_gem_m3_strip_nstrips_keep_lmax;
   Double_t        bb_gem_m3_strip_nstrips_keep_lmaxU;
   Double_t        bb_gem_m3_strip_nstrips_keep_lmaxV;
   Double_t        bb_gem_m3_strip_nstripsfired;
   Double_t        bb_gem_m4_clust_nclustu;
   Double_t        bb_gem_m4_clust_nclustu_tot;
   Double_t        bb_gem_m4_clust_nclustv;
   Double_t        bb_gem_m4_clust_nclustv_tot;
   Double_t        bb_gem_m4_strip_nstrips_keep;
   Double_t        bb_gem_m4_strip_nstrips_keepU;
   Double_t        bb_gem_m4_strip_nstrips_keepV;
   Double_t        bb_gem_m4_strip_nstrips_keep_lmax;
   Double_t        bb_gem_m4_strip_nstrips_keep_lmaxU;
   Double_t        bb_gem_m4_strip_nstrips_keep_lmaxV;
   Double_t        bb_gem_m4_strip_nstripsfired;
   Double_t        bb_gem_m5_clust_nclustu;
   Double_t        bb_gem_m5_clust_nclustu_tot;
   Double_t        bb_gem_m5_clust_nclustv;
   Double_t        bb_gem_m5_clust_nclustv_tot;
   Double_t        bb_gem_m5_strip_nstrips_keep;
   Double_t        bb_gem_m5_strip_nstrips_keepU;
   Double_t        bb_gem_m5_strip_nstrips_keepV;
   Double_t        bb_gem_m5_strip_nstrips_keep_lmax;
   Double_t        bb_gem_m5_strip_nstrips_keep_lmaxU;
   Double_t        bb_gem_m5_strip_nstrips_keep_lmaxV;
   Double_t        bb_gem_m5_strip_nstripsfired;
   Double_t        bb_gem_m6_clust_nclustu;
   Double_t        bb_gem_m6_clust_nclustu_tot;
   Double_t        bb_gem_m6_clust_nclustv;
   Double_t        bb_gem_m6_clust_nclustv_tot;
   Double_t        bb_gem_m6_strip_nstrips_keep;
   Double_t        bb_gem_m6_strip_nstrips_keepU;
   Double_t        bb_gem_m6_strip_nstrips_keepV;
   Double_t        bb_gem_m6_strip_nstrips_keep_lmax;
   Double_t        bb_gem_m6_strip_nstrips_keep_lmaxU;
   Double_t        bb_gem_m6_strip_nstrips_keep_lmaxV;
   Double_t        bb_gem_m6_strip_nstripsfired;
   Double_t        bb_gem_m7_clust_nclustu;
   Double_t        bb_gem_m7_clust_nclustu_tot;
   Double_t        bb_gem_m7_clust_nclustv;
   Double_t        bb_gem_m7_clust_nclustv_tot;
   Double_t        bb_gem_m7_strip_nstrips_keep;
   Double_t        bb_gem_m7_strip_nstrips_keepU;
   Double_t        bb_gem_m7_strip_nstrips_keepV;
   Double_t        bb_gem_m7_strip_nstrips_keep_lmax;
   Double_t        bb_gem_m7_strip_nstrips_keep_lmaxU;
   Double_t        bb_gem_m7_strip_nstrips_keep_lmaxV;
   Double_t        bb_gem_m7_strip_nstripsfired;
   Double_t        bb_gem_nlayershit;
   Double_t        bb_gem_nlayershitu;
   Double_t        bb_gem_nlayershituv;
   Double_t        bb_gem_nlayershitv;
   Double_t        bb_gem_track_besttrack;
   Double_t        bb_gem_track_ntrack;
   Double_t        bb_gem_trigtime;
   Double_t        bb_grinch_tdc_bestcluster;
   Double_t        bb_grinch_tdc_clus_adc;
   Double_t        bb_grinch_tdc_clus_dx;
   Double_t        bb_grinch_tdc_clus_dy;
   Double_t        bb_grinch_tdc_clus_mirrorindex;
   Double_t        bb_grinch_tdc_clus_size;
   Double_t        bb_grinch_tdc_clus_t_mean;
   Double_t        bb_grinch_tdc_clus_t_rms;
   Double_t        bb_grinch_tdc_clus_tot_mean;
   Double_t        bb_grinch_tdc_clus_trackindex;
   Double_t        bb_grinch_tdc_clus_x_mean;
   Double_t        bb_grinch_tdc_clus_y_mean;
   Double_t        bb_grinch_tdc_nclus;
   Double_t        bb_grinch_tdc_ngoodhits;
   Double_t        bb_grinch_tdc_ntrackmatch;
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
   Double_t        bb_ps_againblk;
   Double_t        bb_ps_atimeblk;
   Double_t        bb_ps_colblk;
   Double_t        bb_ps_e;
   Double_t        bb_ps_eblk;
   Double_t        bb_ps_idblk;
   Double_t        bb_ps_index;
   Double_t        bb_ps_nblk;
   Double_t        bb_ps_nclus;
   Double_t        bb_ps_ngoodADChits;
   Double_t        bb_ps_rowblk;
   Double_t        bb_ps_x;
   Double_t        bb_ps_y;
   Double_t        bb_sh_againblk;
   Double_t        bb_sh_atimeblk;
   Double_t        bb_sh_colblk;
   Double_t        bb_sh_e;
   Double_t        bb_sh_eblk;
   Double_t        bb_sh_idblk;
   Double_t        bb_sh_index;
   Double_t        bb_sh_nblk;
   Double_t        bb_sh_nclus;
   Double_t        bb_sh_ngoodADChits;
   Double_t        bb_sh_rowblk;
   Double_t        bb_sh_x;
   Double_t        bb_sh_y;
   Double_t        bb_tr_n;
   Double_t        bb_ts_over_threshold;
   Double_t        e_kine_Q2;
   Double_t        e_kine_W2;
   Double_t        e_kine_angle;
   Double_t        e_kine_epsilon;
   Double_t        e_kine_nu;
   Double_t        e_kine_omega;
   Double_t        e_kine_ph_q;
   Double_t        e_kine_q3m;
   Double_t        e_kine_q_x;
   Double_t        e_kine_q_y;
   Double_t        e_kine_q_z;
   Double_t        e_kine_th_q;
   Double_t        e_kine_x_bj;
   Double_t        g_datatype;
   Double_t        g_evlen;
   Double_t        g_evnum;
   Double_t        g_evtime;
   Double_t        g_evtyp;
   Double_t        g_runnum;
   Double_t        g_runtime;
   Double_t        g_runtype;
   Double_t        g_trigbits;
   Double_t        sbs_hcal_againblk;
   Double_t        sbs_hcal_atimeblk;
   Double_t        sbs_hcal_colblk;
   Double_t        sbs_hcal_e;
   Double_t        sbs_hcal_eblk;
   Double_t        sbs_hcal_idblk;
   Double_t        sbs_hcal_index;
   Double_t        sbs_hcal_nblk;
   Double_t        sbs_hcal_nclus;
   Double_t        sbs_hcal_ngoodADChits;
   Double_t        sbs_hcal_rowblk;
   Double_t        sbs_hcal_tdctimeblk;
   Double_t        sbs_hcal_x;
   Double_t        sbs_hcal_y;
   Double_t        scalhel_errcode;
   Double_t        scalhel_evtcount;
   Double_t        scalhel_hel;
   Double_t        scalhel_lhrs_fadc_hel;
   Double_t        scalhel_lhrs_fadc_pat;
   Double_t        scalhel_lhrs_fadc_tsettle;
   Double_t        scalhel_patcount;
   Double_t        scalhel_patphase;
   Double_t        scalhel_seed;
   Double_t        singletrack_bb;
   Double_t        anytrack_bb;
   Double_t        HALLA_p;
   Double_t        hac_bcm_average;
   Double_t        IPM1H04A_XPOS;
   Double_t        IPM1H04A_YPOS;
   Double_t        IPM1H04E_XPOS;
   Double_t        IPM1H04E_YPOS;
   Double_t        IGL1I00OD16_16;
 //THaEvent        *Event_Branch;
   ULong64_t       fEvtHdr_fEvtTime;
   UInt_t          fEvtHdr_fEvtNum;
   UInt_t          fEvtHdr_fEvtType;
   UInt_t          fEvtHdr_fEvtLen;
   Int_t           fEvtHdr_fHelicity;
   UInt_t          fEvtHdr_fTrigBits;
   UInt_t          fEvtHdr_fRun;

   // List of branches
   TBranch        *b_rast12x;   //!
   TBranch        *b_rast12y;   //!
   TBranch        *b_rast12xmm;   //!
   TBranch        *b_rast12ymm;   //!
   TBranch        *b_ax_new;   //!
   TBranch        *b_bx_new;   //!
   TBranch        *b_ay_new;   //!
   TBranch        *b_by_new;   //!
   TBranch        *b_targx;   //!
   TBranch        *b_targy;   //!
   TBranch        *b_scalhel_true_hel;   //!
   TBranch        *b_scalhel_hel_stable;   //!
   TBranch        *b_Ndata_bb_bbtrig_a_amp_p;   //!
   TBranch        *b_bb_bbtrig_a_amp_p;   //!
   TBranch        *b_Ndata_bb_bbtrig_a_time;   //!
   TBranch        *b_bb_bbtrig_a_time;   //!
   TBranch        *b_Ndata_bb_bbtrig_adcelemID;   //!
   TBranch        *b_bb_bbtrig_adcelemID;   //!
   TBranch        *b_Ndata_bb_bbtrig_tdc;   //!
   TBranch        *b_bb_bbtrig_tdc;   //!
   TBranch        *b_Ndata_bb_bbtrig_tdcelemID;   //!
   TBranch        *b_bb_bbtrig_tdcelemID;   //!
   TBranch        *b_Ndata_bb_eps_over_etot;   //!
   TBranch        *b_bb_eps_over_etot;   //!
   TBranch        *b_Ndata_bb_etot_over_p;   //!
   TBranch        *b_bb_etot_over_p;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCU;   //!
   TBranch        *b_bb_gem_hit_ADCU;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCU_deconv;   //!
   TBranch        *b_bb_gem_hit_ADCU_deconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCV;   //!
   TBranch        *b_bb_gem_hit_ADCV;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCV_deconv;   //!
   TBranch        *b_bb_gem_hit_ADCV_deconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCasym;   //!
   TBranch        *b_bb_gem_hit_ADCasym;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCasym_deconv;   //!
   TBranch        *b_bb_gem_hit_ADCasym_deconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCavg;   //!
   TBranch        *b_bb_gem_hit_ADCavg;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCavg_deconv;   //!
   TBranch        *b_bb_gem_hit_ADCavg_deconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCfrac0_Umax;   //!
   TBranch        *b_bb_gem_hit_ADCfrac0_Umax;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCfrac0_Vmax;   //!
   TBranch        *b_bb_gem_hit_ADCfrac0_Vmax;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCfrac1_Umax;   //!
   TBranch        *b_bb_gem_hit_ADCfrac1_Umax;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCfrac1_Vmax;   //!
   TBranch        *b_bb_gem_hit_ADCfrac1_Vmax;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCfrac2_Umax;   //!
   TBranch        *b_bb_gem_hit_ADCfrac2_Umax;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCfrac2_Vmax;   //!
   TBranch        *b_bb_gem_hit_ADCfrac2_Vmax;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCfrac3_Umax;   //!
   TBranch        *b_bb_gem_hit_ADCfrac3_Umax;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCfrac3_Vmax;   //!
   TBranch        *b_bb_gem_hit_ADCfrac3_Vmax;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCfrac4_Umax;   //!
   TBranch        *b_bb_gem_hit_ADCfrac4_Umax;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCfrac4_Vmax;   //!
   TBranch        *b_bb_gem_hit_ADCfrac4_Vmax;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCfrac5_Umax;   //!
   TBranch        *b_bb_gem_hit_ADCfrac5_Umax;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCfrac5_Vmax;   //!
   TBranch        *b_bb_gem_hit_ADCfrac5_Vmax;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCmaxcomboUclust_deconv;   //!
   TBranch        *b_bb_gem_hit_ADCmaxcomboUclust_deconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCmaxcomboVclust_deconv;   //!
   TBranch        *b_bb_gem_hit_ADCmaxcomboVclust_deconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCmaxsampU;   //!
   TBranch        *b_bb_gem_hit_ADCmaxsampU;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCmaxsampUclust;   //!
   TBranch        *b_bb_gem_hit_ADCmaxsampUclust;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCmaxsampUclust_deconv;   //!
   TBranch        *b_bb_gem_hit_ADCmaxsampUclust_deconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCmaxsampV;   //!
   TBranch        *b_bb_gem_hit_ADCmaxsampV;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCmaxsampVclust;   //!
   TBranch        *b_bb_gem_hit_ADCmaxsampVclust;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCmaxsampVclust_deconv;   //!
   TBranch        *b_bb_gem_hit_ADCmaxsampVclust_deconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCmaxstripU;   //!
   TBranch        *b_bb_gem_hit_ADCmaxstripU;   //!
   TBranch        *b_Ndata_bb_gem_hit_ADCmaxstripV;   //!
   TBranch        *b_bb_gem_hit_ADCmaxstripV;   //!
   TBranch        *b_Ndata_bb_gem_hit_BUILD_ALL_SAMPLES_U;   //!
   TBranch        *b_bb_gem_hit_BUILD_ALL_SAMPLES_U;   //!
   TBranch        *b_Ndata_bb_gem_hit_BUILD_ALL_SAMPLES_V;   //!
   TBranch        *b_bb_gem_hit_BUILD_ALL_SAMPLES_V;   //!
   TBranch        *b_Ndata_bb_gem_hit_CM_GOOD_U;   //!
   TBranch        *b_bb_gem_hit_CM_GOOD_U;   //!
   TBranch        *b_Ndata_bb_gem_hit_CM_GOOD_V;   //!
   TBranch        *b_bb_gem_hit_CM_GOOD_V;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADC0_Umax;   //!
   TBranch        *b_bb_gem_hit_DeconvADC0_Umax;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADC0_Vmax;   //!
   TBranch        *b_bb_gem_hit_DeconvADC0_Vmax;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADC1_Umax;   //!
   TBranch        *b_bb_gem_hit_DeconvADC1_Umax;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADC1_Vmax;   //!
   TBranch        *b_bb_gem_hit_DeconvADC1_Vmax;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADC2_Umax;   //!
   TBranch        *b_bb_gem_hit_DeconvADC2_Umax;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADC2_Vmax;   //!
   TBranch        *b_bb_gem_hit_DeconvADC2_Vmax;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADC3_Umax;   //!
   TBranch        *b_bb_gem_hit_DeconvADC3_Umax;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADC3_Vmax;   //!
   TBranch        *b_bb_gem_hit_DeconvADC3_Vmax;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADC4_Umax;   //!
   TBranch        *b_bb_gem_hit_DeconvADC4_Umax;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADC4_Vmax;   //!
   TBranch        *b_bb_gem_hit_DeconvADC4_Vmax;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADC5_Umax;   //!
   TBranch        *b_bb_gem_hit_DeconvADC5_Umax;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADC5_Vmax;   //!
   TBranch        *b_bb_gem_hit_DeconvADC5_Vmax;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADCmaxcomboU;   //!
   TBranch        *b_bb_gem_hit_DeconvADCmaxcomboU;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADCmaxcomboV;   //!
   TBranch        *b_bb_gem_hit_DeconvADCmaxcomboV;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADCmaxsampU;   //!
   TBranch        *b_bb_gem_hit_DeconvADCmaxsampU;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADCmaxsampV;   //!
   TBranch        *b_bb_gem_hit_DeconvADCmaxsampV;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADCmaxstripU;   //!
   TBranch        *b_bb_gem_hit_DeconvADCmaxstripU;   //!
   TBranch        *b_Ndata_bb_gem_hit_DeconvADCmaxstripV;   //!
   TBranch        *b_bb_gem_hit_DeconvADCmaxstripV;   //!
   TBranch        *b_Ndata_bb_gem_hit_ENABLE_CM_U;   //!
   TBranch        *b_bb_gem_hit_ENABLE_CM_U;   //!
   TBranch        *b_Ndata_bb_gem_hit_ENABLE_CM_V;   //!
   TBranch        *b_bb_gem_hit_ENABLE_CM_V;   //!
   TBranch        *b_Ndata_bb_gem_hit_TSchi2_Umax;   //!
   TBranch        *b_bb_gem_hit_TSchi2_Umax;   //!
   TBranch        *b_Ndata_bb_gem_hit_TSchi2_Vmax;   //!
   TBranch        *b_bb_gem_hit_TSchi2_Vmax;   //!
   TBranch        *b_Ndata_bb_gem_hit_TSprob_Umax;   //!
   TBranch        *b_bb_gem_hit_TSprob_Umax;   //!
   TBranch        *b_Ndata_bb_gem_hit_TSprob_Vmax;   //!
   TBranch        *b_bb_gem_hit_TSprob_Vmax;   //!
   TBranch        *b_Ndata_bb_gem_hit_Tavg;   //!
   TBranch        *b_bb_gem_hit_Tavg;   //!
   TBranch        *b_Ndata_bb_gem_hit_Tavg_corr;   //!
   TBranch        *b_bb_gem_hit_Tavg_corr;   //!
   TBranch        *b_Ndata_bb_gem_hit_Tavg_deconv;   //!
   TBranch        *b_bb_gem_hit_Tavg_deconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_Tavg_fit;   //!
   TBranch        *b_bb_gem_hit_Tavg_fit;   //!
   TBranch        *b_Ndata_bb_gem_hit_Ugain;   //!
   TBranch        *b_bb_gem_hit_Ugain;   //!
   TBranch        *b_Ndata_bb_gem_hit_Utime;   //!
   TBranch        *b_bb_gem_hit_Utime;   //!
   TBranch        *b_Ndata_bb_gem_hit_UtimeDeconv;   //!
   TBranch        *b_bb_gem_hit_UtimeDeconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_UtimeFit;   //!
   TBranch        *b_bb_gem_hit_UtimeFit;   //!
   TBranch        *b_Ndata_bb_gem_hit_UtimeMaxStrip;   //!
   TBranch        *b_bb_gem_hit_UtimeMaxStrip;   //!
   TBranch        *b_Ndata_bb_gem_hit_UtimeMaxStripDeconv;   //!
   TBranch        *b_bb_gem_hit_UtimeMaxStripDeconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_UtimeMaxStripFit;   //!
   TBranch        *b_bb_gem_hit_UtimeMaxStripFit;   //!
   TBranch        *b_Ndata_bb_gem_hit_Vgain;   //!
   TBranch        *b_bb_gem_hit_Vgain;   //!
   TBranch        *b_Ndata_bb_gem_hit_Vtime;   //!
   TBranch        *b_bb_gem_hit_Vtime;   //!
   TBranch        *b_Ndata_bb_gem_hit_VtimeDeconv;   //!
   TBranch        *b_bb_gem_hit_VtimeDeconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_VtimeFit;   //!
   TBranch        *b_bb_gem_hit_VtimeFit;   //!
   TBranch        *b_Ndata_bb_gem_hit_VtimeMaxStrip;   //!
   TBranch        *b_bb_gem_hit_VtimeMaxStrip;   //!
   TBranch        *b_Ndata_bb_gem_hit_VtimeMaxStripDeconv;   //!
   TBranch        *b_bb_gem_hit_VtimeMaxStripDeconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_VtimeMaxStripFit;   //!
   TBranch        *b_bb_gem_hit_VtimeMaxStripFit;   //!
   TBranch        *b_Ndata_bb_gem_hit_ccor_clust;   //!
   TBranch        *b_bb_gem_hit_ccor_clust;   //!
   TBranch        *b_Ndata_bb_gem_hit_ccor_clust_deconv;   //!
   TBranch        *b_bb_gem_hit_ccor_clust_deconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_ccor_strip;   //!
   TBranch        *b_bb_gem_hit_ccor_strip;   //!
   TBranch        *b_Ndata_bb_gem_hit_ccor_strip_deconv;   //!
   TBranch        *b_bb_gem_hit_ccor_strip_deconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_deltat;   //!
   TBranch        *b_bb_gem_hit_deltat;   //!
   TBranch        *b_Ndata_bb_gem_hit_deltat_deconv;   //!
   TBranch        *b_bb_gem_hit_deltat_deconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_deltat_fit;   //!
   TBranch        *b_bb_gem_hit_deltat_fit;   //!
   TBranch        *b_Ndata_bb_gem_hit_eresidu;   //!
   TBranch        *b_bb_gem_hit_eresidu;   //!
   TBranch        *b_Ndata_bb_gem_hit_eresidv;   //!
   TBranch        *b_bb_gem_hit_eresidv;   //!
   TBranch        *b_Ndata_bb_gem_hit_icombomaxUclustDeconv;   //!
   TBranch        *b_bb_gem_hit_icombomaxUclustDeconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_icombomaxUstripDeconv;   //!
   TBranch        *b_bb_gem_hit_icombomaxUstripDeconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_icombomaxVclustDeconv;   //!
   TBranch        *b_bb_gem_hit_icombomaxVclustDeconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_icombomaxVstripDeconv;   //!
   TBranch        *b_bb_gem_hit_icombomaxVstripDeconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_isampmaxUclust;   //!
   TBranch        *b_bb_gem_hit_isampmaxUclust;   //!
   TBranch        *b_Ndata_bb_gem_hit_isampmaxUclustDeconv;   //!
   TBranch        *b_bb_gem_hit_isampmaxUclustDeconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_isampmaxUstrip;   //!
   TBranch        *b_bb_gem_hit_isampmaxUstrip;   //!
   TBranch        *b_Ndata_bb_gem_hit_isampmaxUstripDeconv;   //!
   TBranch        *b_bb_gem_hit_isampmaxUstripDeconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_isampmaxVclust;   //!
   TBranch        *b_bb_gem_hit_isampmaxVclust;   //!
   TBranch        *b_Ndata_bb_gem_hit_isampmaxVclustDeconv;   //!
   TBranch        *b_bb_gem_hit_isampmaxVclustDeconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_isampmaxVstrip;   //!
   TBranch        *b_bb_gem_hit_isampmaxVstrip;   //!
   TBranch        *b_Ndata_bb_gem_hit_isampmaxVstripDeconv;   //!
   TBranch        *b_bb_gem_hit_isampmaxVstripDeconv;   //!
   TBranch        *b_Ndata_bb_gem_hit_layer;   //!
   TBranch        *b_bb_gem_hit_layer;   //!
   TBranch        *b_Ndata_bb_gem_hit_module;   //!
   TBranch        *b_bb_gem_hit_module;   //!
   TBranch        *b_Ndata_bb_gem_hit_nstripu;   //!
   TBranch        *b_bb_gem_hit_nstripu;   //!
   TBranch        *b_Ndata_bb_gem_hit_nstripv;   //!
   TBranch        *b_bb_gem_hit_nstripv;   //!
   TBranch        *b_Ndata_bb_gem_hit_residu;   //!
   TBranch        *b_bb_gem_hit_residu;   //!
   TBranch        *b_Ndata_bb_gem_hit_residv;   //!
   TBranch        *b_bb_gem_hit_residv;   //!
   TBranch        *b_Ndata_bb_gem_hit_trackindex;   //!
   TBranch        *b_bb_gem_hit_trackindex;   //!
   TBranch        *b_Ndata_bb_gem_hit_u;   //!
   TBranch        *b_bb_gem_hit_u;   //!
   TBranch        *b_Ndata_bb_gem_hit_umoment;   //!
   TBranch        *b_bb_gem_hit_umoment;   //!
   TBranch        *b_Ndata_bb_gem_hit_usigma;   //!
   TBranch        *b_bb_gem_hit_usigma;   //!
   TBranch        *b_Ndata_bb_gem_hit_ustriphi;   //!
   TBranch        *b_bb_gem_hit_ustriphi;   //!
   TBranch        *b_Ndata_bb_gem_hit_ustriplo;   //!
   TBranch        *b_bb_gem_hit_ustriplo;   //!
   TBranch        *b_Ndata_bb_gem_hit_ustripmax;   //!
   TBranch        *b_bb_gem_hit_ustripmax;   //!
   TBranch        *b_Ndata_bb_gem_hit_v;   //!
   TBranch        *b_bb_gem_hit_v;   //!
   TBranch        *b_Ndata_bb_gem_hit_vmoment;   //!
   TBranch        *b_bb_gem_hit_vmoment;   //!
   TBranch        *b_Ndata_bb_gem_hit_vsigma;   //!
   TBranch        *b_bb_gem_hit_vsigma;   //!
   TBranch        *b_Ndata_bb_gem_hit_vstriphi;   //!
   TBranch        *b_bb_gem_hit_vstriphi;   //!
   TBranch        *b_Ndata_bb_gem_hit_vstriplo;   //!
   TBranch        *b_bb_gem_hit_vstriplo;   //!
   TBranch        *b_Ndata_bb_gem_hit_vstripmax;   //!
   TBranch        *b_bb_gem_hit_vstripmax;   //!
   TBranch        *b_Ndata_bb_gem_hit_xglobal;   //!
   TBranch        *b_bb_gem_hit_xglobal;   //!
   TBranch        *b_Ndata_bb_gem_hit_xlocal;   //!
   TBranch        *b_bb_gem_hit_xlocal;   //!
   TBranch        *b_Ndata_bb_gem_hit_yglobal;   //!
   TBranch        *b_bb_gem_hit_yglobal;   //!
   TBranch        *b_Ndata_bb_gem_hit_ylocal;   //!
   TBranch        *b_bb_gem_hit_ylocal;   //!
   TBranch        *b_Ndata_bb_gem_hit_zglobal;   //!
   TBranch        *b_bb_gem_hit_zglobal;   //!
   TBranch        *b_Ndata_bb_gem_n2Dhit_layer;   //!
   TBranch        *b_bb_gem_n2Dhit_layer;   //!
   TBranch        *b_Ndata_bb_gem_nclustu_layer;   //!
   TBranch        *b_bb_gem_nclustu_layer;   //!
   TBranch        *b_Ndata_bb_gem_nclustv_layer;   //!
   TBranch        *b_bb_gem_nclustv_layer;   //!
   TBranch        *b_Ndata_bb_gem_nstripsu_layer;   //!
   TBranch        *b_bb_gem_nstripsu_layer;   //!
   TBranch        *b_Ndata_bb_gem_nstripsv_layer;   //!
   TBranch        *b_bb_gem_nstripsv_layer;   //!
   TBranch        *b_Ndata_bb_gem_track_chi2ndf;   //!
   TBranch        *b_bb_gem_track_chi2ndf;   //!
   TBranch        *b_Ndata_bb_gem_track_chi2ndf_hitquality;   //!
   TBranch        *b_bb_gem_track_chi2ndf_hitquality;   //!
   TBranch        *b_Ndata_bb_gem_track_ngoodhits;   //!
   TBranch        *b_bb_gem_track_ngoodhits;   //!
   TBranch        *b_Ndata_bb_gem_track_nhits;   //!
   TBranch        *b_bb_gem_track_nhits;   //!
   TBranch        *b_Ndata_bb_gem_track_t0;   //!
   TBranch        *b_bb_gem_track_t0;   //!
   TBranch        *b_Ndata_bb_gem_track_x;   //!
   TBranch        *b_bb_gem_track_x;   //!
   TBranch        *b_Ndata_bb_gem_track_xp;   //!
   TBranch        *b_bb_gem_track_xp;   //!
   TBranch        *b_Ndata_bb_gem_track_y;   //!
   TBranch        *b_bb_gem_track_y;   //!
   TBranch        *b_Ndata_bb_gem_track_yp;   //!
   TBranch        *b_bb_gem_track_yp;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_allclus_adc;   //!
   TBranch        *b_bb_grinch_tdc_allclus_adc;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_allclus_dx;   //!
   TBranch        *b_bb_grinch_tdc_allclus_dx;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_allclus_dy;   //!
   TBranch        *b_bb_grinch_tdc_allclus_dy;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_allclus_mirrorindex;   //!
   TBranch        *b_bb_grinch_tdc_allclus_mirrorindex;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_allclus_size;   //!
   TBranch        *b_bb_grinch_tdc_allclus_size;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_allclus_t_mean;   //!
   TBranch        *b_bb_grinch_tdc_allclus_t_mean;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_allclus_t_rms;   //!
   TBranch        *b_bb_grinch_tdc_allclus_t_rms;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_allclus_tot_mean;   //!
   TBranch        *b_bb_grinch_tdc_allclus_tot_mean;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_allclus_trackindex;   //!
   TBranch        *b_bb_grinch_tdc_allclus_trackindex;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_allclus_x_mean;   //!
   TBranch        *b_bb_grinch_tdc_allclus_x_mean;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_allclus_y_mean;   //!
   TBranch        *b_bb_grinch_tdc_allclus_y_mean;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_hit_amp;   //!
   TBranch        *b_bb_grinch_tdc_hit_amp;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_hit_clustindex;   //!
   TBranch        *b_bb_grinch_tdc_hit_clustindex;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_hit_col;   //!
   TBranch        *b_bb_grinch_tdc_hit_col;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_hit_pmtnum;   //!
   TBranch        *b_bb_grinch_tdc_hit_pmtnum;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_hit_row;   //!
   TBranch        *b_bb_grinch_tdc_hit_row;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_hit_time;   //!
   TBranch        *b_bb_grinch_tdc_hit_time;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_hit_trackindex;   //!
   TBranch        *b_bb_grinch_tdc_hit_trackindex;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_hit_xhit;   //!
   TBranch        *b_bb_grinch_tdc_hit_xhit;   //!
   TBranch        *b_Ndata_bb_grinch_tdc_hit_yhit;   //!
   TBranch        *b_bb_grinch_tdc_hit_yhit;   //!
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
   TBranch        *b_Ndata_bb_ps_clus_again;   //!
   TBranch        *b_bb_ps_clus_again;   //!
   TBranch        *b_Ndata_bb_ps_clus_atime;   //!
   TBranch        *b_bb_ps_clus_atime;   //!
   TBranch        *b_Ndata_bb_ps_clus_col;   //!
   TBranch        *b_bb_ps_clus_col;   //!
   TBranch        *b_Ndata_bb_ps_clus_e;   //!
   TBranch        *b_bb_ps_clus_e;   //!
   TBranch        *b_Ndata_bb_ps_clus_eblk;   //!
   TBranch        *b_bb_ps_clus_eblk;   //!
   TBranch        *b_Ndata_bb_ps_clus_id;   //!
   TBranch        *b_bb_ps_clus_id;   //!
   TBranch        *b_Ndata_bb_ps_clus_nblk;   //!
   TBranch        *b_bb_ps_clus_nblk;   //!
   TBranch        *b_Ndata_bb_ps_clus_row;   //!
   TBranch        *b_bb_ps_clus_row;   //!
   TBranch        *b_Ndata_bb_ps_clus_tdctime;   //!
   TBranch        *b_bb_ps_clus_tdctime;   //!
   TBranch        *b_Ndata_bb_ps_clus_x;   //!
   TBranch        *b_bb_ps_clus_x;   //!
   TBranch        *b_Ndata_bb_ps_clus_y;   //!
   TBranch        *b_bb_ps_clus_y;   //!
   TBranch        *b_Ndata_bb_ps_clus_blk_again;   //!
   TBranch        *b_bb_ps_clus_blk_again;   //!
   TBranch        *b_Ndata_bb_ps_clus_blk_atime;   //!
   TBranch        *b_bb_ps_clus_blk_atime;   //!
   TBranch        *b_Ndata_bb_ps_clus_blk_col;   //!
   TBranch        *b_bb_ps_clus_blk_col;   //!
   TBranch        *b_Ndata_bb_ps_clus_blk_e;   //!
   TBranch        *b_bb_ps_clus_blk_e;   //!
   TBranch        *b_Ndata_bb_ps_clus_blk_id;   //!
   TBranch        *b_bb_ps_clus_blk_id;   //!
   TBranch        *b_Ndata_bb_ps_clus_blk_row;   //!
   TBranch        *b_bb_ps_clus_blk_row;   //!
   TBranch        *b_Ndata_bb_ps_clus_blk_tdctime;   //!
   TBranch        *b_bb_ps_clus_blk_tdctime;   //!
   TBranch        *b_Ndata_bb_ps_clus_blk_x;   //!
   TBranch        *b_bb_ps_clus_blk_x;   //!
   TBranch        *b_Ndata_bb_ps_clus_blk_y;   //!
   TBranch        *b_bb_ps_clus_blk_y;   //!
   TBranch        *b_Ndata_bb_sh_clus_again;   //!
   TBranch        *b_bb_sh_clus_again;   //!
   TBranch        *b_Ndata_bb_sh_clus_atime;   //!
   TBranch        *b_bb_sh_clus_atime;   //!
   TBranch        *b_Ndata_bb_sh_clus_col;   //!
   TBranch        *b_bb_sh_clus_col;   //!
   TBranch        *b_Ndata_bb_sh_clus_e;   //!
   TBranch        *b_bb_sh_clus_e;   //!
   TBranch        *b_Ndata_bb_sh_clus_eblk;   //!
   TBranch        *b_bb_sh_clus_eblk;   //!
   TBranch        *b_Ndata_bb_sh_clus_id;   //!
   TBranch        *b_bb_sh_clus_id;   //!
   TBranch        *b_Ndata_bb_sh_clus_nblk;   //!
   TBranch        *b_bb_sh_clus_nblk;   //!
   TBranch        *b_Ndata_bb_sh_clus_row;   //!
   TBranch        *b_bb_sh_clus_row;   //!
   TBranch        *b_Ndata_bb_sh_clus_tdctime;   //!
   TBranch        *b_bb_sh_clus_tdctime;   //!
   TBranch        *b_Ndata_bb_sh_clus_x;   //!
   TBranch        *b_bb_sh_clus_x;   //!
   TBranch        *b_Ndata_bb_sh_clus_y;   //!
   TBranch        *b_bb_sh_clus_y;   //!
   TBranch        *b_Ndata_bb_sh_clus_blk_again;   //!
   TBranch        *b_bb_sh_clus_blk_again;   //!
   TBranch        *b_Ndata_bb_sh_clus_blk_atime;   //!
   TBranch        *b_bb_sh_clus_blk_atime;   //!
   TBranch        *b_Ndata_bb_sh_clus_blk_col;   //!
   TBranch        *b_bb_sh_clus_blk_col;   //!
   TBranch        *b_Ndata_bb_sh_clus_blk_e;   //!
   TBranch        *b_bb_sh_clus_blk_e;   //!
   TBranch        *b_Ndata_bb_sh_clus_blk_id;   //!
   TBranch        *b_bb_sh_clus_blk_id;   //!
   TBranch        *b_Ndata_bb_sh_clus_blk_row;   //!
   TBranch        *b_bb_sh_clus_blk_row;   //!
   TBranch        *b_Ndata_bb_sh_clus_blk_tdctime;   //!
   TBranch        *b_bb_sh_clus_blk_tdctime;   //!
   TBranch        *b_Ndata_bb_sh_clus_blk_x;   //!
   TBranch        *b_bb_sh_clus_blk_x;   //!
   TBranch        *b_Ndata_bb_sh_clus_blk_y;   //!
   TBranch        *b_bb_sh_clus_blk_y;   //!
   TBranch        *b_Ndata_bb_tdctrig_tdc;   //!
   TBranch        *b_bb_tdctrig_tdc;   //!
   TBranch        *b_Ndata_bb_tdctrig_tdcelemID;   //!
   TBranch        *b_bb_tdctrig_tdcelemID;   //!
   TBranch        *b_Ndata_bb_tr_beta;   //!
   TBranch        *b_bb_tr_beta;   //!
   TBranch        *b_Ndata_bb_tr_chi2;   //!
   TBranch        *b_bb_tr_chi2;   //!
   TBranch        *b_Ndata_bb_tr_d_ph;   //!
   TBranch        *b_bb_tr_d_ph;   //!
   TBranch        *b_Ndata_bb_tr_d_th;   //!
   TBranch        *b_bb_tr_d_th;   //!
   TBranch        *b_Ndata_bb_tr_d_x;   //!
   TBranch        *b_bb_tr_d_x;   //!
   TBranch        *b_Ndata_bb_tr_d_y;   //!
   TBranch        *b_bb_tr_d_y;   //!
   TBranch        *b_Ndata_bb_tr_dbeta;   //!
   TBranch        *b_bb_tr_dbeta;   //!
   TBranch        *b_Ndata_bb_tr_dtime;   //!
   TBranch        *b_bb_tr_dtime;   //!
   TBranch        *b_Ndata_bb_tr_flag;   //!
   TBranch        *b_bb_tr_flag;   //!
   TBranch        *b_Ndata_bb_tr_ndof;   //!
   TBranch        *b_bb_tr_ndof;   //!
   TBranch        *b_Ndata_bb_tr_p;   //!
   TBranch        *b_bb_tr_p;   //!
   TBranch        *b_Ndata_bb_tr_pathl;   //!
   TBranch        *b_bb_tr_pathl;   //!
   TBranch        *b_Ndata_bb_tr_ph;   //!
   TBranch        *b_bb_tr_ph;   //!
   TBranch        *b_Ndata_bb_tr_px;   //!
   TBranch        *b_bb_tr_px;   //!
   TBranch        *b_Ndata_bb_tr_py;   //!
   TBranch        *b_bb_tr_py;   //!
   TBranch        *b_Ndata_bb_tr_pz;   //!
   TBranch        *b_bb_tr_pz;   //!
   TBranch        *b_Ndata_bb_tr_r_ph;   //!
   TBranch        *b_bb_tr_r_ph;   //!
   TBranch        *b_Ndata_bb_tr_r_th;   //!
   TBranch        *b_bb_tr_r_th;   //!
   TBranch        *b_Ndata_bb_tr_r_x;   //!
   TBranch        *b_bb_tr_r_x;   //!
   TBranch        *b_Ndata_bb_tr_r_y;   //!
   TBranch        *b_bb_tr_r_y;   //!
   TBranch        *b_Ndata_bb_tr_tg_dp;   //!
   TBranch        *b_bb_tr_tg_dp;   //!
   TBranch        *b_Ndata_bb_tr_tg_ph;   //!
   TBranch        *b_bb_tr_tg_ph;   //!
   TBranch        *b_Ndata_bb_tr_tg_th;   //!
   TBranch        *b_bb_tr_tg_th;   //!
   TBranch        *b_Ndata_bb_tr_tg_x;   //!
   TBranch        *b_bb_tr_tg_x;   //!
   TBranch        *b_Ndata_bb_tr_tg_y;   //!
   TBranch        *b_bb_tr_tg_y;   //!
   TBranch        *b_Ndata_bb_tr_th;   //!
   TBranch        *b_bb_tr_th;   //!
   TBranch        *b_Ndata_bb_tr_time;   //!
   TBranch        *b_bb_tr_time;   //!
   TBranch        *b_Ndata_bb_tr_vx;   //!
   TBranch        *b_bb_tr_vx;   //!
   TBranch        *b_Ndata_bb_tr_vy;   //!
   TBranch        *b_bb_tr_vy;   //!
   TBranch        *b_Ndata_bb_tr_vz;   //!
   TBranch        *b_bb_tr_vz;   //!
   TBranch        *b_Ndata_bb_tr_x;   //!
   TBranch        *b_bb_tr_x;   //!
   TBranch        *b_Ndata_bb_tr_y;   //!
   TBranch        *b_bb_tr_y;   //!
   TBranch        *b_Ndata_bb_x_bcp;   //!
   TBranch        *b_bb_x_bcp;   //!
   TBranch        *b_Ndata_bb_x_fcp;   //!
   TBranch        *b_bb_x_fcp;   //!
   TBranch        *b_Ndata_bb_y_bcp;   //!
   TBranch        *b_bb_y_bcp;   //!
   TBranch        *b_Ndata_bb_y_fcp;   //!
   TBranch        *b_bb_y_fcp;   //!
   TBranch        *b_Ndata_bb_z_bcp;   //!
   TBranch        *b_bb_z_bcp;   //!
   TBranch        *b_Ndata_bb_z_fcp;   //!
   TBranch        *b_bb_z_fcp;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_again;   //!
   TBranch        *b_sbs_hcal_clus_again;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_atime;   //!
   TBranch        *b_sbs_hcal_clus_atime;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_col;   //!
   TBranch        *b_sbs_hcal_clus_col;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_e;   //!
   TBranch        *b_sbs_hcal_clus_e;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_eblk;   //!
   TBranch        *b_sbs_hcal_clus_eblk;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_id;   //!
   TBranch        *b_sbs_hcal_clus_id;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_nblk;   //!
   TBranch        *b_sbs_hcal_clus_nblk;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_row;   //!
   TBranch        *b_sbs_hcal_clus_row;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_tdctime;   //!
   TBranch        *b_sbs_hcal_clus_tdctime;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_x;   //!
   TBranch        *b_sbs_hcal_clus_x;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_y;   //!
   TBranch        *b_sbs_hcal_clus_y;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_blk_again;   //!
   TBranch        *b_sbs_hcal_clus_blk_again;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_blk_atime;   //!
   TBranch        *b_sbs_hcal_clus_blk_atime;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_blk_col;   //!
   TBranch        *b_sbs_hcal_clus_blk_col;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_blk_e;   //!
   TBranch        *b_sbs_hcal_clus_blk_e;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_blk_id;   //!
   TBranch        *b_sbs_hcal_clus_blk_id;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_blk_row;   //!
   TBranch        *b_sbs_hcal_clus_blk_row;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_blk_tdctime;   //!
   TBranch        *b_sbs_hcal_clus_blk_tdctime;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_blk_x;   //!
   TBranch        *b_sbs_hcal_clus_blk_x;   //!
   TBranch        *b_Ndata_sbs_hcal_clus_blk_y;   //!
   TBranch        *b_sbs_hcal_clus_blk_y;   //!
   TBranch        *b_Ndata_sbs_hcal_goodblock_atime;   //!
   TBranch        *b_sbs_hcal_goodblock_atime;   //!
   TBranch        *b_Ndata_sbs_hcal_goodblock_cid;   //!
   TBranch        *b_sbs_hcal_goodblock_cid;   //!
   TBranch        *b_Ndata_sbs_hcal_goodblock_col;   //!
   TBranch        *b_sbs_hcal_goodblock_col;   //!
   TBranch        *b_Ndata_sbs_hcal_goodblock_e;   //!
   TBranch        *b_sbs_hcal_goodblock_e;   //!
   TBranch        *b_Ndata_sbs_hcal_goodblock_id;   //!
   TBranch        *b_sbs_hcal_goodblock_id;   //!
   TBranch        *b_Ndata_sbs_hcal_goodblock_row;   //!
   TBranch        *b_sbs_hcal_goodblock_row;   //!
   TBranch        *b_Ndata_sbs_hcal_goodblock_tdctime;   //!
   TBranch        *b_sbs_hcal_goodblock_tdctime;   //!
   TBranch        *b_Ndata_sbs_hcal_goodblock_x;   //!
   TBranch        *b_sbs_hcal_goodblock_x;   //!
   TBranch        *b_Ndata_sbs_hcal_goodblock_y;   //!
   TBranch        *b_sbs_hcal_goodblock_y;   //!
   TBranch        *b_Ndata_sbs_trig_a_amp_p;   //!
   TBranch        *b_sbs_trig_a_amp_p;   //!
   TBranch        *b_Ndata_sbs_trig_a_p;   //!
   TBranch        *b_sbs_trig_a_p;   //!
   TBranch        *b_Ndata_sbs_trig_a_time;   //!
   TBranch        *b_sbs_trig_a_time;   //!
   TBranch        *b_Ndata_sbs_trig_adcelemID;   //!
   TBranch        *b_sbs_trig_adcelemID;   //!
   TBranch        *b_BB_gold_beta;   //!
   TBranch        *b_BB_gold_dp;   //!
   TBranch        *b_BB_gold_index;   //!
   TBranch        *b_BB_gold_ok;   //!
   TBranch        *b_BB_gold_p;   //!
   TBranch        *b_BB_gold_ph;   //!
   TBranch        *b_BB_gold_px;   //!
   TBranch        *b_BB_gold_py;   //!
   TBranch        *b_BB_gold_pz;   //!
   TBranch        *b_BB_gold_th;   //!
   TBranch        *b_BB_gold_x;   //!
   TBranch        *b_BB_gold_y;   //!
   TBranch        *b_Lrb_BPMA_rawcur_1;   //!
   TBranch        *b_Lrb_BPMA_rawcur_2;   //!
   TBranch        *b_Lrb_BPMA_rawcur_3;   //!
   TBranch        *b_Lrb_BPMA_rawcur_4;   //!
   TBranch        *b_Lrb_BPMA_rotpos1;   //!
   TBranch        *b_Lrb_BPMA_rotpos2;   //!
   TBranch        *b_Lrb_BPMA_x;   //!
   TBranch        *b_Lrb_BPMA_y;   //!
   TBranch        *b_Lrb_BPMA_z;   //!
   TBranch        *b_Lrb_BPMB_rawcur_1;   //!
   TBranch        *b_Lrb_BPMB_rawcur_2;   //!
   TBranch        *b_Lrb_BPMB_rawcur_3;   //!
   TBranch        *b_Lrb_BPMB_rawcur_4;   //!
   TBranch        *b_Lrb_BPMB_rotpos1;   //!
   TBranch        *b_Lrb_BPMB_rotpos2;   //!
   TBranch        *b_Lrb_BPMB_x;   //!
   TBranch        *b_Lrb_BPMB_y;   //!
   TBranch        *b_Lrb_BPMB_z;   //!
   TBranch        *b_Lrb_Raster_bpma_x;   //!
   TBranch        *b_Lrb_Raster_bpma_y;   //!
   TBranch        *b_Lrb_Raster_bpma_z;   //!
   TBranch        *b_Lrb_Raster_bpmb_x;   //!
   TBranch        *b_Lrb_Raster_bpmb_y;   //!
   TBranch        *b_Lrb_Raster_bpmb_z;   //!
   TBranch        *b_Lrb_Raster_rawcur_x;   //!
   TBranch        *b_Lrb_Raster_rawcur_y;   //!
   TBranch        *b_Lrb_Raster_rawslope_x;   //!
   TBranch        *b_Lrb_Raster_rawslope_y;   //!
   TBranch        *b_Lrb_Raster_target_dir_x;   //!
   TBranch        *b_Lrb_Raster_target_dir_y;   //!
   TBranch        *b_Lrb_Raster_target_dir_z;   //!
   TBranch        *b_Lrb_Raster_target_x;   //!
   TBranch        *b_Lrb_Raster_target_y;   //!
   TBranch        *b_Lrb_Raster_target_z;   //!
   TBranch        *b_Lrb_Raster2_bpma_x;   //!
   TBranch        *b_Lrb_Raster2_bpma_y;   //!
   TBranch        *b_Lrb_Raster2_bpma_z;   //!
   TBranch        *b_Lrb_Raster2_bpmb_x;   //!
   TBranch        *b_Lrb_Raster2_bpmb_y;   //!
   TBranch        *b_Lrb_Raster2_bpmb_z;   //!
   TBranch        *b_Lrb_Raster2_rawcur_x;   //!
   TBranch        *b_Lrb_Raster2_rawcur_y;   //!
   TBranch        *b_Lrb_Raster2_rawslope_x;   //!
   TBranch        *b_Lrb_Raster2_rawslope_y;   //!
   TBranch        *b_Lrb_Raster2_target_dir_x;   //!
   TBranch        *b_Lrb_Raster2_target_dir_y;   //!
   TBranch        *b_Lrb_Raster2_target_dir_z;   //!
   TBranch        *b_Lrb_Raster2_target_x;   //!
   TBranch        *b_Lrb_Raster2_target_y;   //!
   TBranch        *b_Lrb_Raster2_target_z;   //!
   TBranch        *b_SBSrb_BPMA_rawcur_1;   //!
   TBranch        *b_SBSrb_BPMA_rawcur_2;   //!
   TBranch        *b_SBSrb_BPMA_rawcur_3;   //!
   TBranch        *b_SBSrb_BPMA_rawcur_4;   //!
   TBranch        *b_SBSrb_BPMA_rotpos1;   //!
   TBranch        *b_SBSrb_BPMA_rotpos2;   //!
   TBranch        *b_SBSrb_BPMA_x;   //!
   TBranch        *b_SBSrb_BPMA_y;   //!
   TBranch        *b_SBSrb_BPMA_z;   //!
   TBranch        *b_SBSrb_BPMB_rawcur_1;   //!
   TBranch        *b_SBSrb_BPMB_rawcur_2;   //!
   TBranch        *b_SBSrb_BPMB_rawcur_3;   //!
   TBranch        *b_SBSrb_BPMB_rawcur_4;   //!
   TBranch        *b_SBSrb_BPMB_rotpos1;   //!
   TBranch        *b_SBSrb_BPMB_rotpos2;   //!
   TBranch        *b_SBSrb_BPMB_x;   //!
   TBranch        *b_SBSrb_BPMB_y;   //!
   TBranch        *b_SBSrb_BPMB_z;   //!
   TBranch        *b_SBSrb_Raster_bpma_x;   //!
   TBranch        *b_SBSrb_Raster_bpma_y;   //!
   TBranch        *b_SBSrb_Raster_bpma_z;   //!
   TBranch        *b_SBSrb_Raster_bpmb_x;   //!
   TBranch        *b_SBSrb_Raster_bpmb_y;   //!
   TBranch        *b_SBSrb_Raster_bpmb_z;   //!
   TBranch        *b_SBSrb_Raster_rawcur_x;   //!
   TBranch        *b_SBSrb_Raster_rawcur_y;   //!
   TBranch        *b_SBSrb_Raster_rawslope_x;   //!
   TBranch        *b_SBSrb_Raster_rawslope_y;   //!
   TBranch        *b_SBSrb_Raster_target_dir_x;   //!
   TBranch        *b_SBSrb_Raster_target_dir_y;   //!
   TBranch        *b_SBSrb_Raster_target_dir_z;   //!
   TBranch        *b_SBSrb_Raster_target_x;   //!
   TBranch        *b_SBSrb_Raster_target_y;   //!
   TBranch        *b_SBSrb_Raster_target_z;   //!
   TBranch        *b_SBSrb_Raster2_bpma_x;   //!
   TBranch        *b_SBSrb_Raster2_bpma_y;   //!
   TBranch        *b_SBSrb_Raster2_bpma_z;   //!
   TBranch        *b_SBSrb_Raster2_bpmb_x;   //!
   TBranch        *b_SBSrb_Raster2_bpmb_y;   //!
   TBranch        *b_SBSrb_Raster2_bpmb_z;   //!
   TBranch        *b_SBSrb_Raster2_rawcur_x;   //!
   TBranch        *b_SBSrb_Raster2_rawcur_y;   //!
   TBranch        *b_SBSrb_Raster2_rawslope_x;   //!
   TBranch        *b_SBSrb_Raster2_rawslope_y;   //!
   TBranch        *b_SBSrb_Raster2_target_dir_x;   //!
   TBranch        *b_SBSrb_Raster2_target_dir_y;   //!
   TBranch        *b_SBSrb_Raster2_target_dir_z;   //!
   TBranch        *b_SBSrb_Raster2_target_x;   //!
   TBranch        *b_SBSrb_Raster2_target_y;   //!
   TBranch        *b_SBSrb_Raster2_target_z;   //!
   TBranch        *b_bb_gem_hit_ngoodhits;   //!
   TBranch        *b_bb_gem_m0_clust_nclustu;   //!
   TBranch        *b_bb_gem_m0_clust_nclustu_tot;   //!
   TBranch        *b_bb_gem_m0_clust_nclustv;   //!
   TBranch        *b_bb_gem_m0_clust_nclustv_tot;   //!
   TBranch        *b_bb_gem_m0_strip_nstrips_keep;   //!
   TBranch        *b_bb_gem_m0_strip_nstrips_keepU;   //!
   TBranch        *b_bb_gem_m0_strip_nstrips_keepV;   //!
   TBranch        *b_bb_gem_m0_strip_nstrips_keep_lmax;   //!
   TBranch        *b_bb_gem_m0_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_bb_gem_m0_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_bb_gem_m0_strip_nstripsfired;   //!
   TBranch        *b_bb_gem_m1_clust_nclustu;   //!
   TBranch        *b_bb_gem_m1_clust_nclustu_tot;   //!
   TBranch        *b_bb_gem_m1_clust_nclustv;   //!
   TBranch        *b_bb_gem_m1_clust_nclustv_tot;   //!
   TBranch        *b_bb_gem_m1_strip_nstrips_keep;   //!
   TBranch        *b_bb_gem_m1_strip_nstrips_keepU;   //!
   TBranch        *b_bb_gem_m1_strip_nstrips_keepV;   //!
   TBranch        *b_bb_gem_m1_strip_nstrips_keep_lmax;   //!
   TBranch        *b_bb_gem_m1_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_bb_gem_m1_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_bb_gem_m1_strip_nstripsfired;   //!
   TBranch        *b_bb_gem_m2_clust_nclustu;   //!
   TBranch        *b_bb_gem_m2_clust_nclustu_tot;   //!
   TBranch        *b_bb_gem_m2_clust_nclustv;   //!
   TBranch        *b_bb_gem_m2_clust_nclustv_tot;   //!
   TBranch        *b_bb_gem_m2_strip_nstrips_keep;   //!
   TBranch        *b_bb_gem_m2_strip_nstrips_keepU;   //!
   TBranch        *b_bb_gem_m2_strip_nstrips_keepV;   //!
   TBranch        *b_bb_gem_m2_strip_nstrips_keep_lmax;   //!
   TBranch        *b_bb_gem_m2_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_bb_gem_m2_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_bb_gem_m2_strip_nstripsfired;   //!
   TBranch        *b_bb_gem_m3_clust_nclustu;   //!
   TBranch        *b_bb_gem_m3_clust_nclustu_tot;   //!
   TBranch        *b_bb_gem_m3_clust_nclustv;   //!
   TBranch        *b_bb_gem_m3_clust_nclustv_tot;   //!
   TBranch        *b_bb_gem_m3_strip_nstrips_keep;   //!
   TBranch        *b_bb_gem_m3_strip_nstrips_keepU;   //!
   TBranch        *b_bb_gem_m3_strip_nstrips_keepV;   //!
   TBranch        *b_bb_gem_m3_strip_nstrips_keep_lmax;   //!
   TBranch        *b_bb_gem_m3_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_bb_gem_m3_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_bb_gem_m3_strip_nstripsfired;   //!
   TBranch        *b_bb_gem_m4_clust_nclustu;   //!
   TBranch        *b_bb_gem_m4_clust_nclustu_tot;   //!
   TBranch        *b_bb_gem_m4_clust_nclustv;   //!
   TBranch        *b_bb_gem_m4_clust_nclustv_tot;   //!
   TBranch        *b_bb_gem_m4_strip_nstrips_keep;   //!
   TBranch        *b_bb_gem_m4_strip_nstrips_keepU;   //!
   TBranch        *b_bb_gem_m4_strip_nstrips_keepV;   //!
   TBranch        *b_bb_gem_m4_strip_nstrips_keep_lmax;   //!
   TBranch        *b_bb_gem_m4_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_bb_gem_m4_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_bb_gem_m4_strip_nstripsfired;   //!
   TBranch        *b_bb_gem_m5_clust_nclustu;   //!
   TBranch        *b_bb_gem_m5_clust_nclustu_tot;   //!
   TBranch        *b_bb_gem_m5_clust_nclustv;   //!
   TBranch        *b_bb_gem_m5_clust_nclustv_tot;   //!
   TBranch        *b_bb_gem_m5_strip_nstrips_keep;   //!
   TBranch        *b_bb_gem_m5_strip_nstrips_keepU;   //!
   TBranch        *b_bb_gem_m5_strip_nstrips_keepV;   //!
   TBranch        *b_bb_gem_m5_strip_nstrips_keep_lmax;   //!
   TBranch        *b_bb_gem_m5_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_bb_gem_m5_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_bb_gem_m5_strip_nstripsfired;   //!
   TBranch        *b_bb_gem_m6_clust_nclustu;   //!
   TBranch        *b_bb_gem_m6_clust_nclustu_tot;   //!
   TBranch        *b_bb_gem_m6_clust_nclustv;   //!
   TBranch        *b_bb_gem_m6_clust_nclustv_tot;   //!
   TBranch        *b_bb_gem_m6_strip_nstrips_keep;   //!
   TBranch        *b_bb_gem_m6_strip_nstrips_keepU;   //!
   TBranch        *b_bb_gem_m6_strip_nstrips_keepV;   //!
   TBranch        *b_bb_gem_m6_strip_nstrips_keep_lmax;   //!
   TBranch        *b_bb_gem_m6_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_bb_gem_m6_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_bb_gem_m6_strip_nstripsfired;   //!
   TBranch        *b_bb_gem_m7_clust_nclustu;   //!
   TBranch        *b_bb_gem_m7_clust_nclustu_tot;   //!
   TBranch        *b_bb_gem_m7_clust_nclustv;   //!
   TBranch        *b_bb_gem_m7_clust_nclustv_tot;   //!
   TBranch        *b_bb_gem_m7_strip_nstrips_keep;   //!
   TBranch        *b_bb_gem_m7_strip_nstrips_keepU;   //!
   TBranch        *b_bb_gem_m7_strip_nstrips_keepV;   //!
   TBranch        *b_bb_gem_m7_strip_nstrips_keep_lmax;   //!
   TBranch        *b_bb_gem_m7_strip_nstrips_keep_lmaxU;   //!
   TBranch        *b_bb_gem_m7_strip_nstrips_keep_lmaxV;   //!
   TBranch        *b_bb_gem_m7_strip_nstripsfired;   //!
   TBranch        *b_bb_gem_nlayershit;   //!
   TBranch        *b_bb_gem_nlayershitu;   //!
   TBranch        *b_bb_gem_nlayershituv;   //!
   TBranch        *b_bb_gem_nlayershitv;   //!
   TBranch        *b_bb_gem_track_besttrack;   //!
   TBranch        *b_bb_gem_track_ntrack;   //!
   TBranch        *b_bb_gem_trigtime;   //!
   TBranch        *b_bb_grinch_tdc_bestcluster;   //!
   TBranch        *b_bb_grinch_tdc_clus_adc;   //!
   TBranch        *b_bb_grinch_tdc_clus_dx;   //!
   TBranch        *b_bb_grinch_tdc_clus_dy;   //!
   TBranch        *b_bb_grinch_tdc_clus_mirrorindex;   //!
   TBranch        *b_bb_grinch_tdc_clus_size;   //!
   TBranch        *b_bb_grinch_tdc_clus_t_mean;   //!
   TBranch        *b_bb_grinch_tdc_clus_t_rms;   //!
   TBranch        *b_bb_grinch_tdc_clus_tot_mean;   //!
   TBranch        *b_bb_grinch_tdc_clus_trackindex;   //!
   TBranch        *b_bb_grinch_tdc_clus_x_mean;   //!
   TBranch        *b_bb_grinch_tdc_clus_y_mean;   //!
   TBranch        *b_bb_grinch_tdc_nclus;   //!
   TBranch        *b_bb_grinch_tdc_ngoodhits;   //!
   TBranch        *b_bb_grinch_tdc_ntrackmatch;   //!
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
   TBranch        *b_bb_ps_againblk;   //!
   TBranch        *b_bb_ps_atimeblk;   //!
   TBranch        *b_bb_ps_colblk;   //!
   TBranch        *b_bb_ps_e;   //!
   TBranch        *b_bb_ps_eblk;   //!
   TBranch        *b_bb_ps_idblk;   //!
   TBranch        *b_bb_ps_index;   //!
   TBranch        *b_bb_ps_nblk;   //!
   TBranch        *b_bb_ps_nclus;   //!
   TBranch        *b_bb_ps_ngoodADChits;   //!
   TBranch        *b_bb_ps_rowblk;   //!
   TBranch        *b_bb_ps_x;   //!
   TBranch        *b_bb_ps_y;   //!
   TBranch        *b_bb_sh_againblk;   //!
   TBranch        *b_bb_sh_atimeblk;   //!
   TBranch        *b_bb_sh_colblk;   //!
   TBranch        *b_bb_sh_e;   //!
   TBranch        *b_bb_sh_eblk;   //!
   TBranch        *b_bb_sh_idblk;   //!
   TBranch        *b_bb_sh_index;   //!
   TBranch        *b_bb_sh_nblk;   //!
   TBranch        *b_bb_sh_nclus;   //!
   TBranch        *b_bb_sh_ngoodADChits;   //!
   TBranch        *b_bb_sh_rowblk;   //!
   TBranch        *b_bb_sh_x;   //!
   TBranch        *b_bb_sh_y;   //!
   TBranch        *b_bb_tr_n;   //!
   TBranch        *b_bb_ts_over_threshold;   //!
   TBranch        *b_e_kine_Q2;   //!
   TBranch        *b_e_kine_W2;   //!
   TBranch        *b_e_kine_angle;   //!
   TBranch        *b_e_kine_epsilon;   //!
   TBranch        *b_e_kine_nu;   //!
   TBranch        *b_e_kine_omega;   //!
   TBranch        *b_e_kine_ph_q;   //!
   TBranch        *b_e_kine_q3m;   //!
   TBranch        *b_e_kine_q_x;   //!
   TBranch        *b_e_kine_q_y;   //!
   TBranch        *b_e_kine_q_z;   //!
   TBranch        *b_e_kine_th_q;   //!
   TBranch        *b_e_kine_x_bj;   //!
   TBranch        *b_g_datatype;   //!
   TBranch        *b_g_evlen;   //!
   TBranch        *b_g_evnum;   //!
   TBranch        *b_g_evtime;   //!
   TBranch        *b_g_evtyp;   //!
   TBranch        *b_g_runnum;   //!
   TBranch        *b_g_runtime;   //!
   TBranch        *b_g_runtype;   //!
   TBranch        *b_g_trigbits;   //!
   TBranch        *b_sbs_hcal_againblk;   //!
   TBranch        *b_sbs_hcal_atimeblk;   //!
   TBranch        *b_sbs_hcal_colblk;   //!
   TBranch        *b_sbs_hcal_e;   //!
   TBranch        *b_sbs_hcal_eblk;   //!
   TBranch        *b_sbs_hcal_idblk;   //!
   TBranch        *b_sbs_hcal_index;   //!
   TBranch        *b_sbs_hcal_nblk;   //!
   TBranch        *b_sbs_hcal_nclus;   //!
   TBranch        *b_sbs_hcal_ngoodADChits;   //!
   TBranch        *b_sbs_hcal_rowblk;   //!
   TBranch        *b_sbs_hcal_tdctimeblk;   //!
   TBranch        *b_sbs_hcal_x;   //!
   TBranch        *b_sbs_hcal_y;   //!
   TBranch        *b_scalhel_errcode;   //!
   TBranch        *b_scalhel_evtcount;   //!
   TBranch        *b_scalhel_hel;   //!
   TBranch        *b_scalhel_lhrs_fadc_hel;   //!
   TBranch        *b_scalhel_lhrs_fadc_pat;   //!
   TBranch        *b_scalhel_lhrs_fadc_tsettle;   //!
   TBranch        *b_scalhel_patcount;   //!
   TBranch        *b_scalhel_patphase;   //!
   TBranch        *b_scalhel_seed;   //!
   TBranch        *b_singletrack_bb;   //!
   TBranch        *b_anytrack_bb;   //!
   TBranch        *b_HALLA_p;   //!
   TBranch        *b_hac_bcm_average;   //!
   TBranch        *b_IPM1H04A_XPOS;   //!
   TBranch        *b_IPM1H04A_YPOS;   //!
   TBranch        *b_IPM1H04E_XPOS;   //!
   TBranch        *b_IPM1H04E_YPOS;   //!
   TBranch        *b_IGL1I00OD16_16;   //!
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
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/volatile/halla/sbs/gpenman/GEN_REPLAY/rootfiles/Bad_EncodeTDC/e1209016_fullreplay_2095_stream0_2_seg0_0.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/volatile/halla/sbs/gpenman/GEN_REPLAY/rootfiles/Bad_EncodeTDC/e1209016_fullreplay_2095_stream0_2_seg0_0.root");
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

   fChain->SetBranchAddress("rast12x", &rast12x, &b_rast12x);
   fChain->SetBranchAddress("rast12y", &rast12y, &b_rast12y);
   fChain->SetBranchAddress("rast12xmm", &rast12xmm, &b_rast12xmm);
   fChain->SetBranchAddress("rast12ymm", &rast12ymm, &b_rast12ymm);
   fChain->SetBranchAddress("ax_new", &ax_new, &b_ax_new);
   fChain->SetBranchAddress("bx_new", &bx_new, &b_bx_new);
   fChain->SetBranchAddress("ay_new", &ay_new, &b_ay_new);
   fChain->SetBranchAddress("by_new", &by_new, &b_by_new);
   fChain->SetBranchAddress("targx", &targx, &b_targx);
   fChain->SetBranchAddress("targy", &targy, &b_targy);
   fChain->SetBranchAddress("scalhel.true_hel", &scalhel_true_hel, &b_scalhel_true_hel);
   fChain->SetBranchAddress("scalhel.hel_stable", &scalhel_hel_stable, &b_scalhel_hel_stable);
   fChain->SetBranchAddress("Ndata.bb.bbtrig.a_amp_p", &Ndata_bb_bbtrig_a_amp_p, &b_Ndata_bb_bbtrig_a_amp_p);
   fChain->SetBranchAddress("bb.bbtrig.a_amp_p", bb_bbtrig_a_amp_p, &b_bb_bbtrig_a_amp_p);
   fChain->SetBranchAddress("Ndata.bb.bbtrig.a_time", &Ndata_bb_bbtrig_a_time, &b_Ndata_bb_bbtrig_a_time);
   fChain->SetBranchAddress("bb.bbtrig.a_time", bb_bbtrig_a_time, &b_bb_bbtrig_a_time);
   fChain->SetBranchAddress("Ndata.bb.bbtrig.adcelemID", &Ndata_bb_bbtrig_adcelemID, &b_Ndata_bb_bbtrig_adcelemID);
   fChain->SetBranchAddress("bb.bbtrig.adcelemID", bb_bbtrig_adcelemID, &b_bb_bbtrig_adcelemID);
   fChain->SetBranchAddress("Ndata.bb.bbtrig.tdc", &Ndata_bb_bbtrig_tdc, &b_Ndata_bb_bbtrig_tdc);
   fChain->SetBranchAddress("bb.bbtrig.tdc", bb_bbtrig_tdc, &b_bb_bbtrig_tdc);
   fChain->SetBranchAddress("Ndata.bb.bbtrig.tdcelemID", &Ndata_bb_bbtrig_tdcelemID, &b_Ndata_bb_bbtrig_tdcelemID);
   fChain->SetBranchAddress("bb.bbtrig.tdcelemID", bb_bbtrig_tdcelemID, &b_bb_bbtrig_tdcelemID);
   fChain->SetBranchAddress("Ndata.bb.eps_over_etot", &Ndata_bb_eps_over_etot, &b_Ndata_bb_eps_over_etot);
   fChain->SetBranchAddress("bb.eps_over_etot", bb_eps_over_etot, &b_bb_eps_over_etot);
   fChain->SetBranchAddress("Ndata.bb.etot_over_p", &Ndata_bb_etot_over_p, &b_Ndata_bb_etot_over_p);
   fChain->SetBranchAddress("bb.etot_over_p", bb_etot_over_p, &b_bb_etot_over_p);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCU", &Ndata_bb_gem_hit_ADCU, &b_Ndata_bb_gem_hit_ADCU);
   fChain->SetBranchAddress("bb.gem.hit.ADCU", bb_gem_hit_ADCU, &b_bb_gem_hit_ADCU);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCU_deconv", &Ndata_bb_gem_hit_ADCU_deconv, &b_Ndata_bb_gem_hit_ADCU_deconv);
   fChain->SetBranchAddress("bb.gem.hit.ADCU_deconv", bb_gem_hit_ADCU_deconv, &b_bb_gem_hit_ADCU_deconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCV", &Ndata_bb_gem_hit_ADCV, &b_Ndata_bb_gem_hit_ADCV);
   fChain->SetBranchAddress("bb.gem.hit.ADCV", bb_gem_hit_ADCV, &b_bb_gem_hit_ADCV);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCV_deconv", &Ndata_bb_gem_hit_ADCV_deconv, &b_Ndata_bb_gem_hit_ADCV_deconv);
   fChain->SetBranchAddress("bb.gem.hit.ADCV_deconv", bb_gem_hit_ADCV_deconv, &b_bb_gem_hit_ADCV_deconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCasym", &Ndata_bb_gem_hit_ADCasym, &b_Ndata_bb_gem_hit_ADCasym);
   fChain->SetBranchAddress("bb.gem.hit.ADCasym", bb_gem_hit_ADCasym, &b_bb_gem_hit_ADCasym);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCasym_deconv", &Ndata_bb_gem_hit_ADCasym_deconv, &b_Ndata_bb_gem_hit_ADCasym_deconv);
   fChain->SetBranchAddress("bb.gem.hit.ADCasym_deconv", bb_gem_hit_ADCasym_deconv, &b_bb_gem_hit_ADCasym_deconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCavg", &Ndata_bb_gem_hit_ADCavg, &b_Ndata_bb_gem_hit_ADCavg);
   fChain->SetBranchAddress("bb.gem.hit.ADCavg", bb_gem_hit_ADCavg, &b_bb_gem_hit_ADCavg);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCavg_deconv", &Ndata_bb_gem_hit_ADCavg_deconv, &b_Ndata_bb_gem_hit_ADCavg_deconv);
   fChain->SetBranchAddress("bb.gem.hit.ADCavg_deconv", bb_gem_hit_ADCavg_deconv, &b_bb_gem_hit_ADCavg_deconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCfrac0_Umax", &Ndata_bb_gem_hit_ADCfrac0_Umax, &b_Ndata_bb_gem_hit_ADCfrac0_Umax);
   fChain->SetBranchAddress("bb.gem.hit.ADCfrac0_Umax", bb_gem_hit_ADCfrac0_Umax, &b_bb_gem_hit_ADCfrac0_Umax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCfrac0_Vmax", &Ndata_bb_gem_hit_ADCfrac0_Vmax, &b_Ndata_bb_gem_hit_ADCfrac0_Vmax);
   fChain->SetBranchAddress("bb.gem.hit.ADCfrac0_Vmax", bb_gem_hit_ADCfrac0_Vmax, &b_bb_gem_hit_ADCfrac0_Vmax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCfrac1_Umax", &Ndata_bb_gem_hit_ADCfrac1_Umax, &b_Ndata_bb_gem_hit_ADCfrac1_Umax);
   fChain->SetBranchAddress("bb.gem.hit.ADCfrac1_Umax", bb_gem_hit_ADCfrac1_Umax, &b_bb_gem_hit_ADCfrac1_Umax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCfrac1_Vmax", &Ndata_bb_gem_hit_ADCfrac1_Vmax, &b_Ndata_bb_gem_hit_ADCfrac1_Vmax);
   fChain->SetBranchAddress("bb.gem.hit.ADCfrac1_Vmax", bb_gem_hit_ADCfrac1_Vmax, &b_bb_gem_hit_ADCfrac1_Vmax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCfrac2_Umax", &Ndata_bb_gem_hit_ADCfrac2_Umax, &b_Ndata_bb_gem_hit_ADCfrac2_Umax);
   fChain->SetBranchAddress("bb.gem.hit.ADCfrac2_Umax", bb_gem_hit_ADCfrac2_Umax, &b_bb_gem_hit_ADCfrac2_Umax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCfrac2_Vmax", &Ndata_bb_gem_hit_ADCfrac2_Vmax, &b_Ndata_bb_gem_hit_ADCfrac2_Vmax);
   fChain->SetBranchAddress("bb.gem.hit.ADCfrac2_Vmax", bb_gem_hit_ADCfrac2_Vmax, &b_bb_gem_hit_ADCfrac2_Vmax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCfrac3_Umax", &Ndata_bb_gem_hit_ADCfrac3_Umax, &b_Ndata_bb_gem_hit_ADCfrac3_Umax);
   fChain->SetBranchAddress("bb.gem.hit.ADCfrac3_Umax", bb_gem_hit_ADCfrac3_Umax, &b_bb_gem_hit_ADCfrac3_Umax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCfrac3_Vmax", &Ndata_bb_gem_hit_ADCfrac3_Vmax, &b_Ndata_bb_gem_hit_ADCfrac3_Vmax);
   fChain->SetBranchAddress("bb.gem.hit.ADCfrac3_Vmax", bb_gem_hit_ADCfrac3_Vmax, &b_bb_gem_hit_ADCfrac3_Vmax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCfrac4_Umax", &Ndata_bb_gem_hit_ADCfrac4_Umax, &b_Ndata_bb_gem_hit_ADCfrac4_Umax);
   fChain->SetBranchAddress("bb.gem.hit.ADCfrac4_Umax", bb_gem_hit_ADCfrac4_Umax, &b_bb_gem_hit_ADCfrac4_Umax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCfrac4_Vmax", &Ndata_bb_gem_hit_ADCfrac4_Vmax, &b_Ndata_bb_gem_hit_ADCfrac4_Vmax);
   fChain->SetBranchAddress("bb.gem.hit.ADCfrac4_Vmax", bb_gem_hit_ADCfrac4_Vmax, &b_bb_gem_hit_ADCfrac4_Vmax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCfrac5_Umax", &Ndata_bb_gem_hit_ADCfrac5_Umax, &b_Ndata_bb_gem_hit_ADCfrac5_Umax);
   fChain->SetBranchAddress("bb.gem.hit.ADCfrac5_Umax", bb_gem_hit_ADCfrac5_Umax, &b_bb_gem_hit_ADCfrac5_Umax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCfrac5_Vmax", &Ndata_bb_gem_hit_ADCfrac5_Vmax, &b_Ndata_bb_gem_hit_ADCfrac5_Vmax);
   fChain->SetBranchAddress("bb.gem.hit.ADCfrac5_Vmax", bb_gem_hit_ADCfrac5_Vmax, &b_bb_gem_hit_ADCfrac5_Vmax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCmaxcomboUclust_deconv", &Ndata_bb_gem_hit_ADCmaxcomboUclust_deconv, &b_Ndata_bb_gem_hit_ADCmaxcomboUclust_deconv);
   fChain->SetBranchAddress("bb.gem.hit.ADCmaxcomboUclust_deconv", bb_gem_hit_ADCmaxcomboUclust_deconv, &b_bb_gem_hit_ADCmaxcomboUclust_deconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCmaxcomboVclust_deconv", &Ndata_bb_gem_hit_ADCmaxcomboVclust_deconv, &b_Ndata_bb_gem_hit_ADCmaxcomboVclust_deconv);
   fChain->SetBranchAddress("bb.gem.hit.ADCmaxcomboVclust_deconv", bb_gem_hit_ADCmaxcomboVclust_deconv, &b_bb_gem_hit_ADCmaxcomboVclust_deconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCmaxsampU", &Ndata_bb_gem_hit_ADCmaxsampU, &b_Ndata_bb_gem_hit_ADCmaxsampU);
   fChain->SetBranchAddress("bb.gem.hit.ADCmaxsampU", bb_gem_hit_ADCmaxsampU, &b_bb_gem_hit_ADCmaxsampU);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCmaxsampUclust", &Ndata_bb_gem_hit_ADCmaxsampUclust, &b_Ndata_bb_gem_hit_ADCmaxsampUclust);
   fChain->SetBranchAddress("bb.gem.hit.ADCmaxsampUclust", bb_gem_hit_ADCmaxsampUclust, &b_bb_gem_hit_ADCmaxsampUclust);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCmaxsampUclust_deconv", &Ndata_bb_gem_hit_ADCmaxsampUclust_deconv, &b_Ndata_bb_gem_hit_ADCmaxsampUclust_deconv);
   fChain->SetBranchAddress("bb.gem.hit.ADCmaxsampUclust_deconv", bb_gem_hit_ADCmaxsampUclust_deconv, &b_bb_gem_hit_ADCmaxsampUclust_deconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCmaxsampV", &Ndata_bb_gem_hit_ADCmaxsampV, &b_Ndata_bb_gem_hit_ADCmaxsampV);
   fChain->SetBranchAddress("bb.gem.hit.ADCmaxsampV", bb_gem_hit_ADCmaxsampV, &b_bb_gem_hit_ADCmaxsampV);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCmaxsampVclust", &Ndata_bb_gem_hit_ADCmaxsampVclust, &b_Ndata_bb_gem_hit_ADCmaxsampVclust);
   fChain->SetBranchAddress("bb.gem.hit.ADCmaxsampVclust", bb_gem_hit_ADCmaxsampVclust, &b_bb_gem_hit_ADCmaxsampVclust);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCmaxsampVclust_deconv", &Ndata_bb_gem_hit_ADCmaxsampVclust_deconv, &b_Ndata_bb_gem_hit_ADCmaxsampVclust_deconv);
   fChain->SetBranchAddress("bb.gem.hit.ADCmaxsampVclust_deconv", bb_gem_hit_ADCmaxsampVclust_deconv, &b_bb_gem_hit_ADCmaxsampVclust_deconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCmaxstripU", &Ndata_bb_gem_hit_ADCmaxstripU, &b_Ndata_bb_gem_hit_ADCmaxstripU);
   fChain->SetBranchAddress("bb.gem.hit.ADCmaxstripU", bb_gem_hit_ADCmaxstripU, &b_bb_gem_hit_ADCmaxstripU);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ADCmaxstripV", &Ndata_bb_gem_hit_ADCmaxstripV, &b_Ndata_bb_gem_hit_ADCmaxstripV);
   fChain->SetBranchAddress("bb.gem.hit.ADCmaxstripV", bb_gem_hit_ADCmaxstripV, &b_bb_gem_hit_ADCmaxstripV);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.BUILD_ALL_SAMPLES_U", &Ndata_bb_gem_hit_BUILD_ALL_SAMPLES_U, &b_Ndata_bb_gem_hit_BUILD_ALL_SAMPLES_U);
   fChain->SetBranchAddress("bb.gem.hit.BUILD_ALL_SAMPLES_U", bb_gem_hit_BUILD_ALL_SAMPLES_U, &b_bb_gem_hit_BUILD_ALL_SAMPLES_U);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.BUILD_ALL_SAMPLES_V", &Ndata_bb_gem_hit_BUILD_ALL_SAMPLES_V, &b_Ndata_bb_gem_hit_BUILD_ALL_SAMPLES_V);
   fChain->SetBranchAddress("bb.gem.hit.BUILD_ALL_SAMPLES_V", bb_gem_hit_BUILD_ALL_SAMPLES_V, &b_bb_gem_hit_BUILD_ALL_SAMPLES_V);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.CM_GOOD_U", &Ndata_bb_gem_hit_CM_GOOD_U, &b_Ndata_bb_gem_hit_CM_GOOD_U);
   fChain->SetBranchAddress("bb.gem.hit.CM_GOOD_U", bb_gem_hit_CM_GOOD_U, &b_bb_gem_hit_CM_GOOD_U);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.CM_GOOD_V", &Ndata_bb_gem_hit_CM_GOOD_V, &b_Ndata_bb_gem_hit_CM_GOOD_V);
   fChain->SetBranchAddress("bb.gem.hit.CM_GOOD_V", bb_gem_hit_CM_GOOD_V, &b_bb_gem_hit_CM_GOOD_V);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADC0_Umax", &Ndata_bb_gem_hit_DeconvADC0_Umax, &b_Ndata_bb_gem_hit_DeconvADC0_Umax);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADC0_Umax", bb_gem_hit_DeconvADC0_Umax, &b_bb_gem_hit_DeconvADC0_Umax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADC0_Vmax", &Ndata_bb_gem_hit_DeconvADC0_Vmax, &b_Ndata_bb_gem_hit_DeconvADC0_Vmax);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADC0_Vmax", bb_gem_hit_DeconvADC0_Vmax, &b_bb_gem_hit_DeconvADC0_Vmax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADC1_Umax", &Ndata_bb_gem_hit_DeconvADC1_Umax, &b_Ndata_bb_gem_hit_DeconvADC1_Umax);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADC1_Umax", bb_gem_hit_DeconvADC1_Umax, &b_bb_gem_hit_DeconvADC1_Umax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADC1_Vmax", &Ndata_bb_gem_hit_DeconvADC1_Vmax, &b_Ndata_bb_gem_hit_DeconvADC1_Vmax);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADC1_Vmax", bb_gem_hit_DeconvADC1_Vmax, &b_bb_gem_hit_DeconvADC1_Vmax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADC2_Umax", &Ndata_bb_gem_hit_DeconvADC2_Umax, &b_Ndata_bb_gem_hit_DeconvADC2_Umax);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADC2_Umax", bb_gem_hit_DeconvADC2_Umax, &b_bb_gem_hit_DeconvADC2_Umax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADC2_Vmax", &Ndata_bb_gem_hit_DeconvADC2_Vmax, &b_Ndata_bb_gem_hit_DeconvADC2_Vmax);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADC2_Vmax", bb_gem_hit_DeconvADC2_Vmax, &b_bb_gem_hit_DeconvADC2_Vmax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADC3_Umax", &Ndata_bb_gem_hit_DeconvADC3_Umax, &b_Ndata_bb_gem_hit_DeconvADC3_Umax);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADC3_Umax", bb_gem_hit_DeconvADC3_Umax, &b_bb_gem_hit_DeconvADC3_Umax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADC3_Vmax", &Ndata_bb_gem_hit_DeconvADC3_Vmax, &b_Ndata_bb_gem_hit_DeconvADC3_Vmax);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADC3_Vmax", bb_gem_hit_DeconvADC3_Vmax, &b_bb_gem_hit_DeconvADC3_Vmax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADC4_Umax", &Ndata_bb_gem_hit_DeconvADC4_Umax, &b_Ndata_bb_gem_hit_DeconvADC4_Umax);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADC4_Umax", bb_gem_hit_DeconvADC4_Umax, &b_bb_gem_hit_DeconvADC4_Umax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADC4_Vmax", &Ndata_bb_gem_hit_DeconvADC4_Vmax, &b_Ndata_bb_gem_hit_DeconvADC4_Vmax);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADC4_Vmax", bb_gem_hit_DeconvADC4_Vmax, &b_bb_gem_hit_DeconvADC4_Vmax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADC5_Umax", &Ndata_bb_gem_hit_DeconvADC5_Umax, &b_Ndata_bb_gem_hit_DeconvADC5_Umax);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADC5_Umax", bb_gem_hit_DeconvADC5_Umax, &b_bb_gem_hit_DeconvADC5_Umax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADC5_Vmax", &Ndata_bb_gem_hit_DeconvADC5_Vmax, &b_Ndata_bb_gem_hit_DeconvADC5_Vmax);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADC5_Vmax", bb_gem_hit_DeconvADC5_Vmax, &b_bb_gem_hit_DeconvADC5_Vmax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADCmaxcomboU", &Ndata_bb_gem_hit_DeconvADCmaxcomboU, &b_Ndata_bb_gem_hit_DeconvADCmaxcomboU);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADCmaxcomboU", bb_gem_hit_DeconvADCmaxcomboU, &b_bb_gem_hit_DeconvADCmaxcomboU);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADCmaxcomboV", &Ndata_bb_gem_hit_DeconvADCmaxcomboV, &b_Ndata_bb_gem_hit_DeconvADCmaxcomboV);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADCmaxcomboV", bb_gem_hit_DeconvADCmaxcomboV, &b_bb_gem_hit_DeconvADCmaxcomboV);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADCmaxsampU", &Ndata_bb_gem_hit_DeconvADCmaxsampU, &b_Ndata_bb_gem_hit_DeconvADCmaxsampU);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADCmaxsampU", bb_gem_hit_DeconvADCmaxsampU, &b_bb_gem_hit_DeconvADCmaxsampU);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADCmaxsampV", &Ndata_bb_gem_hit_DeconvADCmaxsampV, &b_Ndata_bb_gem_hit_DeconvADCmaxsampV);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADCmaxsampV", bb_gem_hit_DeconvADCmaxsampV, &b_bb_gem_hit_DeconvADCmaxsampV);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADCmaxstripU", &Ndata_bb_gem_hit_DeconvADCmaxstripU, &b_Ndata_bb_gem_hit_DeconvADCmaxstripU);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADCmaxstripU", bb_gem_hit_DeconvADCmaxstripU, &b_bb_gem_hit_DeconvADCmaxstripU);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.DeconvADCmaxstripV", &Ndata_bb_gem_hit_DeconvADCmaxstripV, &b_Ndata_bb_gem_hit_DeconvADCmaxstripV);
   fChain->SetBranchAddress("bb.gem.hit.DeconvADCmaxstripV", bb_gem_hit_DeconvADCmaxstripV, &b_bb_gem_hit_DeconvADCmaxstripV);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ENABLE_CM_U", &Ndata_bb_gem_hit_ENABLE_CM_U, &b_Ndata_bb_gem_hit_ENABLE_CM_U);
   fChain->SetBranchAddress("bb.gem.hit.ENABLE_CM_U", bb_gem_hit_ENABLE_CM_U, &b_bb_gem_hit_ENABLE_CM_U);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ENABLE_CM_V", &Ndata_bb_gem_hit_ENABLE_CM_V, &b_Ndata_bb_gem_hit_ENABLE_CM_V);
   fChain->SetBranchAddress("bb.gem.hit.ENABLE_CM_V", bb_gem_hit_ENABLE_CM_V, &b_bb_gem_hit_ENABLE_CM_V);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.TSchi2_Umax", &Ndata_bb_gem_hit_TSchi2_Umax, &b_Ndata_bb_gem_hit_TSchi2_Umax);
   fChain->SetBranchAddress("bb.gem.hit.TSchi2_Umax", bb_gem_hit_TSchi2_Umax, &b_bb_gem_hit_TSchi2_Umax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.TSchi2_Vmax", &Ndata_bb_gem_hit_TSchi2_Vmax, &b_Ndata_bb_gem_hit_TSchi2_Vmax);
   fChain->SetBranchAddress("bb.gem.hit.TSchi2_Vmax", bb_gem_hit_TSchi2_Vmax, &b_bb_gem_hit_TSchi2_Vmax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.TSprob_Umax", &Ndata_bb_gem_hit_TSprob_Umax, &b_Ndata_bb_gem_hit_TSprob_Umax);
   fChain->SetBranchAddress("bb.gem.hit.TSprob_Umax", bb_gem_hit_TSprob_Umax, &b_bb_gem_hit_TSprob_Umax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.TSprob_Vmax", &Ndata_bb_gem_hit_TSprob_Vmax, &b_Ndata_bb_gem_hit_TSprob_Vmax);
   fChain->SetBranchAddress("bb.gem.hit.TSprob_Vmax", bb_gem_hit_TSprob_Vmax, &b_bb_gem_hit_TSprob_Vmax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.Tavg", &Ndata_bb_gem_hit_Tavg, &b_Ndata_bb_gem_hit_Tavg);
   fChain->SetBranchAddress("bb.gem.hit.Tavg", bb_gem_hit_Tavg, &b_bb_gem_hit_Tavg);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.Tavg_corr", &Ndata_bb_gem_hit_Tavg_corr, &b_Ndata_bb_gem_hit_Tavg_corr);
   fChain->SetBranchAddress("bb.gem.hit.Tavg_corr", bb_gem_hit_Tavg_corr, &b_bb_gem_hit_Tavg_corr);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.Tavg_deconv", &Ndata_bb_gem_hit_Tavg_deconv, &b_Ndata_bb_gem_hit_Tavg_deconv);
   fChain->SetBranchAddress("bb.gem.hit.Tavg_deconv", bb_gem_hit_Tavg_deconv, &b_bb_gem_hit_Tavg_deconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.Tavg_fit", &Ndata_bb_gem_hit_Tavg_fit, &b_Ndata_bb_gem_hit_Tavg_fit);
   fChain->SetBranchAddress("bb.gem.hit.Tavg_fit", bb_gem_hit_Tavg_fit, &b_bb_gem_hit_Tavg_fit);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.Ugain", &Ndata_bb_gem_hit_Ugain, &b_Ndata_bb_gem_hit_Ugain);
   fChain->SetBranchAddress("bb.gem.hit.Ugain", bb_gem_hit_Ugain, &b_bb_gem_hit_Ugain);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.Utime", &Ndata_bb_gem_hit_Utime, &b_Ndata_bb_gem_hit_Utime);
   fChain->SetBranchAddress("bb.gem.hit.Utime", bb_gem_hit_Utime, &b_bb_gem_hit_Utime);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.UtimeDeconv", &Ndata_bb_gem_hit_UtimeDeconv, &b_Ndata_bb_gem_hit_UtimeDeconv);
   fChain->SetBranchAddress("bb.gem.hit.UtimeDeconv", bb_gem_hit_UtimeDeconv, &b_bb_gem_hit_UtimeDeconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.UtimeFit", &Ndata_bb_gem_hit_UtimeFit, &b_Ndata_bb_gem_hit_UtimeFit);
   fChain->SetBranchAddress("bb.gem.hit.UtimeFit", bb_gem_hit_UtimeFit, &b_bb_gem_hit_UtimeFit);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.UtimeMaxStrip", &Ndata_bb_gem_hit_UtimeMaxStrip, &b_Ndata_bb_gem_hit_UtimeMaxStrip);
   fChain->SetBranchAddress("bb.gem.hit.UtimeMaxStrip", bb_gem_hit_UtimeMaxStrip, &b_bb_gem_hit_UtimeMaxStrip);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.UtimeMaxStripDeconv", &Ndata_bb_gem_hit_UtimeMaxStripDeconv, &b_Ndata_bb_gem_hit_UtimeMaxStripDeconv);
   fChain->SetBranchAddress("bb.gem.hit.UtimeMaxStripDeconv", bb_gem_hit_UtimeMaxStripDeconv, &b_bb_gem_hit_UtimeMaxStripDeconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.UtimeMaxStripFit", &Ndata_bb_gem_hit_UtimeMaxStripFit, &b_Ndata_bb_gem_hit_UtimeMaxStripFit);
   fChain->SetBranchAddress("bb.gem.hit.UtimeMaxStripFit", bb_gem_hit_UtimeMaxStripFit, &b_bb_gem_hit_UtimeMaxStripFit);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.Vgain", &Ndata_bb_gem_hit_Vgain, &b_Ndata_bb_gem_hit_Vgain);
   fChain->SetBranchAddress("bb.gem.hit.Vgain", bb_gem_hit_Vgain, &b_bb_gem_hit_Vgain);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.Vtime", &Ndata_bb_gem_hit_Vtime, &b_Ndata_bb_gem_hit_Vtime);
   fChain->SetBranchAddress("bb.gem.hit.Vtime", bb_gem_hit_Vtime, &b_bb_gem_hit_Vtime);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.VtimeDeconv", &Ndata_bb_gem_hit_VtimeDeconv, &b_Ndata_bb_gem_hit_VtimeDeconv);
   fChain->SetBranchAddress("bb.gem.hit.VtimeDeconv", bb_gem_hit_VtimeDeconv, &b_bb_gem_hit_VtimeDeconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.VtimeFit", &Ndata_bb_gem_hit_VtimeFit, &b_Ndata_bb_gem_hit_VtimeFit);
   fChain->SetBranchAddress("bb.gem.hit.VtimeFit", bb_gem_hit_VtimeFit, &b_bb_gem_hit_VtimeFit);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.VtimeMaxStrip", &Ndata_bb_gem_hit_VtimeMaxStrip, &b_Ndata_bb_gem_hit_VtimeMaxStrip);
   fChain->SetBranchAddress("bb.gem.hit.VtimeMaxStrip", bb_gem_hit_VtimeMaxStrip, &b_bb_gem_hit_VtimeMaxStrip);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.VtimeMaxStripDeconv", &Ndata_bb_gem_hit_VtimeMaxStripDeconv, &b_Ndata_bb_gem_hit_VtimeMaxStripDeconv);
   fChain->SetBranchAddress("bb.gem.hit.VtimeMaxStripDeconv", bb_gem_hit_VtimeMaxStripDeconv, &b_bb_gem_hit_VtimeMaxStripDeconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.VtimeMaxStripFit", &Ndata_bb_gem_hit_VtimeMaxStripFit, &b_Ndata_bb_gem_hit_VtimeMaxStripFit);
   fChain->SetBranchAddress("bb.gem.hit.VtimeMaxStripFit", bb_gem_hit_VtimeMaxStripFit, &b_bb_gem_hit_VtimeMaxStripFit);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ccor_clust", &Ndata_bb_gem_hit_ccor_clust, &b_Ndata_bb_gem_hit_ccor_clust);
   fChain->SetBranchAddress("bb.gem.hit.ccor_clust", bb_gem_hit_ccor_clust, &b_bb_gem_hit_ccor_clust);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ccor_clust_deconv", &Ndata_bb_gem_hit_ccor_clust_deconv, &b_Ndata_bb_gem_hit_ccor_clust_deconv);
   fChain->SetBranchAddress("bb.gem.hit.ccor_clust_deconv", bb_gem_hit_ccor_clust_deconv, &b_bb_gem_hit_ccor_clust_deconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ccor_strip", &Ndata_bb_gem_hit_ccor_strip, &b_Ndata_bb_gem_hit_ccor_strip);
   fChain->SetBranchAddress("bb.gem.hit.ccor_strip", bb_gem_hit_ccor_strip, &b_bb_gem_hit_ccor_strip);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ccor_strip_deconv", &Ndata_bb_gem_hit_ccor_strip_deconv, &b_Ndata_bb_gem_hit_ccor_strip_deconv);
   fChain->SetBranchAddress("bb.gem.hit.ccor_strip_deconv", bb_gem_hit_ccor_strip_deconv, &b_bb_gem_hit_ccor_strip_deconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.deltat", &Ndata_bb_gem_hit_deltat, &b_Ndata_bb_gem_hit_deltat);
   fChain->SetBranchAddress("bb.gem.hit.deltat", bb_gem_hit_deltat, &b_bb_gem_hit_deltat);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.deltat_deconv", &Ndata_bb_gem_hit_deltat_deconv, &b_Ndata_bb_gem_hit_deltat_deconv);
   fChain->SetBranchAddress("bb.gem.hit.deltat_deconv", bb_gem_hit_deltat_deconv, &b_bb_gem_hit_deltat_deconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.deltat_fit", &Ndata_bb_gem_hit_deltat_fit, &b_Ndata_bb_gem_hit_deltat_fit);
   fChain->SetBranchAddress("bb.gem.hit.deltat_fit", bb_gem_hit_deltat_fit, &b_bb_gem_hit_deltat_fit);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.eresidu", &Ndata_bb_gem_hit_eresidu, &b_Ndata_bb_gem_hit_eresidu);
   fChain->SetBranchAddress("bb.gem.hit.eresidu", bb_gem_hit_eresidu, &b_bb_gem_hit_eresidu);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.eresidv", &Ndata_bb_gem_hit_eresidv, &b_Ndata_bb_gem_hit_eresidv);
   fChain->SetBranchAddress("bb.gem.hit.eresidv", bb_gem_hit_eresidv, &b_bb_gem_hit_eresidv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.icombomaxUclustDeconv", &Ndata_bb_gem_hit_icombomaxUclustDeconv, &b_Ndata_bb_gem_hit_icombomaxUclustDeconv);
   fChain->SetBranchAddress("bb.gem.hit.icombomaxUclustDeconv", bb_gem_hit_icombomaxUclustDeconv, &b_bb_gem_hit_icombomaxUclustDeconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.icombomaxUstripDeconv", &Ndata_bb_gem_hit_icombomaxUstripDeconv, &b_Ndata_bb_gem_hit_icombomaxUstripDeconv);
   fChain->SetBranchAddress("bb.gem.hit.icombomaxUstripDeconv", bb_gem_hit_icombomaxUstripDeconv, &b_bb_gem_hit_icombomaxUstripDeconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.icombomaxVclustDeconv", &Ndata_bb_gem_hit_icombomaxVclustDeconv, &b_Ndata_bb_gem_hit_icombomaxVclustDeconv);
   fChain->SetBranchAddress("bb.gem.hit.icombomaxVclustDeconv", bb_gem_hit_icombomaxVclustDeconv, &b_bb_gem_hit_icombomaxVclustDeconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.icombomaxVstripDeconv", &Ndata_bb_gem_hit_icombomaxVstripDeconv, &b_Ndata_bb_gem_hit_icombomaxVstripDeconv);
   fChain->SetBranchAddress("bb.gem.hit.icombomaxVstripDeconv", bb_gem_hit_icombomaxVstripDeconv, &b_bb_gem_hit_icombomaxVstripDeconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.isampmaxUclust", &Ndata_bb_gem_hit_isampmaxUclust, &b_Ndata_bb_gem_hit_isampmaxUclust);
   fChain->SetBranchAddress("bb.gem.hit.isampmaxUclust", bb_gem_hit_isampmaxUclust, &b_bb_gem_hit_isampmaxUclust);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.isampmaxUclustDeconv", &Ndata_bb_gem_hit_isampmaxUclustDeconv, &b_Ndata_bb_gem_hit_isampmaxUclustDeconv);
   fChain->SetBranchAddress("bb.gem.hit.isampmaxUclustDeconv", bb_gem_hit_isampmaxUclustDeconv, &b_bb_gem_hit_isampmaxUclustDeconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.isampmaxUstrip", &Ndata_bb_gem_hit_isampmaxUstrip, &b_Ndata_bb_gem_hit_isampmaxUstrip);
   fChain->SetBranchAddress("bb.gem.hit.isampmaxUstrip", bb_gem_hit_isampmaxUstrip, &b_bb_gem_hit_isampmaxUstrip);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.isampmaxUstripDeconv", &Ndata_bb_gem_hit_isampmaxUstripDeconv, &b_Ndata_bb_gem_hit_isampmaxUstripDeconv);
   fChain->SetBranchAddress("bb.gem.hit.isampmaxUstripDeconv", bb_gem_hit_isampmaxUstripDeconv, &b_bb_gem_hit_isampmaxUstripDeconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.isampmaxVclust", &Ndata_bb_gem_hit_isampmaxVclust, &b_Ndata_bb_gem_hit_isampmaxVclust);
   fChain->SetBranchAddress("bb.gem.hit.isampmaxVclust", bb_gem_hit_isampmaxVclust, &b_bb_gem_hit_isampmaxVclust);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.isampmaxVclustDeconv", &Ndata_bb_gem_hit_isampmaxVclustDeconv, &b_Ndata_bb_gem_hit_isampmaxVclustDeconv);
   fChain->SetBranchAddress("bb.gem.hit.isampmaxVclustDeconv", bb_gem_hit_isampmaxVclustDeconv, &b_bb_gem_hit_isampmaxVclustDeconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.isampmaxVstrip", &Ndata_bb_gem_hit_isampmaxVstrip, &b_Ndata_bb_gem_hit_isampmaxVstrip);
   fChain->SetBranchAddress("bb.gem.hit.isampmaxVstrip", bb_gem_hit_isampmaxVstrip, &b_bb_gem_hit_isampmaxVstrip);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.isampmaxVstripDeconv", &Ndata_bb_gem_hit_isampmaxVstripDeconv, &b_Ndata_bb_gem_hit_isampmaxVstripDeconv);
   fChain->SetBranchAddress("bb.gem.hit.isampmaxVstripDeconv", bb_gem_hit_isampmaxVstripDeconv, &b_bb_gem_hit_isampmaxVstripDeconv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.layer", &Ndata_bb_gem_hit_layer, &b_Ndata_bb_gem_hit_layer);
   fChain->SetBranchAddress("bb.gem.hit.layer", bb_gem_hit_layer, &b_bb_gem_hit_layer);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.module", &Ndata_bb_gem_hit_module, &b_Ndata_bb_gem_hit_module);
   fChain->SetBranchAddress("bb.gem.hit.module", bb_gem_hit_module, &b_bb_gem_hit_module);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.nstripu", &Ndata_bb_gem_hit_nstripu, &b_Ndata_bb_gem_hit_nstripu);
   fChain->SetBranchAddress("bb.gem.hit.nstripu", bb_gem_hit_nstripu, &b_bb_gem_hit_nstripu);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.nstripv", &Ndata_bb_gem_hit_nstripv, &b_Ndata_bb_gem_hit_nstripv);
   fChain->SetBranchAddress("bb.gem.hit.nstripv", bb_gem_hit_nstripv, &b_bb_gem_hit_nstripv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.residu", &Ndata_bb_gem_hit_residu, &b_Ndata_bb_gem_hit_residu);
   fChain->SetBranchAddress("bb.gem.hit.residu", bb_gem_hit_residu, &b_bb_gem_hit_residu);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.residv", &Ndata_bb_gem_hit_residv, &b_Ndata_bb_gem_hit_residv);
   fChain->SetBranchAddress("bb.gem.hit.residv", bb_gem_hit_residv, &b_bb_gem_hit_residv);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.trackindex", &Ndata_bb_gem_hit_trackindex, &b_Ndata_bb_gem_hit_trackindex);
   fChain->SetBranchAddress("bb.gem.hit.trackindex", bb_gem_hit_trackindex, &b_bb_gem_hit_trackindex);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.u", &Ndata_bb_gem_hit_u, &b_Ndata_bb_gem_hit_u);
   fChain->SetBranchAddress("bb.gem.hit.u", bb_gem_hit_u, &b_bb_gem_hit_u);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.umoment", &Ndata_bb_gem_hit_umoment, &b_Ndata_bb_gem_hit_umoment);
   fChain->SetBranchAddress("bb.gem.hit.umoment", bb_gem_hit_umoment, &b_bb_gem_hit_umoment);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.usigma", &Ndata_bb_gem_hit_usigma, &b_Ndata_bb_gem_hit_usigma);
   fChain->SetBranchAddress("bb.gem.hit.usigma", bb_gem_hit_usigma, &b_bb_gem_hit_usigma);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ustriphi", &Ndata_bb_gem_hit_ustriphi, &b_Ndata_bb_gem_hit_ustriphi);
   fChain->SetBranchAddress("bb.gem.hit.ustriphi", bb_gem_hit_ustriphi, &b_bb_gem_hit_ustriphi);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ustriplo", &Ndata_bb_gem_hit_ustriplo, &b_Ndata_bb_gem_hit_ustriplo);
   fChain->SetBranchAddress("bb.gem.hit.ustriplo", bb_gem_hit_ustriplo, &b_bb_gem_hit_ustriplo);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ustripmax", &Ndata_bb_gem_hit_ustripmax, &b_Ndata_bb_gem_hit_ustripmax);
   fChain->SetBranchAddress("bb.gem.hit.ustripmax", bb_gem_hit_ustripmax, &b_bb_gem_hit_ustripmax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.v", &Ndata_bb_gem_hit_v, &b_Ndata_bb_gem_hit_v);
   fChain->SetBranchAddress("bb.gem.hit.v", bb_gem_hit_v, &b_bb_gem_hit_v);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.vmoment", &Ndata_bb_gem_hit_vmoment, &b_Ndata_bb_gem_hit_vmoment);
   fChain->SetBranchAddress("bb.gem.hit.vmoment", bb_gem_hit_vmoment, &b_bb_gem_hit_vmoment);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.vsigma", &Ndata_bb_gem_hit_vsigma, &b_Ndata_bb_gem_hit_vsigma);
   fChain->SetBranchAddress("bb.gem.hit.vsigma", bb_gem_hit_vsigma, &b_bb_gem_hit_vsigma);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.vstriphi", &Ndata_bb_gem_hit_vstriphi, &b_Ndata_bb_gem_hit_vstriphi);
   fChain->SetBranchAddress("bb.gem.hit.vstriphi", bb_gem_hit_vstriphi, &b_bb_gem_hit_vstriphi);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.vstriplo", &Ndata_bb_gem_hit_vstriplo, &b_Ndata_bb_gem_hit_vstriplo);
   fChain->SetBranchAddress("bb.gem.hit.vstriplo", bb_gem_hit_vstriplo, &b_bb_gem_hit_vstriplo);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.vstripmax", &Ndata_bb_gem_hit_vstripmax, &b_Ndata_bb_gem_hit_vstripmax);
   fChain->SetBranchAddress("bb.gem.hit.vstripmax", bb_gem_hit_vstripmax, &b_bb_gem_hit_vstripmax);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.xglobal", &Ndata_bb_gem_hit_xglobal, &b_Ndata_bb_gem_hit_xglobal);
   fChain->SetBranchAddress("bb.gem.hit.xglobal", bb_gem_hit_xglobal, &b_bb_gem_hit_xglobal);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.xlocal", &Ndata_bb_gem_hit_xlocal, &b_Ndata_bb_gem_hit_xlocal);
   fChain->SetBranchAddress("bb.gem.hit.xlocal", bb_gem_hit_xlocal, &b_bb_gem_hit_xlocal);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.yglobal", &Ndata_bb_gem_hit_yglobal, &b_Ndata_bb_gem_hit_yglobal);
   fChain->SetBranchAddress("bb.gem.hit.yglobal", bb_gem_hit_yglobal, &b_bb_gem_hit_yglobal);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.ylocal", &Ndata_bb_gem_hit_ylocal, &b_Ndata_bb_gem_hit_ylocal);
   fChain->SetBranchAddress("bb.gem.hit.ylocal", bb_gem_hit_ylocal, &b_bb_gem_hit_ylocal);
   fChain->SetBranchAddress("Ndata.bb.gem.hit.zglobal", &Ndata_bb_gem_hit_zglobal, &b_Ndata_bb_gem_hit_zglobal);
   fChain->SetBranchAddress("bb.gem.hit.zglobal", bb_gem_hit_zglobal, &b_bb_gem_hit_zglobal);
   fChain->SetBranchAddress("Ndata.bb.gem.n2Dhit_layer", &Ndata_bb_gem_n2Dhit_layer, &b_Ndata_bb_gem_n2Dhit_layer);
   fChain->SetBranchAddress("bb.gem.n2Dhit_layer", bb_gem_n2Dhit_layer, &b_bb_gem_n2Dhit_layer);
   fChain->SetBranchAddress("Ndata.bb.gem.nclustu_layer", &Ndata_bb_gem_nclustu_layer, &b_Ndata_bb_gem_nclustu_layer);
   fChain->SetBranchAddress("bb.gem.nclustu_layer", bb_gem_nclustu_layer, &b_bb_gem_nclustu_layer);
   fChain->SetBranchAddress("Ndata.bb.gem.nclustv_layer", &Ndata_bb_gem_nclustv_layer, &b_Ndata_bb_gem_nclustv_layer);
   fChain->SetBranchAddress("bb.gem.nclustv_layer", bb_gem_nclustv_layer, &b_bb_gem_nclustv_layer);
   fChain->SetBranchAddress("Ndata.bb.gem.nstripsu_layer", &Ndata_bb_gem_nstripsu_layer, &b_Ndata_bb_gem_nstripsu_layer);
   fChain->SetBranchAddress("bb.gem.nstripsu_layer", bb_gem_nstripsu_layer, &b_bb_gem_nstripsu_layer);
   fChain->SetBranchAddress("Ndata.bb.gem.nstripsv_layer", &Ndata_bb_gem_nstripsv_layer, &b_Ndata_bb_gem_nstripsv_layer);
   fChain->SetBranchAddress("bb.gem.nstripsv_layer", bb_gem_nstripsv_layer, &b_bb_gem_nstripsv_layer);
   fChain->SetBranchAddress("Ndata.bb.gem.track.chi2ndf", &Ndata_bb_gem_track_chi2ndf, &b_Ndata_bb_gem_track_chi2ndf);
   fChain->SetBranchAddress("bb.gem.track.chi2ndf", bb_gem_track_chi2ndf, &b_bb_gem_track_chi2ndf);
   fChain->SetBranchAddress("Ndata.bb.gem.track.chi2ndf_hitquality", &Ndata_bb_gem_track_chi2ndf_hitquality, &b_Ndata_bb_gem_track_chi2ndf_hitquality);
   fChain->SetBranchAddress("bb.gem.track.chi2ndf_hitquality", bb_gem_track_chi2ndf_hitquality, &b_bb_gem_track_chi2ndf_hitquality);
   fChain->SetBranchAddress("Ndata.bb.gem.track.ngoodhits", &Ndata_bb_gem_track_ngoodhits, &b_Ndata_bb_gem_track_ngoodhits);
   fChain->SetBranchAddress("bb.gem.track.ngoodhits", bb_gem_track_ngoodhits, &b_bb_gem_track_ngoodhits);
   fChain->SetBranchAddress("Ndata.bb.gem.track.nhits", &Ndata_bb_gem_track_nhits, &b_Ndata_bb_gem_track_nhits);
   fChain->SetBranchAddress("bb.gem.track.nhits", bb_gem_track_nhits, &b_bb_gem_track_nhits);
   fChain->SetBranchAddress("Ndata.bb.gem.track.t0", &Ndata_bb_gem_track_t0, &b_Ndata_bb_gem_track_t0);
   fChain->SetBranchAddress("bb.gem.track.t0", bb_gem_track_t0, &b_bb_gem_track_t0);
   fChain->SetBranchAddress("Ndata.bb.gem.track.x", &Ndata_bb_gem_track_x, &b_Ndata_bb_gem_track_x);
   fChain->SetBranchAddress("bb.gem.track.x", bb_gem_track_x, &b_bb_gem_track_x);
   fChain->SetBranchAddress("Ndata.bb.gem.track.xp", &Ndata_bb_gem_track_xp, &b_Ndata_bb_gem_track_xp);
   fChain->SetBranchAddress("bb.gem.track.xp", bb_gem_track_xp, &b_bb_gem_track_xp);
   fChain->SetBranchAddress("Ndata.bb.gem.track.y", &Ndata_bb_gem_track_y, &b_Ndata_bb_gem_track_y);
   fChain->SetBranchAddress("bb.gem.track.y", bb_gem_track_y, &b_bb_gem_track_y);
   fChain->SetBranchAddress("Ndata.bb.gem.track.yp", &Ndata_bb_gem_track_yp, &b_Ndata_bb_gem_track_yp);
   fChain->SetBranchAddress("bb.gem.track.yp", bb_gem_track_yp, &b_bb_gem_track_yp);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.allclus.adc", &Ndata_bb_grinch_tdc_allclus_adc, &b_Ndata_bb_grinch_tdc_allclus_adc);
   fChain->SetBranchAddress("bb.grinch_tdc.allclus.adc", bb_grinch_tdc_allclus_adc, &b_bb_grinch_tdc_allclus_adc);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.allclus.dx", &Ndata_bb_grinch_tdc_allclus_dx, &b_Ndata_bb_grinch_tdc_allclus_dx);
   fChain->SetBranchAddress("bb.grinch_tdc.allclus.dx", bb_grinch_tdc_allclus_dx, &b_bb_grinch_tdc_allclus_dx);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.allclus.dy", &Ndata_bb_grinch_tdc_allclus_dy, &b_Ndata_bb_grinch_tdc_allclus_dy);
   fChain->SetBranchAddress("bb.grinch_tdc.allclus.dy", bb_grinch_tdc_allclus_dy, &b_bb_grinch_tdc_allclus_dy);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.allclus.mirrorindex", &Ndata_bb_grinch_tdc_allclus_mirrorindex, &b_Ndata_bb_grinch_tdc_allclus_mirrorindex);
   fChain->SetBranchAddress("bb.grinch_tdc.allclus.mirrorindex", bb_grinch_tdc_allclus_mirrorindex, &b_bb_grinch_tdc_allclus_mirrorindex);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.allclus.size", &Ndata_bb_grinch_tdc_allclus_size, &b_Ndata_bb_grinch_tdc_allclus_size);
   fChain->SetBranchAddress("bb.grinch_tdc.allclus.size", bb_grinch_tdc_allclus_size, &b_bb_grinch_tdc_allclus_size);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.allclus.t_mean", &Ndata_bb_grinch_tdc_allclus_t_mean, &b_Ndata_bb_grinch_tdc_allclus_t_mean);
   fChain->SetBranchAddress("bb.grinch_tdc.allclus.t_mean", bb_grinch_tdc_allclus_t_mean, &b_bb_grinch_tdc_allclus_t_mean);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.allclus.t_rms", &Ndata_bb_grinch_tdc_allclus_t_rms, &b_Ndata_bb_grinch_tdc_allclus_t_rms);
   fChain->SetBranchAddress("bb.grinch_tdc.allclus.t_rms", bb_grinch_tdc_allclus_t_rms, &b_bb_grinch_tdc_allclus_t_rms);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.allclus.tot_mean", &Ndata_bb_grinch_tdc_allclus_tot_mean, &b_Ndata_bb_grinch_tdc_allclus_tot_mean);
   fChain->SetBranchAddress("bb.grinch_tdc.allclus.tot_mean", bb_grinch_tdc_allclus_tot_mean, &b_bb_grinch_tdc_allclus_tot_mean);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.allclus.trackindex", &Ndata_bb_grinch_tdc_allclus_trackindex, &b_Ndata_bb_grinch_tdc_allclus_trackindex);
   fChain->SetBranchAddress("bb.grinch_tdc.allclus.trackindex", bb_grinch_tdc_allclus_trackindex, &b_bb_grinch_tdc_allclus_trackindex);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.allclus.x_mean", &Ndata_bb_grinch_tdc_allclus_x_mean, &b_Ndata_bb_grinch_tdc_allclus_x_mean);
   fChain->SetBranchAddress("bb.grinch_tdc.allclus.x_mean", bb_grinch_tdc_allclus_x_mean, &b_bb_grinch_tdc_allclus_x_mean);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.allclus.y_mean", &Ndata_bb_grinch_tdc_allclus_y_mean, &b_Ndata_bb_grinch_tdc_allclus_y_mean);
   fChain->SetBranchAddress("bb.grinch_tdc.allclus.y_mean", bb_grinch_tdc_allclus_y_mean, &b_bb_grinch_tdc_allclus_y_mean);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.hit.amp", &Ndata_bb_grinch_tdc_hit_amp, &b_Ndata_bb_grinch_tdc_hit_amp);
   fChain->SetBranchAddress("bb.grinch_tdc.hit.amp", bb_grinch_tdc_hit_amp, &b_bb_grinch_tdc_hit_amp);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.hit.clustindex", &Ndata_bb_grinch_tdc_hit_clustindex, &b_Ndata_bb_grinch_tdc_hit_clustindex);
   fChain->SetBranchAddress("bb.grinch_tdc.hit.clustindex", bb_grinch_tdc_hit_clustindex, &b_bb_grinch_tdc_hit_clustindex);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.hit.col", &Ndata_bb_grinch_tdc_hit_col, &b_Ndata_bb_grinch_tdc_hit_col);
   fChain->SetBranchAddress("bb.grinch_tdc.hit.col", bb_grinch_tdc_hit_col, &b_bb_grinch_tdc_hit_col);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.hit.pmtnum", &Ndata_bb_grinch_tdc_hit_pmtnum, &b_Ndata_bb_grinch_tdc_hit_pmtnum);
   fChain->SetBranchAddress("bb.grinch_tdc.hit.pmtnum", bb_grinch_tdc_hit_pmtnum, &b_bb_grinch_tdc_hit_pmtnum);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.hit.row", &Ndata_bb_grinch_tdc_hit_row, &b_Ndata_bb_grinch_tdc_hit_row);
   fChain->SetBranchAddress("bb.grinch_tdc.hit.row", bb_grinch_tdc_hit_row, &b_bb_grinch_tdc_hit_row);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.hit.time", &Ndata_bb_grinch_tdc_hit_time, &b_Ndata_bb_grinch_tdc_hit_time);
   fChain->SetBranchAddress("bb.grinch_tdc.hit.time", bb_grinch_tdc_hit_time, &b_bb_grinch_tdc_hit_time);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.hit.trackindex", &Ndata_bb_grinch_tdc_hit_trackindex, &b_Ndata_bb_grinch_tdc_hit_trackindex);
   fChain->SetBranchAddress("bb.grinch_tdc.hit.trackindex", bb_grinch_tdc_hit_trackindex, &b_bb_grinch_tdc_hit_trackindex);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.hit.xhit", &Ndata_bb_grinch_tdc_hit_xhit, &b_Ndata_bb_grinch_tdc_hit_xhit);
   fChain->SetBranchAddress("bb.grinch_tdc.hit.xhit", bb_grinch_tdc_hit_xhit, &b_bb_grinch_tdc_hit_xhit);
   fChain->SetBranchAddress("Ndata.bb.grinch_tdc.hit.yhit", &Ndata_bb_grinch_tdc_hit_yhit, &b_Ndata_bb_grinch_tdc_hit_yhit);
   fChain->SetBranchAddress("bb.grinch_tdc.hit.yhit", bb_grinch_tdc_hit_yhit, &b_bb_grinch_tdc_hit_yhit);
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
   fChain->SetBranchAddress("bb.hodotdc.allclus.id", &bb_hodotdc_allclus_id, &b_bb_hodotdc_allclus_id);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.allclus.itrack", &Ndata_bb_hodotdc_allclus_itrack, &b_Ndata_bb_hodotdc_allclus_itrack);
   fChain->SetBranchAddress("bb.hodotdc.allclus.itrack", &bb_hodotdc_allclus_itrack, &b_bb_hodotdc_allclus_itrack);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.allclus.size", &Ndata_bb_hodotdc_allclus_size, &b_Ndata_bb_hodotdc_allclus_size);
   fChain->SetBranchAddress("bb.hodotdc.allclus.size", &bb_hodotdc_allclus_size, &b_bb_hodotdc_allclus_size);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.allclus.tdiff", &Ndata_bb_hodotdc_allclus_tdiff, &b_Ndata_bb_hodotdc_allclus_tdiff);
   fChain->SetBranchAddress("bb.hodotdc.allclus.tdiff", &bb_hodotdc_allclus_tdiff, &b_bb_hodotdc_allclus_tdiff);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.allclus.tmean", &Ndata_bb_hodotdc_allclus_tmean, &b_Ndata_bb_hodotdc_allclus_tmean);
   fChain->SetBranchAddress("bb.hodotdc.allclus.tmean", &bb_hodotdc_allclus_tmean, &b_bb_hodotdc_allclus_tmean);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.allclus.totmean", &Ndata_bb_hodotdc_allclus_totmean, &b_Ndata_bb_hodotdc_allclus_totmean);
   fChain->SetBranchAddress("bb.hodotdc.allclus.totmean", &bb_hodotdc_allclus_totmean, &b_bb_hodotdc_allclus_totmean);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.allclus.xmean", &Ndata_bb_hodotdc_allclus_xmean, &b_Ndata_bb_hodotdc_allclus_xmean);
   fChain->SetBranchAddress("bb.hodotdc.allclus.xmean", &bb_hodotdc_allclus_xmean, &b_bb_hodotdc_allclus_xmean);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.allclus.ymean", &Ndata_bb_hodotdc_allclus_ymean, &b_Ndata_bb_hodotdc_allclus_ymean);
   fChain->SetBranchAddress("bb.hodotdc.allclus.ymean", &bb_hodotdc_allclus_ymean, &b_bb_hodotdc_allclus_ymean);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.L.le", &Ndata_bb_hodotdc_bar_tdc_L_le, &b_Ndata_bb_hodotdc_bar_tdc_L_le);
   fChain->SetBranchAddress("bb.hodotdc.bar.tdc.L.le", &bb_hodotdc_bar_tdc_L_le, &b_bb_hodotdc_bar_tdc_L_le);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.L.leW", &Ndata_bb_hodotdc_bar_tdc_L_leW, &b_Ndata_bb_hodotdc_bar_tdc_L_leW);
   fChain->SetBranchAddress("bb.hodotdc.bar.tdc.L.leW", &bb_hodotdc_bar_tdc_L_leW, &b_bb_hodotdc_bar_tdc_L_leW);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.L.te", &Ndata_bb_hodotdc_bar_tdc_L_te, &b_Ndata_bb_hodotdc_bar_tdc_L_te);
   fChain->SetBranchAddress("bb.hodotdc.bar.tdc.L.te", &bb_hodotdc_bar_tdc_L_te, &b_bb_hodotdc_bar_tdc_L_te);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.L.teW", &Ndata_bb_hodotdc_bar_tdc_L_teW, &b_Ndata_bb_hodotdc_bar_tdc_L_teW);
   fChain->SetBranchAddress("bb.hodotdc.bar.tdc.L.teW", &bb_hodotdc_bar_tdc_L_teW, &b_bb_hodotdc_bar_tdc_L_teW);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.L.tot", &Ndata_bb_hodotdc_bar_tdc_L_tot, &b_Ndata_bb_hodotdc_bar_tdc_L_tot);
   fChain->SetBranchAddress("bb.hodotdc.bar.tdc.L.tot", &bb_hodotdc_bar_tdc_L_tot, &b_bb_hodotdc_bar_tdc_L_tot);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.L.totW", &Ndata_bb_hodotdc_bar_tdc_L_totW, &b_Ndata_bb_hodotdc_bar_tdc_L_totW);
   fChain->SetBranchAddress("bb.hodotdc.bar.tdc.L.totW", &bb_hodotdc_bar_tdc_L_totW, &b_bb_hodotdc_bar_tdc_L_totW);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.R.le", &Ndata_bb_hodotdc_bar_tdc_R_le, &b_Ndata_bb_hodotdc_bar_tdc_R_le);
   fChain->SetBranchAddress("bb.hodotdc.bar.tdc.R.le", &bb_hodotdc_bar_tdc_R_le, &b_bb_hodotdc_bar_tdc_R_le);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.R.leW", &Ndata_bb_hodotdc_bar_tdc_R_leW, &b_Ndata_bb_hodotdc_bar_tdc_R_leW);
   fChain->SetBranchAddress("bb.hodotdc.bar.tdc.R.leW", &bb_hodotdc_bar_tdc_R_leW, &b_bb_hodotdc_bar_tdc_R_leW);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.R.te", &Ndata_bb_hodotdc_bar_tdc_R_te, &b_Ndata_bb_hodotdc_bar_tdc_R_te);
   fChain->SetBranchAddress("bb.hodotdc.bar.tdc.R.te", &bb_hodotdc_bar_tdc_R_te, &b_bb_hodotdc_bar_tdc_R_te);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.R.teW", &Ndata_bb_hodotdc_bar_tdc_R_teW, &b_Ndata_bb_hodotdc_bar_tdc_R_teW);
   fChain->SetBranchAddress("bb.hodotdc.bar.tdc.R.teW", &bb_hodotdc_bar_tdc_R_teW, &b_bb_hodotdc_bar_tdc_R_teW);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.R.tot", &Ndata_bb_hodotdc_bar_tdc_R_tot, &b_Ndata_bb_hodotdc_bar_tdc_R_tot);
   fChain->SetBranchAddress("bb.hodotdc.bar.tdc.R.tot", &bb_hodotdc_bar_tdc_R_tot, &b_bb_hodotdc_bar_tdc_R_tot);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.R.totW", &Ndata_bb_hodotdc_bar_tdc_R_totW, &b_Ndata_bb_hodotdc_bar_tdc_R_totW);
   fChain->SetBranchAddress("bb.hodotdc.bar.tdc.R.totW", &bb_hodotdc_bar_tdc_R_totW, &b_bb_hodotdc_bar_tdc_R_totW);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.id", &Ndata_bb_hodotdc_bar_tdc_id, &b_Ndata_bb_hodotdc_bar_tdc_id);
   fChain->SetBranchAddress("bb.hodotdc.bar.tdc.id", &bb_hodotdc_bar_tdc_id, &b_bb_hodotdc_bar_tdc_id);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.meantime", &Ndata_bb_hodotdc_bar_tdc_meantime, &b_Ndata_bb_hodotdc_bar_tdc_meantime);
   fChain->SetBranchAddress("bb.hodotdc.bar.tdc.meantime", &bb_hodotdc_bar_tdc_meantime, &b_bb_hodotdc_bar_tdc_meantime);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.timediff", &Ndata_bb_hodotdc_bar_tdc_timediff, &b_Ndata_bb_hodotdc_bar_tdc_timediff);
   fChain->SetBranchAddress("bb.hodotdc.bar.tdc.timediff", &bb_hodotdc_bar_tdc_timediff, &b_bb_hodotdc_bar_tdc_timediff);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.timehitpos", &Ndata_bb_hodotdc_bar_tdc_timehitpos, &b_Ndata_bb_hodotdc_bar_tdc_timehitpos);
   fChain->SetBranchAddress("bb.hodotdc.bar.tdc.timehitpos", &bb_hodotdc_bar_tdc_timehitpos, &b_bb_hodotdc_bar_tdc_timehitpos);
   fChain->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.vpos", &Ndata_bb_hodotdc_bar_tdc_vpos, &b_Ndata_bb_hodotdc_bar_tdc_vpos);
   fChain->SetBranchAddress("bb.hodotdc.bar.tdc.vpos", &bb_hodotdc_bar_tdc_vpos, &b_bb_hodotdc_bar_tdc_vpos);
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
   fChain->SetBranchAddress("Ndata.bb.ps.clus.again", &Ndata_bb_ps_clus_again, &b_Ndata_bb_ps_clus_again);
   fChain->SetBranchAddress("bb.ps.clus.again", bb_ps_clus_again, &b_bb_ps_clus_again);
   fChain->SetBranchAddress("Ndata.bb.ps.clus.atime", &Ndata_bb_ps_clus_atime, &b_Ndata_bb_ps_clus_atime);
   fChain->SetBranchAddress("bb.ps.clus.atime", bb_ps_clus_atime, &b_bb_ps_clus_atime);
   fChain->SetBranchAddress("Ndata.bb.ps.clus.col", &Ndata_bb_ps_clus_col, &b_Ndata_bb_ps_clus_col);
   fChain->SetBranchAddress("bb.ps.clus.col", bb_ps_clus_col, &b_bb_ps_clus_col);
   fChain->SetBranchAddress("Ndata.bb.ps.clus.e", &Ndata_bb_ps_clus_e, &b_Ndata_bb_ps_clus_e);
   fChain->SetBranchAddress("bb.ps.clus.e", bb_ps_clus_e, &b_bb_ps_clus_e);
   fChain->SetBranchAddress("Ndata.bb.ps.clus.eblk", &Ndata_bb_ps_clus_eblk, &b_Ndata_bb_ps_clus_eblk);
   fChain->SetBranchAddress("bb.ps.clus.eblk", bb_ps_clus_eblk, &b_bb_ps_clus_eblk);
   fChain->SetBranchAddress("Ndata.bb.ps.clus.id", &Ndata_bb_ps_clus_id, &b_Ndata_bb_ps_clus_id);
   fChain->SetBranchAddress("bb.ps.clus.id", bb_ps_clus_id, &b_bb_ps_clus_id);
   fChain->SetBranchAddress("Ndata.bb.ps.clus.nblk", &Ndata_bb_ps_clus_nblk, &b_Ndata_bb_ps_clus_nblk);
   fChain->SetBranchAddress("bb.ps.clus.nblk", bb_ps_clus_nblk, &b_bb_ps_clus_nblk);
   fChain->SetBranchAddress("Ndata.bb.ps.clus.row", &Ndata_bb_ps_clus_row, &b_Ndata_bb_ps_clus_row);
   fChain->SetBranchAddress("bb.ps.clus.row", bb_ps_clus_row, &b_bb_ps_clus_row);
   fChain->SetBranchAddress("Ndata.bb.ps.clus.tdctime", &Ndata_bb_ps_clus_tdctime, &b_Ndata_bb_ps_clus_tdctime);
   fChain->SetBranchAddress("bb.ps.clus.tdctime", bb_ps_clus_tdctime, &b_bb_ps_clus_tdctime);
   fChain->SetBranchAddress("Ndata.bb.ps.clus.x", &Ndata_bb_ps_clus_x, &b_Ndata_bb_ps_clus_x);
   fChain->SetBranchAddress("bb.ps.clus.x", bb_ps_clus_x, &b_bb_ps_clus_x);
   fChain->SetBranchAddress("Ndata.bb.ps.clus.y", &Ndata_bb_ps_clus_y, &b_Ndata_bb_ps_clus_y);
   fChain->SetBranchAddress("bb.ps.clus.y", bb_ps_clus_y, &b_bb_ps_clus_y);
   fChain->SetBranchAddress("Ndata.bb.ps.clus_blk.again", &Ndata_bb_ps_clus_blk_again, &b_Ndata_bb_ps_clus_blk_again);
   fChain->SetBranchAddress("bb.ps.clus_blk.again", bb_ps_clus_blk_again, &b_bb_ps_clus_blk_again);
   fChain->SetBranchAddress("Ndata.bb.ps.clus_blk.atime", &Ndata_bb_ps_clus_blk_atime, &b_Ndata_bb_ps_clus_blk_atime);
   fChain->SetBranchAddress("bb.ps.clus_blk.atime", bb_ps_clus_blk_atime, &b_bb_ps_clus_blk_atime);
   fChain->SetBranchAddress("Ndata.bb.ps.clus_blk.col", &Ndata_bb_ps_clus_blk_col, &b_Ndata_bb_ps_clus_blk_col);
   fChain->SetBranchAddress("bb.ps.clus_blk.col", bb_ps_clus_blk_col, &b_bb_ps_clus_blk_col);
   fChain->SetBranchAddress("Ndata.bb.ps.clus_blk.e", &Ndata_bb_ps_clus_blk_e, &b_Ndata_bb_ps_clus_blk_e);
   fChain->SetBranchAddress("bb.ps.clus_blk.e", bb_ps_clus_blk_e, &b_bb_ps_clus_blk_e);
   fChain->SetBranchAddress("Ndata.bb.ps.clus_blk.id", &Ndata_bb_ps_clus_blk_id, &b_Ndata_bb_ps_clus_blk_id);
   fChain->SetBranchAddress("bb.ps.clus_blk.id", bb_ps_clus_blk_id, &b_bb_ps_clus_blk_id);
   fChain->SetBranchAddress("Ndata.bb.ps.clus_blk.row", &Ndata_bb_ps_clus_blk_row, &b_Ndata_bb_ps_clus_blk_row);
   fChain->SetBranchAddress("bb.ps.clus_blk.row", bb_ps_clus_blk_row, &b_bb_ps_clus_blk_row);
   fChain->SetBranchAddress("Ndata.bb.ps.clus_blk.tdctime", &Ndata_bb_ps_clus_blk_tdctime, &b_Ndata_bb_ps_clus_blk_tdctime);
   fChain->SetBranchAddress("bb.ps.clus_blk.tdctime", bb_ps_clus_blk_tdctime, &b_bb_ps_clus_blk_tdctime);
   fChain->SetBranchAddress("Ndata.bb.ps.clus_blk.x", &Ndata_bb_ps_clus_blk_x, &b_Ndata_bb_ps_clus_blk_x);
   fChain->SetBranchAddress("bb.ps.clus_blk.x", bb_ps_clus_blk_x, &b_bb_ps_clus_blk_x);
   fChain->SetBranchAddress("Ndata.bb.ps.clus_blk.y", &Ndata_bb_ps_clus_blk_y, &b_Ndata_bb_ps_clus_blk_y);
   fChain->SetBranchAddress("bb.ps.clus_blk.y", bb_ps_clus_blk_y, &b_bb_ps_clus_blk_y);
   fChain->SetBranchAddress("Ndata.bb.sh.clus.again", &Ndata_bb_sh_clus_again, &b_Ndata_bb_sh_clus_again);
   fChain->SetBranchAddress("bb.sh.clus.again", bb_sh_clus_again, &b_bb_sh_clus_again);
   fChain->SetBranchAddress("Ndata.bb.sh.clus.atime", &Ndata_bb_sh_clus_atime, &b_Ndata_bb_sh_clus_atime);
   fChain->SetBranchAddress("bb.sh.clus.atime", bb_sh_clus_atime, &b_bb_sh_clus_atime);
   fChain->SetBranchAddress("Ndata.bb.sh.clus.col", &Ndata_bb_sh_clus_col, &b_Ndata_bb_sh_clus_col);
   fChain->SetBranchAddress("bb.sh.clus.col", bb_sh_clus_col, &b_bb_sh_clus_col);
   fChain->SetBranchAddress("Ndata.bb.sh.clus.e", &Ndata_bb_sh_clus_e, &b_Ndata_bb_sh_clus_e);
   fChain->SetBranchAddress("bb.sh.clus.e", bb_sh_clus_e, &b_bb_sh_clus_e);
   fChain->SetBranchAddress("Ndata.bb.sh.clus.eblk", &Ndata_bb_sh_clus_eblk, &b_Ndata_bb_sh_clus_eblk);
   fChain->SetBranchAddress("bb.sh.clus.eblk", bb_sh_clus_eblk, &b_bb_sh_clus_eblk);
   fChain->SetBranchAddress("Ndata.bb.sh.clus.id", &Ndata_bb_sh_clus_id, &b_Ndata_bb_sh_clus_id);
   fChain->SetBranchAddress("bb.sh.clus.id", bb_sh_clus_id, &b_bb_sh_clus_id);
   fChain->SetBranchAddress("Ndata.bb.sh.clus.nblk", &Ndata_bb_sh_clus_nblk, &b_Ndata_bb_sh_clus_nblk);
   fChain->SetBranchAddress("bb.sh.clus.nblk", bb_sh_clus_nblk, &b_bb_sh_clus_nblk);
   fChain->SetBranchAddress("Ndata.bb.sh.clus.row", &Ndata_bb_sh_clus_row, &b_Ndata_bb_sh_clus_row);
   fChain->SetBranchAddress("bb.sh.clus.row", bb_sh_clus_row, &b_bb_sh_clus_row);
   fChain->SetBranchAddress("Ndata.bb.sh.clus.tdctime", &Ndata_bb_sh_clus_tdctime, &b_Ndata_bb_sh_clus_tdctime);
   fChain->SetBranchAddress("bb.sh.clus.tdctime", bb_sh_clus_tdctime, &b_bb_sh_clus_tdctime);
   fChain->SetBranchAddress("Ndata.bb.sh.clus.x", &Ndata_bb_sh_clus_x, &b_Ndata_bb_sh_clus_x);
   fChain->SetBranchAddress("bb.sh.clus.x", bb_sh_clus_x, &b_bb_sh_clus_x);
   fChain->SetBranchAddress("Ndata.bb.sh.clus.y", &Ndata_bb_sh_clus_y, &b_Ndata_bb_sh_clus_y);
   fChain->SetBranchAddress("bb.sh.clus.y", bb_sh_clus_y, &b_bb_sh_clus_y);
   fChain->SetBranchAddress("Ndata.bb.sh.clus_blk.again", &Ndata_bb_sh_clus_blk_again, &b_Ndata_bb_sh_clus_blk_again);
   fChain->SetBranchAddress("bb.sh.clus_blk.again", bb_sh_clus_blk_again, &b_bb_sh_clus_blk_again);
   fChain->SetBranchAddress("Ndata.bb.sh.clus_blk.atime", &Ndata_bb_sh_clus_blk_atime, &b_Ndata_bb_sh_clus_blk_atime);
   fChain->SetBranchAddress("bb.sh.clus_blk.atime", bb_sh_clus_blk_atime, &b_bb_sh_clus_blk_atime);
   fChain->SetBranchAddress("Ndata.bb.sh.clus_blk.col", &Ndata_bb_sh_clus_blk_col, &b_Ndata_bb_sh_clus_blk_col);
   fChain->SetBranchAddress("bb.sh.clus_blk.col", bb_sh_clus_blk_col, &b_bb_sh_clus_blk_col);
   fChain->SetBranchAddress("Ndata.bb.sh.clus_blk.e", &Ndata_bb_sh_clus_blk_e, &b_Ndata_bb_sh_clus_blk_e);
   fChain->SetBranchAddress("bb.sh.clus_blk.e", bb_sh_clus_blk_e, &b_bb_sh_clus_blk_e);
   fChain->SetBranchAddress("Ndata.bb.sh.clus_blk.id", &Ndata_bb_sh_clus_blk_id, &b_Ndata_bb_sh_clus_blk_id);
   fChain->SetBranchAddress("bb.sh.clus_blk.id", bb_sh_clus_blk_id, &b_bb_sh_clus_blk_id);
   fChain->SetBranchAddress("Ndata.bb.sh.clus_blk.row", &Ndata_bb_sh_clus_blk_row, &b_Ndata_bb_sh_clus_blk_row);
   fChain->SetBranchAddress("bb.sh.clus_blk.row", bb_sh_clus_blk_row, &b_bb_sh_clus_blk_row);
   fChain->SetBranchAddress("Ndata.bb.sh.clus_blk.tdctime", &Ndata_bb_sh_clus_blk_tdctime, &b_Ndata_bb_sh_clus_blk_tdctime);
   fChain->SetBranchAddress("bb.sh.clus_blk.tdctime", bb_sh_clus_blk_tdctime, &b_bb_sh_clus_blk_tdctime);
   fChain->SetBranchAddress("Ndata.bb.sh.clus_blk.x", &Ndata_bb_sh_clus_blk_x, &b_Ndata_bb_sh_clus_blk_x);
   fChain->SetBranchAddress("bb.sh.clus_blk.x", bb_sh_clus_blk_x, &b_bb_sh_clus_blk_x);
   fChain->SetBranchAddress("Ndata.bb.sh.clus_blk.y", &Ndata_bb_sh_clus_blk_y, &b_Ndata_bb_sh_clus_blk_y);
   fChain->SetBranchAddress("bb.sh.clus_blk.y", bb_sh_clus_blk_y, &b_bb_sh_clus_blk_y);
   fChain->SetBranchAddress("Ndata.bb.tdctrig.tdc", &Ndata_bb_tdctrig_tdc, &b_Ndata_bb_tdctrig_tdc);
   fChain->SetBranchAddress("bb.tdctrig.tdc", bb_tdctrig_tdc, &b_bb_tdctrig_tdc);
   fChain->SetBranchAddress("Ndata.bb.tdctrig.tdcelemID", &Ndata_bb_tdctrig_tdcelemID, &b_Ndata_bb_tdctrig_tdcelemID);
   fChain->SetBranchAddress("bb.tdctrig.tdcelemID", bb_tdctrig_tdcelemID, &b_bb_tdctrig_tdcelemID);
   fChain->SetBranchAddress("Ndata.bb.tr.beta", &Ndata_bb_tr_beta, &b_Ndata_bb_tr_beta);
   fChain->SetBranchAddress("bb.tr.beta", bb_tr_beta, &b_bb_tr_beta);
   fChain->SetBranchAddress("Ndata.bb.tr.chi2", &Ndata_bb_tr_chi2, &b_Ndata_bb_tr_chi2);
   fChain->SetBranchAddress("bb.tr.chi2", bb_tr_chi2, &b_bb_tr_chi2);
   fChain->SetBranchAddress("Ndata.bb.tr.d_ph", &Ndata_bb_tr_d_ph, &b_Ndata_bb_tr_d_ph);
   fChain->SetBranchAddress("bb.tr.d_ph", bb_tr_d_ph, &b_bb_tr_d_ph);
   fChain->SetBranchAddress("Ndata.bb.tr.d_th", &Ndata_bb_tr_d_th, &b_Ndata_bb_tr_d_th);
   fChain->SetBranchAddress("bb.tr.d_th", bb_tr_d_th, &b_bb_tr_d_th);
   fChain->SetBranchAddress("Ndata.bb.tr.d_x", &Ndata_bb_tr_d_x, &b_Ndata_bb_tr_d_x);
   fChain->SetBranchAddress("bb.tr.d_x", bb_tr_d_x, &b_bb_tr_d_x);
   fChain->SetBranchAddress("Ndata.bb.tr.d_y", &Ndata_bb_tr_d_y, &b_Ndata_bb_tr_d_y);
   fChain->SetBranchAddress("bb.tr.d_y", bb_tr_d_y, &b_bb_tr_d_y);
   fChain->SetBranchAddress("Ndata.bb.tr.dbeta", &Ndata_bb_tr_dbeta, &b_Ndata_bb_tr_dbeta);
   fChain->SetBranchAddress("bb.tr.dbeta", bb_tr_dbeta, &b_bb_tr_dbeta);
   fChain->SetBranchAddress("Ndata.bb.tr.dtime", &Ndata_bb_tr_dtime, &b_Ndata_bb_tr_dtime);
   fChain->SetBranchAddress("bb.tr.dtime", bb_tr_dtime, &b_bb_tr_dtime);
   fChain->SetBranchAddress("Ndata.bb.tr.flag", &Ndata_bb_tr_flag, &b_Ndata_bb_tr_flag);
   fChain->SetBranchAddress("bb.tr.flag", bb_tr_flag, &b_bb_tr_flag);
   fChain->SetBranchAddress("Ndata.bb.tr.ndof", &Ndata_bb_tr_ndof, &b_Ndata_bb_tr_ndof);
   fChain->SetBranchAddress("bb.tr.ndof", bb_tr_ndof, &b_bb_tr_ndof);
   fChain->SetBranchAddress("Ndata.bb.tr.p", &Ndata_bb_tr_p, &b_Ndata_bb_tr_p);
   fChain->SetBranchAddress("bb.tr.p", bb_tr_p, &b_bb_tr_p);
   fChain->SetBranchAddress("Ndata.bb.tr.pathl", &Ndata_bb_tr_pathl, &b_Ndata_bb_tr_pathl);
   fChain->SetBranchAddress("bb.tr.pathl", bb_tr_pathl, &b_bb_tr_pathl);
   fChain->SetBranchAddress("Ndata.bb.tr.ph", &Ndata_bb_tr_ph, &b_Ndata_bb_tr_ph);
   fChain->SetBranchAddress("bb.tr.ph", bb_tr_ph, &b_bb_tr_ph);
   fChain->SetBranchAddress("Ndata.bb.tr.px", &Ndata_bb_tr_px, &b_Ndata_bb_tr_px);
   fChain->SetBranchAddress("bb.tr.px", bb_tr_px, &b_bb_tr_px);
   fChain->SetBranchAddress("Ndata.bb.tr.py", &Ndata_bb_tr_py, &b_Ndata_bb_tr_py);
   fChain->SetBranchAddress("bb.tr.py", bb_tr_py, &b_bb_tr_py);
   fChain->SetBranchAddress("Ndata.bb.tr.pz", &Ndata_bb_tr_pz, &b_Ndata_bb_tr_pz);
   fChain->SetBranchAddress("bb.tr.pz", bb_tr_pz, &b_bb_tr_pz);
   fChain->SetBranchAddress("Ndata.bb.tr.r_ph", &Ndata_bb_tr_r_ph, &b_Ndata_bb_tr_r_ph);
   fChain->SetBranchAddress("bb.tr.r_ph", bb_tr_r_ph, &b_bb_tr_r_ph);
   fChain->SetBranchAddress("Ndata.bb.tr.r_th", &Ndata_bb_tr_r_th, &b_Ndata_bb_tr_r_th);
   fChain->SetBranchAddress("bb.tr.r_th", bb_tr_r_th, &b_bb_tr_r_th);
   fChain->SetBranchAddress("Ndata.bb.tr.r_x", &Ndata_bb_tr_r_x, &b_Ndata_bb_tr_r_x);
   fChain->SetBranchAddress("bb.tr.r_x", bb_tr_r_x, &b_bb_tr_r_x);
   fChain->SetBranchAddress("Ndata.bb.tr.r_y", &Ndata_bb_tr_r_y, &b_Ndata_bb_tr_r_y);
   fChain->SetBranchAddress("bb.tr.r_y", bb_tr_r_y, &b_bb_tr_r_y);
   fChain->SetBranchAddress("Ndata.bb.tr.tg_dp", &Ndata_bb_tr_tg_dp, &b_Ndata_bb_tr_tg_dp);
   fChain->SetBranchAddress("bb.tr.tg_dp", bb_tr_tg_dp, &b_bb_tr_tg_dp);
   fChain->SetBranchAddress("Ndata.bb.tr.tg_ph", &Ndata_bb_tr_tg_ph, &b_Ndata_bb_tr_tg_ph);
   fChain->SetBranchAddress("bb.tr.tg_ph", bb_tr_tg_ph, &b_bb_tr_tg_ph);
   fChain->SetBranchAddress("Ndata.bb.tr.tg_th", &Ndata_bb_tr_tg_th, &b_Ndata_bb_tr_tg_th);
   fChain->SetBranchAddress("bb.tr.tg_th", bb_tr_tg_th, &b_bb_tr_tg_th);
   fChain->SetBranchAddress("Ndata.bb.tr.tg_x", &Ndata_bb_tr_tg_x, &b_Ndata_bb_tr_tg_x);
   fChain->SetBranchAddress("bb.tr.tg_x", bb_tr_tg_x, &b_bb_tr_tg_x);
   fChain->SetBranchAddress("Ndata.bb.tr.tg_y", &Ndata_bb_tr_tg_y, &b_Ndata_bb_tr_tg_y);
   fChain->SetBranchAddress("bb.tr.tg_y", bb_tr_tg_y, &b_bb_tr_tg_y);
   fChain->SetBranchAddress("Ndata.bb.tr.th", &Ndata_bb_tr_th, &b_Ndata_bb_tr_th);
   fChain->SetBranchAddress("bb.tr.th", bb_tr_th, &b_bb_tr_th);
   fChain->SetBranchAddress("Ndata.bb.tr.time", &Ndata_bb_tr_time, &b_Ndata_bb_tr_time);
   fChain->SetBranchAddress("bb.tr.time", bb_tr_time, &b_bb_tr_time);
   fChain->SetBranchAddress("Ndata.bb.tr.vx", &Ndata_bb_tr_vx, &b_Ndata_bb_tr_vx);
   fChain->SetBranchAddress("bb.tr.vx", bb_tr_vx, &b_bb_tr_vx);
   fChain->SetBranchAddress("Ndata.bb.tr.vy", &Ndata_bb_tr_vy, &b_Ndata_bb_tr_vy);
   fChain->SetBranchAddress("bb.tr.vy", bb_tr_vy, &b_bb_tr_vy);
   fChain->SetBranchAddress("Ndata.bb.tr.vz", &Ndata_bb_tr_vz, &b_Ndata_bb_tr_vz);
   fChain->SetBranchAddress("bb.tr.vz", bb_tr_vz, &b_bb_tr_vz);
   fChain->SetBranchAddress("Ndata.bb.tr.x", &Ndata_bb_tr_x, &b_Ndata_bb_tr_x);
   fChain->SetBranchAddress("bb.tr.x", bb_tr_x, &b_bb_tr_x);
   fChain->SetBranchAddress("Ndata.bb.tr.y", &Ndata_bb_tr_y, &b_Ndata_bb_tr_y);
   fChain->SetBranchAddress("bb.tr.y", bb_tr_y, &b_bb_tr_y);
   fChain->SetBranchAddress("Ndata.bb.x_bcp", &Ndata_bb_x_bcp, &b_Ndata_bb_x_bcp);
   fChain->SetBranchAddress("bb.x_bcp", bb_x_bcp, &b_bb_x_bcp);
   fChain->SetBranchAddress("Ndata.bb.x_fcp", &Ndata_bb_x_fcp, &b_Ndata_bb_x_fcp);
   fChain->SetBranchAddress("bb.x_fcp", bb_x_fcp, &b_bb_x_fcp);
   fChain->SetBranchAddress("Ndata.bb.y_bcp", &Ndata_bb_y_bcp, &b_Ndata_bb_y_bcp);
   fChain->SetBranchAddress("bb.y_bcp", bb_y_bcp, &b_bb_y_bcp);
   fChain->SetBranchAddress("Ndata.bb.y_fcp", &Ndata_bb_y_fcp, &b_Ndata_bb_y_fcp);
   fChain->SetBranchAddress("bb.y_fcp", bb_y_fcp, &b_bb_y_fcp);
   fChain->SetBranchAddress("Ndata.bb.z_bcp", &Ndata_bb_z_bcp, &b_Ndata_bb_z_bcp);
   fChain->SetBranchAddress("bb.z_bcp", bb_z_bcp, &b_bb_z_bcp);
   fChain->SetBranchAddress("Ndata.bb.z_fcp", &Ndata_bb_z_fcp, &b_Ndata_bb_z_fcp);
   fChain->SetBranchAddress("bb.z_fcp", bb_z_fcp, &b_bb_z_fcp);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus.again", &Ndata_sbs_hcal_clus_again, &b_Ndata_sbs_hcal_clus_again);
   fChain->SetBranchAddress("sbs.hcal.clus.again", sbs_hcal_clus_again, &b_sbs_hcal_clus_again);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus.atime", &Ndata_sbs_hcal_clus_atime, &b_Ndata_sbs_hcal_clus_atime);
   fChain->SetBranchAddress("sbs.hcal.clus.atime", sbs_hcal_clus_atime, &b_sbs_hcal_clus_atime);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus.col", &Ndata_sbs_hcal_clus_col, &b_Ndata_sbs_hcal_clus_col);
   fChain->SetBranchAddress("sbs.hcal.clus.col", sbs_hcal_clus_col, &b_sbs_hcal_clus_col);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus.e", &Ndata_sbs_hcal_clus_e, &b_Ndata_sbs_hcal_clus_e);
   fChain->SetBranchAddress("sbs.hcal.clus.e", sbs_hcal_clus_e, &b_sbs_hcal_clus_e);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus.eblk", &Ndata_sbs_hcal_clus_eblk, &b_Ndata_sbs_hcal_clus_eblk);
   fChain->SetBranchAddress("sbs.hcal.clus.eblk", sbs_hcal_clus_eblk, &b_sbs_hcal_clus_eblk);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus.id", &Ndata_sbs_hcal_clus_id, &b_Ndata_sbs_hcal_clus_id);
   fChain->SetBranchAddress("sbs.hcal.clus.id", sbs_hcal_clus_id, &b_sbs_hcal_clus_id);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus.nblk", &Ndata_sbs_hcal_clus_nblk, &b_Ndata_sbs_hcal_clus_nblk);
   fChain->SetBranchAddress("sbs.hcal.clus.nblk", sbs_hcal_clus_nblk, &b_sbs_hcal_clus_nblk);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus.row", &Ndata_sbs_hcal_clus_row, &b_Ndata_sbs_hcal_clus_row);
   fChain->SetBranchAddress("sbs.hcal.clus.row", sbs_hcal_clus_row, &b_sbs_hcal_clus_row);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus.tdctime", &Ndata_sbs_hcal_clus_tdctime, &b_Ndata_sbs_hcal_clus_tdctime);
   fChain->SetBranchAddress("sbs.hcal.clus.tdctime", sbs_hcal_clus_tdctime, &b_sbs_hcal_clus_tdctime);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus.x", &Ndata_sbs_hcal_clus_x, &b_Ndata_sbs_hcal_clus_x);
   fChain->SetBranchAddress("sbs.hcal.clus.x", sbs_hcal_clus_x, &b_sbs_hcal_clus_x);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus.y", &Ndata_sbs_hcal_clus_y, &b_Ndata_sbs_hcal_clus_y);
   fChain->SetBranchAddress("sbs.hcal.clus.y", sbs_hcal_clus_y, &b_sbs_hcal_clus_y);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus_blk.again", &Ndata_sbs_hcal_clus_blk_again, &b_Ndata_sbs_hcal_clus_blk_again);
   fChain->SetBranchAddress("sbs.hcal.clus_blk.again", sbs_hcal_clus_blk_again, &b_sbs_hcal_clus_blk_again);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus_blk.atime", &Ndata_sbs_hcal_clus_blk_atime, &b_Ndata_sbs_hcal_clus_blk_atime);
   fChain->SetBranchAddress("sbs.hcal.clus_blk.atime", sbs_hcal_clus_blk_atime, &b_sbs_hcal_clus_blk_atime);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus_blk.col", &Ndata_sbs_hcal_clus_blk_col, &b_Ndata_sbs_hcal_clus_blk_col);
   fChain->SetBranchAddress("sbs.hcal.clus_blk.col", sbs_hcal_clus_blk_col, &b_sbs_hcal_clus_blk_col);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus_blk.e", &Ndata_sbs_hcal_clus_blk_e, &b_Ndata_sbs_hcal_clus_blk_e);
   fChain->SetBranchAddress("sbs.hcal.clus_blk.e", sbs_hcal_clus_blk_e, &b_sbs_hcal_clus_blk_e);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus_blk.id", &Ndata_sbs_hcal_clus_blk_id, &b_Ndata_sbs_hcal_clus_blk_id);
   fChain->SetBranchAddress("sbs.hcal.clus_blk.id", sbs_hcal_clus_blk_id, &b_sbs_hcal_clus_blk_id);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus_blk.row", &Ndata_sbs_hcal_clus_blk_row, &b_Ndata_sbs_hcal_clus_blk_row);
   fChain->SetBranchAddress("sbs.hcal.clus_blk.row", sbs_hcal_clus_blk_row, &b_sbs_hcal_clus_blk_row);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus_blk.tdctime", &Ndata_sbs_hcal_clus_blk_tdctime, &b_Ndata_sbs_hcal_clus_blk_tdctime);
   fChain->SetBranchAddress("sbs.hcal.clus_blk.tdctime", sbs_hcal_clus_blk_tdctime, &b_sbs_hcal_clus_blk_tdctime);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus_blk.x", &Ndata_sbs_hcal_clus_blk_x, &b_Ndata_sbs_hcal_clus_blk_x);
   fChain->SetBranchAddress("sbs.hcal.clus_blk.x", sbs_hcal_clus_blk_x, &b_sbs_hcal_clus_blk_x);
   fChain->SetBranchAddress("Ndata.sbs.hcal.clus_blk.y", &Ndata_sbs_hcal_clus_blk_y, &b_Ndata_sbs_hcal_clus_blk_y);
   fChain->SetBranchAddress("sbs.hcal.clus_blk.y", sbs_hcal_clus_blk_y, &b_sbs_hcal_clus_blk_y);
   fChain->SetBranchAddress("Ndata.sbs.hcal.goodblock.atime", &Ndata_sbs_hcal_goodblock_atime, &b_Ndata_sbs_hcal_goodblock_atime);
   fChain->SetBranchAddress("sbs.hcal.goodblock.atime", sbs_hcal_goodblock_atime, &b_sbs_hcal_goodblock_atime);
   fChain->SetBranchAddress("Ndata.sbs.hcal.goodblock.cid", &Ndata_sbs_hcal_goodblock_cid, &b_Ndata_sbs_hcal_goodblock_cid);
   fChain->SetBranchAddress("sbs.hcal.goodblock.cid", sbs_hcal_goodblock_cid, &b_sbs_hcal_goodblock_cid);
   fChain->SetBranchAddress("Ndata.sbs.hcal.goodblock.col", &Ndata_sbs_hcal_goodblock_col, &b_Ndata_sbs_hcal_goodblock_col);
   fChain->SetBranchAddress("sbs.hcal.goodblock.col", sbs_hcal_goodblock_col, &b_sbs_hcal_goodblock_col);
   fChain->SetBranchAddress("Ndata.sbs.hcal.goodblock.e", &Ndata_sbs_hcal_goodblock_e, &b_Ndata_sbs_hcal_goodblock_e);
   fChain->SetBranchAddress("sbs.hcal.goodblock.e", sbs_hcal_goodblock_e, &b_sbs_hcal_goodblock_e);
   fChain->SetBranchAddress("Ndata.sbs.hcal.goodblock.id", &Ndata_sbs_hcal_goodblock_id, &b_Ndata_sbs_hcal_goodblock_id);
   fChain->SetBranchAddress("sbs.hcal.goodblock.id", sbs_hcal_goodblock_id, &b_sbs_hcal_goodblock_id);
   fChain->SetBranchAddress("Ndata.sbs.hcal.goodblock.row", &Ndata_sbs_hcal_goodblock_row, &b_Ndata_sbs_hcal_goodblock_row);
   fChain->SetBranchAddress("sbs.hcal.goodblock.row", sbs_hcal_goodblock_row, &b_sbs_hcal_goodblock_row);
   fChain->SetBranchAddress("Ndata.sbs.hcal.goodblock.tdctime", &Ndata_sbs_hcal_goodblock_tdctime, &b_Ndata_sbs_hcal_goodblock_tdctime);
   fChain->SetBranchAddress("sbs.hcal.goodblock.tdctime", sbs_hcal_goodblock_tdctime, &b_sbs_hcal_goodblock_tdctime);
   fChain->SetBranchAddress("Ndata.sbs.hcal.goodblock.x", &Ndata_sbs_hcal_goodblock_x, &b_Ndata_sbs_hcal_goodblock_x);
   fChain->SetBranchAddress("sbs.hcal.goodblock.x", sbs_hcal_goodblock_x, &b_sbs_hcal_goodblock_x);
   fChain->SetBranchAddress("Ndata.sbs.hcal.goodblock.y", &Ndata_sbs_hcal_goodblock_y, &b_Ndata_sbs_hcal_goodblock_y);
   fChain->SetBranchAddress("sbs.hcal.goodblock.y", sbs_hcal_goodblock_y, &b_sbs_hcal_goodblock_y);
   fChain->SetBranchAddress("Ndata.sbs.trig.a_amp_p", &Ndata_sbs_trig_a_amp_p, &b_Ndata_sbs_trig_a_amp_p);
   fChain->SetBranchAddress("sbs.trig.a_amp_p", sbs_trig_a_amp_p, &b_sbs_trig_a_amp_p);
   fChain->SetBranchAddress("Ndata.sbs.trig.a_p", &Ndata_sbs_trig_a_p, &b_Ndata_sbs_trig_a_p);
   fChain->SetBranchAddress("sbs.trig.a_p", sbs_trig_a_p, &b_sbs_trig_a_p);
   fChain->SetBranchAddress("Ndata.sbs.trig.a_time", &Ndata_sbs_trig_a_time, &b_Ndata_sbs_trig_a_time);
   fChain->SetBranchAddress("sbs.trig.a_time", sbs_trig_a_time, &b_sbs_trig_a_time);
   fChain->SetBranchAddress("Ndata.sbs.trig.adcelemID", &Ndata_sbs_trig_adcelemID, &b_Ndata_sbs_trig_adcelemID);
   fChain->SetBranchAddress("sbs.trig.adcelemID", sbs_trig_adcelemID, &b_sbs_trig_adcelemID);
   fChain->SetBranchAddress("BB.gold.beta", &BB_gold_beta, &b_BB_gold_beta);
   fChain->SetBranchAddress("BB.gold.dp", &BB_gold_dp, &b_BB_gold_dp);
   fChain->SetBranchAddress("BB.gold.index", &BB_gold_index, &b_BB_gold_index);
   fChain->SetBranchAddress("BB.gold.ok", &BB_gold_ok, &b_BB_gold_ok);
   fChain->SetBranchAddress("BB.gold.p", &BB_gold_p, &b_BB_gold_p);
   fChain->SetBranchAddress("BB.gold.ph", &BB_gold_ph, &b_BB_gold_ph);
   fChain->SetBranchAddress("BB.gold.px", &BB_gold_px, &b_BB_gold_px);
   fChain->SetBranchAddress("BB.gold.py", &BB_gold_py, &b_BB_gold_py);
   fChain->SetBranchAddress("BB.gold.pz", &BB_gold_pz, &b_BB_gold_pz);
   fChain->SetBranchAddress("BB.gold.th", &BB_gold_th, &b_BB_gold_th);
   fChain->SetBranchAddress("BB.gold.x", &BB_gold_x, &b_BB_gold_x);
   fChain->SetBranchAddress("BB.gold.y", &BB_gold_y, &b_BB_gold_y);
   fChain->SetBranchAddress("Lrb.BPMA.rawcur.1", &Lrb_BPMA_rawcur_1, &b_Lrb_BPMA_rawcur_1);
   fChain->SetBranchAddress("Lrb.BPMA.rawcur.2", &Lrb_BPMA_rawcur_2, &b_Lrb_BPMA_rawcur_2);
   fChain->SetBranchAddress("Lrb.BPMA.rawcur.3", &Lrb_BPMA_rawcur_3, &b_Lrb_BPMA_rawcur_3);
   fChain->SetBranchAddress("Lrb.BPMA.rawcur.4", &Lrb_BPMA_rawcur_4, &b_Lrb_BPMA_rawcur_4);
   fChain->SetBranchAddress("Lrb.BPMA.rotpos1", &Lrb_BPMA_rotpos1, &b_Lrb_BPMA_rotpos1);
   fChain->SetBranchAddress("Lrb.BPMA.rotpos2", &Lrb_BPMA_rotpos2, &b_Lrb_BPMA_rotpos2);
   fChain->SetBranchAddress("Lrb.BPMA.x", &Lrb_BPMA_x, &b_Lrb_BPMA_x);
   fChain->SetBranchAddress("Lrb.BPMA.y", &Lrb_BPMA_y, &b_Lrb_BPMA_y);
   fChain->SetBranchAddress("Lrb.BPMA.z", &Lrb_BPMA_z, &b_Lrb_BPMA_z);
   fChain->SetBranchAddress("Lrb.BPMB.rawcur.1", &Lrb_BPMB_rawcur_1, &b_Lrb_BPMB_rawcur_1);
   fChain->SetBranchAddress("Lrb.BPMB.rawcur.2", &Lrb_BPMB_rawcur_2, &b_Lrb_BPMB_rawcur_2);
   fChain->SetBranchAddress("Lrb.BPMB.rawcur.3", &Lrb_BPMB_rawcur_3, &b_Lrb_BPMB_rawcur_3);
   fChain->SetBranchAddress("Lrb.BPMB.rawcur.4", &Lrb_BPMB_rawcur_4, &b_Lrb_BPMB_rawcur_4);
   fChain->SetBranchAddress("Lrb.BPMB.rotpos1", &Lrb_BPMB_rotpos1, &b_Lrb_BPMB_rotpos1);
   fChain->SetBranchAddress("Lrb.BPMB.rotpos2", &Lrb_BPMB_rotpos2, &b_Lrb_BPMB_rotpos2);
   fChain->SetBranchAddress("Lrb.BPMB.x", &Lrb_BPMB_x, &b_Lrb_BPMB_x);
   fChain->SetBranchAddress("Lrb.BPMB.y", &Lrb_BPMB_y, &b_Lrb_BPMB_y);
   fChain->SetBranchAddress("Lrb.BPMB.z", &Lrb_BPMB_z, &b_Lrb_BPMB_z);
   fChain->SetBranchAddress("Lrb.Raster.bpma.x", &Lrb_Raster_bpma_x, &b_Lrb_Raster_bpma_x);
   fChain->SetBranchAddress("Lrb.Raster.bpma.y", &Lrb_Raster_bpma_y, &b_Lrb_Raster_bpma_y);
   fChain->SetBranchAddress("Lrb.Raster.bpma.z", &Lrb_Raster_bpma_z, &b_Lrb_Raster_bpma_z);
   fChain->SetBranchAddress("Lrb.Raster.bpmb.x", &Lrb_Raster_bpmb_x, &b_Lrb_Raster_bpmb_x);
   fChain->SetBranchAddress("Lrb.Raster.bpmb.y", &Lrb_Raster_bpmb_y, &b_Lrb_Raster_bpmb_y);
   fChain->SetBranchAddress("Lrb.Raster.bpmb.z", &Lrb_Raster_bpmb_z, &b_Lrb_Raster_bpmb_z);
   fChain->SetBranchAddress("Lrb.Raster.rawcur.x", &Lrb_Raster_rawcur_x, &b_Lrb_Raster_rawcur_x);
   fChain->SetBranchAddress("Lrb.Raster.rawcur.y", &Lrb_Raster_rawcur_y, &b_Lrb_Raster_rawcur_y);
   fChain->SetBranchAddress("Lrb.Raster.rawslope.x", &Lrb_Raster_rawslope_x, &b_Lrb_Raster_rawslope_x);
   fChain->SetBranchAddress("Lrb.Raster.rawslope.y", &Lrb_Raster_rawslope_y, &b_Lrb_Raster_rawslope_y);
   fChain->SetBranchAddress("Lrb.Raster.target.dir.x", &Lrb_Raster_target_dir_x, &b_Lrb_Raster_target_dir_x);
   fChain->SetBranchAddress("Lrb.Raster.target.dir.y", &Lrb_Raster_target_dir_y, &b_Lrb_Raster_target_dir_y);
   fChain->SetBranchAddress("Lrb.Raster.target.dir.z", &Lrb_Raster_target_dir_z, &b_Lrb_Raster_target_dir_z);
   fChain->SetBranchAddress("Lrb.Raster.target.x", &Lrb_Raster_target_x, &b_Lrb_Raster_target_x);
   fChain->SetBranchAddress("Lrb.Raster.target.y", &Lrb_Raster_target_y, &b_Lrb_Raster_target_y);
   fChain->SetBranchAddress("Lrb.Raster.target.z", &Lrb_Raster_target_z, &b_Lrb_Raster_target_z);
   fChain->SetBranchAddress("Lrb.Raster2.bpma.x", &Lrb_Raster2_bpma_x, &b_Lrb_Raster2_bpma_x);
   fChain->SetBranchAddress("Lrb.Raster2.bpma.y", &Lrb_Raster2_bpma_y, &b_Lrb_Raster2_bpma_y);
   fChain->SetBranchAddress("Lrb.Raster2.bpma.z", &Lrb_Raster2_bpma_z, &b_Lrb_Raster2_bpma_z);
   fChain->SetBranchAddress("Lrb.Raster2.bpmb.x", &Lrb_Raster2_bpmb_x, &b_Lrb_Raster2_bpmb_x);
   fChain->SetBranchAddress("Lrb.Raster2.bpmb.y", &Lrb_Raster2_bpmb_y, &b_Lrb_Raster2_bpmb_y);
   fChain->SetBranchAddress("Lrb.Raster2.bpmb.z", &Lrb_Raster2_bpmb_z, &b_Lrb_Raster2_bpmb_z);
   fChain->SetBranchAddress("Lrb.Raster2.rawcur.x", &Lrb_Raster2_rawcur_x, &b_Lrb_Raster2_rawcur_x);
   fChain->SetBranchAddress("Lrb.Raster2.rawcur.y", &Lrb_Raster2_rawcur_y, &b_Lrb_Raster2_rawcur_y);
   fChain->SetBranchAddress("Lrb.Raster2.rawslope.x", &Lrb_Raster2_rawslope_x, &b_Lrb_Raster2_rawslope_x);
   fChain->SetBranchAddress("Lrb.Raster2.rawslope.y", &Lrb_Raster2_rawslope_y, &b_Lrb_Raster2_rawslope_y);
   fChain->SetBranchAddress("Lrb.Raster2.target.dir.x", &Lrb_Raster2_target_dir_x, &b_Lrb_Raster2_target_dir_x);
   fChain->SetBranchAddress("Lrb.Raster2.target.dir.y", &Lrb_Raster2_target_dir_y, &b_Lrb_Raster2_target_dir_y);
   fChain->SetBranchAddress("Lrb.Raster2.target.dir.z", &Lrb_Raster2_target_dir_z, &b_Lrb_Raster2_target_dir_z);
   fChain->SetBranchAddress("Lrb.Raster2.target.x", &Lrb_Raster2_target_x, &b_Lrb_Raster2_target_x);
   fChain->SetBranchAddress("Lrb.Raster2.target.y", &Lrb_Raster2_target_y, &b_Lrb_Raster2_target_y);
   fChain->SetBranchAddress("Lrb.Raster2.target.z", &Lrb_Raster2_target_z, &b_Lrb_Raster2_target_z);
   fChain->SetBranchAddress("SBSrb.BPMA.rawcur.1", &SBSrb_BPMA_rawcur_1, &b_SBSrb_BPMA_rawcur_1);
   fChain->SetBranchAddress("SBSrb.BPMA.rawcur.2", &SBSrb_BPMA_rawcur_2, &b_SBSrb_BPMA_rawcur_2);
   fChain->SetBranchAddress("SBSrb.BPMA.rawcur.3", &SBSrb_BPMA_rawcur_3, &b_SBSrb_BPMA_rawcur_3);
   fChain->SetBranchAddress("SBSrb.BPMA.rawcur.4", &SBSrb_BPMA_rawcur_4, &b_SBSrb_BPMA_rawcur_4);
   fChain->SetBranchAddress("SBSrb.BPMA.rotpos1", &SBSrb_BPMA_rotpos1, &b_SBSrb_BPMA_rotpos1);
   fChain->SetBranchAddress("SBSrb.BPMA.rotpos2", &SBSrb_BPMA_rotpos2, &b_SBSrb_BPMA_rotpos2);
   fChain->SetBranchAddress("SBSrb.BPMA.x", &SBSrb_BPMA_x, &b_SBSrb_BPMA_x);
   fChain->SetBranchAddress("SBSrb.BPMA.y", &SBSrb_BPMA_y, &b_SBSrb_BPMA_y);
   fChain->SetBranchAddress("SBSrb.BPMA.z", &SBSrb_BPMA_z, &b_SBSrb_BPMA_z);
   fChain->SetBranchAddress("SBSrb.BPMB.rawcur.1", &SBSrb_BPMB_rawcur_1, &b_SBSrb_BPMB_rawcur_1);
   fChain->SetBranchAddress("SBSrb.BPMB.rawcur.2", &SBSrb_BPMB_rawcur_2, &b_SBSrb_BPMB_rawcur_2);
   fChain->SetBranchAddress("SBSrb.BPMB.rawcur.3", &SBSrb_BPMB_rawcur_3, &b_SBSrb_BPMB_rawcur_3);
   fChain->SetBranchAddress("SBSrb.BPMB.rawcur.4", &SBSrb_BPMB_rawcur_4, &b_SBSrb_BPMB_rawcur_4);
   fChain->SetBranchAddress("SBSrb.BPMB.rotpos1", &SBSrb_BPMB_rotpos1, &b_SBSrb_BPMB_rotpos1);
   fChain->SetBranchAddress("SBSrb.BPMB.rotpos2", &SBSrb_BPMB_rotpos2, &b_SBSrb_BPMB_rotpos2);
   fChain->SetBranchAddress("SBSrb.BPMB.x", &SBSrb_BPMB_x, &b_SBSrb_BPMB_x);
   fChain->SetBranchAddress("SBSrb.BPMB.y", &SBSrb_BPMB_y, &b_SBSrb_BPMB_y);
   fChain->SetBranchAddress("SBSrb.BPMB.z", &SBSrb_BPMB_z, &b_SBSrb_BPMB_z);
   fChain->SetBranchAddress("SBSrb.Raster.bpma.x", &SBSrb_Raster_bpma_x, &b_SBSrb_Raster_bpma_x);
   fChain->SetBranchAddress("SBSrb.Raster.bpma.y", &SBSrb_Raster_bpma_y, &b_SBSrb_Raster_bpma_y);
   fChain->SetBranchAddress("SBSrb.Raster.bpma.z", &SBSrb_Raster_bpma_z, &b_SBSrb_Raster_bpma_z);
   fChain->SetBranchAddress("SBSrb.Raster.bpmb.x", &SBSrb_Raster_bpmb_x, &b_SBSrb_Raster_bpmb_x);
   fChain->SetBranchAddress("SBSrb.Raster.bpmb.y", &SBSrb_Raster_bpmb_y, &b_SBSrb_Raster_bpmb_y);
   fChain->SetBranchAddress("SBSrb.Raster.bpmb.z", &SBSrb_Raster_bpmb_z, &b_SBSrb_Raster_bpmb_z);
   fChain->SetBranchAddress("SBSrb.Raster.rawcur.x", &SBSrb_Raster_rawcur_x, &b_SBSrb_Raster_rawcur_x);
   fChain->SetBranchAddress("SBSrb.Raster.rawcur.y", &SBSrb_Raster_rawcur_y, &b_SBSrb_Raster_rawcur_y);
   fChain->SetBranchAddress("SBSrb.Raster.rawslope.x", &SBSrb_Raster_rawslope_x, &b_SBSrb_Raster_rawslope_x);
   fChain->SetBranchAddress("SBSrb.Raster.rawslope.y", &SBSrb_Raster_rawslope_y, &b_SBSrb_Raster_rawslope_y);
   fChain->SetBranchAddress("SBSrb.Raster.target.dir.x", &SBSrb_Raster_target_dir_x, &b_SBSrb_Raster_target_dir_x);
   fChain->SetBranchAddress("SBSrb.Raster.target.dir.y", &SBSrb_Raster_target_dir_y, &b_SBSrb_Raster_target_dir_y);
   fChain->SetBranchAddress("SBSrb.Raster.target.dir.z", &SBSrb_Raster_target_dir_z, &b_SBSrb_Raster_target_dir_z);
   fChain->SetBranchAddress("SBSrb.Raster.target.x", &SBSrb_Raster_target_x, &b_SBSrb_Raster_target_x);
   fChain->SetBranchAddress("SBSrb.Raster.target.y", &SBSrb_Raster_target_y, &b_SBSrb_Raster_target_y);
   fChain->SetBranchAddress("SBSrb.Raster.target.z", &SBSrb_Raster_target_z, &b_SBSrb_Raster_target_z);
   fChain->SetBranchAddress("SBSrb.Raster2.bpma.x", &SBSrb_Raster2_bpma_x, &b_SBSrb_Raster2_bpma_x);
   fChain->SetBranchAddress("SBSrb.Raster2.bpma.y", &SBSrb_Raster2_bpma_y, &b_SBSrb_Raster2_bpma_y);
   fChain->SetBranchAddress("SBSrb.Raster2.bpma.z", &SBSrb_Raster2_bpma_z, &b_SBSrb_Raster2_bpma_z);
   fChain->SetBranchAddress("SBSrb.Raster2.bpmb.x", &SBSrb_Raster2_bpmb_x, &b_SBSrb_Raster2_bpmb_x);
   fChain->SetBranchAddress("SBSrb.Raster2.bpmb.y", &SBSrb_Raster2_bpmb_y, &b_SBSrb_Raster2_bpmb_y);
   fChain->SetBranchAddress("SBSrb.Raster2.bpmb.z", &SBSrb_Raster2_bpmb_z, &b_SBSrb_Raster2_bpmb_z);
   fChain->SetBranchAddress("SBSrb.Raster2.rawcur.x", &SBSrb_Raster2_rawcur_x, &b_SBSrb_Raster2_rawcur_x);
   fChain->SetBranchAddress("SBSrb.Raster2.rawcur.y", &SBSrb_Raster2_rawcur_y, &b_SBSrb_Raster2_rawcur_y);
   fChain->SetBranchAddress("SBSrb.Raster2.rawslope.x", &SBSrb_Raster2_rawslope_x, &b_SBSrb_Raster2_rawslope_x);
   fChain->SetBranchAddress("SBSrb.Raster2.rawslope.y", &SBSrb_Raster2_rawslope_y, &b_SBSrb_Raster2_rawslope_y);
   fChain->SetBranchAddress("SBSrb.Raster2.target.dir.x", &SBSrb_Raster2_target_dir_x, &b_SBSrb_Raster2_target_dir_x);
   fChain->SetBranchAddress("SBSrb.Raster2.target.dir.y", &SBSrb_Raster2_target_dir_y, &b_SBSrb_Raster2_target_dir_y);
   fChain->SetBranchAddress("SBSrb.Raster2.target.dir.z", &SBSrb_Raster2_target_dir_z, &b_SBSrb_Raster2_target_dir_z);
   fChain->SetBranchAddress("SBSrb.Raster2.target.x", &SBSrb_Raster2_target_x, &b_SBSrb_Raster2_target_x);
   fChain->SetBranchAddress("SBSrb.Raster2.target.y", &SBSrb_Raster2_target_y, &b_SBSrb_Raster2_target_y);
   fChain->SetBranchAddress("SBSrb.Raster2.target.z", &SBSrb_Raster2_target_z, &b_SBSrb_Raster2_target_z);
   fChain->SetBranchAddress("bb.gem.hit.ngoodhits", &bb_gem_hit_ngoodhits, &b_bb_gem_hit_ngoodhits);
   fChain->SetBranchAddress("bb.gem.m0.clust.nclustu", &bb_gem_m0_clust_nclustu, &b_bb_gem_m0_clust_nclustu);
   fChain->SetBranchAddress("bb.gem.m0.clust.nclustu_tot", &bb_gem_m0_clust_nclustu_tot, &b_bb_gem_m0_clust_nclustu_tot);
   fChain->SetBranchAddress("bb.gem.m0.clust.nclustv", &bb_gem_m0_clust_nclustv, &b_bb_gem_m0_clust_nclustv);
   fChain->SetBranchAddress("bb.gem.m0.clust.nclustv_tot", &bb_gem_m0_clust_nclustv_tot, &b_bb_gem_m0_clust_nclustv_tot);
   fChain->SetBranchAddress("bb.gem.m0.strip.nstrips_keep", &bb_gem_m0_strip_nstrips_keep, &b_bb_gem_m0_strip_nstrips_keep);
   fChain->SetBranchAddress("bb.gem.m0.strip.nstrips_keepU", &bb_gem_m0_strip_nstrips_keepU, &b_bb_gem_m0_strip_nstrips_keepU);
   fChain->SetBranchAddress("bb.gem.m0.strip.nstrips_keepV", &bb_gem_m0_strip_nstrips_keepV, &b_bb_gem_m0_strip_nstrips_keepV);
   fChain->SetBranchAddress("bb.gem.m0.strip.nstrips_keep_lmax", &bb_gem_m0_strip_nstrips_keep_lmax, &b_bb_gem_m0_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("bb.gem.m0.strip.nstrips_keep_lmaxU", &bb_gem_m0_strip_nstrips_keep_lmaxU, &b_bb_gem_m0_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("bb.gem.m0.strip.nstrips_keep_lmaxV", &bb_gem_m0_strip_nstrips_keep_lmaxV, &b_bb_gem_m0_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("bb.gem.m0.strip.nstripsfired", &bb_gem_m0_strip_nstripsfired, &b_bb_gem_m0_strip_nstripsfired);
   fChain->SetBranchAddress("bb.gem.m1.clust.nclustu", &bb_gem_m1_clust_nclustu, &b_bb_gem_m1_clust_nclustu);
   fChain->SetBranchAddress("bb.gem.m1.clust.nclustu_tot", &bb_gem_m1_clust_nclustu_tot, &b_bb_gem_m1_clust_nclustu_tot);
   fChain->SetBranchAddress("bb.gem.m1.clust.nclustv", &bb_gem_m1_clust_nclustv, &b_bb_gem_m1_clust_nclustv);
   fChain->SetBranchAddress("bb.gem.m1.clust.nclustv_tot", &bb_gem_m1_clust_nclustv_tot, &b_bb_gem_m1_clust_nclustv_tot);
   fChain->SetBranchAddress("bb.gem.m1.strip.nstrips_keep", &bb_gem_m1_strip_nstrips_keep, &b_bb_gem_m1_strip_nstrips_keep);
   fChain->SetBranchAddress("bb.gem.m1.strip.nstrips_keepU", &bb_gem_m1_strip_nstrips_keepU, &b_bb_gem_m1_strip_nstrips_keepU);
   fChain->SetBranchAddress("bb.gem.m1.strip.nstrips_keepV", &bb_gem_m1_strip_nstrips_keepV, &b_bb_gem_m1_strip_nstrips_keepV);
   fChain->SetBranchAddress("bb.gem.m1.strip.nstrips_keep_lmax", &bb_gem_m1_strip_nstrips_keep_lmax, &b_bb_gem_m1_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("bb.gem.m1.strip.nstrips_keep_lmaxU", &bb_gem_m1_strip_nstrips_keep_lmaxU, &b_bb_gem_m1_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("bb.gem.m1.strip.nstrips_keep_lmaxV", &bb_gem_m1_strip_nstrips_keep_lmaxV, &b_bb_gem_m1_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("bb.gem.m1.strip.nstripsfired", &bb_gem_m1_strip_nstripsfired, &b_bb_gem_m1_strip_nstripsfired);
   fChain->SetBranchAddress("bb.gem.m2.clust.nclustu", &bb_gem_m2_clust_nclustu, &b_bb_gem_m2_clust_nclustu);
   fChain->SetBranchAddress("bb.gem.m2.clust.nclustu_tot", &bb_gem_m2_clust_nclustu_tot, &b_bb_gem_m2_clust_nclustu_tot);
   fChain->SetBranchAddress("bb.gem.m2.clust.nclustv", &bb_gem_m2_clust_nclustv, &b_bb_gem_m2_clust_nclustv);
   fChain->SetBranchAddress("bb.gem.m2.clust.nclustv_tot", &bb_gem_m2_clust_nclustv_tot, &b_bb_gem_m2_clust_nclustv_tot);
   fChain->SetBranchAddress("bb.gem.m2.strip.nstrips_keep", &bb_gem_m2_strip_nstrips_keep, &b_bb_gem_m2_strip_nstrips_keep);
   fChain->SetBranchAddress("bb.gem.m2.strip.nstrips_keepU", &bb_gem_m2_strip_nstrips_keepU, &b_bb_gem_m2_strip_nstrips_keepU);
   fChain->SetBranchAddress("bb.gem.m2.strip.nstrips_keepV", &bb_gem_m2_strip_nstrips_keepV, &b_bb_gem_m2_strip_nstrips_keepV);
   fChain->SetBranchAddress("bb.gem.m2.strip.nstrips_keep_lmax", &bb_gem_m2_strip_nstrips_keep_lmax, &b_bb_gem_m2_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("bb.gem.m2.strip.nstrips_keep_lmaxU", &bb_gem_m2_strip_nstrips_keep_lmaxU, &b_bb_gem_m2_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("bb.gem.m2.strip.nstrips_keep_lmaxV", &bb_gem_m2_strip_nstrips_keep_lmaxV, &b_bb_gem_m2_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("bb.gem.m2.strip.nstripsfired", &bb_gem_m2_strip_nstripsfired, &b_bb_gem_m2_strip_nstripsfired);
   fChain->SetBranchAddress("bb.gem.m3.clust.nclustu", &bb_gem_m3_clust_nclustu, &b_bb_gem_m3_clust_nclustu);
   fChain->SetBranchAddress("bb.gem.m3.clust.nclustu_tot", &bb_gem_m3_clust_nclustu_tot, &b_bb_gem_m3_clust_nclustu_tot);
   fChain->SetBranchAddress("bb.gem.m3.clust.nclustv", &bb_gem_m3_clust_nclustv, &b_bb_gem_m3_clust_nclustv);
   fChain->SetBranchAddress("bb.gem.m3.clust.nclustv_tot", &bb_gem_m3_clust_nclustv_tot, &b_bb_gem_m3_clust_nclustv_tot);
   fChain->SetBranchAddress("bb.gem.m3.strip.nstrips_keep", &bb_gem_m3_strip_nstrips_keep, &b_bb_gem_m3_strip_nstrips_keep);
   fChain->SetBranchAddress("bb.gem.m3.strip.nstrips_keepU", &bb_gem_m3_strip_nstrips_keepU, &b_bb_gem_m3_strip_nstrips_keepU);
   fChain->SetBranchAddress("bb.gem.m3.strip.nstrips_keepV", &bb_gem_m3_strip_nstrips_keepV, &b_bb_gem_m3_strip_nstrips_keepV);
   fChain->SetBranchAddress("bb.gem.m3.strip.nstrips_keep_lmax", &bb_gem_m3_strip_nstrips_keep_lmax, &b_bb_gem_m3_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("bb.gem.m3.strip.nstrips_keep_lmaxU", &bb_gem_m3_strip_nstrips_keep_lmaxU, &b_bb_gem_m3_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("bb.gem.m3.strip.nstrips_keep_lmaxV", &bb_gem_m3_strip_nstrips_keep_lmaxV, &b_bb_gem_m3_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("bb.gem.m3.strip.nstripsfired", &bb_gem_m3_strip_nstripsfired, &b_bb_gem_m3_strip_nstripsfired);
   fChain->SetBranchAddress("bb.gem.m4.clust.nclustu", &bb_gem_m4_clust_nclustu, &b_bb_gem_m4_clust_nclustu);
   fChain->SetBranchAddress("bb.gem.m4.clust.nclustu_tot", &bb_gem_m4_clust_nclustu_tot, &b_bb_gem_m4_clust_nclustu_tot);
   fChain->SetBranchAddress("bb.gem.m4.clust.nclustv", &bb_gem_m4_clust_nclustv, &b_bb_gem_m4_clust_nclustv);
   fChain->SetBranchAddress("bb.gem.m4.clust.nclustv_tot", &bb_gem_m4_clust_nclustv_tot, &b_bb_gem_m4_clust_nclustv_tot);
   fChain->SetBranchAddress("bb.gem.m4.strip.nstrips_keep", &bb_gem_m4_strip_nstrips_keep, &b_bb_gem_m4_strip_nstrips_keep);
   fChain->SetBranchAddress("bb.gem.m4.strip.nstrips_keepU", &bb_gem_m4_strip_nstrips_keepU, &b_bb_gem_m4_strip_nstrips_keepU);
   fChain->SetBranchAddress("bb.gem.m4.strip.nstrips_keepV", &bb_gem_m4_strip_nstrips_keepV, &b_bb_gem_m4_strip_nstrips_keepV);
   fChain->SetBranchAddress("bb.gem.m4.strip.nstrips_keep_lmax", &bb_gem_m4_strip_nstrips_keep_lmax, &b_bb_gem_m4_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("bb.gem.m4.strip.nstrips_keep_lmaxU", &bb_gem_m4_strip_nstrips_keep_lmaxU, &b_bb_gem_m4_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("bb.gem.m4.strip.nstrips_keep_lmaxV", &bb_gem_m4_strip_nstrips_keep_lmaxV, &b_bb_gem_m4_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("bb.gem.m4.strip.nstripsfired", &bb_gem_m4_strip_nstripsfired, &b_bb_gem_m4_strip_nstripsfired);
   fChain->SetBranchAddress("bb.gem.m5.clust.nclustu", &bb_gem_m5_clust_nclustu, &b_bb_gem_m5_clust_nclustu);
   fChain->SetBranchAddress("bb.gem.m5.clust.nclustu_tot", &bb_gem_m5_clust_nclustu_tot, &b_bb_gem_m5_clust_nclustu_tot);
   fChain->SetBranchAddress("bb.gem.m5.clust.nclustv", &bb_gem_m5_clust_nclustv, &b_bb_gem_m5_clust_nclustv);
   fChain->SetBranchAddress("bb.gem.m5.clust.nclustv_tot", &bb_gem_m5_clust_nclustv_tot, &b_bb_gem_m5_clust_nclustv_tot);
   fChain->SetBranchAddress("bb.gem.m5.strip.nstrips_keep", &bb_gem_m5_strip_nstrips_keep, &b_bb_gem_m5_strip_nstrips_keep);
   fChain->SetBranchAddress("bb.gem.m5.strip.nstrips_keepU", &bb_gem_m5_strip_nstrips_keepU, &b_bb_gem_m5_strip_nstrips_keepU);
   fChain->SetBranchAddress("bb.gem.m5.strip.nstrips_keepV", &bb_gem_m5_strip_nstrips_keepV, &b_bb_gem_m5_strip_nstrips_keepV);
   fChain->SetBranchAddress("bb.gem.m5.strip.nstrips_keep_lmax", &bb_gem_m5_strip_nstrips_keep_lmax, &b_bb_gem_m5_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("bb.gem.m5.strip.nstrips_keep_lmaxU", &bb_gem_m5_strip_nstrips_keep_lmaxU, &b_bb_gem_m5_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("bb.gem.m5.strip.nstrips_keep_lmaxV", &bb_gem_m5_strip_nstrips_keep_lmaxV, &b_bb_gem_m5_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("bb.gem.m5.strip.nstripsfired", &bb_gem_m5_strip_nstripsfired, &b_bb_gem_m5_strip_nstripsfired);
   fChain->SetBranchAddress("bb.gem.m6.clust.nclustu", &bb_gem_m6_clust_nclustu, &b_bb_gem_m6_clust_nclustu);
   fChain->SetBranchAddress("bb.gem.m6.clust.nclustu_tot", &bb_gem_m6_clust_nclustu_tot, &b_bb_gem_m6_clust_nclustu_tot);
   fChain->SetBranchAddress("bb.gem.m6.clust.nclustv", &bb_gem_m6_clust_nclustv, &b_bb_gem_m6_clust_nclustv);
   fChain->SetBranchAddress("bb.gem.m6.clust.nclustv_tot", &bb_gem_m6_clust_nclustv_tot, &b_bb_gem_m6_clust_nclustv_tot);
   fChain->SetBranchAddress("bb.gem.m6.strip.nstrips_keep", &bb_gem_m6_strip_nstrips_keep, &b_bb_gem_m6_strip_nstrips_keep);
   fChain->SetBranchAddress("bb.gem.m6.strip.nstrips_keepU", &bb_gem_m6_strip_nstrips_keepU, &b_bb_gem_m6_strip_nstrips_keepU);
   fChain->SetBranchAddress("bb.gem.m6.strip.nstrips_keepV", &bb_gem_m6_strip_nstrips_keepV, &b_bb_gem_m6_strip_nstrips_keepV);
   fChain->SetBranchAddress("bb.gem.m6.strip.nstrips_keep_lmax", &bb_gem_m6_strip_nstrips_keep_lmax, &b_bb_gem_m6_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("bb.gem.m6.strip.nstrips_keep_lmaxU", &bb_gem_m6_strip_nstrips_keep_lmaxU, &b_bb_gem_m6_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("bb.gem.m6.strip.nstrips_keep_lmaxV", &bb_gem_m6_strip_nstrips_keep_lmaxV, &b_bb_gem_m6_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("bb.gem.m6.strip.nstripsfired", &bb_gem_m6_strip_nstripsfired, &b_bb_gem_m6_strip_nstripsfired);
   fChain->SetBranchAddress("bb.gem.m7.clust.nclustu", &bb_gem_m7_clust_nclustu, &b_bb_gem_m7_clust_nclustu);
   fChain->SetBranchAddress("bb.gem.m7.clust.nclustu_tot", &bb_gem_m7_clust_nclustu_tot, &b_bb_gem_m7_clust_nclustu_tot);
   fChain->SetBranchAddress("bb.gem.m7.clust.nclustv", &bb_gem_m7_clust_nclustv, &b_bb_gem_m7_clust_nclustv);
   fChain->SetBranchAddress("bb.gem.m7.clust.nclustv_tot", &bb_gem_m7_clust_nclustv_tot, &b_bb_gem_m7_clust_nclustv_tot);
   fChain->SetBranchAddress("bb.gem.m7.strip.nstrips_keep", &bb_gem_m7_strip_nstrips_keep, &b_bb_gem_m7_strip_nstrips_keep);
   fChain->SetBranchAddress("bb.gem.m7.strip.nstrips_keepU", &bb_gem_m7_strip_nstrips_keepU, &b_bb_gem_m7_strip_nstrips_keepU);
   fChain->SetBranchAddress("bb.gem.m7.strip.nstrips_keepV", &bb_gem_m7_strip_nstrips_keepV, &b_bb_gem_m7_strip_nstrips_keepV);
   fChain->SetBranchAddress("bb.gem.m7.strip.nstrips_keep_lmax", &bb_gem_m7_strip_nstrips_keep_lmax, &b_bb_gem_m7_strip_nstrips_keep_lmax);
   fChain->SetBranchAddress("bb.gem.m7.strip.nstrips_keep_lmaxU", &bb_gem_m7_strip_nstrips_keep_lmaxU, &b_bb_gem_m7_strip_nstrips_keep_lmaxU);
   fChain->SetBranchAddress("bb.gem.m7.strip.nstrips_keep_lmaxV", &bb_gem_m7_strip_nstrips_keep_lmaxV, &b_bb_gem_m7_strip_nstrips_keep_lmaxV);
   fChain->SetBranchAddress("bb.gem.m7.strip.nstripsfired", &bb_gem_m7_strip_nstripsfired, &b_bb_gem_m7_strip_nstripsfired);
   fChain->SetBranchAddress("bb.gem.nlayershit", &bb_gem_nlayershit, &b_bb_gem_nlayershit);
   fChain->SetBranchAddress("bb.gem.nlayershitu", &bb_gem_nlayershitu, &b_bb_gem_nlayershitu);
   fChain->SetBranchAddress("bb.gem.nlayershituv", &bb_gem_nlayershituv, &b_bb_gem_nlayershituv);
   fChain->SetBranchAddress("bb.gem.nlayershitv", &bb_gem_nlayershitv, &b_bb_gem_nlayershitv);
   fChain->SetBranchAddress("bb.gem.track.besttrack", &bb_gem_track_besttrack, &b_bb_gem_track_besttrack);
   fChain->SetBranchAddress("bb.gem.track.ntrack", &bb_gem_track_ntrack, &b_bb_gem_track_ntrack);
   fChain->SetBranchAddress("bb.gem.trigtime", &bb_gem_trigtime, &b_bb_gem_trigtime);
   fChain->SetBranchAddress("bb.grinch_tdc.bestcluster", &bb_grinch_tdc_bestcluster, &b_bb_grinch_tdc_bestcluster);
   fChain->SetBranchAddress("bb.grinch_tdc.clus.adc", &bb_grinch_tdc_clus_adc, &b_bb_grinch_tdc_clus_adc);
   fChain->SetBranchAddress("bb.grinch_tdc.clus.dx", &bb_grinch_tdc_clus_dx, &b_bb_grinch_tdc_clus_dx);
   fChain->SetBranchAddress("bb.grinch_tdc.clus.dy", &bb_grinch_tdc_clus_dy, &b_bb_grinch_tdc_clus_dy);
   fChain->SetBranchAddress("bb.grinch_tdc.clus.mirrorindex", &bb_grinch_tdc_clus_mirrorindex, &b_bb_grinch_tdc_clus_mirrorindex);
   fChain->SetBranchAddress("bb.grinch_tdc.clus.size", &bb_grinch_tdc_clus_size, &b_bb_grinch_tdc_clus_size);
   fChain->SetBranchAddress("bb.grinch_tdc.clus.t_mean", &bb_grinch_tdc_clus_t_mean, &b_bb_grinch_tdc_clus_t_mean);
   fChain->SetBranchAddress("bb.grinch_tdc.clus.t_rms", &bb_grinch_tdc_clus_t_rms, &b_bb_grinch_tdc_clus_t_rms);
   fChain->SetBranchAddress("bb.grinch_tdc.clus.tot_mean", &bb_grinch_tdc_clus_tot_mean, &b_bb_grinch_tdc_clus_tot_mean);
   fChain->SetBranchAddress("bb.grinch_tdc.clus.trackindex", &bb_grinch_tdc_clus_trackindex, &b_bb_grinch_tdc_clus_trackindex);
   fChain->SetBranchAddress("bb.grinch_tdc.clus.x_mean", &bb_grinch_tdc_clus_x_mean, &b_bb_grinch_tdc_clus_x_mean);
   fChain->SetBranchAddress("bb.grinch_tdc.clus.y_mean", &bb_grinch_tdc_clus_y_mean, &b_bb_grinch_tdc_clus_y_mean);
   fChain->SetBranchAddress("bb.grinch_tdc.nclus", &bb_grinch_tdc_nclus, &b_bb_grinch_tdc_nclus);
   fChain->SetBranchAddress("bb.grinch_tdc.ngoodhits", &bb_grinch_tdc_ngoodhits, &b_bb_grinch_tdc_ngoodhits);
   fChain->SetBranchAddress("bb.grinch_tdc.ntrackmatch", &bb_grinch_tdc_ntrackmatch, &b_bb_grinch_tdc_ntrackmatch);
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
   fChain->SetBranchAddress("bb.ps.againblk", &bb_ps_againblk, &b_bb_ps_againblk);
   fChain->SetBranchAddress("bb.ps.atimeblk", &bb_ps_atimeblk, &b_bb_ps_atimeblk);
   fChain->SetBranchAddress("bb.ps.colblk", &bb_ps_colblk, &b_bb_ps_colblk);
   fChain->SetBranchAddress("bb.ps.e", &bb_ps_e, &b_bb_ps_e);
   fChain->SetBranchAddress("bb.ps.eblk", &bb_ps_eblk, &b_bb_ps_eblk);
   fChain->SetBranchAddress("bb.ps.idblk", &bb_ps_idblk, &b_bb_ps_idblk);
   fChain->SetBranchAddress("bb.ps.index", &bb_ps_index, &b_bb_ps_index);
   fChain->SetBranchAddress("bb.ps.nblk", &bb_ps_nblk, &b_bb_ps_nblk);
   fChain->SetBranchAddress("bb.ps.nclus", &bb_ps_nclus, &b_bb_ps_nclus);
   fChain->SetBranchAddress("bb.ps.ngoodADChits", &bb_ps_ngoodADChits, &b_bb_ps_ngoodADChits);
   fChain->SetBranchAddress("bb.ps.rowblk", &bb_ps_rowblk, &b_bb_ps_rowblk);
   fChain->SetBranchAddress("bb.ps.x", &bb_ps_x, &b_bb_ps_x);
   fChain->SetBranchAddress("bb.ps.y", &bb_ps_y, &b_bb_ps_y);
   fChain->SetBranchAddress("bb.sh.againblk", &bb_sh_againblk, &b_bb_sh_againblk);
   fChain->SetBranchAddress("bb.sh.atimeblk", &bb_sh_atimeblk, &b_bb_sh_atimeblk);
   fChain->SetBranchAddress("bb.sh.colblk", &bb_sh_colblk, &b_bb_sh_colblk);
   fChain->SetBranchAddress("bb.sh.e", &bb_sh_e, &b_bb_sh_e);
   fChain->SetBranchAddress("bb.sh.eblk", &bb_sh_eblk, &b_bb_sh_eblk);
   fChain->SetBranchAddress("bb.sh.idblk", &bb_sh_idblk, &b_bb_sh_idblk);
   fChain->SetBranchAddress("bb.sh.index", &bb_sh_index, &b_bb_sh_index);
   fChain->SetBranchAddress("bb.sh.nblk", &bb_sh_nblk, &b_bb_sh_nblk);
   fChain->SetBranchAddress("bb.sh.nclus", &bb_sh_nclus, &b_bb_sh_nclus);
   fChain->SetBranchAddress("bb.sh.ngoodADChits", &bb_sh_ngoodADChits, &b_bb_sh_ngoodADChits);
   fChain->SetBranchAddress("bb.sh.rowblk", &bb_sh_rowblk, &b_bb_sh_rowblk);
   fChain->SetBranchAddress("bb.sh.x", &bb_sh_x, &b_bb_sh_x);
   fChain->SetBranchAddress("bb.sh.y", &bb_sh_y, &b_bb_sh_y);
   fChain->SetBranchAddress("bb.tr.n", &bb_tr_n, &b_bb_tr_n);
   fChain->SetBranchAddress("bb.ts.over_threshold", &bb_ts_over_threshold, &b_bb_ts_over_threshold);
   fChain->SetBranchAddress("e.kine.Q2", &e_kine_Q2, &b_e_kine_Q2);
   fChain->SetBranchAddress("e.kine.W2", &e_kine_W2, &b_e_kine_W2);
   fChain->SetBranchAddress("e.kine.angle", &e_kine_angle, &b_e_kine_angle);
   fChain->SetBranchAddress("e.kine.epsilon", &e_kine_epsilon, &b_e_kine_epsilon);
   fChain->SetBranchAddress("e.kine.nu", &e_kine_nu, &b_e_kine_nu);
   fChain->SetBranchAddress("e.kine.omega", &e_kine_omega, &b_e_kine_omega);
   fChain->SetBranchAddress("e.kine.ph_q", &e_kine_ph_q, &b_e_kine_ph_q);
   fChain->SetBranchAddress("e.kine.q3m", &e_kine_q3m, &b_e_kine_q3m);
   fChain->SetBranchAddress("e.kine.q_x", &e_kine_q_x, &b_e_kine_q_x);
   fChain->SetBranchAddress("e.kine.q_y", &e_kine_q_y, &b_e_kine_q_y);
   fChain->SetBranchAddress("e.kine.q_z", &e_kine_q_z, &b_e_kine_q_z);
   fChain->SetBranchAddress("e.kine.th_q", &e_kine_th_q, &b_e_kine_th_q);
   fChain->SetBranchAddress("e.kine.x_bj", &e_kine_x_bj, &b_e_kine_x_bj);
   fChain->SetBranchAddress("g.datatype", &g_datatype, &b_g_datatype);
   fChain->SetBranchAddress("g.evlen", &g_evlen, &b_g_evlen);
   fChain->SetBranchAddress("g.evnum", &g_evnum, &b_g_evnum);
   fChain->SetBranchAddress("g.evtime", &g_evtime, &b_g_evtime);
   fChain->SetBranchAddress("g.evtyp", &g_evtyp, &b_g_evtyp);
   fChain->SetBranchAddress("g.runnum", &g_runnum, &b_g_runnum);
   fChain->SetBranchAddress("g.runtime", &g_runtime, &b_g_runtime);
   fChain->SetBranchAddress("g.runtype", &g_runtype, &b_g_runtype);
   fChain->SetBranchAddress("g.trigbits", &g_trigbits, &b_g_trigbits);
   fChain->SetBranchAddress("sbs.hcal.againblk", &sbs_hcal_againblk, &b_sbs_hcal_againblk);
   fChain->SetBranchAddress("sbs.hcal.atimeblk", &sbs_hcal_atimeblk, &b_sbs_hcal_atimeblk);
   fChain->SetBranchAddress("sbs.hcal.colblk", &sbs_hcal_colblk, &b_sbs_hcal_colblk);
   fChain->SetBranchAddress("sbs.hcal.e", &sbs_hcal_e, &b_sbs_hcal_e);
   fChain->SetBranchAddress("sbs.hcal.eblk", &sbs_hcal_eblk, &b_sbs_hcal_eblk);
   fChain->SetBranchAddress("sbs.hcal.idblk", &sbs_hcal_idblk, &b_sbs_hcal_idblk);
   fChain->SetBranchAddress("sbs.hcal.index", &sbs_hcal_index, &b_sbs_hcal_index);
   fChain->SetBranchAddress("sbs.hcal.nblk", &sbs_hcal_nblk, &b_sbs_hcal_nblk);
   fChain->SetBranchAddress("sbs.hcal.nclus", &sbs_hcal_nclus, &b_sbs_hcal_nclus);
   fChain->SetBranchAddress("sbs.hcal.ngoodADChits", &sbs_hcal_ngoodADChits, &b_sbs_hcal_ngoodADChits);
   fChain->SetBranchAddress("sbs.hcal.rowblk", &sbs_hcal_rowblk, &b_sbs_hcal_rowblk);
   fChain->SetBranchAddress("sbs.hcal.tdctimeblk", &sbs_hcal_tdctimeblk, &b_sbs_hcal_tdctimeblk);
   fChain->SetBranchAddress("sbs.hcal.x", &sbs_hcal_x, &b_sbs_hcal_x);
   fChain->SetBranchAddress("sbs.hcal.y", &sbs_hcal_y, &b_sbs_hcal_y);
   fChain->SetBranchAddress("scalhel.errcode", &scalhel_errcode, &b_scalhel_errcode);
   fChain->SetBranchAddress("scalhel.evtcount", &scalhel_evtcount, &b_scalhel_evtcount);
   fChain->SetBranchAddress("scalhel.hel", &scalhel_hel, &b_scalhel_hel);
   fChain->SetBranchAddress("scalhel.lhrs.fadc.hel", &scalhel_lhrs_fadc_hel, &b_scalhel_lhrs_fadc_hel);
   fChain->SetBranchAddress("scalhel.lhrs.fadc.pat", &scalhel_lhrs_fadc_pat, &b_scalhel_lhrs_fadc_pat);
   fChain->SetBranchAddress("scalhel.lhrs.fadc.tsettle", &scalhel_lhrs_fadc_tsettle, &b_scalhel_lhrs_fadc_tsettle);
   fChain->SetBranchAddress("scalhel.patcount", &scalhel_patcount, &b_scalhel_patcount);
   fChain->SetBranchAddress("scalhel.patphase", &scalhel_patphase, &b_scalhel_patphase);
   fChain->SetBranchAddress("scalhel.seed", &scalhel_seed, &b_scalhel_seed);
   fChain->SetBranchAddress("singletrack_bb", &singletrack_bb, &b_singletrack_bb);
   fChain->SetBranchAddress("anytrack_bb", &anytrack_bb, &b_anytrack_bb);
   fChain->SetBranchAddress("HALLA_p", &HALLA_p, &b_HALLA_p);
   fChain->SetBranchAddress("hac_bcm_average", &hac_bcm_average, &b_hac_bcm_average);
   fChain->SetBranchAddress("IPM1H04A.XPOS", &IPM1H04A_XPOS, &b_IPM1H04A_XPOS);
   fChain->SetBranchAddress("IPM1H04A.YPOS", &IPM1H04A_YPOS, &b_IPM1H04A_YPOS);
   fChain->SetBranchAddress("IPM1H04E.XPOS", &IPM1H04E_XPOS, &b_IPM1H04E_XPOS);
   fChain->SetBranchAddress("IPM1H04E.YPOS", &IPM1H04E_YPOS, &b_IPM1H04E_YPOS);
   fChain->SetBranchAddress("IGL1I00OD16_16", &IGL1I00OD16_16, &b_IGL1I00OD16_16);
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
