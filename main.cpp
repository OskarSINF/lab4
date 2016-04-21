#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

void naCyfry(int liczba);
void naSlowa(int liczba);

int main(int argc, char *argv[])
{
	
}

int naCyfry(int liczba)
{	int i;
	for(i=1;i<7;i++)
		if(liczba<=pow(10,i))
			break;	
	
	int *cyfry=NULL;
	cyfry=new int[i];
	
	for(int k=0;k<i;k++)
	{				
 		cyfry[i-1-k]=liczba%10;
 		liczba/=10;
 	}
	return cyfry;
}

void naSlowa()
{
	string jednosci[]={"zero","jeden","dwa","trzy","cztery","piec","szesc","siedem","osiem","dziewiec"}
	string wyjatkiPolanskiego[]={"jedenascie","dwanascie","trzynascie","czternascie","pietnascie","szesnascie","siedemanscie","osiemnascie","dziewietnascie"};
	string dziesiatki[]={"dziesiec","dwadziescia","trzydziesci","czterdziesci","piecdziesiat","szescdziesiat","siedemdziesiat","osiemdziesiat","dziewiecdziesiat",};
	string setki[]={"sto","dwiescie","trzysta","czterysta","piecset","szescset","siedemset","osiemset","dziewiecset",};
	string tysiace[]={"tysiac","tysiace","tysiecy"};
	
	switch(i)
	case 1:
	{
		cout<<jednosci[cyfry[0]];
	}	
	
	case 2:
	{
		if(cyfry[1]==1&&cyfry[0]!=0)
			cout<<wyjatkiPolanskiego[cyfry[0]-1];
		if(cyfry[1]==1&&cyfry[0]==0)
			cout<<dziesiatki[0];
		if(cyfry[1]!=1&&cyfry[0]==0)
			cout<<dziesiatki[cyfry[1]-1];
	}
	case 3:
	{
		cout<<setki[cyfry[2]-1];
		if(cyfry[1]&&cyfry[0]!=0)
		{
			if(cyfry[1]==1&&cyfry[0]!=0)
				cout<<wyjatkiPolanskiego[cyfry[0]-1];
			if(cyfry[1]==1&&cyfry[0]==0)
				cout<<dziesiatki[0];
			if(cyfry[1]!=1&&cyfry[0]==0)
			   	cout<<dziesiatki[cyfry[1]-1];
		}
		if()
	}	
	case 4:
	{
		if(cyfry[3]>=2&&cyfry[3]<=4)
			cout<<jednosci[cyfry[3]]<<" "<<tysiace[1]
		if(cyfry[3]>=5&&cyfry[3]<=9||cyfry[3]==1)
			cout<<jednosci[cyfry[3]]<<" "<<tysiace[2]
	}
	
	
	
	
}