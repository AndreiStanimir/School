

#include "stdafx.h"


#include <iostream>

using namespace std;

int n;

void Copy(int *v, int *tempV)
{
	for (int i = 0; i < n; i++)
	{
		tempV[i] = v[i];
	}
}
void Merge(int *v, int *tempV, int stanga, int mid, int dreapta)
{
	int i = stanga;
	int j = mid;
	for (int k = stanga; k < dreapta; k++)
	{
		if ((v[i] <= v[j] || j >= dreapta) && i < mid)
			tempV[k] = v[i++];
		else
			tempV[k] = v[j++];
	}
}
void MergeSort(int *v, int *tempV, int stanga, int dreapta)
{
	if (dreapta - stanga<2)
		return;
	int mid = (stanga + dreapta) / 2;
	MergeSort(tempV, v, stanga, mid);
	MergeSort(tempV, v, mid, dreapta);

	Merge(v, tempV, stanga, mid, dreapta);

}


int main()
{
	int v[100], tempV[100];

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	Copy(v, tempV);

	MergeSort(v, tempV, 0, n);

	return 0;
}

