#include "Astro.h"

#include <GL/glut.h>

#include <math.h>
#include <iostream>

using namespace std;


//Astro     (desplazamiendo ,    posicion    ,    color rgb   ,  facEscala ,  alfa  , velocidad, ref M_A);
Astro::Astro(vector<float> d, vector<float> p, vector<float> c, int fEscala, float a,  float v , Matriz& mA) : skin()
{
	desplazamiento = d;
	pos = p;
	color = c;
	facEscala = fEscala;
	alfa = a;
	speed = v;
	matriz = &mA;
	//skin(facEscala, p);

	radio = 1 * facEscala;

	//skin.
	
}



void Astro::draw() {
	glColor3f(color.at(0), color.at(1), color.at(2));
	matriz->push();//Push a ma matriz A

	//Se calcula la matriz modelado
	matriz->opTraslacion(desplazamiento);
	matriz->opRotacion(alfa);
	matriz->opEscala(facEscala);

	matriz->toString();

	/*
	* multiplicamos el centro del circulo con la matriz A para moverlo a su nueva ubicacion
	* luego hacemos el calculo de los puntos
	*/

	Punto pC(skin.getCentro());
	pC.toString();
	pC.setCoords(matriz->multiplicaPunto(pC.getCoords()));
	pC.toString();

	skin.toString();
	skin.setCentro(pC.getCoords());
	skin.uptade();
	skin.toString();

	/* Multiplicamos un punto del cirulo con la matriz modelado
	* usamos las coordenadas del nuevo punto y con el centro del circulo 
	* calculamos el nuevo radio
	* usamos un setRadio para circulo y luego lo actualizamos
	*/

	//skin.printPoints();
	//cout << "radio viejo: " << skin.getRadio() << endl;

	////este es el punto n1 del circulo unitario
	//Punto p(skin.getPuntos().at(0).getX(), skin.getPuntos().at(1).getY());
	//cout << "punto [0]: " << p.getX() << ", " << p.getY() << endl;
	//p.setCoords(matriz->multiplicaPunto(p.getCoords())); //multiplicamos el punto con la matriz A
	//cout << "punto [0]: " << p.getX() << ", " << p.getY() << endl;

	////calculamos el nuevo radio
	//float rNew = sqrtf( pow(p.getX() - pos.at(0),2) + pow(p.getY() - pos.at(1), 2));

	//cout << "Nuevo radio: " << rNew << endl;


	//actualizamos el radio en el circulo
	/*skin.setRadio(rNew);

	skin.uptade();
	skin.printPoints();*/

	skin.draw();



	//skin.draw();
}

void Astro::update() {

}