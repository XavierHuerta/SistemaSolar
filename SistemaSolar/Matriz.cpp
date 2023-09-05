#include "Matriz.h"

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

void Matriz::opTraslacion() {

}

void Matriz::opRotacion() {

}


