#include <iostream>

#include "TSystem.h"
#include "TString.h"
#include "TFile.h"

#include "THaShower.h"
#include "THaEvData.h"
#include "THaRun.h"
#include "THaAnalyzer.h"
#include "THaVarList.h"

#include "SBSBigBite.h"
#include "SBSBBShower.h"
#include "SBSTimingHodoscope.h"

// Simple example replay script
//
// Ole Hansen, 11 April 2016
void replay_bbhodo(int run_number = 124, uint nev = -1, uint nseg = 0)
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


  THaRun* run = new THaRun( pathList, Form(RunFileNamePattern, run_number) );

  run->SetDataRequired(7);//for the time being
  
  cout << "Number of events to replay (-1=all)? ";
  if( nev > 0 )
    run->SetLastEvent(nev);
  
  //--- Set up any physics calculations we want to do ---

  // Extract the reconstructed target quantities of the golden track
  // Not really a physics calculation, but a convenience function.
  // It effectively converts the L.tr.* variables, which are arrays, 
  // to scalers L.gold.*

  //gHaPhysics->Add( new THaGoldenTrack( "R.gold", "RHRS golden track", "R" ));

  // Single-arm electron kinematics for the one spectrometer we have set up.
  // We assume a carbon-12 target (12 AMU)
  //gHaPhysics->Add( new THaPrimaryKine( "R.ekine", "RHRS electron kinematics",
  //"R", 0.511e-3, 12*0.9315 ));

  // Vertex position calculated from RHRS golden track and ideal beam
  // (will poor resolution if raster is on)
  //gHaPhysics->Add( new THaReactionPoint( "R.vx", "Vertex R", "R", "IB" ));

  //--- Define what we want the analyzer to do ---
  // The only mandatory items are the output definition and output file names
  
  THaAnalyzer* analyzer = new THaAnalyzer;

  TString out_dir = gSystem->Getenv("OUT_DIR");
  if( out_dir.IsNull() )  out_dir = ".";
  TString out_file = out_dir + "/" + exp + Form("_%d_%d.root", run_number,nev);

  analyzer->SetOutFile( out_file );
  
  analyzer->SetCutFile( "replay_hodo.cdef" );
  analyzer->SetOdefFile( "replay_hodo.odef" );

  analyzer->SetVerbosity(2);  // write cut summary to stdout
  analyzer->EnableBenchmarks();

  //--- Analyze the run ---
  // Here, one could replay more than one run with
  // a succession of Process calls. The results would all go into the
  // same ROOT output file

  run->Print();
  

  analyzer->Process(run);

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
