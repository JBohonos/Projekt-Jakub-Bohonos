#include "cScena.h"

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