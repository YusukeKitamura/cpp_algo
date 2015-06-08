/***********************************************************
	plotter.h -- �O���t�B�b�N�X
***********************************************************/
#ifndef PLOTTER_H
#define PLOTTER_H
/* �v���b�^�̃V�~�����[�V���� */
#include <GL/glut.h>

class Plotter {
public:
	Plotter();
	Plotter(double x, double y);
	void move(double x, double y);  // �y���A�b�v�ňړ�
	void move_rel(double dx, double dy);  // ���� (���΍��W) 
	void draw(double x, double y);  // �y���_�E���ňړ�
	void draw_rel(double dx, double dy);  //���� (���΍��W)

private:
	double xpen;
	double ypen;  // �y���̌��݈ʒu
};

#endif
