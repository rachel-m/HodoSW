// Replay script for SBS-GEn adapted for raw Hodo calibration
// October 2022
//
// Requires Podd 1.7.4

#if !defined(__CLING__) || defined(__ROOTCLING__)
#include <iostream>

#include "TSystem.h"
#include "THaGlobals.h"
#include "TString.h"
#include "TFile.h"
#include "TList.h"
#include "TObject.h"
#include "TClonesArray.h"

#include "THaEvData.h"
#include "MultiFileRun.h"
#include "THaAnalyzer.h"
#include "THaVarList.h"
#include "THaInterface.h"
#include "THaGoldenTrack.h"
#include "THaPrimaryKine.h"
#include "THaDecData.h"

#include "SBSBigBite.h"
#include "SBSBBShower.h"
#include "SBSBBTotalShower.h"
#include "SBSGRINCH.h"
//#include "SBSCherenkovDetector.h"
#include "SBSEArm.h"
#include "SBSHCal.h"
#include "SBSGEMStand.h"
#include "SBSTimingHodoscope.h"
#include "SBSGEMSpectrometerTracker.h"
#include "SBSGEMTrackerBase.h"
#include "SBSRasteredBeam.h"
#include "LHRSScalerEvtHandler.h"
#include "SBSScalerEvtHandler.h"
#include "SBSScalerHelicity.h"
#endif

using namespace std;

