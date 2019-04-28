
#include <conio.h>
#include "jeu.h"
#include <time.h>


jeu::jeu(){
	Board=new int*[Board_Horizontal+4];
	for(int i=0;i<(Board_Horizontal+4);i++)
		Board[i]=new int[Board_Vertical+4];
	for(int i=0;i<(Board_Vertical+4);i++)
	{
		Board[0][i] = Board_Boundary;
		Board[Board_Horizontal+3][i] = Board_Boundary;
		Board[1][i] = Board_Boundary;
		Board[Board_Horizontal+2][i] = Board_Boundary;
	}
	for(int i=0;i< (Board_Horizontal+4);i++)
	{
		Board[i][0] = Board_Boundary;
		Board[i][Board_Vertical+3] = Board_Boundary;
        Board[i][1] = Board_Boundary;
		Board[i][Board_Vertical+2] = Board_Boundary;
	}
	for(int i=2;i<(Board_Horizontal+2);i++)
		for(int j=2;j<(Board_Vertical+2);j++)
			Board[i][j] = Board_Empty;
}


jeu::~jeu(){
        delete []Board; 
		Board=0;
}

jeu* jeu::instance=0;


jeu* jeu::getInstance(){
 if (instance == NULL) instance = new jeu();  
    return instance;  
    }   

int jeu::PeindreEncore(void){
	int i=(6*Board_Vertical+2)/2-20;
	int mode;
	set_cursor_color(green);
	COORD pos;
	pos.X=i;
	pos.Y=3;
	set_cursor_position(pos);
    cout << "/ \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\";
    
	for(int n=4;n<=15;n=n+2){
        pos.Y=n;
        set_cursor_position(pos);
        cout << "\\" << endl;
	}
	
	for(int n=5;n<=16;n=n+2){
        pos.Y=n;
        set_cursor_position(pos);
        cout << "/" << endl;
	}
	pos.X=40;
	set_cursor_position(pos);

	for(int n=4;n<=16;n=n+2){
        pos.Y=n;
        set_cursor_position(pos);
        cout << "/" << endl;
	}
	
	for(int n=5;n<=15;n=n+2){
        pos.Y=n;
        set_cursor_position(pos);
        cout << "\\" << endl;
	}
	pos.X=2;
	pos.Y=16;
	set_cursor_position(pos);
	cout << "\\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ /";
	
	set_cursor_color(yellow);
	pos.X=14;
	pos.Y=5;
	set_cursor_position(pos);
	cout << "Encore une fois??" <<endl;
	pos.X=18;
    pos.Y=7;
	set_cursor_position(pos);
	cout << "1.Oui" <<endl;
	
    pos.Y=10;
	set_cursor_position(pos);
	cout << "2.Non" <<endl;
	
	
	set_cursor_color(white);
	pos.X=18;
    pos.Y=13;
	set_cursor_position(pos);
	cout << "choisir" <<endl;

	set_cursor_color(red);
	pos.X=31;
	pos.Y=17;
	set_cursor_position(pos);
	cout << "- Luc";
	pos.X=33;
	pos.Y=18;
	set_cursor_position(pos);
	cout << "Jerome";
	pos.Y=19;
	set_cursor_position(pos);
	cout << "Valentin";
	pos.X=35;
	pos.Y=21;
	set_cursor_color(white);
	set_cursor_position(pos);
	cout << "^_^";
	pos.X=(6*Board_Vertical+2)/2;
	pos.Y=13;
	set_cursor_position(pos);
	mode=getch();
	while(mode!=49&&mode!=50)
		{
			MessageBox(NULL,_T("Choisir 1 ou 2"),_T("Erreur!"),MB_OK|MB_ICONWARNING);
	        pos.X=(6*Board_Vertical+2)/2;
			pos.Y=13;
			set_cursor_position(pos);
			mode=getch();
		}
    clear();
	switch(mode)
	{
	case 49:
			return 1;
		case 50:
			return 2;
	}
	return 0;
}

