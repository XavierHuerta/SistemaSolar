#include "Matriz.h"

using namespace std;

//constructor
Matriz::Matriz() {
	loadIdentity();
}

//Metodos
void Matriz::loadIdentity() {
	/*
	* cargamos la matriz identidad en la matriz A
	*	1 0 0
	*	0 1 0
	*	0 0 1
	*/

	M_A = { {1,0,0}, {0,1,0}, {0,0,1} };
}

void Matriz::opTraslacion(vector <int> desplazamiento) {

}

void Matriz::opRotacion(float) {

}

void Matriz::opEscala(float) {

}


//constructores de matrices

void Matriz::cMT(float x, float y) {
	M_T = { {1,0,x}, 
			{0,1,y}, 
			{0,0,1} };
}

void Matriz::cME(float e) {
	M_E = { {e,0,0}, 
			{0,e,0}, 
			{0,0,1} };
}

void Matriz::cMR(float t) {
	M_R = { {(float)cos(t), (float)  -sin(t), 0},
			{(float)sin(t), (float)   cos(t), 0}, 
			{      0      ,        0        , 1}};
}


vector<vector<float>> Matriz::multiplicaMatriz(vector<vector<float>> m1, vector<vector<float>> m2) {
	vector<vector<float>> mr(3, vector<float>(3, 0.0));

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				mr[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}

	return mr; // Devolver la matriz resultante
}

