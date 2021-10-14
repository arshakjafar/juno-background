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
//  tree_u238->Draw("sqrt(edepX^2+edepY^2+edepZ^2)>>h_pos_u238(18000,0,18000)","","");
  tree_u238->Draw("sqrt(edepX^2+edepY^2+edepZ^2)>>h_pos_u238(18000,0,18000)","","");
  TH1F *h_pos_u238 = (TH1F*)gDirectory->Get("h_pos_u238");


  // u234
  TTree *tree_u234 = (TTree*) tf_u234->Get("tree_u234");
  float qedep_u234;
  tree_u234->SetBranchAddress("Qedep",&qedep_u234);
  tree_u234->Draw("sqrt(edepX^2+edepY^2+edepZ^2)>>h_pos_u234(18000,0,18000)","","");
  TH1F *h_pos_u234 = (TH1F*)gDirectory->Get("h_pos_u234");



  // bi214
  TTree *tree_bi214 = (TTree*) tf_bi214->Get("tree_bi214");
  float qedep_bi214;
  tree_bi214->SetBranchAddress("Qedep",&qedep_bi214);
  tree_bi214->Draw("sqrt(edepX^2+edepY^2+edepZ^2)>>h_pos_bi214(18000,0,18000)","","");
  TH1F *h_pos_bi214 = (TH1F*)gDirectory->Get("h_pos_bi214");


  // bi210
    TTree *tree_bi210 = (TTree*) tf_bi210->Get("tree_bi210");
    float qedep_bi210;
    tree_bi210->SetBranchAddress("Qedep",&qedep_bi210);
    tree_bi210->Draw("sqrt(edepX^2+edepY^2+edepZ^2)>>h_pos_bi210(18000,0,18000)","","");
    TH1F *h_pos_bi210 = (TH1F*)gDirectory->Get("h_pos_bi210");


  // pa234
    TTree *tree_pa234 = (TTree*) tf_pa234->Get("tree_pa234");
    float qedep_pa234;
    tree_pa234->SetBranchAddress("Qedep",&qedep_pa234);
    tree_pa234->Draw("sqrt(edepX^2+edepY^2+edepZ^2)>>h_pos_pa234(18000,0,18000)","","");
    TH1F *h_pos_pa234 = (TH1F*)gDirectory->Get("h_pos_pa234");

    // pb210
    TTree *tree_pb210 = (TTree*) tf_pb210->Get("tree_pb210");
    float qedep_pb210;
    tree_pb210->SetBranchAddress("Qedep",&qedep_pb210);
    tree_pb210->Draw("sqrt(edepX^2+edepY^2+edepZ^2)>>h_pos_pb210(18000,0,18000)","","");
    TH1F *h_pos_pb210 = (TH1F*)gDirectory->Get("h_pos_pb210");



    // pb214
    TTree *tree_pb214 = (TTree*) tf_pb214->Get("tree_pb214");
    float qedep_pb214;
    tree_pb214->SetBranchAddress("Qedep",&qedep_pb214);
    tree_pb214->Draw("sqrt(edepX^2+edepY^2+edepZ^2)>>h_pos_pb214(18000,0,18000)","","");
    TH1F *h_pos_pb214 = (TH1F*)gDirectory->Get("h_pos_pb214");


    // po210
    TTree *tree_po210 = (TTree*) tf_po210->Get("tree_po210");
    float qedep_po210;
    tree_po210->SetBranchAddress("Qedep",&qedep_po210);
    tree_po210->Draw("sqrt(edepX^2+edepY^2+edepZ^2)>>h_pos_po210(18000,0,18000)","","");
    TH1F *h_pos_po210 = (TH1F*)gDirectory->Get("h_pos_po210");



    // po214
    TTree *tree_po214 = (TTree*) tf_po214->Get("tree_po214");
    float qedep_po214;
    tree_po214->SetBranchAddress("Qedep",&qedep_po214);
    tree_po214->Draw("sqrt(edepX^2+edepY^2+edepZ^2)>>h_pos_po214(18000,0,18000)","","");
    TH1F *h_pos_po214 = (TH1F*)gDirectory->Get("h_pos_po214");



    // po218
    TTree *tree_po218 = (TTree*) tf_po218->Get("tree_po218");
    float qedep_po218;
    tree_po218->SetBranchAddress("Qedep",&qedep_po218);
    tree_po218->Draw("sqrt(edepX^2+edepY^2+edepZ^2)>>h_pos_po218(18000,0,18000)","","");
    TH1F *h_pos_po218 = (TH1F*)gDirectory->Get("h_pos_po218");


    // ra226
    TTree *tree_ra226 = (TTree*) tf_ra226->Get("tree_ra226");
    float qedep_ra226;
    tree_ra226->SetBranchAddress("Qedep",&qedep_ra226);
    tree_ra226->Draw("sqrt(edepX^2+edepY^2+edepZ^2)>>h_pos_ra226(18000,0,18000)","","");
    TH1F *h_pos_ra226 = (TH1F*)gDirectory->Get("h_pos_ra226");


    // rn222
    TTree *tree_rn222 = (TTree*) tf_rn222->Get("tree_rn222");
    float qedep_rn222;
    tree_rn222->SetBranchAddress("Qedep",&qedep_rn222);
    tree_rn222->Draw("sqrt(edepX^2+edepY^2+edepZ^2)>>h_pos_rn222(18000,0,18000)","","");
    TH1F *h_pos_rn222 = (TH1F*)gDirectory->Get("h_pos_rn222");



    // th230
    TTree *tree_th230 = (TTree*) tf_th230->Get("tree_th230");
    float qedep_th230;
    tree_th230->SetBranchAddress("Qedep",&qedep_th230);
    tree_th230->Draw("sqrt(edepX^2+edepY^2+edepZ^2)>>h_pos_th230(18000,0,18000)","","");
    TH1F *h_pos_th230 = (TH1F*)gDirectory->Get("h_pos_th230");



    // th234
    TTree *tree_th234 = (TTree*) tf_th234->Get("tree_th234");
    float qedep_th234;
    tree_th234->SetBranchAddress("Qedep",&qedep_th234);
    tree_th234->Draw("sqrt(edepX^2+edepY^2+edepZ^2)>>h_pos_th234(18000,0,18000)","","");
    TH1F *h_pos_th234 = (TH1F*)gDirectory->Get("h_pos_th234");




  TH1F *h_pos_sum = (TH1F*)h_pos_u238->Clone("h_pos_sum");
  h_pos_sum->Add(h_pos_u234);
  h_pos_sum->Add(h_pos_bi214);
  h_pos_sum->Add(h_pos_bi210);
  h_pos_sum->Add(h_pos_pa234);
  h_pos_sum->Add(h_pos_pb210);
  h_pos_sum->Add(h_pos_pb214);
  h_pos_sum->Add(h_pos_po210);
  h_pos_sum->Add(h_pos_po214);
  h_pos_sum->Add(h_pos_po218);
  h_pos_sum->Add(h_pos_ra226);
  h_pos_sum->Add(h_pos_rn222);
  h_pos_sum->Add(h_pos_th230);
  h_pos_sum->Add(h_pos_th234);


