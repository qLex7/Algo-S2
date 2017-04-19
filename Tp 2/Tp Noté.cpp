#include <iostream>

using namespace std;

int* question(int N, int x, int d)
{
	int *T;
	T=new int[N];
	int poids=10;
	
	for(int i=1; i<=N;i++)
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
	for(int i=1;i<N;i++)
	{
		cout<<"[";
		cout<<Tab[i];
		cout<<"]"<<endl;
		
	}
}

int resoudre(int * B, int n, int d1, int d2, int d3,int & plus_moins)
{
	
}

int main()
{
	int N;
	int x;
	int d;
	int *Tab=question(N,x,d);
	int n;
	question(27,11,5);
	
	cout<<"Entrez le nombre de boules";
	cin>>N;
	cout<<"Numéro de la boule différente";
	cin>>x;
	cout<<"1<0 ou 1>0";
	cin>>d;
	
	afficher(Tab,N);
	
}
	
