 #include "style.h"

void Q8(){

  // Apply global style
  SetGlobalStyle();

  // =========================
  // OPEN FILE
  // =========================
  TFile *file = TFile::Open("mlpHiggs.root");

  // =========================
  // QUESTION (1):
  // Get the SIGNAL tree "sig_filtered"
  // =========================
  TTree *sig_tree = (TTree*)file->Get("sig_filtered");


  // =========================
  // VARIABLE
  // =========================
  float sig_minvis = 0;

  // =========================
  // QUESTION (2):
  // Set branch address for "minvis"
  // =========================
  sig_tree->SetBranchAddress("minvis", &sig_minvis);


  // =========================
  // HISTOGRAM
  // =========================
  // QUESTION (3):
  // Define histogram with:
  //   50 bins
  //   range from 30 to 120
  // =========================
  TH1F *h = new TH1F("h", "Min Visible Mass", 50, 30, 120);


  // =========================
  // QUESTION (4):
  // Fill histogram using loop over sig_tree
  // =========================
  for (int i = 0; i < sig_tree->GetEntries(); i++) {

    sig_tree->GetEntry(i);

    h->Fill(sig_minvis);
  }


  // =========================
  // CANVAS
  // =========================
  TCanvas *c = new TCanvas("c", "Gaussian Fit", 800, 600);
  SetCanvasStyle(c);

  // =========================
  // STYLE HISTOGRAM
  // =========================
  SetHistogramStyle(h);

  // =========================
  // QUESTION (5):
  // Set axis labels:
  //   X → "Min Visible Mass (GeV/c^{2})"
  //   Y → "Events"
  // =========================
  h->GetXaxis()->SetTitle("Min Visible Mass (GeV/c^{2})");

  h->GetYaxis()->SetTitle("Events");


  // =========================
  // DRAW HISTOGRAM
  // =========================
  h->Draw("HIST");


  // =========================
  // QUESTION (6):
  // Create Gaussian function with range:
  //   30 to 120
  // =========================
  TF1 *g = new TF1("g", "gaus", 30, 120);


  // =========================
  // QUESTION (7):
  // Fit histogram with Gaussian
  // =========================
  h->Fit(g, "R");

  g->SetLineColor(kRed);

  g->Draw("SAME");


  // =========================
  // QUESTION (8):
  // Extract:
  //   mean, sigma, mean_err, sigma_err
  // =========================
  double mean = g->GetParameter(1);

  double sigma = g->GetParameter(2);

  double mean_err = g->GetParError(1);

  double sigma_err = g->GetParError(2);


  // =========================
  // QUESTION (9):
  // Create legend and display results
  // =========================
  TLegend *leg = CreateLegend();

  leg->AddEntry(h, "Signal", "l");

  leg->AddEntry(g, "Gaussian Fit", "l");

  leg->AddEntry((TObject*)0,
                Form("#mu = %.3f #pm %.3f", mean, mean_err), "");

  leg->AddEntry((TObject*)0,
                Form("#sigma = %.3f #pm %.3f", sigma, sigma_err), "");

  leg->Draw();


  // =========================
  // QUESTION (10):
  // Save plot as:
  //   "minvis_gaussian_fit.png"
  // =========================
  c->SaveAs("minvis_gaussian_fit.png");

}
