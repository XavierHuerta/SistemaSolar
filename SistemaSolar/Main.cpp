#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

//
#include "Punto.h"
#include "Circulo.h"
#include "Matriz.h"
#include "Astro.h"

//valores para el Sol
vector <float> pos = { 0.0, 0.0, 1.0 };
vector <float> des = { 50.0, 0.0, 0.0 };
vector <float> rgb = { 1.0, 0.0, 0.0 };

//valores para la tierra
vector <float> pos_T = { 0.0, 0.0, 1.0 };
vector <float> des_T = { 1.75, 0.0, 0.0 };
vector <float> rgb_T = { 0.0, 1.0, 0.0 };

//valores para la luna 1
vector <float> pos_L1 = { 0.0, 0.0, 1.0 };
vector <float> des_L1 = { 2.0, 0.0, 0.0 };
vector <float> rgb_L1 = { 0.0, 1.0, 1.0 };

//valores para la luna 2
vector <float> pos_L2 = { 0.0, 0.0, 1.0 };
vector <float> des_L2 = { 2.0, 0.0, 0.0 };
vector <float> rgb_L2 = { 1.0, 1.0, 1.0 };

Matriz m;
//Astro sol(des, pos, rgb, 1, 0.0f, 0.0f, m);
Punto p1(0,0);
Astro sol(des, pos, rgb, 20.0,90.0 * (3.14 / 180), 2.0, m);
Astro tierra(des_T, pos_T, rgb_T, 0.15, 0.0, 1.0, m);
Astro luna(des_L1, pos_L1, rgb_L1, 0.4, 0.0, 0.0, m);
Astro luna2(des_L2, pos_L2, rgb_L2, 0.4, 180.0, 0.0, m);

//Inicializamoslas matrices
void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION); //Es la matriz que se utiliza para proyectar el BufferGrafico al Display
    glLoadIdentity(); //cargara la matriz identidad y modifica la Matriz de proyeccion

    gluOrtho2D(-350, 350, -250, 250); /*Prepara al buffer grafico en sistema carteciano
                                indicando los valores de Xmax/Xmin y Ymax/Ymin y
                                se hace sobre la matriz de proyeccion*/

    glMatrixMode(GL_MODELVIEW); //MAtriz de modelado se usa para hacer modificaciones geometricas.
    glLoadIdentity();
}

void funcion() {
    glClear(GL_COLOR_BUFFER_BIT);
    //glColor3f(0.0, 0.0, 1.0);

    //c.draw();
    m.push();//guardamos A0
    sol.draw();//modifico
    m.toString();
    sol.toString();
    cout << "play" << endl;
    //m.push();//guardamos A1
    m.pop();
    m.toString();

    
    
    

    /*-----------------------------------------*/
    glColor3f(0.0, 0.0, 1.0);
    glPointSize(2);
    p1.draw();


    //se usa para liberar el buffer grafico al display
    //se usa cuando solo se use un buffer grafico
    //Solo se debe usar 1 vez al final de la funcion que dibuja todo el entorno grafico
    glFlush();
    //glutPostRedisplay();
}

static void idle(void)
{
    sol.update();
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
    //glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}
