#pragma once

#include <vector>
#include <stack>

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
	void opTraslacion();
	void opRotacion();
	void opEscala();

};

