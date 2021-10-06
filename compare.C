#include <fstream>

void compare(){
  TFile *tf_jie = new TFile("Acrilico_U238_0-12_17.7.root");
  TFile *tf_arsh = new TFile("U238av.root");

   TH1F *h_andrea = (TH1F*)tf_jie->Get("h");
   TH1F *h_arsh = (TH1F*)tf_arsh->Get("h_qedep_sum");
   //TH1D *py= h_jie->ProjectionY(" ",0,6000,"");

  // double_t norm = 14.18386;
//   h_arsh->Scale(norm);

   h_andrea->SetLineColor(1);
   h_arsh->SetLineColor(2);

   auto legend = new TLegend(0.8,0.5,0.9,0.9);
   legend->AddEntry(h_andrea, "Andrea's histo", "l");
   legend->AddEntry(h_arsh, "our histo", "l");

   TH2F *h_guide = new TH2F("h_guide","",1,0,4,1,0,700000);
   h_guide->GetXaxis()->SetTitle("Energy [MeV]");
   h_guide->GetYaxis()->SetTitle("Counts");
   h_guide->SetTitle("U238 AV comparison ");


   TCanvas *c1 = new TCanvas("c1","c1");
   c1->cd();
   gStyle->SetOptStat(0);
   h_guide->Draw();
   h_andrea->Draw("SAME");
   h_arsh->Draw("HIST L SAME");
   legend->Draw();


      TH2F *h_guide1 = new TH2F("h_guide1","",1,0,1,1,0,700000);
      h_guide1->GetXaxis()->SetTitle("Energy [MeV]");
      h_guide1->GetYaxis()->SetTitle("Counts");
      h_guide1->SetTitle("U238 AV comparison ");


      TCanvas *c2 = new TCanvas("c2","c2");
      c2->cd();
      gStyle->SetOptStat(0);
      h_guide1->Draw();
      h_andrea->Draw("SAME");
      h_arsh->Draw("HIST L SAME");
      legend->Draw();

      double a = h_arsh->Integral(h_arsh->FindFixBin(0.7), h_arsh->FindFixBin(8));
     printf("Arshaks number of events over 0.7 MeV =  %f \n", a );

           double b = h_andrea->Integral(h_andrea->FindFixBin(0.7), h_andrea->FindFixBin(8));
          printf("Andrea's number of events over 0.7 MeV =  %f \n", b );

}
