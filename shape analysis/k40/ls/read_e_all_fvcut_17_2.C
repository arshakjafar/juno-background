#include <fstream>

void readtree(){


  TFile *tf_k40 = new TFile("k40lstrees.root");


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

      double a19 = h_qedep_k40->Integral(h_qedep_k40->FindFixBin(0.1), h_qedep_k40->FindFixBin(8));
      printf("number of events over 0.1 MeV =  %f \n", a19 );

      double a18 = h_qedep_k40->Integral(h_qedep_k40->FindFixBin(0.2), h_qedep_k40->FindFixBin(8));
      printf("number of events over 0.2 MeV =  %f \n", a18 );


      double a17 = h_qedep_k40->Integral(h_qedep_k40->FindFixBin(0.3), h_qedep_k40->FindFixBin(8));
      printf("number of events over 0.3 MeV =  %f \n", a17 );

      double a16 = h_qedep_k40->Integral(h_qedep_k40->FindFixBin(0.4), h_qedep_k40->FindFixBin(8));
      printf("number of events over 0.4 MeV =  %f \n", a16 );



      double a0 = h_qedep_k40->Integral(h_qedep_k40->FindFixBin(0.5), h_qedep_k40->FindFixBin(8));
       printf("number of events over 0.5 MeV =  %f \n", a0 );

      double a1 = h_qedep_k40->Integral(h_qedep_k40->FindFixBin(0.6), h_qedep_k40->FindFixBin(8));
       printf("number of events over 0.6 MeV =  %f \n", a1 );

       double a2 = h_qedep_k40->Integral(h_qedep_k40->FindFixBin(0.7), h_qedep_k40->FindFixBin(8));
        printf("number of events over 0.7 MeV =  %f \n", a2 );

        double a3 = h_qedep_k40->Integral(h_qedep_k40->FindFixBin(0.8), h_qedep_k40->FindFixBin(8));
        printf("number of events over 0.8 MeV =  %f \n", a3 );

        double a4 = h_qedep_k40->Integral(h_qedep_k40->FindFixBin(0.9), h_qedep_k40->FindFixBin(8));
        printf("number of events over 0.9 MeV =  %f \n", a4 );

        double a5 = h_qedep_k40->Integral(h_qedep_k40->FindFixBin(1), h_qedep_k40->FindFixBin(8));
        printf("number of events over 1 MeV =  %f \n", a5 );

        double a6 = h_qedep_k40->Integral(h_qedep_k40->FindFixBin(1.1), h_qedep_k40->FindFixBin(8));
        printf("number of events over 1.1 MeV =  %f \n", a6 );

        double a7 = h_qedep_k40->Integral(h_qedep_k40->FindFixBin(1.2), h_qedep_k40->FindFixBin(8));
        printf("number of events over 1.2 MeV =  %f \n", a7 );

        double a8 = h_qedep_k40->Integral(h_qedep_k40->FindFixBin(1.3), h_qedep_k40->FindFixBin(8));
        printf("number of events over 1.3 MeV =  %f \n", a8 );

        double a9 = h_qedep_k40->Integral(h_qedep_k40->FindFixBin(1.4), h_qedep_k40->FindFixBin(8));
        printf("number of events over 1.4 MeV =  %f \n", a9 );

        double a10 = h_qedep_k40->Integral(h_qedep_k40->FindFixBin(1.5), h_qedep_k40->FindFixBin(8));
        printf("number of events over 1.5 MeV =  %f \n", a10 );

        double a11 = h_qedep_k40->Integral(h_qedep_k40->FindFixBin(1.6), h_qedep_k40->FindFixBin(8));
        printf("number of events over 1.6 MeV =  %f \n", a11 );

        double a12 = h_qedep_k40->Integral(h_qedep_k40->FindFixBin(1.7), h_qedep_k40->FindFixBin(8));
        printf("number of events over 1.7 MeV =  %f \n", a12 );

        double a13 = h_qedep_k40->Integral(h_qedep_k40->FindFixBin(1.8), h_qedep_k40->FindFixBin(8));
        printf("number of events over 1.8 MeV =  %f \n", a13 );

        double a14 = h_qedep_k40->Integral(h_qedep_k40->FindFixBin(1.9), h_qedep_k40->FindFixBin(8));
        printf("number of events over 1.9 MeV =  %f \n", a14 );

        double a15 = h_qedep_k40->Integral(h_qedep_k40->FindFixBin(2), h_qedep_k40->FindFixBin(8));
        printf("number of events over 2 MeV =  %f \n", a15 );


  legend->Draw();
}
