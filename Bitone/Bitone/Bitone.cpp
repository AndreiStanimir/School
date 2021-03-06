// Bitone.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

void InterclasareBitona(int *v,int n)
{
	int st = 0, dr = n - 1;
	int *b=new int[n];
	int indB = 0;
	if (v[st] < v[dr])
	{
		b[indB] = v[st];
		indB++;
		st++;
	}
	else
	{
		b[indB] = v[dr];
		indB++;
		dr--;
	}

}

bool EsteSecventaBitona(int *v, int st, int dr)
{
	int i;
	for (i = st; i < dr; i++)
	{
		if (v[i] > v[i + 1])
			break;
	}
	for (; i < dr; i++)
	{
		if (v[i] < v[i + 1])
			return 0;
	}
	return 1;
}

int main()
{
	int v[100];
	int n;
	ifstream fin("a.txt");
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		fin >> v[i];
	}
	int nrTeste,st,dr;
	fin >> nrTeste;
	for (int i = 0; i < nrTeste; i++)
	{
		fin >> st >> dr;
		cout << EsteSecventaBitona(v, st, dr);
	}
}

