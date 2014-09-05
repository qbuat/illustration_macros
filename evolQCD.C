#include "TMath.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TAxis.h"
#include "TLine.h"
#include "TLatex.h"

double evolbeta(double x, double alpha, double beta, double mu2);
double qed(double* X, double* par);
double qcd(double* X, double* par);
double ew1(double* X, double* par);
double ew2(double* X, double* par);

double invqed(double* X, double* par) {return 1./qed(X,par);}
double invqcd(double* X, double* par) {return 1./qcd(X,par);}
double invew1(double* X, double* par) {return 1./ew1(X,par);}
double invew2(double* X, double* par) {return 1./ew2(X,par);}

void DummyPlot(TF1* f1, TF1* f2, TF1* f3);

void evolQCD(){

TF1* QCD = new TF1("qcd",&invqcd,1e2,1e20,0);
QCD->SetLineWidth(4);QCD->SetLineStyle(1);QCD->SetLineColor(kRed+1);
TF1* EW1 = new TF1("ew1",&invew1,1e2,1e20,0);
EW1->SetLineWidth(4);EW1->SetLineStyle(1);EW1->SetLineColor(kAzure-5);
TF1* EW2 = new TF1("ew2",&invew2,1e2,1e20,0);
EW2->SetLineWidth(4);EW2->SetLineStyle(1);EW2->SetLineColor(kMagenta+2);
QCD->SetTitle("");
TCanvas* ccc= new TCanvas;
ccc->SetLogx(1);

QCD->Draw();
QCD->GetYaxis()->SetRangeUser(0,65);

QCD->GetXaxis()->SetTitle("Echelle d'energie (GeV)");
QCD->GetXaxis()->SetTitleOffset(1.3);
QCD->GetXaxis()->SetTitleSize(0.05);

QCD->GetYaxis()->SetTitle("Inverse du couplage #alpha^{-1}");
QCD->GetYaxis()->SetTitleSize(0.05);

EW1->Draw("same");
EW2->Draw("same");
TLatex ltx; 
ltx.SetTextSize(0.035);
ltx.SetTextAngle(26.0);ltx.SetTextColor(kRed+1);
ltx.DrawLatex(5e2, QCD->Eval(5e2)-3,"Interaction Forte");

ltx.SetTextAngle(13.2);ltx.SetTextColor(kMagenta+2);
ltx.DrawLatex(5e2, EW2->Eval(5e2)-3,"Interaction électrofaible, courants chargés");

ltx.SetTextAngle(-16.9);ltx.SetTextColor(kAzure-5);
ltx.DrawLatex(5e2, EW1->Eval(5e2)+1,"Interaction électrofaible, courants neutres");

TLine L;
L.SetLineStyle(2);
L.SetLineWidth(8);
L.DrawLine(1.2e19,0,1.2e19,65);
ltx.SetTextAngle(90);ltx.SetTextColor(kBlack);
ltx.DrawLatex(5e19,5,"échelle de Planck");



}

double qcd(double* X, double* par)
{
double x  = X[0];
double al = 0.118;
double mu = 91.2;

if(x>172) // mtop
  {
  double alphatop = evolbeta(172,al,-11/3*3+ 2/3.*2*5*1/2., mu*mu);  //
  return evolbeta(x,alphatop, -11+ 2/3.*2*6*1/2., 172*172); // 
  }
return evolbeta(x,al,-11/3*3+ 2/3.*2*5*1/2., mu*mu);
}


double qed(double* X, double* par)
{
double x  = X[0];
double al = 1./127.9;
double mu = 91.2;

if(x>172) // mtop
  {
  double alphatop = evolbeta(172,al, 2./3.*2*(3+11./9), mu*mu);
  return evolbeta(x,alphatop,2./3.*2*(3*15./9), 172*172);
  }
return evolbeta(x,al,  2./3.*2*(3+11./9)   , mu*mu);
}



double ew1(double* X, double* par)
{
double x  = X[0];
double al = 5./3.*1./127.9*1/(1-0.231);  //1.37
double mu = 91.2;

if(x>172) // mtop
  {
  double alphatop = evolbeta(172,al, (2./3.*(18+5/9.+16./9.*2+4/9.*3))*0.25 , mu*mu);
  return evolbeta(x,alphatop, (2./3.*(18+6/9.+16./9.*3+4/9.*3))*0.25 , 172*172);
  }
return evolbeta(x,al, 2./3.*(18+5/9.+16./9.*2+4/9.*3) +1/6.  , mu*mu);
}

double ew2(double* X, double* par)
{
double x  = X[0];
double al = 1./(127.9*0.231);
double mu = 91.2;

if(x>172) // mtop
  {
  double alphatop = evolbeta(172,al, -22./3 +2./3.*1./2.*11+1/6.*1/2. , mu*mu);
  return evolbeta(x,alphatop, -22./3 +2./3.*1./2.*12+1/6.*1/2., 172*172);
  }
return evolbeta(x,al,  -22./3 +2./3.*1./2.*11+1/6.*1/2.  , mu*mu);
}


double evolbeta(double x, double alpha, double beta, double mu2)
{
return alpha/(1-alpha*beta/TMath::Pi()*0.25*log(x*x/mu2));
}

/*
void DummyPlot(TF1* f1, TF1* f2, TF1* f3)
{
double x0 = 89;
double y0 = 350;
double dx = 15/(309-x0);
double dy = 60/(y0-50);

double xc1 = 123;
double yc1 = 57;
double xc2 = 329;
double yc2 = 164;
double xe1 = 123;
double ye1 = 306;
double xe2 = 331;
double ye2 = 121;
double xw1 = 125;
double yw1 = 198;
double xw2 = 325;
double yw2 = 121;

double a1  = -(yc2-yc1)/(xc2-xc1)*dy/dx;  
double a2  = -(ye2-ye1)/(xe2-xe1)*dy/dx;  
double a3  = -(yw2-yw1)/(xw2-xw1)*dy/dx;  
double b1  = (y0-yc1)*dy-a1*(xc1-x0)*dx;
double b2  = (y0-ye1)*dy-a2*(xe1-x0)*dx;
double b3  = (y0-yw1)*dy-a3*(xw1-x0)*dx;

std::cout << a1 << "  " << a2 << "  " << a3 << std::endl;
f1->SetParameter(0,a1); f1->SetParameter(1,b1);
f2->SetParameter(0,a2); f2->SetParameter(1,b2);
f3->SetParameter(0,a3); f3->SetParameter(1,b3);
f1->SetLineColor(2);
f2->SetLineColor(3);
f3->SetLineColor(4);
}
*/
