#include <fstream>

void rvse(){
  TGraph *gr_u238 = new TGraph();
  TGraph *gr_th232 = new TGraph();
  TGraph *gr_k40 = new TGraph();

  TGraph *gr_sum = new TGraph();

  fstream file_u238, file_th232, file_k40, file_pb210;
  file_u238.open("u238_r_vs_e_fv.txt", ios::in);
  file_th232.open("th232_r_vs_e_fv.txt", ios::in);
  file_k40.open("k40_r_vs_e_fv.txt", ios::in);


  int counter=0;

  while (1) {
    float e_u238, e_th232, e_k40, e_pb210, r_u238, r_th232, r_k40, r_pb210;

    file_u238 >> e_u238 >> r_u238;
  //  cout << "U238 " << counter << ": " << e_u238 << " " << r_u238 << endl;
    gr_u238->SetPoint(counter,e_u238, r_u238);

    file_th232 >> e_th232 >> r_th232;
//    cout << "Th232 " << counter << ": " << e_th232 << " " << r_th232 << endl;
    gr_th232->SetPoint(counter,e_th232, r_th232);

    file_k40 >> e_k40 >> r_k40;
  //  cout << "K40 " << counter << ": " << e_k40 << " " << r_k40 << endl;
    gr_k40->SetPoint(counter,e_k40, r_k40);



    gr_sum->SetPoint(counter,e_u238,r_u238+r_th232+r_k40);

    cout << e_u238 << " " << r_u238+r_th232+r_k40 << endl;

    if(file_u238.eof()) break;
    if(file_th232.eof()) break;
    if(file_k40.eof()) break;


    counter+=1;
  }

  file_u238.close();
  file_th232.close();
  file_k40.close();


  TMultiGraph* mg = new TMultiGraph();


  gr_u238->SetName("gr_u238");
  gr_u238->SetTitle("U238");
  gr_u238->SetMarkerColor(3);
  gr_u238->SetLineColor(3);
  gr_u238->SetMarkerStyle(20);
  //gr_u238->Draw("APL");

  gr_th232->SetName("gr_th232");
  gr_th232->SetTitle("Th232");
  gr_th232->SetMarkerColor(2);
  gr_th232->SetLineColor(2);
  gr_th232->SetMarkerStyle(21);
  //gr_th232->Draw("PL");

  gr_k40->SetName("gr_k40");
  gr_k40->SetTitle("K40");
  gr_k40->SetMarkerColor(4);
  gr_k40->SetLineColor(4);
  gr_k40->SetMarkerStyle(22);
  //gr_th232->Draw("PL");


  //gr_th232->Draw("PL");

  gr_sum->SetName("gr_sum");
  gr_sum->SetTitle("Total");
  gr_sum->SetMarkerStyle(34);
  gr_sum->SetMarkerColor(1);
  gr_sum->SetLineColor(1);

  mg->Add(gr_sum);
  mg->Add(gr_u238);
  mg->Add(gr_th232);
  mg->Add(gr_k40);



  TCanvas *c1 = new TCanvas("c1","c1");
  c1->cd();
  c1->SetLogy();
  gStyle->SetOptStat(0);
  mg->Draw("ALP");
  mg->GetXaxis()->SetTitle("Energy threshold [MeV]");
  mg->GetYaxis()->SetTitle("Rate [Hz]");

  c1->BuildLegend();

  mg->GetHistogram()->SetTitle("Rate vs Energy Threshold in Acrylic Vessel With FV 17.2m");

  c1->Print("R_vs_E_AV_v2.pdf");
}
