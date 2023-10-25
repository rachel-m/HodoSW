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

#include <TTreeReader.h>
#include <TTreeReaderArray.h>

#include "TMVA/Tools.h"
#include "TMVA/Factory.h"
#include "TMVA/DataLoader.h"
#include "TMVA/Reader.h"
#include "TMVA/TMVARegGui.h"

//using namespace TMVA;
using namespace std;

//Correlation methods
const Bool_t   MVA_method = false; //mlp neural network
const Bool_t   JW_method = false; //john williamson, fit 4 variables independent
const Bool_t   GP_method = true; //gary penman, fit 4 variables dependent

const TString outfilename = "PL_Histos.root";

//global array for fit params
double fp_pars[8] = {0};
double tg_pars[8] = {0};
double fp_iter_pars[8] = {0};
double tg_iter_pars[8] = {0};

void RunPL(const TString Exp = "GEN", const Int_t kin_no = 2, const TString Target = "H2", int iter=0){
  //Exp  = GEN or GMN
  //kin_no = 1,2,4,5 for GEN, 4,7,8,9,11,14 for GMN
  //Target = H2 for 10bar H2 reference cell data
  //Target = He3 for 10bar polarised He3 production cell data.
  //Target = LD2 or LH2 for GMN (not hard coded stuff r.e. this yet)
  
  cout << "Iteration: " << iter << endl;
  cout << fp_pars[0] << " " <<  fp_pars[1] << " " << fp_pars[2] << " " << fp_pars[3] << " " << fp_pars[4] << " " << fp_pars[5] << " " << fp_pars[6] << " " << fp_pars[7] << " " << endl;
     
  //stopwatch for benchmarking analysis time on large dataset
  TStopwatch t;
  t.Start();
  
  //SET ROOTFILE DIRECTORY
  TString Rootfile_Dir, Base_Dir, Pass_Dir;

  Rootfile_Dir = "/w/work5/home/garyp/sbs/rootfiles/GEn/hodocalib/GEMcalib/";
  
  TChain* C = new TChain("T");
  C->Add(Rootfile_Dir + "*.root");
  
  TFile *outfile = new TFile(outfilename,"RECREATE");
  
  TTreeReader rd (C);
  TTreeReaderArray<Double_t> *bb_tr_x, *bb_tr_y, 
    *bb_tr_px, *bb_tr_py, *bb_tr_pz, 
    *bb_tr_p, *bb_tr_th, *bb_tr_ph, 
    *bb_tr_vx, *bb_tr_vy, *bb_tr_vz;
  
  TTreeReaderArray<Double_t> *bb_tr_tg_th, *bb_tr_tg_ph, *bb_tr_tg_y;
  
  TTreeReaderValue<Double_t> *bb_ps_e, *bb_sh_e;
  
  TTreeReaderValue<Double_t> *sbs_hcal_x, *sbs_hcal_y, *sbs_hcal_e, *sbs_hcal_nclus;
  
  TTreeReaderValue<Double_t> *bb_tr_n;

  TTreeReaderArray<Double_t> *bb_hodotdc_clus_bar_tdc_meantime;
  bb_hodotdc_clus_bar_tdc_meantime = new TTreeReaderArray<Double_t>{rd,"bb.hodotdc.clus.bar.tdc.meantime"};
  bb_tr_x = new TTreeReaderArray<Double_t>{rd,"bb.tr.x"};
  bb_tr_y = new TTreeReaderArray<Double_t>{rd,"bb.tr.y"};
  bb_tr_px = new TTreeReaderArray<Double_t>{rd,"bb.tr.px"};
  bb_tr_py = new TTreeReaderArray<Double_t>{rd,"bb.tr.py"};
  bb_tr_pz = new TTreeReaderArray<Double_t>{rd,"bb.tr.pz"};
  bb_tr_p = new TTreeReaderArray<Double_t>{rd,"bb.tr.p"};
  bb_tr_th = new TTreeReaderArray<Double_t>{rd,"bb.tr.th"};
  bb_tr_ph = new TTreeReaderArray<Double_t>{rd,"bb.tr.ph"};
  bb_tr_vx = new TTreeReaderArray<Double_t>{rd,"bb.tr.vx"};
  bb_tr_vy = new TTreeReaderArray<Double_t>{rd,"bb.tr.vy"};
  bb_tr_vz = new TTreeReaderArray<Double_t>{rd,"bb.tr.vz"};

  bb_tr_tg_th = new TTreeReaderArray<Double_t>{rd,"bb.tr.tg_th"};
  bb_tr_tg_ph = new TTreeReaderArray<Double_t>{rd,"bb.tr.tg_ph"};
  bb_tr_tg_y = new TTreeReaderArray<Double_t>{rd,"bb.tr.tg_y"};
    
  bb_ps_e = new TTreeReaderValue<Double_t>{rd,"bb.ps.e"};
  bb_sh_e = new TTreeReaderValue<Double_t>{rd,"bb.sh.e"};
    
  sbs_hcal_x = new TTreeReaderValue<Double_t>{rd,"sbs.hcal.x"};
  sbs_hcal_y = new TTreeReaderValue<Double_t>{rd,"sbs.hcal.y"};
  sbs_hcal_e = new TTreeReaderValue<Double_t>{rd,"sbs.hcal.e"};
  sbs_hcal_nclus = new TTreeReaderValue<Double_t>{rd,"sbs.hcal.nclus"};
    
  bb_tr_n = new TTreeReaderValue<Double_t>(rd,"bb.tr.n");
  
  
  //setup ML stuff 
  TMVA::Reader reader1; // = new TMVA::Reader("!Color");
  TMVA::Reader reader2;
  
  float var1,var2,var3,var4;
  reader1.AddVariable( "bb.tr.x", &var1 );
  reader1.AddVariable( "bb.tr.y", &var2 );
  reader1.AddVariable( "bb.tr.th", &var3 );
  reader1.AddVariable( "bb.tr.ph", &var4 );
  
  float var5,var6,var7,var8;
  reader2.AddVariable( "bb.tr.p", &var5 );
  reader2.AddVariable( "bb.tr.tg_y", &var6 );
  reader2.AddVariable( "bb.tr.tg_th", &var7 );
  reader2.AddVariable( "bb.tr.tg_ph", &var8 );
  
  double FP_response;
  double TG_response;
  
  if(MVA_method){
    reader1.BookMVA("HodoFPRegression","/home/garyp/MachineLearning/HodoRegression/FocalPlane/dataset/weights/TMVARegression_MLP.weights.xml");
    reader2.BookMVA("HodoTGRegression","/home/garyp/MachineLearning/HodoRegression/TargetPlane/dataset/weights/TMVARegression_MLP.weights.xml");
  }
  
  
  //setup histograms
  Int_t nbins = 200;

  //1d time histo
  TH1D *hMT = new TH1D("hMT","",nbins,-4,-4);
  TH1D *hMT_fpc = new TH1D("hMT_fpc","",nbins,-4,-4);
  TH1D *hMT_tgc = new TH1D("hMT_tgc","",nbins,-4,-4);
    

  //focal plane vars
  TH2D *h2d_mt_x = new TH2D("h2d_mt_x","",
			    nbins,-0.6,0.6,
			    nbins,6,-10);
  TH2D *h2d_mt_y = new TH2D("h2d_mt_y","",
			    nbins,-0.2,-0.2,
			    nbins,-4,-4);
  TH2D *h2d_mt_th = new TH2D("h2d_mt_th","",
			    nbins,-0.2,-0.2,
			    nbins,-4,-4);
  TH2D *h2d_mt_ph = new TH2D("h2d_mt_ph","",
			    nbins,-0.2,-0.2,
			    nbins,-4,-4);
  //corrected
  TH2D *h2d_mt_x_c = new TH2D("h2d_mt_x_c","",
			    nbins,-0.5,-0.5,
			    nbins,-4,-4);
  TH2D *h2d_mt_y_c = new TH2D("h2d_mt_y_c","",
			    nbins,-0.2,-0.2,
			    nbins,-4,-4);
  TH2D *h2d_mt_th_c = new TH2D("h2d_mt_th_c","",
			    nbins,-0.2,-0.2,
			    nbins,-4,-4);
  TH2D *h2d_mt_ph_c = new TH2D("h2d_mt_ph_c","",
			    nbins,-0.2,-0.2,
			    nbins,-4,-4);

  //target vars
  TH2D *h2d_mt_tgy = new TH2D("h2d_mt_tgy","",
			    100,-0.3,0.3,
			    100,-4,4);
  TH2D *h2d_mt_tgth = new TH2D("h2d_mt_tgth","",
			    100,-0.3,0.3,
			    100,-4,4);
  TH2D *h2d_mt_tgph = new TH2D("h2d_mt_tgph","",
			    100,-0.2,0.2,
			    100,-4,4);
  TH2D *h2d_mt_p = new TH2D("h2d_mt_p","",
			    100,2.0,3.5,
			    100,-4,4);

  //corrected
  TH2D *h2d_mt_tgy_c = new TH2D("h2d_mt_tgy_c","",
			    100,-0.3,0.3,
			    100,-4,4);
  TH2D *h2d_mt_tgth_c = new TH2D("h2d_mt_tgth_c","",
			    100,-0.3,0.3,
			    100,-4,4);
  TH2D *h2d_mt_tgph_c = new TH2D("h2d_mt_tgph_c","",
			    100,-0.2,0.2,
			    100,-4,4);
  TH2D *h2d_mt_p_c = new TH2D("h2d_mt_p_c","",
			    100,2.0,3.5,
			    100,-4,4);

  
  
  //event loop
  Long64_t ev = -1;
  Long64_t nev = C->GetEntries();
  cout << "Processing " << nev << " events." << endl;
  
  while(rd.Next() && ev < nev){
    ev = rd.GetCurrentEntry();

    //if(ev%10000==0) cout << ev << "/" << nev << endl;
    
    if(**bb_tr_n < 1) continue;
    if(bb_hodotdc_clus_bar_tdc_meantime->GetSize() < 2) continue;
    
    double hodomt = (*bb_hodotdc_clus_bar_tdc_meantime)[0] - (*bb_hodotdc_clus_bar_tdc_meantime)[1];
    
    double tr_x = (*bb_tr_x)[0];
    double tr_y = (*bb_tr_y)[0];
    double th = (*bb_tr_th)[0];
    double ph = (*bb_tr_ph)[0];

    double p = (*bb_tr_p)[0];
    double tg_y = (*bb_tr_tg_y)[0];
    double tg_th = (*bb_tr_tg_th)[0];
    double tg_ph = (*bb_tr_tg_ph)[0];
    
    var1 = tr_x;
    var2 = tr_y;
    var3 = th;
    var4 = ph;
    
    var5 = p;
    var6 = tg_y;
    var7 = tg_th;
    var8 = tg_ph;
    
    if( p < 2.0) continue; //low p electron cut
    if( fabs(tg_y) > 0.18) continue; //cut on target windows
    if ( (**bb_ps_e) < 0.2) continue; //low E pion cut
    
    //uncalibrated histograms
    hMT->Fill(hodomt);
    //focal plane
    h2d_mt_x->Fill(tr_x,hodomt);
    h2d_mt_y->Fill(tr_y,hodomt);
    h2d_mt_th->Fill(th,hodomt);
    h2d_mt_ph->Fill(ph,hodomt);
    
    //target
    h2d_mt_p->Fill(p,hodomt);
    h2d_mt_tgy->Fill(tg_y,hodomt);
    h2d_mt_tgth->Fill(tg_th,hodomt);
    h2d_mt_tgph->Fill(tg_ph,hodomt);

    //either use fits or MVA response for correction
    double mt_fp_c;
    double mt_tg_c;
    
    if (MVA_method){
      FP_response = reader1.EvaluateMVA("HodoFPRegression");
      TG_response = reader2.EvaluateMVA("HodoTGRegression");
      
      mt_fp_c = hodomt - FP_response;
      mt_tg_c = hodomt - TG_response;
      //mt_fp_c = FP_response;
      //mt_tg_c = TG_response;
    
    }else if(GP_method){
      double L_fp = 0;
      double L_tg = 0;
      
      if(iter >= 0){
	L_fp = 0;
	L_tg = 0;
      }
      if(iter >=  1){
	L_fp = L_fp + fp_iter_pars[0] + fp_iter_pars[1]*tr_x;
	L_tg = L_tg + tg_iter_pars[0] + tg_iter_pars[1]*p;
      }
      if(iter >=  2){
	L_fp = L_fp + fp_iter_pars[2] + fp_iter_pars[3]*tr_y;
	L_tg = L_tg + tg_iter_pars[2] + tg_iter_pars[3]*tg_y;
      }
      if(iter >=  3){
	L_fp = L_fp + fp_iter_pars[4] + fp_iter_pars[5]*th;	
	L_tg = L_tg + tg_iter_pars[4] + tg_iter_pars[5]*tg_th;
      }
      if(iter >=  4){
	L_fp = L_fp + fp_iter_pars[6] + fp_iter_pars[7]*ph;
	L_tg = L_tg + tg_iter_pars[6] + tg_iter_pars[7]*tg_ph;
      }
      
      mt_fp_c = hodomt - L_fp;
      mt_tg_c = hodomt - L_tg;
      
    }else if(JW_method){
      double mt_x_c = (fp_pars[1]*tr_x + fp_pars[0]);
      double mt_y_c = (fp_pars[3]*tr_y + fp_pars[2]);
      double mt_th_c = (fp_pars[5]*th + fp_pars[4]);
      double mt_ph_c = (fp_pars[7]*ph + fp_pars[6]);
      
      double mt_p_c = (tg_pars[1]*p + tg_pars[0]);
      double mt_tgy_c = (tg_pars[3]*tg_y + tg_pars[2]);
      double mt_tgth_c = (tg_pars[5]*tg_th + tg_pars[4]);
      double mt_tgph_c = (tg_pars[7]*tg_ph + tg_pars[6]);
      
      double L_fp = mt_x_c + mt_y_c + mt_th_c + mt_ph_c;
      double L_tg = mt_p_c + mt_tgy_c + mt_tgth_c + mt_tgph_c;
      
      mt_fp_c = hodomt - L_fp;
      mt_tg_c = hodomt - L_tg;
	
    }
	     
    //corrected histos
    hMT_fpc->Fill(mt_fp_c);
    hMT_tgc->Fill(mt_tg_c);
    
    h2d_mt_x_c->Fill(tr_x,mt_fp_c);
    h2d_mt_y_c->Fill(tr_y,mt_fp_c);
    h2d_mt_th_c->Fill(th,mt_fp_c);
    h2d_mt_ph_c->Fill(ph,mt_fp_c);
      
    h2d_mt_p_c->Fill(p,mt_tg_c);
    h2d_mt_tgy_c->Fill(tg_y,mt_tg_c);
    h2d_mt_tgth_c->Fill(tg_th,mt_tg_c);
    h2d_mt_tgph_c->Fill(tg_ph,mt_tg_c);
    
  }
  outfile->Write();
  outfile->Close();
}

