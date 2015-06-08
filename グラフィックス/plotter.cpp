/***********************************************************
	plotter.cpp -- �O���t�B�b�N�X
***********************************************************/
/* �v���b�^�̃V�~�����[�V���� */
#include "plotter.h"

Plotter::Plotter() :
	xpen(0.0),
	ypen(0.0)
{
}

void Plotter::move(double x, double y)  /* �y���A�b�v�ňړ� */
{
	xpen = x;
	ypen = y;
}

void Plotter::move_rel(double dx, double dy)  /* ���� (���΍��W) */
{
	xpen += dx;
	ypen += dy;
}

void Plotter::draw(double x, double y)  /* �y���_�E���ňړ� */
{
	glBegin (GL_LINE_LOOP);
	glVertex2d(xpen,ypen);
	glVertex2d(x,y);
    glEnd();
	xpen = x;
	ypen = y;
}

void Plotter::draw_rel(double dx, double dy)  /* ���� (���΍��W) */
{
	glBegin (GL_LINE_LOOP);
	glVertex2d(xpen,ypen);
	glVertex2d(xpen + dx, ypen + dy);
    glEnd ();
	xpen += dx;
	ypen += dy;
}
