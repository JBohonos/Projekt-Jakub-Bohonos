//
// Created by piotr on 27.03.19.
//

#ifndef FREEGLUT_CPROSTOKAT_H
#define FREEGLUT_CPROSTOKAT_H
#include <GL/freeglut.h>
#include"cFigura.h"
class cKwadrat: public cFigura {
double a_,b_;

public:
    cKwadrat(double a, double b, double x, double y,double r, double g, double blue, char n);
    void rysuj();
	bool czy_kliknieto(double x, double y);
	void set_x(double x);
	void set_y(double y);
	double get_a();
	//void ustaw_rozmiar(double a, double b);

};


#endif //FREEGLUT_CPROSTOKAT_H
