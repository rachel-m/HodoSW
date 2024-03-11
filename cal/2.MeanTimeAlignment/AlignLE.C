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
#include <TStyle.h>
#include <TLatex.h>

#include <TTreeReader.h>
#include <TTreeReaderArray.h>

const Int_t nTDC = 180;
const Int_t nBarsTDC = 90;
const Int_t nBarsADC = 32;
const Double_t ADCCUT = 150.;//100.0;

using namespace std;

double TimeWalk(double time, double tot, double par0, double par1)
{
  double tcorr = time - (par0*tot + par1);
  return tcorr;
}

double Align(double time, double offset){
  double tcorr = time - offset;
  return tcorr;
}

double PathLength(double time, double mom, double par0, double par1){
  double tcorr = time - (par0*mom + par1);
  return tcorr;
}

double GemMatch(double tdiff){
  //insert code later
  return tdiff;
}

double AlignRF(double rftime, double time, double bunch = 4.008){
  //time = fmod(rftime-time,bunch);
  time = fmod(time,bunch);
  //time = fmod(time1+bunch,bunch);
  return time;
}


void FitProcedure(TH1D *histo, Double_t *pars, Double_t min=-1, Double_t max=1){
  cout << histo->GetName() << endl;
  TLatex *tex = new TLatex();
  tex->SetNDC();

  double gausmax = histo->GetMaximum();
  int maxbin = histo->GetMaximumBin();
  double gausmean = histo->GetBinCenter(maxbin);
  min = gausmean + min;
  max = gausmean + max;
  //cout << min << " " << max << endl;
  ///  TF1 *gausfit = new TF1("gausfit","pol0(0)+gaus(1)",min,max);
  TF1 *gausfit = new TF1("gausfit","gaus",min,max);

  //gausfit->SetParameter(0,gausmax/10.); //empirically noted that the background is typically 10% the peak height
  gausfit->SetParameter(1,gausmax); //set the starting max as the maximum 
  gausfit->SetParameter(2,gausmean); //set the starting mean as the x position of the maximum
  //gausfit->SetParameter(3,5); //empirically found the widths to be 3-5ns, a fair enough starting point
  
  //gausfit->SetParLimits(2,min,max); //the real means should not be outside these ranges
  //gausfit->SetParLimits(3,0.5,5); //anything above 10ns width is just stats in bad bars
  
  histo->Fit("gausfit","Q","",min,max);
  //pars[0] = gausfit->GetParameter(0);
  pars[1] = gausfit->GetParameter(0);
  pars[2] = gausfit->GetParameter(1);
  pars[3] = gausfit->GetParameter(2);
  histo->Draw();
  tex->DrawLatex(0.25,0.80,Form("#mu = %.2f",pars[2]));
  tex->DrawLatex(0.25,0.75,Form("#sigma = %.2f",pars[3]));
  
}


//as of yet, unused function
void DrawProcedure(TH1D *h1,TH1D *h2,TH1D *h3,TH1D *h4,TH1D *h5,TH1D *h6){

  TCanvas *c = new TCanvas();
  c->Divide(2,2);
  Double_t pars[4];
  
  //raw
  c->cd(1);
  FitProcedure(h1,pars);

  //after timewalk
  c->cd(2);
  FitProcedure(h2,pars);

  //after alignment
  c->cd(3);
  FitProcedure(h3,pars);

  //after gem matching
  c->cd(4);
  FitProcedure(h4,pars);
  
  //after g4sbs path length correction
  c->cd(5);
  FitProcedure(h5,pars);

  //after alignment to RF
  c->cd(6);
  FitProcedure(h6,pars);

  c->Print("temp.pdf");
  
}


