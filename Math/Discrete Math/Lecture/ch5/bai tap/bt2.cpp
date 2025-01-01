#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#define MAX 100
#define TRUE 1
#define FALSE 0
using namespace std;
int n, X[MAX], k, count=0, Stop;
void Init(void)
{
	cout << "\n Nhap n = ";
	cin >> n;
	k = 1; count = 0; X[k] = n;
}

void Result(void)
{
	int i;
	cout << "\n Ket qua " << ++count << ": ";
	for (int i=1; i<=k; i++)
		if (i==k)
			cout << X[i] << " ";
		else
			cout << X[i] << "+";
}

void Next_Division(void)
{
	int i=k, j, R, S, D;
	while (i>0 && X[i] == 1) //X[1] = 1 thì end
		i--;
	if (i>0)
	{
		X[i] = X[i] - 1; //X[1] = 2 1
		D = k - i + 1;	//1 2
		R = D / X[i];	//0 2
		S = D % X[i];	//1 0
		k = i;			//1 
		if (R>0)
		{
			for (j=i+1; j<=i+R; j++)
				X[j] = X[i];
			k = k + R;	//chap
		}
		if (S>0)
		{
			k = k + 1;	//chap
			X[k] = S;	//X[2] = 1
		}
	}
	else Stop = TRUE;
}

int main()
{
	Init();
	Stop = FALSE;
	while (!Stop)
	{
		Result();
		Next_Division();
	}
	getch();
}
