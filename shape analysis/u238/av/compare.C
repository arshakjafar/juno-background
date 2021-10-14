#include <fstream>

void compare(){
  TFile *tf_jie = new TFile("radioSpec_require.root");
  TFile *tf_arsh = new TFile("U238av.root");

   TH2F *h_jie = (TH2F*)tf_jie->Get("Acrylic_U238");
   TH2F *h_arsh = (TH2F*)tf_arsh->Get("h_qedep_sum");
   TH1D *py= h_jie->ProjectionY(" ",0,6000,"");

   //double_t norm = 776259/13.6293;
   //h_arsh->Scale(1/norm);

   py->SetLineColor(1);
   h_arsh->SetLineColor(2);

   auto legend = new TLegend(0.8,0.5,0.9,0.9);
   legend->AddEntry(py, "Jie's histo", "l");
   legend->AddEntry(h_arsh, "our histo", "l");

   TH2F *h_guide = new TH2F("h_guide","",1,0,4,1,0,0.3);
   h_guide->GetXaxis()->SetTitle("Energy [MeV]");
   h_guide->GetYaxis()->SetTitle("Counts");
   h_guide->SetTitle("U238 AV comparison ");


   TCanvas *c1 = new TCanvas("c1","c1");
   c1->cd();
   gStyle->SetOptStat(0);
   h_guide->Draw();
   py->Draw("HIST L SAME");
   h_arsh->Draw("HIST L SAME");
   legend->Draw();


      TH2F *h_guide1 = new TH2F("h_guide1","",1,0,1,1,0,0.3);
      h_guide1->GetXaxis()->SetTitle("Energy [MeV]");
      h_guide1->GetYaxis()->SetTitle("Counts");
      h_guide1->SetTitle("U238 AV comparison ");


      TCanvas *c2 = new TCanvas("c2","c2");
      c2->cd();
      gStyle->SetOptStat(0);
      h_guide1->Draw();
      py->Draw("SAME");
      h_arsh->Draw("SAME");
      legend->Draw();
      

           double b = py->Integral(py->FindFixBin(0.7), py->FindFixBin(8));
          printf("jie's number of events over 0.7 MeV =  %f \n", b );

}