void AlignLE(Int_t nevents=-1, Int_t cosmic=0, Int_t DoFit=1, Int_t CutADC=0, Double_t Fitmin=-5., Double_t Fitmax=5.)
{
  //InFile is the input file without absolute path and without .root suffix
  //nevents is how many events to analyse, -1 for all
  //DoFit==1 means fit tot v le and write out txt file of results
  //CutADC==1 will demand an ADC hit above a specified threshold (ADCCUT)
  
  //To execute
  //root -l
  //.L AlignLE.C+
  //AlignLE("filename", -1, 0, 1, 0, -999., -999.)

  
  //Get data from tree
  TChain *T = new TChain("T");
  TString ROOTFILE_DIR = "/volatile/halla/sbs/gpenman/GEN_REPLAY/rootfiles/Pass1/";
  T->Add(ROOTFILE_DIR + "/SBS100/*.root");
  T->Add(ROOTFILE_DIR + "/SBS30/*.root");
  TString ANALYSED_DIR = "./";
  
  TTreeReader rd (T);
  //bar member
  TTreeReaderValue<Int_t> Ndata_bb_hodotdc_bar_tdc_id = {rd, "Ndata.bb.hodotdc.bar.tdc.id"};
  TTreeReaderArray<Double_t> bb_hodotdc_bar_tdc_id = {rd, "bb.hodotdc.bar.tdc.id"};
  TTreeReaderArray<Double_t> bb_hodotdc_bar_tdc_meantime = {rd, "bb.hodotdc.bar.tdc.meantime"};
  //TTreeReaderArray<Double_t> bb_hodotdc_bar_tdc_timediff = {rd, "bb.hodotdc.bar.tdc.timediff"};
  //TTreeReaderArray<Double_t> bb_hodotdc_bar_tdc_timehitpos = {rd, "bb.hodotdc.bar.tdc.timehitpos"};
  //TTreeReaderArray<Double_t> bb_hodotdc_bar_tdc_vpos = {rd, "bb.hodotdc.bar.tdc.vpos"};

  //bar L/R variables
  TTreeReaderArray<Double_t> bb_hodotdc_bar_tdc_L_le = {rd, "bb.hodotdc.bar.tdc.L.le"};
  //TTreeReaderArray<Double_t> bb_hodotdc_bar_tdc_L_leW = {rd, "bb.hodotdc.bar.tdc.L.leW"};
  TTreeReaderArray<Double_t> bb_hodotdc_bar_tdc_L_te = {rd, "bb.hodotdc.bar.tdc.L.te"};
  //TTreeReaderArray<Double_t> bb_hodotdc_bar_tdc_L_teW = {rd, "bb.hodotdc.bar.tdc.L.teW"};
  TTreeReaderArray<Double_t> bb_hodotdc_bar_tdc_L_tot = {rd, "bb.hodotdc.bar.tdc.L.tot"};
  //TTreeReaderArray<Double_t> bb_hodotdc_bar_tdc_L_totW = {rd, "bb.hodotdc.bar.tdc.L.totW"};
  TTreeReaderArray<Double_t> bb_hodotdc_bar_tdc_R_le = {rd, "bb.hodotdc.bar.tdc.R.le"};
  //TTreeReaderArray<Double_t> bb_hodotdc_bar_tdc_R_leW = {rd, "bb.hodotdc.bar.tdc.R.leW"};
  TTreeReaderArray<Double_t> bb_hodotdc_bar_tdc_R_te = {rd, "bb.hodotdc.bar.tdc.R.te"};
  //TTreeReaderArray<Double_t> bb_hodotdc_bar_tdc_R_teW = {rd, "bb.hodotdc.bar.tdc.R.teW"};
  TTreeReaderArray<Double_t> bb_hodotdc_bar_tdc_R_tot = {rd, "bb.hodotdc.bar.tdc.R.tot"};
  //TTreeReaderArray<Double_t> bb_hodotdc_bar_tdc_R_totW = {rd, "bb.hodotdc.bar.tdc.R.totW"};
  
  //main cluster bars
  TTreeReaderValue<Int_t> Ndata_bb_hodotdc_clus_bar_tdc_id = {rd, "Ndata.bb.hodotdc.clus.bar.tdc.id"};
  TTreeReaderArray<Double_t> bb_hodotdc_clus_bar_tdc_id = {rd, "bb.hodotdc.clus.bar.tdc.id"};
  TTreeReaderArray<Double_t> bb_hodotdc_clus_bar_tdc_itrack = {rd, "bb.hodotdc.clus.bar.tdc.itrack"};
  TTreeReaderArray<Double_t> bb_hodotdc_clus_bar_tdc_meantime = {rd, "bb.hodotdc.clus.bar.tdc.meantime"};
  TTreeReaderArray<Double_t> bb_hodotdc_clus_bar_tdc_meantot = {rd, "bb.hodotdc.clus.bar.tdc.meantot"};
  TTreeReaderArray<Double_t> bb_hodotdc_clus_bar_tdc_timediff = {rd, "bb.hodotdc.clus.bar.tdc.timediff"};
  TTreeReaderArray<Double_t> bb_hodotdc_clus_bar_tdc_timehitpos = {rd, "bb.hodotdc.clus.bar.tdc.timehitpos"};
  TTreeReaderArray<Double_t> bb_hodotdc_clus_bar_tdc_vpos = {rd, "bb.hodotdc.clus.bar.tdc.vpos"};
  
  //all cluster main bar
  TTreeReaderValue<Int_t> Ndata_bb_hodotdc_clus_id = {rd, "Ndata.bb.hodotdc.clus.id"};
  //TTreeReaderArray<Double_t> bb_hodotdc_clus_id = {rd, "bb.hodotdc.clus.id"};
  //TTreeReaderArray<Double_t> bb_hodotdc_clus_size = {rd, "bb.hodotdc.clus.size"};
  //TTreeReaderArray<Double_t> bb_hodotdc_clus_tdiff = {rd, "bb.hodotdc.clus.tdiff"};
  //TTreeReaderArray<Double_t> bb_hodotdc_clus_tmean = {rd, "bb.hodotdc.clus.tmean"};
  //TTreeReaderArray<Double_t> bb_hodotdc_clus_totmean = {rd, "bb.hodotdc.clus.totmean"};
  //TTreeReaderArray<Double_t> bb_hodotdc_clus_trackindex = {rd, "bb.hodotdc.clus.trackindex"};
  //TTreeReaderArray<Double_t> bb_hodotdc_clus_xmean = {rd, "bb.hodotdc.clus.xmean"};
  //TTreeReaderArray<Double_t> bb_hodotdc_clus_ymean = {rd, "bb.hodotdc.clus.ymean"};
  
  //all cluster all bar
  //this variable does not exist yet
  
  
  TTreeReaderValue<Double_t> bb_tr_n = {rd, "bb.tr.n"};
  TTreeReaderArray<Double_t> bb_tr_p = {rd, "bb.tr.p"};
  TTreeReaderValue<Double_t> bb_ps_e = {rd, "bb.ps.e"};
   
  TTreeReaderValue<Int_t> Ndata_bb_tdctrig_tdc = {rd, "Ndata.bb.tdctrig.tdc"};
  TTreeReaderArray<Double_t> bb_tdctrig_tdc = {rd, "bb.tdctrig.tdc"};
  TTreeReaderValue<Int_t> Ndata_bb_tdctrig_tdcelemID = {rd, "Ndata.bb.tdctrig.tdcelemID"};
  TTreeReaderArray<Double_t> bb_tdctrig_tdcelemID = {rd, "bb.tdctrig.tdcelemID"};
   
  //Check no of events
  Int_t Nev = T->GetEntries();
  if (Nev==0)
    cout << "Tree empty. Check Paths! Exiting!" << endl;
  else
    cout << "N entries in tree is " << Nev << endl;
  
  Int_t NEventsAnalysis;
  if(nevents==-1) 
    NEventsAnalysis = Nev;
  else 
    NEventsAnalysis = nevents;
  
  cout << "Running analysis for " << NEventsAnalysis << " events" << endl;

  
  //read in TWmaps from FitTimeWalk.C output
  fstream twfile;
  twfile.open(ANALYSED_DIR+"TWFits.txt",ios::in);
  if(!twfile.is_open()){
    cout << "TW fit file not found. Exiting!" << endl;
    exit(1);
  }
  double Lpar0[nBarsTDC], Rpar0[nBarsTDC], Lpar1[nBarsTDC], Rpar1[nBarsTDC];
  
  int iterline=0;
  string line;
  while(getline(twfile,line)){
    if (iterline >= 1 && iterline <= 90)     
      Lpar0[iterline-1] = stod(line);
    else if (iterline >= 91 && iterline <= 180)
      Rpar0[iterline-91] = stod(line);
    else if (iterline >= 182 && iterline <= 271)
      Lpar1[iterline-182] = stod(line);
    else if (iterline >= 272)
      Rpar1[iterline-272] = stod(line);
    iterline++;
  }
  twfile.close();
  
  //read in fitted means from this scripts output
  fstream meanfile;
  double Lmean[nBarsTDC] = {0};
  double Rmean[nBarsTDC] = {0};
  meanfile.open(ANALYSED_DIR+"AlignedLE.txt",ios::in);
  if(!meanfile.is_open()){
    cout << "AlignedLE.txt file not found. Generating post timewalk realignments for the first time!" << endl;
  }
  else{
    //cout << "AlignedLE.txt found!" << endl;
    iterline=0;
    while(getline(meanfile,line)){
      if (iterline >= 1 && iterline <=90){
	Lmean[iterline-1] = stod(line);
      }else if (iterline >= 91)
	Rmean[iterline-91] = stod(line);
      iterline++;
    }
  }
  
  //Histogram Declarations
  // number of histo bins
  Int_t NTotBins = 100;//200;
  Double_t TotBinLow = 0.;
  Double_t TotBinHigh = 30;//400.;
  Int_t NLEBins = 100;
  Double_t LEBinLow = -20.0;//-800.0;//-100.;
  Double_t LEBinHigh = 20.0;//100.;
  Double_t ClusLow = -5.0;
  Double_t ClusHigh = 5.0;
  
  TH1D* hLE = new TH1D("hLE","",NLEBins,LEBinLow,LEBinHigh);
  TH1D* hLEW = new TH1D("hLEW","",NLEBins,LEBinLow,LEBinHigh);
  TH1D* hLEWc = new TH1D("hLEWc","",NLEBins,LEBinLow,LEBinHigh);
  TH1D* hLERF = new TH1D("hLERF","",NLEBins,LEBinLow,LEBinHigh);
 
  TH1D* hLle[nBarsTDC];
  TH1D* hRle[nBarsTDC];
  
  TH1D* hLleW[nBarsTDC];
  TH1D* hRleW[nBarsTDC];

  TH1D* hLleWc[nBarsTDC];
  TH1D* hRleWc[nBarsTDC];

  TH1D* hclus_t = new TH1D("hclus_t","",NLEBins,ClusLow,ClusHigh);
  TH1D* hclus_tW = new TH1D("hclus_tW","",NLEBins,ClusLow,ClusHigh);
  TH1D* hclus_tWc = new TH1D("hclus_tWc","",NLEBins,ClusLow,ClusHigh);
  TH1D* hclus_tRF = new TH1D("hclus_tRF","",NLEBins,ClusLow,ClusHigh);
  
  TH1D* hclus_tcorr[nBarsTDC];
  TH1D* hclus_tcorrW[nBarsTDC];
  TH1D* hclus_tcorrWc[nBarsTDC];
  TH1D* hclus_tcorrRF[nBarsTDC];
  
  //histograms
  for (int i=0; i<nBarsTDC; i++){
    hLle[i] = new TH1D (Form("hLle_%d",i),"",NLEBins,LEBinLow,LEBinHigh);
    hRle[i] = new TH1D (Form("hRle_%d",i),"",NLEBins,LEBinLow,LEBinHigh);
    hLleW[i] = new TH1D (Form("hLleW_%d",i),"",NLEBins,LEBinLow,LEBinHigh);
    hRleW[i] = new TH1D (Form("hRleW_%d",i),"",NLEBins,LEBinLow,LEBinHigh);
    hLleWc[i] = new TH1D (Form("hLleWc_%d",i),"",NLEBins,LEBinLow,LEBinHigh);
    hRleWc[i] = new TH1D (Form("hRleWc_%d",i),"",NLEBins,LEBinLow,LEBinHigh);
    
    hclus_tcorr[i] = new TH1D(Form("hclus_tcorr_%d",i),"",NLEBins,ClusLow,ClusHigh);
    hclus_tcorrW[i] = new TH1D(Form("hclus_tcorrW_%d",i),"",NLEBins,ClusLow,ClusHigh);
    hclus_tcorrWc[i] = new TH1D(Form("hclus_tcorrWc_%d",i),"",NLEBins,ClusLow,ClusHigh);
    hclus_tcorrRF[i] = new TH1D(Form("hclus_tcorrRF_%d",i),"",NLEBins,ClusLow,ClusHigh);

  }
  
  //event loop
  for(Int_t ev=0; ev<NEventsAnalysis; ev++){
    
    if(ev%100000==0) cout << ev << " / " << NEventsAnalysis << endl;
    rd.SetEntry(ev);
    

    //very loose elastic electron cut if not cosmic run
    if (!cosmic){
      if(*bb_tr_n <= 0) continue;
      if(*bb_ps_e < 0.2) continue;
      if(bb_tr_p[0] < 2.0) continue;
    }
    
    Int_t NdataTDC = (int)(*Ndata_bb_hodotdc_bar_tdc_id);
    
    if(NdataTDC == 0) continue;
    
    //getting rf and trigger info
    int NtdctrigID = (int)(*Ndata_bb_tdctrig_tdcelemID);
    int Ntdctrig = (int)(*Ndata_bb_tdctrig_tdc);
    //cout << NtdctrigID << " " << Ntdctrig << endl;
    
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
    
    /*
    if(!haveRF){
      badRF++;
      //continue;
    }

    if(!haveTRIG){
      badTRIG++;
      //continue;
    }
    */
    
    if(!haveRF || !haveTRIG) continue;
    
    //getting the coorect array position in the bar array, for the 
    //bars1 and 2 in the main cluster
    Int_t tdcbar1iter=-1;
    Int_t tdcbar2iter=-1;
    for(Int_t tdc=0; tdc<NdataTDC; tdc++){
      Int_t tdcbar = bb_hodotdc_bar_tdc_id[tdc];
    
      double Lle = bb_hodotdc_bar_tdc_L_le[tdc];
      double Rle = bb_hodotdc_bar_tdc_R_le[tdc];
      double Lte = bb_hodotdc_bar_tdc_L_te[tdc];
      double Rte = bb_hodotdc_bar_tdc_R_te[tdc];
      double Ltot = Lte - Lle;
      double Rtot = Rte - Rle;
      if (Lle == 0.00   ||   Rle == 0.00  ||  Lte == 0.00 || Rte == 0.00)
	continue;
      
      //if bar ID == the main bar of the main cluster
      //if bar ID == the second bar of the main cluster
      if (tdcbar == bb_hodotdc_clus_bar_tdc_id[0]) tdcbar1iter = tdc; 
      if (tdcbar == bb_hodotdc_clus_bar_tdc_id[1]) tdcbar2iter = tdc; 
    
      double LleW = TimeWalk(Lle, Ltot, Lpar0[tdcbar], Lpar1[tdcbar]);
      double RleW = TimeWalk(Rle, Rtot, Rpar0[tdcbar], Rpar1[tdcbar]);
      double LleWc = Align(LleW,Lmean[tdcbar]);
      double RleWc = Align(RleW,Rmean[tdcbar]);
      double LleRF = AlignRF(rftime, LleWc);
      double RleRF = AlignRF(rftime, RleWc);
      
      //check for good cosmic bar i.e one neighbouring hit
      if(cosmic){
	if( tdc==0 ){
	  if( bb_hodotdc_bar_tdc_id[tdc+1] != tdcbar+1 )
	    continue;
	}
	else if( tdc==(Int_t)NdataTDC-1 ){
	  if( bb_hodotdc_bar_tdc_id[tdc-1] != tdcbar-1 )
	    continue;
	}
	else{ 
	  if( bb_hodotdc_bar_tdc_id[tdc+1] != tdcbar+1 || bb_hodotdc_bar_tdc_id[tdc-1] != tdcbar-1 )
	    continue;
	}
      }
      if(CutADC==1){
	/*
	  for(Int_t adcbar=0; adcbar<nBarsADC; adcbar++){
	  Int_t bar = ADCBar[adcbar];//adcbarstart+adcbar;
	  if(bar==tdcbar){
	  if(ADCValL[adcbar]>=ADCCUT){
	  hLleW[tdcbar]->Fill(LleW);
	  //hADCL[adcbar]->Fill(ADCValL[adcbar]);
	  }
	  if(ADCValR[adcbar]>=ADCCUT){
	  hRleW[tdcbar]->Fill(RleW);
	  //hADCR[adcbar]->Fill(ADCValR[adcbar]);
	  }
	  }//if bar matches
	  }//adc bar loop
	*/
      }//adc cut
      else if(CutADC!=1){
      
	//fill the "all pmt" histo with both sides values for every bar
	hLE->Fill(Lle);
	hLE->Fill(Rle);
	hLEW->Fill(LleW);
	hLEW->Fill(RleW);
	hLEWc->Fill(LleWc);
	hLEWc->Fill(RleWc);
	
	//fill the bar by bar histos with the specific values.
	hLle[tdcbar]->Fill(Lle);
	hRle[tdcbar]->Fill(Rle);
	hLleW[tdcbar]->Fill(LleW);
	hRleW[tdcbar]->Fill(RleW);
	hLleWc[tdcbar]->Fill(LleWc);
	hRleWc[tdcbar]->Fill(RleWc);
      }//else
    }//tdc bar loop
    int Nclus = (int)(*Ndata_bb_hodotdc_clus_id);
    int clus_size = (int)(*Ndata_bb_hodotdc_clus_bar_tdc_id);
    if( Nclus > 0 && clus_size >= 2){
      //if cluster has atleast 2 bars, do cluster stuff
      Int_t tdcbar = bb_hodotdc_bar_tdc_id[tdcbar1iter];
      Int_t tdcbar2 = bb_hodotdc_bar_tdc_id[tdcbar2iter];
      
      double Lle = bb_hodotdc_bar_tdc_L_le[tdcbar1iter];
      double Rle = bb_hodotdc_bar_tdc_R_le[tdcbar1iter];
      double Lte = bb_hodotdc_bar_tdc_L_te[tdcbar1iter];
      double Rte = bb_hodotdc_bar_tdc_R_te[tdcbar1iter];
      double Ltot = Lte - Lle;
      double Rtot = Rte - Rle;

      double LleW = TimeWalk(Lle, Ltot, Lpar0[tdcbar], Lpar1[tdcbar]);
      double RleW = TimeWalk(Rle, Rtot, Rpar0[tdcbar], Rpar1[tdcbar]);
      double LleWc = Align(LleW,Lmean[tdcbar]);
      double RleWc = Align(RleW,Rmean[tdcbar]);
      double LleRF = AlignRF(rftime, LleWc);
      double RleRF = AlignRF(rftime, RleWc);

      double Lle2 = bb_hodotdc_bar_tdc_L_le[tdcbar2iter];
      double Rle2 = bb_hodotdc_bar_tdc_R_le[tdcbar2iter];
      double Lte2 = bb_hodotdc_bar_tdc_L_te[tdcbar2iter];
      double Rte2 = bb_hodotdc_bar_tdc_R_te[tdcbar2iter];
      double Ltot2 = Lte2 - Lle2;
      double Rtot2 = Rte2 - Rle2;
      
      double Lle2W = TimeWalk(Lle2, Ltot2, Lpar0[tdcbar2], Lpar1[tdcbar2]);
      double Rle2W = TimeWalk(Rle2, Rtot2, Rpar0[tdcbar2], Rpar1[tdcbar2]);
      double Lle2Wc = Align(Lle2W,Lmean[tdcbar2]);
      double Rle2Wc = Align(Rle2W,Rmean[tdcbar2]);
	  
      double tmean_1 = (Lle + Rle)/2; //should be same as clus_bar_tmean[0]
      double tmean_2 = (Lle2 + Rle2)/2; //should be same as clus_bar_tmean[1]
      double tcorr = tmean_1 - tmean_2;
	  
      double tmeanW_1 = (LleW + RleW)/2; 
      double tmeanW_2 = (Lle2W + Rle2W)/2; 
      double tcorrW = tmeanW_1 - tmeanW_2;

      double tmeanWc_1 = (LleWc + RleWc)/2; 
      double tmeanWc_2 = (Lle2Wc + Rle2Wc)/2; 
      double tcorrWc = tmeanWc_1 - tmeanWc_2;
      double tcorrRF = AlignRF(rftime,tcorrWc);
      
      hclus_t->Fill(tcorr);
      hclus_tW->Fill(tcorrW);
      hclus_tWc->Fill(tcorrWc);
      hclus_tRF->Fill(tcorrRF);
      
      hclus_tcorr[tdcbar]->Fill(tcorr);
      hclus_tcorrW[tdcbar]->Fill(tcorrW);
      hclus_tcorrWc[tdcbar]->Fill(tcorrWc);
      hclus_tcorrRF[tdcbar]->Fill(tcorrRF);
    }//cluster if block
    
  }//event loop

  
  //global draw options
  gStyle->SetHistLineWidth(2);
  //gStyle->SetOptTitle(0);
  //gStyle->SetOptStat(0);
   
  TCanvas *cl = new TCanvas();
  TCanvas *cr = new TCanvas();
  
  double BarFitMin = Fitmin;
  double BarFitMax = Fitmax;
  double ClusFitMin = BarFitMin / 4.;
  double ClusFitMax = BarFitMax / 4.;
  cout << ClusFitMin << " " << ClusFitMax << endl;
  double pars[4];
  
  TCanvas *cBars = new TCanvas();
  cBars->Divide(2,2);
  cBars->cd(1);
  FitProcedure(hLE, pars, BarFitMin, BarFitMax);
  cBars->cd(2);
  FitProcedure(hLEW, pars, BarFitMin, BarFitMax);
  cBars->cd(3);
  FitProcedure(hLEWc, pars, BarFitMin, BarFitMax);
  cBars->cd(4);
  FitProcedure(hLERF, pars, BarFitMin, BarFitMax);
  
  cBars->Print("allbars.pdf");
  cBars->Close();
  
  TCanvas *cClus = new TCanvas();
  cClus->Divide(2,2);
  cClus->cd(1);
  FitProcedure(hclus_t, pars, ClusFitMin, ClusFitMax);
  cClus->cd(2);
  FitProcedure(hclus_tW, pars, ClusFitMin, ClusFitMax);
  cClus->cd(3);
  FitProcedure(hclus_tWc, pars, ClusFitMin, ClusFitMax);
  cClus->cd(4);
  FitProcedure(hclus_tRF, pars, ClusFitMin, ClusFitMax);
  cClus->Print("allclus.pdf");
  cClus->Close();
  
  double mean[nTDC];
  double meanW[nTDC];
  double meanWc[nTDC];
  double sig[nTDC];
  double sigW[nTDC];
  double sigWc[nTDC];
  
  double clusmean[nBarsTDC];
  double clusmeanW[nBarsTDC];
  double clusmeanWc[nBarsTDC];
  double clussig[nBarsTDC];
  double clussigW[nBarsTDC];
  double clussigWc[nBarsTDC];
  
  //double bars[nBarsTDC];
  double pmts[nTDC];
  double bars[nBarsTDC];
  
  for (int i=0; i<nBarsTDC; i++){
    pmts[i] = i;
    bars[i] = i;
    pmts[i+nBarsTDC] = i + nBarsTDC;
    
    TCanvas *cClus2 = new TCanvas();
    cClus2->Divide(2,2);
    cClus2->cd(1);
    FitProcedure(hclus_tcorr[i], pars, ClusFitMin, ClusFitMax);
    clusmean[i] = pars[2];
    clussig[i] = pars[3];

    cClus2->cd(2);
    FitProcedure(hclus_tcorrW[i], pars, ClusFitMin, ClusFitMax);
    clusmeanW[i] = pars[2];
    clussigW[i] = pars[3];

    cClus2->cd(3);
    FitProcedure(hclus_tcorrWc[i], pars, ClusFitMin, ClusFitMax);
    clusmeanWc[i] = pars[2];
    clussigWc[i] = pars[3];

    cClus2->Print(Form("clus_%d.pdf",i));
    cClus2->Close();
    
    FitProcedure(hLle[i], pars, BarFitMin, BarFitMax);
    mean[i] = pars[2];
    sig[i] = pars[3];

    FitProcedure(hLleW[i], pars, BarFitMin, BarFitMax);
    meanW[i] = pars[2];
    sigW[i] = pars[3];

    FitProcedure(hLleWc[i], pars, BarFitMin, BarFitMax);
    meanWc[i] = pars[2];
    sigWc[i] = pars[3];

    FitProcedure(hRle[i], pars, BarFitMin, BarFitMax);
    mean[i+90] = pars[2];
    sig[i+90] = pars[3];

    FitProcedure(hRleW[i], pars, BarFitMin, BarFitMax);
    meanW[i+90] = pars[2];
    sigW[i+90] = pars[3];
    
    FitProcedure(hRleWc[i], pars, BarFitMin, BarFitMax);
    meanWc[i+90] = pars[2];
    sigWc[i+90] = pars[3];
    
  }


  //graph the change in means across the bars
  double mean_lo = -5;
  double mean_hi = 5;
  
  TCanvas *cGmeans = new TCanvas();
  cGmeans->Divide(2,2);
  cGmeans->cd(1);
  TGraph *Gmean = new TGraph(nTDC,pmts,mean);
  Gmean->SetTitle("Raw Means; pmt ID; #mu [ns]");
  Gmean->SetMinimum(mean_lo);
  Gmean->SetMaximum(mean_hi);
  Gmean->Draw("AP");
  cGmeans->cd(2);
  TGraph *GmeanW = new TGraph(nTDC,pmts,meanW);
  GmeanW->SetTitle("TW Corrected Means; pmt ID; #mu [ns]");
  GmeanW->SetMinimum(mean_lo);
  GmeanW->SetMaximum(mean_hi);
  GmeanW->Draw("AP");
  cGmeans->cd(3);
  TGraph *GmeanWc = new TGraph(nTDC,pmts,meanWc);
  GmeanWc->SetTitle("TW Corrected + Realigned Means; pmt ID; #mu [ns]");
  GmeanWc->SetMinimum(mean_lo);
  GmeanWc->SetMaximum(mean_hi);
  GmeanWc->Draw("AP");
  cGmeans->Print("means.pdf");
  
  //graph the change in sigma (widths) across the bars
  TCanvas *cGsigs = new TCanvas();
  cGsigs->Divide(2,2);
  cGsigs->cd(1);
  TGraph *Gsig = new TGraph(nTDC,pmts,sig);
  Gsig->SetTitle("Raw Widths; pmt ID; #sigma [ns]");
  Gsig->Draw("AP");
  cGsigs->cd(2);
  TGraph *GsigW = new TGraph(nTDC,pmts,sigW);
  GsigW->SetTitle("TW Corrected Widths; pmt ID; #sigma [ns]");
  GsigW->Draw("AP");
  cGsigs->cd(3);
  TGraph *GsigWc = new TGraph(nTDC,pmts,sigWc);
  GsigWc->SetTitle("TW Corrected + Realigned Widths; pmt ID; #sigma [ns]");
  GsigWc->Draw("AP");
  cGsigs->Print("sigs.pdf");
    
  TCanvas *cGclusmeans = new TCanvas();
  cGclusmeans->Divide(2,2);
  cGclusmeans->cd(1);
  TGraph *Gclusmean = new TGraph(nBarsTDC,bars,clusmean);
  Gclusmean->SetTitle("Raw Clus Means; bar ID; #mu [ns]");
  Gclusmean->SetMinimum(mean_lo);
  Gclusmean->SetMaximum(mean_hi);
  Gclusmean->Draw("AP");
  cGclusmeans->cd(2);
  TGraph *GclusmeanW = new TGraph(nBarsTDC,bars,clusmeanW);
  GclusmeanW->SetTitle("TW Corrected Clus Means; bar ID; #mu [ns]");
  GclusmeanW->SetMinimum(mean_lo);
  GclusmeanW->SetMaximum(mean_hi);
  GclusmeanW->Draw("AP");
  cGclusmeans->cd(3);
  TGraph *GclusmeanWc = new TGraph(nBarsTDC,bars,clusmeanWc);
  GclusmeanWc->SetTitle("TW Corrected + Realigned Clus Means; bar ID; #mu [ns]");
  GclusmeanWc->SetMinimum(mean_lo);
  GclusmeanWc->SetMaximum(mean_hi);
  GclusmeanWc->Draw("AP");
  cGclusmeans->Print("clusmeans.pdf");
  
  //graph the change in sigma (widths) across the bars
  TCanvas *cGclussigs = new TCanvas();
  cGclussigs->Divide(2,2);
  cGclussigs->cd(1);
  TGraph *Gclussig = new TGraph(nBarsTDC,bars,clussig);
  Gclussig->SetTitle("Raw Cluster Widths; bar ID; #sigma [ns]");
  Gclussig->Draw("AP");
  cGclussigs->cd(2);
  TGraph *GclussigW = new TGraph(nBarsTDC,bars,clussigW);
  GclussigW->SetTitle("TW Corrected Cluster Widths; bar ID; #sigma [ns]");
  GclussigW->Draw("AP");
  cGclussigs->cd(3);
  TGraph *GclussigWc = new TGraph(nBarsTDC,bars,clussigWc);
  GclussigWc->SetTitle("TW Corrected + Realigned Cluster Widths; bar ID; #sigma [ns]");
  GclussigWc->Draw("AP");
  cGclussigs->Print("clussigs.pdf");
  
  //draw loop
  for (int i=0; i<6; i++){
    cl->cd(0);
    gPad->Clear();
    cl->Divide(4,4);
    cr->cd(0);
    gPad->Clear();
    cr->Divide(4,4);
     
    for (int j=0; j<16; j++){
      int bar = 16*i + j;
      if (bar >= 90)
	break;
       
      //left
      cl->cd(j+1);
      hLleW[bar]->SetLineColor(kBlack);
      hLleW[bar]->GetXaxis()->SetTitle("Leading Edge [ns]");
      hLleW[bar]->Draw("");
       
      //right
      cr->cd(j+1);
      hRleW[bar]->SetLineColor(kBlack);
      hRleW[bar]->GetXaxis()->SetTitle("Leading Edge [ns]");
      hRleW[bar]->Draw("");
    }

    cl->Print(Form("Left_%i.pdf",i));
    cr->Print(Form("Right_%i.pdf",i));
  }
   
  cl->Close();
  cr->Close();
   
  gSystem->Exec("pdfunite clusmeans.pdf clussigs.pdf allclus.pdf  clus_*.pdf Cluster_Alignment.pdf");
  gSystem->Exec("rm clusmeans.pdf clussigs.pdf allclus.pdf clus_*.pdf");
  gSystem->Exec("pdfunite means.pdf sigs.pdf allbars.pdf Left*.pdf Right*.pdf BarLE_Alignment.pdf");
  gSystem->Exec("rm means.pdf sigs.pdf allbars.pdf Left*.pdf Right*.pdf");
  
  //gSystem->Exec(Form("mv AlignedLE.pdf %s",ANALYSED_DIR.Data()));
  
  ofstream textfile;
  textfile.open(ANALYSED_DIR+"AlignedLE.txt");
  textfile << "LE Align" << endl;
  for (int i=0; i<180; i++){
    //cout << pmts[i] << endl;
    textfile << meanW[i] << endl;
  }
  //for (int i=0; i<90; i++)
  //textfile << rmean[i] << endl;
   
  textfile.close();
   
}//end main


