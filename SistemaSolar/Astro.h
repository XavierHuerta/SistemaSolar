#pragma once

#include <vector>

#include "Circulo.h"
#include "Astro.h"
#include "Matriz.h"

using namespace std;

class Astro
{
private:
	Circulo skin;
	int radio;
	vector <float> desplazamiento;
	vector <float> pos;
	vector <float> color;

	int facEscala;
	float alfa;
	float speed;
	vector <vector <float>>* matrizModel;//referencia a la matriz a

public:
	//   desplazamiendo | posicion | color rgb | facEscala | alfa, velocidad, ref M_A);
	Astro(vector <float>, vector <float>, vector <float>, int, float, float, Matriz&);

	void draw();
	void update();
};