/*

  h_pos_u238->SetLineColor(1);
  h_pos_u234->SetLineColor(2);
  h_pos_bi214->SetLineColor(3);
  h_pos_bi210->SetLineColor(4);
  h_pos_pa234->SetLineColor(5);
  h_pos_pb210->SetLineColor(6);
  h_pos_pb214->SetLineColor(7);
  h_pos_po210->SetLineColor(8);
  h_pos_po214->SetLineColor(49);
  h_pos_po218->SetLineColor(28);
  h_pos_ra226->SetLineColor(46);
  h_pos_rn222->SetLineColor(14);
  h_pos_th230->SetLineColor(kTeal-6);
  h_pos_th234->SetLineColor(41);

  h_pos_sum->SetLineColor(1);
  h_pos_sum->SetLineWidth(2);



//  double_t norm = (14*0.2487*0.9176)/12846825;
//  h_pos_sum->Scale(norm);


  auto legend = new TLegend(0.8,0.5,0.9,0.9);
  legend->AddEntry(h_pos_u238, "U-238 - #alpha decay", "l");
  legend->AddEntry(h_pos_th234, "Th-234 - #beta decay", "l");
  legend->AddEntry(h_pos_pa234, "Pa-234 - #beta decay", "l");
  legend->AddEntry(h_pos_u234, "U-234 - #alpha decay", "l");
  legend->AddEntry(h_pos_th230, "Th-230 - #alpha decay", "l");
  legend->AddEntry(h_pos_ra226, "Ra-226 - #alpha decay", "l");
  legend->AddEntry(h_pos_rn222, "Rn-222 - #alpha decay", "l");
  legend->AddEntry(h_pos_po218, "Po-218 - #alpha decay", "l");
  legend->AddEntry(h_pos_pb214, "Pb-214 - #beta decay", "l");
  legend->AddEntry(h_pos_bi214, "Bi-214 - #beta decay ", "l");
  legend->AddEntry(h_pos_po214, "Po-214 - #alpha decay", "l");
  legend->AddEntry(h_pos_pb210, "Pb-210 - #beta decay", "l");
  legend->AddEntry(h_pos_bi210, "Bi-210 - #beta decay", "l");
  legend->AddEntry(h_pos_po210, "Po-210 - #alpha decay", "l");
  legend->AddEntry(h_pos_sum, "Total Spectrum", "l");

*/

  TH2F *h_guide = new TH2F("h_guide","",1,0,18000,1,0,50000);

  h_guide->GetXaxis()->SetTitle("Quenched energy [MeV]");
  h_guide->GetYaxis()->SetTitle("Counts / 2 keV");
  h_guide->SetTitle("Quenched Energy  - U238 Chain in LS - Unstacked 0:8 ");

  // draw histogram
  TCanvas *c1 = new TCanvas("c1","c1");
  c1->cd();
