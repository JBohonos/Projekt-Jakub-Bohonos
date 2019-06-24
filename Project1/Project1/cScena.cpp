//
// Created by piotr on 27.03.19.
//

#include "cScena.h"

cScena::cScena():active_id(0), vector_active_id(0) {
	//vector<cFigura*> prostokaty;
	//vector<cFigura*> prostokaty_pusty;
	//vector<int> linia_bomb;
	//vector<bool> linia_nacisnietych_kwadratow;
	srand(time(0));
	//for (double i = 0; i < 5; i++)
	//{
	//	prostokaty.push_back(new cKwadrat(1.5 - i * 0.15, 0.5, -2, -2.25 + i * 0.5, 1, 0, 0));
	//}
	for (double j = 0; j < 30; j++)
	{
		vector<cFigura*> prostokaty;
		vector<int> linia_bomb;
		vector<bool> linia_nacisnietych_kwadratow;
		for (double i = 0; i < 30; i++)
		{
			prostokaty.push_back(new cKwadrat(0.95, 0.95, 0.5+i, 0.5+j, 0, 0, 0));
			linia_nacisnietych_kwadratow.push_back(false);
			int los = rand() % 5 + 1;
			if (los == 1)
			{
				linia_bomb.push_back(1);
			}
			else
			{
				linia_bomb.push_back(0);
			}
		}
		bomby.push_back(linia_bomb);
		kwadraty.push_back(prostokaty);
		nacisniete_kwadraty.push_back(linia_nacisnietych_kwadratow);
	}
	//kwadraty.push_back(prostokaty);
	//kwadraty.push_back(prostokaty_pusty);
	//kwadraty.push_back(prostokaty_pusty);
	koniec_gry = false;
}
cScena::~cScena()
{
	//for (auto& el : prostokaty)
		//delete el;
}
void cScena::resize(int width, int height) {
    const float ar = (float)width / (float)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    //gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
	glOrtho(0, 30, 30, 0, 1, -1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void cScena::idle() {
    glutPostRedisplay();
}

void cScena::display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    {
        //for(auto& el: prostokaty)
		
		for (auto itr1 = kwadraty.begin(); itr1 != kwadraty.end(); itr1++)
		{
			for (auto itr2 = (*itr1).begin(); itr2 != (*itr1).end(); itr2++)
			{
				(*itr2)->rysuj();
			}
		}
		
    }
    glPopMatrix();

    glutSwapBuffers();
}
void cScena::key(unsigned char key, int x, int y)
{
	switch(key)
	{
	
	case'z':
	{
		
	}

		
	}


}
void cScena::mouse(int button, int state, int x, int y)
{
	if (koniec_gry == false)
	{
		//double openglX = ((double)x - 400) / 800 * 6.68;
		//double openglY = -((double)y - 300) / 600 * 5;
		double openglX = (double)x / 800 * 30;
		double openglY = (double)y / 800 * 30;
		if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
		{
			if (active_id > -1 && vector_active_id > -1)
			{
				//kwadraty[vector_active_id][active_id]->zmien_kolor(1, 0, 0);		
			}
		}
		else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{


			int vector_licznik = 0;
			active_id = -1;
			vector_active_id = -1;
			bool kliknieto = false;
			for (auto itr = kwadraty.begin(); itr != kwadraty.end(); itr++)
			{
				int licznik = 0;
				for (auto itr2 = (*itr).begin(); itr2 != (*itr).end(); itr2++)
				{

					if ((*itr2)->czy_kliknieto(openglX, openglY))
					{
						//(*itr2)->zmien_kolor(0, 1, 0);
						vector_active_id = vector_licznik;
						active_id = licznik;
						kliknieto = true;
						break;
					}

					licznik++;
				}
				vector_licznik++;
				if (kliknieto == true)
				{
					break;
				}
			}
			if (nacisniete_kwadraty[vector_active_id][active_id] == false)
			{
				if (bomby[vector_active_id][active_id] == 1)
				{
					nacisniete_kwadraty[vector_active_id][active_id] = true;
					kwadraty[vector_active_id][active_id]->zmien_kolor(1, 0, 0);
					cout << "Przegrales." << endl;
					koniec_gry = true;
				}
				if (bomby[vector_active_id][active_id] == 0)
				{
					nacisniete_kwadraty[vector_active_id][active_id] = true;
					int bomby_wokolo = 0;
					if (vector_active_id != 0)
					{
						if (bomby[vector_active_id - 1][active_id] == 1)
						{
							bomby_wokolo++;
						}
					}
					if (vector_active_id != 0 && active_id != 29)
					{
						if (bomby[vector_active_id - 1][active_id + 1] == 1)
						{
							bomby_wokolo++;
						}
					}
					if (active_id != 29)
					{
						if (bomby[vector_active_id][active_id + 1] == 1)
						{
							bomby_wokolo++;
						}
					}
					if (vector_active_id != 29 && active_id != 29)
					{
						if (bomby[vector_active_id + 1][active_id + 1] == 1)
						{
							bomby_wokolo++;
						}
					}
					if (vector_active_id != 29)
					{
						if (bomby[vector_active_id + 1][active_id] == 1)
						{
							bomby_wokolo++;
						}
					}
					if (vector_active_id != 29 && active_id != 0)
					{
						if (bomby[vector_active_id + 1][active_id - 1] == 1)
						{
							bomby_wokolo++;
						}
					}
					if (active_id != 0)
					{
						if (bomby[vector_active_id][active_id - 1] == 1)
						{
							bomby_wokolo++;
						}
					}
					if (vector_active_id != 0 && active_id != 0)
					{
						if (bomby[vector_active_id - 1][active_id - 1] == 1)
						{
							bomby_wokolo++;
						}
					}
					if (bomby_wokolo == 1)
					{
						kwadraty[vector_active_id][active_id]->zmien_kolor(0, 0, 0.5);
					}
					if (bomby_wokolo == 2)
					{
						kwadraty[vector_active_id][active_id]->zmien_kolor(0, 0, 1);
					}
					if (bomby_wokolo == 3)
					{
						kwadraty[vector_active_id][active_id]->zmien_kolor(0, 0.5, 0);
					}
					if (bomby_wokolo == 4)
					{
						kwadraty[vector_active_id][active_id]->zmien_kolor(0, 1, 0);
					}
					if (bomby_wokolo == 5)
					{
						kwadraty[vector_active_id][active_id]->zmien_kolor(0, 0.5, 1);
					}
					if (bomby_wokolo == 6)
					{
						kwadraty[vector_active_id][active_id]->zmien_kolor(1, 0, 1);
					}
					if (bomby_wokolo == 7)
					{
						kwadraty[vector_active_id][active_id]->zmien_kolor(0.25, 0, 1);
					}
					if (bomby_wokolo == 8)
					{
						kwadraty[vector_active_id][active_id]->zmien_kolor(1, 1, 0);
					}
					if (bomby_wokolo == 0)
					{
						kwadraty[vector_active_id][active_id]->zmien_kolor(0.9, 0.9, 0.9);
					}
				}
			}
		}
		if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
		{

		}
		else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		{
			int vector_licznik = 0;
			active_id = -1;
			vector_active_id = -1;
			bool kliknieto = false;
			for (auto itr = kwadraty.begin(); itr != kwadraty.end(); itr++)
			{
				int licznik = 0;
				for (auto itr2 = (*itr).begin(); itr2 != (*itr).end(); itr2++)
				{

					if ((*itr2)->czy_kliknieto(openglX, openglY))
					{
						vector_active_id = vector_licznik;
						active_id = licznik;
						if (nacisniete_kwadraty[vector_active_id][active_id] == false)
						{
							if ((*itr2)->get_czerwony() < 0.5)
							{
								(*itr2)->zmien_kolor(1, 0.5, 0);
							}
							else
							{
								(*itr2)->zmien_kolor(0, 0, 0);
							}
						}
						kliknieto = true;
						break;
					}

					licznik++;
				}
				vector_licznik++;
				if (kliknieto == true)
				{
					break;
				}
			}

		}
	}
}
void cScena::motion(int x, int y)
{
	
	//double openglX = ((double)x - 400) / 800 * 6.68;
	//double openglY = -((double)y - 300) / 600 * 5;
	double openglX = (double)x / 800 * 30;
	double openglY = (double)y / 800 * 30;
	
	//if (active_id > -1)
	//{
		//kwadraty[vector_active_id][active_id]->przesun_do(openglX, openglY);
	//}
}

void cScena::set_callbacks() {
    glutReshapeFunc(resize_binding);
    glutDisplayFunc(display_binding);
    glutIdleFunc(idle_binding);
	glutKeyboardFunc(key_binding);
	glutMouseFunc(mouse_binding);
	glutMotionFunc(motion_binding);
}

void cScena::init(int argc, char **argv, const char *window_name) {

    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(40, 40);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

    glutCreateWindow(window_name);

    // set white as the clear colour
    glClearColor(1, 1, 1, 1);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);

    set_callbacks();

    // start GLUT event loop. It ends when user close the window.
    glutMainLoop();
}