//void replay_BBHodoRaw(UInt_t runnum=10491, Long_t nevents=-1, Long_t firstevent=1, const char *fname_prefix="e1209016", UInt_t firstsegment=0, UInt_t maxsegments=1, Int_t maxstream=2, Int_t pedestalmode=0, Int_t cmplots=1, Int_t usesbsgems=1)
void replay_BBHodoRawNew(UInt_t runnum=2236, Long_t nevents=50000, uint firstsegment=0, uint maxsegments=1, const char *fname_prefix="e1209016")
{
 
  Long_t firstevent=1;
  UInt_t maxstream=2;
  Int_t cmplots=1;
  
  THaAnalyzer* analyzer = new THaAnalyzer;

  SBSBigBite* bigbite = new SBSBigBite("bb", "BigBite spectrometer" );
  
  SBSTimingHodoscope* hodotdc = new  SBSTimingHodoscope("hodotdc", "BigBite hodo");
  hodotdc->SetModeTDC(SBSModeTDC::kTDC);
  hodotdc->SetModeADC(SBSModeADC::kNone);
  hodotdc->SetStoreEmptyElements(kFALSE);
  hodotdc->SetStoreRawHits(kTRUE);
  //hodotdc->SetDataOutputLevel(1);// => this adds in the output the elements belonging to the "main" cluster.

  SBSTimingHodoscope* hodoadc = new  SBSTimingHodoscope("hodoadc", "BigBite hodo");
  hodoadc->SetModeTDC(SBSModeTDC::kNone);
  hodoadc->SetModeADC(SBSModeADC::kADC);
  hodoadc->SetStoreEmptyElements(kFALSE);
  hodoadc->SetStoreRawHits(kTRUE);
  //hodoadc->SetDataOutputLevel(0);
  bigbite->AddDetector(hodotdc);
  bigbite->AddDetector(hodoadc);
  gHaApps->Add(bigbite);
  //bigbite->SetDebug(2);
  //harm->SetDebug(2);
  
  TString prefix = gSystem->Getenv("DATA_DIR");

  vector<string> pathlist;
  if( !prefix.IsNull() )
    pathlist.push_back( prefix.Data() );

  if( prefix != "/adaqeb[1-3]/data1" )
    pathlist.push_back( "/adaqeb[1-3]/data1" );

  if( prefix != "/adaq1/data1/sbs" )
    pathlist.push_back( "/adaq1/data1/sbs" );

  // Do not use wildcard filenames with this directory
  if( prefix != "/cache/mss/halla/sbs/raw" )
    pathlist.push_back( "/cache/mss/halla/sbs/raw" );

  if( prefix != "/cache/mss/halla/sbs/GEnII/raw" )
    pathlist.push_back( "/cache/mss/halla/sbs/GEnII/raw" );

  for( const auto& path: pathlist ) {
    cout << "search paths = " << path << endl;
  }

  TString ftest(fname_prefix);
  bool test_data = ( ftest == "bbgem" || ftest == "e1209019_trigtest" );

  // Build list of files we'd like to analyze. These are candidates. If some of them
  // do not exist, they will be quietly skipped by the MultiFileRun class. A list of
  // the actually found files will be printed during initialization.
  vector<string> filenames;
  Int_t actual_maxstream = test_data ? 0 : maxstream;
  for( Int_t istream = 0; istream <= actual_maxstream; ++istream ) {
    for( UInt_t iseg = firstsegment; iseg < firstsegment + maxsegments; ++iseg ) {
      TString codafilename;
      if( test_data )
	codafilename.Form("%s_%u.evio.%u", fname_prefix, runnum, istream);
      else
	codafilename.Form("%s_%u.evio.%d.%u", fname_prefix, runnum, istream, iseg);
      cout << "codafilename = " << codafilename << endl;
      filenames.emplace_back(codafilename.Data());
    }
  }
  if( filenames.empty() ) {
    cout << "No files. Check your parameters." << endl;
    return;
  }

  auto* run = new Podd::MultiFileRun(pathlist, filenames);
  run->SetFirstSegment(firstsegment);  // Starting segment number
  run->SetMaxSegments(maxsegments);    // Number of segments
  run->SetMaxStreams(maxstream+1);  // Number of streams

  // Count physics events sequentially, i.e. always starting at 1, for each invocation of
  // analyzer->Process(). This count will be compared to the run's event range, so it
  // can be specified independently of absolute event numbers. This is relevant if
  // the analysis starts with a segment > 0. Actual (raw, CODA) physics event numbers
  // will then start with some largish number (the first event number in the continuation
  // segment), but the analyzer's count will still start at 1 for that analysis,
  // so you can give the run an event range of, say, 1-50000 to analyze 50k events,
  // regardless of what segments are being replayed. The event header written for each
  // entry in the output ROOT tree does contain the actual CODA event number, which is
  // what you usually want for analysis.

  analyzer->SetCountMode(THaAnalyzer::kCountPhysics);

  if( nevents > 0 ) run->SetLastEvent(firstevent+nevents-1);
  run->SetFirstEvent( firstevent );
  run->SetDataRequired(THaRunBase::kDate|THaRunBase::kRunNumber);
  Int_t st = run->Init();
  if( st != THaRunBase::READ_OK ) {
    cerr << "========= Error initializing run" << endl;
    return;
  }

  cout << "n segments to analyze = " << run->GetNFiles() << endl;

  prefix = gSystem->Getenv("OUT_DIR");

  TString outfilename;
  UInt_t lastsegment = run->GetLastSegment();
  if( nevents > 0 ){
    outfilename.Form( "%s/%s_bbhodo_%u_stream%d_%d_seg%u_%u_firstevent%ld_nevent%ld.root", prefix.Data(), fname_prefix, runnum,
		      0, maxstream, firstsegment, lastsegment, firstevent, nevents );
  } else {
    outfilename.Form( "%s/%s_bbhodofull_%u_stream%d_%d_seg%u_%u.root", prefix.Data(), fname_prefix, runnum,
		      0, maxstream, firstsegment, lastsegment );
  }


  analyzer->EnableHelicity();

  analyzer->SetVerbosity(2);
  analyzer->SetMarkInterval(100);

  analyzer->EnableBenchmarks();

  // Define the analysis parameters
  analyzer->SetOutFile( outfilename.Data() );

  // File to record cuts accounting information
  //prefix = gSystem->Getenv("LOG_DIR");
  //analyzer->SetSummaryFile(Form("%s/replay_gen_%d_stream%d_%d_seg%d_%d.log", prefix.Data(), runnum,
  //				0, maxstream, firstsegment, lastsegment));

  prefix = gSystem->Getenv("SBS_REPLAY");
  prefix += "/replay/";

  TString odef_filename = "replay_hodo.odef";

  odef_filename.Prepend( prefix );

  analyzer->SetOdefFile( odef_filename );

  //added cut list in order to have
  //on the farm we only write out events with a track in BigBite
  //TString cdef_filename = "replay_gen_farm.cdef";
  TString cdef_filename = "replay_hodo.cdef";

  //the above cdef file includes almost no significant cuts (basically just any hit in BigBite shower or preshower
  cdef_filename.Prepend( prefix );

  analyzer->SetCutFile( cdef_filename );
  //analyzer->SetCompressionLevel(0); // turn off compression

  st = analyzer->Init(run);
  if( st != 0 ) {
    cerr << "========= Error initializing analyzer" << endl;
    return;
  }
  analyzer->Process(run);     // start the actual analysis

}

