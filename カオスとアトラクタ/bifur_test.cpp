/***********************************************************
	bifur_test.cpp -- カオスとアトラクタ　テスト用
***********************************************************/
#include "bifur.h"
#include <GL/glut.h>
#include <iostream>
#include <cstdlib>

Bifur b;

void display() {
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3d(1.0, 0.0, 0.0);
	b.Draw();
	glFlush ();
}

void init() {
    glClearColor (0.0, 1.0, 0.0, 1.0);
	b.gr_window(b.kmin, b.pmin, b.kmax, b.pmax, false, BLACK);
}


int main(int argc, char *argv[])
{
	double k_min, k_max, p_min, p_max;
	
	std::cout << "kmin = ";
	std::cin >> k_min;
	std::cout << "kmax = ";
	std::cin >> k_max;
	std::cout << "pmin = ";
	std::cin >> p_min;
	std::cout << "pmax = ";
	std::cin >> p_max;
	
	b.Init(k_min, k_max, p_min, p_max);

    glutInit (&argc, argv);
	glutInitWindowSize(640, 400);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
	
	glColor3f(0.7, 0.7, 0.3);
	glPointSize(5.0);
	glBegin(GL_POINTS);
	glVertex2f(0.0 , 0.0);
	glEnd();
	init();
    glutMainLoop();
	return EXIT_SUCCESS;
}