void DrawPL(TString method = "null", Int_t iter = -1){
  
  TFile *file = new TFile(outfilename,"OPEN");
  
  TH1D *hMT = (TH1D*)file->Get("hMT");
  TH1D *hMT_fpc = (TH1D*)file->Get("hMT_fpc");
  TH1D *hMT_tgc = (TH1D*)file->Get("hMT_tgc");

  TH2D *h2d_mt_x = (TH2D*)file->Get("h2d_mt_x");
  TH2D *h2d_mt_y = (TH2D*)file->Get("h2d_mt_y");
  TH2D *h2d_mt_th = (TH2D*)file->Get("h2d_mt_th");
  TH2D *h2d_mt_ph = (TH2D*)file->Get("h2d_mt_ph");

  TH2D *h2d_mt_tgy = (TH2D*)file->Get("h2d_mt_tgy");
  TH2D *h2d_mt_tgth = (TH2D*)file->Get("h2d_mt_tgth");
  TH2D *h2d_mt_tgph = (TH2D*)file->Get("h2d_mt_tgph");
  TH2D *h2d_mt_p = (TH2D*)file->Get("h2d_mt_p");
  
  TH2D *h2d_mt_x_c = (TH2D*)file->Get("h2d_mt_x_c");
  TH2D *h2d_mt_y_c = (TH2D*)file->Get("h2d_mt_y_c");
  TH2D *h2d_mt_th_c = (TH2D*)file->Get("h2d_mt_th_c");
  TH2D *h2d_mt_ph_c = (TH2D*)file->Get("h2d_mt_ph_c");
  
  TH2D *h2d_mt_tgy_c = (TH2D*)file->Get("h2d_mt_tgy_c");
  TH2D *h2d_mt_tgth_c = (TH2D*)file->Get("h2d_mt_tgth_c");
  TH2D *h2d_mt_tgph_c = (TH2D*)file->Get("h2d_mt_tgph_c");
  TH2D *h2d_mt_p_c = (TH2D*)file->Get("h2d_mt_p_c");
  
  TF1 *f = new TF1("f","pol1");
  
  TLatex *tex = new TLatex();
  tex->SetNDC();
  //tex->SetTextSize(0.04);
  //tex->SetTextColor(kBlack);
  //tex->SetTextAlign(22);

  double xndc = 0.25;
  double yndc = 0.80;
  double chi2 = 0;
  
  Int_t fsy_cut = 100;
  
  //x focal plane
  TCanvas *c_x = new TCanvas("c_x","Focal Plane x",1920,1080);
  c_x->Divide(2,2);
  c_x->cd(1);
  h2d_mt_x->GetXaxis()->SetTitle("x_{FP} [m]");
  h2d_mt_x->GetYaxis()->SetTitle("Hodoscope Mean Time [ns]");
  h2d_mt_x->Draw("colz");
  
  c_x->cd(2);
  h2d_mt_x->FitSlicesY(0,0,-1,fsy_cut,"QNR");
  TH1D *h2d_mt_x_1 = (TH1D*)gDirectory->Get("h2d_mt_x_1");
  h2d_mt_x_1->SetMinimum(-10);
  h2d_mt_x_1->SetMaximum(6);
  h2d_mt_x_1->Fit("f","");
  h2d_mt_x_1->Draw();
  chi2 = f->GetChisquare() / f->GetNDF();
  tex->DrawLatex(xndc,yndc,Form("#Chi^{2}=%.1f",chi2));
  
  c_x->cd(3);
  TH1D *h2d_mt_x_0 = (TH1D*)gDirectory->Get("h2d_mt_x_0");
  h2d_mt_x_0->Draw();

  c_x->cd(4);
  TH1D *h2d_mt_x_2 = (TH1D*)gDirectory->Get("h2d_mt_x_2");
  h2d_mt_x_2->Draw();
  c_x->Print("hodopl_fp1.pdf");
  c_x->Print("x_fp.png");
  c_x->Close();
  //////
  
  //y focal plane
  TCanvas *c_y = new TCanvas("c_y","Focal Plane y",1920,1080);
  c_y->Divide(2,2);
  c_y->cd(1);
  h2d_mt_y->GetXaxis()->SetTitle("y_{FP} [m]");
  h2d_mt_y->GetYaxis()->SetTitle("Hodoscope Mean Time [ns]");
  h2d_mt_y->Draw("colz");
  
  c_y->cd(2);
  h2d_mt_y->FitSlicesY(0,0,-1,fsy_cut,"QNR");
  TH1D *h2d_mt_y_1 = (TH1D*)gDirectory->Get("h2d_mt_y_1");
  h2d_mt_y_1->SetMinimum(-10);
  h2d_mt_y_1->SetMaximum(6);
  h2d_mt_y_1->Fit("f","");
  h2d_mt_y_1->Draw();
  chi2 = f->GetChisquare() / f->GetNDF();
  tex->DrawLatex(xndc,yndc,Form("#Chi^{2}=%.1f",chi2));
  
  c_y->cd(3);
  TH1D *h2d_mt_y_0 = (TH1D*)gDirectory->Get("h2d_mt_y_0");
  h2d_mt_y_0->Draw();

  c_y->cd(4);
  TH1D *h2d_mt_y_2 = (TH1D*)gDirectory->Get("h2d_mt_y_2");
  h2d_mt_y_2->Draw();
  c_y->Print("hodopl_fp2.pdf");
  c_y->Print("y_fp.png");
  c_y->Close();
  /////

  //theta focal plane
  TCanvas *c_th = new TCanvas("c_th","Focal Plane #theta",1920,1080);
  c_th->Divide(2,2);
  c_th->cd(1);
  h2d_mt_th->GetXaxis()->SetTitle("#theta_{FP} [m]");
  h2d_mt_th->GetYaxis()->SetTitle("Hodoscope Mean Time [ns]");
  h2d_mt_th->Draw("colz");
  
  c_th->cd(2);
  h2d_mt_th->FitSlicesY(0,0,-1,fsy_cut,"QNR");
  TH1D *h2d_mt_th_1 = (TH1D*)gDirectory->Get("h2d_mt_th_1");
  h2d_mt_th_1->SetMinimum(-10);
  h2d_mt_th_1->SetMaximum(6);
  h2d_mt_th_1->Fit("f","");
  h2d_mt_th_1->Draw();
  chi2 = f->GetChisquare() / f->GetNDF();
  tex->DrawLatex(xndc,yndc,Form("#Chi^{2}=%.1f",chi2));
  
  c_th->cd(3);
  TH1D *h2d_mt_th_0 = (TH1D*)gDirectory->Get("h2d_mt_th_0");
  h2d_mt_th_0->Draw();

  c_th->cd(4);
  TH1D *h2d_mt_th_2 = (TH1D*)gDirectory->Get("h2d_mt_th_2");
  h2d_mt_th_2->Draw();
  c_th->Print("hodopl_fp3.pdf");
  c_th->Print("th_fp.png");
  c_th->Close();
  /////
  
  //phi focal plane
  TCanvas *c_ph = new TCanvas("c_ph","Focal Plane #phi",1920,1080);
  c_ph->Divide(2,2);
  c_ph->cd(1);
  h2d_mt_ph->GetXaxis()->SetTitle("#phi_{FP} [m]");
  h2d_mt_ph->GetYaxis()->SetTitle("Hodoscope Mean Time [ns]");
  h2d_mt_ph->Draw("colz");
  
  c_ph->cd(2);
  h2d_mt_ph->FitSlicesY(0,0,-1,fsy_cut,"QNR");
  TH1D *h2d_mt_ph_1 = (TH1D*)gDirectory->Get("h2d_mt_ph_1");
  h2d_mt_ph_1->SetMinimum(-10);
  h2d_mt_ph_1->SetMaximum(6);
  h2d_mt_ph_1->Fit("f","");
  h2d_mt_ph_1->Draw();
  chi2 = f->GetChisquare() / f->GetNDF();
  tex->DrawLatex(xndc,yndc,Form("#Chi^{2}=%.1f",chi2));
  
  c_ph->cd(3);
  TH1D *h2d_mt_ph_0 = (TH1D*)gDirectory->Get("h2d_mt_ph_0");
  h2d_mt_ph_0->Draw();

  c_ph->cd(4);
  TH1D *h2d_mt_ph_2 = (TH1D*)gDirectory->Get("h2d_mt_ph_2");
  h2d_mt_ph_2->Draw();
  c_ph->Print("hodopl_fp4.pdf");
  c_ph->Print("ph_fp.png");
  c_ph->Close();
  /////

    //target variables
  TCanvas *c_p = new TCanvas("c_p","Target Plane x",1920,1080);
  c_p->Divide(2,2);
  c_p->cd(1);
  h2d_mt_p->GetXaxis()->SetTitle("p [m]");
  h2d_mt_p->GetYaxis()->SetTitle("Hodoscope Mean Time [ns]");
  h2d_mt_p->Draw("colz");
  
  c_p->cd(2);
  h2d_mt_p->FitSlicesY(0,0,-1,fsy_cut,"QNR");
  TH1D *h2d_mt_p_1 = (TH1D*)gDirectory->Get("h2d_mt_p_1");
  h2d_mt_p_1->SetMinimum(-10);
  h2d_mt_p_1->SetMaximum(6);
  h2d_mt_p_1->Fit("f","");
  h2d_mt_p_1->Draw();
  chi2 = f->GetChisquare() / f->GetNDF();
  tex->DrawLatex(xndc,yndc,Form("#Chi^{2}=%.1f",chi2));

  c_p->cd(3);
  TH1D *h2d_mt_p_0 = (TH1D*)gDirectory->Get("h2d_mt_p_0");
  h2d_mt_p_0->Draw();

  c_p->cd(4);
  TH1D *h2d_mt_p_2 = (TH1D*)gDirectory->Get("h2d_mt_p_2");
  h2d_mt_p_2->Draw();
  c_p->Print("hodopl_tg1.pdf");
  c_p->Print("p_tg.png");
  c_p->Close();
  //////
  
  //y focal plane
  TCanvas *c_tgy = new TCanvas("c_tgy","Target Plane y",1920,1080);
  c_tgy->Divide(2,2);
  c_tgy->cd(1);
  h2d_mt_tgy->GetXaxis()->SetTitle("y_{TG} [m]");
  h2d_mt_tgy->GetYaxis()->SetTitle("Hodoscope Mean Time [ns]");
  h2d_mt_tgy->Draw("colz");
  
  c_tgy->cd(2);
  h2d_mt_tgy->FitSlicesY(0,0,-1,fsy_cut,"QNR");
  TH1D *h2d_mt_tgy_1 = (TH1D*)gDirectory->Get("h2d_mt_tgy_1");
  h2d_mt_tgy_1->SetMinimum(-10);
  h2d_mt_tgy_1->SetMaximum(6);
  h2d_mt_tgy_1->Fit("f","");
  h2d_mt_tgy_1->Draw();
  chi2 = f->GetChisquare() / f->GetNDF();
  tex->DrawLatex(xndc,yndc,Form("#Chi^{2}=%.1f",chi2));

  c_tgy->cd(3);
  TH1D *h2d_mt_tgy_0 = (TH1D*)gDirectory->Get("h2d_mt_tgy_0");
  h2d_mt_tgy_0->Draw();

  c_tgy->cd(4);
  TH1D *h2d_mt_tgy_2 = (TH1D*)gDirectory->Get("h2d_mt_tgy_2");
  h2d_mt_tgy_2->Draw();
  c_tgy->Print("hodopl_tg2.pdf");
  c_tgy->Print("y_fp.png");
  c_tgy->Close();
  /////

  
  //theta focal plane
  TCanvas *c_tgth = new TCanvas("c_tgth","Target Plane #theta",1920,1080);
  c_tgth->Divide(2,2);
  c_tgth->cd(1);
  h2d_mt_tgth->GetXaxis()->SetTitle("#theta_{TG} [m]");
  h2d_mt_tgth->GetYaxis()->SetTitle("Hodoscope Mean Time [ns]");
  h2d_mt_tgth->Draw("colz");
  
  c_tgth->cd(2);
  h2d_mt_tgth->FitSlicesY(0,0,-1,fsy_cut,"QNR");
  TH1D *h2d_mt_tgth_1 = (TH1D*)gDirectory->Get("h2d_mt_tgth_1");
  h2d_mt_tgth_1->SetMinimum(-10);
  h2d_mt_tgth_1->SetMaximum(6);
  h2d_mt_tgth_1->Fit("f","");
  h2d_mt_tgth_1->Draw();
  chi2 = f->GetChisquare() / f->GetNDF();
  tex->DrawLatex(xndc,yndc,Form("#Chi^{2}=%.1f",chi2));

  c_tgth->cd(3);
  TH1D *h2d_mt_tgth_0 = (TH1D*)gDirectory->Get("h2d_mt_tgth_0");
  h2d_mt_tgth_0->Draw();

  c_tgth->cd(4);
  TH1D *h2d_mt_tgth_2 = (TH1D*)gDirectory->Get("h2d_mt_tgth_2");
  h2d_mt_tgth_2->Draw();
  c_tgth->Print("hodopl_tg3.pdf");
  c_tgth->Print("th_tg.png");
  c_tgth->Close();
  /////
  
  
  //phi focal plane
  TCanvas *c_tgph = new TCanvas("c_tgph","Target Plane #phi",1920,1080);
  c_tgph->Divide(2,2);
  c_tgph->cd(1);
  h2d_mt_tgph->GetXaxis()->SetTitle("#phi_{TG} [m]");
  h2d_mt_tgph->GetYaxis()->SetTitle("Hodoscope Mean Time [ns]");
  h2d_mt_tgph->Draw("colz");
  
  c_tgph->cd(2);
  h2d_mt_tgph->FitSlicesY(0,0,-1,fsy_cut,"QNR");
  TH1D *h2d_mt_tgph_1 = (TH1D*)gDirectory->Get("h2d_mt_tgph_1");
  h2d_mt_tgph_1->SetMinimum(-10);
  h2d_mt_tgph_1->SetMaximum(6);
  h2d_mt_tgph_1->Fit("f","");
  h2d_mt_tgph_1->Draw();
  chi2 = f->GetChisquare() / f->GetNDF();
  tex->DrawLatex(xndc,yndc,Form("#Chi^{2}=%.1f",chi2));

  c_tgph->cd(3);
  TH1D *h2d_mt_tgph_0 = (TH1D*)gDirectory->Get("h2d_mt_tgph_0");
  h2d_mt_tgph_0->Draw();

  c_tgph->cd(4);
  TH1D *h2d_mt_tgph_2 = (TH1D*)gDirectory->Get("h2d_mt_tgph_2");
  h2d_mt_tgph_2->Draw();
  c_tgph->Print("hodopl_tg4.pdf");
  c_tgph->Print("ph_tg.png");
  c_tgph->Close();
  /////
  
  //Corrected FP
  TCanvas *c_fp = new TCanvas("c_fp","Corrected FP Variables",1920,1080);
  c_fp->Divide(4,2);
  c_fp->cd(1);
  h2d_mt_x_c->GetXaxis()->SetTitle("x_{FP} [m]");
  h2d_mt_x_c->GetYaxis()->SetTitle("Corrected Hodoscope Mean Time [ns]");
  h2d_mt_x_c->Draw("colz");
  
  c_fp->cd(2);
  h2d_mt_x_c->FitSlicesY(0,0,-1,fsy_cut,"QNR");
  TH1D *h2d_mt_x_c_1 = (TH1D*)gDirectory->Get("h2d_mt_x_c_1");
  h2d_mt_x_c_1->SetMinimum(-10);
  h2d_mt_x_c_1->SetMaximum(6);
  h2d_mt_x_c_1->Fit("f","");
  h2d_mt_x_c_1->Draw();
  chi2 = f->GetChisquare() / f->GetNDF();
  tex->DrawLatex(xndc,yndc,Form("#Chi^{2}=%.1f",chi2));
  
  fp_pars[0] = f->GetParameter(0);
  fp_pars[1] = f->GetParameter(1);

  if(iter==0){
    fp_iter_pars[0] = f->GetParameter(0);
    fp_iter_pars[1] = f->GetParameter(1);
  }
  
  c_fp->cd(3);
  h2d_mt_y_c->GetXaxis()->SetTitle("y_{FP} [m]");
  h2d_mt_y_c->GetYaxis()->SetTitle("Corrected Hodoscope Mean Time [ns]");
  h2d_mt_y_c->Draw("colz");
  
  c_fp->cd(4);
  h2d_mt_y_c->FitSlicesY(0,0,-1,fsy_cut,"QNR");
  TH1D *h2d_mt_y_c_1 = (TH1D*)gDirectory->Get("h2d_mt_y_c_1");
  h2d_mt_y_c_1->SetMinimum(-10);
  h2d_mt_y_c_1->SetMaximum(6);
  h2d_mt_y_c_1->Fit("f","");
  h2d_mt_y_c_1->Draw();
  chi2 = f->GetChisquare() / f->GetNDF();
  tex->DrawLatex(xndc,yndc,Form("#Chi^{2}=%.1f",chi2));
  
  fp_pars[2] = f->GetParameter(0);
  fp_pars[3] = f->GetParameter(1);

  if(iter==1){
    fp_iter_pars[2] = f->GetParameter(0);
    fp_iter_pars[3] = f->GetParameter(1);
  }
  
  c_fp->cd(5);
  h2d_mt_th_c->GetXaxis()->SetTitle("#theta_{FP} [m]");
  h2d_mt_th_c->GetYaxis()->SetTitle("Corrected Hodoscope Mean Time [ns]");
  h2d_mt_th_c->Draw("colz");
  
  c_fp->cd(6);
  h2d_mt_th_c->FitSlicesY(0,0,-1,fsy_cut,"QNR");
  TH1D *h2d_mt_th_c_1 = (TH1D*)gDirectory->Get("h2d_mt_th_c_1");
  h2d_mt_th_c_1->SetMinimum(-10);
  h2d_mt_th_c_1->SetMaximum(6);
  h2d_mt_th_c_1->Fit("f","");
  h2d_mt_th_c_1->Draw();
  chi2 = f->GetChisquare() / f->GetNDF();
  tex->DrawLatex(xndc,yndc,Form("#Chi^{2}=%.1f",chi2));
  
  fp_pars[4] = f->GetParameter(0);
  fp_pars[5] = f->GetParameter(1);

  if(iter==2){
    fp_iter_pars[4] = f->GetParameter(0);
    fp_iter_pars[5] = f->GetParameter(1);
  }

  c_fp->cd(7);
  h2d_mt_ph_c->GetXaxis()->SetTitle("#phi_{FP} [m]");
  h2d_mt_ph_c->GetYaxis()->SetTitle("Corrected Hodoscope Mean Time [ns]");
  h2d_mt_ph_c->Draw("colz");
  
  c_fp->cd(8);
  h2d_mt_ph_c->FitSlicesY(0,0,-1,fsy_cut,"QNR");
  TH1D *h2d_mt_ph_c_1 = (TH1D*)gDirectory->Get("h2d_mt_ph_c_1");
  h2d_mt_ph_c_1->SetMinimum(-10);
  h2d_mt_ph_c_1->SetMaximum(6);
  h2d_mt_ph_c_1->Fit("f","");
  h2d_mt_ph_c_1->Draw();
  chi2 = f->GetChisquare() / f->GetNDF();
  tex->DrawLatex(xndc,yndc,Form("#Chi^{2}=%.1f",chi2));
  
  fp_pars[6] = f->GetParameter(0);
  fp_pars[7] = f->GetParameter(1);

  if(iter==3){
    fp_iter_pars[6] = f->GetParameter(0);
    fp_iter_pars[7] = f->GetParameter(1);
  }

  c_fp->Print("hodopl_fp5.pdf");
  c_fp->Print("corrected_fp.png");
  c_fp->Close();
  //////
  
  //Corrected TG
  TCanvas *c_tg = new TCanvas("c_tg","Corrected TG Variables",1920,1080);
  c_tg->Divide(4,2);
  c_tg->cd(1);
  h2d_mt_p_c->GetXaxis()->SetTitle("p [m]");
  h2d_mt_p_c->GetYaxis()->SetTitle("Corrected Hodoscope Mean Time [ns]");
  h2d_mt_p_c->Draw("colz");
  
  c_tg->cd(2);
  h2d_mt_p_c->FitSlicesY(0,0,-1,fsy_cut,"QNR");
  TH1D *h2d_mt_p_c_1 = (TH1D*)gDirectory->Get("h2d_mt_p_c_1");
  h2d_mt_p_c_1->SetMinimum(-10);
  h2d_mt_p_c_1->SetMaximum(6);
  h2d_mt_p_c_1->Fit("f","");
  h2d_mt_p_c_1->Draw();
  chi2 = f->GetChisquare() / f->GetNDF();
  tex->DrawLatex(xndc,yndc,Form("#Chi^{2}=%.1f",chi2));
  
  tg_pars[0] = f->GetParameter(0);
  tg_pars[1] = f->GetParameter(1);

  if(iter==0){
    tg_iter_pars[0] = f->GetParameter(0);
    tg_iter_pars[1] = f->GetParameter(1);
  }

  c_tg->cd(3);
  h2d_mt_tgy_c->GetXaxis()->SetTitle("y_{TG} [m]");
  h2d_mt_tgy_c->GetYaxis()->SetTitle("Corrected Hodoscope Mean Time [ns]");
  h2d_mt_tgy_c->Draw("colz");
  
  c_tg->cd(4);
  h2d_mt_tgy_c->FitSlicesY(0,0,-1,fsy_cut,"QNR");
  TH1D *h2d_mt_tgy_c_1 = (TH1D*)gDirectory->Get("h2d_mt_tgy_c_1");
  h2d_mt_tgy_c_1->SetMinimum(-10);
  h2d_mt_tgy_c_1->SetMaximum(6);
  h2d_mt_tgy_c_1->Fit("f","");
  h2d_mt_tgy_c_1->Draw();
  chi2 = f->GetChisquare() / f->GetNDF();
  tex->DrawLatex(xndc,yndc,Form("#Chi^{2}=%.1f",chi2));
  
  tg_pars[2] = f->GetParameter(0);
  tg_pars[3] = f->GetParameter(1);
  
  if(iter==1){
    tg_iter_pars[2] = f->GetParameter(0);
    tg_iter_pars[3] = f->GetParameter(1);
  }

  c_tg->cd(5);
  h2d_mt_tgth_c->GetXaxis()->SetTitle("#theta_{TG} [m]");
  h2d_mt_tgth_c->GetYaxis()->SetTitle("Corrected Hodoscope Mean Time [ns]");
  h2d_mt_tgth_c->Draw("colz");
  
  c_tg->cd(6);
  h2d_mt_tgth_c->FitSlicesY(0,0,-1,fsy_cut,"QNR");
  TH1D *h2d_mt_tgth_c_1 = (TH1D*)gDirectory->Get("h2d_mt_tgth_c_1");
  h2d_mt_tgth_c_1->SetMinimum(-10);
  h2d_mt_tgth_c_1->SetMaximum(6);
  h2d_mt_tgth_c_1->Fit("f","");
  h2d_mt_tgth_c_1->Draw();
  chi2 = f->GetChisquare() / f->GetNDF();
  tex->DrawLatex(xndc,yndc,Form("#Chi^{2}=%.1f",chi2));
  
  tg_pars[4] = f->GetParameter(0);
  tg_pars[5] = f->GetParameter(1);

  if(iter==2){
    tg_iter_pars[4] = f->GetParameter(0);
    tg_iter_pars[5] = f->GetParameter(1);
  }

  c_tg->cd(7);
  h2d_mt_tgph_c->GetXaxis()->SetTitle("#phi_{TG} [m]");
  h2d_mt_tgph_c->GetYaxis()->SetTitle("Corrected Hodoscope Mean Time [ns]");
  h2d_mt_tgph_c->Draw("colz");
  
  c_tg->cd(8);
  h2d_mt_tgph_c->FitSlicesY(0,0,-1,fsy_cut,"QNR");
  TH1D *h2d_mt_tgph_c_1 = (TH1D*)gDirectory->Get("h2d_mt_tgph_c_1");
  h2d_mt_tgph_c_1->SetMinimum(-10);
  h2d_mt_tgph_c_1->SetMaximum(6);
  h2d_mt_tgph_c_1->Fit("f","");
  h2d_mt_tgph_c_1->Draw();
  chi2 = f->GetChisquare() / f->GetNDF();
  tex->DrawLatex(xndc,yndc,Form("#Chi^{2}=%.1f",chi2));

  tg_pars[6] = f->GetParameter(0);
  tg_pars[7] = f->GetParameter(1);

  if(iter==3){
    tg_iter_pars[6] = f->GetParameter(0);
    tg_iter_pars[7] = f->GetParameter(1);
  }

  c_tg->Print("hodopl_tg.pdf");
  c_tg->Print("corrected_tg.png");
  c_tg->Close();

  TCanvas *c_1d = new TCanvas("c_1d","",1920,1080);
  TF1 *fgaus = new TF1("fgaus","gaus");
  c_1d->Divide(2,2);
  c_1d->cd(1);
  hMT->GetXaxis()->SetTitle("tmean [ns]");
  hMT->Draw("");
  hMT->Fit("fgaus","");
  tex->DrawLatex(xndc,yndc,Form("#sigma = %.2f",fgaus->GetParameter(2)));
  
  c_1d->cd(3);
  hMT_fpc->GetXaxis()->SetTitle("tmean fp corr [ns]");
  hMT_fpc->Draw("");
  hMT_fpc->Fit("fgaus","");
  tex->DrawLatex(xndc,yndc,Form("#sigma = %.2f",fgaus->GetParameter(2)));
  
  c_1d->cd(4);
  hMT_tgc->GetXaxis()->SetTitle("tmean tg corr [ns]");
  hMT_tgc->Draw("");
  hMT_tgc->Fit("fgaus","");
  tex->DrawLatex(xndc,yndc,Form("#sigma = %.2f",fgaus->GetParameter(2)));
  
  c_1d->Print(Form("time_%s_1d.png",method.Data()));
  c_1d->Close();
	       
  gSystem->Exec(Form("pdfunite hodopl_fp*.pdf HodoPL_%s_fp_%i.pdf",method.Data(),iter));
  gSystem->Exec(Form("pdfunite hodopl_tg*.pdf HodoPL_%s_tg_%i.pdf",method.Data(),iter));
  gSystem->Exec("rm hodopl_*.pdf");

}

void PathLength(){
  
  TString method = "";
  
  if(GP_method){
    method = "GP";
    for (int i=0; i<5; i++){
      RunPL("GEN", 2, "H2",i);
      DrawPL(method,i);
    }
  }

  if(JW_method){
    method = "JW";
    RunPL("GEN", 2, "H2",0);
    DrawPL(method,0);
    RunPL("GEN", 2, "H2",1);
    DrawPL(method,1);
  }

  if(MVA_method){
    method = "MVA";
    RunPL("GEN", 2, "H2",0);
    DrawPL(method,0);
  }
    
  
}
