#include <iostream>

#include "TSystem.h"
#include "TString.h"
#include "TFile.h"

#include "THaShower.h"
#include "THaEvent.h"
#include "THaEvData.h"
#include "THaRun.h"
#include "THaAnalyzer.h"
#include "THaVarList.h"

#include "SBSBigBite.h"
#include "SBSBBTotalShower.h"
#include "SBSBBShower.h"
#include "SBSTimingHodoscope.h"

// Simple example replay script
//
// Ole Hansen, 11 April 2016
void replay_BBHodoRaw(int run_number = 124, uint nev = -1, uint nseg = 0)
{
  //load SBS-offline
  //gSystem->Load("libsbs.so");
  //--- Define the experimental configuration, i.e. spectrometers, detectors ---

  //THaHRS* bb = new THaHRS("R", "Right HRS" );
  //hrs->AddDetector( new THaVDC("vdc", "Vertical Drift Chambers") );
  // gHaApps->Add(hrs);
  
  SBSBigBite* bigbite = new SBSBigBite("bb", "BigBite spectrometer" );
  SBSTimingHodoscope* hodotdc = new  SBSTimingHodoscope("hodotdc", "BigBite hodo");
  hodotdc->SetModeTDC(SBSModeTDC::kTDC);
  hodotdc->SetModeADC(SBSModeADC::kNone);
  hodotdc->SetStoreRawHits(true);
  SBSTimingHodoscope* hodoadc = new  SBSTimingHodoscope("hodoadc", "BigBite hodo");
  hodoadc->SetModeTDC(SBSModeTDC::kNone);
  hodoadc->SetModeADC(SBSModeADC::kADCSimple);
  //bigbite->AddDetector( new THaShower("ps", "BigBite preshower") );
  bigbite->AddDetector(hodotdc);
  bigbite->AddDetector(hodoadc);
  //bigbite->AddDetector( new SBSBBShower("sh", "BigBite shower") );
  gHaApps->Add(bigbite);
  
  // Ideal beam (perfect normal incidence and centering)
  // THaIdealBeam* ib = new THaIdealBeam("IB", "Ideal beam");
  // gHaApps->Add(ib);

  //--- Set up the run we want to replay ---

  // This often requires a bit of coding to search directories, test
  // for non-existent files, etc.
  TString exp = "bbhodo";
  // Create file name patterns.
  string firstname = "bbhodo_%d";
  string endname = Form(".evio.%d",nseg);
  //string endname = Form(".evio");
  string combined(string(firstname)+endname);
   const char* RunFileNamePattern = combined.c_str();
  vector<TString> pathList;
  pathList.push_back(".");
  pathList.push_back(Form("%s/data",".."));

   THaAnalyzer* analyzer = new THaAnalyzer;
THaEvent* event = new THaEvent;
  THaRun* run = 0;
  int seg = 0;
  bool seg_ok = true;
  while(seg_ok) {
    TString data_fname;
    data_fname = TString::Format("%s/bbhodo_%d.evio.%d",getenv("DATA_DIR"),run_number,seg);
 //new THaRun( pathList, Form(RunFileNamePattern, run_number) );
    std::cout << "Looking for segment " << seg << " file " << data_fname.Data() << std::endl;
    if( gSystem->AccessPathName(data_fname)) {
      seg_ok = false;
      std::cout << "Segment " << seg << " not found. Exiting" << std::endl;
      continue;
    }
   run = new THaRun(data_fname);
    run->SetLastEvent(nev);

  run->SetDataRequired(0);//for the time being
   run->SetDate(TDatime());
  
  

  analyzer->SetEvent( event );
  TString out_dir = gSystem->Getenv("OUT_DIR");
  if( out_dir.IsNull() )  out_dir = ".";
  TString out_file = out_dir + "/" + exp + Form("_%d_%d.root", run_number,nev);

  analyzer->SetOutFile( out_file );
  
  analyzer->SetCutFile( "replay.cdef" );
  //  analyzer->SetOdefFile( "replay.odef" );
  analyzer->SetOdefFile( "replayhodo.odef" );
  analyzer->SetVerbosity(2);  // write cut summary to stdout
  analyzer->EnableBenchmarks();

  //--- Analyze the run ---
  // Here, one could replay more than one run with
  // a succession of Process calls. The results would all go into the
  // same ROOT output file

  run->Print();
  

  analyzer->Process(run);
    // Cleanup this run segment
    delete run;
    
    seg++; // Increment for next search
 }

  // Clean up

  analyzer->Close();
  delete analyzer;
  //gHaCuts->Clear();
  gHaVars->Clear();
  gHaPhysics->Delete();
  gHaApps->Delete();

  // Open the ROOT file so that a user doing interactive analysis can 
  // immediately look at the results. Of course, don't do this in batch jobs!
  // To close the file later, simply type "delete rootfile" or just exit

  //TFile* rootfile = new TFile( out_file, "READ" );
}