int jeu::PeindreBienvenue(void)
{
	int i=(6*Board_Vertical+2)/2-20;
	int mode;
	set_cursor_color(green);
	COORD pos;
	pos.X=i;
	pos.Y=3;
	set_cursor_position(pos);
    cout << "/ \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\";
    
	for(int n=4;n<=15;n=n+2){
        pos.Y=n;
        set_cursor_position(pos);
        cout << "\\" << endl;
	}
	
	for(int n=5;n<=16;n=n+2){
        pos.Y=n;
        set_cursor_position(pos);
        cout << "/" << endl;
	}
	pos.X=40;
	set_cursor_position(pos);

	for(int n=4;n<=16;n=n+2){
        pos.Y=n;
        set_cursor_position(pos);
        cout << "/" << endl;
	}
	
	for(int n=5;n<=15;n=n+2){
        pos.Y=n;
        set_cursor_position(pos);
        cout << "\\" << endl;
	}
	pos.X=2;
	pos.Y=16;
	set_cursor_position(pos);
	cout << "\\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ /";
	
	set_cursor_color(yellow);
	pos.X=6;
	pos.Y=5;
	set_cursor_position(pos);
	cout << "Bienvenue de monde PUISSANCE 4!!" <<endl;
	pos.X=8;
    pos.Y=7;
	set_cursor_position(pos);
	cout << "1.Joueur VS Ordinateur" <<endl;
	
    pos.Y=9;
	set_cursor_position(pos);
	cout << "2.Joueur VS Joueur" <<endl;
	
    pos.Y=11;
	set_cursor_position(pos);
	cout << "3.Ordinateur VS Ordinateur" <<endl;
	
	set_cursor_color(white);
	pos.X=18;
    pos.Y=13;
	set_cursor_position(pos);
	cout << "choisir" <<endl;

	set_cursor_color(red);
	pos.X=31;
	pos.Y=17;
	set_cursor_position(pos);
	cout << "- Luc";
	pos.X=33;
	pos.Y=18;
	set_cursor_position(pos);
	cout << "Jerome";
	pos.Y=19;
	set_cursor_position(pos);
	cout << "Valentin";
	pos.X=35;
	pos.Y=21;
	set_cursor_color(white);
	set_cursor_position(pos);
	cout << "^_^";
	pos.X=(6*Board_Vertical+2)/2;
	pos.Y=13;
	set_cursor_position(pos);
	mode=getch();
	while(mode<49||mode>51)
		{
			MessageBox(NULL,_T("Choisir 1, 2 ou 3"),_T("Erreur!"),MB_OK|MB_ICONWARNING);
	        pos.X=(6*Board_Vertical+2)/2;
			pos.Y=13;
			set_cursor_position(pos);
			mode=getch();
		}
    clear();
	switch(mode)
	{
	case 49:
			return 1;
		case 50:
			return 2;
		case 51:
			return 3;
	}
	return 0;
}

void jeu::PeindreAurevoir(void){
	int i=(6*Board_Vertical+2)/2-20;
	set_cursor_color(green);
	COORD pos;
	pos.X=i;
	pos.Y=3;
	set_cursor_position(pos);
    cout << "/ \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\";
    
	for(int n=4;n<=15;n=n+2){
        pos.Y=n;
        set_cursor_position(pos);
        cout << "\\" << endl;
	}
	
	for(int n=5;n<=16;n=n+2){
        pos.Y=n;
        set_cursor_position(pos);
        cout << "/" << endl;
	}
	pos.X=40;
	set_cursor_position(pos);

	for(int n=4;n<=16;n=n+2){
        pos.Y=n;
        set_cursor_position(pos);
        cout << "/" << endl;
	}
	
	for(int n=5;n<=15;n=n+2){
        pos.Y=n;
        set_cursor_position(pos);
        cout << "\\" << endl;
	}
	pos.X=2;
	pos.Y=16;
	set_cursor_position(pos);
	cout << "\\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ /";
	set_cursor_color(yellow);
	pos.X=16;
    pos.Y=8;
	set_cursor_position(pos);
	cout << "Au revoir!!" <<endl;
	set_cursor_color(red);
	pos.X=31;
	pos.Y=17;
	set_cursor_position(pos);
	cout << "- Luc";
	pos.X=33;
	pos.Y=18;
	set_cursor_position(pos);
	cout << "Jerome";
	pos.Y=19;
	set_cursor_position(pos);
	cout << "Valentin";
	pos.X=35;
	pos.Y=21;
	set_cursor_color(white);
	set_cursor_position(pos);
	cout << "^_^";
}


