#include "Astro.h"

#include <GL/glut.h>

#include <math.h>
#include <iostream>

using namespace std;


//Astro     (desplazamiendo ,    posicion    ,    color rgb   ,  facEscala ,  alfa  , velocidad, ref M_A);
Astro::Astro(vector<float> d, vector<float> p, vector<float> c, float fEscala, float a,  float v , Matriz& mA) : skin(p)
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
	//matriz->push();//Push a ma matriz A

	//Se calcula la matriz modelado
	
	matriz->opRotacion(alfa);
	matriz->opTraslacion(desplazamiento);
	matriz->opEscala(facEscala);


	/* Multiplicamos un punto del cirulo con la matriz modelado
	* usamos las coordenadas del nuevo punto y con el centro del circulo 
	* calculamos el nuevo radio
	* usamos un setRadio para circulo y luego lo actualizamos
	*/
	
	//extraemos el punto [0] de los puntos del circlo trasladado
	Punto p = skin.getPuntos().at(0);

	//Multiplicamos el punto [0] del circulo por la amtriz modelado
	vector <float> vAux = matriz->multiplicaPunto(p.getCoords());
	p.setCoords(vAux);

	/*
	* multiplicamos el centro del circulo con la matriz A
	* para moverlo a su nueva ubicacion
	*/

	Punto pC(pos);
	//calculamos nuevas coordenadas del centro del ciruclo
	pC.setCoords(matriz->multiplicaPunto(pC.getCoords()));

	//guardamos nuevas coordenadas del centro en el circulo
	pos = pC.getCoords();//actualizazo el centro del Astro
	skin.setCentro(pC.getCoords());//actualizo el centro del circulo
	skin.uptade();//actualizo el circulo

	//calculamos el nuevo radio
	float rNew = 0;
	rNew = nuevoRadio(p);

	//actualizamos el radio en el circulo
	skin.setRadio(rNew);
	// actualizamos los puntos del circulo
	skin.uptade();

	


	//dibujamos los puntos
	skin.draw();
}



void Astro::update() {
	if (alfa < 360) {
		alfa += speed;
	}
	else
	{
		alfa = 0;
	}
}

float Astro::nuevoRadio(Punto p) {
	float rNew = sqrt(pow(p.getX() - pos.at(0), 2) + pow(p.getY() - pos.at(1), 2));
	return rNew;
}

void Astro::toString() {
	cout << endl;
	cout << "<<<<<<<<<< Datos de Astro >>>>>>>>>>" << endl;
	skin.toString();
	cout << "vector de posicion: " << endl;
	cout << "x: " << pos.at(0) << "   y: " << pos.at(1) << "   k: " << pos.at(2) << endl;
	cout << "vector de desplazamiento: " << endl;
	cout << "x: " << desplazamiento.at(0) << "   y: " << desplazamiento.at(1) << "   k: " << desplazamiento.at(2) << endl;
	cout << "vector de Color: " << endl;
	cout << "R: " << color.at(0) << "   G: " << color.at(1) << "   B: " << color.at(2) << endl;
	cout << "Factor de escala: " << facEscala << endl;
	cout << "Angulo de rotacion: " << alfa << endl;
	cout << "velocidad de moviemiento: " << speed << endl;
	cout << endl;
}