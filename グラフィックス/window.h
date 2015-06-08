/***********************************************************
	window.h -- グラフィックス
***********************************************************/
/* 座標変換 */
#ifndef WINDOW_H
#define WINDOW_H

// 色コード
enum Color {
	BLACK, 
	BLUE, 
	RED, 
	MAGENTA, 
	GREEN, 
	CYAN, 
	YELLOW, 
	WHITE};
	
const int XMAX = 640;
const int YMAX = 400;
	
class Window {
public:
	Window();
	void gr_wdot(double x, double y, int color);
	void gr_wline(double x1, double y1, double x2, double y2, int color);
	void gr_window(double left,  double bottom, double right, double top, bool samescale, int bordercolor);

private:
	double gr_xfac;
	double gr_yfac;
	double gr_xconst;
	double gr_yconst;
	int gr_xscr(double x);
	int gr_yscr(double y);
};

#endif
