/***********************************************************
	ccurve_test.cpp -- Cã»ê¸
***********************************************************/
#include <GL/glut.h>
#include <iostream>
#include <cstdlib.>
#include "ccurve.h"

Ccurve c;

void display() {
    glClear (GL_COLOR_BUFFER_BIT);
	glColor3d(1.0, 0.0, 0.0);
	c.run(c.getOrder(), c.getDx(), c.getDy());
    glFlush ();
}

void init() {
    glClearColor (0.0, 1.0, 0.0, 1.0);
}

int main(int argc, char *argv[])
{
	int ord;
	std::cout << "à êî = " << std::endl;
	std::cin >> ord;
	
	c.Init(ord);
    glutInit (&argc, argv);
	glutInitWindowSize(400, 300);
    glutInitDisplayMode (GLUT_RGBA);
    glutCreateWindow (argv[0]);
    glutDisplayFunc (display);
	init();
    glutMainLoop ();

	return EXIT_SUCCESS;
}
