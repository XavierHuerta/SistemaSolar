#include "Matriz.h"

using namespace std;

//constructor
Matriz::Matriz() {
	loadIdentity();
	clearM(M_T);
	clearM(M_R);
	clearM(M_E);
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

//Realizan las operaciones entre las matrices
void Matriz::opTraslacion(vector <float> desplazamiento) {
	//construimos la matriz de traslacion
	cMT(desplazamiento.at(0), desplazamiento.at(1));

	//multiplicamos la matriz de traslacion con la matriz A
	M_A = multiplicaMatriz(M_A, M_T);
}

void Matriz::opRotacion(float t) {
	//construye la matriz de rotacion
	cMR(t);
	//multiplica la matriz de rotacion con la matriz A
	M_A = multiplicaMatriz(M_A, M_R);
}

void Matriz::opEscala(float e) {
	//construye la matriz 
	cME(e);
	M_A = multiplicaMatriz(M_A, M_E);
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

void Matriz::push() {
	PilaE.push(M_A);
}

void Matriz::pop() {
	M_A = PilaE.top();
	PilaE.pop();
}


//recibe dos matrices y retorna la matriz producto de ellas
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

void Matriz::clearM(vector <vector <float>> m) {
	m = {{1,0,0},
		 {0,1,0},
		 {0,0,1}};
}

vector <vector <float>>* Matriz::getA() {
	return &M_A;
}