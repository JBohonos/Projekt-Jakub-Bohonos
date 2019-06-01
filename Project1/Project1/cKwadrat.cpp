//
// Created by piotr on 27.03.19.
//

#include "cKwadrat.h"

cKwadrat::cKwadrat(double a, double b, double x, double y, double r, double g, double blue) : cFigura(x,y,r,g,blue), a_(a), b_(b)  {
	
	
}

void cKwadrat::rysuj() {
    glPushMatrix();

    glTranslated(x_, y_, 0.0);
    glRotated(0, 1.0, 0.0, 0.0);
    glRotated(0, 0.0, 1.0, 0.0);
    glRotated(0, 0.0, 0.0, 1.0);

	glColor3d(r_, g_, blue_);

    glBegin(GL_POLYGON);
    {
        glVertex3d(-a_ / 2, b_ / 2, 0);
        glVertex3d(a_ / 2, b_ / 2, 0);
        glVertex3d(a_ / 2, -b_ / 2, 0);
        glVertex3d(-a_ / 2, -b_ / 2, 0);
    }
    glEnd();
    glPopMatrix();
}
bool cKwadrat::czy_kliknieto(double x, double y)
{
	if (fabs(x - x_) < a_ / 2 && fabs(y - y_) < b_ / 2)
	{
		return true;
	}
	return false;
	//return(fabs(x - x_) < a_ / 2 && fabs(y - y_) < b_ / 2);
}
void cKwadrat::set_x(double x)
{
	x_ = x;
}
void cKwadrat::set_y(double y)
{
	y_ = y;
}
double cKwadrat::get_a()
{
	return a_;
}
