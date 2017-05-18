#ifndef Collection_m
#define Collection_m


class Maillon
{	
	
	friend class Liste;
	int info;
	Maillon *suiv;
	
	
	public:
		Maillon(int,int);
	
	
};


class Liste
{
	Maillon *debut;
	
	public:
	int Liste();
	int Liste(int,int);
	int NouveauMaillon(Maillon*, int);
	void afficher();
	void afficher_Rec(Maillon*tmp);
	~Liste();
	
};
#endif
