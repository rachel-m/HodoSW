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

const Int_t nTdc = 180;
const Int_t nBarsTDC = 90;
const Int_t nBarsADC = 32;
const Double_t ADCCUT = 150.;//100.0;

// for local analysis at uog (please leave in comments)
//TString REPLAYED_DIR = "/w/work0/home/rachel/HallA/BB_Hodo/FallRun2021/Replayed";
//TString ANALYSED_DIR = "/w/work0/home/rachel/HallA/BB_Hodo/FallRun2021/Analysed";

TString REPLAYED_DIR = "/w/work5/home/garyp/sbs/rootfiles/GEn/hodocalib/TWcalib3_defaultoffset/";
TString ANALYSED_DIR = "/w/work5/home/garyp/sbs/results/hodocalib/";

using namespace std;

double TimeWalk(double time, double tot, double par0, double par1)
{
  double tcorr = time - (par0*tot + par1);
  return tcorr;
}

void AlignLE(const TString InFile="e1209016", Int_t nevents=-1, Int_t cosmic=0, Int_t DoFit=1, Int_t CutADC=0, Double_t Fitmin=-5., Double_t Fitmax=5.)
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
  TString sInFile = REPLAYED_DIR + "/" + InFile + "*.root";
  cout << "Adding " << sInFile << endl;
  TChain *T = new TChain("T");
  T->Add(sInFile);
    
  Int_t NdataTDC;
  Double_t TDCBar[nBarsTDC];
  Double_t TDCleL[nBarsTDC], TDCleR[nBarsTDC], TDCtotL[nBarsTDC], TDCtotR[nBarsTDC];
  Int_t NdataADC;
  Double_t ADCBar[nBarsADC], ADCValL[nBarsADC], ADCValR[nBarsADC];
  //Int_t ADCBarOff[nBarsADC];
     
  Double_t tr_p[3], tr_n, ps_e;
  
  //disable all branches
  T->SetBranchStatus("*",0);
  //enable branches
  T->SetBranchStatus("Ndata.bb.hodotdc.bar.tdc.id",1);
  T->SetBranchStatus("bb.hodotdc.*",1);
    
  T->SetBranchAddress("Ndata.bb.hodotdc.bar.tdc.id",&NdataTDC);
  T->SetBranchAddress("bb.hodotdc.bar.tdc.id",TDCBar);
  T->SetBranchAddress("bb.hodotdc.bar.tdc.L.tot",TDCtotL);
  T->SetBranchAddress("bb.hodotdc.bar.tdc.R.tot",TDCtotR);
  T->SetBranchAddress("bb.hodotdc.bar.tdc.L.le",TDCleL);
  T->SetBranchAddress("bb.hodotdc.bar.tdc.R.le",TDCleR);
     
  if(CutADC==1){
    T->SetBranchStatus("Ndata.bb.hodoadc.bar.adc.id",1);
    T->SetBranchStatus("bb.hodoadc.bar.adc.*",1);
    T->SetBranchAddress("Ndata.bb.hodoadc.bar.adc.id",&NdataADC);
    T->SetBranchAddress("bb.hodoadc.bar.adc.id",ADCBar);
    T->SetBranchAddress("bb.hodoadc.bar.adc.L.ap",ADCValL);
    T->SetBranchAddress("bb.hodoadc.bar.adc.R.ap",ADCValR);
    //T->SetBranchAddress("bb.hodoadc.bar.adc.L.a",ADCValL);
    //T->SetBranchAddress("bb.hodoadc.bar.adc.R.a",ADCValR);
    //T->SetBranchAddress("bb.hodoadc.adcbaroff",ADCBarOff);
    //T->SetBranchAddress("Ndata.bb.hodoadc.bar.adc.L.ap",&NdataADCL);
    //T->SetBranchAddress("Ndata.bb.hodoadc.bar.adc.R.ap",&NdataADCR);
    //T->SetBranchAddress("Ndata.bb.hodoadc.bar.adc.L.a",&NdataADCL);
    //T->SetBranchAddress("Ndata.bb.hodoadc.bar.adc.R.a",&NdataADCR);  
  }

  if(!cosmic){
    T->SetBranchStatus("bb.tr.p",1);
    T->SetBranchStatus("bb.ps.e",1);
    T->SetBranchStatus("bb.tr.n",1);
      
    T->SetBranchAddress("bb.tr.p",&tr_p);
    T->SetBranchAddress("bb.tr.n",&tr_n);
    T->SetBranchAddress("bb.ps.e",&ps_e);
  }
  
  
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
   
  //Histogram Declarations
  // number of histo bins
  Int_t NTotBins = 100;//200;
  Double_t TotBinLow = 0.;
  Double_t TotBinHigh = 30;//400.;
  Int_t NLEBins = 100;
  Double_t LEBinLow = -20.0;//-800.0;//-100.;
  Double_t LEBinHigh = 20.0;//100.;

  TH1D* hLleW[nBarsTDC];
  TH1D* hRleW[nBarsTDC];
  
  //histograms
  for (int i=0; i<nBarsTDC; i++){
    hLleW[i] = new TH1D (Form("hLleW_%d",i),"",NLEBins,LEBinLow,LEBinHigh);
    hRleW[i] = new TH1D (Form("hRleW_%d",i),"",NLEBins,LEBinLow,LEBinHigh);
  }
  
  //event loop
  for(Int_t ev=0; ev<NEventsAnalysis; ev++){
    
    if(ev%10000==0) cout << ev << " / " << NEventsAnalysis << endl;
    T->GetEntry(ev);
    

    //very loose elastic electron cut if not cosmic run
    if (!cosmic){
      if(tr_n <= 0) continue;
      if(ps_e < 0.2) continue;
      if(tr_p[0] < 2.0) continue;
    }
    
    for(Int_t tdc=0; tdc<NdataTDC; tdc++){
      Int_t tdcbar = TDCBar[tdc];
      
      double LleW = TimeWalk(TDCleL[tdc], TDCtotL[tdc], Lpar0[tdcbar], Lpar1[tdcbar]);
      double RleW = TimeWalk(TDCleR[tdc], TDCtotR[tdc], Rpar0[tdcbar], Rpar1[tdcbar]);
       
       //check for good cosmic bar i.e one neighbouring hit
      if(cosmic){
	if( tdc==0 ){
	  if( TDCBar[tdc+1] != tdcbar+1 )
	    continue;
	}
	else if( tdc==(Int_t)NdataTDC-1 ){
	  if( TDCBar[tdc-1] != tdcbar-1 )
	    continue;
	}
	else{ 
	  if( TDCBar[tdc+1] != tdcbar+1 || TDCBar[tdc-1] != tdcbar-1 )
	    continue;
	}
      }
      
      if(CutADC==1){
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
      }//adc cut
      else if(CutADC!=1){
	hLleW[tdcbar]->Fill(LleW);
	hRleW[tdcbar]->Fill(RleW);
      }//else
    }//tdc bar loop
  }//event loop

  
  //global draw options
  gStyle->SetHistLineWidth(2);
  gStyle->SetOptTitle(0);
  //gStyle->SetOptStat(0);
   
  TCanvas *cl = new TCanvas();
  TCanvas *cr = new TCanvas();
   
  TF1 *gausfit = new TF1("gausfit","gaus",LEBinLow,LEBinHigh);
   
  double loff[nBarsTDC];
  double roff[nBarsTDC];
   
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
      hLleW[bar]->Fit(gausfit,"Q","",Fitmin,Fitmax);
      loff[bar] = gausfit->GetParameter(1);
      hLleW[bar]->Draw("");
       
      //right
      cr->cd(j+1);
      hRleW[bar]->SetLineColor(kBlack);
      hRleW[bar]->GetXaxis()->SetTitle("Leading Edge [ns]");
      hRleW[bar]->Fit(gausfit,"Q","",Fitmin,Fitmax);
      roff[bar] = gausfit->GetParameter(1);
      hRleW[bar]->Draw("");
    }
    cl->Print(Form("Left_%i.pdf",i));
    cr->Print(Form("Right_%i.pdf",i));
  }
   
  cl->Close();
  cr->Close();
   
  gSystem->Exec("pdfunite Left*.pdf Right*.pdf AlignedLE.pdf");
  gSystem->Exec("rm Left*.pdf Right*.pdf");
  gSystem->Exec(Form("mv AlignedLE.pdf %s",ANALYSED_DIR.Data()));
  
  ofstream textfile;
  textfile.open(ANALYSED_DIR+"AlignedLE.txt");
  textfile << "LE Align" << endl;
  for (int i=0; i<90; i++)
    textfile << loff[i] << endl;
  for (int i=0; i<90; i++)
    textfile << roff[i] << endl;
   
  textfile.close();
   
}//end main

  
