void feynman_monophoton()
{
   //Draw Feynman diagrams
   // To see the output of this macro, click begin_html <a href="gif/feynman.gif">here</a>. end_html
   //Author: Otto Schaile
   
   TCanvas *c1 = new TCanvas("c1", "A canvas", 10,10, 500, 500);
   c1->Range(0, 0, 70, 60);
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


   //----> Mono Whatever Extra-Dim
   // TCurlyLine *boson;
   // boson = new TCurlyLine(30, 30, 50, 10); 
   // boson->SetWaveLength(0.03);
   // boson->Draw();
   // boson = new TCurlyLine(30, 30, 50, 50); l->Draw();
   // boson->SetWavy();
   // boson->SetWaveLength(0.04);
   // boson->Draw();
   // t.DrawLatex(7,6,"#bar{f}");
   // t.DrawLatex(7,55,"f");
   // t.DrawLatex(55,55,"#gamma,Z,g");
   // t.DrawLatex(55,6,"Graviton");


   //----> Mono Whatever Dark-Mater
   TEllipse * inter = new TEllipse(30,30,5,5); 
   inter->SetFillColor(kBlack);
   inter->Draw();
   TLine *wimp;
   wimp = new TLine(30, 30, 50, 10); wimp->Draw();
   wimp = new TLine(30, 30, 50, 50); wimp->Draw();
   arrow = new TArrow(30,30,40,20,0.03,">"); arrow->Draw();
   arrow = new TArrow(30,30,40,40,0.03,">"); arrow->Draw();

   TCurlyLine *boson;
   boson = new TCurlyLine(20, 40, 30, 50); 
   boson->SetWavy();
   boson->Draw();


   t.DrawLatex(7,6,"#bar{f}");
   t.DrawLatex(7,55,"f");
   t.DrawLatex(55,55,"#bar{#chi}");
   t.DrawLatex(55,6,"#chi");
   t.DrawLatex(30,55,"#gamma");



}
