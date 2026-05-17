#include "style.h"

void sigeffpurity() {

  SetGlobalStyle();

  // =========================
  // OPEN FILE
  // =========================

  TFile *file = TFile::Open("mlpHiggs.root");


  // =========================
  // GET TREES
  // =========================
// =========================

TTree *sig=(TTree*)file->Get("sig_filtered");

// Q1(a) [1 Mark]
//
// Define background tree and
// complete the command

TTree *bg =(TTree*)file->Get("bg_filtered");



// =========================
// TOTAL EVENTS
// =========================

int Ns=sig->GetEntries();

int Nb=bg->GetEntries();



// Q1(b) [1 Mark]
//
// Define variables and apply
// SetBranchAddress()

float sig_acolin,bg_acolin;


 sig->SetBranchAddress("acolin"&sig_acolin);
 bg->SetBranchAddress("acolin"&bg_acolin);




// =========================
// GRAPHS
// =========================

TGraphErrors *g_eff= new TGraphErrors();


// Q2 [2 Marks]
//
// Create purity and product
// graphs using TGraphErrors

TGraphErrors *g_pur=new TGraphErrors();
//____________________;

TGraphErrors *g_prod=new TGraphErrors();


for(int t=80;t<=200;t++){

  int count_sig=0;
  int count_bg=0;


  // Signal loop already completed

  for(int i=0;i<Ns;i++){

    sig->GetEntry(i);

    if(sig_acolin>=t)

      count_sig++;
  }



  // Q3 [1 Mark]
  //
  // Complete only the
  // background selection
  //
  // Condition:
  //
  // bg_acolin >= threshold

  for(int i=0;i<Nb;i++){

    bg->GetEntry(i);

    if(bg_acolin>=t)

      count_bg++;

  }



  // Q4(a) [1 Mark]
  //
  // Calculate:
  //
  // Efficiency
  // Binomial error

  double eff=(double)count_sig/Ns;

  double efficiency_err=sqrt(efficiency*(1-efficiency)/Ns;

  double purity =(double)count_sig/(count_sig+count_bg);

  double pur_err =sqrt(purity*(1-purity)/count_sig+count_bg);



                  int p=g_eff->GetN();

                  g_eff->SetPoint(p,t,eff);
                  g_eff->SetPointError(p,0,err);



                             g_pur->SetPoint(p,t,pur);

                             g_pur->SetPoint(p,0,err);
                             g_prod->SetPoint(p,t,0);
                             g_prod->SetPointError(p,0,0);

                  if((count_sig+count_bg)>0)

                            purity=
                              (double)count_sig/
                              (count_sig+count_bg);


                  int p2=g_pur->GetN();

                  g_pur->SetPoint(p2,t,purity);



                  // Q4(b) [1 Mark]
                  //
                  // Calculate:
                  //
                  // Product =
                  // Efficiency * Purity

                  double product= efficiency * purity;



                          int p3=g_prod->GetN();

                          g_prod->SetPoint(p3,t,product);

 }



g_eff->SetLineColor(kBlue);

g_pur->SetLineColor(kRed);

g_prod->SetLineColor(kGreen+2);



    TCanvas *c=
      new TCanvas("c","",800,600);

SetCanvasStyle(c);



// Q5(a) [1 Mark]
//
// Draw purity and product
// on the same canvas

g_eff->Draw("ALP");
 g_pure->Draw("LP SAME");
 g_prod->Draw("LP SAME");


// Q5(b) [1 Mark]
//
// Add legend entries and explain:
//
// Efficiency
// Purity
// Efficiency * Purity

    TLegend *leg=
      new TLegend(0.65,0.70,0.88,0.88);
    leg->g_eff(efficiency,"efficiency","lp");
    leg->g_pur(purity,"purity","lp");
    leg->g_prod(product,"prouduct","lp");
    leg->Draw();



// Q5(c) [1 Mark]
//
// Save result as png

    c->SaveAs("sigeffpurity.png");

}
