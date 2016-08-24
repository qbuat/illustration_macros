double xpos(double e)
{
  double x_min = -9;
  double x_max = 9;
  double e_min = 1e-6;
  double e_max = 1e21;

  double slope = (x_max-x_min)/(TMath::Log(e_max)-TMath::Log(e_min));
  double offset = (x_min+x_max-slope*(TMath::Log(e_max)+TMath::Log(e_min)))/2.;
  cout << slope << "/" << offset << endl;
  return slope*TMath::Log(e)+offset;

}

void fund_scale()
{
  double alpha = 197; //alpha/E=d avec alpha = 197 MeV.fm

  TCanvas* c1 = new TCanvas("c1","c1",800,300);
  c1->cd();
  c1->Range(-10,-1,10,1);

  double e_min = 1e-6;
  double e_max = 1e21;

  double x_min = -9;
  double x_max =  9;
  double y_min = -0.5;
  double y_max =  0.5;


  TGaxis *axis_E = new TGaxis(x_min,y_min,x_max,y_min,e_min,e_max,50510,"G+-");
  // axis_E->SetTitle("Energie [GeV]");
  axis_E->SetTitle("Energy [GeV]");
  axis_E->SetTitleOffset(2);
  axis_E->SetNdivisions(10);
  axis_E->Draw("");

  TArrow* arr_E = new TArrow(x_min,y_min,x_max+0.7,y_min,0.03,">");
  arr_E->SetAngle(40);
  arr_E->SetLineWidth(2);
  arr_E->Draw("");

  double l_min = alpha/(e_min*1e3)*1e-13;
  double l_max = alpha/(e_max*1e3)*1e-13;

  TGaxis *axis_L = new TGaxis(x_max,y_max,x_min,y_max,l_max,l_min,50510,"G+-");
  // axis_L->SetTitle("Distance [cm]");
  axis_L->SetTitle("Lenght [cm]");
  axis_L->SetTitleOffset(2);
  axis_L->SetLabelOffset(-0.008);
  axis_L->SetNdivisions(10);
  axis_L->Draw("same");


  TArrow* arr_L = new TArrow(x_min-0.7,y_max,x_max,y_max,0.03,"<");
  arr_L->SetAngle(40);
  arr_L->SetLineWidth(2);
  arr_L->Draw("");


  double e_em  = 511*1e-6;// gev
  double e_qcd = 0.938;// gev
  double e_ew  = 80.385; //gev
  double e_pl = 1.22*1e19;//gev

  double x_em  = xpos(e_em);cout << x_em << endl;
  double x_qcd = xpos(e_qcd);cout << x_qcd << endl;
  double x_ew  = xpos(e_ew);cout << x_ew << endl;
  double x_pl  = xpos(e_pl); cout << x_pl << endl;

  TArrow* ar_em  = new TArrow(x_em ,y_min,x_em,y_max,0.03,"<>");
  TArrow* ar_qcd = new TArrow(x_qcd,y_min,x_qcd,y_max,0.03,"<>");
  TArrow* ar_ew  = new TArrow(x_ew ,y_min,x_ew,y_max,0.03,"<>");
  TArrow* ar_pl  = new TArrow(x_pl ,y_min,x_pl,y_max,0.03,"<>");
  TArrow* ar_hier = new TArrow(x_ew,0,x_pl,0,0.03,"<>");

  ar_em->Draw();
  ar_qcd->Draw();
  ar_ew->Draw();
  ar_pl->Draw();
  ar_hier->Draw();

  // TText* t_hier = new TText(0.4*(x_pl+x_ew),0.1,"17 ordres de grandeur");
  TText* t_hier = new TText(0.4*(x_pl+x_ew),0.1,"17 orders of magnitude");
  t_hier->Draw();

  TLatex*lat = new TLatex();
  lat->SetTextAngle(90);
  // lat->DrawLatex(x_em -0.05,-0.2,"#acute{e}lectron");
  // lat->DrawLatex(x_qcd-0.05,-0.2,"proton");
  // lat->DrawLatex(x_ew -0.05,-0.2,"boson W");
  // lat->DrawLatex(x_pl +0.33,-0.35,"#acute{e}chelle de planck");
  lat->DrawLatex(x_em -0.05,-0.2,"electron");
  lat->DrawLatex(x_qcd-0.05,-0.2,"proton");
  lat->DrawLatex(x_ew -0.05,-0.2,"W boson");
  lat->DrawLatex(x_pl +0.33,-0.35,"Planck scale");
  // TPaveText *pt_hier = new TPaveText(x_ew+0.1*x_ew,-0.2,x_pl-0.1*x_pl,0.2);
  // pt_hier->AddText("16 ordres de grandeurs");
  // pt_hier->Draw();


}


