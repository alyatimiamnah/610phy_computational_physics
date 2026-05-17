#include "style.h"

void fill2DHistogramsigbk() {

  // Open the ROOT file

  TFile *file = TFile::Open("mlpHiggs.root");


  // =========================
  // GET TREES
  // =========================

      TTree *sig =(TTree*)file->Get("sig_filtered");


      // Q1 [1 Point]
      //
      // Complete the command to retrieve
      // the background tree

      TTree *bg  = (TTree*)file->Get("bg_filtered");
      //            __________________________;




          // Q2 [2 Points]
          //
          // Define variables and apply
          // SetBranchAddress()
          // for acolin in signal and background
      float sig_acolin = 0;

      float bg_acolin  = 0;

      sig->SetBranchAddress("acolin", &sig_acolin);
      bg->SetBranchAddress("acolin", &bg_acolin);



          // Q3 [1 Point]
          //
          // Complete the TH2F constructor:
          //
          // X-axis = Background
          // Y-axis = Signal

      TH2F *h2 = new TH2F("h2",
                          "Signal vs Background",
                         100,200,100,
                          100,200,100);



          // Fill histogram

          for (int j=0;
               j<bg->GetEntries();
               ++j) {

            bg->GetEntry(j);

            for (int i=0;
                 i<sig->GetEntries();
                 ++i) {

              sig->GetEntry(i);

              h2->Fill( bg_acolin,sig_acolin);

            }
          }



              TCanvas *c =
                new TCanvas(
                            "c",
                            "Background vs Signal",
                            800,
                            600);


              // Q4 [1 Point]
              //
              // Draw the histogram
              // using color representation

              h2->Draw("COLZ");



              // Q5 [1 Point]
              //
              // Save the histogram
              // as PNG format

              c->SaveAs("h2.png");


              file->Close();

}
