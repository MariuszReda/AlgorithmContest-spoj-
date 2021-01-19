
/*
You are probably familiar with the story of flatfish, flat creatures living in two-dimensional space. Flatlanders can only move along the plane. 
In their world, any change in position can be described by a vector with two components.

Unlike flatfish, people live in three-dimensional space. Therefore, they can move in any direction horizontally, and thanks to the achievements of technology also vertically. 
In this case, the change of position is described by a vector with three components.

Imagine that somewhere in the universe you can meet creatures whose space has n dimensions. For the purposes of our story, we will call these creatures N-oids. 
The N-oid world is egocentric, discrete and orthogonal:
    -Egocentric, because each of them has his own and for him the only Cartesian frame of reference, with a center in his own house.
    -Discrete, because only integers are known in this world.
    -Orthogonal, as N-oids move in straight lines in sections. Additionally, two adjacent segments of their journey are always mutually perpendicular.

Before N-oid leaves the house, in his notebook he has the next segments of his journey in the form of a sequence of vectors with n integer components. Wandering, 
it first goes towards the first vector, 
and then goes towards the next vectors.

Until now, there have never been errors in the description of the N-oid journey: 
the route consisted of a series of non-zero vectors which were always perpendicular to the previous vector. Unfortunately, the matter has become a bit more complicated lately. 
Errors have started to appear in the description of the route for unknown reasons. And this is a vector not perpendicular to its predecessor, but a vector with zero components.

Write a program to help N-oid in his journey.

For each data set in the description of the N-oida route, the program should eliminate vectors that are null or not perpendicular to the last valid vector. Finally, 
the coordinates of the point that the N-oid should reach by hiking as specified should be listed.

Before starting to write the program, make the following assumptions:
    -The N-oid took off from the center of the Cartesian frame of reference
    -The first vector in the route is correctly defined

INPUT
The first line of input contains exactly one integer d ∈ [1; 4] denoting the number of data sets.

Each set begins with n ∈ [2; 10] which is the size of the space, then m zestawie [2; 500] appears in the data set indicating the number of vectors in the route description. 
Then in the m lines are the coordinates of the vectors.

OUTPUT
On d exit lines, a vector should be given for each data set that specifies the position of the N-oid at the end of the hike.
*/



#include <iostream>

using namespace std;

int *wczytaj_wektor(int wymiar) 
{
	int *wek = new int[wymiar];
	bool zerowy = true;
	
	for (int i = 0; i < wymiar; i++) 
  {
		cin >> wek[i];
		
		if (wek[i] != 0) {
			zerowy = false;
		}
	}
	
	if (zerowy) 
  {
		delete[] wek;
		return NULL;
	} 
  else 
  {
		return wek;
	}
}

void jedno_powtorzenie(int wymiar, int ilosc) {
	int *pom = new int[wymiar];
	int *wynik = wczytaj_wektor(wymiar);
	ilosc--;
	
	for (int i = 0; i < wymiar; i++) 
  {
		pom[i] = wynik[i];
	}
	
	for (int i = 0; i < ilosc; i++) 
  {
		int *pom2 = wczytaj_wektor(wymiar);
		
		if (pom2 == NULL) continue;
		
		int sprawdzacz = 0;
		for (int j = 0; j < wymiar; j++) 
    {
			sprawdzacz += pom[j] * pom2[j];
		}
		
		if (sprawdzacz != 0) 
    {
			delete[] pom2;
			continue;
		}
		
		for (int j = 0; j < wymiar; j++) 
    {
			wynik[j] += pom2[j];
			pom[j] = pom2[j];
		}
		
		delete[] pom2;
	}
	
	for (int i = 0; i < wymiar; i++) 
  {
		cout << wynik[i];
		
		if (i != wymiar - 1) cout << " ";
		else cout << "\n";
	}
	
	delete[] pom;
	delete[] wynik;
}

int main() 
{
    int powtorzenia;
    int wymiar, ilosc;
    
    cin >> powtorzenia;
    for (int i = 0; i < powtorzenia; i++) 
    {
    	cin >> wymiar >> ilosc;
    	jedno_powtorzenie(wymiar, ilosc);
	}
    
    return 0;
}
