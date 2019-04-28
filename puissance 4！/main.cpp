
#include <iostream>
#include "jeu.h"

int main(int argc, char *argv[])
{
int again=1;
while(again==1){
Joueur* joueur;
JoueurOrdinateur* ordinateur;
int Who_Turn = Joueur1;
jeu* Jeu=jeu::getInstance();
int x,mode,position;
int i=0;
COORD pos,coord;
Jeu->set_title(L"puissance 4");
Jeu->set_dimensions((6*Board_Vertical+2),(3*Board_Horizontal+9)+4);
Jeu->clear();
mode=Jeu->PeindreBienvenue();
Jeu->clear();
Jeu->PeindreBoard(Board_Horizontal,Board_Vertical);

if(mode==1)
{
	JoueurHumain p1(Joueur1,Jeu->Board);
	JoueurOrdinateur p2(Joueur2,Jeu->Board);
	while(1)
	{
		
		Jeu->PeindreJoueur(Who_Turn);
		pos.X=0;
		pos.Y=3*Board_Horizontal+8;
		Jeu->set_cursor_position(pos);
		cin >> position;
		position++;
		Jeu->erreur(position);
		x=p1.Mouvoir(position);
		Jeu->PeindrePoint(Who_Turn,x-1,position-1);
		if(p1.AvecSucces(mode)!=0)break;
		Jeu->ChangerJoueur(Who_Turn);
		Jeu->PeindreJoueur(Who_Turn);
		coord=p2.operation();
		Jeu->PeindrePoint(Who_Turn,coord.X-1,coord.Y-1);
		i=Jeu->match_nul();
		if(i==0)return EXIT_SUCCESS;
		if(p2.AvecSucces(mode)!=0)break;
		Jeu->ChangerJoueur(Who_Turn);
		Jeu->PeindreJoueur(Who_Turn);
	}
}

if(mode==2)
{
	JoueurHumain p1(Joueur1,Jeu->Board);
	JoueurHumain p2(Joueur2,Jeu->Board);
	while(1)
	{
		if(Who_Turn==Joueur1)
		    joueur=&p1;
		if(Who_Turn==Joueur2)
			joueur=&p2;
		Jeu->PeindreJoueur(Who_Turn);
		pos.X=0;
		pos.Y=3*Board_Horizontal+8;
		Jeu->set_cursor_position(pos);
		cin >>position;
		position++;
		Jeu->erreur(position);
		x=joueur->Mouvoir(position);
		Jeu->PeindrePoint(Who_Turn,x-1,position-1);
		i=Jeu->match_nul();
		if(i==0)break;
		if(p1.AvecSucces(mode)!=0)break;	
		if(p2.AvecSucces(mode)!=0)break;
		Jeu->ChangerJoueur(Who_Turn);
		Jeu->PeindreJoueur(Who_Turn);
	}
}



if(mode==3)
{
	JoueurOrdinateur p1(Joueur1,Jeu->Board);
	JoueurOrdinateur p2(Joueur2,Jeu->Board);
	while(1)
	{
		if(Who_Turn==Joueur1)
		    ordinateur=&p1;
		if(Who_Turn==Joueur2)
			ordinateur=&p2;
		Jeu->PeindreJoueur(Who_Turn);
		coord=ordinateur->operation();
		Jeu->PeindrePoint(Who_Turn,coord.X-1,coord.Y-1);
		i=0;
		i=Jeu->match_nul();
		if(i==0)break;
		if(p2.AvecSucces(mode)!=0)break;
		if(p1.AvecSucces(mode)!=0)break;
		Jeu->ChangerJoueur(Who_Turn);
		Jeu->PeindreJoueur(Who_Turn);
	}
}
Jeu->clear();
again=Jeu->PeindreEncore();
Jeu->viderBoard();
if(again!=1)
	{
		Jeu->PeindreAurevoir();
		Jeu->~jeu();
}
}
return 0;
}