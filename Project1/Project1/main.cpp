#include <iostream>

#define NDEBUG
#include <GL/freeglut.h>
#include "cScena.h"

cScena scena;

void resize_binding(int width, int height){
    scena.resize(width,height);
}
void idle_binding(){
    scena.idle();
}
void display_binding(){
    scena.display();
}
void key_binding(unsigned char key,	int x, int y) {
	scena.key(key,x,y);
}
void mouse_binding(int button, int state, int x, int y) {
	scena.mouse(button, state, x, y);
}
void motion_binding(int x, int y)
{
	scena.motion(x, y);
}
int main(int argc, char *argv[])
{	
    
	cout << "Ilosc bomb zalezy od koloru pola: " << endl;
	cout << "Ciemnoniebieski - 1" << endl;
	cout << "Niebieski - 2" << endl;
	cout << "Ciemnozielony - 3" << endl;
	cout << "Zielony - 4" << endl;
	cout << "Cyjanowy - 5" << endl;
	cout << "Rozowy - 6" << endl;
	cout << "Ciemnorozowy - 7" << endl;
	cout << "Zolty - 8" << endl;
	cout << "Szary - 0" << endl;
	cout << "Czerwony - bomba" << endl;
	cout << "Pomaranczowy - flaga" << endl;
    scena.init(argc,argv,"Saper");




    return 0;
}