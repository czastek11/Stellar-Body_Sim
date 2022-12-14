#include <iostream>
#include "Stellar_Body.h"


using namespace std;

int main()
{
	/*
	fstream plik1;
	vector<double> R,L, GM, ef;
	double l = 5 * 100 * 10;
	for (double r = 0.1; r < 301; r += 1)
	{
		R.push_back(r);
		L.push_back(l*l / (2 * 5 * r * r));
		GM.push_back(-1 * 10000 * 5 / r);
		ef.push_back(L.back() + GM.back());
	}

	plik1.open("wykres.data", ios::out);
	for (int i = 0; i < R.size(); i++)
	{
		plik1 << R.at(i) << " " << L.at(i) << " " << GM.at(i) << " "<<ef.at(i) << endl;
	}
	plik1.close();
	R.clear(); L.clear(); GM.clear(); ef.clear();
	*/
	vector<double> time; //wektor z przedziałami czasowymi
	int proc = 0;
	int N = 20000;  // ilość próbek
	double h = 3200,hp1,hp2=0.1; //przedział czasu
	Stellar_Body* Planety[2]; //tablica obiektów nie zafiksowanych

	Planety[0] = new Stellar_Body( 5.97219e24, 1.5e11, 0, 0, 29780);  //deklaracja obiektu (indeks (nie zaczynać od 0 !) , masa ,
																	//  x0 -pozycja początkowa , y0 -pozycja początkowa , vx0 - prędkośc początkowa , vy0  -prędkośc początkowa)
	Planety[1]=new Stellar_Body(4.867e24, 0, 1.0821e11, 0,0 ); // aby dodac kolejne obiekty trzeba je zinicjalizowac w tablicy

	Planety[0]->lista_ob = Planety; //ważny el. w klasie ta tablice jest jako statyczny ** wskaznik wiec zeby metody miały dostep trzeba przypisać
	Planety[0]->Calculate_q1(h); //przed petla trzeba dla wszytskich policzyc 1 krok bo mamy algorytm 3 punktowy
	Planety[1]->Stay();
	time.push_back(0);
	for (int i = 0; i < N; i++)
	{
		if (i % (N / 100) == 0)
		{
			//cout << proc << "%" << " ";
			//if (proc % 10 == 0) cout << endl;
			proc++;
		}
		/*
		hp1 = Planety[0]->GET_SPEED();
		h = 0.1/ hp1/hp1;
		Planety[0]->Calculate_Step(hp2,h); //dla kazdego obiektu liczymy jeden krok
		hp2 = h;
		//Planety[1]->Calculate_Step(h); //mozna zmieniac h jak 1/v
		*/
		Planety[0]->Calculate_Step(h);
		Planety[1]->Stay();
		time.push_back(time.at(time.size()-1)+h);
		if (Planety[0]->Rfrompoint(1.5e11, 0) < 1e8) cout << time.back() << endl;
		
	}
	Planety[0]->Write_Data(1); //wypisanie danych
	Planety[1]->Write_Data(2);

	Planety[0]->Calc_and_Write_E_ANGM(time); //wypisanie energi i momentu pędu dla całego układu od czasu
											//(wywołac tą metode tylko raz bo ona liczy dla całego układu , więc potrzeba poprostu jednego wywołania żeby dostać się do tablicy planet)
}

///program napisany przez Aleksander Cząstkiewicz

