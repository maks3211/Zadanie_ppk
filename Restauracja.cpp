#include <iostream>
#include <fstream>
#include <sstream>
#include<algorithm>
#include<vector>
#include <string>
#include <iomanip>
#include "naglowki.h"
#include "struktury.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <chrono>
#include <windows.h>
using namespace::std;


int main(int argc, char* argv[])
{			
		if (argc < 3)
		{
			cerr << "Sprawdz poprawnosc parametrow przelaczajacych" ;
			cerr << "\nPodaj dwa argumenty wlaczajace '-s' oraz numer stolika. " << endl;
			return 1;
		}
		if (strcmp(argv[1], "-s"))
		{
			cerr << "Sprawdz poprawnosc parametrow przelaczajacych";
			cerr << "\nPodaj dwa argumenty wlaczajace '-s' oraz numer stolika. " << endl;
			return 1;
		}	
	char* stolik;
	char a = *argv[2];
	int b = a - '0';
	stolik = argv[2];
	if ( b > 10)
	{
		cout << "Podaj numer stolika. ";
		return 1;
	}



	vector<int> zamowienie; //zawiera zamowione rzeczy 
	zamowienie.clear();
	pozycja element;

	vector <pozycja> menu;

	odczyt(menu, "baza.txt");


	vector <string> kategorie;	  //vector ten zawiera kategorie (posortowane, niepowtarzaja sie) 
	kategorie.clear();						
	for (unsigned int i = 0; i < menu.size(); i++)        //sortowanie    
	{
		if (find(kategorie.begin(), kategorie.end(), menu[i].kategoria) == kategorie.end())
			kategorie.push_back(menu[i].kategoria);
	}
	string pierwszy_wybor;
	vector <int> zamowione;
	
	double do_zpalaty;
	
	int wybor_pierwszy = 1 ;
	const int dalej = 1;
	const int zle = 0;
	const int zamow = 5; 

	int przelacznik=0;
	do {
		
		while (przelacznik == zle)
		{
			wys_kategorie(kategorie, zamowione, wybor_pierwszy, przelacznik);
			
		}

		while (przelacznik == dalej)
		{
	
			menu_poziom_pier(wybor_pierwszy, menu, kategorie, zamowione, przelacznik);
		}
	} while (przelacznik != zamow);
	menu_poziom_drugi(zamowione, do_zpalaty, menu);
	rachunek(zamowione, menu, do_zpalaty, stolik);
}