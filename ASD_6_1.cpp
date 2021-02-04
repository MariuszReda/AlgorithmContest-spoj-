/*
##Składowe spójne grafu
Dany jest nieskierowany graf prosty, zawierający nie więcej niż 100 wierzchołków, zdefiniowany przez listę jego krawędzi: krawędź łącząca wierzchołki i-ty oraz j-ty będzie opisana rozdzieloną spacjami parą liczb i oraz j. Z kolei, o liczności zbioru wierzchołków grafu można wnioskować na podstawie największej z liczb i lub j we wszystkich parach definiujących krawędzie.

Należy napisać program, który zidentyfikuje składowe spójne tego grafu.

Wejście
Na wejściu programu, w kolejności jak niżej powinny się znaleźć następujące elementy:

Całkowita dodatnia liczba n określająca liczbę zestawów danych;
W każdym z n zestawów znajdują się:
Liczba całkowita dodatnia m określająca liczbę krawędzi grafu;
m par liczb całkowitych i oraz j definiujących kolejne krawędzieie grafu.

Wyjście
Wyniki działania programu uzyskane dla kolejnych n zestawów danych zostaną na wyjściu programu oddzielone pustą linią.

Dla danego zestawu danych, jego składowe spójne zostaną podane w kolejnych liniach: 
najpierw pojawi się numer kolejnej składowej spójnej, a po dwukropku pojawią się odzielone spacjami kolejne wierzchołki grafu należące do tej składowej.
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX_WIERZCHOLKI = 100;

class Para
{
public:
	int A;
	int B;
	void pobierz(int a, int b)
	{
		this->A = a;
		this->B = b;
	}
};


class Graf
{
	int Liczba_wierzcholkow;
	vector<int>* krawedzie;
	bool odwiedzone_wierzcholki[MAX_WIERZCHOLKI];

	void DFS(int v, vector<int>& polaczone_wierzcholki)
	{
		odwiedzone_wierzcholki[v] = true; //
		polaczone_wierzcholki.push_back(v);

		vector<int>::iterator i;
		for (i = krawedzie[v].begin(); i != krawedzie[v].end(); ++i)
		{
			if (odwiedzone_wierzcholki[*i] == false)
			{
				DFS(*i, polaczone_wierzcholki);
			}
		}
	}
public:

	Graf(int Liczba_wierzcholkow)
	{
		this->Liczba_wierzcholkow = Liczba_wierzcholkow;
		krawedzie = new vector<int>[Liczba_wierzcholkow];
	}

	void Dodaj_wierzcholek(int v, int w)
	{
		krawedzie[v].push_back(w);
		krawedzie[w].push_back(v);
	}
	void ZnajdzPolaczenia()
	{
		for (int v = 0; v < Liczba_wierzcholkow; v++)
			odwiedzone_wierzcholki[v] = false;
		vector<int> polaczone_wierzcholki;
		int counter = 1;
		for (int v = 1; v < Liczba_wierzcholkow; v++)
		{

			if (odwiedzone_wierzcholki[v] == false)
			{
				cout << counter << ": ";
				counter++;

				DFS(v, polaczone_wierzcholki); // odwiedzone_wierzcholki,
				sort(polaczone_wierzcholki.begin(), polaczone_wierzcholki.end());
				for (int j = 0; j < polaczone_wierzcholki.size(); j++)
				{
					cout << polaczone_wierzcholki[j] << " ";
				}
				cout << "\n";
				polaczone_wierzcholki.clear();
			}
		}
	}
};

int main()
{

	int tests;
	cin >> tests;
	for (int i = 0; i < tests; i++)
	{
		vector<Para> pary;
		int najwiekszy_index_grafu = 0;
		int edgesCount;
		cin >> edgesCount;
		for (int j = 1; j <= edgesCount; j++)
		{
			Para p;
			int a, b;
			cin >> a >> b;
			p.pobierz(a, b);
			pary.push_back(p);
			if (a > najwiekszy_index_grafu)najwiekszy_index_grafu = a;
			if (b > najwiekszy_index_grafu)najwiekszy_index_grafu = b;
		}
		Graf graf(najwiekszy_index_grafu + 1);
		for (int j = 0; j < pary.size(); j++)
		{
			graf.Dodaj_wierzcholek(pary[j].A, pary[j].B);
		}
		graf.ZnajdzPolaczenia();
	}
	return 0;
}
