#include <TROOT.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <iostream>
#include <fstream>
#include <TMath.h>
#include <TLorentzVector.h>
#include <TH1.h>
#include <TH1D.h>
#include <TH2.h>
#include <TF1.h>
#include <TF2.h>
#include <TFile.h>
#include <TTree.h>
#include <TChain.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TLine.h>
#include <TSystem.h>
#include <TSpectrum.h>
#include <sstream>
#include <TStopwatch.h>

#include "GEnTree.C"

using namespace std;

// options
const Bool_t   ApplyFidu  = true;
const Bool_t   ApplyElas  = true;
const Bool_t   ApplyElec  = true;
const Bool_t   ApplyPion  = false;
const Bool_t   Apply1Bar  = false;

const Bool_t   PlotHodo   = true;
const Bool_t   PlotBBCal  = true;
const Bool_t   PlotHCal   = true;
const Bool_t   PlotKine   = true;
const Bool_t   PlotOptics = true;


void AnalyseHodoGEM(const TString Exp = "GEN", const Int_t kin_no = 2, const TString Target = "H2"){
  // Exp  = GEN or GMN
  //kin_no = 1,2,4,5 for GEN, 4,7,8,9,11,14 for GMN
  //Target = H2 for 10bar H2 reference cell data
  //Target = He3 for 10bar polarised He3 production cell data.
  //Target = LD2 or LH2 for GMN (no hard coded stuff r.e. this yet)
  
  //stopwatch for benchmarking analysis time on large dataset
  TStopwatch t;
  t.Start();
  

  //This just sets paths for different files at jlab. Below there is similar strings which set paths at glasgow. Comment / change as necessary for your file locations.
  TString Base_Dir = "/volatile/halla/sbs/gpenman/Rootfiles/GEn/";
  Base_Dir = "/volatile/halla/sbs/jeffas/GEN_root/Rootfiles/";
  //Base_Dir = "/w/work5/home/garyp/sbs/rootfiles/GEn/";
  TString Pass_Dir = Form("GEN%i/",kin_no);
  TString Rootfile_Dir;
  
  if (Target == "H2"){
    cout << "Target is H2 Reference Cell" << endl;
    Rootfile_Dir = Base_Dir + Pass_Dir + "H2";
  }
  else if (Target == "He3"){
    cout << "Target is He3 Production Cell" << endl;
    Rootfile_Dir = Base_Dir + Pass_Dir + "He3";
  }
  else{
    cout << "Target doesn't make sense. Try harder." << endl;
    exit(1);
  }
   
  gSystem->Setenv("ROOTFILE_DIR",Rootfile_Dir);
  ///////////

  //SET ROOTFILE DIR IF USING AT GLASGOW
  TString work_dir;
  if (Target == "He3")
    work_dir = "/w/work5/home/garyp/sbs/rootfiles/GEn/50K/";
  else if (Target == "H2")
    //work_dir = "/w/work5/home/garyp/sbs/rootfiles/GEn/hodocalib/uncalib";
    //work_dir = "/w/work5/home/garyp/sbs/rootfiles/GEn/hodocalib/TWcalib";
    work_dir = "/w/work5/home/garyp/sbs/rootfiles/GEn/hodocalib/GEMcalib2";
  gSystem->Setenv("ROOTFILE_DIR",work_dir);
  //
  
  TChain* C = new TChain("T");
  
  C->SetBranchStatus("*",0);
  C->SetBranchStatus("bb.tr.*",1);
  C->SetBranchStatus("bb.sh.*",1);
  C->SetBranchStatus("bb.ps.*",1);
  C->SetBranchStatus("bb.hodotdc.clus.*",1);
  
  Int_t run_no = 0;
  Double_t Eb, th_sbs, th_bb, pcent, runtime, avI, pdiff_off;
  Double_t hcal_dist;
  
  //Elastic Cuts Based on Kinematic Setting
  Double_t sh_min, sh_max, sh_e, ps_min, W_min, W_max, W_minc, W_maxc, pdiffcut;
  
  //Nucleon spot cuts - should these change on a pass basis?
  Double_t ymean,ysig,nxmean,nxsig,pxmean,pxsig;
  ymean = 0.0;
  ysig = 0.5;
  nxmean = 0.26;
  nxsig = 0.78;
  pxmean = -2.38;
  pxsig = 0.63;
  //Double_t nxcut = sqrt(pow(ymean/ysig,2) + pow(nxmean/nxsig,2));
  //Double_t pxcut = sqrt(pow(ymean/ysig,2) + pow(pxmean/pxsig,2));
  Double_t nxcut = 1;
  Double_t pxcut = 1;

  W_min   = 0.0; 
  W_max   = 4.0; 
  W_minc = 0.25;
  W_maxc = 1.75;
  
  if (Exp == "GEN"){
    hcal_dist = 17.0;
    runtime = 60;
    avI = 45;
    pdiffcut = 0.2;
    sh_e = 0.75;
    sh_min = 0.65;
    sh_max = 1.0;
    ps_min = 0.1;
    
    if( kin_no == 1) { //GEN-1
      C->Add("$ROOTFILE_DIR/e1209016_fullreplay_*.root");
      Eb = 2.200;
      th_bb = 47.5;
      th_sbs = 34.7;
    }  
    else if( kin_no == 2) { //GEN-2
      C->Add("$ROOTFILE_DIR/e1209016_fullreplay_*.root");
      Eb = 4.288;
      th_bb = 29.5;
      th_sbs = 34.7;

      pxmean = -2.81024;
      pxsig = 0.304931;
    }
    else if( kin_no == 3) { //GEN-3
      C->Add("$ROOTFILE_DIR/e1209016_fullreplay*.root");
      Eb = 6.600;
      th_bb = 35.9;
      th_sbs = 22.1;
    }
    else if( kin_no == 4) { //GEN-4
      C->Add("$ROOTFILE_DIR/e1209016_fullreplay_*.root");
      Eb = 8.800;
      th_bb = 35.0;
      th_sbs = 18.0;
    }
  }else if (Exp == "GMN"){
    if( kin_no == 4) { //SBS-4
      //sbsmag 30%
      //C->Add("$OUT_DIR/LH2/*11499*.root");
      //C->Add("$OUT_DIR/LH2/*11500*.root");
      //C->Add("$OUT_DIR/LH2/*11520*.root");
      //C->Add("$OUT_DIR/LH2/*11547*.root");
      //C->Add("/work/halla/sbs/ralphmm/Rootfiles/e1209019_fullreplay_11547_stream0_seg0_76.root");
      //C->Add("$OUT_DIR/LH2/*11548*.root");
      //sbsmag off
      //C->Add("$OUT_DIR/LH2/*11573*.root");
      //C->Add("$OUT_DIR/LH2/*11587*.root");
      //C->Add("$OUT_DIR/LH2/*11588*.root");
      //sbsmag 50%
      // C->Add("$OUT_DIR/e1209019_fullreplay_11562*.root");
      //C->Add("$OUT_DIR/LH2/e1209019_fullreplay_11590*.root");
      //C->Add("$OUT_DIR/LH2/e1209019_fullreplay_11592*.root");
      //C->Add("$OUT_DIR/LH2/e1209019_fullreplay_11616*.root");
    
      C->Add("$OUT_DIR/../e1209019_fullreplay_11547_stream0_seg0_76*.root");

      run_no = 11547;

      Eb        = 3.7278;  
      th_bb     = 36.0; 
      th_sbs    = 31.9; 
      hcal_dist = 11.0;
        
      runtime   = (8. + (63*1./73.) )* 60.;    
      avI       = 3.5;     

      pdiff_off = 0.0;

      sh_min  = 0.70;
      sh_max  = 0.95;
      ps_min  = 0.1;

      pxmean = -0.062;
      pxsig = 0.15;
      ymean = 0.037;
      ysig = 0.12;
      
      pdiffcut = 0.05;

      W_minc = 0.0;
      W_maxc = 4.0;

    }  
    else if( kin_no == 44) { //SBS-4
      //sbsmag 30%
      //C->Add("$OUT_DIR/LH2/*11499*.root");
      //C->Add("$OUT_DIR/LH2/*11500*.root");
      //C->Add("$OUT_DIR/LH2/*11520*.root");
      //C->Add("$OUT_DIR/LH2/*11547*.root");
      //    C->Add("/work/halla/sbs/ralphmm/Rootfiles/e1209019_fullreplay_11547_stream0_seg0_76.root");
      //C->Add("$OUT_DIR/LH2/*11548*.root");
      //sbsmag off
      //C->Add("$OUT_DIR/LH2/*11573*.root");
      //C->Add("$OUT_DIR/LH2/*11587*.root");
      //C->Add("$OUT_DIR/LH2/*11588*.root");
      //sbsmag 50%
      // C->Add("$OUT_DIR/e1209019_fullreplay_11562*.root");
      //C->Add("$OUT_DIR/LH2/e1209019_fullreplay_11590*.root");
      //C->Add("$OUT_DIR/LH2/e1209019_fullreplay_11592*.root");
      //C->Add("$OUT_DIR/LH2/e1209019_fullreplay_11616*.root");
    
      C->Add("$OUT_DIR/../e1209019_fullreplay_11562*.root");

      run_no = 11562;

      Eb        = 3.7278;  
      th_bb     = 36.0; 
      th_sbs    = 31.9; 
      hcal_dist = 11.0;
        
      runtime   = (8. + (63*1./73.) )* 60.;    
      avI       = 3.5;     

      pdiff_off = 0.0;

      sh_min  = 0.70;
      sh_max  = 0.95;
      ps_min  = 0.1;

      pxmean = -0.062;
      pxsig = 0.15;
      ymean = 0.037;
      ysig = 0.12;
      
      pdiffcut = 0.05;

      W_minc = 0.0;
      W_maxc = 4.0;

    }  
    else if( kin_no == 440) { //SBS-4
    
      C->Add("$OUT_DIR/../SBS4_LH2/*.root");

      run_no = 11562;

      Eb        = 3.7278;  
      th_bb     = 36.0; 
      th_sbs    = 31.9; 
      hcal_dist = 11.0;
        
      runtime   = (8. + (63*1./73.) )* 60.;    
      avI       = 3.5;     

      pdiff_off = 0.0;

      sh_min  = 0.70;
      sh_max  = 0.95;
      ps_min  = 0.1;

      pxmean = -0.33;
      pxsig = 0.15;
      ymean = 0.037;
      ysig = 0.15;
      
      pdiffcut = 0.05;

      W_minc = 0.0;
      W_maxc = 4.0;

    }  
    else if( kin_no == 7) { //SBS-7
      //C->Add("$OUT_DIR/LH2/e1209019_fullreplay_11994_stream0_seg0_99.root");
      C->Add("$OUT_DIR/../e1209019_fullreplay_11994_stream0_seg0_122*.root");
      //C->Add("$OUT_DIR/LH2/gmn_replayed_11994*.root");

      run_no = 11994;
    
      Eb      = 7.906;   
      th_bb   = 40.0;   
      th_sbs  = 16.1; 
      hcal_dist = 14.0;
        
      runtime = 87. * (3.975 / 10.) * 60.;
      //runtime = 87. * 60.;   
      avI = 8;
      
      pdiff_off = 0.23;

      sh_min  = 0.65;
      sh_max  = 1.0;
      ps_min  = 0.10;
      
      pxmean = -1.0;
      pxsig = 0.1;
      ymean = -0.2;
      ysig = 0.1;
      
      pdiffcut = 0.05;

      //W_minc = 0.0;
      //W_maxc = 4.0;
    }
    else if( kin_no == 11) { //SBS-11

      C->Add("$OUT_DIR/../fADDC/e1209019_fullreplay_12313_stream0_seg*.root");

      //     C->Add("$OUT_DIR/LH2/*12313*.root");
      //     C->Add("$OUT_DIR/LH2/*12320*.root");
      //     C->Add("$OUT_DIR/LH2/*12345*.root");

      run_no = 12313;

      Eb      = 9.91;   
      th_bb   = 42.0; 
      th_sbs  = 13.3; 
      hcal_dist = 14.5;
    
      runtime = (59. + 74. + 95.) * 60.;
      avI     = 15.;
    
      pdiff_off = 0.23;

      sh_min  = 0.75;
      sh_max  = 1.05;
      ps_min  = 0.12;

      pxmean = -1.0;
      pxsig = 0.1;
      ymean = -0.2;
      ysig = 0.1;
     
      pdiffcut = 0.1;
    }
    else if( kin_no == 14) { //SBS-14

      //     C->Add("$OUT_DIR/LH2/gmn_replayed_13241*.root");
      //     C->Add("$OUT_DIR/LH2/gmn_replayed_13242*.root");
      //     C->Add("$OUT_DIR/LH2/gmn_replayed_13243*.root");

      C->Add("$OUT_DIR/../e1209019_fullreplay_1324*.root");

      run_no = 13244;

      Eb      = 5.9648;   
      th_bb   = 46.5; 
      th_sbs  = 17.3; 
      hcal_dist = 14.;
        
      // runtime = (25. + 28.) * 60.;
      runtime = (32. + 25. + 28.) * 60.;
      avI = 9.6;
    
      pdiff_off = 0.23;

      sh_min  = 0.75;
      sh_max  = 1.05;
      ps_min  = 0.07;
    
      pxmean = -0.75;
      pxsig = 0.125;
      ymean = -0.4;
      ysig = 0.125;
    
      pdiffcut = 0.1;
    }
    else if( kin_no == 8) { //SBS-8
      //production
      //C->Add("$OUT_DIR/LH2/e1209019_fullreplay_13486_stream0_seg8*.root");
      //    C->Add("$OUT_DIR/LH2/e1209019_fullreplay_13486*.root"); 

      C->Add("$OUT_DIR/../e1209019_fullreplay_13486*.root");

      run_no = 13486;
    
      //sbs magnet off
      //C->Add("$OUT_DIR/LH2/e1209019_fullreplay_13461*.root");
    
      Eb      = 6.0;   
      th_bb   = 26.5; 
      th_sbs  = 29.9; 
      hcal_dist = 11.0;
        
      runtime = 63. * 60.;
      avI     = 8.0;
    
      pdiff_off = -0.03;

      sh_min  = 0.70;
      sh_max  = 1.05;
      ps_min  = 0.07;
      
      pxmean = -0.676;
      pxsig = 0.113;
      ymean = -0.171;
      ysig = 0.155;
    
      pdiffcut = 0.1;
    }
    else if( kin_no == 18) { //SBS-8
      //production
      //C->Add("$OUT_DIR/LH2/e1209019_fullreplay_13486_stream0_seg8*.root");
      //    C->Add("$OUT_DIR/LH2/e1209019_fullreplay_13486*.root"); 

      C->Add("$OUT_DIR/../e1209019_fullreplay_13608*.root");

      run_no = 13608;
    
      //sbs magnet off
      //C->Add("$OUT_DIR/LH2/e1209019_fullreplay_13461*.root");
    
      Eb      = 6.0;   
      th_bb   = 26.5; 
      th_sbs  = 29.9; 
      hcal_dist = 11.0;
        
      runtime = 63. * 60.;
      avI     = 8.0;
    
      pdiff_off = -0.03;

      sh_min  = 0.70;
      sh_max  = 1.05;
      ps_min  = 0.07;
      
      pxmean = -0.676;
      pxsig = 0.113;
      ymean = -0.171;
      ysig = 0.155;
    
      pdiffcut = 0.1;
    }
    else if( kin_no == 9) { //SBS-9
      //C->Add("$OUT_DIR/LH2/e1209019_fullreplay_13683_stream0_seg8*.root");
      //C->Add("$OUT_DIR/LH2/e1209019_fullreplay_13657*.root"); 
      //C->Add("$OUT_DIR/LH2/e1209019_fullreplay_13683*.root"); 
      //C->Add("$OUT_DIR/LH2/e1209019_fullreplay_13696*.root"); 
      //C->Add("$OUT_DIR/LH2/e1209019_fullreplay_13697*.root");
      //    C->Add("/work/halla/sbs/ralphmm/Rootfiles/e1209019_fullreplay_13656*.root");
    
      C->Add("$OUT_DIR/../e1209019_fullreplay_13656_stream0_seg0_106*.root");

      run_no = 13656;

      Eb      = 4.014;   
      th_bb   = 49.0; 
      th_sbs  = 22.5; 
      hcal_dist = 11.0;
        
      runtime = (59.*(76./163.) + 75.*(100./186.) + 48.*(100./142.)) * 60.; 
      avI     = 15.;
    
      pdiff_off = 0.29;

      sh_min  = 0.6;
      sh_max  = 0.9;
      ps_min  = 0.12;
    
      pxmean = -0.634;
      pxsig = 0.094;
      ymean = -0.460;
      ysig = 0.155;
    
      pdiffcut = 0.2;
    }
    else if( kin_no == 19) { //SBS-9
      //C->Add("$OUT_DIR/LH2/e1209019_fullreplay_13683_stream0_seg8*.root");
      //C->Add("$OUT_DIR/LH2/e1209019_fullreplay_13657*.root"); 
      //C->Add("$OUT_DIR/LH2/e1209019_fullreplay_13683*.root"); 
      //C->Add("$OUT_DIR/LH2/e1209019_fullreplay_13696*.root"); 
      //C->Add("$OUT_DIR/LH2/e1209019_fullreplay_13697*.root");
      //    C->Add("/work/halla/sbs/ralphmm/Rootfiles/e1209019_fullreplay_13656*.root");
    
      C->Add("$OUT_DIR/../e1209019_fullreplay_13681_*.root");

      run_no = 13681;

      Eb      = 4.014;   
      th_bb   = 49.0; 
      th_sbs  = 22.5; 
      hcal_dist = 11.0;
        
      runtime = (59.*(76./163.) + 75.*(100./186.) + 48.*(100./142.)) * 60.; 
      avI     = 15.;
    
      pdiff_off = 0.29;

      sh_min  = 0.6;
      sh_max  = 0.9;
      ps_min  = 0.12;
    
      pxmean = -0.634;
      pxsig = 0.094;
      ymean = -0.460;
      ysig = 0.155;
    
      pdiffcut = 0.2;
    }
  }
  //End of setting kinematics

  const Double_t Mp = 0.938272; //proton mass (gev/c2)
  const Double_t Mn = 0.939565; //neutron mass (gev/c2)

  pcent = Eb / (1+(2*Eb/Mp)*pow(sin(TMath::DegToRad()*th_bb/2),2));
  cout << "pcent = " << pcent << endl;
  cout << "pdiffcut = " << pdiffcut << endl;
  
  GEnTree* T = new GEnTree(C);  
  Long64_t nentries = C->GetEntries();
  //nentries = 1000000;

  if(nentries == 0){
    cout << gSystem->Getenv("ROOTFILE_DIR") << " appears to be empty. Check files and/or paths." << endl;
    exit(1);
  }
  
  TFile *outfile = new TFile(Form("AnaOut_%s%i_%s.root",Exp.Data(),kin_no,Target.Data()),"RECREATE");
  //TFile *outfile = new TFile(Form("TEST_%s_%i.root",Target.Data(),kin_no),"RECREATE");
  
  gStyle->SetOptFit(0);
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  gStyle->SetPalette(1);

  gStyle->SetCanvasColor(0);
  gStyle->SetFrameFillColor(0);

  gStyle->SetPadTopMargin(.05);
  gStyle->SetPadLeftMargin(.18);
  gStyle->SetPadRightMargin(.18);
  gStyle->SetPadBottomMargin(.15);

  gStyle->SetTitleOffset(1.1, "X");
  gStyle->SetTitleOffset(1.5, "Y");
  gStyle->SetTitleFont(42,"X");
  gStyle->SetTitleFont(42,"Y");
  gStyle->SetTitleSize(0.055,"X");
  gStyle->SetTitleSize(0.055,"Y");

  gStyle->SetLabelOffset(0.01, "X");
  gStyle->SetLabelOffset(0.01, "Y");
  gStyle->SetLabelFont(42,"X");
  gStyle->SetLabelFont(42,"Y");
  gStyle->SetLabelSize(0.045,"X");
  gStyle->SetLabelSize(0.045,"Y");

  gStyle->SetNdivisions(105,"X");
  gStyle->SetNdivisions(105,"Y");

  gStyle->SetStripDecimals(kFALSE);
  
  //kinematic histo defs
  //TH1D* hQ2 = new TH1D("hQ2","",50,0,12);
  //TH1D* hW2 = new TH1D("hW2","",50,0,12);
  //TH1D* hEpsilon = new TH1D("hEpsilon","",50,0,12);
  //TH1D* hXbj = new TH1D("hXbj","",50,0,12);
  //TH1D* hNu = new TH1D("hNu","",50,0,12);
  
  //TH2D* hWvP = new TH2D("hWvP","",50,0,4,50,-2,0.5);

  //hodo histo defs
  TH1D* hth_tmult   = new TH1D("hth_tmult","",6,0,6);
  TH1D* hth_hmult   = new TH1D("hth_cmult","",6,0,6);
  TH1D* hth_csize   = new TH1D("hth_csize","",6,0,6);

  TH1D* hth_tx      = new TH1D("hth_tx","",90,-1.125,1.125);
  TH1D* hth_ty      = new TH1D("hth_ty","",90,-0.30,0.30);

  TH1D* hth_xmean   = new TH1D("hth_xmean","",90,-1.125,1.125);
  TH1D* hth_xdiff   = new TH1D("hth_xdiff","",100,-0.2,0.2);
  TH1D* hth_ymean   = new TH1D("hth_ymean","",90,-0.30,0.30);
  TH1D* hth_ydiff   = new TH1D("hth_ydiff","",100,-0.2,0.2);

  TH2D* hth2d_txy    = new TH2D("hth2d_txy","", 1,-0.30,0.30, 90,-1.125,1.125);
  TH2D* hth2d_xymean = new TH2D("hth2d_xymean","", 1,-0.30,0.30, 90,-1.125,1.125);
  TH2D* hth2d_xdiff  = new TH2D("hth2d_xdiff","",20,-0.08,0.08,90,0,90);
  TH2D* hth2d_ydiff  = new TH2D("hth2d_ydiff","",20,-0.16,0.16,90,0,90);
  TH2D* hth2d_tdiff  = new TH2D("hth2d_tdiff","",100,-100.,100.,90,0,90);
  TH2D* hth2d_tmean  = new TH2D("hth2d_tmean","",100,-20.,20.,90,0,90);
  TH2D* hth2d_Diff   = new TH2D("hth2d_Diff", "", 50, -0.35, 0.35, 50, -5., 5. );

  
  TH2D* hth2d_fadcr1  = new TH2D("hth2d_fadcr1","",125,0.,250.,32,0,32);
  TH2D* hth2d_fadcr2  = new TH2D("hth2d_fadcr2","",125,0.,250.,32,0,32);
  TH2D* hth2d_fadcl1  = new TH2D("hth2d_fadcl1","",125,0.,250.,32,0,32);
  TH2D* hth2d_fadcl2  = new TH2D("hth2d_fadcl2","",125,0.,250.,32,0,32);
  TH1D* hth_fadcl1    = new TH1D("hth_fadcl1","",125,0.,250.);
  TH1D* hth_fadcl2    = new TH1D("hth_fadcl2","",125,0.,250.);
  TH1D* hth_fadcr1    = new TH1D("hth_fadcr1","",125,0.,250.);
  TH1D* hth_fadcr2    = new TH1D("hth_fadcr2","",125,0.,250.);
  
  
  //kinematic histo defs
  //TH1D* hkin_p        = new TH1D("hkin_p","",100,0.25*pcent,1.25*pcent);
  //TH1D* hkin_th       = new TH1D("hkin_th","",100,-0.3,0.3);
  //TH1D* hkin_ph       = new TH1D("hkin_ph","",100,-0.1,0.1);
  //TH1D* hkin_x        = new TH1D("hkin_x","",100,-1.0,1.0);
  //TH1D* hkin_y        = new TH1D("hkin_y","",100,-0.4,0.4);
  //TH1D* hkin_yt       = new TH1D("hkin_yt","",100,-0.15,0.15);
  //TH1D* hkin_pdiff    = new TH1D("hkin_pdiff","",50,-1.5,1.5);
  //TH1D* hkin_W        = new TH1D("hkin_W","",50,W_min,W_max);
  //TH2D* hkin2d_thp    = new TH2D("hkin2d_thp","",100, th_bb-6,th_bb+6.,100,0.25*pcent,1.25*pcent);
  
  //TH1D* hkin_pc       = new TH1D("hkin_pc","",100,0.25*pcent,1.25*pcent);
  //TH1D* hkin_thc      = new TH1D("hkin_thc","",100,-0.3,0.3);
  //TH1D* hkin_phc      = new TH1D("hkin_phc","",100,-0.1,0.1);
  //TH1D* hkin_xc       = new TH1D("hkin_xc","",100,-1.0,1.0);
  //TH1D* hkin_yc       = new TH1D("hkin_yc","",100,-0.4,0.4);
  //TH1D* hkin_ytc      = new TH1D("hkin_ytc","",100,-0.15,0.15);
  //TH1D* hkin_pdiffc   = new TH1D("hkin_pdiffc","",50,-1.5,1.5);
  //TH1D* hkin_Wc       = new TH1D("hkin_Wc","",50,W_min,W_max);
  //TH2D* hkin2d_thpc    = new TH2D("hkin2d_thpc","",100, th_bb-6,th_bb+6.,100,0.25*pcent,1.25*pcent);
  
  //bbcal energy and position histo defs
  //TH1D *hbbcal_psE    = new TH1D("hbbcal_psE","",100,0,1.25*pcent/2.); 
  //TH1D *hbbcal_shE    = new TH1D("hbbcal_shE","",100,0,1.25*pcent); 
  //TH1D* hbbcal_cale   = new TH1D("hbbcal_cale","",100,0.25*pcent,1.25*pcent);
  //TH1D* hbbcal_edivp  = new TH1D("hbbcal_edivp","",100,-1.0,1.0);
  //TH1D* hbbcal_xdiff  = new TH1D("hbbcal_xdiff","",100,-0.2,0.2);
  //TH1D* hbbcal_ydiff  = new TH1D("hbbcal_ydiff","",100,-0.2,0.2);
  //TH2D *hbbcal2d_pss  = new TH2D("hbbcal2d_pssh","",100,0.,1.2, 100,0.,1.2); 
  
  //TH1D *hbbcal_psEc   = new TH1D("hbbcal_psEc","",100,0,1.25*pcent/2.); 
  //TH1D *hbbcal_shEc   = new TH1D("hbbcal_shEc","",100,0,1.25*pcent); 
  //TH1D* hbbcal_calec  = new TH1D("hbbcal_calec","",100,0.25*pcent,1.25*pcent);
  //TH1D* hbbcal_edivpc = new TH1D("hbbcal_edivpc","",100,-1.0,1.0);
  //TH1D* hbbcal_xdiffc = new TH1D("hbbcal_xdiffc","",100,-0.2,0.2);
  //TH1D* hbbcal_ydiffc = new TH1D("hbbcal_ydiffc","",100,-0.2,0.2);
  //TH2D *hbbcal2d_pssc  = new TH2D("hbbcal2d_psshc","",100,0.,1.2, 100,0.,1.2); 
  
  //TH2D* hhcal_xbb   = new TH2D("hhcal_xbb","",100,-1.2,1.2,100,-1.2,1.2);
  //TH2D* hhcal_ybb   = new TH2D("hhcal_ybb","",100,-0.3,0.3,100,-0.3,0.3);
  //TH1D* hhcal_xdiff = new TH1D("hhcal_xdiff","",100,-1.2,1.2);
  //TH1D* hhcal_ydiff = new TH1D("hhcal_ydiff","",100,-1.2,1.2);
  //TH1D* hhcal_xdiffc = new TH1D("hhcal_xdiffc","",100,-1.2,1.2);
  //TH1D* hhcal_xdiffcW = new TH1D("hhcal_xdiffcW","",100,-1.2,1.2);
  //TH1D* hhcal_ydiffc = new TH1D("hhcal_ydiffc","",100,-1.2,1.2);

  //hcal position histo defs
  //TH1D* hhcal_x = new TH1D("hhcal_x","",100,-2.5,2.5);
  //TH1D* hhcal_y = new TH1D("hhcal_y","",100,-4.,4.);
  //TH2D* hhcal_xy = new TH2D("hhcal_xy","",100,-2.,2.,100,-2.5,1.);
  //TH1D* hhcal_predx = new TH1D("hhcal_predx","",100,-2.5,2.5);
  //TH1D* hhcal_predy = new TH1D("hhcal_predy","",100,-4.,4.);
  //TH2D* hhcal_predxy = new TH2D("hhcal_predxy","",100,-2.,2.,100,-2.,2.);
  TH1D* hhcal_dx = new TH1D("hhcal_dx","",100,-4,4);
  TH1D* hhcal_dy = new TH1D("hhcal_dy","",100,-10,10);
  TH2D* hhcal_dxy = new TH2D("hhcal_dxy","",100,-10,10,100,-4,4);
  
  //TH1D* hhcal_xc = new TH1D("hhcal_xc","",100,-2.5,2.5); 
  //TH1D* hhcal_yc = new TH1D("hhcal_yc","",100,-2.,2.); 
  //TH2D* hhcal_xyc = new TH2D("hhcal_xyc","",100,-2.,2.,100,-2.5,1.);
  //TH1D* hhcal_predxc = new TH1D("hhcal_predxc","",100,-2.5,2.5);
  //TH1D* hhcal_predyc = new TH1D("hhcal_predyc","",100,-4.,4.);
  //TH2D* hhcal_predxyc = new TH2D("hhcal_predxyc","",100,-2.,2.,100,-2.,2.);
  TH1D* hhcal_dxc = new TH1D("hhcal_dxc","",100,-4,4);
  TH1D* hhcal_dyc = new TH1D("hhcal_dyc","",100,-10,10);
  TH2D* hhcal_dxyc = new TH2D("hhcal_dxyc","",100,-10,10,100,-4,4);
  
  TH2D* hkin_dxyc = new TH2D("hkin_dxyc","",100,-4,4,100,-4,4);
  
  //TH1D* hbbcal_pxdiff = new TH1D("hbbcal_pxdiff","",100,-0.5,0.5);
  //TH1D* hbbcal_pydiff = new TH1D("hbbcal_pydiff","",100,-0.5,0.5);
  //TH1D* hbbcal_pzdiff = new TH1D("hbbcal_pzdiff","",100,-0.5,0.5);
  
  //TH2D* hhcalsh_blkdiff = new TH2D("hhcalbbsh_blkdiff","",5,0,5,5,0,5);
  //TH2D* hhcalps_blkdiff = new TH2D("hhcalbbps_blkdiff","",5,0,5,5,0,5);
  
   //Asymmetry Plots
  //TH1D* hneutron_dx_hplus = new TH1D("hneutron_dx_hplus","",50,-4,4);
  //TH1D* hneutron_dx_hminus = new TH1D("hneutron_dx_hminus","",50,-4,4);
  //TH1D* hproton_dx_hplus = new TH1D("hproton_dx_hplus","",50,-4,4);
  //TH1D* hproton_dx_hminus = new TH1D("hproton_dx_hminus","",50,-4,4);

  //optics histo defs
  TH2D* hopt_x_pd     = new TH2D("hopt_x_pd","",  20,-0.8,0.8,   20,-0.1, +0.1);
  TH2D* hopt_y_pd     = new TH2D("hopt_y_pd","",  20,-0.3,0.3,   20,-0.1, +0.1);
  TH2D* hopt_xp_pd     = new TH2D("hopt_xp_pd","",20,-0.25,0.25, 20,-0.1, +0.1);
  TH2D* hopt_yp_pd     = new TH2D("hopt_yp_pd","",20,-0.1,0.1,   20,-0.1, +0.1);
  TH2D* hopt_p_pd      = new TH2D("hopt_p_pd","",20,pcent-0.2,pcent+0.2,    20,-0.1, +0.1);
  TH2D* hopt_th_pd     = new TH2D("hopt_th_pd","",20,-0.3,0.3,   20,-0.1, +0.1);
  TH2D* hopt_ph_pd     = new TH2D("hopt_ph_pd","",20,-0.1,0.1,   20,-0.1, +0.1);
  TH2D* hopt_yt_pd     = new TH2D("hopt_yt_pd","",20,-0.1,0.1,   20,-0.1, +0.1);

  TH2D* hopt_x_pc     = new TH2D("hopt_x_pc","",  20,-0.8,0.8,   20,pcent-0.2,pcent+0.2);
  TH2D* hopt_y_pc     = new TH2D("hopt_y_pc","",  20,-0.3,0.3,   20,pcent-0.2,pcent+0.2);
  TH2D* hopt_xp_pc     = new TH2D("hopt_xp_pc","",20,-0.25,0.25, 20,pcent-0.2,pcent+0.2);
  TH2D* hopt_yp_pc     = new TH2D("hopt_yp_pc","",20,-0.1,0.1,   20,pcent-0.2,pcent+0.2);
  TH2D* hopt_p_pc      = new TH2D("hopt_p_pc","",20,pcent-0.2,pcent+0.2,   20,pcent-0.2,pcent+0.2);
  TH2D* hopt_th_pc     = new TH2D("hopt_th_pc","",20,-0.3,0.3,   20,pcent-0.2,pcent+0.2);
  TH2D* hopt_ph_pc     = new TH2D("hopt_ph_pc","",20,-0.1,0.1,   20,pcent-0.2,pcent+0.2);
  TH2D* hopt_yt_pc     = new TH2D("hopt_yt_pc","",20,-0.1,0.1,   20,pcent-0.2,pcent+0.2);

  const Int_t    nBarsTDC   = 90;
  TH1D* hResx[nBarsTDC];
  TH1D* hResy[nBarsTDC];
  TH1D* hRest[nBarsTDC];
  TH1D* hResmt[nBarsTDC];
  TH1D* hResmt1[nBarsTDC];
  TH1D* hRestd[nBarsTDC];
  TH2D* hDiff[nBarsTDC];
  TH2D* hDiffc[nBarsTDC];
  TH2D* hDiffp[nBarsTDC];
  TH2D* hDiffE[nBarsTDC];
  TH2D* hDiffshE[nBarsTDC];
  TH2D* hDiffpsE[nBarsTDC];
  TH2D* hMean[nBarsTDC];
  TH2D* hMeanc[nBarsTDC];
  TH2D* hMeanp[nBarsTDC];
  TH2D* hMeanE[nBarsTDC];
  TH2D* hMeanshE[nBarsTDC];
  TH2D* hMeansht[nBarsTDC];
  TH2D* hMeansht0[nBarsTDC];
  TH2D* hMeansht1[nBarsTDC];
  TH2D* hMeansht2[nBarsTDC];
  TH2D* hMeansht3[nBarsTDC];
  TH2D* hMeansht4[nBarsTDC];
  TH2D* hMeansht5[nBarsTDC];
  TH2D* hMeanpsE[nBarsTDC];
  
  for(Int_t i=0; i<nBarsTDC; i++) {
    hDiff[i] = new TH2D(Form("hDiff_%d",i), "", 50, -0.35, 0.35, 50, -7., 7. );
    hDiffc[i] = new TH2D(Form("hDiffc_%d",i), "", 50, -0.35, 0.35, 50, -7., 7. );
    hDiffp[i] = new TH2D(Form("hDiffp_%d",i), "", 50, -0.15, 0.15, 50, -7., 7. );
    hDiffE[i] = new TH2D(Form("hDiffE_%d",i), "", 50, 1.0, 2.7, 50, -7., 7. );
    hDiffshE[i] = new TH2D(Form("hDiffshE_%d",i), "", 50, 0.0, 2.0, 50, -7., 7. );
    hDiffpsE[i] = new TH2D(Form("hDiffpsE_%d",i), "", 50, 0.0, 2.0, 50, -7., 7. );

//     hMean[i]   = new TH2D(Form("hMean_%d",i), "", 50, 0.25*pcent,1.25*pcent, 50, -12., 12. );
//     hMeanc[i]  = new TH2D(Form("hMeanc_%d",i), "", 50, 0.25*pcent,1.25*pcent, 50, -12., 12. );

    hMean[i]   = new TH2D(Form("hMean_%d",i), "", 50, -12., 12., 50, -12., 12. );
    hMeanc[i]  = new TH2D(Form("hMeanc_%d",i), "", 50, -12., 12., 50, -12., 12. );

    hMeanp[i] = new TH2D(Form("hMeanp_%d",i), "", 50, 0.25*pcent,1.25*pcent,  50, -12., 12. );
    hMeanE[i] = new TH2D(Form("hMeanE_%d",i), "", 50, 1.0, 2.7, 50, -12., 12. );
    hMeanshE[i] = new TH2D(Form("hMeanshE_%d",i), "", 50, 0.0, 2.0, 50, -7., 7. );
    hMeansht[i] = new TH2D(Form("hMeansht_%d",i), "", 100, -20.0, 20.0, 50, -10., 10. );
    
    hMeansht0[i] = new TH2D(Form("hMeansht0_%d",i), "", 100, -10.0, 10.0, 50, -10., 10. );
    hMeansht1[i] = new TH2D(Form("hMeansht1_%d",i), "", 100, -30.0, 30.0, 50, -30., 30. );
    hMeansht2[i] = new TH2D(Form("hMeansht2_%d",i), "", 100, -30.0, 30.0, 50, -10., 10. );
    hMeansht3[i] = new TH2D(Form("hMeansht3_%d",i), "", 100, -30.0, 30.0, 50, -10., 10. );
    hMeansht4[i] = new TH2D(Form("hMeansht4_%d",i), "", 100, -30.0, 30.0, 50, -10., 10. );
    hMeansht5[i] = new TH2D(Form("hMeansht5_%d",i), "", 100, -30.0, 30.0, 50, -30., 30. );
    hMeanpsE[i] = new TH2D(Form("hMeanpsE_%d",i), "", 50, 0.0, 2.0, 50, -12., 12. );
  }
  
  const Double_t bb_dist = 1.630;
  const Double_t hodo_dist  = 1.8545;
  const Double_t show_dist  = 1.902;

  TLorentzVector Tp4(0,0,0,Mp); //target 4vec
  TLorentzVector kp4(0,0,Eb,Eb); //beam 4vec
  TLorentzVector Qp4, kpp4, Rp4; //q, recoil electron, recoil nucleon
  
  th_bb = TMath::DegToRad() * th_bb;
  th_sbs = TMath::DegToRad() * th_sbs;
  avI = avI * 0.85;
  
  TVector3 hcal_origin( -hcal_dist*sin(th_sbs), 0, hcal_dist*cos(th_sbs) );
  
  TVector3 hcal_zaxis = hcal_origin.Unit();
  TVector3 hcal_xaxis(0,-1,0);
  TVector3 hcal_yaxis = hcal_zaxis.Cross( hcal_xaxis ).Unit();
  
  Double_t bbth_vscint[] = {
    0.180805, 0.175, 0.1828, 0.170004, 0.155359, 0.175734, 0.165697, 0.148091, 0.149093, 0.157593, 0.156496, 0.147809, 0.144615, 0.155042,
    0.153622, 0.156597, 0.18024, 0.189606, 0.18859, 0.191777, 0.187433, 0.18625, 0.194762, 0.181658, 0.170269, 0.173745, 0.17409,  0.178897,
    0.182398, 0.181071, 0.178551, 0.173263, 0.173062, 0.182632, 0.172438, 0.163344, 0.163478, 0.173636, 0.17075, 0.174676, 0.170085, 0.175636,
    0.177966, 0.176808, 0.176445, 0.185673, 0.194028, 0.190548, 0.178487, 0.17055, .16343, .156035, .161937, .181659, .190242, .187991, .171034,
    0.157068, .155213, .157255, .162826, .16233, .162542, .165997, .166097, .170121, .17755, .181141, .16835,  .164615, .186073, .204715,
    0.191067, .181214, .166507, .149339, .136413, .147212, .154051, .140077, .202052, .178857, .175, .20838, .150853, .175, .175, .175, .175, .175  };

  Double_t bbth_tdiffoffset[] = {
    -2.65084, -0.68, -2.66389, -2.85596, -2.41139, -1.71499, -1.25864, -1.16894, -1.055, -1.28258, -1.46683, -1.43057, -1.65976, -1.37499, -1.36125,
    -1.29987, -0.87604, -0.896621, -1.0101, -1.07004, -1.1659, -1.16767, -1.10648, -1.06361, -1.25146, -1.18546, -1.04481, -0.923806, -0.746351,
    -0.927521, -1.17295, -1.4767, -1.36772, -1.03762, -0.826993, -0.553472, -0.405161, 0.00429142, -0.024965, 0.000631514, -0.202755, -0.210413,
    -0.168327, -0.148707, -0.384142, -0.542555, -0.565375, -0.530648, -0.156928, -0.308494, -0.356375, -0.64134, -0.743249, -0.477605,   -0.732362,
    -0.656796, -0.670947, -0.659558, -0.629137, -0.787749, -1.01695, -1.05689, -1.10139, -0.999139, -0.783825, -0.621926, -0.412212, -0.379391,
    -0.445681, -0.411827, -0.73396, -0.874087, -0.716473, -0.794139, -0.821767, -0.755983, -1.13393, -0.768597, 2.05995, 1.49198,   -0.35568,
    -0.211182, -0.68, -0.356193, -0.945469, -0.68, -0.68, -0.68, -0.68, -0.68 };
  
  
  ////////////////////////////////////////////////////////
  //Data loop
  //Double_t realIHWP = 0;
  //int prevRun = -1;
  //int curRun;
  //int tempev;
  cout << "Processing " << nentries << " events." << endl;
  for(Long64_t ev=0; ev<nentries;ev++) {
    
    //if (ev != 0) prevRun = T->fEvtHdr_fRun;
    
    T->GetEntry(ev);
    //curRun = T->fEvtHdr_fRun;
    
    //Double_t tempIHWP;
    
    /*
    if (prevRun != curRun){
      cout << "New Run, " << curRun << ", recalibrating the IHWP." << endl;
      tempev = ev;
      tempIHWP = T->IGL1I00OD16_16; //half wave plate in/out
      while(fabs(tempIHWP) != 1){
	tempev++;
	T->GetEntry(tempev);
	tempIHWP = T->IGL1I00OD16_16;
      }
      cout << "realistic IHWP value of " << tempIHWP << " found, resuming analysis" << endl;
    }
    
    Double_t IHWP = tempIHWP;
    */
    
    if( ev%10000 == 0 )
      cout << ev << endl;

    // Pre-cuts -- these should be in the replay cdef
    if( T->bb_tr_n <= 0 ) continue; 
    if( T->bb_ps_e < 0.05 ) continue;
     
    //hcal 2 arm cuts
    if ( T->sbs_hcal_e <= 0 ) continue;
    if ( T->sbs_hcal_nclus <= 0) continue;
    
    //target z vertex cut (get rid of end caps)
    if (Target == "He3")
      if(fabs(T->bb_tr_vz[0]) > 0.27) continue;
    //if(T->fEvtHdr_fTrigBits != 1) continue;

    /*
    // Hodo fADCs (no cuts)
    for(int i = 0 ; i < T->Ndata_bb_hodoadc_bar_adc_L_ap ; i++ ) {
      hth2d_fadcl1->Fill(T->bb_hodoadc_bar_adc_L_ap[i], T->bb_hodoadc_bar_adc_id[i]);
      hth_fadcl1->Fill(T->bb_hodoadc_bar_adc_L_ap[i]);
    }
    for(int i = 0 ; i < T->Ndata_bb_hodoadc_bar_adc_R_ap ; i++ ) {
      hth2d_fadcr1->Fill(T->bb_hodoadc_bar_adc_R_ap[i], T->bb_hodoadc_bar_adc_id[i]);
      hth_fadcr1->Fill(T->bb_hodoadc_bar_adc_R_ap[i]);
    }
    */
    
    // Kinematic cuts
    Double_t th  = acos(T->bb_tr_pz[0]/T->bb_tr_p[0]); //theta in the lab
    Double_t th1 = T->bb_tr_th[0]; //theta in the transport system.
    Double_t th2 = T->bb_tr_px[0] / T->bb_tr_pz[0]; //gradient
    

    //Double_t pexp_th2 = 2.*Mp*Eb*(Mp+Eb)*cos(th) / (Mp*Mp + 2.*Mp*Eb + (Eb*sin(th)*Eb*sin(th))); // e mom from angle
    Double_t pexp_th = Eb / (1.0 + Eb/Mp*(1.0-cos(th)));
    Double_t p       = T->bb_tr_p[0];
    Double_t pdiff   = p - pexp_th; 
    
    //cout << pdiff << endl;

    //pdiff = pdiff - pdiff_off;
    //pdiff = pdiff-0.07*T->bb_tr_x[0];
    //pdiff = pdiff-0.32*T->bb_tr_y[0];
    Double_t pc = p;
    
    //Double_t px1 = pc * TMath::Sin( th_bb+T->bb_tr_tg_ph[0] ) * TMath::Cos( T->bb_tr_tg_th[0] );
    //Double_t py1 = pc * TMath::Sin( th_bb+T->bb_tr_tg_ph[0] ) * TMath::Sin( T->bb_tr_tg_th[0] );
    //Double_t pz1 = pc * TMath::Cos( th_bb+T->bb_tr_tg_ph[0] );

    // _tg = target plane,  tr_ = local transport coord system (focal plane variables) 
    Double_t px = T->bb_tr_px[0];
    Double_t py = T->bb_tr_py[0];
    Double_t pz = T->bb_tr_pz[0];
    
    Double_t vx = T->bb_tr_vx[0];
    Double_t vy = T->bb_tr_vy[0];
    Double_t vz = T->bb_tr_vz[0];

    //hbbcal_pxdiff->Fill(px-px1);
    //hbbcal_pydiff->Fill(py+py1);
    //hbbcal_pzdiff->Fill(pz-pz1);
    
    //hhcalsh_blkdiff->Fill(T->Ndata_bb_sh_clus_blk_id,T->Ndata_sbs_hcal_clus_blk_id);
    //hhcalps_blkdiff->Fill(T->Ndata_bb_ps_clus_blk_id,T->Ndata_sbs_hcal_clus_blk_id);
    
    kpp4.SetPxPyPzE(px,py,pz,pc);
    Qp4 = kp4 - kpp4;
    TVector3 qdir = Qp4.Vect().Unit();
    Rp4 = Tp4 + Qp4;
    Double_t W2 = T->e_kine_W2;
    //Double_t W2 = Rp4.M2(); 
    
    Double_t trx_sh  = (T->bb_tr_x[0] + (show_dist) * T->bb_tr_th[0] );
    Double_t try_sh  = (T->bb_tr_y[0] + (show_dist) * T->bb_tr_ph[0] );
    
    Rp4.RotateY(th_sbs);
    
    Double_t hcal_th = TMath::ATan(Rp4.Px()/Rp4.Pz());
    Double_t hcal_ph = TMath::ATan(Rp4.Py()/Rp4.Pz());

    Double_t hcal_x = T->sbs_hcal_x;
    Double_t hcal_y = T->sbs_hcal_y;
   
    //My (old) Method
    //Double_t pred_x = -(hcal_dist * TMath::Sin( hcal_ph ));
    //Double_t pred_y = hcal_dist * TMath::Sin(hcal_th);
    //Double_t dx = hcal_x - pred_x;
    //Double_t dy = hcal_y - pred_y;
    
    //vertex corrections
    TVector3 vertex(0,0,vz);
    double sintersect = (hcal_origin-vertex).Dot( hcal_zaxis )/qdir.Dot( hcal_zaxis );
    TVector3 hcal_intersect = vertex + sintersect * qdir; 
    double pred_x = hcal_intersect.Dot( hcal_xaxis );
    double pred_y = hcal_intersect.Dot( hcal_yaxis );
    double dx = hcal_x - pred_x;
    double dy = hcal_y - pred_y;
    
    //fiducial Cuts
    if( ApplyFidu ) {
      Double_t thtg_cut   = 0.18;
      Double_t phtg_cut   = 0.07;
      Double_t ytg_cut    = 0.15;
      //Double_t th_cut = 0.1;
      //if( fabs(T->bb_tr_th[0])  >  th_cut  ) continue;
      if( fabs(T->bb_tr_tg_th[0]) > thtg_cut ) continue;
      if( fabs(T->bb_tr_tg_ph[0]) > phtg_cut ) continue;
      if( fabs(T->bb_tr_tg_y[0]) > ytg_cut ) continue;
    }

    //hhcal_xdiff->Fill( trx_sh - T->sbs_hcal_y);
    //hhcal_ydiff->Fill( try_sh - T->sbs_hcal_x);
  
    //hkin_p->Fill(p);
    //hkin_x->Fill(T->bb_tr_x[0]);
    //hkin_y->Fill(T->bb_tr_y[0]);
    //hkin_th->Fill(T->bb_tr_tg_th[0]);
    //hkin_ph->Fill(T->bb_tr_tg_ph[0]);
    //hkin_yt->Fill(T->bb_tr_tg_y[0]);
    //hkin_pdiff->Fill( pdiff );
    //hkin_W->Fill(W2);
    //hWvP->Fill(W2,pdiff);
    //hkin2d_thp->Fill(TMath::RadToDeg()*th, p);

    //hbbcal_psE->Fill( T->bb_ps_e );
    //hbbcal_shE->Fill( T->bb_sh_e );
    //hbbcal_cale->Fill((T->bb_ps_e + T->bb_sh_e));
    //hbbcal_edivp->Fill(((T->bb_ps_e + T->bb_sh_e) - p));
    //hbbcal_xdiff->Fill( T->bb_sh_x - trx_sh );
    //hbbcal_ydiff->Fill( T->bb_sh_y - try_sh );
    //hbbcal2d_pss->Fill( T->bb_sh_e/T->bb_tr_p[0], T->bb_ps_e/T->bb_tr_p[0] );
    
    
    //hhcal_xbb->Fill( trx_sh,  T->sbs_hcal_x);
    //hhcal_ybb->Fill( try_sh, T->sbs_hcal_y);
    //hhcal_xdiffc->Fill( trx_sh - T->sbs_hcal_x);
    //hhcal_ydiffc->Fill( try_sh - T->sbs_hcal_y);
    
    //hhcal_x->Fill(hcal_x);
    //hhcal_y->Fill(hcal_y);
    //hhcal_xy->Fill(hcal_y,hcal_x);
    
    //hhcal_predx->Fill(pred_x);
    //hhcal_predy->Fill(pred_y);
    //hhcal_predxy->Fill(pred_y,pred_x);
    
    //hhcal_dx->Fill(dx);
    //hhcal_dy->Fill(dy);
    //hhcal_dxy->Fill(dy,dx);
    
    //pxcut = 3. * pxsig;
    //ycut = 3. * ysig;
    
    //electron cuts
    if( ApplyElec ) { 
      if( T->bb_ps_e/T->bb_tr_p[0] < ps_min ) continue;
      if( (T->bb_ps_e/T->bb_tr_p[0] + sh_e*T->bb_sh_e/T->bb_tr_p[0]) < sh_min ) continue;
      if( (T->bb_ps_e/T->bb_tr_p[0] + sh_e*T->bb_sh_e/T->bb_tr_p[0]) > sh_max) continue;
      if( W2 < W_min ) continue; 
      if( W2 > W_max ) continue;  
    }
    else if (ApplyPion) { 
      if( T->bb_ps_e/T->bb_tr_p[0] > ps_min ) continue;
      if( (T->bb_ps_e/T->bb_tr_p[0] + sh_e*T->bb_sh_e/T->bb_tr_p[0]) > sh_min ) continue;
    }
    
    //elastic cuts
    if (ApplyElas){
      if(Target == "LD2" || Target == "He3"){
	if( pow(dy - ymean,2)/pow(ysig,2)  +  pow(dx - nxmean,2)/pow(nxsig,2)  > pow(nxcut,2)   &&   pow(dy - ymean,2)/pow(ysig,2)  +  pow(dx - pxmean,2)/pow(pxsig,2) > pow(pxcut,2) ) continue;
      }else if(Target=="LH2" || Target == "H2"){
	if(pow(dy - ymean,2)/pow(ysig,2)  +  pow(dx - pxmean,2)/pow(pxsig,2) > pow(pxcut,2)) continue;
      }
      //if( T->bb_tr_p[0] < 0.25*pcent ) continue;
      //if( T->bb_tr_p[0] < 2 ) continue;
      if( W2 < W_minc ) continue; 
      if( W2 > W_maxc ) continue;   
    }

    //hkin_pdiffc->Fill( pdiff );
     
    //hkin_pc->Fill(pc);
    //hkin_xc->Fill(T->bb_tr_x[0]);
    //hkin_yc->Fill(T->bb_tr_y[0]);
    //hkin_thc->Fill(T->bb_tr_tg_th[0]);
    //hkin_phc->Fill(T->bb_tr_tg_ph[0]);
    //hkin_ytc->Fill(T->bb_tr_tg_y[0]);
    //hkin2d_thpc->Fill(TMath::RadToDeg()*th, pc);
    //hkin_Wc->Fill(W2);
    //hkin_dxyc->Fill(dy,dx);
    
    if( ApplyElas ) 
      if( fabs(pdiff) > pdiffcut ) continue;
    
    /*
    //Helicity Stuff + Hcal elastic spot cuts
    Double_t Helicity = T->scalhel_hel; //helicity from tree
    if (IHWP == 1) Helicity *= -1;
    else Helicity *= 1;
      
    //cut on neutron spot
    if( pow(dy - ymean,2)/pow(ysig,2)  +  pow(dx - nxmean,2)/pow(nxsig,2)  <= pow(nxcut,2)){
      if (Helicity == 1) hneutron_dx_hplus->Fill(dx);
      else if (Helicity == -1) hneutron_dx_hminus->Fill(dx);
      //cut on proton spot
    }else if(pow(dy - ymean,2)/pow(ysig,2)  +  pow(dx - pxmean,2)/pow(pxsig,2)  < pow(pxcut,2)){
      if (Helicity == 1) hproton_dx_hplus->Fill(dx);
      else if (Helicity == -1) hproton_dx_hminus->Fill(dx);
    }
    */
    
    //hhcal_xc->Fill(hcal_x);
    //hhcal_yc->Fill(hcal_y);
    //hhcal_xyc->Fill(hcal_y,hcal_x);
    
    //hhcal_predxc->Fill(pred_x);
    //hhcal_predyc->Fill(pred_y);
    //hhcal_predxyc->Fill(pred_y,pred_x);
    
    //hhcal_dxc->Fill(dx);
    //hhcal_dyc->Fill(dy);
    //hhcal_dxyc->Fill(dy,dx);
            
    //hbbcal_psEc->Fill( T->bb_ps_e );
    //hbbcal_shEc->Fill( T->bb_sh_e );
    //hbbcal_calec->Fill((T->bb_ps_e + T->bb_sh_e));
    //hbbcal_edivpc->Fill(((T->bb_ps_e + T->bb_sh_e) - pc));
    //hbbcal_xdiffc->Fill( T->bb_sh_x - (T->bb_tr_x[0] + (show_dist) * T->bb_tr_th[0] ) ); 
    //hbbcal_ydiffc->Fill( T->bb_sh_y - (T->bb_tr_y[0] + (show_dist) * T->bb_tr_ph[0] ) );
    //hbbcal2d_pssc->Fill( T->bb_sh_e/T->bb_tr_p[0], T->bb_ps_e/T->bb_tr_p[0] );
      
    
      if ( PlotOptics ){
	hopt_x_pd->Fill(T->bb_tr_x[0] , pdiff);
	hopt_y_pd->Fill(T->bb_tr_y[0] , pdiff);
	hopt_xp_pd->Fill(T->bb_tr_th[0] , pdiff);
	hopt_yp_pd->Fill(T->bb_tr_ph[0] , pdiff);
	hopt_p_pd->Fill(p , pdiff);
	hopt_th_pd->Fill(T->bb_tr_tg_th[0] , pdiff);
	hopt_ph_pd->Fill(T->bb_tr_tg_ph[0] , pdiff);
	hopt_yt_pd->Fill(T->bb_tr_tg_y[0] , pdiff);
      
	hopt_x_pc->Fill(T->bb_tr_x[0] , p);
	hopt_y_pc->Fill(T->bb_tr_y[0] , p);
	hopt_xp_pc->Fill(T->bb_tr_th[0] , p);
	hopt_yp_pc->Fill(T->bb_tr_ph[0] , p);
	hopt_p_pc->Fill(p , p);
	hopt_th_pc->Fill(T->bb_tr_tg_th[0] , p);
	hopt_ph_pc->Fill(T->bb_tr_tg_ph[0] , p);
	hopt_yt_pc->Fill(T->bb_tr_tg_y[0] , p);
      }
      
      
      
      // GEM-Hodoscope track matching
      if ( PlotHodo ){
	hth_tx->Fill( T->bb_tr_x[0] + hodo_dist * T->bb_tr_th[0] ); // track x at hodo (dispersive)
	hth_ty->Fill( T->bb_tr_y[0] + hodo_dist * T->bb_tr_ph[0] ); // track y at hodo (non-dispersive)
      
	hth2d_txy->Fill( T->bb_tr_y[0] + hodo_dist * T->bb_tr_ph[0], T->bb_tr_x[0] + hodo_dist * T->bb_tr_th[0] );
      
	hth_tmult->Fill(T->bb_tr_n-1); // BB track "id" 
      
	Bool_t Singlebarhit = kFALSE;
	if( T->bb_hodotdc_clus_size[0] == 1 && T->bb_hodotdc_clus_trackindex[0] == 0 )
	  Singlebarhit = kTRUE;
	
	if( Apply1Bar && !Singlebarhit ) continue;
    
	if( T->bb_hodotdc_clus_trackindex[0] == 0 ) {  // only hodo clusters that match bb track id = 0 (I guess redundndat for single track events)	
      
	  hth_csize->Fill( T->bb_hodotdc_clus_size[0] );
	  hth_hmult->Fill( T->bb_hodotdc_clus_trackindex[0] ); // track id that is matched
      
	  hth_xmean->Fill( T->bb_hodotdc_clus_xmean[0] ); // mean x position of hodo cluster
	  hth_xdiff->Fill( (T->bb_hodotdc_clus_xmean[0] - (T->bb_tr_x[0] + hodo_dist * T->bb_tr_th[0])) );
      
	  hth_ymean->Fill( T->bb_hodotdc_clus_ymean[0] ); // mean y position of hodo cluster
	  hth_ydiff->Fill( (T->bb_hodotdc_clus_ymean[0] - (T->bb_tr_y[0] + hodo_dist * T->bb_tr_ph[0])) );
	  
	  Int_t maxbar = (Int_t)T->bb_hodotdc_clus_id[0]; 
	  
	  hth2d_xdiff->Fill( (T->bb_hodotdc_clus_xmean[0] - (T->bb_tr_x[0] + hodo_dist * T->bb_tr_th[0])), maxbar );
	  hth2d_ydiff->Fill( (T->bb_hodotdc_clus_ymean[0] - (T->bb_tr_y[0] + hodo_dist * T->bb_tr_ph[0])), maxbar );
	  hth2d_tmean->Fill( T->bb_hodotdc_clus_tmean[0], maxbar );

	  hth2d_xymean->Fill( T->bb_hodotdc_clus_ymean[0], T->bb_hodotdc_clus_xmean[0] );
      
	  hth2d_Diff->Fill((T->bb_tr_y[0] + hodo_dist * T->bb_tr_ph[0]), 0.5*T->bb_hodotdc_clus_tdiff[0] ); // note th 1/2
	
	  //Double_t HorizPos = -0.5 * (bartimediff-ftDiff0.at(BarInc)) * fvScint.at(BarInc); // position from L based on timediff and in m. 

	  //(-2*y/vscint) + tdiff0  =(bartimediff
	  Double_t tdiff_corr = T->bb_hodotdc_clus_tdiff[0] + (2./bbth_vscint[maxbar]*(T->bb_tr_y[0] + hodo_dist * T->bb_tr_ph[0])) - bbth_tdiffoffset[maxbar];
	  //	Double_t tdiff_corr = T->bb_hodotdc_clus_tdiff[0] + (2./bbth_vscint[maxbar]*(T->bb_tr_y[0] + hodo_dist * T->bb_tr_ph[0])) - bbth_tdiffoffset[maxbar];
	  //	Double_t tdiff_corr = 2 * ( 0.5*T->bb_hodotdc_clus_tdiff[0] + 1./bbth_vscint[maxbar]*(T->bb_tr_y[0] + hodo_dist * T->bb_tr_ph[0]) - bbth_tdiffoffset[maxbar]);

	  hDiff[maxbar]->Fill((T->bb_tr_y[0] + hodo_dist * T->bb_tr_ph[0]), 0.5*T->bb_hodotdc_clus_tdiff[0] ); // note th 1/2
	  hDiffc[maxbar]->Fill( (T->bb_tr_y[0] + hodo_dist * T->bb_tr_ph[0]) , tdiff_corr ); 
	  //	hDiffp[maxbar]->Fill( T->bb_tr_p[0] , tdiff_corr ); 
	  hDiffp[maxbar]->Fill( T->bb_tr_th[0] , tdiff_corr ); 
	  hDiffE[maxbar]->Fill((T->bb_ps_e + T->bb_sh_e)  , tdiff_corr ); 	
	  hDiffshE[maxbar]->Fill((T->bb_sh_e)  , tdiff_corr ); 	
	  hDiffpsE[maxbar]->Fill((T->bb_ps_e)  , tdiff_corr ); 	
	  
	  //float bbtrig0 = -999.;
	  //float bbtrig1 = -999.;
	  //float bbtrig2 = -999.;
	  //float bbtrig3 = -999.;
	  //float bbtrig4 = -999.;
	  //float bbtrig5 = -999.;

	  /*
	  for(int i = 0 ; i < T->Ndata_bb_tdctrig_tdcelemID ; i++ ) {

	    int elem = T->bb_tdctrig_tdcelemID[i];

	    //	  cout << elem << "\t" << T->bb_tdctrig_tdc[i] << endl;

	    if (elem == 0 ) bbtrig0 = T->bb_tdctrig_tdc[i];
	    if (elem == 1 ) bbtrig1 = T->bb_tdctrig_tdc[i];
	    if (elem == 2 ) bbtrig2 = T->bb_tdctrig_tdc[i];
	    if (elem == 3 ) bbtrig3 = T->bb_tdctrig_tdc[i];
	    if (elem == 4 ) bbtrig4 = T->bb_tdctrig_tdc[i];
	    if (elem == 5 ) bbtrig5 = T->bb_tdctrig_tdc[i];
	  }
	  */
	  // 	if( bbtrig0 != -999 )
	  // 	  cout << bbtrig0 << endl;

	  Double_t tmean_corr1, tmean_corr2, tmean_corr;

	  if( T->Ndata_bb_hodotdc_clus_bar_tdc_meantime == 2 ) {

	    //	  tmean_corr = T->bb_hodotdc_clus_tmean[0] - T->bb_hodotdc_Ref_tdc[0];
	  
	    //	  for( int i = 0 ; i < T->Ndata_bb_hodotdc_clus_bar_tdc_meantime ) {


	    tmean_corr1 = T->bb_hodotdc_clus_bar_tdc_meantime[0];
	    // 	  //tmean_corr1 = (tmean_corr1 - 5.14*T->bb_tr_p[0] + 7.71); 

	    tmean_corr2 = T->bb_hodotdc_clus_bar_tdc_meantime[1];
	    // 	  //	  tmean_corr2 = (tmean_corr2 - 5.14*T->bb_tr_p[0] + 7.71); 
	  
	    tmean_corr = tmean_corr2 - tmean_corr1;// - T->bb_hodotdc_Ref_tdc[0]; // - tmean_corr2;
	  
	    // 	  hMean[maxbar]->Fill( T->bb_tr_p[0], tmean_corr1 ); 
	    // 	  hMeanp[maxbar]->Fill( T->bb_tr_p[0], (tmean_corr - 5.14*T->bb_tr_p[0] + 7.71) ); 
	    // 	  hMeanc[maxbar]->Fill( T->bb_tr_p[0], tmean_corr ); 

	    hMean[maxbar]->Fill( tmean_corr2, tmean_corr1 ); 
	    hMeanp[maxbar]->Fill( T->bb_tr_p[0], (tmean_corr - 5.14*T->bb_tr_p[0] + 7.71) ); 
	    hMeanc[maxbar]->Fill( tmean_corr2, tmean_corr ); 
	  

	    //	    Double_t tmean_corr = T->bb_hodotdc_clus_tmean[0];//- 0.42*T->bb_sh_atimeblk - 2.8;  	
	    //	tmean_corr = tmean_corr - 2.7*T->bb_tr_p[0] + 4.7;  	
	
	    Double_t hcal_time = T->sbs_hcal_tdctimeblk + 73;

	    hMeansht0[maxbar]->Fill( tmean_corr1,  tmean_corr2  );
	    hMeansht1[maxbar]->Fill( hcal_time,  (tmean_corr  - hcal_time)  );
	    hMeansht2[maxbar]->Fill( hcal_time,  (tmean_corr)  );
	    hMeansht3[maxbar]->Fill( hcal_time,  tmean_corr1  );
	    hMeansht4[maxbar]->Fill( hcal_time,  tmean_corr2  );
	    hMeansht5[maxbar]->Fill( hcal_time,  (tmean_corr2 - hcal_time)  );

	    //	hMeanc[maxbar]->Fill( T->bb_tr_p[0], tmean_corr ); 

	    //hMeanc[maxbar]->Fill(T->bb_tr_p[0], tmean_corr ); 
	    hMeanE[maxbar]->Fill((T->bb_ps_e + T->bb_sh_e)  , tmean_corr );  	
	    hMeanshE[maxbar]->Fill((T->bb_sh_e)  , tmean_corr );  	
	    //	hMeanc[maxbar]->Fill( (T->bb_sh_e)  , tmean_corr );
	    hMeanpsE[maxbar]->Fill((T->bb_ps_e)  , tmean_corr );  	
	    hMeansht[maxbar]->Fill( T->bb_sh_atimeblk,  tmean_corr  );
	    //hMeansht[maxbar]->Fill( T->bb_sh_atimeblk , tdiff_corr ); 	
	  }
	
	
	  /*
	    if( maxbar >= 32 && maxbar < 64 ) {
	    for(int i = 0 ; i < T->Ndata_bb_hodoadc_bar_adc_L_ap ; i++ ) 
	    if( T->bb_hodoadc_bar_adc_id[i] == maxbar - 32 ) { 
	    hth2d_fadcl2->Fill(T->bb_hodoadc_bar_adc_L_ap[i], T->bb_hodoadc_bar_adc_id[i]);
	    hth2d_fadcr2->Fill(T->bb_hodoadc_bar_adc_R_ap[i], T->bb_hodoadc_bar_adc_id[i]);
	    hth_fadcl2->Fill(T->bb_hodoadc_bar_adc_L_ap[i]);
	    hth_fadcr2->Fill(T->bb_hodoadc_bar_adc_R_ap[i]);
	    }
	    }
	  */
	}
      }
  }//End of event loop
  
  
  
  //-----------------------------------------------------------------------------------------------------------------------------
  // GEM-Hodoscope track matching plots
  //-----------------------------------------------------------------------------------------------------------------------------

    Int_t kin_no1;

    if( kin_no > 14 ) 
      kin_no1 = kin_no - 10;
    else
      kin_no1 = kin_no;


  TLatex* tex;

  if( PlotHodo ) {
    TCanvas* c1 = new TCanvas("c1","",1200,800);
    c1->Divide(4,2);
    
    c1->cd(1);
    hth_tx->Draw("");
    hth_tx->SetLineColor(2);
    hth_xmean->Draw("same");
    hth_tx->GetXaxis()->SetTitle("x_{FP} [m]");
    
    tex = new TLatex( 0.35, 0.3, "GEM");
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(2);
    tex->SetTextSize(0.055);
    tex->Draw();
    
    tex = new TLatex( 0.35, 0.22, "BBHodo");
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(4);
    tex->SetTextSize(0.055);
    tex->Draw();
    
    c1->cd(2);
    hth_ty->Draw("");
    hth_ty->SetLineColor(2);
    hth_ymean->Draw("same");
    hth_ty->GetXaxis()->SetTitle("y_{FP} [m]");
    
    tex = new TLatex( 0.35, 0.3, "GEM");
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(2);
    tex->SetTextSize(0.055);
    tex->Draw();
    
    tex = new TLatex( 0.35, 0.22, "BBHodo");
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(4);
    tex->SetTextSize(0.055);
    tex->Draw();
    
    c1->cd(3);
    
    hth_hmult->Divide(hth_tmult);
    hth_hmult->Draw("");
    hth_hmult->GetXaxis()->SetTitle("BB track ID");
    hth_csize->Draw("");
    hth_csize->SetLineColor(2);
    hth_csize->GetXaxis()->SetTitle("BBHodo Cluster Size");
    
    cout << "Mean cluster size " << hth_csize->GetMean() << endl;
    
    tex = new TLatex( 0.25, 0.8, Form("Mean Size = %3.2f bars", hth_csize->GetMean()) );
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(1);
    tex->SetTextSize(0.055);
    tex->Draw();
    
    tex = new TLatex( 0.25, 0.72, Form("Efficiency = %3.2f %%", 100*hth_hmult->GetBinContent(1)) );
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(1);
    tex->SetTextSize(0.055);
    tex->Draw();
        
    c1->cd(4);
    hth2d_xymean->Divide(hth2d_txy);
    hth2d_xymean->Draw("colz");
    hth2d_xymean->GetYaxis()->SetTitle("x_{FP} [m]");
    hth2d_xymean->GetXaxis()->SetTitle("y_{FP} [m]");
    hth2d_xymean->SetMaximum(1.3);
        
    c1->cd(5);
    TH1D* hth_xmean1 = (TH1D*)hth_xmean->Clone("hth_xmean1");
    hth_xmean->Sumw2();
    hth_xmean1->Sumw2();
    hth_tx->Sumw2();
    hth_xmean1->Divide(hth_tx);
    hth_xmean1->Draw("");
    hth_xmean1->GetXaxis()->SetTitle("x_{FP} [m]");
    hth_xmean1->GetYaxis()->SetTitle("Track Match Efficiency");
    hth_xmean1->SetMaximum(1.5);
    
    c1->cd(6);
    TH1D* hth_ymean1 = (TH1D*)hth_ymean->Clone("hth_ymean1");
    hth_ymean->Sumw2();
    hth_ymean1->Sumw2();
    hth_ty->Sumw2();
    hth_ymean1->Divide(hth_ty);
    hth_ymean1->Draw("");
    hth_ymean1->GetXaxis()->SetTitle("y_{FP} [m]");
    hth_ymean1->GetYaxis()->SetTitle("Track Match Efficiency");
    hth_ymean1->SetMaximum(1.5);
    
    c1->cd(7);
    hth2d_xdiff->Draw("colz");
    hth2d_xdiff->GetXaxis()->SetTitle("#delta x_{FP} (GEM-BBHodo) [m]");
    hth2d_xdiff->GetYaxis()->SetTitle("Hodoscope Bar ID");
    
    c1->cd(8);
    hth2d_ydiff->Draw("colz");
    hth2d_ydiff->GetXaxis()->SetTitle("#delta y_{FP} (GEM-BBHodo) [m]");
    hth2d_ydiff->GetYaxis()->SetTitle("Hodoscope Bar ID");
    
    c1->Print("bbhodo_temp1.pdf");
    c1->cd();

    //-----------------------------------------------------------------------------------------------------------------------------
    // Hodoscope bar efficiencies and resolution plots
    //-----------------------------------------------------------------------------------------------------------------------------

    Int_t barlow  = 12;
    Int_t barhigh = 68;

    TCanvas* c2 = new TCanvas("c2","",1200,800);
    c2->Divide(3,2);

    c2->cd(1);

    tex = new TLatex( 0.34, 0.6, Form("SBS-%d", kin_no1 ));
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(1);
    tex->SetTextSize(0.095);
    tex->Draw();

    tex = new TLatex( 0.24, 0.4, Form("Run %d", run_no ));
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(1);
    tex->SetTextSize(0.095);
    tex->Draw();

    c2->cd(2)->SetRightMargin(.05);
    
    Double_t Eff[nBarsTDC], eEff[nBarsTDC];
    Double_t Bar[nBarsTDC], eBar[nBarsTDC];
    
    for(Int_t i=0; i<nBarsTDC; i++){
      Bar[i]  = (Double_t)(nBarsTDC -1 - i);
      eBar[i] = 0.0;
      Eff[i]  = hth_xmean1->GetBinContent(i);
      eEff[i]  = hth_xmean1->GetBinError(i);
    }
    
    TGraphErrors* gEff = new TGraphErrors( nBarsTDC, Bar, Eff, eBar, eEff );
    gEff->SetMarkerColor( 4 );
    gEff->SetLineColor( 4 );
    gEff->SetMarkerStyle( 20 );
    gEff->SetMarkerSize( 0.8 );
    gEff->Draw("AP");
    gEff->GetYaxis()->SetRangeUser( 0.3, 1.7 );
    gEff->GetXaxis()->SetRangeUser( 0, 85 );
    gEff->GetXaxis()->SetTitle( "Hodoscope Bar ID");
    gEff->GetYaxis()->SetTitle( "Track Match Efficiency");
    gEff->RemovePoint(59);
    
    TF1* meaneff = new TF1("meaneff","pol0", 12., 78.);  
    meaneff->SetLineColor( 4 );
    gEff->Fit(meaneff,"Q","",barlow, barhigh);
    
    tex = new TLatex( 0.35, 0.9, Form("Mean = %3.2f %%",100.* meaneff->GetParameter(0)));
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(4);
    tex->SetTextSize(0.055);
    tex->Draw();
      
    //========================================================= Resolutions

    c2->cd(3)->SetRightMargin(.05);
    
    TF1* gausf = new TF1("gausf","gaus(0)",-0.20, 0.20);
    
    Double_t ulim, dlim;
    Double_t sig1, sig2, esig1, esig2;
    Double_t sigt[nBarsTDC], esigt[nBarsTDC];
    Double_t sigmt[nBarsTDC], esigmt[nBarsTDC];
    Double_t sigmt1[nBarsTDC], esigmt1[nBarsTDC];
    Double_t sigtd[nBarsTDC], esigtd[nBarsTDC];
    Double_t sigx[nBarsTDC], esigx[nBarsTDC];
    Double_t sigy[nBarsTDC], esigy[nBarsTDC];
    
    Double_t BarRed[nBarsTDC];
    Int_t nBars_red = 0;


   for(Int_t i=0; i<nBarsTDC; i++){ 
      
      Bar[i]  = (Double_t)i;

      //===================
      hRest[i] = (TH1D*)hDiffc[i]->ProjectionY(Form("htempt%d",i),0,100);
      
      ulim = hRest[i]->GetMean() + (7*hRest[i]->GetRMS());
      dlim = hRest[i]->GetMean() - (7*hRest[i]->GetRMS()); 
      gausf->SetParameter(1, hRest[i]->GetMean() ); 
      gausf->SetParameter(2,(4*hRest[i]->GetRMS()) ); 
      
      hRest[i]->Fit(gausf,"QN","",dlim, ulim);
      
      sigt[i]  = gausf->GetParameter(2); 
      esigt[i] = gausf->GetParError(2);
      

      //===================
      if( i > barlow && i <barhigh ) {
	
	hRestd[i] = (TH1D*)hDiff[i]->ProjectionY(Form("htemptd%d",i),25,26);
	
	ulim = hRestd[i]->GetMean() + (7*hRestd[i]->GetRMS());
	dlim = hRestd[i]->GetMean() - (7*hRestd[i]->GetRMS()); 
	gausf->SetParameter(1, hRestd[i]->GetMean() ); 
	gausf->SetParameter(2,(4*hRestd[i]->GetRMS()) ); 
	
	hRestd[i]->Fit(gausf,"QN","",dlim, ulim);
	
	sigtd[nBars_red]  = gausf->GetParameter(2); 
	esigtd[nBars_red] = gausf->GetParError(2);

	BarRed[nBars_red]  = (Double_t)i;
      }
	
      //===================
      hResmt[i] = (TH1D*)hMean[i]->ProjectionY(Form("htempmt%d",i),0,100);
      
      ulim = hResmt[i]->GetMean() + (7*hResmt[i]->GetRMS());
      dlim = hResmt[i]->GetMean() - (7*hResmt[i]->GetRMS()); 
      gausf->SetParameter(1, hResmt[i]->GetMean() ); 
      gausf->SetParameter(2,(4*hResmt[i]->GetRMS()) ); 
      
      hResmt[i]->Fit(gausf,"QN","",dlim, ulim);
      
      sigmt[i]  = gausf->GetParameter(2); 
      esigmt[i] = gausf->GetParError(2);

      //===================
      if( i >barlow && i <barhigh ) {

	hResmt1[i] = (TH1D*)hMeanc[i]->ProjectionY(Form("htempmt1%d",i),0,100);
	
	ulim = hResmt1[i]->GetMean() + (7*hResmt1[i]->GetRMS());
	dlim = hResmt1[i]->GetMean() - (7*hResmt1[i]->GetRMS()); 
	gausf->SetParameter(1, hResmt1[i]->GetMean() ); 
	gausf->SetParameter(2,(4*hResmt1[i]->GetRMS()) ); 
	
	hResmt1[i]->Fit(gausf,"QN","",dlim, ulim);
	
	BarRed[nBars_red]  = (Double_t)i;

	sigmt1[nBars_red]  = gausf->GetParameter(2); 
	esigmt1[nBars_red] = gausf->GetParError(2);
	//	if( esigmt1[nBars_red] < 0.01 ) esigmt1[nBars_red] = 2.; 
	nBars_red++;
      }

      //===================
      hResx[i] = (TH1D*)hth2d_xdiff->ProjectionX(Form("htempx%d",i),i,i+1);
      
      ulim = hResx[i]->GetMean() + (7*hResx[i]->GetRMS());
      dlim = hResx[i]->GetMean() - (7*hResx[i]->GetRMS()); 
      gausf->SetParameter(1, hResx[i]->GetMean() ); 
      gausf->SetParameter(2,(4*hResx[i]->GetRMS()) ); 
      
      hResx[i]->Fit(gausf,"Q","",dlim, ulim);
      
      sigx[i]  = gausf->GetParameter(2); 
      esigx[i] = gausf->GetParError(2);
      
      //===================
      hResy[i] = (TH1D*)hth2d_ydiff->ProjectionX(Form("htempy%d",i),i,i+1);
      
      ulim = hResy[i]->GetMean() + (7*hResy[i]->GetRMS());
      dlim = hResy[i]->GetMean() - (7*hResy[i]->GetRMS()); 
      gausf->SetParameter(1, hResy[i]->GetMean() ); 
      gausf->SetParameter(2,(4*hResy[i]->GetRMS()) ); 
      
      hResy[i]->Fit(gausf,"Q","",dlim, ulim);

      sigy[i]  = gausf->GetParameter(2); 
      esigy[i] = gausf->GetParError(2);
    }    

   TGraphErrors* gRest = new TGraphErrors( nBarsTDC, Bar, sigt, eBar, esigt );
   gRest->SetMarkerColor( 1 );
   gRest->SetLineColor( 1 );
   gRest->SetMarkerStyle( 20 );
   gRest->SetMarkerSize( 0.8 );
   gRest->Draw("AP");
   gRest->GetXaxis()->SetTitle( "Hodoscope Bar ID");
   gRest->GetYaxis()->SetTitle( "Bar Time Diff Resolution [ns]");
   gRest->GetYaxis()->SetRangeUser( 0.0, 1.0 );
   gRest->GetXaxis()->SetRangeUser( 0, 85 );
   gRest->RemovePoint(59);
   gRest->RemovePoint(29);

   TF1* meanrest = new TF1("meanrest","pol0", 12., 78.);  
   meanrest->SetLineColor( 1 );
   gRest->Fit(meanrest,"Q","",barlow, barhigh);;
    
   tex = new TLatex( 0.34, 0.9, Form("Mean = %3.1f ps", 1000*meanrest->GetParameter(0)));
   tex->SetNDC(1);
   tex->SetTextFont(42);
   tex->SetTextColor(1);
   tex->SetTextSize(0.055);
   tex->Draw();

   TGraphErrors* gRestd = new TGraphErrors( nBars_red, BarRed, sigtd, eBar, esigtd );
   gRestd->SetMarkerColor( 2 );
   gRestd->SetLineColor( 2 );
   gRestd->SetMarkerStyle( 20 );
   gRestd->SetMarkerSize( 0.8 );
   //gRestd->Draw("AP");
   gRestd->GetXaxis()->SetTitle( "Hodoscope Bar ID");
   gRestd->GetYaxis()->SetTitle( "Bar Mean Time Resolution [ns]");
   gRestd->GetYaxis()->SetRangeUser( 0.0, 1.0 );
   gRestd->GetXaxis()->SetRangeUser( 0, 85 );
   gRestd->RemovePoint(59);
   gRestd->RemovePoint(29);
   //    gRestd->RemovePoint(21);
   
   TF1* meanrestd = new TF1("meanrestd","pol0", 12., 78.);  
   meanrestd->SetLineColor( 2 );
   gRestd->Fit(meanrestd,"QN","",barlow, barhigh);
    
   tex = new TLatex( 0.34, 0.9, Form("Mean = %3.1f ps", 1000*meanrestd->GetParameter(0)));
   tex->SetNDC(2);
   tex->SetTextFont(42);
   tex->SetTextColor(2);
   tex->SetTextSize(0.055);
   //   tex->Draw();

    c2->cd(4)->SetRightMargin(.05);

    TGraphErrors* gResmt = new TGraphErrors( nBarsTDC, Bar, sigmt, eBar, esigmt );
    gResmt->SetMarkerColor( 1 );
    gResmt->SetLineColor( 1 );
    gResmt->SetMarkerStyle( 20 );
    gResmt->SetMarkerSize( 0.8 );
    //    gResmt->Draw("AP");
    gResmt->GetXaxis()->SetTitle( "Hodoscope Bar ID");
    gResmt->GetYaxis()->SetTitle( "Bar Mean Time Resolution [ns]");
    gResmt->GetYaxis()->SetRangeUser( 0.0, 4.0 );
    gResmt->GetXaxis()->SetRangeUser( 0, 85 );
    gResmt->RemovePoint(59);
    gResmt->RemovePoint(29);

    TF1* meanresmt = new TF1("meanresmt","pol0", 12., 78.);  
    meanresmt->SetLineColor( 1 );
    gResmt->Fit(meanresmt,"QN","",barlow, barhigh);
    
    tex = new TLatex( 0.34, 0.9, Form("Mean = %3.1f ps", 1000*meanresmt->GetParameter(0)));
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(1);
    tex->SetTextSize(0.055);
    //    tex->Draw();

    TGraphErrors* gResmt1 = new TGraphErrors( nBars_red, BarRed, sigmt1, eBar, esigmt1 );
    gResmt1->SetMarkerColor( 8 );
    gResmt1->SetLineColor( 8 );
    gResmt1->SetMarkerStyle( 20 );
    gResmt1->SetMarkerSize( 0.8 );
    gResmt1->Draw("AP");
    gResmt1->GetXaxis()->SetTitle( "Hodoscope Bar ID");
    gResmt1->GetYaxis()->SetTitle( "Bar Mean Time Resolution [ns]");
    gResmt1->GetYaxis()->SetRangeUser( 0.0, 1.0 );
    gResmt1->GetXaxis()->SetRangeUser( 0, 85 );


    TF1* meanresmt1 = new TF1("meanresmt1","pol0", 12., 78.);  
    meanresmt1->SetLineColor( 8 );
    gResmt1->Fit(meanresmt1,"Q","",barlow, barhigh);
    
    tex = new TLatex( 0.34, 0.9, Form("Mean = %3.1f ps", 1000*meanresmt1->GetParameter(0)));
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(8);
    tex->SetTextSize(0.055);
    tex->Draw();

    c2->cd(5)->SetRightMargin(.05);
  
    TGraphErrors* gResx = new TGraphErrors( nBarsTDC, Bar, sigx, eBar, esigx );
    gResx->SetMarkerColor( 6 );
    gResx->SetLineColor( 6 );
    gResx->SetMarkerStyle( 20 );
    gResx->SetMarkerSize( 0.8 );
    gResx->Draw("AP");
    gResx->GetXaxis()->SetTitle( "Hodoscope Bar ID");
    gResx->GetYaxis()->SetTitle( "Vertical Position Resolution [m]");
    gResx->GetYaxis()->SetRangeUser( 0.005, 0.03 );
    gResx->GetXaxis()->SetRangeUser( 0, 85 );
    gResx->RemovePoint(59);
    gResx->RemovePoint(29);

    TF1* meanresx = new TF1("meanresx","pol0", 12., 78.);  
    meanresx->SetLineColor( 6 );
    gResx->Fit(meanresx,"Q","",barlow, barhigh);
    
    tex = new TLatex( 0.34, 0.9, Form("Mean = %3.2f cm", 100*meanresx->GetParameter(0)));
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(6);
    tex->SetTextSize(0.055);
    tex->Draw();

    c2->cd(6)->SetRightMargin(.05);
  
    TGraphErrors* gResy = new TGraphErrors( nBarsTDC, Bar, sigy, eBar, esigy );
    gResy->SetMarkerColor( 9 );
    gResy->SetLineColor( 9 );
    gResy->SetMarkerStyle( 20 );
    gResy->SetMarkerSize( 0.8 );
    gResy->Draw("AP");
    gResy->GetXaxis()->SetTitle( "Hodoscope Bar ID");
    gResy->GetYaxis()->SetTitle( "Horizontal Position Resolution [m]");
    gResy->GetYaxis()->SetRangeUser( 0.02, 0.08 );
    gResy->GetXaxis()->SetRangeUser( 0, 85 );
    gResy->RemovePoint(59);
    gResy->RemovePoint(29);

    TF1* meanresy = new TF1("meanresy","pol0", 12., 78.);  
    meanresy->SetLineColor( 9 );
    gResy->Fit(meanresy,"Q","",barlow, barhigh);
    
    tex = new TLatex( 0.34, 0.9, Form("Mean = %3.2f cm", 100*meanresy->GetParameter(0)));
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(9);
    tex->SetTextSize(0.055);
    tex->Draw();
    
    c2->Print("bbhodo_temp2.pdf");
    c2->Print(Form("HodoTime_SBSC-%d.pdf", kin_no1));  
    c2->cd();

    //-----------------------------------------------------------------------------------------------------------------------------

    TCanvas* c223 = new TCanvas("c223","",1200,800);
    c223->Divide(3,2);

    c223->cd(1);

    tex = new TLatex( 0.34, 0.6, Form("SBS-%d", kin_no1 ));
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(1);
    tex->SetTextSize(0.095);
    tex->Draw();

    tex = new TLatex( 0.24, 0.4, Form("Run %d", run_no ));
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(1);
    tex->SetTextSize(0.095);
    tex->Draw();

    c223->cd(2);
    hMean[40]->Draw("colz");
    hMean[40]->GetXaxis()->SetTitle("Bar 1 Mean Time [ns]");
    hMean[40]->GetYaxis()->SetTitle("Bar 2 Mean Time [ns]");

    c223->cd(3);
    hMeanc[40]->Draw("colz");
    hMeanc[40]->GetXaxis()->SetTitle("Bar 1 Mean Time [ns]");
    hMeanc[40]->GetYaxis()->SetTitle("Mean Time (Bar1 - Bar2) [ns]");

    c223->cd(4)->SetLogy(1);

    hResmt1[40]->Draw("");
    hResmt1[40]->SetLineColor(2);
    hResmt[40]->Draw("same");
    hResmt[40]->SetLineColor(1);
    hResmt[40]->GetXaxis()->SetTitle("Bar Mean Time [ns]");
    //    hResmt[40]->GetXaxis()->SetRangeUser( -5, 5 );
    
    //    hRestd[40]->Scale( hRest[40]->GetMaximum()/hRestd[40]->GetMaximum());
    //    hRestd[40]->Sumw2(0);

    c223->cd(5);
    gResmt->Draw("AP");
    meanresmt->Draw("same" );

    tex = new TLatex( 0.34, 0.9, Form("Mean = %3.1f ps", 1000*meanresmt->GetParameter(0)));
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(1);
    tex->SetTextSize(0.055);
    tex->Draw();

    c223->cd(6);
    gResmt1->GetXaxis()->SetTitle( "Hodoscope Bar ID");
    gResmt1->GetYaxis()->SetTitle( "Bar Mean Time Resolution [ns]");
    gResmt1->Draw("AP");
    gResmt1->GetYaxis()->SetRangeUser( 0.0, 4.0 );

    meanresmt1->Draw("same" );
    gResmt1->SetMarkerColor( 2 );
    gResmt1->SetLineColor( 2 );
    meanresmt1->SetLineColor( 2 );

    
    tex = new TLatex( 0.34, 0.9, Form("Mean = %3.1f ps", 1000*meanresmt1->GetParameter(0)));
    tex->SetNDC(2);
    tex->SetTextFont(42);
    tex->SetTextColor(2);
    tex->SetTextSize(0.055);
    tex->Draw();

    c223->Print(Form("HodoTime_SBSA-%d.pdf", kin_no1));  
    c223->cd();

    //-----------------------------------------------------------------------------------------------------------------------------

    TCanvas* c222 = new TCanvas("c222","",1200,800);
    c222->Divide(3,2);

    c222->cd(1);

    tex = new TLatex( 0.34, 0.6, Form("SBS-%d", kin_no1 ));
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(1);
    tex->SetTextSize(0.095);
    tex->Draw();

    tex = new TLatex( 0.24, 0.4, Form("Run %d", run_no ));
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(1);
    tex->SetTextSize(0.095);
    tex->Draw();

    c222->cd(2);
    hDiffc[40]->Draw("colz");
    hDiffc[40]->GetXaxis()->SetTitle("y_{FP} [m]");
    hDiffc[40]->GetYaxis()->SetTitle("Corrected Bar Time Diff [ns]");

    c222->cd(3);
    hDiff[40]->Draw("colz");
    hDiff[40]->GetXaxis()->SetTitle("y_{FP} [m]");
    hDiff[40]->GetYaxis()->SetTitle("Bar Time Diff [ns]");

    TLine *line11 = new TLine(-0.01,-7,-0.01,7); 
    line11->SetLineColor(2); 
    line11->SetLineStyle(2); 
    line11->Draw(); 

    TLine *line22 = new TLine(0.01,-7,0.01,7); 
    line22->SetLineColor(2); 
    line22->SetLineStyle(2); 
    line22->Draw(); 

    c222->cd(4)->SetLogy(1);

    hRest[40]->Draw("");
    hRest[40]->SetLineColor(1);
    hRest[40]->GetXaxis()->SetTitle("Bar Time Diff [ns]");
    hRest[40]->GetXaxis()->SetRangeUser( -5, 5 );
    
    hRestd[40]->Draw("same");
    hRestd[40]->SetLineColor(2);
    //    hRestd[40]->Scale( hRest[40]->GetMaximum()/hRestd[40]->GetMaximum());
    //    hRestd[40]->Sumw2(0);

    c222->cd(5);
    gRest->Draw("AP");
    meanrest->Draw("same" );

    tex = new TLatex( 0.34, 0.9, Form("Mean = %3.1f ps", 1000*meanrest->GetParameter(0)));
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(1);
    tex->SetTextSize(0.055);
    tex->Draw();

    c222->cd(6);
    gRestd->GetXaxis()->SetTitle( "Hodoscope Bar ID");
    gRestd->GetYaxis()->SetTitle( "Bar Time Diff Resolution [ns]");
    gRestd->Draw("AP");
    gRestd->GetYaxis()->SetRangeUser( 0.1, 1.0 );

    meanrestd->Draw("same" );
    
    tex = new TLatex( 0.34, 0.9, Form("Mean = %3.1f ps", 1000*meanrestd->GetParameter(0)));
    tex->SetNDC(2);
    tex->SetTextFont(42);
    tex->SetTextColor(2);
    tex->SetTextSize(0.055);
    tex->Draw();
    
    c222->Print("bbhodo_temp222.pdf");
    c222->Print(Form("HodoTime_SBSB-%d.pdf", kin_no1));  
    c222->cd();
    
  }  

  //-----------------------------------------------------------------------------------------------------------------------------
  // Pre-shower and Shower correlation plots
  //-----------------------------------------------------------------------------------------------------------------------------

  if( PlotBBCal ) {

    TCanvas* c3 = new TCanvas("c3","",1200,800);
    c3->Divide(4,2);
    c3->cd(1)->SetLogy(1);
    hbbcal_psE->Draw("");
    if( kin_no != 4 ) 
      hbbcal_psE->GetYaxis()->SetRangeUser(1,6e5);
    hbbcal_psEc->SetLineColor(2);
    hbbcal_psEc->Draw("same");
    hbbcal_psE->GetXaxis()->SetTitle("BBCal PS Energy [GeV]");

    tex = new TLatex( 0.48, 0.8, "All tracks");
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(4);
    tex->SetTextSize(0.055);
    tex->Draw();
    
    tex = new TLatex( 0.48, 0.72, "After cuts");
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(2);
    tex->SetTextSize(0.055);
    tex->Draw();

    c3->cd(2)->SetLogy(1);
    hbbcal_shE->Draw("");
    hbbcal_shEc->SetLineColor(2);
    hbbcal_shEc->Draw("same");
    hbbcal_shE->GetXaxis()->SetTitle("BBCal Shower Energy [GeV]");

    c3->cd(3)->SetLogy(1);
    hbbcal_cale->Draw();
    hbbcal_calec->SetLineColor(2);
    hbbcal_calec->Draw("same");
    hbbcal_cale->GetXaxis()->SetTitle("E_{bbcal} [GeV]");

    c3->cd(4);
    hbbcal2d_pss->Draw("colz");
    hbbcal2d_pss->GetXaxis()->SetTitle("E_{SH}/p_{bbtrack}");
    hbbcal2d_pss->GetYaxis()->SetTitle("E_{PS}/p_{bbtrack}");
    TLine *line1 = new TLine(0,sh_min,sh_min/sh_e,0); 
    line1->SetLineColor(2); 
    line1->SetLineWidth(2); 
    line1->Draw(); 
    TLine *line3 = new TLine(0,sh_max,sh_max/sh_e,0); 
    line3->SetLineColor(2); 
    line3->SetLineWidth(2); 
    line3->Draw(); 
    TLine *line2 = new TLine(0,ps_min,1.2,ps_min); 
    line2->SetLineColor(2); 
    line2->SetLineWidth(2); 
    line2->Draw(); 

    c3->cd(8);
    hbbcal2d_pssc->Draw("colz");
    hbbcal2d_pssc->GetXaxis()->SetTitle("E_{SH}/p_{bbtrack}");
    hbbcal2d_pssc->GetYaxis()->SetTitle("E_{PS}/p_{bbtrack}");

    c3->cd(5)->SetLogy(1);
    hbbcal_edivp->Draw();
    if( kin_no != 4 ) 
      hbbcal_edivp->GetYaxis()->SetRangeUser(1,2e5);
    hbbcal_edivpc->SetLineColor(2);
    hbbcal_edivpc->Draw("same");
    TF1* gausfedp = new TF1("gausfedp","gaus(0)",-1.00, 1.00);
    gausfedp->SetLineColor(1);
    hbbcal_edivpc->Fit(gausfedp,"Q");
    hbbcal_edivp->GetXaxis()->SetTitle("(E_{bbcal} - p_{bbtrack}) [GeV]");

    tex = new TLatex( 0.54, 0.9, Form("#sigma = %3.2f %%", 
				      100.*TMath::Sqrt( (gausfedp->GetParameter(2)/pcent) * 
							(gausfedp->GetParameter(2)/pcent) - pres*pres ) ) );
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(2);
    tex->SetTextSize(0.055);
    tex->Draw();

    c3->cd(6)->SetLogy(1);
    
    TF1* gausf = new TF1("gausf","gaus(0)",-0.20, 0.20);
    hbbcal_xdiff->Draw("");
    gausf->SetLineColor(1);
    hbbcal_xdiffc->SetLineColor(2);
    hbbcal_xdiffc->Draw("same");
    hbbcal_xdiff->GetXaxis()->SetTitle("#delta x_{FP} (GEM-BBSH) [m]");

    TF1* gausfc = new TF1("gausfc","gaus(0)",-0.20, 0.20);
    gausfc->SetLineColor(1);
    hbbcal_xdiffc->Fit(gausfc,"Q");

    tex = new TLatex( 0.54, 0.9, Form("#sigma = %2.1f cm", 100.*gausfc->GetParameter(2)));
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(2);
    tex->SetTextSize(0.055);
    tex->Draw();


    c3->cd(7)->SetLogy(1);

    hbbcal_ydiff->Draw("");
    //    hbbcal_xdiff->Fit(gausf,"Q");
    hbbcal_ydiffc->SetLineColor(2);
    hbbcal_ydiffc->Draw("same");
    gausfc->SetLineColor(1);
    hbbcal_ydiffc->Fit(gausfc,"Q");
    hbbcal_ydiff->GetXaxis()->SetTitle("#delta y_{FP} (GEM-BBSH) [m]");

    tex = new TLatex( 0.54, 0.9, Form("#sigma = %2.1f cm", 100.*gausfc->GetParameter(2)));
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(2);
    tex->SetTextSize(0.055);
    tex->Draw();

    c3->Print("kinematics_1.pdf");
    c3->Print("bbhodo_temp3.pdf");
    //c3->cd();
  }

  //-----------------------------------------------------------------------------------------------------------------------------
  // Kinematic plots
  //-----------------------------------------------------------------------------------------------------------------------------

  if( PlotKine ) {

    TCanvas* c4 = new TCanvas("c4","",1200,800);
    c4->Divide(4,2);

    c4->cd(1);
    hkin_p->Draw();
    hkin_p->GetXaxis()->SetTitle("p_{bbtrack} [GeV/c]");

    tex = new TLatex( 0.45, 0.8, "All tracks");
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(4);
    tex->SetTextSize(0.05);
    tex->Draw();

    tex = new TLatex( 0.45, 0.75, "(E_{ps} > 0.05 GeV)");
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(4);
    tex->SetTextSize(0.05);
    tex->Draw();

    c4->cd(2);
    hkin_th->Draw();
    hkin_th->GetXaxis()->SetTitle("#theta_tgt_{bbtrack} [rad]");

    c4->cd(3);
    hkin_ph->Draw();
    hkin_ph->GetXaxis()->SetTitle("#phi_tgt_{bbtrack} [rad]");

    c4->cd(4);
    hkin_yt->Draw();
    hkin_yt->GetXaxis()->SetTitle("y_tgt_{bbtrack} [m]");

    c4->cd(5);
    hkin2d_thp->Draw("colz");
    hkin2d_thp->GetXaxis()->SetTitle("#theta_{bblab} [degrees]");
    hkin2d_thp->GetYaxis()->SetTitle("p_{bbtrack} [GeV/c]");

    c4->cd(6);
    hhcal_deltaxy->Draw("colz");
    hhcal_deltaxy->GetXaxis()->SetTitle("HCal (Meas - Pred) y[m]");
    hhcal_deltaxy->GetYaxis()->SetTitle("HCal (Meas - Pred) x[m]");
    
    c4->cd(7);
    hkin_W->Draw();
    hkin_W->GetXaxis()->SetTitle("W^{2} [GeV^{2}]");
    
    c4->cd(8);
    hkin_pdiff->Draw();
    hkin_pdiff->GetXaxis()->SetTitle("p_{bbtrack} - p_{#theta exp} [GeV/c]");

    c4->Print("bbhodo_temp4.pdf");
    c4->Print("kinematics_2.pdf");
    //c4->cd();
    
    TCanvas* c5 = new TCanvas("c5","",1200,800);
    c5->Divide(4,2);

    c5->cd(1);
    hkin_pc->Draw();
    hkin_pc->SetLineColor(2);
    hkin_pc->GetXaxis()->SetTitle("p_{bbtrack} [GeV/c]");

    tex = new TLatex( 0.58, 0.8, "After cuts");
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(2);
    tex->SetTextSize(0.05);
    tex->Draw();

    c5->cd(2);
    hkin_thc->Draw();
    hkin_thc->SetLineColor(2);
    hkin_thc->GetXaxis()->SetTitle("#theta_tgt_{bbtrack} [rad]");

    c5->cd(3);
    hkin_phc->Draw();
    hkin_phc->SetLineColor(2);
    hkin_phc->GetXaxis()->SetTitle("#phi_tgt_{bbtrack} [rad]");

    c5->cd(4);
    hkin_ytc->Draw();
    hkin_ytc->SetLineColor(2);
    hkin_ytc->GetXaxis()->SetTitle("y_tgt_{bbtrack} [m]");

    c5->cd(5);
    hkin2d_thpc->Draw("colz");
    hkin2d_thpc->GetXaxis()->SetTitle("#theta_{bblab} [degrees]");
    hkin2d_thpc->GetYaxis()->SetTitle("p_{bbtrack} [GeV/c]");

    cout << hkin2d_thpc->GetMean(1) << "\t" << hkin2d_thpc->GetMean(2) << endl;
    
    c5->cd(6);
    hkin_deltaxyc->Draw("colz");
    hkin_deltaxyc->GetXaxis()->SetTitle("Hcal (Pred - Meas) y[m]");
    hkin_deltaxyc->GetYaxis()->SetTitle("Hcal (Pred - Meas) x[m]");
    
    c5->cd(7);
    hkin_Wc->Draw();
    hkin_Wc->SetLineColor(2);
    hkin_Wc->GetXaxis()->SetTitle("W^{2} [GeV^{2}]");

    
    c5->cd(8);
    hkin_pdiffc->Draw();
    hkin_pdiffc->SetLineColor(2);
    hkin_pdiffc->GetXaxis()->SetTitle("p_{bbtrack} - p_{#theta exp} [GeV/c]");

    if( DoFit ) {

      Float_t binwidth = hkin_pdiffc->GetXaxis()->GetBinWidth(1); 
      
      //this method works when the peak is clear and higher than the bg
      int maxbin = hkin_pdiffc->GetMaximumBin();
      float a = hkin_pdiffc->GetMaximum();
      float b = hkin_pdiffc->GetBinCenter(maxbin);

      //need this method when the peak is less clear (high Q2 kinematics)
      //float b = 0;
      //float maxbin = hkin_pdiffc->FindBin(0);
      //float a = hkin_pdiffc->GetBinContent(maxbin);
      
      float pmean    = b;
      float pwidth   = 0.05;

      float pmin   = pmean - 3*pwidth;    // peak minimum 
      float pmax   = pmean + 3*pwidth;    // peak maximum 
      
      float cmin   = -0.3;    // fit minimum 
      float cmax   = 0.3;    // fit maximum 

      int pbmin   = hkin_pdiffc->FindBin( pmin ); 
      int pbmax   = hkin_pdiffc->FindBin( pmax ); 
      int pbrange = pbmax - pbmin; 
      float pbins[pbrange], perr[pbrange]; 
      for( int i = pbmin; i < pbmax; i++) { 
	pbins[i - pbmin] = hkin_pdiffc->GetBinContent( i ); 
	perr[i - pbmin]  = hkin_pdiffc->GetBinError( i ); 
	hkin_pdiffc->SetBinContent( i, 0 ); 
	hkin_pdiffc->SetBinError( i, 0 ); 
      } 
      
      TF1* bg = new TF1("back", "pol1(0)", cmin, cmax);     // 1-D root function 
      hkin_pdiffc->Fit("back","Q","",cmin,cmax); 
      
      float abg = bg->Eval(b);
      float par0 = bg->GetParameter(0); 
      float par1 = bg->GetParameter(1); 
      //float par2 = bg->GetParameter(2); 
      //float par3 = bg->GetParameter(3); 
      
      bg->SetLineWidth(2); 
      bg->SetLineColor(4); 
      
      for( int i = pbmin; i < pbmax; i++) { 
	hkin_pdiffc->SetBinContent( i, pbins[i - pbmin] ); 
	hkin_pdiffc->SetBinError( i, perr[i - pbmin] ); 
      } 
      
      TF1* peakbg = new TF1("peakbg", "pol1(0)+gaus(4)", cmin, cmax); 
      peakbg->FixParameter( 0, par0   ); 
      peakbg->FixParameter( 1, par1   ); 
      //peakbg->FixParameter( 2, par2   ); 
      //peakbg->FixParameter( 3, par3   ); 
      peakbg->FixParameter( 4, a-abg);
      peakbg->FixParameter( 5, b); 
      peakbg->SetParameter( 6, pwidth );    
      peakbg->SetLineWidth(2); 
      peakbg->SetLineColor(1); 
      hkin_pdiffc->Fit("peakbg","Q","",cmin,cmax); 
      peakbg->Draw("same"); 
      bg->Draw("same"); 
      
      float chi2              = peakbg->GetChisquare(); 
      float NDF               = peakbg->GetNDF(); 
      float fitted_mean       = peakbg->GetParameter(5); 
      float fitted_mean_err   = peakbg->GetParError(5); 
      float fitted_sigma      = peakbg->GetParameter(6); 
      float fitted_sigma_err  = peakbg->GetParError(6); 
      
      float integral     = (peakbg->Integral(cmin, cmax) - bg->Integral(cmin,cmax)) / binwidth; 
      float integral_err = TMath::Sqrt( integral ); 
      
      if( kin_no == 4)
	tex = new TLatex( 0.43, 0.9, Form("R_{elastic} = %3.1fk /uAh", (0.001*integral/(runtime*avI/3600))));
      else 
	tex = new TLatex( 0.43, 0.9, Form("R_{elastic} = %3.1f /uAh", (integral/(runtime*avI/3600))));
     
      tex->SetNDC(1);
      tex->SetTextFont(42);
      tex->SetTextColor(1);
      tex->SetTextSize(0.05);
      tex->Draw();
      
      tex = new TLatex( 0.43, 0.83, Form("#sigma = %3.2f %%", 100*(fitted_sigma/pcent)));
      tex->SetNDC(1);
      tex->SetTextFont(42);
      tex->SetTextColor(1);
      tex->SetTextSize(0.05);
      tex->Draw();

    }

    c5->Print("bbhodo_temp5.pdf");
    c5->Print("kinematics_3.pdf");
    //c5->Print("kinematics_aftercuts.C");
    //c5->cd();
  }

  //-----------------------------------------------------------------------------------------------------------------------------
  // Optics plots
  //-----------------------------------------------------------------------------------------------------------------------------

  if( PlotOptics ) {

    TCanvas* c6 = new TCanvas("c6","",1200,800);
    c6->Divide(4,2);

    TF1 *f11 = new TF1("f11","[0]+[1]*x",-0.4,0.4);
    f11->SetLineColor(kRed);    

    TF1 *f110 = new TF1("f110","[0]+[1]*x",-7.0,7.0);

    hMeansht4[40]->Fit( f110, "","",-7, 7);

    TF1 *f12 = new TF1("f12","[0]+[1]*x",-0.15,0.15);
    f12->SetLineColor(kRed);    

    c6->cd(1);
    hopt_x_pd->Draw("colz");
    hopt_x_pd->GetXaxis()->SetTitle("x_FP [m]");
    hopt_x_pd->GetYaxis()->SetTitle("p_{bbtrack} - p_{#theta exp} [GeV/c]");
    hopt_x_pd->Fit(f11,"Q");
    
    c6->cd(2);
    hopt_xp_pd->Draw("colz");
    hopt_xp_pd->GetXaxis()->SetTitle("xp_FP [rad]");
    hopt_xp_pd->GetYaxis()->SetTitle("p_{bbtrack} - p_{#theta exp} [GeV/c]");

    c6->cd(3);
    hopt_y_pd->Draw("colz");
    hopt_y_pd->GetXaxis()->SetTitle("y_FP [m]");
    hopt_y_pd->GetYaxis()->SetTitle("p_{bbtrack} - p_{#theta exp} [GeV/c]");
    hopt_y_pd->Fit(f11,"Q");

    c6->cd(4);
    hopt_yp_pd->Draw("colz");
    hopt_yp_pd->GetXaxis()->SetTitle("yp_FP [rad]");
    hopt_yp_pd->GetYaxis()->SetTitle("p_{bbtrack} - p_{#theta exp} [GeV/c]");

    c6->cd(5);
    hopt_p_pd->Draw("colz");
    hopt_p_pd->GetXaxis()->SetTitle("p_{bbtrack} [GeV/c]");
    hopt_p_pd->GetYaxis()->SetTitle("p_{bbtrack} - p_{#theta exp} [GeV/c]");

    c6->cd(6);
    hopt_th_pd->Draw("colz");
    hopt_th_pd->GetXaxis()->SetTitle("#theta_tgt [rad]");
    hopt_th_pd->GetYaxis()->SetTitle("p_{bbtrack} - p_{#theta exp} [GeV/c]");

    c6->cd(7);
    hopt_yt_pd->Draw("colz");
    hopt_yt_pd->GetXaxis()->SetTitle("y_tgt [m]");
    hopt_yt_pd->GetYaxis()->SetTitle("p_{bbtrack} - p_{#theta exp} [GeV/c]");

    c6->cd(8);
    hopt_ph_pd->Draw("colz");
    hopt_ph_pd->GetXaxis()->SetTitle("#phi_tgt [rad]");
    hopt_ph_pd->GetYaxis()->SetTitle("p_{bbtrack} - p_{#theta exp} [GeV/c]");

    c6->Print("bbhodo_temp6.pdf");
    //c6->Print("kinematics_4.pdf");
    c6->cd();
    
    TCanvas* c7 = new TCanvas("c7","",1200,800);
    c7->Divide(4,2);

    c7->cd(1);
    hopt_x_pc->Draw("colz");
    hopt_x_pc->GetXaxis()->SetTitle("x_FP [m]");
    hopt_x_pc->GetYaxis()->SetTitle("p_{bbtrack} [GeV/c]");

    c7->cd(2);
    hopt_xp_pc->Draw("colz");
    hopt_xp_pc->GetXaxis()->SetTitle("xp_FP [rad]");
    hopt_xp_pc->GetYaxis()->SetTitle("p_{bbtrack} [GeV/c]");

    c7->cd(3);
    hopt_y_pc->Draw("colz");
    hopt_y_pc->GetXaxis()->SetTitle("y_FP [m]");
    hopt_y_pc->GetYaxis()->SetTitle("p_{bbtrack} [GeV/c]");

    c7->cd(4);
    hopt_yp_pc->Draw("colz");
    hopt_yp_pc->GetXaxis()->SetTitle("yp_FP [rad]");
    hopt_yp_pc->GetYaxis()->SetTitle("p_{bbtrack} [GeV/c]");

    c7->cd(5);
    hopt_p_pc->Draw("colz");
    hopt_p_pc->GetXaxis()->SetTitle("p_{bbtrack} [GeV/c]");
    hopt_p_pc->GetYaxis()->SetTitle("p_{bbtrack} [GeV/c]");

    c7->cd(6);
    hopt_th_pc->Draw("colz");
    hopt_th_pc->GetXaxis()->SetTitle("#theta_tgt [rad]");
    hopt_th_pc->GetYaxis()->SetTitle("p_{bbtrack} [GeV/c]");

    c7->cd(7);
    hopt_yt_pc->Draw("colz");
    hopt_yt_pc->GetXaxis()->SetTitle("y_tgt [m]");
    hopt_yt_pc->GetYaxis()->SetTitle("p_{bbtrack} [GeV/c]");

    c7->cd(8);
    hopt_ph_pc->Draw("colz");
    hopt_ph_pc->GetXaxis()->SetTitle("#phi_tgt [rad]");
    hopt_ph_pc->GetYaxis()->SetTitle("p_{bbtrack} [GeV/c]");

    c7->Print("bbhodo_temp7.pdf");
    c7->cd();
  }

  
  //-----------------------------------------------------------------------------------------------------------------------------
  // HCal plots
  //-----------------------------------------------------------------------------------------------------------------------------

  if( PlotHCal ) {

    TCanvas* c8 = new TCanvas("c8","",1200,800);
    c8->Divide(4,3);
    c8->cd(1)->SetLogy(1);
    hhcal_x->Draw("");
    hhcal_x->GetXaxis()->SetTitle("HCal x[m]");
    hhcal_xc->SetLineColor(2);
    hhcal_xc->Draw("same");
    hhcal_x->GetYaxis()->SetRangeUser(1,1.2*hhcal_x->GetMaximum());
    
    tex = new TLatex( 0.48, 0.8, "All BB tracks");
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(4);
    tex->SetTextSize(0.055);
    tex->Draw();
    
    tex = new TLatex( 0.48, 0.72, "After elastics cuts");
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(2);
    tex->SetTextSize(0.055);
    tex->Draw();

    c8->cd(2)->SetLogy(1);
    hhcal_y->Draw("");
    hhcal_y->GetXaxis()->SetTitle("HCal y[m]");
    hhcal_yc->SetLineColor(2);
    hhcal_yc->Draw("same");
    hhcal_y->GetYaxis()->SetRangeUser(1,1.2*hhcal_y->GetMaximum());
    
    c8->cd(3);
    hhcal_xy->Draw("colz");
    hhcal_xy->GetXaxis()->SetTitle("HCal y[m]");
    hhcal_xy->GetYaxis()->SetTitle("HCal x[m]");
    
    c8->cd(4);
    hhcal_xyc->Draw("colz");
    hhcal_xyc->GetXaxis()->SetTitle("HCal y[m]");
    hhcal_xyc->GetYaxis()->SetTitle("HCal x[m]");
    
    c8->cd(5)->SetLogy(1);
    hhcal_predx->Draw("");
    hhcal_predx->GetXaxis()->SetTitle("HCal predicted x[m]");
    hhcal_predxc->SetLineColor(2);
    hhcal_predxc->Draw("same");
    
    c8->cd(6)->SetLogy(1);
    hhcal_predy->Draw("");
    hhcal_predy->GetXaxis()->SetTitle("HCal predicted y[m]");
    hhcal_predyc->SetLineColor(2);
    hhcal_predyc->Draw("same");
    
    c8->cd(7);
    hhcal_predxy->Draw("colz");
    hhcal_predxy->GetXaxis()->SetTitle("HCal Pred y[m]");
    hhcal_predxy->GetYaxis()->SetTitle("HCal Pred x[m]");

    c8->cd(8);
    hhcal_predxyc->Draw("colz");
    hhcal_predxyc->GetXaxis()->SetTitle("HCal Pred y[m]");
    hhcal_predxyc->GetYaxis()->SetTitle("HCal Pred x[m]");
   
    c8->cd(9)->SetLogy(1);
    hhcal_deltax->Draw("");
    hhcal_deltax->GetXaxis()->SetTitle("HCal (Meas - Predicted) x[m]");
    hhcal_deltaxc->SetLineColor(2);
    hhcal_deltaxc->Draw("same");
    
    c8->cd(10)->SetLogy(1);
    hhcal_deltay->Draw("");
    hhcal_deltay->GetXaxis()->SetTitle("HCal (Meas - Pred) y[m]");
    hhcal_deltayc->SetLineColor(2);
    hhcal_deltayc->Draw("same");
    
    c8->cd(11);
    hhcal_deltaxy->Draw("colz");
    hhcal_deltaxy->GetXaxis()->SetTitle("HCal (Meas - Pred) y[m]");
    hhcal_deltaxy->GetYaxis()->SetTitle("HCal (Meas - Pred) x[m]");
    
    c8->cd(12);
    hhcal_deltaxyc->Draw("colz");
    hhcal_deltaxyc->GetXaxis()->SetTitle("HCal (Meas - Pred) y[m]");
    hhcal_deltaxyc->GetYaxis()->SetTitle("HCal (Meas - Pred) x[m]");
    
    c8->Print("kinematics_5.pdf");
    c8->Print("bbhodo_temp8.pdf");
    //c8->cd();
  
    
    TCanvas *c9 = new TCanvas("c9","",1200,800);
    c9->Divide(2,1);
    c9->cd(1);
    hhcal_deltax->Draw("");
    hhcal_deltax->GetXaxis()->SetTitle("HCal (Meas - Pred) x[m]");
    hhcal_deltaxc->SetLineColor(2);
    hhcal_deltaxc->Draw("same");
    
    c9->cd(2);
    hhcal_deltaxc->GetXaxis()->SetTitle("HCal (Meas - Pred) x[m]");
    hhcal_deltaxc->SetLineColor(2);
    hhcal_deltaxc->Draw("");
    
    //delta_x fit
    float binwidth = hhcal_deltaxc->GetXaxis()->GetBinWidth(1); 
    int maxbin = hhcal_deltaxc->GetMaximumBin();

    float a = hhcal_deltaxc->GetMaximum();
    float b = hhcal_deltaxc->GetBinCenter(maxbin);
    
    float pmean    = b;
    float pwidth   = 0.12;
    
    float pmin   = pmean - 3*pwidth;    // peak minimum 
    float pmax   = pmean + 3*pwidth;    // peak maximum 
    
    float cmin   = -1.15;    // fit minimum 
    float cmax   = -0.15;    // fit maximum 
    //float cmin = -2.5;
    //float cmax = 2.5;
    
    int pbmin   = hhcal_deltaxc->FindBin( pmin ); 
    int pbmax   = hhcal_deltaxc->FindBin( pmax ); 
    
    int pbrange = pbmax - pbmin; 
    float pbins[pbrange], perr[pbrange];
    
    
    for( int i = pbmin; i < pbmax; i++) { 
      pbins[i - pbmin] = hhcal_deltaxc->GetBinContent( i ); 
      perr[i - pbmin]  = hhcal_deltaxc->GetBinError( i ); 
      hhcal_deltaxc->SetBinContent( i, 0 ); 
      hhcal_deltaxc->SetBinError( i, 0 ); 
    } 
    
    TF1* bg = new TF1("bg","gaus(0)",-2.5,2.5);
    //TF1* bg = new TF1("bg","pol2(0)",-2.5,2.5);
    bg->SetLineColor(kBlue);
    hhcal_deltaxc->Fit("bg","Q","",-2.5,2.5);
    
    double par0 = bg->GetParameter(0);
    double par1 = bg->GetParameter(1);
    double par2 = bg->GetParameter(2);
    //double par3 = bg->GetParameter(3);
    
    TFormula* bgform = bg->GetFormula();
    double abg = bgform->Eval(b);
    
    for( int i = pbmin; i < pbmax; i++) { 
      hhcal_deltaxc->SetBinContent( i, pbins[i - pbmin] ); 
      hhcal_deltaxc->SetBinError( i, perr[i - pbmin] ); 
    } 
    
    //TF1* peakbg = new TF1("peakbg","pol2(0)+gaus(4)",cmin,cmax);
    TF1* peakbg = new TF1("peakbg","gaus(0)+gaus(4)",cmin,cmax);
    peakbg->SetLineColor(kRed);
    
    peakbg->FixParameter(0,par0);
    peakbg->FixParameter(1,par1);
    peakbg->FixParameter(2,par2);
    //peakbg->FixParameter(3,par3);
    peakbg->FixParameter(4,a-abg);
    peakbg->FixParameter(5,b);
    peakbg->SetParameter(6,pwidth);
    
    hhcal_deltaxc->Fit("peakbg","Q","",cmin,cmax);
    bg->Draw("same");
    peakbg->Draw("same");
    
    float fitted_sigma      = peakbg->GetParameter(6); 
    float fitted_sigma_err  = peakbg->GetParError(6); 
    
    float integral = (peakbg->Integral(cmin,cmax) - bg->Integral(cmin,cmax)) / binwidth;
    
    if( kin_no == 4)
      tex = new TLatex( 0.45, 0.9, Form("R_{elastic} = %3.1fk /uAh", (0.001*integral/(runtime*avI/3600))));
    else 
      tex = new TLatex( 0.45, 0.9, Form("R_{elastic} = %3.1f /uAh", (integral/(runtime*avI/3600))));
    
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(1);
    tex->SetTextSize(0.05);
    tex->Draw();
      
    tex = new TLatex( 0.45, 0.83, Form("#sigma = %3.2f m",fitted_sigma));
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(1);
    tex->SetTextSize(0.05);
    tex->Draw();
    
    c9->Print("kinematics_6.pdf");
    //c9->cd();
  }

  if( PlotfADC ) {
    
    TCanvas* c66 = new TCanvas("c66","",1200,800);
    c66->Divide(3,2);  
    c66->cd(1);
    hth2d_fadcl1->Draw("colz");
    c66->cd(2);
    hth2d_fadcr1->Draw("colz");
    c66->cd(4);
    hth2d_fadcl2->Draw("colz");
    c66->cd(5);
    hth2d_fadcr2->Draw("colz");
    c66->cd(3)->SetLogy();
    hth_fadcl1->Draw("");
    hth_fadcl2->SetLineColor(2);
    c66->cd(6);
    hth_fadcl2->SetLineColor(2);
    hth_fadcl2->Draw("");

    c66->Print("bbhodo_temp66.pdf");
    c66->cd();
  } 

  //gSystem->Exec(Form("pdfunite  bbhodo_temp*.pdf fullanalysis_SBS-%d.pdf", kin_no));  

  gSystem->Exec(Form("pdfunite  kinem*.pdf Heep_SBS-%d.pdf", kin_no));  
  gSystem->Exec("rm  kinema*.pdf");  
  gSystem->Exec(Form("pdfunite  bbhodo*.pdf PlotHodo_SBS-%d.pdf", kin_no));  
  gSystem->Exec(Form("pdfunite  HodoTime*.pdf BBHodoTime_SBS-%d.pdf", kin_no));  
  gSystem->Exec("rm  HodoTime*.pdf");  
  gSystem->Exec("rm  bbhodo_temp*.pdf");  
  
  cout <<"Saving rootfiles" << endl;
  outfile->cd();
  outfile->Write();
  outfile->Close();
  t.Stop();
  cout << "Total Time: ";
  t.Print();
  cout << " s" << endl;
}//End of macro
  
