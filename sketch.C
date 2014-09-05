void sketch()
{

  gStyle->SetPadRightMargin(0.22);
  gStyle->SetPadTopMargin(0.1);
  TH1F* h = new TH1F("h","h",10,0,1);
  h->GetYaxis()->SetRangeUser(0,1);
  h->GetYaxis()->SetTitle("Leading Photon");
  h->GetXaxis()->SetTitle("Subleading Photon");
  h->GetXaxis()->SetNdivisions(1);
  h->GetYaxis()->SetNdivisions(1);
  h->GetXaxis()->SetLabelSize(0.0001);
  h->GetYaxis()->SetLabelSize(0.00001);

  TBox * bkg = new TBox(0,0,1,1);
  bkg->SetFillColor(kGreen+2);
  TLine * lx = new TLine(0.5,0,0.5,1);
  TLine * ly = new TLine(0,0.5,1,0.5);

  TLine* lnomin = new TLine();
  lnomin->SetLineColor(kRed);
  lnomin->SetLineWidth(2);
  TLine* lprime = new TLine();
  lprime->SetLineColor(kRed);
  lprime->SetLineStyle(kDashed);
  lprime->SetLineWidth(4);

  // TRandom Rd;
  // const int N= 100;
  // double x[N];
  // double y[N];

  // double Radius = 0.29;
  // double x_center = 0.68;
  // double y_center = 0.65;

  // for(int i= 0; i<(N/2); i++){
  //   // double x_truth = 0.45+ (double)i*(0.95-0.45)/((double)N/2) ;
  //   // x[i] = Rd.Gaus(x_truth,0.001*x_truth);
  //   x[i] = x_center-Radius + (double)i*(2*Radius)/((double)N/2) ;
  //   double x_c = fabs(x[i]-x_center);
  //   double y_c = sqrt( Radius*Radius- x_c*x_c);
  //   y[i] = Rd.Gaus(y_c,0.05*Radius)+y_center;
  // }
  // for(int i= N/2; i>1; i--){
  //   // double x_truth = 0.45+ (double)i*(0.95-0.45)/((double)N/2) ;
  //   // x[N-i] = Rd.Gaus(x_truth,0.001*x_truth);
  //   x[N-i] = x_center-Radius + (double)i*(2*Radius)/((double)N/2) ;
  //   double x_c = fabs(x[N-i]-x_center);
  //   double y_c = sqrt( Radius*Radius- x_c*x_c);
  //   y[N-i] = y_center-Rd.Gaus(y_c,0.05*Radius);
  // }
  // x[N-1]=x[0];
  // y[N-1]=y[0];

  // TGraph* gr = new TGraph(N,x,y);

  TGraph* gr = GetTruePhotonRegion(0.69,0.65,0.29,0.29);
  gr->SetFillColor(kBlue);

  TLatex * lat = new TLatex();



  TLegend* leg = new TLegend(0.8,0.4,1.0,0.7);
  leg->SetFillColor(0);
  leg->AddEntry(gr,"True photons","f");
  leg->AddEntry(bkg,"Fake photons","f");
  leg->AddEntry(lnomin,"Id criteria","l");
  // leg->AddEntry(lprime,"Id criteria (syst)","l");

  TText * text = new TText();
  text->SetTextColor(kRed);
  text->SetNDC();
  TCanvas * c = new TCanvas("c1","c1",800,400);
  c->SetTicks(0,0);
  h->Draw("");
  bkg->Draw("same");
  gr->Draw("sameF");
  lnomin->DrawLine(0.5,0,0.5,1);
  lnomin->DrawLine(0,0.5,1,0.5);

  // lprime->DrawLine(0,0.65,0.35,0.65);
  // lprime->DrawLine(0,0.35,0.35,0.35);
  // lprime->DrawLine(0.65,0.35,1,0.35);
  // lprime->DrawLine(0.35,0.65,0.35,1);
  // lprime->DrawLine(0.35,0.,0.35,0.35);
  // lprime->DrawLine(0.65,0.,0.65,0.35);

  lat->SetTextColor(kWhite);
  lat->DrawLatex(0.05,0.75,"CR1: #gammaj enriched");
  lat->DrawLatex(0.05,0.25,"CR2: jj enriched");
  lat->DrawLatex(0.60,0.25,"CR3: j#gamma enriched");
  lat->DrawLatex(0.60,0.75,"SR: #gamma#gamma enriched");
  leg->Draw("same");
  text->DrawTextNDC(0.20,0.922,"Fail Tight");
  text->DrawTextNDC(0.52,0.922,"Pass Tight");
  text->SetTextAngle(90);
  text->DrawTextNDC(0.15,0.20,"Fail Tight");
  text->DrawTextNDC(0.15,0.58,"Pass Tight");
  c->RedrawAxis();

}


TGraph* GetTruePhotonRegion(double x_center,double y_center, double a_param, double b_param)
{

  //--> Draw the photon region as an ellipse.

  // double Radius = 0.29;
  // double x_center = 0.68;
  // double y_center = 0.65;

  const int N = 50;
  double x[N];
  double y[N];

  TRandom Rdm;
  for(int i= 0; i<N; i++){
    double theta = TMath::TwoPi()/N*i;
    double Radius = a_param*b_param/sqrt( pow(b_param*cos(theta),2)+pow(a_param*sin(theta),2) );
    
    double Radius_rdm = Rdm.Gaus(Radius,0.05*Radius);
    x[i] = x_center + Radius_rdm*cos(theta);
    y[i] = y_center + Radius_rdm*sin(theta);
  }
  x[N-1]=x[0];
  y[N-1]=y[0];

  TGraph* gr = new TGraph(N,x,y);
  return gr;
}
