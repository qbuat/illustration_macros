void erfinv()

{

  TF1* f = new TF1("f1","sqrt(2)*TMath::ErfInverse(1-2*x)",1e-12,1);
  f->GetYaxis()->SetRangeUser(-1,8);
  f->GetXaxis()->SetRangeUser(1e-5,1.1);
  TCanvas* c1 = new TCanvas();
  c1->SetLogx();
  f->Draw();

  double z = 0 ;
  double x = 0.5;
  while( z<7.){
    x = x/10; 
    z = sqrt(2)*TMath::ErfInverse(1-2*x);
    std::cout << "x = " << x << "\t z= "<< z << std::endl;  
  }

  // const int N =10000;
  // double x[N];
  // double y[N];
  // x[0] = 1e-5 ;
  // double step = (1-x[0])/(double)N;
  // for(int i=0; i<N;i++) {
  //   x[i]=x[0]+i*step;
  //   y[i]=sqrt(2.)*TMath::ErfInverse(1.-2.*x[i]);
  // }

  // TGraph* gr = new TGraph(N,x,y);
  // gr->GetXaxis()->SetTitle("Valeur p");
  // gr->GetYaxis()->SetTitle("Deviation standard");
  // gr->Draw("AL");

  // TAxis * axis_x = gr->GetXaxis();
}
