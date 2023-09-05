#pragma once

#include <vector>

#include "Circulo.h"
#include "Astro.h"

using namespace std;

class Astro
{
protected:
	Circulo skin;
	int radio;
	int desplazamiento;
	vector <int> pos;
	vector <float> color;

	int facEscala;
	float alfa;
	vector <vector <float>>* matrizModel;//referencia a la matriz a

	void draw();
	void update();

public:
	Astro();
	//Astro(radio, posicion, factor de escala, teta, color);
	Astro(int, vector <int>, int, float, vector <float>);

	//Astro(deszplazamiento, factor de escala, teta, color);
	Astro(vector <int>, int, float, vector <float>);
};

