#include <fstream>
#include "TEfficiency.h"

void error(){
    TH2F *h_passed_ls = new TH2F("h_passed_ls","",20,0,2,15000000,0,15000000);
    TH2F *h_total_ls = new TH2F("h_total_ls","",20,0,2,15000000,0,15000000);

    fstream file_pass, file_total;
    file_pass.open("u238_ls_nofv.txt", ios::in);
    file_total.open("u238_ls_nofv_total.txt", ios::in);

  //  int counter=0;

    while (1) {
      float epass_u238, etotal_u238, npass_u238, ntotal_u238;
      file_pass >> epass_u238 >> npass_u238;
      h_passed_ls->Fill(epass_u238,npass_u238);
      file_total >> etotal_u238 >> ntotal_u238;
      h_total_ls->Fill(etotal_u238,ntotal_u238);

      if(file_pass.eof()) break;
      if(file_total.eof()) break;

  //    counter+=1;
    }


  h_passed_ls->SetMarkerStyle(21);
  h_total_ls->SetMarkerStyle(22);

  TCanvas *c1 = new TCanvas("c1","c1");
  c1->cd();
//  c1->SetLogy();
  h_passed_ls->Draw();
  h_total_ls->Draw("SAME");

  TEfficiency *pEff = new TEfficiency(*h_passed_ls,*h_total_ls);
    pEff->SetStatisticOption(TEfficiency::kBUniform);

}
