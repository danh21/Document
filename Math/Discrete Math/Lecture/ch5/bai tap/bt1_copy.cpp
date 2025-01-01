#include <iostream>			Liet kê tat ca các chuoi nhi phân do dài n không chua k so 0 liên tiep.
#include <stdlib.h>
#define MAX 100
#define TRUE 1
#define FALSE 0
int n, k, X[MAX], OK=TRUE, dem=0;
using namespace std;
void Init (void)
{
	cout << "\n Nhap n = ";
	cin >> n;
	cout << "\n Nhap k = ";
	cin >> k;
	for (int i=1;i<=n;i++)
		X[i] = 0;	
}
void Result(void)
{
	cout << "\n Ket qua buoc"" "<< ++dem << ":"" ";
	for (int i=1;i<=n;i++)
		cout << X[i] << " ";
}
void Next_Bit_String (void)
{
	int i=n;
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
	int i,j,count=0,temp=0;
	Init (); //nhap n
	while (OK)
	{
		for (i=1;i<n-(k-2);i++)
		{
			for (j=0;j<k;j++)
				temp = temp + X[i+j];
			if (temp == 0)
				count++;
			else 
				temp = 0;
		}			
		if (count > 0)
			count = 0;	
		else 
			Result ();		
		Next_Bit_String();
	}
	system ("PAUSE");
	return 0;
}