void jeu::PeindreJoueur(int Joueur)
{
	COORD pos;
	for(int i=0;i<15;i++){
		pos.X=20+i;
		pos.Y=3*Board_Horizontal+3;
		clear(pos);
	}
	pos.X=21;
	pos.Y=3*Board_Horizontal+3;
	set_cursor_position(pos);
	if(Joueur==Joueur1)
	{
		set_cursor_color(red);
		cout << "rouge";
	}
	else {
		set_cursor_color(yellow);
		cout << "jaune";
	}
}

void jeu::PeindrePoint(int who_turn,unsigned int x, unsigned int y)
{
	color col;
	COORD pos;
	if(who_turn==Joueur1)
		col=red;
	else if(who_turn == Joueur2)
		col=yellow;
	set_cursor_color(col);
	pos.X=(y-1)*6+2;
	pos.Y=(x-1)*3+1;
	set_cursor_position(pos);
	cout <<"■■" ;
	pos.Y=(x-1)*3+2;
	set_cursor_position(pos);
	cout <<"■■" ;
}

void jeu::PeindreBoard(int Horizontal,int Vertical)
{
	COORD pos;
	set_cursor_color(blue);
	pos.X=0;
	pos.Y=0;
	set_cursor_position(pos);
	for(int i=0;i<(Horizontal+1);i++)
		for(int j=0;j<(3*Vertical+1);j++)
		{
			pos.X=j*2;
			pos.Y=i*3;
			set_cursor_position(pos);
			cout << "■" ;
		}
		for(int i=0;i<(Vertical+1);i++)
			for(int j=0;j<(3*Horizontal+1);j++)
			{
				pos.X=i*6;
			    pos.Y=j;
				set_cursor_position(pos) ;
				cout << "■" ;
			}
			set_cursor_color(default_color);
			for(int i=1;i<(Board_Vertical+1);i++)
			{
				pos.X=6*(i-1)+4;
			    pos.Y=3*Horizontal+1;
				set_cursor_position(pos);
				cout << i;
			}
			pos.X=0;
			pos.Y=3*Horizontal+2;
			set_cursor_position(pos);
			set_cursor_color(green);
			for(int i=0;i<(3*Vertical+1);i++)
				cout << "■" ;
			set_cursor_color(white);
			cout << "Joueur: " << endl;
			cout << "Colonne: " << endl << endl;
			cout << "Votre choix (";
			for(int i=1;i<(Vertical+1);i++)
				cout << i << " ";
			cout <<")?" << endl<<endl<<endl;
			set_cursor_color(green);
			for(int i=0;i<(3*Vertical+1);i++)
				cout << "■" ;
}

void jeu::erreur(int &p){
	COORD pos;
	while(p>Board_Vertical+1||p<2)
		{
			MessageBox(NULL,_T("Cette colonne n'existe pas"),_T("Error"),MB_OK|MB_ICONWARNING);
			pos.X=0;
			pos.Y=3*Board_Horizontal+8;
			for(pos.X=0;pos.X<10;pos.X++)clear(pos);
			pos.X=0;
			set_cursor_position(pos);
			cin >> p;
			p++;
		}
		while(Board[2][p]!=Board_Empty)
		{
			pos.X=0;
			pos.Y=3*Board_Horizontal+8;
			MessageBox(NULL,_T("Cette colonne est pleine"),_T("Error"),MB_OK|MB_ICONWARNING);
			for(pos.X=0;pos.X<10;pos.X++)clear(pos);
			pos.X=0;
			set_cursor_position(pos);
			cin >> p;
			p++;
		}
}

