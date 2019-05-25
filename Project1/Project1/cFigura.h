#pragma once
#include<cstdlib>
class cFigura
{
protected:
	double x_, y_;
	double r_, g_;
public:
	cFigura(double x=0.0,double y=0.0, double r=1,double g=0);
	virtual void rysuj()=0; //metoda abstrakcyjna
	void przesun(double dx, double dy);
	void przesun_do(double x, double y);
	void zmien_kolor(double r, double g);
	virtual bool czy_kliknieto(double x, double y) = 0;
	~cFigura();
};