//  c1->SetLogy();
  gStyle->SetOptStat(0);



  h_guide->Draw();
  h_pos_u238->Draw("SAME");
  h_pos_u234->Draw("SAME");
  h_pos_bi214->Draw("SAME");
  h_pos_bi210->Draw("SAME");
  h_pos_pa234->Draw("SAME");
  h_pos_pb210->Draw("SAME");
  h_pos_pb214->Draw("SAME");
  h_pos_po210->Draw("SAME");
  h_pos_po214->Draw("SAME");
  h_pos_po218->Draw("SAME");
  h_pos_ra226->Draw("SAME");
  h_pos_rn222->Draw("SAME");
  h_pos_th230->Draw("SAME");
  h_pos_th234->Draw("SAME");
  h_pos_sum->Draw("SAME");




  printf("Number of entries in h_pos_u238 %f \n", h_pos_u238->GetEntries());
  printf("Number of entries in h_pos_u234 %f \n", h_pos_u234->GetEntries());
  printf("Number of entries in h_pos_bi214 %f \n", h_pos_bi214->GetEntries());
  printf("Number of entries in h_pos_bi210 %f \n", h_pos_bi210->GetEntries());
  printf("Number of entries in h_pos_pa234 %f \n", h_pos_pa234->GetEntries());
  printf("Number of entries in h_pos_pb210 %f \n", h_pos_pb210->GetEntries());
  printf("Number of entries in h_pos_pb214 %f \n", h_pos_pb214->GetEntries());
  printf("Number of entries in h_pos_po210 %f \n", h_pos_po210->GetEntries());
  printf("Number of entries in h_pos_po214 %f \n", h_pos_po214->GetEntries());
  printf("Number of entries in h_pos_po218 %f \n", h_pos_po218->GetEntries());
  printf("Number of entries in h_pos_ra226 %f \n", h_pos_ra226->GetEntries());
  printf("Number of entries in h_pos_rn222 %f \n", h_pos_rn222->GetEntries());
  printf("Number of entries in h_pos_th230 %f \n", h_pos_th230->GetEntries());
  printf("Number of entries in h_pos_th234 %f \n", h_pos_th234->GetEntries());
  printf("Number of entries in h_pos_sum %f \n", h_pos_sum->GetEntries());

  double a0 = h_pos_sum->Integral(h_pos_sum->FindFixBin(0), h_pos_sum->FindFixBin(13000));
 printf("13 =  %f \n", a0 );

 double a1 = h_pos_sum->Integral(h_pos_sum->FindFixBin(0), h_pos_sum->FindFixBin(14000));