int jeu::match_nul(){
	int i=0;
	COORD pos;
	while(Board[2][i+1]!=Board_Empty)
			i++;
		if(i>=Board_Vertical+1)
		{
			MessageBox(NULL,_T("Match null!"),_T("Game Over!"),MB_OK|MB_ICONWARNING);
			pos.X=0;
			pos.Y=3*Board_Horizontal+11;
			set_cursor_position(pos);
			return 0;
		}
		else return 1;
}

void jeu::ChangerJoueur(int& Who_Turn){
	if(Who_Turn == Joueur1)
		Who_Turn = Joueur2;
	else Who_Turn = Joueur1;
}

void jeu::viderBoard(){
	for(int i=2;i<(Board_Horizontal+2);i++)
		for(int j=2;j<(Board_Vertical+2);j++)
			Board[i][j] = Board_Empty;
}



//*************************************************************************



int Joueur::AvecSucces(int mode){
	int Count_Gauche = 1;
	int Count_Droit = 1;
	int m=0;
	for(int i = 2;i<(Board_Horizontal+2);i++)
	{
		if(m==1)break;
		for(int j = 2;j<(Board_Vertical+2);j++)
		{
			if(B[i][j]!=joueur)
				continue;
			while(B[i][j-Count_Gauche] == joueur)
				Count_Gauche++;
			while(B[i][j+Count_Droit] == joueur)
				Count_Droit++;

			if((Count_Gauche+Count_Droit) >= 5)
			{
				m=1;
				break;
			}
			Count_Gauche=1;
			Count_Droit=1;
			}
	}
	for(int i = 2;i<(Board_Horizontal+2);i++)
	{
		if(m==1)break;
		for(int j = 2;j<(Board_Vertical+2);j++)
		{
			if(B[i][j]!=joueur)
				continue;
			while(B[i+Count_Gauche][j] == joueur)
				Count_Gauche++;
			while(B[i-Count_Droit][j] == joueur)
				Count_Droit++;
			if((Count_Gauche+Count_Droit) >= 5)
			{
				m=1;
				break;
		     }
			Count_Gauche=1;
			Count_Droit=1;
	        }
	}
	for(int i = 2;i<(Board_Horizontal+2);i++)
	{
		if(m==1)break;
		for(int j = 2;j <(Board_Vertical+2);j++)
		{
			if(B[i][j]!=joueur)
				continue;
			while(B[i-Count_Gauche][j-Count_Gauche] == joueur)
				Count_Gauche++;
			while(B[i+Count_Droit][j+Count_Droit] == joueur)
				Count_Droit++;
			if((Count_Gauche+Count_Droit) >= 5)
			{
				m=1;
				break;
			}
			Count_Gauche=1;
			Count_Droit=1;
		}
	}
	for(int i = 2;i<(Board_Horizontal+2);i++)
	{
		if(m==1)break;
		for(int j = 2;j <(Board_Vertical+2);j++)
		{
			if(B[i][j]!=joueur)
				continue;
			while(B[i+Count_Gauche][j-Count_Gauche] == joueur)
				Count_Gauche++;
			while(B[i-Count_Droit][j+Count_Droit] == joueur)
				Count_Droit++;
			if((Count_Gauche+Count_Droit) >= 5)
			{
				m=1;
				break;
			}
			Count_Gauche=1;
			Count_Droit=1;
		}

	}
	if(m==0)return 0;
	else{
		message(mode);
		return 1;
		}
}


