/***********************************************************
	plotter.cpp -- グラフィックス
***********************************************************/
/* プロッタのシミュレーション */
#include "plotter.h"

Plotter::Plotter() :
	xpen(0.0),
	ypen(0.0)
{
}

void Plotter::move(double x, double y)  /* ペンアップで移動 */
{
	xpen = x;
	ypen = y;
}

void Plotter::move_rel(double dx, double dy)  /* 同上 (相対座標) */
{
	xpen += dx;
	ypen += dy;
}

void Plotter::draw(double x, double y)  /* ペンダウンで移動 */
{
	glBegin (GL_LINE_LOOP);
	glVertex2d(xpen,ypen);
	glVertex2d(x,y);
    glEnd();
	xpen = x;
	ypen = y;
}

void Plotter::draw_rel(double dx, double dy)  /* 同上 (相対座標) */
{
	glBegin (GL_LINE_LOOP);
	glVertex2d(xpen,ypen);
	glVertex2d(xpen + dx, ypen + dy);
    glEnd ();
	xpen += dx;
	ypen += dy;
}
