void photon_conversion()

{

  TCanvas* c = new TCanvas("conversion", "conversion",  800, 800);
  c->Range(-1500, -1500, 1500, 1500);
  c->cd();

  TEllipse * cal;
  call = new TEllipse(0,0,1300);
  call->SetFillColor(kGreen+3);
  call->Draw();
  call = new TEllipse(0,0,1100);
  call->SetFillColor(kWhite);

  TEllipse * cluster;
  cluster = new TEllipse(0,0,1300,1300,
			 2.7*TMath::Pi()/4*180/TMath::Pi(),
			 3.1*TMath::Pi()/4*180/TMath::Pi());
  cluster->SetFillColor(kYellow);
  cluster->Draw();

  cluster = new TEllipse(0,0,1300,1300,
			 0.8*TMath::Pi()/4*180/TMath::Pi(),
			 1.2*TMath::Pi()/4*180/TMath::Pi());
  cluster->SetFillColor(kYellow);
  cluster->Draw();

  cluster = new TEllipse(0,0,1300,1300,
			 -0.95*TMath::Pi()/2*180/TMath::Pi(),
			 -1.05*TMath::Pi()/2*180/TMath::Pi());
  cluster->SetFillColor(kYellow);
  cluster->Draw();



  call->Draw();

  TEllipse * tracker_layers;
  tracker_layers = new TEllipse(0,0,1000);
  tracker_layers->SetFillColor(kGray);
  tracker_layers->SetLineColor(kGray);
  tracker_layers->Draw();
  tracker_layers = new TEllipse(0,0,550);
  tracker_layers->SetFillColor(kWhite);
  tracker_layers->SetLineColor(kWhite);
  tracker_layers->Draw();
  tracker_layers = new TEllipse(0,0,440);
  tracker_layers->Draw();
  tracker_layers = new TEllipse(0,0,370);
  tracker_layers->Draw();
  tracker_layers = new TEllipse(0,0,300);
  tracker_layers->Draw();
  tracker_layers = new TEllipse(0,0,120);
  tracker_layers->Draw();
  tracker_layers = new TEllipse(0,0,90);
  tracker_layers->Draw();
  tracker_layers = new TEllipse(0,0,50);
  tracker_layers->Draw();

  TMarker * hit;
  hit = new TMarker(0,0,20);
  hit->Draw();

  // hit = new TMarker(1200*TMath::Cos(3*TMath::Pi()/4.),
  // 		    1200*TMath::Sin(3*TMath::Pi()/4.),
  // 		    5);
  // hit->Draw();
  // hit = new TMarker(1200*TMath::Cos(TMath::Pi()/4.),
  // 		    1200*TMath::Sin(TMath::Pi()/4.),
  // 		    5);
  // hit->Draw();
  // hit = new TMarker(1200*TMath::Cos(-TMath::Pi()/2.),
  // 		    1200*TMath::Sin(-TMath::Pi()/2.),
  // 		    2);
  // hit->Draw();

  TPolyLine *el = el_line(2.2*TMath::Pi()/4,3*TMath::Pi()/4,0);
  el->SetLineWidth(4);
  el->Draw();


  TMarker* hit_pix1_el = el_hit(2.2*TMath::Pi()/4,3*TMath::Pi()/4,0,50);
  hit_pix1_el->SetMarkerSize(0.6); 
  hit_pix1_el->Draw(); 
  std::cout << "toto" << std::endl;
  TMarker* hit_pix2_el = el_hit(2.2*TMath::Pi()/4,3*TMath::Pi()/4,0,90);
  hit_pix2_el->SetMarkerSize(0.6); 
  hit_pix2_el->Draw(); 
  TMarker* hit_pix3_el = el_hit(2.2*TMath::Pi()/4,3*TMath::Pi()/4,0,120);
  hit_pix3_el->SetMarkerSize(0.6); 
  hit_pix3_el->Draw(); 

  TMarker* hit_sct1_el = el_hit(2.2*TMath::Pi()/4,3*TMath::Pi()/4,0,300);
  hit_sct1_el->Draw(); 
  TMarker* hit_sct2_el = el_hit(2.2*TMath::Pi()/4,3*TMath::Pi()/4,0,370);
  hit_sct2_el->Draw(); 
  TMarker* hit_sct3_el = el_hit(2.2*TMath::Pi()/4,3*TMath::Pi()/4,0,440);
  hit_sct3_el->Draw(); 

  TRandom * Rd_flat = new TRandom();
  TMarker* hit_trt1_el = el_hit(2.2*TMath::Pi()/4,3*TMath::Pi()/4,0,
				550+(1000-550)*Rd_flat->Rndm());
  hit_trt1_el->Draw(); 
  TMarker* hit_trt2_el = el_hit(2.2*TMath::Pi()/4,3*TMath::Pi()/4,0,
				550+(1000-550)*Rd_flat->Rndm());
  hit_trt2_el->Draw(); 
  TMarker* hit_trt3_el = el_hit(2.2*TMath::Pi()/4,3*TMath::Pi()/4,0,
				550+(1000-550)*Rd_flat->Rndm());
  hit_trt3_el->Draw(); 
  TMarker* hit_trt4_el = el_hit(2.2*TMath::Pi()/4,3*TMath::Pi()/4,0,
				550+(1000-550)*Rd_flat->Rndm());
  hit_trt4_el->Draw(); 



  TPolyLine *el_conv1 = el_line(TMath::Pi()/4,1.1*TMath::Pi()/4,250);
  el_conv1->SetLineWidth(4);
  el_conv1->Draw();
  TPolyLine *el_conv2 = el_line(TMath::Pi()/4,0.9*TMath::Pi()/4,250);
  el_conv2->SetLineWidth(4);
  el_conv2->Draw();

  TMarker* hit_sct1_el_conv1 = el_hit(TMath::Pi()/4,1.1*TMath::Pi()/4,250,300);
  hit_sct1_el_conv1->Draw(); 
  TMarker* hit_sct2_el_conv1 = el_hit(TMath::Pi()/4,1.1*TMath::Pi()/4,250,370);
  hit_sct2_el_conv1->Draw(); 
  TMarker* hit_sct3_el_conv1 = el_hit(TMath::Pi()/4,1.1*TMath::Pi()/4,250,440);
  hit_sct3_el_conv1->Draw(); 

  TMarker* hit_trt1_el_conv1 = el_hit(TMath::Pi()/4,1.1*TMath::Pi()/4,250,
				      550+(1000-550)*Rd_flat->Rndm());
  hit_trt1_el_conv1->Draw(); 
  TMarker* hit_trt2_el_conv1 = el_hit(TMath::Pi()/4,1.1*TMath::Pi()/4,250,
				      550+(1000-550)*Rd_flat->Rndm());
  hit_trt2_el_conv1->Draw(); 
  TMarker* hit_trt3_el_conv1 = el_hit(TMath::Pi()/4,1.1*TMath::Pi()/4,250,
				      550+(1000-550)*Rd_flat->Rndm());
  hit_trt3_el_conv1->Draw(); 
  TMarker* hit_trt4_el_conv1 = el_hit(TMath::Pi()/4,1.1*TMath::Pi()/4,250,
				      550+(1000-550)*Rd_flat->Rndm());
  hit_trt4_el_conv1->Draw(); 


  TMarker* hit_sct3_el_conv2 = el_hit(TMath::Pi()/4,0.9*TMath::Pi()/4,250,440);
  hit_sct3_el_conv2->Draw(); 

  TMarker* hit_trt1_el_conv2 = el_hit(TMath::Pi()/4,0.9*TMath::Pi()/4,250,
				      550+(1000-550)*Rd_flat->Rndm());
  hit_trt1_el_conv2->Draw(); 
  TMarker* hit_trt2_el_conv2 = el_hit(TMath::Pi()/4,0.9*TMath::Pi()/4,250,
				      550+(1000-550)*Rd_flat->Rndm());
  hit_trt2_el_conv2->Draw(); 
  TMarker* hit_trt3_el_conv2 = el_hit(TMath::Pi()/4,0.9*TMath::Pi()/4,250,
				      550+(1000-550)*Rd_flat->Rndm());
  hit_trt3_el_conv2->Draw(); 
  TMarker* hit_trt4_el_conv2 = el_hit(TMath::Pi()/4,0.9*TMath::Pi()/4,250,
				      550+(1000-550)*Rd_flat->Rndm());
  hit_trt4_el_conv2->Draw(); 


  TCurlyLine* photon;
  photon = new TCurlyLine(0,0,0,-1200);
  photon->SetWavy();
  photon->SetWaveLength(0.03);
  photon->SetLineWidth(3);
  photon->SetLineStyle(kDashed);
  photon->Draw();

  photon = new TCurlyLine(0,0,
			  250*TMath::Cos(TMath::Pi()/4),
			  250*TMath::Sin(TMath::Pi()/4) );
  photon->SetWavy();
  photon->SetWaveLength(0.02);
  photon->SetLineWidth(3);
  photon->SetLineStyle(kDashed);
  photon->Draw();


  TArrow * axis;
  axis = new TArrow(0,0,1450,0);
  axis->SetLineWidth(3);
  axis->Draw();
  axis = new TArrow(0,0,0,1450);
  axis->SetLineWidth(3);
  axis->Draw();
  TLatex * label = new TLatex();
  label->DrawLatex(1350,-180,"X");
  label->DrawLatex(-180,1350,"Y");

  label->SetTextAngle(40);
  label->DrawLatex(-1020,845,"electron");
  label->SetTextAngle(-45);
  label->DrawLatex(644,1268,"converted photon");
  label->SetTextAngle(0);
  label->DrawLatex(-524,-1459,"unconverted photon");

}


