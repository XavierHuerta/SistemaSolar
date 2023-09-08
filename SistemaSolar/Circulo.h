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
	Circulo(vector <float>);
	//      radio
	Circulo(float);
	//     radio    coordenadas
	Circulo(float, vector <float>);

	//metodos
	void calcularPuntos();
	void puntos(int, int, int, int);
	void draw();
	void uptade();

	vector <Punto> getPuntos();
	void setPuntos(vector <Punto>);
	void setRadio(float);
	float getRadio();
	void setCentro(vector <float>);
	vector <float> getCentro();

	void printPoints();
	void toString();
};

