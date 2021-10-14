#include <fstream>

void rvse(){
  TH2F *h_u238 = new TH2F("h_u238","",1000,0,3,1000,0,10);
  TH2F *h_th232 = new TH2F("h_th232","",1000,0,3,1000,0,10);
  TH2F *h_k40 = new TH2F("h_k40","",1000,0,3,1000,0,10);
//  TH2F *h_pb210 = new TH2F("h_pb210","",1000,0,3,1000,0,10);
//  TH2F *h_sum = new TH2F("h_sum","",1000,0,3,1000,0,10);

  h_u238->GetXaxis()->SetTitle("Energy Cut [MeV]");
  h_u238->GetYaxis()->SetTitle("Rate [Decays/Second]");
  h_u238->SetTitle("Background Rate vs Energy Cut in Liquid Scintillator");

  fstream file_u238, file_th232, file_k40, file_pb210;
  file_u238.open("u238_r_vs_e_fv.txt", ios::in);
  file_th232.open("th232_r_vs_e_fv.txt", ios::in);
  file_k40.open("k40_r_vs_e_fv.txt", ios::in);
//  file_pb210.open("pb_r_vs_e_fv.txt", ios::in);

  while (1) {
    double e_u238, e_th232, e_k40, e_pb210, r_u238, r_th232, r_k40, r_pb210;

    file_u238 >> e_u238 >> r_u238;
    h_u238->Fill(e_u238,r_u238);
    if(file_u238.eof()) break;


    file_th232 >> e_th232 >> r_th232;
    h_th232->Fill(e_th232,r_th232);
    if(file_th232.eof()) break;

    file_k40 >> e_k40 >> r_k40;
    h_k40->Fill(e_k40,r_k40);
    if(file_k40.eof()) break;

//    file_pb210 >> e_pb210 >> r_pb210;
//    h_pb210->Fill(e_pb210,r_pb210);
  //  if(file_pb210.eof()) break;

  }

  file_u238.close();
  file_th232.close();
  file_k40.close();
//  file_pb210.close();

  TH2F *h_sum = (TH2F*)h_u238->Clone("h_sum");
  h_sum->Add(h_th232);
  h_sum->Add(h_k40);
//  h_sum->Add(h_pb210);

  auto legend = new TLegend(0.6,0.5,0.9,0.9);
  legend->AddEntry(h_u238, "U-238", "p");
  legend->AddEntry(h_th232, "Th-232", "p");
  legend->AddEntry(h_k40, "K-40", "p");
//  legend->AddEntry(h_pb210, "Pb-210", "p");
  legend->AddEntry(h_sum, "Total rate", "p");

  TCanvas *c1 = new TCanvas("c1","c1");
  c1->cd();
  c1->SetLogy();
  gStyle->SetOptStat(0);
  h_u238->Draw();
  h_u238->SetMarkerStyle(20);
  h_u238->SetMarkerColor(9);

  h_th232->Draw("SAME");
  h_th232->SetMarkerStyle(21);
  h_th232->SetMarkerColor(2);

  h_k40->Draw("SAME");
  h_k40->SetMarkerStyle(22);
  h_k40->SetMarkerColor(4);

//  h_pb210->Draw("SAME");
//  h_pb210->SetMarkerStyle(33);
//  h_pb210->SetMarkerColor(8);

//  h_sum->Draw("SAME");
  h_sum->SetMarkerStyle(34);
  h_sum->SetMarkerColor(1);

legend->Draw();
c1->Print("R_vs_E_AV.pdf");
}
