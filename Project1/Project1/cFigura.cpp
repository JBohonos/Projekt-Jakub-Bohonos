#include "cFigura.h"



cFigura::cFigura(double x, double y, double r, double g, double blue):x_(x),y_(y),r_(r),g_(g),blue_(blue)
{
}

void cFigura::przesun(double dx, double dy)
{
	x_ += dx;
	y_ += dy;

}
void cFigura::zmien_kolor(double r, double g, double blue)
{
	r_ = r;
	g_ = g;
	blue_ = blue;
}
void cFigura::przesun_do(double x, double y)
{
	x_ = x;
	y_ = y;
}
cFigura::~cFigura()
{
}
