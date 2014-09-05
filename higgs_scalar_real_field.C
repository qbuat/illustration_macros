void higgs_scalar_real_field()
{

  TF1 *f1 = new TF1("f1","(-0.5*[0]*x*x+0.25*[1]*x*x*x*x)*[2]",-2000.,2000.);
  f1->SetParameter(0,7921);
  f1->SetParameter(1,0.13);
  // f1->SetParameter(0,1);
  // f1->SetParameter(1,1);
  f1->SetParameter(2,1);
  f1->GetXaxis()->SetTitle("#phi");
  f1->GetYaxis()->SetTitle("V(#phi)");



  TCanvas* c1 = new TCanvas();
  c1->cd();
  f1->Draw();
  TLatex* lat = new TLatex();
  lat->DrawLatex(-0.5,1.6,"V(#phi) = #frac{#mu^{2}}{2}#phi^{2} + #frac{#lambda}{4}#phi^{4}, #mu^{2}<0");


}
