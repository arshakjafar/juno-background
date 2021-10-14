#include <fstream>

void readtree(){


  TFile *tf_k40 = new TFile("k40avtrees.root");


  //k40

  TTree *tree_k40 = (TTree*) tf_k40->Get("tree_k40");
  float qedep_k40;
  tree_k40->SetBranchAddress("Qedep",&qedep_k40);
  tree_k40->Draw("Qedep>>h_qedep_k40(4000,0,8)","sqrt(edepX*edepX + edepY*edepY + edepZ*edepZ)<17200","");
  TH1F *h_qedep_k40 = (TH1F*)gDirectory->Get("h_qedep_k40");






  auto legend = new TLegend(0.8,0.5,0.9,0.9);
  legend->AddEntry(h_qedep_k40, "Th-232 - #alpha decay", "l");

  TH2F *h_guide = new TH2F("h_guide","",1,0,8,1,0.5,1000000);

  h_guide->GetXaxis()->SetTitle("Quenched energy [MeV]");
  h_guide->GetYaxis()->SetTitle("Counts / 2 keV");
  h_guide->SetTitle("Quenched Energy  - k40 Chain in LS - Unstacked 0:4 ");

  // draw histogram
  TCanvas *c1 = new TCanvas("c1","c1");
  c1->cd();
  c1->SetLogy();
  gStyle->SetOptStat(0);

  h_guide->Draw();
  h_qedep_k40->Draw("SAME");



  printf("Number of entries in h_qedep_k40 %f \n", h_qedep_k40->GetEntries());


  double a = h_qedep_k40->Integral(h_qedep_k40->FindFixBin(0.7), h_qedep_k40->FindFixBin(8));
   printf("number of events over 0.7 MeV =  %f \n", a );


  legend->Draw();
}