double r(double theta,double theta_0,double a,double r0)
{
  return a*(theta-theta_0)+r0;
}
TPolyLine * el_line(double theta_0,double theta_f,double r0)
{


  TPolyLine* el;

  double a = (1200-r0)/ (theta_f-theta_0);
  const int Nhits = 50;
  double x_el[Nhits];
  double y_el[Nhits];
  for(int i=0;i<Nhits;i++){
    double theta_i = theta_0 +i*(theta_f-theta_0)/(double)Nhits;
    double radius = r(theta_i,theta_0,a,r0);  
    x_el[i] = radius*TMath::Cos(theta_i); 
    y_el[i] = radius*TMath::Sin(theta_i);
 }
  el = new TPolyLine(Nhits,x_el,y_el);
  return el;
}


TMarker * el_hit(double theta_0,double theta_f,double r0,double tracker_r)
{



  double a = (1200-r0)/ (theta_f-theta_0);

  double theta_intersec = theta_0;
  double radius = r(theta_intersec,theta_0,a,r0);  
  double Delta_r = fabs(radius-tracker_r);
  while( Delta_r>1){
    theta_intersec += (theta_f-theta_0)/1000.;
    radius = r(theta_intersec,theta_0,a,r0);  
    Delta_r = fabs(radius-tracker_r);
    // std::cout << "Delta_r = " << Delta_r << std::endl;
    // std::cout << "radius  = " << radius << std::endl;
    // std::cout << "theta   = " << theta_intersec << std::endl;
    if(theta_intersec == theta_f) break; 
  }
  std::cout << "Delta_r = " << Delta_r << std::endl;
  std::cout << "radius  = " << radius << std::endl;
  std::cout << "theta   = " << theta_intersec << std::endl;

  TMarker* hit = new TMarker(tracker_r*TMath::Cos(theta_intersec),
			     tracker_r*TMath::Sin(theta_intersec),21 );
  hit->SetMarkerColor(kRed);
  return hit;
}
