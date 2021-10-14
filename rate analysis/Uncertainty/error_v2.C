#include <fstream>
#include "TEfficiency.h"

void error(){
    TH1F *h_pass_ls_u238 = new TH1F("h_pass_ls_u238","",20,0,20);
    TH1F *h_total_ls_u238 = new TH1F("h_total_ls_u238","",20,0,20);

    TH1F *h_pass_ls_th232 = new TH1F("h_pass_ls_th232","",20,0,20);
    TH1F *h_total_ls_th232 = new TH1F("h_total_ls_th232","",20,0,20);

    TH1F *h_pass_ls_pb210 = new TH1F("h_pass_ls_pb210","",20,0,20);
    TH1F *h_total_ls_pb210 = new TH1F("h_total_ls_pb210","",20,0,20);

    TH1F *h_pass_ls_k40 = new TH1F("h_pass_ls_k40","",20,0,20);
    TH1F *h_total_ls_k40 = new TH1F("h_total_ls_k40","",20,0,20);


    fstream file_pass_u238, file_total_u238, file_pass_th232, file_total_th232, file_pass_k40, file_total_k40 , file_pass_pb210, file_total_pb210 ;

    file_pass_u238.open("u238_ls_nofv_pass.txt", ios::in);
    file_total_u238.open("u238_ls_nofv_total.txt", ios::in);

    file_pass_th232.open("th232_ls_nofv_pass.txt", ios::in);
    file_total_th232.open("th232_ls_nofv_total.txt", ios::in);

    file_pass_pb210.open("pb210_ls_nofv_pass.txt", ios::in);
    file_total_pb210.open("pb210_ls_nofv_total.txt", ios::in);

    file_pass_k40.open("k40_ls_nofv_pass.txt", ios::in);
    file_total_k40.open("k40_ls_nofv_total.txt", ios::in);



    int counter=1;

    while (1) {
      float epass_u238, etotal_u238, npass_u238, ntotal_u238, npass_th232, npass_k40, npass_pb210, ntotal_th232, ntotal_pb210, ntotal_k40 ;

      file_pass_u238 >> epass_u238 >> npass_u238;
      h_pass_ls_u238->SetBinContent(counter,npass_u238);
      file_total_u238 >> etotal_u238 >> ntotal_u238;
      h_total_ls_u238->SetBinContent(counter,ntotal_u238);

      file_pass_th232 >> npass_th232;
      h_pass_ls_th232->SetBinContent(counter,npass_th232);
      file_total_th232 >> ntotal_th232;
      h_total_ls_th232->SetBinContent(counter,ntotal_th232);

      file_pass_pb210 >> npass_pb210;
      h_pass_ls_pb210->SetBinContent(counter,npass_pb210);
      file_total_pb210 >> ntotal_pb210;
      h_total_ls_pb210->SetBinContent(counter,ntotal_pb210);

      file_pass_k40 >> npass_k40;
      h_pass_ls_k40->SetBinContent(counter,npass_k40);
      file_total_k40 >> ntotal_k40;
      h_total_ls_k40->SetBinContent(counter,ntotal_k40);

      counter+=1;

      if(file_pass_u238.eof()) break;
      if(file_total_u238.eof()) break;

    }

    file_pass_u238.close();
    file_total_u238.close();

    file_pass_th232.close();
    file_total_th232.close();

    file_pass_pb210.close();
    file_total_pb210.close();

    file_pass_k40.close();
    file_total_k40.close();




  h_pass_ls_u238->SetMarkerStyle(21);
  h_total_ls_u238->SetMarkerStyle(22);

  h_pass_ls_th232->SetMarkerStyle(23);
  h_total_ls_th232->SetMarkerStyle(24);


  TCanvas *c1 = new TCanvas("c1","c1");
  c1->cd();
//  c1->SetLogy();
  h_total_ls_u238->Draw();
  h_pass_ls_u238->Draw("SAME");
  h_total_ls_th232->Draw("SAME");
  h_pass_ls_u238->Draw("SAME");

  TEfficiency *pEff_u = new TEfficiency(*h_pass_ls_u238,*h_total_ls_u238);
  TEfficiency *pEff_t = new TEfficiency(*h_pass_ls_th232,*h_total_ls_th232);
  TEfficiency *pEff_k = new TEfficiency(*h_pass_ls_k40,*h_total_ls_k40);
  TEfficiency *pEff_pb = new TEfficiency(*h_pass_ls_pb210,*h_total_ls_pb210);

  pEff_u->SetStatisticOption(TEfficiency::kBBayesian);
  pEff_t->SetStatisticOption(TEfficiency::kBBayesian);
  pEff_k->SetStatisticOption(TEfficiency::kBBayesian);
  pEff_pb->SetStatisticOption(TEfficiency::kBBayesian);




     int j=0;
     while (1) {
       double eff_u, eff_t, eff_k, eff_pb;
       eff_u = pEff_u->GetEfficiency(j);
       eff_t = pEff_t->GetEfficiency(j);
       eff_k = pEff_k->GetEfficiency(j);
       eff_pb = pEff_pb->GetEfficiency(j);

       cout <<"U  " << j << " bin efficiency " << eff_u << endl;
       cout << "Th " << j << " bin efficiency " << eff_t << endl;
       cout << "K " << j << " bin efficiency " << eff_k << endl;
       cout << "Pb " << j << " bin efficiency " << eff_pb << endl << endl;

       j+=1;
       if(j==21) break;
     }

     int i=0;
     while (1) {
       double erru_u, errl_u, erru_t, errl_t, erru_k, errl_k, erru_pb, errl_pb, erru_tot, errl_tot ;

       erru_u = 3.481*pEff_u->GetEfficiencyErrorUp(i);
       errl_u = 3.481*pEff_u->GetEfficiencyErrorLow(i);

       erru_t = 0.808*pEff_t->GetEfficiencyErrorUp(i);
       errl_t = 0.808*pEff_t->GetEfficiencyErrorLow(i);

       erru_k = 0.529*pEff_k->GetEfficiencyErrorUp(i);
       errl_k = 0.529*pEff_k->GetEfficiencyErrorLow(i);

       erru_pb = 16.945*pEff_pb->GetEfficiencyErrorUp(i);
       errl_pb = 16.945*pEff_pb->GetEfficiencyErrorLow(i);

       erru_tot = sqrt((erru_u*erru_u) + (erru_t*erru_t) + (erru_k*erru_k) + (erru_pb*erru_pb));
       errl_tot = sqrt(errl_u*errl_u + errl_t*errl_t + errl_k*errl_k + errl_pb*errl_pb);

       cout << "U " << i << " bin : up " << erru_u << " low " << errl_u << endl;
       cout << "T " << i << " bin : up " << erru_t << " low " << errl_t << endl;
       cout << "K " << i << " bin : up " << erru_k << " low " << errl_k << endl;
       cout << "Pb " << i << " bin : up " << erru_pb << " low " << errl_pb << endl;
       cout << "Total " << i << " bin : up " << erru_tot << " low " << errl_tot << endl << endl;

       i+=1;
       if(i==21) break;
     }

     TCanvas *c2 = new TCanvas("c2","c2");
     c2->cd();

      pEff_pb->Draw("AP");
      pEff_u->Draw("same");
      pEff_t->Draw("same");
      pEff_k->Draw("same");

}
