// Sortowanie_Insert.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> 

using namespace std;

const int n = 12;   //stały rozmiar tablicy

int tab[n] = { 40,2,1,6,18,20,29,32,23,34,39,10 };  //elementy tab do sortowania

void swap(int& a, int &b) // zamiana elementów
{
	int temp = a;
	a = b;
	b = temp;
}

void show_tab(int *tab)
{
	for (int i = 0; i<n; i++)
		cout << tab[i] << "   ";
		cout << endl;
}

void Sort_Insert(int *tab)
{
	for (int i = 1; i<n; i++)
	{
		int j = i;			// 0  -> i-1 jest już posortowane
		int temp = tab[j];
		while ((j>0) && (tab[j - 1]>temp))
		{
			//tab[j] = tab[j - 1];
			swap(tab[j-1],tab[j]);
			j--;
		}
		tab[j] = temp;
		
		if (i == n - 1)
		{
			cout << "Tablica jest juz posortowana!\n";
			show_tab(tab);
		}
		else
		{
			cout << i << " iteracja sortowania" << endl;
			show_tab(tab);
		}
	}
}

int main()
{
	

	Sort_Insert(tab);

	getchar();

}
