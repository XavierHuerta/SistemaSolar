#pragma once

#include "Punto.h"
#include <vector>

using namespace std;

class Circulo
{
private:
	int radio;
	vector <int> centro;
	vector <Punto> resolucion;

public:
	Circulo();
	Circulo(int, vector <int>);

	//metodos
	void calcularPuntos();
	void puntos(int, int, int, int);
	void draw();
};

