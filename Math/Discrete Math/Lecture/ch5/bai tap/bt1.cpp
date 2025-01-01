#include <iostream>
#include <stdlib.h>
#define MAX 100
#define TRUE 1
#define FALSE 0
int X[MAX], OK=TRUE, dem=0;
using namespace std;
void Init (void)
{
	cout << "\n Cac chuoi nhi phan do dai 5 khong chua 2 so 0 lien tiep: ";
	//std::cin >> n;
	for (int i=1;i<=5;i++)
		X[i] = 0;	
}
void Result(void)
{
	cout << "\n Ket qua buoc"" "<< ++dem << ":"" ";
	for (int i=1;i<=5;i++)
		cout << X[i] << " ";
}
void Next_Bit_String (void)
{
	int i=5;
	while (i>0 && X[i]!=0 )
	{
		X[i] = 0;
		i--;
	}
		if (i>0) X[i] = 1;
		else OK = FALSE;
}
int main ()
{
	int i,j,count=0;
	Init (); 
	while (OK)
	{
		for (i=1;i<5;i++)
			if (X[i] + X[i+1] == 0)
				count++;
		if (count > 0)
			count = 0;	
		else 
			Result ();		
		Next_Bit_String();
	}
	system ("PAUSE");
	return 0;
}
