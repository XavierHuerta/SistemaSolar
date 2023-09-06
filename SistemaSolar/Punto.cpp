#include "Punto.h"


//Constructores
Punto::Punto() {

}

Punto::Punto(float x, float y) {
	coords = { x, y , 0 };
}

Punto::Punto(vector <float> cord) {
	//cord debe ser un vector de 3 elementos
	// 
	//		vector <int> cord = {x,y,0};
	//
	coords.assign(cord.begin(), cord.end());
}

//Metodos
void Punto::draw() {
	glBegin(GL_POINTS);
	glVertex2f(coords.at(0), coords.at(1));
	glEnd();
}

void Punto::update() {

}


//set -/- get

float Punto::getX() {
	return coords.at(0);
}

float Punto::getY() {
	return coords.at(1);
}

