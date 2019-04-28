#ifndef JEU_H_
#define JEU_H_
#include "console.h"
#include <tchar.h>

#define Board_Horizontal 6 
#define Board_Vertical 7 
#define Board_Boundary 3 
#define Board_Empty 0 
#define Joueur1 1 
#define Joueur2 2 

class jeu:public console{
private:
    jeu();
    static jeu* instance;
public:
	int **Board;
	~jeu();
	int PeindreBienvenue(void);
	int PeindreEncore(void);
	void PeindreAurevoir(void);
	void PeindreJoueur(int Joueur);
	void PeindrePoint(int who_turn,unsigned int x, unsigned int y);
	void PeindreBoard(int Horizontal,int Vertical);
	void erreur(int &p);
	int match_nul();
	void ChangerJoueur(int& Who_Turn);
	void viderBoard();
    static jeu* getInstance();
};


class Joueur{
private:
	int joueur;
	virtual void message(int m)=0;
public:
	int **B;
	Joueur(const int j,int** board):joueur(j),B(board){}
	int AvecSucces(int m);
	int Mouvoir(int Vertical);
	int getjoueur()const{return joueur;}
};

class JoueurHumain:public Joueur{
private:
	void message(int m);
public:
	JoueurHumain(const int j,int** board):Joueur(j,board){}
};


class JoueurOrdinateur:public Joueur{
private:
	int X;
	int Y;
	int _Gauche;
	int _Droit;
	int situation[3];
	void detecteur_vertical(int nombre,int joueur);
	void detecteur_horizontal(int nombre,int joueur);
	void detecteur_ligne_oblique_gauche(int nombre,int joueur);
    void detecteur_ligne_oblique_droit(int nombre,int joueur);
	COORD Actionneur_vertical();
	COORD Actionneur_horizontal();
	COORD Actionneur_ligne_oblique_gauche();
	COORD Actionneur_ligne_oblique_droit();
	COORD ordinateur_Mouvoir(int nombre,int joueur);
	void message(int m);
public:
	JoueurOrdinateur(const int j,int** board):Joueur(j,board),X(0),Y(0),_Gauche(0),_Droit(0){
		for(int i=1;i<3;i++)situation[i]=0;
	}
	COORD operation();
};



#endif
