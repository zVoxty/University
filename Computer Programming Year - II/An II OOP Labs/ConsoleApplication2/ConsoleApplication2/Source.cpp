#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<fstream>
#define pinf 10000 //pentru plus infinit, o valoare mare care nu exista
#define _CRT_SECURE_NO_WARNINGS
int a[20][20], n, m;

using namespace std;

void citire_cost()
{
	ifstream in("roy_in.txt");
	int i, j, x, y, c;

	printf("\n");
	in >> n;
	in >> m;
	//initializare matrice
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i == j)
				a[i][j] = 0;
			else
				a[i][j] = pinf;
	for (i = 1; i <= m; i++)
	{
		in >> x >> y >> c;
		a[x][y] = a[y][x] = c;
	}
}

void afisare_mat()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			if (a[i][j] == pinf)
				printf(" - ");
			else
				printf("%4d ", a[i][j]);
		printf("\n");
	}
}

void RoyFloyd() // roy floyd
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (a[i][j]>a[i][k] + a[k][j])
				{
					a[i][j] = a[i][k] + a[k][j];
				}
}

void descompun_drum(int i, int j) //realizeaza descompunerea portiunii de la i la j prin k
{
	int ok = 0, k = 1;

	while (k <= n && !ok)
	{
		if (i != k&&j != k)
			if (a[i][j] == a[i][k] + a[k][j])
			{
				descompun_drum(i, k);
				descompun_drum(k, j);

				ok = 1;
			} //g marcheaza daca se poate realiza descompunerea
		k++;
	}
	if (!ok)
	{
		printf(" %d ", j);
	}//cand “drumul” nu mai poate fi descompus afisez extremitatea finala

}

void scriu_drum(int nod_initial, int nod_final) // functia primeste ca parametri cele doua noduri pt care se determina optimul
{
	if (a[nod_initial][nod_final] < pinf)
	{
		printf("lantul de la %d la %d are lungimea %d", nod_initial, nod_final, a[nod_initial][nod_final]);
		printf("\n un drum optim este: %d ", nod_initial);
		descompun_drum(nod_initial, nod_final); // apeleaza functia care afiseaza efectiv lantul
	}
	else
		cout << "nu exista lant de la" << nod_initial << " la " << nod_final;

}


void main()
{
	int x, y;
	citire_cost();
	cout << "\nmatricea ponderilor \n";
	afisare_mat();
	RoyFloyd();
	cout << "\n matricea drumurilor optime \n";
	afisare_mat();
	cout << "\n Se determina drumul minim intre varfurile x si y \n";
	cout << "x=";
	cin >> x;
	cout << "y=";
	cin >> y;
	scriu_drum(x, y);
	system("PAUSE");
}