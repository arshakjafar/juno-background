#include <fstream>

void rvsr(){
  TGraph *gr_u238 = new TGraph();
  TGraph *gr_th232 = new TGraph();
  TGraph *gr_k40 = new TGraph();
  TGraph *gr_pb210 = new TGraph();
  TGraph *gr_sum = new TGraph();

  fstream file_u238, file_th232, file_k40, file_pb210;
  file_u238.open("u238_rvsr.txt", ios::in);
  file_th232.open("th232_rvsr.txt", ios::in);
  file_k40.open("k40_rvsr.txt", ios::in);
  file_pb210.open("pb210_rvsr.txt", ios::in);

  int counter=0;

  while (1) {
    float e_u238, e_th232, e_k40, e_pb210, r_u238, r_th232, r_k40, r_pb210;  // e is not energy but radius

    file_u238 >> e_u238 >> r_u238;
//    cout << "U238 " << counter << ": " << e_u238 << " " << r_u238 << endl;
    gr_u238->SetPoint(counter,e_u238, r_u238);

    file_th232 >> e_th232 >> r_th232;
//    cout << "Th232 " << counter << ": " << e_th232 << " " << r_th232 << endl;
    gr_th232->SetPoint(counter,e_th232, r_th232);

    file_k40 >> e_k40 >> r_k40;
//    cout << "K40 " << counter << ": " << e_k40 << " " << r_k40 << endl;
    gr_k40->SetPoint(counter,e_k40, r_k40);

    file_pb210 >> e_pb210 >> r_pb210;
//    cout << "Pb210 " << counter << ": " << e_pb210 << " " << r_pb210 << endl;
    gr_pb210->SetPoint(counter,e_pb210, r_pb210);

    gr_sum->SetPoint(counter,e_u238,r_u238+r_th232+r_k40+r_pb210);

    cout << e_u238 << " " << r_u238+r_th232+r_k40+r_pb210 << endl;

    if(file_u238.eof()) break;
    if(file_th232.eof()) break;
    if(file_k40.eof()) break;
    if(file_pb210.eof()) break;

    counter+=1;
  }

  file_u238.close();
  file_th232.close();
  file_k40.close();
  file_pb210.close();

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

  gr_pb210->SetName("gr_pb210");
  gr_pb210->SetTitle("Pb210");
  gr_pb210->SetMarkerColor(6);
  gr_pb210->SetLineColor(6);
  gr_pb210->SetMarkerStyle(33);
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
  mg->Add(gr_pb210);



  TCanvas *c1 = new TCanvas("c1","c1");
  c1->cd();
  c1->SetLogy();
  gStyle->SetOptStat(0);
  mg->Draw("ALP");
  mg->GetXaxis()->SetTitle("Radius [m]");
  mg->GetYaxis()->SetTitle("Rate [Hz]");

  c1->BuildLegend();

  mg->GetHistogram()->SetTitle("Rate vs Radius in Liquid Scintillator With E_{th} 0.7 MeV");

  c1->Print("R_vs_R_LS_v4.pdf");
}