int Joueur::Mouvoir(int Vertical)
{
	int i=2;
	while(B[i][Vertical]==Board_Empty)
		i++;
	B[i-1][Vertical] = joueur;
	return i-1;
}



//*********************************************************************

void JoueurOrdinateur::message(int m){
	if(m==3){
	if(getjoueur()==1)MessageBox(NULL,_T("Ordinateur 1 gagne!"),_T("Game Over!"),MB_OK|MB_ICONWARNING);
	if(getjoueur()==2)MessageBox(NULL,_T("Ordinateur 2 gagne!"),_T("Game Over!"),MB_OK|MB_ICONWARNING);
	}
	if(m==1)MessageBox(NULL,_T("Bien que c'est un jeu simple, l'humain ne peut pas me vaincre .Vous est frit! L'ordinateur va domaine le monde!!!"),_T("Game Over!"),MB_OK|MB_ICONWARNING);
}


void JoueurOrdinateur::detecteur_vertical(int nombre,int joueur){
	int i,j,Gauche,Droit;
	X=0;
	Y=0;
	_Gauche=0;
	_Droit=0;
	for(i = 0;i<=2;i++)situation[i]=0;
	for( i = 2;i<(Board_Horizontal+2);i++)
		for(j = 2;j<(Board_Vertical+2);j++)
		{
			Gauche=0;
			Droit=0;
			if(B[i][j]!=joueur)
				continue;
			while(B[i][j-Gauche] == joueur)
				Gauche++;
			while(B[i][j+Droit] == joueur)
				Droit++;
			if((Gauche+Droit) ==nombre)
			{
				if((B[i][j-Gauche] != Board_Empty)&&(B[i][j+Droit] != Board_Empty))
					continue;
				else if(((B[i][j-Gauche] == Board_Empty)&&(B[i][j+Droit] != Board_Empty))||((B[i][j-Gauche] != Board_Empty)&&(B[i][j+Droit] == Board_Empty)))
				{
					situation[1]++;
					Y=i;
					X=j;
					_Gauche=Gauche;
					_Droit=Droit;
				}
				else {
					situation[2]++;
					Y=i;
					X=j;
					_Gauche=Gauche;
					_Droit=Droit;
				}
				return;
			}
			}
}

void JoueurOrdinateur::detecteur_horizontal(int nombre,int joueur){
	int i,j,Gauche,Droit;
	X=0;
	Y=0;
	_Gauche=0;
	_Droit=0;
	for(i = 0;i<=2;i++)situation[i]=0;
	for(i = 2;i<(Board_Horizontal+2);i++)
		for(j = 2;j<(Board_Vertical+2);j++)
		{
			Gauche=1;
			Droit=1;
			if(B[i][j]!=joueur)
				continue;
			while(B[i+Gauche][j] == joueur)
				Gauche++;
			while(B[i-Droit][j] == joueur)
				Droit++;
			if((Gauche+Droit) == nombre)
				{
					
				if((B[i+Gauche][j] != Board_Empty)&&(B[i-Droit][j] != Board_Empty))
					continue;
				else if((B[i+Gauche][j] != Board_Empty)&&(B[i-Droit][j] == Board_Empty))
				{
					situation[1]++;
					Y=i;
					X=j;
					_Gauche=Gauche;
					_Droit=Droit;
				}
				return;
				}
			}
		}



