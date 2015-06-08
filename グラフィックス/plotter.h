/***********************************************************
	plotter.h -- グラフィックス
***********************************************************/
#ifndef PLOTTER_H
#define PLOTTER_H
/* プロッタのシミュレーション */
#include <GL/glut.h>

class Plotter {
public:
	Plotter();
	Plotter(double x, double y);
	void move(double x, double y);  // ペンアップで移動
	void move_rel(double dx, double dy);  // 同上 (相対座標) 
	void draw(double x, double y);  // ペンダウンで移動
	void draw_rel(double dx, double dy);  //同上 (相対座標)

private:
	double xpen;
	double ypen;  // ペンの現在位置
};

#endif
