#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <math.h>
class Stellar_Body
{
public:
	static Stellar_Body** lista_ob; //tablica planet nie zafiksowanych
	static int ilosc_ob;			//liczba tych planet nie zafiksowanych
	Stellar_Body(double,double,double,double,double); //konstruktor
	void Calculate_q1(double);							//liczenie pierwszego kroku
	void Calculate_Step(double);						//liczenie dowolnego kroku
	void Calculate_Step(double, double);
	void Write_Data(int);									//wypisanie pozycji
	void Calc_and_Write_E_ANGM(std::vector<double>);	//wypisanie czasu , energi i momentu p�du ca�ego uk�adu
	double GET_SPEED();
	double Rfrompoint(double, double);
	void Stay();
	~Stellar_Body();

private:
	//int id; //numer planety numerowa� od 1 do n
	double m; //masa planety
	std::vector<double> qx, qy; //wektory pozycji
	std::vector<double> vx,vy; //wektory pr�dko�ci
	std::fstream plik; //plik do kt�rego wypisuje
};

///program napisany przez Aleksander Cz�stkiewicz

