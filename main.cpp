#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <iterator>

using namespace std;

void zakres(int liczba);
vector<int> naCyfry(int liczba);
bool Czy_zero_jeden(int liczba);
int szukajK(int n);

void naSlowa(int liczba);
void _3cyfry(int liczba,int d);
void regulaTysiaca(int liczba);

//zmienne globalne:
string jednosci[]			={"zero ","jeden ","dwa ","trzy ","cztery ","piec ","szesc ","siedem ","osiem ","dziewiec "};
string wyjatkiPolanskiego[]	={"dziesiec ","jedenascie ","dwanascie ","trzynascie ","czternascie ","pietnascie ","szesnascie ","siedemanscie ","osiemnascie ","dziewietnascie "};
string dziesiatki[]			={"dziesiec ","dwadziescia ","trzydziesci ","czterdziesci ","piecdziesiat ","szescdziesiat ","siedemdziesiat ","osiemdziesiat ","dziewiecdziesiat ",};
string setki[]				={"sto ","dwiescie ","trzysta ","czterysta ","piecset ","szescset ","siedemset ","osiemset ","dziewiecset ",};
string tysiace[]			={"tysiac ","tysiace ","tysiecy "};

int main(int argc, char *argv[])
{
	int liczba=atoi(argv[1]);
	zakres(liczba);
	cout<<"#Liczba n= "; 			naSlowa(liczba);	
	cout<<endl<<"##Liczba k= "; 	naSlowa(szukajK(liczba));
	cout<<endl<<"###Iloczyn n*k= "; zakres(liczba*szukajK(liczba));
	naSlowa(liczba*szukajK(liczba));
	cout<<endl;

	naCyfry(liczba).clear();
}
void naSlowa(int liczba)
{
		
	if(naCyfry(liczba).size()==1&&naCyfry(liczba)[0]==0)
		cout<<jednosci[0];
	else if(naCyfry(liczba).size()==7)
		cout<<"milion";
	else
	{
		if(naCyfry(liczba).size()>3)
		{
			_3cyfry(liczba,5);
			regulaTysiaca(liczba);
		}
		_3cyfry(liczba,2);
}
}	


void _3cyfry(int liczba,int d)
{
	if(naCyfry(liczba)[d]!=0)  
	{	
		cout<<setki[ naCyfry(liczba)[d]-1 ];
		if( naCyfry(liczba)[d-1]==0&& naCyfry(liczba)[d-2]!=0)
		{
			cout<<jednosci[ naCyfry(liczba)[d-2] ];
		}
	}
	if(naCyfry(liczba)[d-1]!=0&& naCyfry(liczba)[d-1]>1) 
	{
		cout<<dziesiatki[ naCyfry(liczba)[d-1]-1 ];
		if(naCyfry(liczba)[d-2]!=0)
		{
			cout<<jednosci[ naCyfry(liczba)[d-2] ];
		}
	}
	else if(naCyfry(liczba)[d-1]!=0&& naCyfry(liczba)[d-1]==1)
	{
		cout<<wyjatkiPolanskiego[ naCyfry(liczba)[d-2] ];
	}
	if(d==5&& naCyfry(liczba)[d-2]==1);
	else
	{
		if(naCyfry(liczba)[d]==0&& naCyfry(liczba)[d-1]==0&& naCyfry(liczba)[d-2]!=0)
		{
		 	cout<<jednosci[ naCyfry(liczba)[d-2] ];
		}
	}
}

void regulaTysiaca(int liczba)
{
	if(naCyfry(liczba)[3]==1&& naCyfry(liczba)[4]==0)
 		cout<<tysiace[0];
 	else if(naCyfry(liczba)[3]>1&& naCyfry(liczba)[3]<5)
		cout<<tysiace[1];
 	else 
 		cout<<tysiace[2];
}

void zakres(int liczba)
{
	if(liczba<0|| liczba>1000000)
	{
		cerr<<"Error! Liczba nie miesci sie w zakresie."<<endl;
		exit(0);
	}
}

vector<int> naCyfry(int liczba)
{
	vector<int> cyfry;
	int szerokosc; //liczby
	for(szerokosc=1;szerokosc<7;szerokosc++)
		if(liczba<pow(10,szerokosc))
			break;	

	for(int i=0;i<szerokosc;i++)
	{
		cyfry.push_back(liczba%10);
		liczba/=10;
	}
	return cyfry;
}

bool Czy_zero_jeden(int liczba)
{
	for(int i=0;i<naCyfry(liczba).size();i++)
		if(naCyfry(liczba)[i]!=0 && naCyfry(liczba)[i]!=1)
			return false;
		return true;
}

int szukajK(int n)
{
	int k=1;
	if(n%9==0&& n!=0)
	{
		cerr<<"Liczba k nie miesci się w zakresie "<<endl;
		exit(0);
	}

	while(!Czy_zero_jeden(k*n))
		k++;
	return k;
}