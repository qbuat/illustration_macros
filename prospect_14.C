void prospect_14()
{
  int n_ssm = 3 ;
  double x_ssm[] ={7,8,14};
  double y_ssm[] = {2.08,2.76,6.5} ;
  TGraph* gr_zssm = new TGraph(n_ssm,x_ssm,y_ssm);
  gr_zssm->GetXaxis()->SetTitle("#sqrt{s} [TeV]");
  gr_zssm->GetYaxis()->SetTitle("Limite sur la masse [TeV]");
  TF1* f1 = new TF1("f1","pol1",7,14);
  gr_zssm->Fit(f1,"RVSNO");
  int n_rs = 2;
  double x_rs[] ={7,8};
  double y_rs[] = {1.92,2.67} ;
  TGraph* gr_rs = new TGraph(n_rs,x_rs,y_rs);
  gr_rs->SetMarkerColor(kRed);
  gr_rs->SetMarkerStyle(22);
  TCanvas* C1 = new TCanvas();
  c1->cd();
  gr_zssm->Draw("AP");
  f1->Draw("same");
  gr_rs->Draw("sameP");

  TLegend * leg = new TLegend(0.1882184,0.6779661,0.625,0.9152542);
  leg->SetFillColor(0);
  leg->AddEntry(gr_zssm,"Z'#rightarrow e^{+}e^{-}","p");
  leg->AddEntry(gr_rs  ,"G#rightarrow #gamma#gamma","p");
  leg->Draw("same");

  TLatex * lat = new TLatex();
  lat->DrawLatex(7.2,1.9,"L = 5 fb^{-1}");
  lat->DrawLatex(8.25,2.6,"L = 20 fb^{-1}");
  lat->DrawLatex(12,6.4,"L = 300 fb^{-1}");
}
