#pragma once

#include "Punto.h"
#include <vector>

using namespace std;

class Circulo
{
private:
	int radio;
	vector <float> centro;
	vector <Punto> resolucion;

public:
	Circulo();
	//      radio
	Circulo(float);
	//     radio    coordenadas
	Circulo(float, vector <float>);

	//metodos
	void calcularPuntos();
	void puntos(int, int, int, int);
	void draw();
};

