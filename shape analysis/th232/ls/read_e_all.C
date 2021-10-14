#include <fstream>

void readtree(){


  TFile *tf_th232 = new TFile("th232trees.root");
  TFile *tf_ra228 = new TFile("ra228trees.root");
  TFile *tf_ac228 = new TFile("ac228trees.root");
  TFile *tf_th228 = new TFile("th228trees.root");
  TFile *tf_ra224 = new TFile("ra224trees.root");
  TFile *tf_rn220 = new TFile("rn220trees.root");
  TFile *tf_po216 = new TFile("po216trees.root");
  TFile *tf_pb212 = new TFile("pb212trees.root");
  TFile *tf_bi212 = new TFile("bi212trees.root");
  TFile *tf_tl208 = new TFile("tl208trees.root");
  TFile *tf_po212 = new TFile("po212trees.root");

  //th232

  TTree *tree_th232 = (TTree*) tf_th232->Get("tree_th232");
  float qedep_th232;
  tree_th232->SetBranchAddress("Qedep",&qedep_th232);
  tree_th232->Draw("Qedep>>h_qedep_th232(4000,0,8)","","");
  TH1F *h_qedep_th232 = (TH1F*)gDirectory->Get("h_qedep_th232");


  // ra228
  TTree *tree_ra228 = (TTree*) tf_ra228->Get("tree_ra228");
  float qedep_ra228;
  tree_ra228->SetBranchAddress("Qedep",&qedep_ra228);
  tree_ra228->Draw("Qedep>>h_qedep_ra228(4000,0,8)","","");
  TH1F *h_qedep_ra228 = (TH1F*)gDirectory->Get("h_qedep_ra228");



  // ac228
  TTree *tree_ac228 = (TTree*) tf_ac228->Get("tree_ac228");
  float qedep_ac228;
  tree_ac228->SetBranchAddress("Qedep",&qedep_ac228);
  tree_ac228->Draw("Qedep>>h_qedep_ac228(4000,0,8)","","");
  TH1F *h_qedep_ac228 = (TH1F*)gDirectory->Get("h_qedep_ac228");


  // th228
    TTree *tree_th228 = (TTree*) tf_th228->Get("tree_th228");
    float qedep_th228;
    tree_th228->SetBranchAddress("Qedep",&qedep_th228);
    tree_th228->Draw("Qedep>>h_qedep_th228(4000,0,8)","","");
    TH1F *h_qedep_th228 = (TH1F*)gDirectory->Get("h_qedep_th228");


  // ra224
    TTree *tree_ra224 = (TTree*) tf_ra224->Get("tree_ra224");
    float qedep_ra224;
    tree_ra224->SetBranchAddress("Qedep",&qedep_ra224);
    tree_ra224->Draw("Qedep>>h_qedep_ra224(4000,0,8)","","");
    TH1F *h_qedep_ra224 = (TH1F*)gDirectory->Get("h_qedep_ra224");

    // rn220
    TTree *tree_rn220 = (TTree*) tf_rn220->Get("tree_rn220");
    float qedep_rn220;
    tree_rn220->SetBranchAddress("Qedep",&qedep_rn220);
    tree_rn220->Draw("Qedep>>h_qedep_rn220(4000,0,8)","","");
    TH1F *h_qedep_rn220 = (TH1F*)gDirectory->Get("h_qedep_rn220");



    // po216
    TTree *tree_po216 = (TTree*) tf_po216->Get("tree_po216");
    float qedep_po216;
    tree_po216->SetBranchAddress("Qedep",&qedep_po216);
    tree_po216->Draw("Qedep>>h_qedep_po216(4000,0,8)","","");
    TH1F *h_qedep_po216 = (TH1F*)gDirectory->Get("h_qedep_po216");


    // pb212
    TTree *tree_pb212 = (TTree*) tf_pb212->Get("tree_pb212");
    float qedep_pb212;
    tree_pb212->SetBranchAddress("Qedep",&qedep_pb212);
    tree_pb212->Draw("Qedep>>h_qedep_pb212(4000,0,8)","","");
    TH1F *h_qedep_pb212 = (TH1F*)gDirectory->Get("h_qedep_pb212");



    // bi212
    TTree *tree_bi212 = (TTree*) tf_bi212->Get("tree_bi212");
    float qedep_bi212;
    tree_bi212->SetBranchAddress("Qedep",&qedep_bi212);
    tree_bi212->Draw("Qedep>>h_qedep_bi212(4000,0,8)","","");
    TH1F *h_qedep_bi212 = (TH1F*)gDirectory->Get("h_qedep_bi212");



    // tl208
    TTree *tree_tl208 = (TTree*) tf_tl208->Get("tree_tl208");
    float qedep_tl208;
    tree_tl208->SetBranchAddress("Qedep",&qedep_tl208);
    tree_tl208->Draw("Qedep>>h_qedep_tl208(4000,0,8)","","");
    TH1F *h_qedep_tl208 = (TH1F*)gDirectory->Get("h_qedep_tl208");


    // po212
    TTree *tree_po212 = (TTree*) tf_po212->Get("tree_po212");
    float qedep_po212;
    tree_po212->SetBranchAddress("Qedep",&qedep_po212);
    tree_po212->Draw("Qedep>>h_qedep_po212(4000,0,8)","","");
    TH1F *h_qedep_po212 = (TH1F*)gDirectory->Get("h_qedep_po212");



    h_qedep_tl208->Scale(0.3594);
    h_qedep_po212->Scale(0.6406);



  TH1F *h_qedep_sum = (TH1F*)h_qedep_th232->Clone("h_qedep_sum");
  h_qedep_sum->Add(h_qedep_ra228);
  h_qedep_sum->Add(h_qedep_ac228);
  h_qedep_sum->Add(h_qedep_th228);
  h_qedep_sum->Add(h_qedep_ra224);
  h_qedep_sum->Add(h_qedep_rn220);
  h_qedep_sum->Add(h_qedep_po216);
  h_qedep_sum->Add(h_qedep_pb212);
  h_qedep_sum->Add(h_qedep_bi212);
  h_qedep_sum->Add(h_qedep_tl208);
  h_qedep_sum->Add(h_qedep_po212);





  h_qedep_th232->SetLineColor(1);
  h_qedep_ra228->SetLineColor(2);
  h_qedep_ac228->SetLineColor(3);
  h_qedep_th228->SetLineColor(4);
  h_qedep_ra224->SetLineColor(5);
  h_qedep_rn220->SetLineColor(6);
  h_qedep_po216->SetLineColor(7);
  h_qedep_pb212->SetLineColor(8);
  h_qedep_bi212->SetLineColor(49);
  h_qedep_tl208->SetLineColor(28);
  h_qedep_po212->SetLineColor(46);


  h_qedep_sum->SetLineColor(1);
  h_qedep_sum->SetLineWidth(2);




  auto legend = new TLegend(0.8,0.5,0.9,0.9);
  legend->AddEntry(h_qedep_th232, "Th-232 - #alpha decay", "l");
  legend->AddEntry(h_qedep_ra228, "Ra-228 - #beta decay", "l");
  legend->AddEntry(h_qedep_ac228, "Ac-228 - #beta decay", "l");
  legend->AddEntry(h_qedep_th228, "Th-228 - #alpha decay", "l");
  legend->AddEntry(h_qedep_ra224, "Ra-224 - #alpha decay", "l");
  legend->AddEntry(h_qedep_rn220, "Rn-220 - #alpha decay", "l");
  legend->AddEntry(h_qedep_po216, "Po-216 - #alpha decay ", "l");
  legend->AddEntry(h_qedep_pb212, "Pb-212 - #beta decay", "l");
  legend->AddEntry(h_qedep_bi212, "Bi-212 - #alpha + #beta decay", "l");
  legend->AddEntry(h_qedep_tl208, "Tl-208 - #beta decay", "l");
  legend->AddEntry(h_qedep_po212, "Po-212 - #alpha decay", "l");
  legend->AddEntry(h_qedep_sum, "Total Spectrum", "l");



  TH2F *h_guide = new TH2F("h_guide","",1,0,8,1,0.5,1000000);

  h_guide->GetXaxis()->SetTitle("Quenched energy [MeV]");
  h_guide->GetYaxis()->SetTitle("Counts / 2 keV");
  h_guide->SetTitle("Quenched Energy  - th232 Chain in LS - Unstacked 0:4 ");

  // draw histogram
  TCanvas *c1 = new TCanvas("c1","c1");
  c1->cd();
  c1->SetLogy();
  gStyle->SetOptStat(0);

  h_guide->Draw();
  h_qedep_th232->Draw("SAME");
  h_qedep_ra228->Draw("SAME");
  h_qedep_ac228->Draw("SAME");
  h_qedep_th228->Draw("SAME");
  h_qedep_ra224->Draw("SAME");
  h_qedep_rn220->Draw("SAME");
  h_qedep_po216->Draw("SAME");
  h_qedep_pb212->Draw("SAME");
  h_qedep_bi212->Draw("SAME");
  h_qedep_tl208->Draw("HIST SAME");
  h_qedep_po212->Draw("HIST SAME");

  h_qedep_sum->Draw("SAME");


  printf("Number of entries in h_qedep_th232 %f \n", h_qedep_th232->GetEntries());
  printf("Number of entries in h_qedep_ra228 %f \n", h_qedep_ra228->GetEntries());
  printf("Number of entries in h_qedep_ac228 %f \n", h_qedep_ac228->GetEntries());
  printf("Number of entries in h_qedep_th228 %f \n", h_qedep_th228->GetEntries());
  printf("Number of entries in h_qedep_ra224 %f \n", h_qedep_ra224->GetEntries());
  printf("Number of entries in h_qedep_rn220 %f \n", h_qedep_rn220->GetEntries());
  printf("Number of entries in h_qedep_po216 %f \n", h_qedep_po216->GetEntries());
  printf("Number of entries in h_qedep_pb212 %f \n", h_qedep_pb212->GetEntries());
  printf("Number of entries in h_qedep_bi212 %f \n", h_qedep_bi212->GetEntries());
  printf("Number of entries in h_qedep_tl208 %f \n", h_qedep_tl208->GetEntries());
  printf("Number of entries in h_qedep_po212 %f \n", h_qedep_po212->GetEntries());

  printf("Number of entries in h_qedep_sum %f \n", h_qedep_sum->GetEntries());

  double a = h_qedep_sum->Integral(h_qedep_sum->FindFixBin(0.7), h_qedep_sum->FindFixBin(8));
   printf("number of events over 0.7 MeV =  %f \n", a );


  legend->Draw();
}
