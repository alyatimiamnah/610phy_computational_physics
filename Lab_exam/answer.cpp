 #include "style.h"

void sigeffpurity1() {

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


 sig->SetBranchAddress("acolin",&sig_acolin);
 bg->SetBranchAddress("acolin",&bg_acolin);




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

  double eff_err=sqrt(eff*(1-eff))/Ns;

  double pur =(double)count_sig/(count_sig+count_bg);

  double pur_err =sqrt(pur*(1-pur)/count_sig+count_bg);



                  int p=g_eff->GetN();

                  g_eff->SetPoint(p,t,eff);

                  g_eff->SetPointError(p,0,eff_err);
                  //              if((count_sig+count_bg)>0)

                  int p2=g_pur->GetN();


                  g_pur->SetPoint(p2,t,pur);


                             g_pur->SetPointError(p2,0,pur_err);
                             if((count_sig+count_bg)>0)
                             double prod= eff * pur;
                             //int p3=g_prod->GetN();
                             //      double prod= eff * pur;
                             //                     g_prod->SetPoint(p3,t,prod);
                             //

                             //g_prod->SetPointError(p3,0,0);


                             //double prod= eff * pur;
                             //   if((count_sig+count_bg)>0)



                    // int p2=g_pur->GetN();

                  // g_pur->SetPoint(p2,t,pur);



                  // Q4(b) [1 Mark]
                  //
                  // Calculate:
                  //
                  // Product =
                  // Efficiency * Purity

                  //double prod= eff * pur;



                  int p3=g_prod->GetN();
                  g_prod->SetPoint(p3,t,prod);


                  g_prod->SetPointError(p3,0,0);


                          //      g_prod->SetPoint(p3,t,product);

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
 g_pur->Draw("LP SAME");
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
    leg->AddEntry(g_eff,"efficiency","lp");
    leg->AddEntry(g_pur,"purity","lp");
    leg->AddEntry(g_prod,"prouduct","lp");
    leg->Draw();



// Q5(c) [1 Mark]
//
// Save result as png

    c->SaveAs("sigeffpurity.png");

}
