#include <fstream>

void readtree(){


  TFile *tf_u238 = new TFile("u238trees.root");
  TFile *tf_u234 = new TFile("u234trees.root");
  TFile *tf_bi214 = new TFile("bi214trees.root");
  TFile *tf_bi210 = new TFile("bi210trees.root");
  TFile *tf_pa234 = new TFile("pa234trees.root");
  TFile *tf_pb210 = new TFile("pb210trees.root");
  TFile *tf_pb214 = new TFile("pb214trees.root");
  TFile *tf_po210 = new TFile("po210trees.root");
  TFile *tf_po214 = new TFile("po214trees.root");
  TFile *tf_po218 = new TFile("po218trees.root");
  TFile *tf_ra226 = new TFile("ra226trees.root");
  TFile *tf_rn222 = new TFile("rn222trees.root");
  TFile *tf_th230 = new TFile("th230trees.root");
  TFile *tf_th234 = new TFile("th234trees.root");

  //u238

  TTree *tree_u238 = (TTree*) tf_u238->Get("tree_u238");
  float qedep_u238;
  tree_u238->SetBranchAddress("Qedep",&qedep_u238);
  tree_u238->Draw("Qedep>>h_qedep_u238(4000,0,8)","","");
  TH1F *h_qedep_u238 = (TH1F*)gDirectory->Get("h_qedep_u238");


  // u234
  TTree *tree_u234 = (TTree*) tf_u234->Get("tree_u234");
  float qedep_u234;
  tree_u234->SetBranchAddress("Qedep",&qedep_u234);
  tree_u234->Draw("Qedep>>h_qedep_u234(4000,0,8)","","");
  TH1F *h_qedep_u234 = (TH1F*)gDirectory->Get("h_qedep_u234");



  // bi214
  TTree *tree_bi214 = (TTree*) tf_bi214->Get("tree_bi214");
  float qedep_bi214;
  tree_bi214->SetBranchAddress("Qedep",&qedep_bi214);
  tree_bi214->Draw("Qedep>>h_qedep_bi214(4000,0,8)","","");
  TH1F *h_qedep_bi214 = (TH1F*)gDirectory->Get("h_qedep_bi214");


  // bi210
    TTree *tree_bi210 = (TTree*) tf_bi210->Get("tree_bi210");
    float qedep_bi210;
    tree_bi210->SetBranchAddress("Qedep",&qedep_bi210);
    tree_bi210->Draw("Qedep>>h_qedep_bi210(4000,0,8)","","");
    TH1F *h_qedep_bi210 = (TH1F*)gDirectory->Get("h_qedep_bi210");


  // pa234
    TTree *tree_pa234 = (TTree*) tf_pa234->Get("tree_pa234");
    float qedep_pa234;
    tree_pa234->SetBranchAddress("Qedep",&qedep_pa234);
    tree_pa234->Draw("Qedep>>h_qedep_pa234(4000,0,8)","","");
    TH1F *h_qedep_pa234 = (TH1F*)gDirectory->Get("h_qedep_pa234");

    // pb210
    TTree *tree_pb210 = (TTree*) tf_pb210->Get("tree_pb210");
    float qedep_pb210;
    tree_pb210->SetBranchAddress("Qedep",&qedep_pb210);
    tree_pb210->Draw("Qedep>>h_qedep_pb210(4000,0,8)","","");
    TH1F *h_qedep_pb210 = (TH1F*)gDirectory->Get("h_qedep_pb210");



    // pb214
    TTree *tree_pb214 = (TTree*) tf_pb214->Get("tree_pb214");
    float qedep_pb214;
    tree_pb214->SetBranchAddress("Qedep",&qedep_pb214);
    tree_pb214->Draw("Qedep>>h_qedep_pb214(4000,0,8)","","");
    TH1F *h_qedep_pb214 = (TH1F*)gDirectory->Get("h_qedep_pb214");


    // po210
    TTree *tree_po210 = (TTree*) tf_po210->Get("tree_po210");
    float qedep_po210;
    tree_po210->SetBranchAddress("Qedep",&qedep_po210);
    tree_po210->Draw("Qedep>>h_qedep_po210(4000,0,8)","","");
    TH1F *h_qedep_po210 = (TH1F*)gDirectory->Get("h_qedep_po210");



    // po214
    TTree *tree_po214 = (TTree*) tf_po214->Get("tree_po214");
    float qedep_po214;
    tree_po214->SetBranchAddress("Qedep",&qedep_po214);
    tree_po214->Draw("Qedep>>h_qedep_po214(4000,0,8)","","");
    TH1F *h_qedep_po214 = (TH1F*)gDirectory->Get("h_qedep_po214");



    // po218
    TTree *tree_po218 = (TTree*) tf_po218->Get("tree_po218");
    float qedep_po218;
    tree_po218->SetBranchAddress("Qedep",&qedep_po218);
    tree_po218->Draw("Qedep>>h_qedep_po218(4000,0,8)","","");
    TH1F *h_qedep_po218 = (TH1F*)gDirectory->Get("h_qedep_po218");


    // ra226
    TTree *tree_ra226 = (TTree*) tf_ra226->Get("tree_ra226");
    float qedep_ra226;
    tree_ra226->SetBranchAddress("Qedep",&qedep_ra226);
    tree_ra226->Draw("Qedep>>h_qedep_ra226(4000,0,8)","","");
    TH1F *h_qedep_ra226 = (TH1F*)gDirectory->Get("h_qedep_ra226");


    // rn222
    TTree *tree_rn222 = (TTree*) tf_rn222->Get("tree_rn222");
    float qedep_rn222;
    tree_rn222->SetBranchAddress("Qedep",&qedep_rn222);
    tree_rn222->Draw("Qedep>>h_qedep_rn222(4000,0,8)","","");
    TH1F *h_qedep_rn222 = (TH1F*)gDirectory->Get("h_qedep_rn222");



    // th230
    TTree *tree_th230 = (TTree*) tf_th230->Get("tree_th230");
    float qedep_th230;
    tree_th230->SetBranchAddress("Qedep",&qedep_th230);
    tree_th230->Draw("Qedep>>h_qedep_th230(4000,0,8)","","");
    TH1F *h_qedep_th230 = (TH1F*)gDirectory->Get("h_qedep_th230");



    // th234
    TTree *tree_th234 = (TTree*) tf_th234->Get("tree_th234");
    float qedep_th234;
    tree_th234->SetBranchAddress("Qedep",&qedep_th234);
    tree_th234->Draw("Qedep>>h_qedep_th234(4000,0,8)","","");
    TH1F *h_qedep_th234 = (TH1F*)gDirectory->Get("h_qedep_th234");



  double_t norm = 7.387/1000000;
  h_qedep_u238->Scale(norm);
  h_qedep_u234->Scale(norm);
  h_qedep_bi214->Scale(norm);
  h_qedep_bi210->Scale(norm);
  h_qedep_pa234->Scale(norm);
  h_qedep_pb210->Scale(norm);
  h_qedep_pb214->Scale(norm);
  h_qedep_po210->Scale(norm);
  h_qedep_po214->Scale(norm);
  h_qedep_po218->Scale(norm);
  h_qedep_ra226->Scale(norm);
  h_qedep_rn222->Scale(norm);
  h_qedep_th230->Scale(norm);
  h_qedep_th234->Scale(norm);

  TH1F *h_qedep_sum = (TH1F*)h_qedep_u238->Clone("h_qedep_sum");
  h_qedep_sum->Add(h_qedep_u234);
  h_qedep_sum->Add(h_qedep_bi214);
  h_qedep_sum->Add(h_qedep_bi210);
  h_qedep_sum->Add(h_qedep_pa234);
  h_qedep_sum->Add(h_qedep_pb210);
  h_qedep_sum->Add(h_qedep_pb214);
  h_qedep_sum->Add(h_qedep_po210);
  h_qedep_sum->Add(h_qedep_po214);
  h_qedep_sum->Add(h_qedep_po218);
  h_qedep_sum->Add(h_qedep_ra226);
  h_qedep_sum->Add(h_qedep_rn222);
  h_qedep_sum->Add(h_qedep_th230);
  h_qedep_sum->Add(h_qedep_th234);




  h_qedep_u238->SetLineColor(1);
  h_qedep_u234->SetLineColor(2);
  h_qedep_bi214->SetLineColor(3);
  h_qedep_bi210->SetLineColor(4);
  h_qedep_pa234->SetLineColor(5);
  h_qedep_pb210->SetLineColor(6);
  h_qedep_pb214->SetLineColor(7);
  h_qedep_po210->SetLineColor(8);
  h_qedep_po214->SetLineColor(49);
  h_qedep_po218->SetLineColor(28);
  h_qedep_ra226->SetLineColor(46);
  h_qedep_rn222->SetLineColor(14);
  h_qedep_th230->SetLineColor(kTeal-6);
  h_qedep_th234->SetLineColor(41);

  h_qedep_sum->SetLineColor(1);
  h_qedep_sum->SetLineWidth(2);




  auto legend = new TLegend(0.8,0.5,0.9,0.9);
  legend->AddEntry(h_qedep_u238, "U-238 - #alpha decay", "l");
  legend->AddEntry(h_qedep_th234, "Th-234 - #beta decay", "l");
  legend->AddEntry(h_qedep_pa234, "Pa-234 - #beta decay", "l");
  legend->AddEntry(h_qedep_u234, "U-234 - #alpha decay", "l");
  legend->AddEntry(h_qedep_th230, "Th-230 - #alpha decay", "l");
  legend->AddEntry(h_qedep_ra226, "Ra-226 - #alpha decay", "l");
  legend->AddEntry(h_qedep_rn222, "Rn-222 - #alpha decay", "l");
  legend->AddEntry(h_qedep_po218, "Po-218 - #alpha decay", "l");
  legend->AddEntry(h_qedep_pb214, "Pb-214 - #beta decay", "l");
  legend->AddEntry(h_qedep_bi214, "Bi-214 - #beta decay ", "l");
  legend->AddEntry(h_qedep_po214, "Po-214 - #alpha decay", "l");
  legend->AddEntry(h_qedep_pb210, "Pb-210 - #beta decay", "l");
  legend->AddEntry(h_qedep_bi210, "Bi-210 - #beta decay", "l");
  legend->AddEntry(h_qedep_po210, "Po-210 - #alpha decay", "l");
  legend->AddEntry(h_qedep_sum, "Total Spectrum", "l");



  TH2F *h_guide = new TH2F("h_guide","",1,0,8,1,0,0.01);

  h_guide->GetXaxis()->SetTitle("Quenched energy [MeV]");
  h_guide->GetYaxis()->SetTitle("Counts / 2 keV");
  h_guide->SetTitle("Quenched Energy  - U238 Chain in AV - Unstacked 0:4 ");

  // draw histogram
  TCanvas *c1 = new TCanvas("c1","c1");
  c1->cd();
  //c1->SetLogy();
  gStyle->SetOptStat(111111);

/*
  h_guide->Draw();
  h_qedep_u238->Draw("SAME");
  h_qedep_u234->Draw("SAME");
  h_qedep_bi214->Draw("SAME");
  h_qedep_bi210->Draw("SAME");
  h_qedep_pa234->Draw("SAME");
  h_qedep_pb210->Draw("SAME");
  h_qedep_pb214->Draw("SAME");
  h_qedep_po210->Draw("SAME");
  h_qedep_po214->Draw("SAME");
  h_qedep_po218->Draw("SAME");
  h_qedep_ra226->Draw("SAME");
  h_qedep_rn222->Draw("SAME");
  h_qedep_th230->Draw("SAME");
  h_qedep_th234->Draw("SAME");
  h_qedep_sum->Draw("SAME");
*/

  //h_qedep_sum->Draw();

  printf("Number of entries in h_qedep_u238 %f \n", h_qedep_u238->GetEntries());
  printf("Number of entries in h_qedep_u234 %f \n", h_qedep_u234->GetEntries());
  printf("Number of entries in h_qedep_bi214 %f \n", h_qedep_bi214->GetEntries());
  printf("Number of entries in h_qedep_bi210 %f \n", h_qedep_bi210->GetEntries());
  printf("Number of entries in h_qedep_pa234 %f \n", h_qedep_pa234->GetEntries());
  printf("Number of entries in h_qedep_pb210 %f \n", h_qedep_pb210->GetEntries());
  printf("Number of entries in h_qedep_pb214 %f \n", h_qedep_pb214->GetEntries());
  printf("Number of entries in h_qedep_po210 %f \n", h_qedep_po210->GetEntries());
  printf("Number of entries in h_qedep_po214 %f \n", h_qedep_po214->GetEntries());
  printf("Number of entries in h_qedep_po218 %f \n", h_qedep_po218->GetEntries());
  printf("Number of entries in h_qedep_ra226 %f \n", h_qedep_ra226->GetEntries());
  printf("Number of entries in h_qedep_rn222 %f \n", h_qedep_rn222->GetEntries());
  printf("Number of entries in h_qedep_th230 %f \n", h_qedep_th230->GetEntries());
  printf("Number of entries in h_qedep_th234 %f \n", h_qedep_th234->GetEntries());
  printf("Number of entries in h_qedep_sum %f \n", h_qedep_sum->GetEntries());


  double a = h_qedep_sum->Integral(h_qedep_sum->FindFixBin(0), h_qedep_sum->FindFixBin(8));
   printf("whole chain activity =  %f \n", a );

  legend->Draw();
}
