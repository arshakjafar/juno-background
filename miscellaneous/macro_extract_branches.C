/* This macro can be used to extract leaves for analysing data off CNAF .
Copying terabytes of data locally isnt a viable solution. 
So using this macro to extact only the leaves of interest is a better solution

*/
#include <fstream>

void extract_trees_time(){

// bi214

// TChain Object and specify TTree
  TChain *tc_bi214_prm = new TChain("prmtrkdep");
  TChain *tc_bi214_evt = new TChain("evt");
  TChain *tc_bi214_gen = new TChain("geninfo");
//  TChain *tc_bi214_radio = new TChain("radio");



// specify the path to txt file
  std::ifstream path_file_bi214("/storage/gpfs_data/juno/junofs/users/arshakjafar/CondorSims/u238/chain/ls/bi214/paths_$  if (path_file_bi214.is_open()){

                std::string line;

                while (std::getline(path_file_bi214,line)) {
                        printf("Reading %s\n",line.c_str());
                        tc_bi214_prm->Add(line.c_str());
                        tc_bi214_evt->Add(line.c_str());
                        tc_bi214_gen->Add(line.c_str());
                  //      tc_bi214_radio->Add(line.c_str());
                }

                path_file_bi214.close();
  }


    printf("Setting Branch addresses for geninfo\n");
    float bi214_initx, bi214_inity, bi214_initz;
    double bi214_exitt;
    tc_bi214_gen->SetBranchAddress("InitX",&bi214_initx);
    tc_bi214_gen->SetBranchAddress("InitY",&bi214_inity);
    tc_bi214_gen->SetBranchAddress("InitZ",&bi214_initz);
    tc_bi214_gen->SetBranchAddress("ExitT",&bi214_exitt);



  printf("Setting Branch addresses for prmtrkdep\n");
  float qedep_bi214, edepnotinls_bi214;
  int pdgid_bi214;
   float qedep_bi214, edepnotinls_bi214;
  int pdgid_bi214;
  tc_bi214_prm->SetBranchAddress("Qedep",&qedep_bi214);
  tc_bi214_prm->SetBranchAddress("PDGID",&pdgid_bi214);
  tc_bi214_prm->SetBranchAddress("edepNotInLS",&edepnotinls_bi214);

  printf("Setting Branch addresses for evt\n");
  float edep_bi214, edepx_bi214, edepy_bi214, edepz_bi214;
  int totalpe_bi214;
  tc_bi214_evt->SetBranchAddress("edep",&edep_bi214);
  tc_bi214_evt->SetBranchAddress("edepX",&edepx_bi214);
  tc_bi214_evt->SetBranchAddress("edepY",&edepy_bi214);
  tc_bi214_evt->SetBranchAddress("edepZ",&edepz_bi214);
  tc_bi214_evt->SetBranchAddress("totalPE",&totalpe_bi214);

//  printf("Setting Branch addresses for radio\n");
//  long int time_bi214;
//  tc_bi214_radio->SetBranchAddress("time",&time_bi214);



    printf("creating new tree\n");
    TTree *tree_bi214 = new TTree("tree_bi214","bi214 Histograms");
    tree_bi214->Branch("Qedep",&qedep_bi214,"Qedep/F");
    tree_bi214->Branch("PDGID",&pdgid_bi214,"PDGID/I");
    tree_bi214->Branch("edepNotInLS",&edepnotinls_bi214,"edepNotInLS/F");

    tree_bi214->Branch("edep",&edep_bi214,"edep/F");
    tree_bi214->Branch("edepX",&edepx_bi214,"edepX/F");
    tree_bi214->Branch("edepY",&edepy_bi214,"edepY/F");
    tree_bi214->Branch("edepZ",&edepz_bi214,"edepZ/F");
    tree_bi214->Branch("totalPE",&totalpe_bi214,"totalPE/I");

    tree_bi214->Branch("InitX",&bi214_initx,"InitX/F");
    tree_bi214->Branch("InitY",&bi214_inity,"InitY/F");
    tree_bi214->Branch("InitZ",&bi214_initz,"InitZ/F");
    tree_bi214->Branch("ExitT",&bi214_exitt,"ExitT/D");

//    tree_bi214->Branch("time",&time_bi214,"time");


  //looping over and filling the tree
   printf("Looping over entries\n");
    for(Int_t i=0;i<tc_bi214_evt->GetEntries();i++){
      tc_bi214_prm->GetEntry(i);
         for(Int_t i=0;i<tc_bi214_evt->GetEntries();i++){
      tc_bi214_prm->GetEntry(i);
      tc_bi214_evt->GetEntry(i);
      tc_bi214_gen->GetEntry(i);
    //  tc_bi214_radio->GetEntry(i);
      tree_bi214->Fill();

      if(i==100){
        printf("Entry no 100\n");
      }
      if(i==1000){
        printf("Entry no 1000\n");
      }
      if(i==10000){
        printf("Entry no 10000\n");
      }
      if(i==100000){
        printf("Entry no 100k \n");
      }
      if(i==250000){
        printf("Entry no 250k\n");
      }
      if(i==500000){
        printf("Entry no 500k\n");
      }
      if(i==750000){
        printf("Entry no 750k\n");
      }
    }

    printf("Saving the tree to ROOT file\n");

    TFile *savefilebi214 = TFile::Open("bi214trees_time.root","RECREATE");
    tree_bi214->Write();
    savefilebi214->Close();


  }
