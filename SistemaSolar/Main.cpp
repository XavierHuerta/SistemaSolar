#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>

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
vector <float> des_T = { 0.5, 0.0, 0.0 };
vector <float> rgb_T = { 0.0, 0.0, 1.0 };

Matriz m;
//Astro sol(des, pos, rgb, 1, 0.0f, 0.0f, m);
Punto p1(0,0);
Astro sol(des, pos, rgb, 10, 45.0, 0.0, m);
Astro tierra(des_T, pos_T, rgb_T, 0.5, 45.0, 0.0, m);

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
    sol.draw();

    //tierra.draw();

    glColor3f(0.0, 0.0, 1.0);
    glPointSize(2);
    p1.draw();


    //se usa para liberar el buffer grafico al display
    //se usa cuando solo se use un buffer grafico
    //Solo se debe usar 1 vez al final de la funcion que dibuja todo el entorno grafico
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); //inizializar glut
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(700, 500);
    glutCreateWindow("Sistema Solar");
    init();
    glutDisplayFunc(funcion);
    glutMainLoop();
    return 0;
}
