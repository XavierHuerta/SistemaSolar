#include "Astro.h"


//Astro     (desplazamiendo ,    posicion    ,    color rgb   ,  facEscala ,  alfa  , velocidad, ref M_A);
Astro::Astro(vector<float> d, vector<float> p, vector<float> c, int fEscala, float a,  float v , Matriz& mA)
{
	desplazamiento = d;
	pos = p;
	color = c;
	facEscala = fEscala;
	alfa = a;
	speed = v;
	matrizModel = mA.getA();
	skin;

	radio = 1 * facEscala;
	
}



void Astro::draw() {
	skin.draw();
}

void Astro::update() {

}