void JoueurOrdinateur::detecteur_ligne_oblique_gauche(int nombre,int joueur){
    int i,j,Gauche,Droit;
    X=0;
	Y=0;
	_Gauche=0;
	_Droit=0;
	for(i = 0;i<=2;i++)situation[i]=0;
	for(i = 2;i<(Board_Horizontal+2);i++)
		for(j = 2;j <(Board_Vertical+2);j++)
		{
			Gauche=0;
			Droit=0;
			if(B[i][j]!=joueur)
					continue;
				while(B[i+Gauche][j-Gauche] == joueur)
					Gauche++;
				while(B[i-Droit][j+Droit] == joueur)
					Droit++;
				if((Gauche+Droit) == nombre)
						{
							if((B[i+Gauche][j-Gauche] != Board_Empty)&&(B[i-Droit][j+Droit] != Board_Empty))
								continue;
							else if(((B[i+Gauche][j-Gauche] == Board_Empty)&&(B[i-Droit][j+Droit] != Board_Empty))||((B[i+Gauche][j-Gauche] != Board_Empty)&&(B[i-Droit][j+Droit] == Board_Empty)))
								{
					situation[1]++;
					Y=i;
					X=j;
					_Gauche=Gauche;
					_Droit=Droit;
				}
				else {
					situation[2]++;
					Y=i;
					X=j;
					_Gauche=Gauche;
					_Droit=Droit;
				}
				return;
		}
		}
}

	void JoueurOrdinateur::detecteur_ligne_oblique_droit(int nombre,int joueur){
    int i,j,Gauche,Droit;
	X=0;
	Y=0;
	_Gauche=0;
	_Droit=0;
	for(i=0;i<=2;i++)situation[i]=0;
	for(i = 2;i<(Board_Horizontal+2);i++)
		for(j = 2;j <(Board_Vertical+2);j++)
		{
			Gauche=0;
			Droit=0;
			if(B[i][j]!=joueur)
					continue;
				while(B[i+Droit][j+Droit] == joueur)
					Droit++;
				while(B[i-Gauche][j-Gauche] == joueur)
					Gauche++;

				if((Gauche+Droit) == nombre)
						{
							if((B[i+Droit][j+Droit] != Board_Empty)&&(B[i-Gauche][j-Gauche] != Board_Empty))
								continue;
							else if(((B[i+Droit][j+Droit] == Board_Empty)&&(B[i-Gauche][j-Gauche] != Board_Empty))||((B[i+Droit][j+Droit] != Board_Empty)&&(B[i-Gauche][j-Gauche] == Board_Empty)))
								{
					situation[1]++;
					Y=i;
					X=j;
					_Gauche=Gauche;
					_Droit=Droit;
				}
				else {
					situation[2]++;
					Y=i;
					X=j;
					_Gauche=Gauche;
					_Droit=Droit;
				}
				return;
		}
		}
}


COORD JoueurOrdinateur::Actionneur_vertical(){
	srand(time(0));
	int random;
    COORD coord;
	coord.X=0;
	coord.Y=0;
	if(situation[1]==1){
		if((B[Y][X-_Gauche] == Board_Empty)&&(B[Y+1][X-_Gauche] != Board_Empty))
		{
				coord.X=Mouvoir(X-_Gauche);
				coord.Y=X-_Gauche;
				return coord;
		}
		else if((B[Y][X+_Droit] == Board_Empty)&&(B[Y+1][X+_Droit] != Board_Empty))
		{
			coord.X=Mouvoir(X+_Droit);
			coord.Y=X+_Droit;
			return coord;
		}
	}
	if(situation[2]==1){
		if((B[Y+1][X-_Gauche] != Board_Empty)&&(B[Y+1][X+_Droit] != Board_Empty))
		{
			random = 1+rand()%2;
			if(random==1)
			{
				coord.X=Mouvoir(X-_Gauche);
			    coord.Y=X-_Gauche;
			    return coord;
			}
			else
			{
				coord.X=Mouvoir(X+_Droit);
			    coord.Y=X+_Droit;
			    return coord;
			}
		}
		else if((B[Y+1][X-_Gauche] == Board_Empty)&&(B[Y+1][X+_Droit] != Board_Empty))
			{
				coord.X=Mouvoir(X+_Droit);
			    coord.Y=X+_Droit;
			    return coord;
			}
		else if((B[Y+1][X-_Gauche] != Board_Empty)&&(B[Y+1][X+_Droit] == Board_Empty))
			{
				coord.X=Mouvoir(X-_Gauche);
			    coord.Y=X-_Gauche;
			    return coord;
			}
	}
	return coord;
}

