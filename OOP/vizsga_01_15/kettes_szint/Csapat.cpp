#include "Csapat.h"
#include "Jatekos.h"
#include <iostream>

using namespace std;

Csapat::Csapat(string nev) : nev(nev) { }

string Csapat::getName() const
{
	return nev;
}

void Csapat::jatekosok() const
{
	cout << nev << endl;
	for (auto j : jatekosLista) cout << "\t" << j->getNev() << endl;
}

void Csapat::leigazol(Jatekos* ujJatekos)
{
	jatekosLista.push_back(ujJatekos);
	if (ujJatekos->getCsapat() != nullptr) ujJatekos->getCsapat()->elad(ujJatekos);
	ujJatekos->setCsapat(this);
}

void Csapat::elad(Jatekos* eladottJatekos)
{
	for (unsigned int i = 0; i<jatekosLista.size(); i++)
		if (jatekosLista[i]->getNev() == eladottJatekos->getNev()) {
			jatekosLista.erase(jatekosLista.begin()+i);
			break;
		}
}
