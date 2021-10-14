void macro_test () {
        // open the file
        TFile *file1 = new TFile("k40ls20knog4user.root","read");
        TFile *file2 = new TFile("k40ls20kg4user.root","read");
        // get the evt tree from the file
        TTree *tree_1 = (TTree*) file1->Get("evt");
        TTree *tree_2 = (TTree*) file2->Get("evt");

        // draw edep in hnew
        tree_1->Draw("edep>>hnew1","","");
        tree_2->Draw("edep>>hnew2","","");

        // get the histogram hnew from the local directory
        TH1F *h_edep1 = (TH1F*)gDirectory->Get("hnew1");
        TH1F *h_edep2 = (TH1F*)gDirectory->Get("hnew2");


        h_edep2->SetLineColor(kRed);
        h_edep1->SetTitle("G4 - GUN; Deposited Energy [MeV]; Counts [a.u]");
        h_edep2->SetTitle("J20- GenDecay ; Deposited Energy [MeV]; Counts [a.u]");
//      h_new1->SetBins(50, 0, 2 );
//      h_new2->SetBins(50, 0 , 2);

        gStyle->SetOptStat(0);
//      auto legend = new TLegend(0.1,0.4,0.3,0.4);
//      legend->AddEntry(h_edep1,"G4- GUN","f");
//      legend->AddEntry(h_edep2,"J20-GenDecay","l");
//
        // do things on your histogram
        // h_edep->GetXaxis()->SetTitle("Deposited energy [MeV]");
        // h_edep->GetYaxis()->SetTitle("Counts [a.u.]");

        // plot and save in .pdf (also other formats possible)
        TCanvas *c1 = new TCanvas("c1","c1");
        c1->cd();
        h_edep1->Draw();
        h_edep2->Draw("same");
//        c1->Print("test.pdf");
        c1->BuildLegend();
      // save it on a root file
       //TFile *newfile = new TFile ("new_file.root","recreate","new file");
        //h_edep->Write();
        TFile *newfile = new TFile ("k40gen.root","recreate","new file");
        c1->Write();
}