COORD JoueurOrdinateur::Actionneur_horizontal(){
	COORD coord;
	coord.X=0;
	coord.Y=0;
	if(situation[1]==1){
		coord.X=Mouvoir(X);
		coord.Y=X;
		return coord;
	}
	return coord;
}

COORD JoueurOrdinateur::Actionneur_ligne_oblique_gauche(){
	srand(time(0));
	int random;
	COORD coord;
	coord.X=0;
	coord.Y=0;
	if(situation[1]==1){
		if((B[Y+_Gauche][X-_Gauche] == Board_Empty)&&(B[Y+_Gauche+1][X-_Gauche] != Board_Empty))
		{
			coord.X=Mouvoir(X-_Gauche);
		    coord.Y=X-_Gauche;
		    return coord;
		}
		else if((B[Y-_Droit][X+_Droit] == Board_Empty)&&(B[Y-_Droit+1][X+_Droit] != Board_Empty))
		{
			coord.X=Mouvoir(X+_Droit);
		    coord.Y=X+_Droit;
		    return coord;
		}
	}
	if(situation[2]==1){
		if((B[Y+_Gauche+1][X-_Gauche] != Board_Empty)&&(B[Y-_Droit+1][X+_Droit] != Board_Empty))
		{
			random = 1+rand()%2;
			if(random==1)
			{
			    coord.X=Mouvoir(X-_Gauche);
		        coord.Y=X-_Gauche;
		        return coord;
			}
			else
			{
			    coord.X=Mouvoir(X+_Droit);
		        coord.Y=X+_Droit;
		        return coord;
			}
		}
		else if((B[Y+_Gauche+1][X-_Gauche] == Board_Empty)&&(B[Y-_Droit+1][X+_Droit] != Board_Empty))
			{
			    coord.X=Mouvoir(X-_Gauche);
		        coord.Y=X-_Gauche;
		        return coord;
			}
		else if((B[Y+_Gauche+1][X-_Gauche] != Board_Empty)&&(B[Y-_Droit+1][X+_Droit] == Board_Empty))
			{
			    coord.X=Mouvoir(X+_Droit);
		        coord.Y=X+_Droit;
		        return coord;
			}
	}
	return coord;
}

COORD JoueurOrdinateur::Actionneur_ligne_oblique_droit(){
		srand(time(0));
	    int random;
		COORD coord;
	    coord.X=0;
	    coord.Y=0;
		if(situation[1]==1){
		if((B[Y+_Droit][X+_Droit] == Board_Empty)&&(B[Y+_Droit+1][X+_Droit] != Board_Empty))
		{
			    coord.X=Mouvoir(X+_Droit);
		        coord.Y=X+_Droit;
		        return coord;
		}
		else if((B[Y-_Gauche][X-_Gauche] == Board_Empty)&&(B[Y-_Gauche+1][X-_Gauche] != Board_Empty))
		{
		    coord.X=Mouvoir(X-_Gauche);
		    coord.Y=X-_Gauche;
		    return coord;
		}
	}
	if(situation[2]==1){
		if((B[Y+_Droit+1][X+_Droit] != Board_Empty)&&(B[Y-_Gauche+1][X-_Gauche] != Board_Empty))
		{
			random = 1+rand()%2;
			if(random==1)
			{
		        coord.X=Mouvoir(X+_Droit);
		        coord.Y=X+_Droit;
		        return coord;
			}
			else
			{
		        coord.X=Mouvoir(X-_Gauche);
		        coord.Y=X-_Gauche;
		        return coord;
			}
		}
		else if((B[Y+_Droit+1][X+_Droit] == Board_Empty)&&(B[Y-_Gauche+1][X-_Gauche] != Board_Empty))
			{	
		        coord.X=Mouvoir(X-_Gauche);
		        coord.Y=X-_Gauche;
		        return coord;
			}
		else if((B[Y+_Droit+1][X+_Droit] != Board_Empty)&&(B[Y-_Gauche+1][X-_Gauche] == Board_Empty))
			{
		        coord.X=Mouvoir(X+_Droit);
		        coord.Y=X+_Droit;
		        return coord;
			}
	}
	return coord;
}

