#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

int *naCyfry(int cyfry[],int liczba);
int szerokosc(int liczba);
bool Czy_zero_jeden(int cyfry[]);
int szukajK(int n);
void zakres(int liczba);

void _3cyfry(int cyfry[],int d,int liczba);
void naSlowa(int cyfry[],int liczba);

int main(int argc, char const *argv[])
{
	int liczba=atoi( argv[1] ),cyfry[6];
	zakres(liczba);
	cout<<"#Liczba n= "; 			naSlowa(naCyfry(cyfry,liczba),liczba);
	cout<<endl<<"##Liczba k= ";		naSlowa(naCyfry(cyfry,szukajK(liczba)),szukajK(liczba));	
	cout<<endl<<"###Iloczyn n*k= "; naSlowa(naCyfry(cyfry,liczba*szukajK(liczba)),liczba*szukajK(liczba));
	cout<<endl;
	return 0;
}

void naSlowa(int cyfry[],int liczba)
{
	if(szerokosc(liczba)==1&& cyfry[0]==0)	cout<<"zero";
	else if(szerokosc(liczba)==7)			cout<<"milion";
	else
	{
		_3cyfry(cyfry,5,liczba);
		_3cyfry(cyfry,2,liczba);
	}
	
}

void _3cyfry(int cyfry[],int d,int liczba)
{
	string jednosci[]			={"zero ","jeden ","dwa ","trzy ","cztery ","piec ","szesc ","siedem ","osiem ","dziewiec "};
	string wyjatkiPolanskiego[]	={"dziesiec ","jedenascie ","dwanascie ","trzynascie ","czternascie ","pietnascie ","szesnascie ","siedemanscie ","osiemnascie ","dziewietnascie "};
	string dziesiatki[]			={"dziesiec ","dwadziescia ","trzydziesci ","czterdziesci ","piecdziesiat ","szescdziesiat ","siedemdziesiat ","osiemdziesiat ","dziewiecdziesiat ",};
	string setki[]				={"sto ","dwiescie ","trzysta ","czterysta ","piecset ","szescset ","siedemset ","osiemset ","dziewiecset ",};
	string tysiace[]			={"tysiac ","tysiace ","tysiecy "};
	
	if(cyfry[d]!=0)							cout<<setki[ cyfry[d]-1 ];
	if(cyfry[d-1]==1)						cout<<wyjatkiPolanskiego[ cyfry[d-2] ];
	else if (cyfry[d-1]>0&& cyfry[d-1]!=1)	cout<<dziesiatki[ cyfry[d-1]-1 ];
	if (d==5&& cyfry[d-2]==1);
	else if(cyfry[d-1]!=1&& cyfry[d-2]!=0)	cout<<jednosci[ cyfry[d-2] ];
	
	if(d!=2&& szerokosc(liczba)>3) 
	{
		if(cyfry[3]==1&& szerokosc(liczba)==4) 		cout<<tysiace[0];	
	 	if(cyfry[3]>1&& cyfry[3]<5&& cyfry[4]==0) 	cout<<tysiace[1];	
	 	else										cout<<tysiace[2];
	}
}
int *naCyfry(int cyfry[],int liczba)
{
	int n=liczba;
	for(int i=0;i<szerokosc(n);i++)
	{
		cyfry[i]=(liczba%10);
		liczba/=10;
	}

	for(int i=szerokosc(n);i<6;i++)
		cyfry[i]=0;
	return cyfry;
}

int szerokosc(int liczba)
{
	int szerokosc; //liczby
	for(szerokosc=1;szerokosc<7;szerokosc++)
		if(liczba<pow(10,szerokosc))
			break;

	return szerokosc;	
}

bool Czy_zero_jeden(int cyfry[])
{
	for(int i=0;i<6;i++)
		if(cyfry[i]!=0 && cyfry[i]!=1)
			return false;
	return true;
}

int szukajK(int n)
{
	int k=1,tab[6];
	if(n%9==0&& n!=0)
	{
		cerr<<"Liczba k nie miesci się w zakresie "<<endl;
		exit(0);
	}
	while(!Czy_zero_jeden(naCyfry(tab,k*n)))
	{
		zakres(n*k);
		k++;
	}

	return k;
}

void zakres(int liczba)
{
	if(liczba<0|| liczba>1000000)
	{
		cerr<<"Error! Liczba nie miesci sie w zakresie."<<endl;
		exit(0);
	}
}
