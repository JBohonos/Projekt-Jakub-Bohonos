#include "cFigura.h"



cFigura::cFigura(double x, double y, double r, double g):x_(x),y_(y),r_(r),g_(g)
{
}

void cFigura::przesun(double dx, double dy)
{
	x_ += dx;
	y_ += dy;

}
void cFigura::zmien_kolor(double r, double g)
{
	r_ = r;
	g_ = g;
}
void cFigura::przesun_do(double x, double y)
{
	x_ = x;
	y_ = y;
}
cFigura::~cFigura()
{
}
