#include "collection.h"
#include <iostream>

using namespace std;

Liste::Liste() //q1
{
	debut=NULL;
}

int Liste::NouveauMaillon(int x, Maillon*M) // q2
{
	Maillon*tmp;
	tmp=new Maillon;
	
	tmp->info=x;
	tmp->suiv=M;
	return tmp;
}

int Liste::Liste(int T[], int N)// q3
{
	if(N==0)
	{
		debut=NULL;
		return;
	}
	debut=NouveauMaillon(T[0], NULL);
	for(int i=1;i<N;i++)
	{
		tmp->suiv=NouveauMaillon(T[i], NULL);
		tmp=tmp->suiv;		
	}
	
}

void Liste::afficher()//q4
{
	NouveauMaillon*=tmp=debut;
	
		if(debut=NULL)
		{
			return;
		}
		
		while(tmp!=NULL)
		{
			cout<<tmp->info;
			tmp=tmp->suiv;
		}
				
}

void Liste::aff()//q6
{
	afficher_Rec(debut);
}

void Liste::afficher_Rec(Maillon*tmp) //q6
{
	if(debut==NULL)
	{
		return;
	}
	else
	{
		cout<<tmp->info<<endl;
		afficher_Rec(tmp)->suiv;	
	}
}



int Liste::~Liste()//q5
{
	NouveauMaillon*=tmp;	
	while(debut!=NULL)
	{
		tmp=debut;
		debut=tmp->suiv;
		delete tmp;
	}
		
}

void Liste::afficher_inverse(Maillon*tmp)//q7
{
	if(debut==NULL)
	{
		return;
	}
	else
	{
		afficher_inverse(tmp) -> suiv;
		cout<<tmp -> info<<endl;
	}
	
}

void Liste::aff_bis()//q7
{
	afficher_inverse(debut);
}

int Liste::Cardinal()//q8
{
	Maillon*tmp=debut;
	cpt=0;
	
	while(tmp!=NULL)
	{
		cpt++;
		tmp = tmp -> suiv;
	}
	return cpt;	
}

bool Liste::chercher(int x)//q9
{
	Maillon*tmp=debut;
	while(tmp!=NULL)
	{
		if(tmp -> info == x)
		{
			return true;
		}
	tmp = tmp -> suiv;
	}
	return false;
	
}

bool Liste::chercher2(int x)//q10
{
	Maillon*tmp=debut;
	while(tmp!=NULL)
	{
		if(tmp -> info == x)
		{
			return true;
		}
		elseif(tmp -> info > x)
		{
			return false;
		}
	tmp = tmp -> suiv;
	}
	return false;
}

int Liste::occurence(int x)//q11
{
	Maillon*tmp=debut;
	int occ=0;
	while(tmp!=NULL)
	{
		if(tmp -> info == x)
		{
			occ++;
		}
	tmp = tmp -> suiv;
	}
	return occ;
}
	
int Liste::supprimer(int x)//q12
{
	Maillon*tmp=debut;
	Maillon*tmp2=NULL;
	while((tmp!=NULL)&&(tmp -> info != x))
	{
		tmp2 = tmp;
		tmp = tmp -> suiv;
	}
	if(tmp == NULL) return;
	
	if(tmp2 == NULL)
	{
		debut = debut -> suiv;
		delete tmp;
	}
	else
	{
		tmp2 -> suiv = tmp -> suiv;
		delete tmp;
	}
}

int Liste::supprimer_Tout(int x)//q13
{
	Maillon*tmp=debut;
	Maillon*tmp2=NULL;
	while((tmp!=NULL)
	{
		if(tmp -> info == x)
		{
			if(tmp2 == NULL)
			{
				debut = debut -> suiv;
				delete tmp;
				tmp = debut;
			}
			else
			{
				tmp2 -> suiv = tmp -> suiv;
				delete tmp;
				tmp = tmp2 -> suiv;
			}
			else
			{
				tmp2 = tmp;
				tmp = tmp -> suiv;
			}
		}
	}
}

void Liste::operator +=(int x)//q14
{
	debut=NouveauMaillon(x, debut);
}

void Liste::Liste(Liste l)//q15
{
	if(l.debut = NULL)
	{
		debut = NULL;
		return;
	}
	debut = NouveauMaillon(l.debut -> info, NULL);
	Maillon*m1 = debut;
	Maillon*m2 = l.debut -> suiv;
	while(m2 != NULL)
	{
		m1 -> suiv =NouveauMaillon(m2 -> info, NULL);
		m1 = m1 -> suiv;
		m2 = m2 -> suiv;
	}
}

