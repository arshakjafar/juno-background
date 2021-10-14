#include <fstream>

void rvse(){
  TGraph *gr_ls = new TGraph();
  TGraph *gr_av = new TGraph();
  TGraph *gr_sum = new TGraph();

  fstream file_ls, file_av;

  file_ls.open("total_rvse_ls.txt", ios::in);
  file_av.open("total_rvse_av.txt", ios::in);

  int counter=0;

  while (1) {
    float e_ls, e_av, r_ls, r_av ; // e is not energy but radius

    file_ls >> e_ls >> r_ls ;
    gr_ls->SetPoint(counter,e_ls,r_ls);

    file_av >> e_av >> r_av ;
    gr_av->SetPoint(counter,e_av,r_av);

    gr_sum->SetPoint(counter,e_ls,r_ls+r_av);

    if(file_av.eof()) break;
    if(file_ls.eof()) break;

    counter+=1 ;
  }


  file_ls.close();
  file_av.close();

  TMultiGraph* mg = new TMultiGraph();

  gr_ls->SetName("gr_ls");
  gr_ls->SetTitle("LS");
  gr_ls->SetMarkerColor(2);
  gr_ls->SetLineColor(2);
  gr_ls->SetMarkerStyle(21);


  gr_av->SetName("gr_av");
  gr_av->SetTitle("AV");
  gr_av->SetMarkerColor(4);
  gr_av->SetLineColor(4);
  gr_av->SetMarkerStyle(22);

  gr_sum->SetName("gr_sum");
  gr_sum->SetTitle("Total");
  gr_sum->SetMarkerColor(1);
  gr_sum->SetLineColor(1);
  gr_sum->SetMarkerStyle(34);


  mg->Add(gr_sum);
  mg->Add(gr_ls);
  mg->Add(gr_av);

  TCanvas *c1 = new TCanvas("c1","c1");
  c1->cd();
   c1->SetLogy();
  gStyle->SetOptStat(0);
  mg->Draw("ALP");
  mg->GetXaxis()->SetTitle("Energy Threshold [MeV]");
  mg->GetYaxis()->SetTitle("Rate [Hz]");

  c1->BuildLegend();

  mg->GetHistogram()->SetTitle("Rate vs Energy Threshold without vertex selection");

  c1->Print("R_vs_E_Total_NOFV.pdf");

}
