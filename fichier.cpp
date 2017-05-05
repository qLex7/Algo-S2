#include "fichier.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int creer()
{
	string nom=" " ;
	cout << "Quel est le nom du répertoire ? " ; cin >> nom ;
	nom+=".txt" ;
	ofstream fichier(nom.c_str(), ios::out) ;

	if(fichier) 
	{
		fichier.close();
	}
	else 
	{
		cerr << "Pas de fichier texte" << endl ;
	}
}

int ouvrir()
{
	string nom ;
	cout << "Quel répertoire voulez-vous ouvrir ? " ; cin >> nom ;
	nom+=".txt" ;

	ifstream fichier(nom.c_str(), ios::in) ;

	if(fichier) 
	{
		string ligne ;

		while(getline(fichier,ligne))
		{
			cout << ligne << endl ;
		}

		fichier.close() ;
	}
	else 
	{
		cerr << "Pas de fichier texte " << endl ;
	}
}

//----------------------Class personne-----------------------

Personne::Personne(string nom, string prenom,string Ad,int Cp, string Numtel)
{
	Nom = nom;
	Prenom = prenom;
	Adresse = Ad;
	CodePostal = Cp;
	NumDeTel = Numtel;

}

void ajouter()
{
	string nom ;
	cout << "Dans quel répertoire voulez-vous ajouter cette personne ? " ; cin >> nom ;
	nom+=".txt" ;

	string nomFa, prenom,Numtel ;
	string Ad ; 
	string ligne ;
	int CP ;

	cout << "Nom : " ; 
	cin >> nom ;
	cout << "Prenom : " ; 
	cin >> prenom ;
	cout << "Numéro de téléphone : " ;
	cin >> Numtel ;
	cout << "Code postale : " ;
	cin >> CP ;
	cout << "Adresse : " ; 
	cin >> Ad ;
	cout << endl ;

	ifstream ajj(nom.c_str(), ios::app) ;

	if(ajj)
	{
		 while(getline(ajj,ligne))
		{
			string nom_famille, prenom_famille ;

			ajj >> nom_famille >> prenom_famille ;

			if(nom_famille==nomFa && prenom_famille==prenom)
			{
				cout << "Erreur, le nom est déjà inscrit ! " << endl ;
				break ;
				ajj.close() ;
			}
		}
			
		
	}
	else
	{
		cout << "Il n'y a pas d'annuaire !" << endl ;
	}

	ofstream fichier_bis(nom.c_str(), ios::in | ios::app) ;

	if(fichier_bis)
	{
		Personne X(nomFa, prenom, Ad, CP, Numtel) ;

		fichier_bis << nomFa << " " << prenom << " " << Numtel << " " << CP << " " << Ad << endl ;

		fichier_bis.close() ;
	}
	else
	{
		cout << "Erreur" << endl ;
	}

}

void afficher()
{
	string nom ;
	cout << "Dans quel répertoire voulez-vous afficher cette personne ? " ; 
	cin >> nom ;
	nom+=".txt" ;

	ifstream fichier(nom.c_str(), ios::in) ;

	if(fichier)
	{	
		string chercher, chercher_bis ;
		cout << "Entrez le nom : " ; cin >> chercher ;
		cout << "Entrez le prénom : " ; cin >> chercher_bis ;

		string ligne ;
		do 
		{
			string nomFa,prenom ;
			fichier >> nomFa >> prenom ;

			if(nomFa==chercher && prenom==chercher_bis)
			{
				string contenu ;
				getline(fichier,contenu) ;
				cout << nomFa << " " << prenom << " " << contenu << endl ;
			}
		} while(getline(fichier,ligne)) ;

		fichier.close() ;
	}
	else
	{
		cerr << "Pas de fichier !" << endl ;
	}
}

void menu()
{
	int choix;

	cout<<"1 - Créer un nouveau répertoire"<<endl;
	cout<<"2 - Ouvrir un répertoire existant"<<endl;
	cout<<"3 - Ajouter une personne"<<endl;
	cout<<"4 - Afficher une personne"<<endl;
	cout<<"5 - Afficher tout le répertoire dans l'ordre du fichier"<<endl;
	cout<<"6 - Afficher tout le répertoire dans l'ordre alphabétique des noms"<<endl;
	cout<<"0 - Quitter"<<endl;
	cout<<"Entrez votre choix : " <<endl;
	cin >> choix;
	switch(choix)
	{
		case 1:
		creer();
		return;

		case 2:
		ouvrir();
		return;

		case 3:
		ajouter();
		return;

		case 4:
		afficher();
		return;

		case 5:
		//afficherRep();
		return;


		case 6:
		//afficherRepA();
		return;

		case 0:
		return;
	}
}

