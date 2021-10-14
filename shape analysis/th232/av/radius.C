#include <fstream>

void readtree(){


  TFile *tf_th232 = new TFile("th232trees_init.root");
  TFile *tf_ra228 = new TFile("ra228trees_init.root");
  TFile *tf_ac228 = new TFile("ac228trees_init.root");
  TFile *tf_th228 = new TFile("th228trees_init.root");
  TFile *tf_ra224 = new TFile("ra224trees_init.root");
  TFile *tf_rn220 = new TFile("rn220trees_init.root");
  TFile *tf_po216 = new TFile("po216trees_init.root");
  TFile *tf_pb212 = new TFile("pb212trees_init.root");
  TFile *tf_bi212 = new TFile("bi212trees_init.root");
  TFile *tf_tl208 = new TFile("tl208trees_init.root");
  TFile *tf_po212 = new TFile("po212trees_init.root");

  //th232

  TTree *tree_th232 = (TTree*) tf_th232->Get("tree_th232");
  float qedep_th232;
  tree_th232->SetBranchAddress("Qedep",&qedep_th232);
  tree_th232->Draw("sqrt(edepX^2+edepY^2+edepZ^2)>>h_pos_th232(18000,0,18000)","sqrt(InitX*InitX + InitY*InitY + InitZ*InitZ) <18000 && Qedep>0.7","");
  TH1F *h_pos_th232 = (TH1F*)gDirectory->Get("h_pos_th232");


  // ra228
  TTree *tree_ra228 = (TTree*) tf_ra228->Get("tree_ra228");
  float qedep_ra228;
  tree_ra228->SetBranchAddress("Qedep",&qedep_ra228);
  tree_ra228->Draw("sqrt(edepX^2+edepY^2+edepZ^2)>>h_pos_ra228(18000,0,18000)","sqrt(InitX*InitX + InitY*InitY + InitZ*InitZ) <18000 && Qedep>0.7","");
  TH1F *h_pos_ra228 = (TH1F*)gDirectory->Get("h_pos_ra228");



  // ac228
  TTree *tree_ac228 = (TTree*) tf_ac228->Get("tree_ac228");
  float qedep_ac228;
  tree_ac228->SetBranchAddress("Qedep",&qedep_ac228);
  tree_ac228->Draw("sqrt(edepX^2+edepY^2+edepZ^2)>>h_pos_ac228(18000,0,18000)","sqrt(InitX*InitX + InitY*InitY + InitZ*InitZ) <18000 && Qedep>0.7","");
  TH1F *h_pos_ac228 = (TH1F*)gDirectory->Get("h_pos_ac228");


  // th228
    TTree *tree_th228 = (TTree*) tf_th228->Get("tree_th228");
    float qedep_th228;
    tree_th228->SetBranchAddress("Qedep",&qedep_th228);
    tree_th228->Draw("sqrt(edepX^2+edepY^2+edepZ^2)>>h_pos_th228(18000,0,18000)","sqrt(InitX*InitX + InitY*InitY + InitZ*InitZ) <18000 && Qedep>0.7","");
    TH1F *h_pos_th228 = (TH1F*)gDirectory->Get("h_pos_th228");


  // ra224
    TTree *tree_ra224 = (TTree*) tf_ra224->Get("tree_ra224");
    float qedep_ra224;
    tree_ra224->SetBranchAddress("Qedep",&qedep_ra224);
    tree_ra224->Draw("sqrt(edepX^2+edepY^2+edepZ^2)>>h_pos_ra224(18000,0,18000)","sqrt(InitX*InitX + InitY*InitY + InitZ*InitZ) <18000 && Qedep>0.7","");
    TH1F *h_pos_ra224 = (TH1F*)gDirectory->Get("h_pos_ra224");

    // rn220
    TTree *tree_rn220 = (TTree*) tf_rn220->Get("tree_rn220");
    float qedep_rn220;
    tree_rn220->SetBranchAddress("Qedep",&qedep_rn220);
    tree_rn220->Draw("sqrt(edepX^2+edepY^2+edepZ^2)>>h_pos_rn220(18000,0,18000)","sqrt(InitX*InitX + InitY*InitY + InitZ*InitZ) <18000 && Qedep>0.7","");
    TH1F *h_pos_rn220 = (TH1F*)gDirectory->Get("h_pos_rn220");



    // po216
    TTree *tree_po216 = (TTree*) tf_po216->Get("tree_po216");
    float qedep_po216;
    tree_po216->SetBranchAddress("Qedep",&qedep_po216);
    tree_po216->Draw("sqrt(edepX^2+edepY^2+edepZ^2)>>h_pos_po216(18000,0,18000)","sqrt(InitX*InitX + InitY*InitY + InitZ*InitZ) <18000 && Qedep>0.7","");
    TH1F *h_pos_po216 = (TH1F*)gDirectory->Get("h_pos_po216");


    // pb212
    TTree *tree_pb212 = (TTree*) tf_pb212->Get("tree_pb212");
    float qedep_pb212;
    tree_pb212->SetBranchAddress("Qedep",&qedep_pb212);
    tree_pb212->Draw("sqrt(edepX^2+edepY^2+edepZ^2)>>h_pos_pb212(18000,0,18000)","sqrt(InitX*InitX + InitY*InitY + InitZ*InitZ) <18000 && Qedep>0.7","");
    TH1F *h_pos_pb212 = (TH1F*)gDirectory->Get("h_pos_pb212");



    // bi212
    TTree *tree_bi212 = (TTree*) tf_bi212->Get("tree_bi212");
    float qedep_bi212;
    tree_bi212->SetBranchAddress("Qedep",&qedep_bi212);
    tree_bi212->Draw("sqrt(edepX^2+edepY^2+edepZ^2)>>h_pos_bi212(18000,0,18000)","sqrt(InitX*InitX + InitY*InitY + InitZ*InitZ) <18000 && Qedep>0.7","");
    TH1F *h_pos_bi212 = (TH1F*)gDirectory->Get("h_pos_bi212");



    // tl208
    TTree *tree_tl208 = (TTree*) tf_tl208->Get("tree_tl208");
    float qedep_tl208;
    tree_tl208->SetBranchAddress("Qedep",&qedep_tl208);
    tree_tl208->Draw("sqrt(edepX^2+edepY^2+edepZ^2)>>h_pos_tl208(18000,0,18000)","sqrt(InitX*InitX + InitY*InitY + InitZ*InitZ) <18000 && Qedep>0.7","");
    TH1F *h_pos_tl208 = (TH1F*)gDirectory->Get("h_pos_tl208");


    // po212
    TTree *tree_po212 = (TTree*) tf_po212->Get("tree_po212");
    float qedep_po212;
    tree_po212->SetBranchAddress("Qedep",&qedep_po212);
    tree_po212->Draw("sqrt(edepX^2+edepY^2+edepZ^2)>>h_pos_po212(18000,0,18000)","sqrt(InitX*InitX + InitY*InitY + InitZ*InitZ) <18000 && Qedep>0.7","");
    TH1F *h_pos_po212 = (TH1F*)gDirectory->Get("h_pos_po212");




    h_pos_tl208->Scale(0.3594);
    h_pos_po212->Scale(0.6406);


  TH1F *h_pos_sum = (TH1F*)h_pos_th232->Clone("h_pos_sum");
  h_pos_sum->Add(h_pos_ra228);
  h_pos_sum->Add(h_pos_ac228);
  h_pos_sum->Add(h_pos_th228);
  h_pos_sum->Add(h_pos_ra224);
  h_pos_sum->Add(h_pos_rn220);
  h_pos_sum->Add(h_pos_po216);
  h_pos_sum->Add(h_pos_pb212);
  h_pos_sum->Add(h_pos_bi212);
  h_pos_sum->Add(h_pos_tl208);
  h_pos_sum->Add(h_pos_po212);


/*


  h_pos_th232->SetLineColor(1);
  h_pos_ra228->SetLineColor(2);
  h_pos_ac228->SetLineColor(3);
  h_pos_th228->SetLineColor(4);
  h_pos_ra224->SetLineColor(5);
  h_pos_rn220->SetLineColor(6);
  h_pos_po216->SetLineColor(7);
  h_pos_pb212->SetLineColor(8);
  h_pos_bi212->SetLineColor(49);
  h_pos_tl208->SetLineColor(28);
  h_pos_po212->SetLineColor(46);


  h_pos_sum->SetLineColor(1);
  h_pos_sum->SetLineWidth(2);




  auto legend = new TLegend(0.8,0.5,0.9,0.9);
  legend->AddEntry(h_pos_th232, "Th-232 - #alpha decay", "l");
  legend->AddEntry(h_pos_ra228, "Ra-228 - #beta decay", "l");
  legend->AddEntry(h_pos_ac228, "Ac-228 - #beta decay", "l");
  legend->AddEntry(h_pos_th228, "Th-228 - #alpha decay", "l");
  legend->AddEntry(h_pos_ra224, "Ra-224 - #alpha decay", "l");
  legend->AddEntry(h_pos_rn220, "Rn-220 - #alpha decay", "l");
  legend->AddEntry(h_pos_po216, "Po-216 - #alpha decay ", "l");
  legend->AddEntry(h_pos_pb212, "Pb-212 - #beta decay", "l");
  legend->AddEntry(h_pos_bi212, "Bi-212 - #alpha + #beta decay", "l");
  legend->AddEntry(h_pos_tl208, "Tl-208 - #beta decay", "l");
  legend->AddEntry(h_pos_po212, "Po-212 - #alpha decay", "l");
  legend->AddEntry(h_pos_sum, "Total Spectrum", "l");


*/
  TH2F *h_guide = new TH2F("h_guide","sqrt(InitX*InitX + InitY*InitY + InitZ*InitZ) <18000 && Qedep>0.7",1,0,18000,1,0,500000);

  h_guide->GetXaxis()->SetTitle("Quenched energy [MeV]");
  h_guide->GetYaxis()->SetTitle("Counts / 2 keV");
  h_guide->SetTitle("Quenched Energy  - th232 Chain in LS - Unstacked 0:4 ");

  // draw histogram
  TCanvas *c1 = new TCanvas("c1","c1");
  c1->cd();
  c1->SetLogy();
//  gStyle->SetOptStat(0);
/*
  h_guide->Draw();
  h_pos_th232->Draw("SAME");
  h_pos_ra228->Draw("SAME");
  h_pos_ac228->Draw("SAME");
  h_pos_th228->Draw("SAME");
  h_pos_ra224->Draw("SAME");
  h_pos_rn220->Draw("SAME");
  h_pos_po216->Draw("SAME");
  h_pos_pb212->Draw("SAME");
  h_pos_bi212->Draw("SAME");
  h_pos_tl208->Draw("SAME");
  h_pos_po212->Draw("SAME");
*/
 h_pos_sum->Draw();


  printf("Number of entries in h_pos_th232 %f \n", h_pos_th232->GetEntries());
  printf("Number of entries in h_pos_ra228 %f \n", h_pos_ra228->GetEntries());
  printf("Number of entries in h_pos_ac228 %f \n", h_pos_ac228->GetEntries());
  printf("Number of entries in h_pos_th228 %f \n", h_pos_th228->GetEntries());
  printf("Number of entries in h_pos_ra224 %f \n", h_pos_ra224->GetEntries());
  printf("Number of entries in h_pos_rn220 %f \n", h_pos_rn220->GetEntries());
  printf("Number of entries in h_pos_po216 %f \n", h_pos_po216->GetEntries());
  printf("Number of entries in h_pos_pb212 %f \n", h_pos_pb212->GetEntries());
  printf("Number of entries in h_pos_bi212 %f \n", h_pos_bi212->GetEntries());
  printf("Number of entries in h_pos_tl208 %f \n", h_pos_tl208->GetEntries());
  printf("Number of entries in h_pos_po212 %f \n", h_pos_po212->GetEntries());

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
