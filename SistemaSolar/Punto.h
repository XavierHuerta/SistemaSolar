#pragma once

#include <GL/glut.h>
#include <vector>

using namespace std;

class Punto
{
private:
	vector <float> coords;

public:
	Punto();
	Punto(float , float);
	Punto(vector <float>);

	//metodos
	void draw();
	void update();

	//set -/- get
	float getX();
	float getY();
	float getK();
	vector <float> getCoords();
	void setCoords(vector <float>);

	void toString();
};