COORD JoueurOrdinateur::ordinateur_Mouvoir(int nombre,int joueur){
	COORD coord;
	detecteur_ligne_oblique_gauche(nombre,joueur);
	coord=Actionneur_ligne_oblique_gauche();
	if(coord.X!=0&&coord.Y!=0)return coord;
	detecteur_ligne_oblique_droit(nombre,joueur);
	coord=Actionneur_ligne_oblique_droit();
	if(coord.X!=0&&coord.Y!=0)return coord;
	detecteur_vertical(nombre,joueur);
	coord=Actionneur_vertical();
	if(coord.X!=0&&coord.Y!=0)return coord;
	detecteur_horizontal(nombre,joueur);
	coord=Actionneur_horizontal();
	if(coord.X!=0&&coord.Y!=0)return coord;
	return coord;
}
COORD JoueurOrdinateur::operation(){
	int i,J1,J2;
	COORD coord;
	srand(time(0));
	int random;
	if(getjoueur()==Joueur1){
		J1=2;
		J2=1;
	}
	else{
		J1=1;
		J2=2;
	}
	coord=ordinateur_Mouvoir(4,J2);
    if(coord.X!=0&&coord.Y!=0)return coord;
	coord=ordinateur_Mouvoir(4,J1);
	if(coord.X!=0&&coord.Y!=0)return coord;
	coord=ordinateur_Mouvoir(3,J2);
	if(coord.X!=0&&coord.Y!=0)return coord;
	coord=ordinateur_Mouvoir(3,J1);
	if(coord.X!=0&&coord.Y!=0)return coord;
	for(i = 2;i<(Board_Horizontal+2);i++)
		for(int j = 2;j<(Board_Vertical+2);j++)
		{
			if(B[i][j]!=J1)
				continue;
			srand(time(0));
	        random=1+rand()%3;
			if(random==1&&(B[2][j-1] == Board_Empty)){
				coord.X=Mouvoir(j-1);
				coord.Y=j-1;
				return coord;
			}
			if(random==2&&(B[i-1][j] == Board_Empty)){
				coord.X=Mouvoir(j);
				coord.Y=j;
				return coord;
			}
			if(random==3&&(B[2][j+1] == Board_Empty)){
				coord.X=Mouvoir(j+1);
				coord.Y=j+1;
				return coord;
			}
			if(random==2&&(B[i-1][j] != Board_Empty)){
				random=1+rand()%7;
				while(1){
					int r=random;
				    if(B[2][random] != Board_Empty)random++;
				    if(random==8&&B[2][random] != Board_Empty)random=2;
				    if(r==random)break;
				}
		        coord.X=Mouvoir(random);
		        coord.Y=random;
		        return coord;
			}
		}
		random=1+rand()%7;
		while(1){
			    int r=random;
			    if(B[2][random] != Board_Empty)random++;
				if(random==8&&B[2][random] != Board_Empty)random=2;
				if(r==random)break;
				}
		coord.X=Mouvoir(random);
		coord.Y=random;
		return coord;
}


//*********************************************************************

void JoueurHumain::message(int m){
	if(m==2){
	if(getjoueur()==1)MessageBox(NULL,_T("Joueur 1 gagne!"),_T("Game Over!"),MB_OK|MB_ICONWARNING);
	if(getjoueur()==2)MessageBox(NULL,_T("Joueur 2 gagne!"),_T("Game Over!"),MB_OK|MB_ICONWARNING);
	}
	if(m==1)MessageBox(NULL,_T("Même si vous avez gagné le jeu, je vais vous vaincre tôt ou tard!"),_T("Game Over!"),MB_OK|MB_ICONWARNING);
}
