#include "Astro.h"

#include <GL/glut.h>


//Astro     (desplazamiendo ,    posicion    ,    color rgb   ,  facEscala ,  alfa  , velocidad, ref M_A);
Astro::Astro(vector<float> d, vector<float> p, vector<float> c, int fEscala, float a,  float v , Matriz& mA) : skin(fEscala)
{
	desplazamiento = d;
	pos = p;
	color = c;
	facEscala = fEscala;
	alfa = a;
	speed = v;
	matrizModel = &mA;
	//skin(facEscala, p);

	radio = 1 * facEscala;

	//skin.
	
}



void Astro::draw() {
	glColor3f(color.at(0), color.at(1), color.at(2));
	matrizModel->push();//Push a ma matriz A
	
	//construimos las matrices
	matrizModel->cMT(pos.at(0), pos.at(1)); // matriz de traslacion
	matrizModel->cMR(alfa);
	matrizModel->cME(facEscala);

	//Se calcula la matriz modelado
	matrizModel->multiplicaMatriz();

	skin.draw();
}

void Astro::update() {

}