printf("14 =  %f \n", a1 );

double a2 = h_pos_sum->Integral(h_pos_sum->FindFixBin(0), h_pos_sum->FindFixBin(15000));
printf("15 =  %f \n", a2 );

double a3 = h_pos_sum->Integral(h_pos_sum->FindFixBin(0), h_pos_sum->FindFixBin(16000));
printf("16 =  %f \n", a3 );

double a4 = h_pos_sum->Integral(h_pos_sum->FindFixBin(0), h_pos_sum->FindFixBin(16100));
printf("16.1 =  %f \n", a4 );


double a5 = h_pos_sum->Integral(h_pos_sum->FindFixBin(0), h_pos_sum->FindFixBin(16200));
printf("16.2 =  %f \n", a5 );


double a6 = h_pos_sum->Integral(h_pos_sum->FindFixBin(0), h_pos_sum->FindFixBin(16300));
printf("16.3 =  %f \n", a6 );


double a7 = h_pos_sum->Integral(h_pos_sum->FindFixBin(0), h_pos_sum->FindFixBin(16400));
printf("16.4 =  %f \n", a7 );

double a8 = h_pos_sum->Integral(h_pos_sum->FindFixBin(0), h_pos_sum->FindFixBin(16500));
printf("16.5 =  %f \n", a8 );


double a9 = h_pos_sum->Integral(h_pos_sum->FindFixBin(0), h_pos_sum->FindFixBin(16600));
printf("16.6 =  %f \n", a9 );

double a10 = h_pos_sum->Integral(h_pos_sum->FindFixBin(0), h_pos_sum->FindFixBin(16700));
printf("16.7 =  %f \n", a10 );


double a11 = h_pos_sum->Integral(h_pos_sum->FindFixBin(0), h_pos_sum->FindFixBin(16800));
printf("16.8 =  %f \n", a11 );


double a12 = h_pos_sum->Integral(h_pos_sum->FindFixBin(0), h_pos_sum->FindFixBin(16900));
printf("16.9 =  %f \n", a12 );


double a13 = h_pos_sum->Integral(h_pos_sum->FindFixBin(0), h_pos_sum->FindFixBin(17000));
printf("17 =  %f \n", a13 );


double a14 = h_pos_sum->Integral(h_pos_sum->FindFixBin(0), h_pos_sum->FindFixBin(17100));
printf("17.1 =  %f \n", a14 );


double a15 = h_pos_sum->Integral(h_pos_sum->FindFixBin(0), h_pos_sum->FindFixBin(17200));
printf("17.2 =  %f \n", a15 );


double a16 = h_pos_sum->Integral(h_pos_sum->FindFixBin(0), h_pos_sum->FindFixBin(17300));
printf("17.3 =  %f \n", a16 );


double a17 = h_pos_sum->Integral(h_pos_sum->FindFixBin(0), h_pos_sum->FindFixBin(17400));
printf("17.4 =  %f \n", a17 );


double a18 = h_pos_sum->Integral(h_pos_sum->FindFixBin(0), h_pos_sum->FindFixBin(17500));
printf("17.5 =  %f \n", a18 );


double a19 = h_pos_sum->Integral(h_pos_sum->FindFixBin(0), h_pos_sum->FindFixBin(17600));
printf("17.6 =  %f \n", a19 );




  double a = h_pos_sum->Integral(h_pos_sum->FindFixBin(0), h_pos_sum->FindFixBin(17700));
 printf("17.7 =  %f \n", a );



//  legend->Draw();
}
