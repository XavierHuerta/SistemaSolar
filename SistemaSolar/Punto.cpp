#include "Punto.h"

#include <iostream>

using namespace std;

//Constructores
Punto::Punto() {

}

Punto::Punto(float x, float y) {
	coords = { x, y , 1 };
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

float Punto::getK() {
	return coords.at(2);
}


vector <float> Punto::getCoords() {
	return coords;
}

void Punto::setCoords(vector <float> v) {
	coords = v;
}

void Punto::toString() {
	cout << endl;
	cout << "### PUNTO ###" << endl;
	cout << "Coordenadas: " << endl;
	cout << "x: " << coords.at(0) << " y: " << coords.at(1) << " k: " << coords.at(2);
	cout << endl;
}