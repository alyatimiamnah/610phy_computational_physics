/*a) Draw the variable acolin for background events.
  b) Draw the variable acolin for signal events.
  c) Apply following style:
  background :black
  signal: red
  Add axis labels:
  X-axis: “Acollinearity”
  Y-axis: “Events”
  legend
  axis labels

  Save as:
  PNG
  ROOT file*/
#include "style.h"

void Q7() {

  SetGlobalStyle();

   TFile *file = TFile::Open("mlpHiggs.root");

  TH1 *bkg = (TH1*)file->Get("acolin_bkg");

  TH1 *sig = (TH1*)file->Get("acolin_sig");

  TCanvas *c = new TCanvas("c","",800,600);

  SetCanvasStyle(c);
  bkg->GetXaxis()->SetTitle("Acollinearity");

  bkg->GetYaxis()->SetTitle("Events");

  bkg->SetLineColor(kBlack);

  sig->SetLineColor(kRed);

  bkg->Draw("HIST");
  sig->Draw("HIST SAME");
  
  TLegend *leg = CreateLegend();
  leg->AddEntry(bkg,"Background","l");

  leg->AddEntry(sig,"Signal","l");

  leg->Draw();
  c->SaveAs("acolin.png");

}
