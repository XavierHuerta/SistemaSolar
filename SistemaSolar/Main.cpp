#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

#include <vector>
#include <iostream>

#include <math.h>
using namespace std;

#include "Punto.h"
#include "Circulo.h"
#include "Matriz.h"
#include "Astro.h"

//valores para el Sol
vector <float> pos = { 0.0, 0.0, 1.0 };
vector <float> des = { 0.0, 0.0, 0.0 };
vector <float> rgb = { 1.0, 0.0, 0.0 };

//valores para p1
vector <float> pos_p1 = { 0.0, 0.0, 1.0 };
vector <float> des_p1 = { 3.0, 0.0, 0.0 };
vector <float> rgb_p1 = { 0.0, 1.0, 0.0 };

//valores para la luna 1
vector <float> pos_L1 = { 0.0, 0.0, 1.0 };
vector <float> des_L1 = { 2.0, 0.0, 0.0 };
vector <float> rgb_L1 = { 0.0, 1.0, 1.0 };

//valores para la luna 2
vector <float> pos_L2 = { 0.0, 0.0, 1.0 };
vector <float> des_L2 = { 3.0, 0.0, 0.0 };
vector <float> rgb_L2 = { 1.0, 1.0, 1.0 };

//valores para p2
vector <float> pos_p2 = { 0.0, 0.0, 1.0 };
vector <float> des_p2 = { 4.0, 0.0, 0.0 };
vector <float> rgb_p2 = { 1.0, 1.0, 0.0 };

//valores para la luna 1
vector <float> pos_L3 = { 0.0, 0.0, 1.0 };
vector <float> des_L3 = { 2.0, 0.0, 0.0 };
vector <float> rgb_L3 = { 0.0, 1.0, 1.0 };

//valores para p3
vector <float> pos_p3 = { 0.0, 0.0, 1.0 };
vector <float> des_p3 = { 1.5, 0.0, 0.0 };
vector <float> rgb_p3 = { 1.0, 1.0, 1.0 };

Matriz m;

//Astro sol(des, pos, rgb, 1, 0.0f, 0.0f, m);
Punto p(0,0);
Astro sol(des, pos, rgb, 50.0,0.0 * ( 3.1415/ 180), 0.0, m);

Astro p1(des_p1, pos_p1, rgb_p1, 0.25, 0.0, 5.0, m);
Astro luna(des_L1, pos_L1, rgb_L1, 0.4, 0.0, 5.0, m);
Astro luna2(des_L2, pos_L2, rgb_L2, 0.4, 180.0 * (3.14 / 180), 10.0, m);

Astro p2(des_p2, pos_p2, rgb_p2, 0.25, 45.0 * (3.14 / 180), 8.0, m);
Astro luna3(des_L3, pos_L3, rgb_L3, 0.4, 0.0, 5.0, m);

Astro p3(des_p3, pos_p3, rgb_p3, 0.25, 90.0 * (3.14 / 180), 2.0, m);


//Inicializamoslas matrices
void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION); //Es la matriz que se utiliza para proyectar el BufferGrafico al Display
    glLoadIdentity(); //cargara la matriz identidad y modifica la Matriz de proyeccion

    /*Prepara al buffer grafico en sistema cartecianoindicando 
    * los valores de Xmax/Xmin y Ymax/Ymin y se hace sobre 
    * la matriz de proyeccion */
    gluOrtho2D(-350, 350, -250, 250); 

    glMatrixMode(GL_MODELVIEW); //MAtriz de modelado se usa para hacer modificaciones geometricas.
    glLoadIdentity();
}

void funcion() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    m.push();//matriz A_0
    sol.draw();//matriz A_1
    m.push();
    p3.draw();//matriz A_2
    m.top();
    p1.draw();//matriz A_3
    m.push();     
    luna.draw();// matriz A_4
    m.top();
    luna2.draw();//matriz A_5
    m.pop();
    m.pop();
    p2.draw();//matriz A_6
    m.push();
    luna3.draw();
    m.pop();
    m.pop();

    
    luna3.update();
    p2.update();
    luna2.update();
    luna.update();
    p1.update();
    p3.update();
    sol.update();
    

    /*-----------------------------------------*/
    glColor3f(0.0, 0.0, 1.0);
    p.draw();


    //se usa para liberar el buffer grafico al display
    //se usa cuando solo se use un buffer grafico
    //Solo se debe usar 1 vez al final de la funcion que dibuja todo el entorno grafico
    glFlush();
}

static void idle(void)
{
    Sleep(70);
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); //inizializar glut
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(700, 500);
    glutCreateWindow("Sistema Solar");
    init();
    glutDisplayFunc(funcion);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}
