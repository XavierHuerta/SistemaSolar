#pragma once

#include <GL/glut.h>
#include <vector>

using namespace std;

class Punto
{
private:
	vector <int> coords;

public:
	Punto();
	Punto(vector <int>);

	//metodos
	void draw();
	void update();

	//set -/- get
	int getX();
	int getY();
};

