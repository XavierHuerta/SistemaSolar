#pragma once

#include <vector>

#include "Circulo.h"

using namespace std;

class Astro
{
protected:
	Circulo skin(int, vector <int>);
	int radio;
	vector <int> pos;
	vector <float> color;

	int facEscala;
	float alfa;
	vector <vector <float>>* matrizModel;//referencia a la matriz a

	void draw();
	void update();

public:
	//Astro(radio, posicion, factor de escala, teta, color);
	Astro();
	Astro(int, vector <int>, int, float, vector <float>);
};

