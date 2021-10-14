#include <fstream>
#include <iostream>
#include "TClass.h"


void readtree(){


  TFile *tf_th232 = new TFile("th232trees.root");
  TFile *tf_ra228 = new TFile("ra228trees.root");
  TFile *tf_ac228 = new TFile("ac228trees.root");
  TFile *tf_th228 = new TFile("th228trees.root");
  TFile *tf_ra224 = new TFile("ra224trees.root");
  TFile *tf_rn220 = new TFile("rn220trees.root");
  TFile *tf_po216 = new TFile("po216trees.root");
  TFile *tf_pb212 = new TFile("pb212trees.root");
  TFile *tf_tl208 = new TFile("tl208trees.root");

  TFile *tf_bi212 = new TFile("bi212trees_time_LS.root");
  TFile *tf_po212 = new TFile("po212trees_time_LS.root");

  //th232

  TTree *tree_th232 = (TTree*) tf_th232->Get("tree_th232");
  int totalpe_th232;
  tree_th232->SetBranchAddress("totalPE",&totalpe_th232);
  tree_th232->Draw("totalPE>>h_totalpe_th232(266,0,10800)","","");
  TH1F *h_totalpe_th232 = (TH1F*)gDirectory->Get("h_totalpe_th232");


  // ra228
  TTree *tree_ra228 = (TTree*) tf_ra228->Get("tree_ra228");
  int totalpe_ra228;
  tree_ra228->SetBranchAddress("totalPE",&totalpe_ra228);
  tree_ra228->Draw("totalPE>>h_totalpe_ra228(266,0,10800)","","");
  TH1F *h_totalpe_ra228 = (TH1F*)gDirectory->Get("h_totalpe_ra228");



  // ac228
  TTree *tree_ac228 = (TTree*) tf_ac228->Get("tree_ac228");
  int totalpe_ac228;
  tree_ac228->SetBranchAddress("totalPE",&totalpe_ac228);
  tree_ac228->Draw("totalPE>>h_totalpe_ac228(266,0,10800)","","");
  TH1F *h_totalpe_ac228 = (TH1F*)gDirectory->Get("h_totalpe_ac228");


  // th228
    TTree *tree_th228 = (TTree*) tf_th228->Get("tree_th228");
    int totalpe_th228;
    tree_th228->SetBranchAddress("totalPE",&totalpe_th228);
    tree_th228->Draw("totalPE>>h_totalpe_th228(266,0,10800)","","");
    TH1F *h_totalpe_th228 = (TH1F*)gDirectory->Get("h_totalpe_th228");


  // ra224
    TTree *tree_ra224 = (TTree*) tf_ra224->Get("tree_ra224");
    int totalpe_ra224;
    tree_ra224->SetBranchAddress("totalPE",&totalpe_ra224);
    tree_ra224->Draw("totalPE>>h_totalpe_ra224(266,0,10800)","","");
    TH1F *h_totalpe_ra224 = (TH1F*)gDirectory->Get("h_totalpe_ra224");

    // rn220
    TTree *tree_rn220 = (TTree*) tf_rn220->Get("tree_rn220");
    int totalpe_rn220;
    tree_rn220->SetBranchAddress("totalPE",&totalpe_rn220);
    tree_rn220->Draw("totalPE>>h_totalpe_rn220(266,0,10800)","","");
    TH1F *h_totalpe_rn220 = (TH1F*)gDirectory->Get("h_totalpe_rn220");



    // po216
    TTree *tree_po216 = (TTree*) tf_po216->Get("tree_po216");
    int totalpe_po216;
    tree_po216->SetBranchAddress("totalPE",&totalpe_po216);
    tree_po216->Draw("totalPE>>h_totalpe_po216(266,0,10800)","","");
    TH1F *h_totalpe_po216 = (TH1F*)gDirectory->Get("h_totalpe_po216");


    // pb212
    TTree *tree_pb212 = (TTree*) tf_pb212->Get("tree_pb212");
    int totalpe_pb212;
    tree_pb212->SetBranchAddress("totalPE",&totalpe_pb212);
    tree_pb212->Draw("totalPE>>h_totalpe_pb212(266,0,10800)","","");
    TH1F *h_totalpe_pb212 = (TH1F*)gDirectory->Get("h_totalpe_pb212");

    // tl208
    TTree *tree_tl208 = (TTree*) tf_tl208->Get("tree_tl208");
    int totalpe_tl208;
    tree_tl208->SetBranchAddress("totalPE",&totalpe_tl208);
    tree_tl208->Draw("totalPE>>h_totalpe_tl208(266,0,10800)","","");
    TH1F *h_totalpe_tl208 = (TH1F*)gDirectory->Get("h_totalpe_tl208");

/*


    // bi212
    TTree *tree_bi212 = (TTree*) tf_bi212->Get("tree_bi212");
    int totalpe_bi212;
    tree_bi212->SetBranchAddress("totalPE",&totalpe_bi212);
    tree_bi212->Draw("totalPE>>h_totalpe_bi212(266,0,10800)","","");
    TH1F *h_totalpe_bi212 = (TH1F*)gDirectory->Get("h_totalpe_bi212");






    // po212
    TTree *tree_po212 = (TTree*) tf_po212->Get("tree_po212");
    int totalpe_po212;
    tree_po212->SetBranchAddress("totalPE",&totalpe_po212);
    tree_po212->Draw("totalPE>>h_totalpe_po212(266,0,10800)","","");
    TH1F *h_totalpe_po212 = (TH1F*)gDirectory->Get("h_totalpe_po212");

*/

TTree *tree_bi212 = (TTree*) tf_bi212->Get("tree_bi212");
TTree *tree_po212 = (TTree*) tf_po212->Get("tree_po212");

int totalpe_bi212, totalpe_po212 ;
double exitt_bi212, exitt_po212 ;

tree_bi212->SetBranchAddress("ExitT",&exitt_bi212);
tree_po212->SetBranchAddress("ExitT",&exitt_po212);

tree_bi212->SetBranchAddress("totalPE",&totalpe_bi212);
tree_po212->SetBranchAddress("totalPE",&totalpe_po212);

TH1D *h_totalpe_bi212 = new TH1D("h_totalpe_bi212","",266,0,10800);
TH1D *h_totalpe_po212 = new TH1D("h_totalpe_po212","",266,0,10800);
TH1D *h_totalpe_bipo212 = new TH1D("h_totalpe_bipo212","",266,0,10800);

for(Int_t i=0;i<tree_po212->GetEntries();i++){
  tree_bi212->GetEntry(i);
  tree_po212->GetEntry(i);

  if(exitt_po212 <= 300){
    int totalpe_bipo212 = totalpe_po212 + totalpe_bi212 ;
    h_totalpe_bipo212->Fill(totalpe_bipo212);
//      printf("exitT value %f \n",exitt_po212 );
  } else {
    h_totalpe_bi212->Fill(totalpe_bi212);
    h_totalpe_po212->Fill(totalpe_po212);
    }
}

    h_totalpe_tl208->Scale(0.3594);
    h_totalpe_po212->Scale(0.6406);
    h_totalpe_bipo212->Scale(0.6406);



  TH1F *h_totalpe_sum = (TH1F*)h_totalpe_th232->Clone("h_totalpe_sum");
  h_totalpe_sum->Add(h_totalpe_ra228);
  h_totalpe_sum->Add(h_totalpe_ac228);
  h_totalpe_sum->Add(h_totalpe_th228);
  h_totalpe_sum->Add(h_totalpe_ra224);
  h_totalpe_sum->Add(h_totalpe_rn220);
  h_totalpe_sum->Add(h_totalpe_po216);
  h_totalpe_sum->Add(h_totalpe_pb212);
  h_totalpe_sum->Add(h_totalpe_bi212);
  h_totalpe_sum->Add(h_totalpe_tl208);
  h_totalpe_sum->Add(h_totalpe_po212);
  h_totalpe_sum->Add(h_totalpe_bipo212);





  h_totalpe_th232->SetLineColor(1);
  h_totalpe_ra228->SetLineColor(2);
  h_totalpe_ac228->SetLineColor(3);
  h_totalpe_th228->SetLineColor(4);
  h_totalpe_ra224->SetLineColor(5);
  h_totalpe_rn220->SetLineColor(6);
  h_totalpe_po216->SetLineColor(7);
  h_totalpe_pb212->SetLineColor(8);
  h_totalpe_bi212->SetLineColor(49);
  h_totalpe_tl208->SetLineColor(28);
  h_totalpe_po212->SetLineColor(46);
  h_totalpe_bipo212->SetLineColor(12);
  h_totalpe_sum->SetLineColor(1);

  h_totalpe_sum->SetLineWidth(2);
  h_totalpe_bipo212->SetLineWidth(2);
  h_totalpe_bi212->SetLineWidth(2);
  h_totalpe_po212->SetLineWidth(2);




  auto legend = new TLegend(0.6,0.65,0.9,0.9);
  legend->AddEntry(h_totalpe_th232, "Th-232 - #alpha decay", "l");
  legend->AddEntry(h_totalpe_ra228, "Ra-228 - #beta decay", "l");
  legend->AddEntry(h_totalpe_ac228, "Ac-228 - #beta decay", "l");
  legend->AddEntry(h_totalpe_th228, "Th-228 - #alpha decay", "l");
  legend->AddEntry(h_totalpe_ra224, "Ra-224 - #alpha decay", "l");
  legend->AddEntry(h_totalpe_rn220, "Rn-220 - #alpha decay", "l");
  legend->AddEntry(h_totalpe_po216, "Po-216 - #alpha decay ", "l");
  legend->AddEntry(h_totalpe_pb212, "Pb-212 - #beta decay", "l");
  legend->AddEntry(h_totalpe_bi212, "Bi-212 - #alpha + #beta decay", "l");
  legend->AddEntry(h_totalpe_tl208, "Tl-208 - #beta decay", "l");
  legend->AddEntry(h_totalpe_po212, "Po-212 - #alpha decay", "l");
  legend->AddEntry(h_totalpe_bipo212, "Bi212 + Po212", "l");
  legend->AddEntry(h_totalpe_sum, "Total Spectrum", "l");



  TH2F *h_guide = new TH2F("h_guide","",2,0,5400,2,0.5,1000000);

  h_guide->GetXaxis()->SetTitle("Total PE");
  h_guide->GetYaxis()->SetTitle("Counts");
  h_guide->SetTitle("TotalPE - Th232 Chain-LS - Bi212 + Po212 300 ns ");

  // draw histogram
  TCanvas *c1 = new TCanvas("c1","c1");
  c1->cd();
  c1->SetLogy();
  gStyle->SetOptStat(0);
  gStyle->SetTitleX(0.45);

  h_guide->Draw();
  h_totalpe_th232->Draw("SAME");
  h_totalpe_ra228->Draw("SAME");
  h_totalpe_ac228->Draw("SAME");
  h_totalpe_th228->Draw("SAME");
  h_totalpe_ra224->Draw("SAME");
  h_totalpe_rn220->Draw("SAME");
  h_totalpe_po216->Draw("SAME");
  h_totalpe_pb212->Draw("SAME");
  h_totalpe_bi212->Draw("SAME");
  h_totalpe_tl208->Draw("HIST SAME");
  h_totalpe_po212->Draw("HIST SAME");
  h_totalpe_bipo212->Draw("HIST SAME");

  h_totalpe_sum->Draw("HIST SAME");



  printf("Number of entries in h_totalpe_th232 %f \n", h_totalpe_th232->GetEntries());
  printf("Number of entries in h_totalpe_ra228 %f \n", h_totalpe_ra228->GetEntries());
  printf("Number of entries in h_totalpe_ac228 %f \n", h_totalpe_ac228->GetEntries());
  printf("Number of entries in h_totalpe_th228 %f \n", h_totalpe_th228->GetEntries());
  printf("Number of entries in h_totalpe_ra224 %f \n", h_totalpe_ra224->GetEntries());
  printf("Number of entries in h_totalpe_rn220 %f \n", h_totalpe_rn220->GetEntries());
  printf("Number of entries in h_totalpe_po216 %f \n", h_totalpe_po216->GetEntries());
  printf("Number of entries in h_totalpe_pb212 %f \n", h_totalpe_pb212->GetEntries());
  printf("Number of entries in h_totalpe_bi212 %f \n", h_totalpe_bi212->GetEntries());
  printf("Number of entries in h_totalpe_tl208 %f \n", h_totalpe_tl208->GetEntries());
  printf("Number of entries in h_totalpe_po212 %f \n", h_totalpe_po212->GetEntries());
  printf("Number of entries in h_totalpe_bipo212 %f \n", h_totalpe_bipo212->GetEntries());

  printf("Number of entries in h_totalpe_sum %f \n", h_totalpe_sum->GetEntries());

  double a = h_totalpe_sum->Integral(h_totalpe_sum->FindFixBin(0.7), h_totalpe_sum->FindFixBin(8));
   printf("number of events over 0.7 MeV =  %f \n", a );


  legend->Draw();
  TGaxis *axis1 = new TGaxis(0,1000000,5400,1000000,0,4,4,"-");
   axis1->SetTitle("Detected Energy [MeV]");
   axis1->SetTitleSize(0.025);
   axis1->SetLabelSize(0.025);
   axis1->SetLabelOffset(-0.01);
   axis1->Draw();


  c1->Print("th232bipo_totalpe_300ns_04.pdf");
}
