// GetRootFileName.C
//
// Helper macro for OnlineGUI to determine ROOT Filename
//   from a given runnumber
//
// 
TString GetRootFileName(UInt_t runnumber)
{
  TString file_path = "/w/work0/home/rachel/HallA/BB_Hodo/rootfiles/";
  TString expID = "replayed_simdig_gmn13.5_1kevts_NB";
  
  TString filename;
  filename = file_path + expID;
  filename += "_";
  filename += runnumber;
  filename += ".root";
  // filename += "-all.root";

  return filename;

}
