#include <iostream>
#include <cmath>

using namespace std;

int* question(int n, int x, int d)
{
	int *T;
	T=new int[n];
	int poids=10; //Modifiez cette ligne afin de modifier le poids des boules
	
	for(int i=1; i<=n;i++)
	{
		if(i==x)
		{
			T[i]=poids+d;
		}
		else
		{
			T[i]=poids;
		}	
	}	
	return T;
}

int balance(int *T, int n, int d1, int d2)
{	
	int cpt=0;
	int cpt_d1=0;
	int cpt_d2=0;
	for(int i=d1;i<=d1+n;i++)
	{
		cpt_d1+=T[i];
	}
	for(int i=d2;i<=d2+n;i++)
	{
		cpt_d2+=T[i]; 
	}
	cpt++;
	return cpt_d1-cpt_d2;
			
}
		
int afficher(int*Tab,int N)
{
	cout<<"voici la liste des boules"<<endl;
	
	for(int i=1;i<=N;i++)
	{
		cout<<"Boule"<<i<<"[ "<<Tab[i]<<" ]"<<endl;
	}
}

int resoudre(int * T, int n, int d1, int d2, int d3,int & plus_moins)
{
	
	
	if(n == 1)
	{
		if(plus_moins != 0)
		{
			int resultat1=balance(T,n,d1,d2);
			
			if(resultat1 == 0)
			{
				return d3;
			}
			else if (( resultat1 > 0 && plus_moins > 0) || (resultat1 < 0 && plus_moins < 0))
			{
				return d1;
			}
			else if (( resultat1 < 0 && plus_moins < 0) || (resultat1 > 0 && plus_moins > 0))
			{
				return d2;
			}
		}
		else // Si on a 3 boules
		{
			int resultat1=balance(T,n,d1,d2);
			int resultat3=balance(T,n,d2,d3);
			
			if(resultat1 == 0)
			{
				if(resultat3 < 0)
				{
					plus_moins = 1 ;
				}
				else
				{
					plus_moins = -1;
				}
				return d3;
			}
			else if ((resultat1 > 0 && resultat3 >0) || (resultat1 < 0 && resultat3 < 0))
			{
				if(resultat1 > 0)
				{
					plus_moins = -1;
				}
				else
				{
					plus_moins = 1;
				}
				return d1;
			}
			else if ((resultat1 > 0 && resultat3 == 0) || (resultat1 < 0 && resultat3 == 0))
			{
				if(resultat1 > 0)
				{
					plus_moins = 1;
				}
				else
				{
					plus_moins = -1;
				}
				return d2;
			}
		}
	}	
	else
	{
		int resultat1=balance(T,n,d1,d2);
		
		if(plus_moins!=0)
		{
			if(resultat1 == 0)
			{
				return resoudre(T, n/3, d3,d3+n/3, d3+(2*n/3), plus_moins);
			}
			else if((resultat1 < 0 && plus_moins > 0) || (resultat1 > 0 && plus_moins < 0))
			{
				return resoudre(T, n/3, d2, d2+n/3, d2+(2*n/3), plus_moins);
			}
			else
			{
				return resoudre(T, n/3, d1, d1+n/3, d1+(2*n/3), plus_moins);
			}
		}
		else
		{
			int resultat2=balance(T,n,d1,d3);
			
			if(resultat1 == 0)
			{
				if(resultat2 < 0)
				{
					plus_moins = 1;
				}
				else
				{
					plus_moins = -1;
				}
				return resoudre(T, n/3, d3, d3+n/3, d3+(2*n/3), plus_moins);
			}
			else if((resultat1 > 0 && resultat2 == 0) || (resultat1 < 0 && resultat2 == 0))
			{
				if(resultat1 > 0)
				{
					plus_moins = -1;
				}
				else
				{
					plus_moins = 1;
				}
				return resoudre(T, n/3, d2, d2+n/3, d2+(2*n/3), plus_moins);
			}
			else
			{
				if(resultat1 > 0)
				{
					plus_moins = 1;
				}
				else
				{
					plus_moins = -1;
				}
				return resoudre(T, n/3, d1, d1+n/3, d1+(2*n/3), plus_moins);
			}
		}	
	}
}

bool verifier(int *T, int n, int a, int b, int pm)
{
	if(b!=a)
	return false;
	for(int i = 1; i<n; i++)
	{
		if(pm > 0)
		{
			if (T[a] > T[i])
			{
				return true;
			}
		}
		else if(pm < 0)
		{
			if(T[a] < T[i])
			{
				return true;
			}
		}
	}
	return false;
}

bool valider(int n)
{
	cout << "Pour pm supérieur " <<endl;
	for(int i =1; i<n; i++)
	{
		int plus_moins = 0;
		int pm = plus_moins;
		cout <<" Indice : " << i << endl;
		int *T = question (n, i, 1);
		int a = resoudre(T, n/3, 1, 1+n/3, 1+(2*n/3), plus_moins);
		cout <<" La boule instrus est : "<< a <<endl;
		cout << " Pm est égale à :"<< plus_moins <<endl;
	
		if(!verifier(T, n, a, i, pm))
		{
			cout << "Pas bon pour " << "(" << i << ") +"<<endl;
			return false;
		}
		cout <<"-------------------------------"<<endl;
	}
	cout << "Pour pm inférieur " <<endl;
	for(int j =1; j<n; j++)
	{
		int plus_moins = 0;
		int pm = plus_moins;
		cout <<" Indice : " << j <<endl;
		int *T_bis = question(n, j, -1);
		int c = resoudre(T_bis, n/3, 1, 1+n/3, 1+(2*n/3), plus_moins);
		cout <<" La boule instrus est : "<< c <<endl;
		cout << " Pm est égale à :"<< plus_moins <<endl;
		
		if(!verifier(T_bis, n, c, j, pm))
		{
			cout << "Pas bon pour " << "(" << j << ") -"<<endl;
			return false;
		}
		cout <<" ------------------------------- "<<endl;
	} 
	cout <<" Tout marche enfin je l'espère :("<<endl;
	return true;
}
int main()
{
	bool trouver;
	
	trouver = valider(27); //Modifier la taille pour changer le nombre de boules
	
		
	return 0;
	
}
	
