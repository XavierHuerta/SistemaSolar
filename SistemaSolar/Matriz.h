#pragma once

#include <vector>
#include <stack>
#include <math.h>

#include "Punto.h"

using namespace std;

class Matriz
{
private:
	vector <vector <float>> M_A;//matriz A
	vector <vector <float>> M_T;//matriz de Traslacion
	vector <vector <float>> M_R;//matriz de Rotacion
	vector <vector <float>> M_E;//matriz de Escala
	stack <vector < vector <float> >> PilaE; //pila de estados

	//metodo
	void loadIdentity();
	

public:
	Matriz();
	void opTraslacion(vector <float>);
	void opRotacion(float);
	void opEscala(float);

	//constructores de matrices
	//         x      y
	void cMT(float, float);
	//        teta
	void cMR(float);
	//   factor de Escala
	void cME(float);

	void push();
	void pop();

	vector <float> multiplicaPunto(vector <float>);

	//devuelve el producto de 2 matrices 3x3
	vector <vector <float>> multiplicaMatriz(vector <vector <float>>, vector <vector <float>>);
	void clearM(vector <vector <float>>);// limpia una matriz
	vector <vector <float>>* getA();//metodo get de la matriz A
	vector <vector <float>>* getMT();//metodo get de la matriz A
	vector <vector <float>>* getMR();//metodo get de la matriz A
	vector <vector <float>>* getME();//metodo get de la matriz A

	void printMatriz(vector <vector <float>>*);

	void toString();
};

