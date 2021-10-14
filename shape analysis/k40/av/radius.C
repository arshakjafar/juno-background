#include <fstream>

void readtree(){


  TFile *tf_k40 = new TFile("k40avtrees_init.root");


  //k40

  TTree *tree_k40 = (TTree*) tf_k40->Get("tree_k40");
  float qedep_k40;
  tree_k40->SetBranchAddress("Qedep",&qedep_k40);
  tree_k40->Draw("sqrt(edepX^2+edepY^2+edepZ^2)>>h_pos_k40(18000,0,18000)","sqrt(InitX*InitX + InitY*InitY + InitZ*InitZ)<18000","");
  TH1F *h_pos_k40 = (TH1F*)gDirectory->Get("h_pos_k40");




/*

  auto legend = new TLegend(0.8,0.5,0.9,0.9);
  legend->AddEntry(h_pos_k40, "Th-232 - #alpha decay", "l");
*/
  TH2F *h_guide = new TH2F("h_guide","",1,0,8,1,0.5,1000000);

  h_guide->GetXaxis()->SetTitle("Quenched energy [MeV]");
  h_guide->GetYaxis()->SetTitle("Counts / 2 keV");
  h_guide->SetTitle("Quenched Energy  - k40 Chain in LS - Unstacked 0:4 ");

  // draw histogram
  TCanvas *c1 = new TCanvas("c1","c1");
  c1->cd();
  c1->SetLogy();
  gStyle->SetOptStat(0);

//  h_guide->Draw();
  h_pos_k40->Draw();



  printf("Number of entries in h_pos_k40 %f \n", h_pos_k40->GetEntries());


  double a0 = h_pos_k40->Integral(h_pos_k40->FindFixBin(0), h_pos_k40->FindFixBin(13000));
 printf("13 =  %f \n", a0 );

 double a1 = h_pos_k40->Integral(h_pos_k40->FindFixBin(0), h_pos_k40->FindFixBin(14000));
printf("14 =  %f \n", a1 );

double a2 = h_pos_k40->Integral(h_pos_k40->FindFixBin(0), h_pos_k40->FindFixBin(15000));
printf("15 =  %f \n", a2 );

double a3 = h_pos_k40->Integral(h_pos_k40->FindFixBin(0), h_pos_k40->FindFixBin(16000));
printf("16 =  %f \n", a3 );

double a4 = h_pos_k40->Integral(h_pos_k40->FindFixBin(0), h_pos_k40->FindFixBin(16100));
printf("16.1 =  %f \n", a4 );


double a5 = h_pos_k40->Integral(h_pos_k40->FindFixBin(0), h_pos_k40->FindFixBin(16200));
printf("16.2 =  %f \n", a5 );


double a6 = h_pos_k40->Integral(h_pos_k40->FindFixBin(0), h_pos_k40->FindFixBin(16300));
printf("16.3 =  %f \n", a6 );


double a7 = h_pos_k40->Integral(h_pos_k40->FindFixBin(0), h_pos_k40->FindFixBin(16400));
printf("16.4 =  %f \n", a7 );

double a8 = h_pos_k40->Integral(h_pos_k40->FindFixBin(0), h_pos_k40->FindFixBin(16500));
printf("16.5 =  %f \n", a8 );


double a9 = h_pos_k40->Integral(h_pos_k40->FindFixBin(0), h_pos_k40->FindFixBin(16600));
printf("16.6 =  %f \n", a9 );

double a10 = h_pos_k40->Integral(h_pos_k40->FindFixBin(0), h_pos_k40->FindFixBin(16700));
printf("16.7 =  %f \n", a10 );


double a11 = h_pos_k40->Integral(h_pos_k40->FindFixBin(0), h_pos_k40->FindFixBin(16800));
printf("16.8 =  %f \n", a11 );


double a12 = h_pos_k40->Integral(h_pos_k40->FindFixBin(0), h_pos_k40->FindFixBin(16900));
printf("16.9 =  %f \n", a12 );


double a13 = h_pos_k40->Integral(h_pos_k40->FindFixBin(0), h_pos_k40->FindFixBin(17000));
printf("17 =  %f \n", a13 );


double a14 = h_pos_k40->Integral(h_pos_k40->FindFixBin(0), h_pos_k40->FindFixBin(17100));
printf("17.1 =  %f \n", a14 );


double a15 = h_pos_k40->Integral(h_pos_k40->FindFixBin(0), h_pos_k40->FindFixBin(17200));
printf("17.2 =  %f \n", a15 );


double a16 = h_pos_k40->Integral(h_pos_k40->FindFixBin(0), h_pos_k40->FindFixBin(17300));
printf("17.3 =  %f \n", a16 );


double a17 = h_pos_k40->Integral(h_pos_k40->FindFixBin(0), h_pos_k40->FindFixBin(17400));
printf("17.4 =  %f \n", a17 );


double a18 = h_pos_k40->Integral(h_pos_k40->FindFixBin(0), h_pos_k40->FindFixBin(17500));
printf("17.5 =  %f \n", a18 );


double a19 = h_pos_k40->Integral(h_pos_k40->FindFixBin(0), h_pos_k40->FindFixBin(17600));
printf("17.6 =  %f \n", a19 );




  double a = h_pos_k40->Integral(h_pos_k40->FindFixBin(0), h_pos_k40->FindFixBin(17700));
 printf("17.7 =  %f \n", a );


//  legend->Draw();
}
