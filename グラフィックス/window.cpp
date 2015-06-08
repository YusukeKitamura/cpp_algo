/***********************************************************
	window.cpp -- �O���t�B�b�N�X
***********************************************************/
/* ���W�ϊ� */
#include "window.h"
#include <GL/glut.h>
#include <cmath>

Window::Window() :
	gr_xfac(1),
	gr_yfac(1),
	gr_xconst(0),
	gr_yconst(0)
{
}

int Window::gr_xscr(double x) {
	return (int)(gr_xfac * x + gr_xconst);
}

int Window::gr_yscr(double y) {
	return (int)(gr_yfac * y + gr_yconst);
}

/* gr_window() �Œ�߂����W�œ_ (x, y) ��
	   �F color (= 0..maxcolor) ������ */
void Window::gr_wdot(double x, double y, int color)
{	
	glColor3f((color/2)%2, color/2, color%2);
	glPointSize(1.0);
	glBegin(GL_POINTS);
	//glVertex2f((unsigned int)(gr_xscr(x)) , (unsigned int)(gr_yscr(y)));
	glVertex2f(x , y);
	glEnd();
}

void Window::gr_wline(double x1, double y1,
              double x2, double y2, int color)
	/* gr_window() �Œ�߂����W�œ_ (x1, y1), (x2, y2)
	   �����Ԑ�����F color (= 0..maxcolor) �ŕ`�� */
{
	glColor3f((color/2)%2, color/2, color%2);
	glBegin(GL_LINE_LOOP);
	glVertex2d(gr_xscr(x1), gr_yscr(y1));
	glVertex2d(gr_xscr(x2), gr_yscr(y2));
	glEnd();
}

void Window::gr_window(double left,  double bottom,
               double right, double top,
               bool samescale, int bordercolor)
	/* ���̍��E���E�E�E��[�̍��W���w�肷��.
	   samescale �� 0 �Ȃ�㉺�ƍ��E�̎ړx�𓯂��ɂ���.
	   bordercolor �� 0 �Ȃ炻�̐F�Řg��`�� */
{
	gr_xfac = (XMAX - 1) / (right - left);
	gr_yfac = (YMAX - 1) / (bottom - top);
	if (samescale) {
		if (fabs(gr_xfac) > fabs(gr_yfac))
			  gr_xfac *= fabs(gr_yfac / gr_xfac);
		else  gr_yfac *= fabs(gr_xfac / gr_yfac);
	}
	gr_xconst = 0.5 - gr_xfac * left;
	gr_yconst = 0.5 - gr_yfac * top;
	if (bordercolor) {
		gr_wline(left , bottom, left , top   , bordercolor);
		gr_wline(left , top   , right, top   , bordercolor);
		gr_wline(right, top   , right, bottom, bordercolor);
		gr_wline(right, bottom, left , bottom, bordercolor);
	}
}
