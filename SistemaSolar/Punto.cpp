#include "Punto.h"


//Constructores
Punto::Punto() {

}

Punto::Punto(vector <int> cord) {
	//cord debe ser un vector de 3 elementos
	// 
	//		vector <int> cord = {x,y,0};
	//
	coords.assign(cord.begin(), cord.end());
}

//Metodos
void Punto::draw() {
	glBegin(GL_POINTS);
	glVertex2i(coords.at(0), coords.at(1));
	glEnd();
}

void Punto::update() {

}


//set -/- get

int Punto::getX() {
	return coords.at(0);
}

int Punto::getY() {
	return coords.at(1);
}

