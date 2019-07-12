
#include "cScena.h"

cScena::cScena() :active_id(0), vector_active_id(0) {
	
	srand(time(0));
	
	for (double j = 0; j < 30; j++)
	{
		vector<cFigura*> prostokaty;
		vector<int> linia_bomb;
		vector<bool> linia_nacisnietych_kwadratow;
		for (double i = 0; i < 30; i++)
		{
			prostokaty.push_back(new cKwadrat(0.95, 0.95, 0.5 + i, 0.5 + j, 0, 0, 0, ' '));
			linia_nacisnietych_kwadratow.push_back(false);
			int los = rand() % 7 + 1;
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
	
	koniec_gry = false;
}
cScena::~cScena()
{
	
}
int liczenie_bomb(vector<vector<int>> bomby, int vector_active_id, int active_id)
{
	int bomby_wokolo = 0;
	if (vector_active_id > 0)
	{
		if (bomby[vector_active_id - 1][active_id] == 1)
		{
			bomby_wokolo++;
		}
	}
	if (vector_active_id > 0 && active_id < 29)
	{
		if (bomby[vector_active_id - 1][active_id + 1] == 1)
		{
			bomby_wokolo++;
		}
	}
	if (active_id < 29)
	{
		if (bomby[vector_active_id][active_id + 1] == 1)
		{
			bomby_wokolo++;
		}
	}
	if (vector_active_id < 29 && active_id < 29)
	{
		if (bomby[vector_active_id + 1][active_id + 1] == 1)
		{
			bomby_wokolo++;
		}
	}
	if (vector_active_id < 29)
	{
		if (bomby[vector_active_id + 1][active_id] == 1)
		{
			bomby_wokolo++;
		}
	}
	if (vector_active_id < 29 && active_id > 0)
	{
		if (bomby[vector_active_id + 1][active_id - 1] == 1)
		{
			bomby_wokolo++;
		}
	}
	if (active_id > 0)
	{
		if (bomby[vector_active_id][active_id - 1] == 1)
		{
			bomby_wokolo++;
		}
	}
	if (vector_active_id > 0 && active_id > 0)
	{
		if (bomby[vector_active_id - 1][active_id - 1] == 1)
		{
			bomby_wokolo++;
		}
	}
	return bomby_wokolo;
}
void kolorowanie_kwadratow(vector<vector<cFigura*>> &kwadraty, int bomby_wokolo, int vector_active_id, int active_id)
{
	if (bomby_wokolo == 1)
	{
		kwadraty[vector_active_id][active_id]->zmien_kolor(0, 0, 0.5);
		kwadraty[vector_active_id][active_id]->ustaw_numer('1');
	}
	if (bomby_wokolo == 2)
	{
		kwadraty[vector_active_id][active_id]->zmien_kolor(0.3, 0.3, 1);
		kwadraty[vector_active_id][active_id]->ustaw_numer('2');
	}
	if (bomby_wokolo == 3)
	{
		kwadraty[vector_active_id][active_id]->zmien_kolor(0, 0.5, 0);
		kwadraty[vector_active_id][active_id]->ustaw_numer('3');
	}
	if (bomby_wokolo == 4)
	{
		kwadraty[vector_active_id][active_id]->zmien_kolor(0, 1, 0);
		kwadraty[vector_active_id][active_id]->ustaw_numer('4');
	}
	if (bomby_wokolo == 5)
	{
		kwadraty[vector_active_id][active_id]->zmien_kolor(0, 1, 1);
		kwadraty[vector_active_id][active_id]->ustaw_numer('5');
	}
	if (bomby_wokolo == 6)
	{
		kwadraty[vector_active_id][active_id]->zmien_kolor(1, 0, 1);
		kwadraty[vector_active_id][active_id]->ustaw_numer('6');
	}
	if (bomby_wokolo == 7)
	{
		kwadraty[vector_active_id][active_id]->zmien_kolor(0.25, 0, 0.25);
		kwadraty[vector_active_id][active_id]->ustaw_numer('7');
	}
	if (bomby_wokolo == 8)
	{
		kwadraty[vector_active_id][active_id]->zmien_kolor(1, 1, 0);
		kwadraty[vector_active_id][active_id]->ustaw_numer('8');
	}
	if (bomby_wokolo == 0)
	{
		kwadraty[vector_active_id][active_id]->zmien_kolor(0.9, 0.9, 0.9);
		kwadraty[vector_active_id][active_id]->ustaw_numer(' ');
	}
}
void sprawdzanie_sasiedztwa_szarych_pol(vector<vector<cFigura*>> &kwadraty, vector<vector<int>> bomby, vector<vector<bool>> &nacisniete_kwadraty, vector<pair<int, int>> &wektor_wspolrzedne_szarych_pol, int bomby_wokolo, int vector_active_id, int active_id)
{
	pair<int, int> wspolrzedne_szarych_pol;
	bomby_wokolo = liczenie_bomb(bomby, vector_active_id, active_id);
	kolorowanie_kwadratow(kwadraty, bomby_wokolo, vector_active_id, active_id);
	if (bomby_wokolo == 0 && nacisniete_kwadraty[vector_active_id][active_id] == false)
	{
		wspolrzedne_szarych_pol.first = vector_active_id;
		wspolrzedne_szarych_pol.second = active_id;
		wektor_wspolrzedne_szarych_pol.push_back(wspolrzedne_szarych_pol);
	}
	nacisniete_kwadraty[vector_active_id][active_id] = true;
}
void cScena::resize(int width, int height) {
	const float ar = (float)width / (float)height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();	
	glOrtho(0, 30, 30, 0, 1, -1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void cScena::idle() {
	bool sprawdzenie_klockow = true;
	int j = 0;
	for (auto itr = nacisniete_kwadraty.begin(); itr != nacisniete_kwadraty.end(); itr++)
	{
		int i = 0;
		for (auto itr2 = (*itr).begin(); itr2 != (*itr).end(); itr2++)
		{
			if ((*itr2) == false && bomby[j][i] == 0)
			{
				sprawdzenie_klockow = false;
			}
			i++;
		}
		j++;
	}
	if (sprawdzenie_klockow == true)
	{
		cout << "Wygrales." << endl;
		koniec_gry = true;
	}
	if (koniec_gry == true)
	{
		int poziom_trudnosci;
		cout << "Gra sie skonczyla." << endl;
		do
		{
			cout << "Podaj jaki poziom trudnosci ma miec nastepna gra(od 3-natrudniejsza do 10-najlatwiejsza): ";
			cin >> poziom_trudnosci;
		} while (poziom_trudnosci < 3 || poziom_trudnosci > 10);

		j = 0;
		srand(time(0));

		for (auto itr = kwadraty.begin(); itr != kwadraty.end(); itr++)
		{
			int i = 0;
			for (auto itr2 = (*itr).begin(); itr2 != (*itr).end(); itr2++)
			{
				(*itr2)->zmien_kolor(0, 0, 0);
				nacisniete_kwadraty[j][i] = false;
				(*itr2)->ustaw_numer(' ');
				int los = rand() % poziom_trudnosci + 1;
				if (los == 1)
				{
					bomby[j][i] = 1;
				}
				else
				{
					bomby[j][i] = 0;
				}
				i++;
			}
			j++;
		}
		koniec_gry = false;
		active_id = -1;
		vector_active_id = -1;
	}




	glutPostRedisplay();
}

void cScena::display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	{		

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

void cScena::mouse(int button, int state, int x, int y)
{
	if (koniec_gry == false)
	{		
		double openglX = (double)x / 800 * 30;
		double openglY = (double)y / 800 * 30;
		if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
		{
			if (active_id > -1 && vector_active_id > -1)
			{
				
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
			if (active_id > -1 && vector_active_id > -1)
			{
				if (nacisniete_kwadraty[vector_active_id][active_id] == false)
				{
					if (bomby[vector_active_id][active_id] == 1)
					{
						nacisniete_kwadraty[vector_active_id][active_id] = true;
						kwadraty[vector_active_id][active_id]->zmien_kolor(1, 0, 0);
						kwadraty[vector_active_id][active_id]->ustaw_numer('B');
						cout << "Przegrales." << endl;
						koniec_gry = true;
					}
					if (bomby[vector_active_id][active_id] == 0)
					{
						nacisniete_kwadraty[vector_active_id][active_id] = true;
						int bomby_wokolo = 0;

						bomby_wokolo = liczenie_bomb(bomby, vector_active_id, active_id);

						kolorowanie_kwadratow(kwadraty, bomby_wokolo, vector_active_id, active_id);

						if (bomby_wokolo == 0)
						{
							vector<pair<int, int>> wektor_wspolrzedne_szarych_pol;
							pair<int, int> wspolrzedne_szarych_pol;
							do
							{


								if (wektor_wspolrzedne_szarych_pol.size() != 0)
								{
									vector_active_id = wektor_wspolrzedne_szarych_pol[0].first;
									active_id = wektor_wspolrzedne_szarych_pol[0].second;
								}
								if (wektor_wspolrzedne_szarych_pol.size() != 0)
								{
									wektor_wspolrzedne_szarych_pol.erase(wektor_wspolrzedne_szarych_pol.begin());
								}
								if (vector_active_id < 29)
								{
									sprawdzanie_sasiedztwa_szarych_pol(kwadraty, bomby, nacisniete_kwadraty, wektor_wspolrzedne_szarych_pol, bomby_wokolo, vector_active_id + 1, active_id);									
								}
								if (vector_active_id < 29 && active_id < 29)
								{
									sprawdzanie_sasiedztwa_szarych_pol(kwadraty, bomby, nacisniete_kwadraty, wektor_wspolrzedne_szarych_pol, bomby_wokolo, vector_active_id + 1, active_id + 1);									
								}
								if (active_id < 29)
								{
									sprawdzanie_sasiedztwa_szarych_pol(kwadraty, bomby, nacisniete_kwadraty, wektor_wspolrzedne_szarych_pol, bomby_wokolo, vector_active_id, active_id + 1);									
								}
								if (vector_active_id > 0 && active_id < 29)
								{
									sprawdzanie_sasiedztwa_szarych_pol(kwadraty, bomby, nacisniete_kwadraty, wektor_wspolrzedne_szarych_pol, bomby_wokolo, vector_active_id - 1, active_id + 1);									
								}
								if (vector_active_id > 0)
								{
									sprawdzanie_sasiedztwa_szarych_pol(kwadraty, bomby, nacisniete_kwadraty, wektor_wspolrzedne_szarych_pol, bomby_wokolo, vector_active_id - 1, active_id);									
								}
								if (vector_active_id > 0 && active_id > 0)
								{
									sprawdzanie_sasiedztwa_szarych_pol(kwadraty, bomby, nacisniete_kwadraty, wektor_wspolrzedne_szarych_pol, bomby_wokolo, vector_active_id - 1, active_id - 1);									
								}
								if (active_id > 0)
								{
									sprawdzanie_sasiedztwa_szarych_pol(kwadraty, bomby, nacisniete_kwadraty, wektor_wspolrzedne_szarych_pol, bomby_wokolo, vector_active_id, active_id - 1);									
								}
								if (vector_active_id < 29 && active_id > 0)
								{
									sprawdzanie_sasiedztwa_szarych_pol(kwadraty, bomby, nacisniete_kwadraty, wektor_wspolrzedne_szarych_pol, bomby_wokolo, vector_active_id + 1, active_id - 1);									
								}
							} while (wektor_wspolrzedne_szarych_pol.size() != 0);
						}
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
								(*itr2)->ustaw_numer('F');
							}
							else
							{
								(*itr2)->zmien_kolor(0, 0, 0);
								(*itr2)->ustaw_numer('?');
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

void cScena::set_callbacks() {
	glutReshapeFunc(resize_binding);
	glutDisplayFunc(display_binding);
	glutIdleFunc(idle_binding);	
	glutMouseFunc(mouse_binding);	
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

