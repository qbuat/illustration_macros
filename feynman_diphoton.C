void feynman_diphoton()
{
   //Draw Feynman diagrams
   // To see the output of this macro, click begin_html <a href="gif/feynman.gif">here</a>. end_html
   //Author: Otto Schaile
   
  TCanvas* c1 = c_qqGgamgam();
  TCanvas* c2 = c_glugluGgamgam();

  TCanvas* c3 = c_sm_qqtoamgam();
  TCanvas* c4 = c_sm_gluglutogamgam();
}



TCanvas* c_qqGgamgam()
{
   TCanvas *c1 = new TCanvas("cqqGgamgam", "qq->G->gamgam", 10,10, 600, 300);
   c1->Range(0, 0, 80, 60);
   Int_t linsav = gStyle->GetLineWidth();
   gStyle->SetLineWidth(3);
   TLatex t;
   t.SetTextAlign(22);
   t.SetTextSize(0.1);
   TLine * l;
   l = new TLine(10, 10, 30, 30); l->Draw();
   l = new TLine(10, 50, 30, 30); l->Draw();

   TArrow * arrow;
   arrow = new TArrow(30,30,17,17,0.03,">"); arrow->Draw();
   arrow = new TArrow(10,50,17,43,0.03,">"); arrow->Draw();
   l = new TLine(30, 30, 50, 30); l->SetLineStyle(kDashed); 
   l->Draw();

   TCurlyLine *photon;
   photon = new TCurlyLine(50, 30, 70, 10); 
   photon->SetWaveLength(.04);
   photon->SetWavy();
   photon->Draw();
   photon = new TCurlyLine(50, 30, 70, 50); 
   photon->SetWaveLength(.04);
   photon->SetWavy();
   photon->Draw();


   t.DrawLatex(20,15,"#bar{q}");
   t.DrawLatex(20,45,"q");
   t.DrawLatex(60,45,"#gamma");
   t.DrawLatex(60,15,"#gamma");
   t.DrawLatex(40,35,"Graviton");
   return c1;
}

TCanvas* c_glugluGgamgam()
{
   TCanvas *c1 = new TCanvas("cggGgamgam", "gluglu->G->gamgam", 10,10, 600, 300);
   c1->Range(0, 0, 80, 60);
   Int_t linsav = gStyle->GetLineWidth();
   gStyle->SetLineWidth(3);
   TLatex t;
   t.SetTextAlign(22);
   t.SetTextSize(0.1);
   TCurlyLine* gluon;
   gluon = new TCurlyLine(10, 10, 30, 30); 
   gluon->SetWaveLength(0.04);
   gluon->Draw();
   gluon = new TCurlyLine(10, 50, 30, 30); 
   gluon->SetWaveLength(0.04);
   gluon->Draw();
   TLine * l;
   l = new TLine(30, 30, 50, 30); l->SetLineStyle(kDashed); 
   l->Draw();

   TCurlyLine *photon;
   photon = new TCurlyLine(50, 30, 70, 10); 
   photon->SetWaveLength(0.04);
   photon->SetWavy();
   photon->Draw();
   photon = new TCurlyLine(50, 30, 70, 50); 
   photon->SetWaveLength(0.04);
   photon->SetWavy();
   photon->Draw();


   t.DrawLatex(20,15,"g");
   t.DrawLatex(20,45,"g");
   t.DrawLatex(60,45,"#gamma");
   t.DrawLatex(60,15,"#gamma");
   t.DrawLatex(40,35,"Graviton");
   return c1;
}
TCanvas* c_sm_qqtoamgam()
{
   TCanvas *c1 = new TCanvas("csmqqtogamgam", "SM: qq->gamgam", 10,10, 600, 300);
   c1->Range(0, 0, 80, 60);
   Int_t linsav = gStyle->GetLineWidth();
   gStyle->SetLineWidth(3);
   TLatex t;
   t.SetTextAlign(22);
   t.SetTextSize(0.1);
   TLine * l;
   l = new TLine(10, 10, 40, 10); l->Draw();
   l = new TLine(40, 10, 40, 50); l->Draw();
   l = new TLine(10, 50, 40, 50); l->Draw();

   TArrow * arrow;
   arrow = new TArrow(10,10,25,10,0.03,">"); arrow->Draw();
   arrow = new TArrow(30,50,25,50,0.03,">"); arrow->Draw();
   arrow = new TArrow(40,10,40,30,0.03,">"); arrow->Draw();

   TCurlyLine *photon;
   photon = new TCurlyLine(40, 10, 70, 10); 
   photon->SetWavy();
   photon->SetWaveLength(0.04);
   photon->Draw();
   photon = new TCurlyLine(40, 50, 70, 50); 
   photon->SetWavy();
   photon->SetWaveLength(0.04);
   photon->Draw();


   t.DrawLatex(20,5,"#bar{q}");
   t.DrawLatex(20,55,"q");
   t.DrawLatex(60,55,"#gamma");
   t.DrawLatex(60,5,"#gamma");
   return c1;
}

TCanvas* c_sm_gluglutogamgam()
{
   TCanvas *c1 = new TCanvas("csmggtogamgam", "SM: gluglu->gamgam", 10,10, 600, 300);
   c1->Range(0, 0, 80, 60);
   Int_t linsav = gStyle->GetLineWidth();
   gStyle->SetLineWidth(3);
   TLatex t;
   t.SetTextAlign(22);
   t.SetTextSize(0.1);
   TCurlyLine * gluon;
   gluon = new TCurlyLine(5, 10, 30, 10); 
   gluon->SetWaveLength(0.04);
   gluon->Draw();
   gluon = new TCurlyLine(5, 50, 30, 50); 
   gluon->SetWaveLength(0.04);
   gluon->Draw();

   TLine *l;
   l = new TLine(30,10,50,10);l->Draw();
   l = new TLine(50,10,50,50);l->Draw();
   l = new TLine(50,50,30,50);l->Draw();
   l = new TLine(30,50,30,10);l->Draw();

   TArrow * arrow;
   arrow = new TArrow(30,10,40,10,0.03,">"); arrow->Draw();
   arrow = new TArrow(50,10,50,30,0.03,">"); arrow->Draw();
   arrow = new TArrow(50,50,40,50,0.03,">"); arrow->Draw();
   arrow = new TArrow(30,50,30,30,0.03,">"); arrow->Draw();

   TCurlyLine *photon;
   photon = new TCurlyLine(50, 10, 70, 10); 
   photon->SetWavy();
   photon->SetWaveLength(0.04);
   photon->Draw();
   photon = new TCurlyLine(50, 50, 70, 50); 
   photon->SetWavy();
   photon->SetWaveLength(0.04);
   photon->Draw();


   t.DrawLatex(20,5,"g");
   t.DrawLatex(20,55,"g");
   t.DrawLatex(60,55,"#gamma");
   t.DrawLatex(60,5,"#gamma");
   return c1;
}
