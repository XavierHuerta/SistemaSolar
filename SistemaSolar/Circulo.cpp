#include "Circulo.h"

#include <GL/glut.h>

Circulo::Circulo(){
	radio = 1;
	centro = { 0,0,0 };
	calcularPuntos();
}


Circulo::Circulo(int r_escalado, vector <int> c) {
	radio = r_escalado;
	centro.assign(c.begin(), c.end());
	calcularPuntos();
}

//Metdos
void Circulo::calcularPuntos() {
	int x, y, p;
	x = 0;
	y = radio;
	p = 1 - radio;

	puntos(centro.at(0), centro.at(1), x, y);

	//se cicla hasta trazar un octante
	while (x < y)
	{
		x = x + 1;
		if (p < 0)
		{
			p = p + 2 * x + 3;
		}
		else
		{
			y = y - 1;
			p = p + 2 * (x - y) + 5;
		}
		puntos(centro[0], centro[1], x, y);
	}
}

//Calcula los puntos del circulo y los guarda en
//el array de puntos del circulo
void Circulo::puntos(int cx, int cy, int x, int y) {
	int _x, _y;

	for (int i = 1; i < 9; i++)
	{
		//calcula las coordenadas de un punto
		switch (i)
		{
		case 1:
			_x = cx + x;
			_y = cy + y;
			break;
		case 2:
			_x = cx - x;
			_y = cy + y;
			break;
		case 3:
			_x = cx + x;
			_y = cy - y;
			break;
		case 4:
			_x = cx - x;
			_y = cy - y;
			break;
		case 5:
			_x = cx + y;
			_y = cy + x;
			break;
		case 6:
			_x = cx - y;
			_y = cy + x;
			break;
		case 7:
			_x = cx + y;
			_y = cy - x;
			break;
		case 8:
			_x = cx - y;
			_y = cy - x;
			break;
		}

		//revisar si existe un punto con esas coordenadas
		//en el array de los puntos del circulo
		for (int i = 0; i <= resolucion.size(); i++)
		{
			if (resolucion.empty()) {
				Punto p(_x, _y);
				resolucion.push_back(p);
				break;
			}
			else
			{
				if (_x == resolucion[i].getX() && _y == resolucion[i].getY()) {
					break;
				}
				else {
					Punto p(_x, _y);
					resolucion.push_back(p);
					break;
				}
			}
		}
	}
}

void Circulo::draw() {
	glBegin(GL_POINTS);
	for (int i = 0; i < resolucion.size(); i++)
	{
		glVertex2i(resolucion[i].getX(), resolucion[i].getY());
	}
	glEnd();
}