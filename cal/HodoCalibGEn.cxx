#include "GEnTree.C"

// Choose cut options
const Bool_t ApplyElec = false;
const Bool_t ApplyElas = false;

const Bool_t PlotParam = true;
const Bool_t PlotPMT = true;
const Bool_t PlotBars = true;


void HodoCalibGEn(Int_t kin_no = 2){
  
  // Files to use
  //const TString sFileOut = "$OUT_DIR/Plots_standalone.root";
  const TString sFileOut = "../Results/Plots_Test.root";
  
  // Load in files - point to replayed files
  TChain* C = new TChain("T");
  //C->Add("$HODO_FILE_DIR/e12*full*11573_stream0_seg0_141*.root");
  //C->Add("$HODO_FILE_DIR/e12*full*11590_stream0_seg0_72*.root");
  //C->Add("$HODO_FILE_DIR/e12*full*11590_stream0_seg0_0.root");
  //C->Add("/adaqfs/home/a-onl/gpenman/rootfiles/e1209016*.root");
  
  //gSystem->Setenv("OUT_DIR","/volatile/halla/sbs/jeffas/GEN_root/Rootfiles/GEN2/He3/good_helicity");
  //C->Add("$OUT_DIR/e1209016_fullreplay_2321*.root");
  //C->Add("$OUT_DIR/e1209016_fullreplay_2322*.root");
  //C->Add("$OUT_DIR/e1209016_fullreplay_2323*.root");
  
  C->Add("../rootfiles/1888_old_tdiff_1M.root");
  
  GEnTree* T = new GEnTree(C);
  Long64_t nentries = C->GetEntries();
  
  if (nentries == 0){
    cout << "No events, check file(s)!" << endl;
    return(0);
  }
  else 
    cout << "Processing " << nentries << endl;
  
  // Declare histograms
  
  // Hodoscope parameters
  // Pre-selection
  TH1D* htd0 = new TH1D("htd0",";Bar no.; time diff. offset [ns]",90,1,90);
  TH1D* hvsc = new TH1D("hvsc",";Bar no.; v_{scint} [m/ns]",90,1,90);
  // Post-selection
  TH1D* htd0_post = new TH1D("htd0_post",";Bar no.; time diff. offset [ns]",90,1,90);
  TH1D* hvsc_post = new TH1D("hvsc_post",";Bar no.; v_{scint} [m/ns]",90,1,90);
  
  // Timing information (tdiff and tavg); for cluster, bar and PMT (with and without TW correction)
  TH1D* hclust_tavg = new TH1D("hclust_tavg",";<t_{clust}> [ns];Counts / 100ps",400,-20,20);
  TH1D* hclust_tdiff = new TH1D("hclust_tdiff",";#Delta t_{clust} [ns];Counts / 100ps",200,-10,10);
  TH1D* hbar_main_tavg = new TH1D("hbar_main_tavg",";<t_{bar}> [ns];Counts / 100ps",400,-20,20);
  TH1D* hbar_main_tdiff = new TH1D("hbar_main_tdiff",";#Delta t_{bar} [ns];Counts / 100ps",200,-10,10);
  TH1D* hbar_scndry_tavg = new TH1D("hbar_scndry_tavg",";<t_{bar}> [ns];Counts / 100ps",400,-20,20);
  TH1D* hbar_scndry_tdiff = new TH1D("hbar_scndry_tdiff",";#Delta t_{bar} [ns];Counts / 100ps",200,-10,10);
  TH1D* hpmtL_tavg = new TH1D("hpmtL_tavg",";<t_{L}> [ns];Counts / 100ps",400,-20,20);
  TH1D* hpmtL_tdiff = new TH1D("hpmtL_tdiff",";#Delta t_{L} [ns];Counts / 100ps",200,-10,10);
  TH1D* hpmtR_tavg = new TH1D("hpmtR_tavg",";<t_{R}> [ns];Counts / 100ps",400,-20,20);
  TH1D* hpmtR_tdiff = new TH1D("hpmtR_tdiff",";#Delta t_{R} [ns];Counts / 100ps",200,-10,10);
  TH1D* hpmtL_tavg_TW = new TH1D("hpmtL_tavg_TW",";<t_{L}> (w/ t.w.) [ns];Counts / 100ps",400,-20,20);
  TH1D* hpmtL_tdiff_TW = new TH1D("hpmtL_tdiff_TW",";#Delta t_{L} (w/ t.w.) [ns];Counts / 100ps",200,-10,10);
  TH1D* hpmtR_tavg_TW = new TH1D("hpmtR_tavg_TW",";<t_{R}> (w/ t.w.) [ns];Counts / 100ps",400,-20,20);
  TH1D* hpmtR_tdiff_TW = new TH1D("hpmtR_tdiff_TW",";#Delta t_{R} (w/ t.w.) [ns];Counts / 100ps",200,-10,10);

  const Int_t nBarsTDC = 90;
  TH2D* hDiff[nBarsTDC];
  for(Int_t i=0; i<nBarsTDC; i++) {
    hDiff[i] = new TH2D(Form("hDiff_%d",i), ";y_{fp} [m]; #Delta_{t} [ns]", 50, -0.35, 0.35, 50, -7., 7. );
  }

  // For testing
  //nentries = 100000;

  for(Long64_t ev=0; ev<nentries;ev++){
    T->GetEntry(ev);
    
    if( ev%10000 == 0 ) cout << ev << endl;
  
    // Kinematic stuff
    const Double_t hodo_dist  = 1.8545;
    Double_t Eb{4.288};
    Double_t Mp{0.93827};
    Double_t th = acos(T->bb_tr_pz[0]/T->bb_tr_p[0]);
    
    Double_t pexp_th = 2.*Mp*Eb*(Mp+Eb)*cos(th) / (Mp*Mp + 2.*Mp*Eb + (Eb*sin(th)*Eb*sin(th))); // e mom from angle
    Double_t p = T->bb_tr_p[0];
    Double_t pdiff_off{0.038};
    Double_t pdiff = p - pexp_th; 
    
    /*
    pdiff = pdiff - pdiff_off;
    pdiff = pdiff-0.07*T->bb_tr_x[0];
    pdiff = pdiff-0.32*T->bb_tr_y[0];
    */
    
    // Apply cuts if needed; kinetic variables as for SBS4 data
    Double_t sh_min{0.65};
    Double_t sh_max{1.0};
    Double_t sh_e{0.70};
    Double_t ps_min{0.1};
    Double_t pcent{2.69};
    Double_t pdiffcut{0.1};
    Double_t W_min{0.0}; 
    Double_t W_max{4.0}; 
    
    if(ApplyElec){
      if( T->bb_ps_e/T->bb_tr_p[0] < ps_min ) continue;
      if( (T->bb_ps_e/T->bb_tr_p[0] + sh_e*T->bb_sh_e/T->bb_tr_p[0]) < sh_min ) continue;
      if( (T->bb_ps_e/T->bb_tr_p[0] + sh_e*T->bb_sh_e/T->bb_tr_p[0]) > sh_max ) continue;
      //if( T->bb_tr_p[0] < 0.25*pcent ) continue;
      }
    
    //if(ApplyElas){
    //    if( fabs(pdiff) > pdiffcut ) continue;
    //if( T->e_kine_W2 < W_min ) continue; 
    //if( T->e_kine_W2 > W_max ) continue;   
   
//}
    
    
    // Start filling histos
    // Only want hodo clusters that match bb track id = 0 (I guess redundant for single track events)
    if(T->bb_hodotdc_clus_trackindex[0] == 0){
      Int_t maxbar = (Int_t)T->bb_hodotdc_clus_id[0];
      hDiff[maxbar]->Fill((T->bb_tr_y[0] + hodo_dist * T->bb_tr_ph[0]), 0.5*T->bb_hodotdc_clus_tdiff[0] ); // note th 1/2
    
      // ----------------------------------------------------------------------------------------------------------------------
      // Cluster and bar timing histograms :
      // ----------------------------------------------------------------------------------------------------------------------
	
      
      // Look for:
      // - 1 cluster
      // - Main cluster has size 2
      // - Main bar in cluster is between bar number 40 and 50 (inclusive)
      // - Bars in cluster no more than 2 apart
      Int_t bardiff = TMath::Abs(T->bb_hodotdc_clus_bar_tdc_id[0] - T->bb_hodotdc_clus_bar_tdc_id[1]);
      if(T->bb_hodotdc_nclus == 1 && T->bb_hodotdc_clus_size[0] == 2 && T->bb_hodotdc_clus_id[0] >= 40 && T->bb_hodotdc_clus_id[0] <= 50 && bardiff <= 2){
	//if(T->bb_hodotdc_nclus == 1 && T->bb_hodotdc_clus_size[0] == 2 && T->bb_hodotdc_clus_id[0] == 42 && bardiff <= 2){
	hclust_tavg->Fill(T->bb_hodotdc_clus_tmean[0]);
	hclust_tdiff->Fill(T->bb_hodotdc_clus_tdiff[0]);
	hbar_main_tavg->Fill(T->bb_hodotdc_clus_bar_tdc_meantime[0]);
	hbar_scndry_tavg->Fill(T->bb_hodotdc_clus_bar_tdc_meantime[1]);
	hbar_main_tdiff->Fill(T->bb_hodotdc_clus_bar_tdc_timediff[0]);
	hbar_scndry_tdiff->Fill(T->bb_hodotdc_clus_bar_tdc_timediff[1]);
      }
      /*
      // ----------------------------------------------------------------------------------------------------------------------
      // PMT timing histograms :
      // ----------------------------------------------------------------------------------------------------------------------
	
      // For now, looking at bars 40-50, irrespective of clustering
      // Bar info. arrays are ordered by bar number; elem [0] is the lowest number -> want bar_id[0] to be >= 40
      // Also want bar_id[0] to be !> 49; if it is, then elem. [1+] will correspond to bars higher than 50
      //if(T->bb_hodotdc_bar_tdc_id[0] < 41 || T->bb_hodotdc_bar_tdc_id[0] > 42) continue; // Bar 42 only
      if(T->bb_hodotdc_bar_tdc_id[0] < 40 || T->bb_hodotdc_bar_tdc_id[0] > 49) continue; // Bars 40-50

      // Want adjacent bars
      if((T->bb_hodotdc_bar_tdc_id[1] - T->bb_hodotdc_bar_tdc_id[0]) > 1) continue;
	
      // Want bars to within 2-bar cluster
      if(T->bb_hodotdc_clus_id[0] < 40 || T->bb_hodotdc_clus_id[0] > 50) continue;
      hpmtL_tavg->Fill((T->bb_hodotdc_bar_tdc_L_le[1]+T->bb_hodotdc_bar_tdc_L_le[0])/2);
      hpmtL_tdiff->Fill(T->bb_hodotdc_bar_tdc_L_le[1]-T->bb_hodotdc_bar_tdc_L_le[0]);
      hpmtR_tavg->Fill((T->bb_hodotdc_bar_tdc_R_le[1]+T->bb_hodotdc_bar_tdc_R_le[0])/2);
      hpmtR_tdiff->Fill(T->bb_hodotdc_bar_tdc_R_le[1]-T->bb_hodotdc_bar_tdc_R_le[0]);
      hpmtL_tavg_TW->Fill((T->bb_hodotdc_bar_tdc_L_leW[1]+T->bb_hodotdc_bar_tdc_L_leW[0])/2);
      hpmtL_tdiff_TW->Fill(T->bb_hodotdc_bar_tdc_L_leW[1]-T->bb_hodotdc_bar_tdc_L_leW[0]);
      hpmtR_tavg_TW->Fill((T->bb_hodotdc_bar_tdc_R_leW[1]+T->bb_hodotdc_bar_tdc_R_leW[0])/2);
      hpmtR_tdiff_TW->Fill(T->bb_hodotdc_bar_tdc_R_leW[1]-T->bb_hodotdc_bar_tdc_R_leW[0]);
    }
*/
    }
  }
 
  // Fit hDiff and fill param histos
  
  TF1 *f1 = new TF1("f1","[0]+[1]*x",-0.25,0.25);
  f1->SetLineColor(kRed);
  
  Double_t td0[nBarsTDC];
  Double_t vsc[nBarsTDC];
  
  fstream tdfile;
  tdfile.open("../Results/tdifcalib.txt",ios::out);
  fstream vsfile;
  vsfile.open("../Results/vscintcalib.txt",ios::out);
  
  Double_t vscint_av = 0.0;
  Double_t tdiff_av = 0.0;
  Int_t goodfit = 0;
  Double_t tdiff_default = -0.838;
  Double_t vscint_default = 0.179;
  
  for(Int_t i=0; i<nBarsTDC; i++) {
    hDiff[i]->Fit(f1,"Q");
    td0[i] = 2*f1->GetParameter(0);
    vsc[i] = -1./f1->GetParameter(1);
    
    htd0->Fill(i+1, td0[i]);
    hvsc->Fill(i+1, vsc[i]);
  
    if(fabs(vsc[i] - vscint_default) > 0.06){
      htd0_post->Fill(i+1, tdiff_default);
      hvsc_post->Fill(i+1, vscint_default);
      tdfile << tdiff_default << endl;
      vsfile << vscint_default << endl;
  }
    else{
      htd0_post->Fill(i+1, td0[i]);
      hvsc_post->Fill(i+1, vsc[i]);
      tdfile << td0[i] << endl;
      vsfile << vsc[i] << endl;
      goodfit++;
      vscint_av += vsc[i];      
      tdiff_av += td0[i];
    }
  }

  cout << vscint_av/(1.0*goodfit) << "\t" << tdiff_av/(1.0*goodfit) << endl;
  tdfile.close();
  vsfile.close();
  exit(0);

  //TFile *fPlots = new TFile("$OUT_DIR/Plots_standalone.root", "RECREATE"); // When testing, files go to /scratch/
  TFile *fPlots = new TFile(sFileOut, "RECREATE"); // When testing, files go to /scratch/
  cout<<"Writing to file: "<<fPlots->GetName()<<endl;
  
  // Parameter histos
  htd0->Write();
  htd0_post->Write();
  hvsc->Write();
  hvsc_post->Write();
  // Cluster level timing
  hclust_tavg->Write();
  hclust_tdiff->Write();
  // Bar level timing
  hbar_main_tavg->Write();
  hbar_main_tdiff->Write();
  hbar_scndry_tavg->Write();
  hbar_scndry_tdiff->Write();
  // PMT level timing
  hpmtL_tavg->Write();
  hpmtL_tdiff->Write();
  hpmtR_tavg->Write();
  hpmtR_tdiff->Write();
  hpmtL_tavg_TW->Write();
  hpmtL_tdiff_TW->Write();
  hpmtR_tavg_TW->Write();
  hpmtR_tdiff_TW->Write();
  
  // y_tgt vs t_diff histos
  TH1D* hSliceMeanSigma = new TH1D("hSliceMeanSigma",";Bar no.;<#sigma> [ns]",90,1,90);

  TString sHistName, sSlices;
  TObjArray aSlices;
  for(Int_t i=0; i<nBarsTDC; i++){
    sHistName = "Bar " + to_string(i);
    hDiff[i]->SetTitle(sHistName);      
    hDiff[i]->Write();
    
    sSlices = (TString)hDiff[i]->GetName() + "_2";

    //hDiff[i]->FitSlicesY(0,0,-1,0,"QNR",&aSlices);
    //TFitResultPtr vals = (TH1D*)aSlices[2]->Fit("pol0","s");
    
    hDiff[i]->FitSlicesY();
    TH1D* h2 = (TH1D*)fPlots->Get(sSlices);
    TFitResultPtr vals = h2->Fit("pol0","SQ0");

    // Make sure fit worked before trying to read parameters
    if(vals == -1) continue;
    else{ 
      hSliceMeanSigma->SetBinContent(i+1, vals->Parameter(0));
    }
  }
  hSliceMeanSigma->Write();

  // TGraphs of database parameters
  
TGraph* g_vsc = new TGraph(Form("../Results/vscint_%i.txt",kin_no),"%lg \t %lg","");
  g_vsc->GetXaxis()->SetTitle("Bar no.");
  g_vsc->GetYaxis()->SetTitle("v_{sc} [m/ns]");
  g_vsc->SetMarkerColor(kRed);
  g_vsc->SetMarkerStyle(kStar);
  //g_vsc->SetLineColor(0);
  g_vsc->SetMarkerColor(kBlue);
  g_vsc->SetMarkerStyle(21);
  g_vsc->Write();

  TGraph* g_tdo = new TGraph(Form("../Results/tdiff_%i.txt",kin_no),"%lg \t %lg","");
  g_tdo->GetXaxis()->SetTitle("Bar no.");
  g_tdo->GetYaxis()->SetTitle("t_{diff} offset [ns]");
  g_tdo->SetMarkerColor(kRed);
  g_tdo->SetMarkerStyle(kStar);
  //g_tdo->SetLineColor(0);
  g_tdo->SetMarkerColor(kBlue);
  g_tdo->SetMarkerStyle(21);
  g_tdo->Write();
  
  // Plot to canvases
  // 1. Parameters of fits to 2D histos
  if(PlotParam){
    TCanvas* c1 = new TCanvas("c1","",1200,800);
    c1->SetFillColor(0);
    gStyle->SetOptStat(0);
    c1->Divide(1,2);
     
    c1->cd(1);
    htd0_post->SetLineColor(0);
    htd0_post->SetMarkerColor(kRed);
    htd0_post->SetMarkerStyle(20);
    htd0_post->Draw();
    g_tdo->Draw("psame");
    c1->cd(2);
    hvsc_post->SetLineColor(0);
    hvsc_post->SetMarkerColor(kRed);
    hvsc_post->SetMarkerStyle(20);
    hvsc_post->Draw();
    g_vsc->Draw("psame");
    
    c1->Print("hodo_barparam.pdf");
  }

  TLatex* tex;
  TLatex* tex_tw;
  
  TFitResultPtr fit_noTW;
  TFitResultPtr fit_TW;
  // 2. PMT-level information (right and left, with and without time walk correction)
  if(PlotPMT){
    TCanvas* c2 = new TCanvas("c2","",1200,800);
    c2->SetFillColor(0);
    c2->Divide(2,1);
    
    c2->cd(1);
    hpmtL_tavg->Draw();
    hpmtL_tavg_TW->SetLineColor(2);
    hpmtL_tavg_TW->Draw("same");
    c2->cd(2);
    hpmtL_tdiff_TW->SetLineColor(2);
    hpmtL_tdiff_TW->Draw();
    hpmtL_tdiff->Draw("same");
    
    fit_noTW = hpmtL_tdiff->Fit("gaus","SQ0");
    fit_TW = hpmtL_tdiff_TW->Fit("gaus","SQ0");
    //tex = new TLatex(0.15, 0.85, Form("No t.w. corr., #sigma = %3.2f ns",fit_noTW->Parameter(2)));
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(4);
    tex->SetTextSize(0.05);
    tex->Draw();
    //tex_tw = new TLatex(0.15, 0.8, Form("With t.w. corr., #sigma = %3.2f ns",fit_TW->Parameter(2)));
    tex_tw->SetNDC(1);
    tex_tw->SetTextFont(42);
    tex_tw->SetTextColor(2);
    tex_tw->SetTextSize(0.05);
    tex_tw->Draw();
    
    TCanvas* c3 = new TCanvas("c3","",1200,800);
    c3->SetFillColor(0);
    c3->Divide(2,1);
    
    c3->cd(1);
    hpmtR_tavg->Draw();
    hpmtR_tavg_TW->SetLineColor(2);
    hpmtR_tavg_TW->Draw("same");
    c3->cd(2);
    hpmtR_tdiff_TW->SetLineColor(2);
    hpmtR_tdiff_TW->Draw();
    hpmtR_tdiff->Draw("same");

    fit_noTW = hpmtR_tdiff->Fit("gaus","SQ0");
    fit_TW = hpmtR_tdiff_TW->Fit("gaus","SQ0");
    tex = new TLatex(0.15, 0.85, Form("No t.w. corr., #sigma = %3.2f ns",fit_noTW->Parameter(2)));
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(4);
    tex->SetTextSize(0.05);
    tex->Draw();
    tex_tw = new TLatex(0.15, 0.8, Form("With t.w. corr., #sigma = %3.2f ns",fit_TW->Parameter(2)));
    tex_tw->SetNDC(1);
    tex_tw->SetTextFont(42);
    tex_tw->SetTextColor(2);
    tex_tw->SetTextSize(0.05);
    tex_tw->Draw();

    c2->Print("hodo_PMTL.pdf");
    c3->Print("hodo_PMTR.pdf");
  }

  TLatex* tex_eq;
  TLatex* tex_mu;
  TLatex* tex_sig;

  TFitResultPtr vals_mu;
  TFitResultPtr vals_sigma;
  
  // 3. Plot 2D histos for 3 bars: low in the stack, mid-stack and high in the stack, alongside FitSliceY parameters
  if(PlotBars){
    // Low bar; defult = 25 
    // Prep work before plotting

    // Extract already existing fit slices for low bar
    sSlices = (TString)hDiff[25]->GetName() + "_0";
    TH1D* hlow_0 = (TH1D*)fPlots->Get(sSlices)->Clone("hlow_0");
    sSlices = (TString)hDiff[25]->GetName() + "_1";
    TH1D* hlow_1 = (TH1D*)fPlots->Get(sSlices)->Clone("hlow_1");
    sSlices = (TString)hDiff[25]->GetName() + "_2";
    TH1D* hlow_2 = (TH1D*)fPlots->Get(sSlices)->Clone("hlow_2");
    
    // Plotting
    TCanvas* c4 = new TCanvas("c4","",1200,800);
    c4->SetFillColor(0);
    c4->Divide(2,2);
   
    c4->cd(1);
    hDiff[25]->Draw("colz");
    hDiff[25]->Fit(f1,"Q");
    tex_eq = new TLatex(0.15, 0.8, Form("y = %3.2f x + %3.2f",f1->GetParameter(1),f1->GetParameter(0)));
    tex_eq->SetNDC(1);
    tex_eq->SetTextFont(42);
    tex_eq->SetTextColor(1);
    tex_eq->SetTextSize(0.05);
    tex_eq->Draw();
    c4->cd(2);
    hlow_0->Draw();
    c4->cd(3);
    hlow_1->Draw();
    vals_mu = hlow_1->Fit("pol1","SQ");
    tex_mu = new TLatex(0.15, 0.8, Form("y = %3.2f x + %3.2f",vals_mu->Parameter(1),vals_mu->Parameter(0)));
    tex_mu->SetNDC(1);
    tex_mu->SetTextFont(42);
    tex_mu->SetTextColor(1);
    tex_mu->SetTextSize(0.05);
    tex_mu->Draw();
    c4->cd(4);
    hlow_2->Draw();
    vals_sigma = hlow_2->Fit("pol0","SQ");
    tex_sig = new TLatex(0.15, 0.8, Form("Mean resoln. = %3.2f ns",vals_sigma->Parameter(0)));
    tex_sig->SetNDC(1);
    tex_sig->SetTextFont(42);
    tex_sig->SetTextColor(1);
    tex_sig->SetTextSize(0.05);
    tex_sig->Draw();

    // Mid bar; default = 50
    // Prep. work before plotting
   
    // Extract already existing fit slices for mid bar
    sSlices = (TString)hDiff[50]->GetName() + "_0";
    TH1D* hmid_0 = (TH1D*)fPlots->Get(sSlices)->Clone("hmid_0");
    sSlices = (TString)hDiff[50]->GetName() + "_1";
    TH1D* hmid_1 = (TH1D*)fPlots->Get(sSlices)->Clone("hmid_1");
    sSlices = (TString)hDiff[50]->GetName() + "_2";
    TH1D* hmid_2 = (TH1D*)fPlots->Get(sSlices)->Clone("hmid_2");

    // Plotting
    TCanvas* c5 = new TCanvas("c5","",1200,800);
    c5->SetFillColor(0);
    c5->Divide(2,2);

    c5->cd(1);
    hDiff[50]->Fit(f1,"Q");
    tex_eq = new TLatex(0.15, 0.8, Form("y = %3.2f x + %3.2f",f1->GetParameter(1),f1->GetParameter(0)));
    tex_eq->SetNDC(1);
    tex_eq->SetTextFont(42);
    tex_eq->SetTextColor(1);
    tex_eq->SetTextSize(0.05);
    hDiff[50]->Draw("colz");
    tex_eq->Draw();
    c5->cd(2);
    hmid_0->Draw();
    c5->cd(3);
    hmid_1->Draw();
    vals_mu = hmid_1->Fit("pol1","SQ");
    tex_mu = new TLatex(0.15, 0.8, Form("y = %3.2f x + %3.2f",vals_mu->Parameter(1),vals_mu->Parameter(0)));
    tex_mu->SetNDC(1);
    tex_mu->SetTextFont(42);
    tex_mu->SetTextColor(1);
    tex_mu->SetTextSize(0.05);
    tex_mu->Draw();
    c5->cd(4);
    hmid_2->Draw();
    vals_sigma = hmid_2->Fit("pol0","SQ");
    tex_sig = new TLatex(0.15, 0.8, Form("Mean resoln. = %3.2f ns",vals_sigma->Parameter(0)));
    tex_sig->SetNDC(1);
    tex_sig->SetTextFont(42);
    tex_sig->SetTextColor(1);
    tex_sig->SetTextSize(0.05);
    tex_sig->Draw();

    // High bar; default = 75
    // Prep work before plotting
    
    // Extract already existing fit slices for mid bar
    sSlices = (TString)hDiff[75]->GetName() + "_0";
    TH1D* h_hi_0 = (TH1D*)fPlots->Get(sSlices)->Clone("hmid_0");
    sSlices = (TString)hDiff[75]->GetName() + "_1";
    TH1D* h_hi_1 = (TH1D*)fPlots->Get(sSlices)->Clone("hmid_1");
    sSlices = (TString)hDiff[75]->GetName() + "_2";
    TH1D* h_hi_2 = (TH1D*)fPlots->Get(sSlices)->Clone("hmid_2");
    
    // Plotting
    TCanvas* c6 = new TCanvas("c6","",1200,800);
    c6->SetFillColor(0);
    c6->Divide(2,2);
    
    c6->cd(1);
    hDiff[75]->Draw("colz");
    hDiff[75]->Fit(f1,"Q");
    tex_eq = new TLatex(0.15, 0.8, Form("y = %3.2f x + %3.2f",f1->GetParameter(1),f1->GetParameter(0)));
    tex_eq->SetNDC(1);
    tex_eq->SetTextFont(42);
    tex_eq->SetTextColor(1);
    tex_eq->SetTextSize(0.05);
    tex_eq->Draw();
    c6->cd(2);
    h_hi_0->Draw();
    c6->cd(3);
    h_hi_1->Draw();
    vals_mu = h_hi_1->Fit("pol1","SQ");
    tex_mu = new TLatex(0.15, 0.8, Form("y = %3.2f x + %3.2f",vals_mu->Parameter(1),vals_mu->Parameter(0)));
    tex_mu->SetNDC(1);
    tex_mu->SetTextFont(42);
    tex_mu->SetTextColor(1);
    tex_mu->SetTextSize(0.05);
    tex_mu->Draw();
    c6->cd(4);
    h_hi_2->Draw();
    vals_sigma = h_hi_2->Fit("pol0","SQ");
    tex_sig = new TLatex(0.15, 0.8, Form("Mean resoln. = %3.2f ns",vals_sigma->Parameter(0)));
    tex_sig->SetNDC(1);
    tex_sig->SetTextFont(42);
    tex_sig->SetTextColor(1);
    tex_sig->SetTextSize(0.05);
    tex_sig->Draw();

    c4->Print("hodo_BarLo.pdf");
    c5->Print("hodo_BarMid.pdf");
    c6->Print("hodo_BarHi.pdf");
  }

  TCanvas* c7 = new TCanvas("c7","",1200,800);
  c7->SetFillColor(0);
  
  hSliceMeanSigma->Draw();
  c7->Print("hodo_SliceMeanSigma.pdf");

  gSystem->Exec("pdfunite hodo*.pdf HodoCalib.pdf");
  gSystem->Exec("rm hodo_*.pdf");

  return 0;
  
}
