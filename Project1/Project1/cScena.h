//
// Created by piotr on 27.03.19.
//

#ifndef FREEGLUT_CSCENA_H
#define FREEGLUT_CSCENA_H
#include "cKwadrat.h"
#include <vector>
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
//bindingi dla callbacków
void resize_binding(int width, int height);
void idle_binding();
void display_binding();
void key_binding(unsigned char key, int x, int y);
void mouse_binding(int button, int state, int x, int y);
void motion_binding(int x, int y);

class cScena {
    //std::vector<cFigura*> prostokaty;
	vector<vector<cFigura*>> kwadraty;
	vector<vector<int>> bomby;
	vector<vector<bool>> nacisniete_kwadraty;
	int vector_active_id;
	int active_id;
public:
    cScena();
	~cScena();
    void resize(int width, int height);
    void idle();
    void display();
	void key(unsigned char key, int x, int y);
	void mouse(int button, int state, int x, int y);
	void motion(int x, int y);
    void init(int argc, char *argv[], const char* window_name);
    void set_callbacks();

};


#endif //FREEGLUT_CSCENA_H
