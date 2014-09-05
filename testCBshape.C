void testCBshape()

{
  // gSystem->Load("libRooFit.so");


  RooRealVar x("x","x",-4,10);

  RooRealVar m("m","m",-2.4537e-01);
  RooRealVar alpha("alpha","#alpha",-5.9691e-01);
  RooRealVar sig("sig","#sigma",1.1274e+00 );
  RooRealVar n("n","n",0.01);

  // RooRealVar m("m","m",3);
  // RooRealVar alpha("alpha","#alpha",-1);
  // RooRealVar sig("sig","#sigma",1);
  // RooRealVar n("n","n",0.01);

  RooCBShape pdf("pdf","pdf",x,m,sig,alpha,n);


  RooPlot* p = x.frame(-4,10);

  pdf.plotOn(p,RooFit::LineColor(2));
  n.setVal(0.01);
  pdf.plotOn(p,RooFit::LineColor(3));
  n.setVal(0.1);
  pdf.plotOn(p,RooFit::LineColor(4));
  n.setVal(1);
  pdf.plotOn(p,RooFit::LineColor(5));
  n.setVal(10);
  pdf.plotOn(p,RooFit::LineColor(6));
  n.setVal(100);
  pdf.plotOn(p,RooFit::LineColor(7));

  p->Draw();

}
