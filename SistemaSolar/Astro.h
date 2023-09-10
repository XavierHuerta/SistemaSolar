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
	//int radio;
	vector <float> desplazamiento;
	vector <float> pos; // posicion (x,y)
	vector <float> color;

	float facEscala;
	float alfa;
	float speed;
	Matriz* matriz;//referencia a la matriz a

	float nuevoRadio(Punto);

public:
	//   desplazamiendo | posicion | color rgb | facEscala | alfa, velocidad, ref M_A);
	Astro(vector <float>, vector <float>, vector <float>, float, float, float, Matriz&);

	void reinicio();

	void draw();
	void update();

	void toString();
};

