#pragma once

#include <vector>
#include <stack>
#include <math.h>

using namespace std;

class Matriz
{
private:
	vector <vector <float>> M_A;//matriz A
	vector <vector <float>> M_T;//matriz de Traslacion
	vector <vector <float>> M_R;//matriz de Rotacion
	vector <vector <float>> M_E;//matriz de Escala
	stack < vector < vector <float> >> PilaE; //pila de estados

	//metodo
	void multiplicaPuntos();

public:
	Matriz();
	void loadIdentity();
	void opTraslacion(vector <int>);
	void opRotacion(float);
	void opEscala(float);

	//constructores de matrices
	void cMT(float, float);
	void cMR(float);
	void cME(float);
};

