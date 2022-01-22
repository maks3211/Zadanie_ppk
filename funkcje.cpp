#include <iostream>
#include <fstream>
#include <sstream>
#include<algorithm>
#include<vector>
#include <string>
#include <iomanip>
#include "naglowki.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <chrono>
#include <windows.h>
#include "naglowki.h"
#include "struktury.h"
using namespace::std;

void odczyt(vector<pozycja>& menu, string nazwa_pliku)
{
	pozycja element;
	ifstream plik(nazwa_pliku);

	if (plik.fail())
	{
		cout << "Nie znaleziono pliku 'baza.txt' " << endl;
		exit(1);
	}


	if (!ifstream("baza.txt", ios::ate).tellg())
	{
		cout << "Plik 'baza.txt' jest pusty\n";
		exit(1);
	}

	if (plik)
	{
		
		while (!plik.eof())
		{
			
			string nr; //numer
			string nazwa{ "" }; //nazwa
			string kategoria{ "" }; //kategoria
			string c; //cena
			string opis; // opis
			char znak;
			plik >> nr;
			plik.get();
			while ((znak = plik.get()) != ';')
			{
				nazwa += znak;
			}

			plik.get();

			while ((znak = plik.get()) != ';')
			{
				kategoria += znak;
			}


			plik >> c;
			plik.get();
			getline(plik, opis);

			nr.pop_back();   //usuwanie ostatnego elementu


			c.pop_back();
			int numer = stoi(nr);
			double cena = stod(c);

			element.numer = numer;
			element.nazwa = nazwa;
			element.kategoria = kategoria;
			element.cena = cena;
			element.opis = opis;
			menu.push_back(element);

		}
	}
	plik.close();
}


void wys_kategorie(vector<string>& kategorie, vector<int>& zamowione, int& wybor_pierwszy, int& przelacznik)
{

	for (unsigned int i = 0; i < unsigned(kategorie.size()); i++)
	{
		cout << i + 1 << "       " << kategorie[i] << endl;

	}
	char wyb_one[1];
	const char zero = '0';
	const int zero_kod = int(zero);
	int rozmiar = kategorie.size();
	const char koniec = rozmiar;
	const int koniec_k = int(koniec) + zero_kod;
	int wyb;


	cout << "\n" << 0 << "       " << "zloz zamowienie";
	cout << "\nR       wyczysc zamowienie";
	char pierwszy_wybor;
	cout << "\nWybierz: ";

	cin >> pierwszy_wybor;
	wyb_one[0] = pierwszy_wybor;
	wyb = wyb_one[0];
	while (pierwszy_wybor != 'r' and (pierwszy_wybor < zero_kod or pierwszy_wybor >  koniec_k)) // w odpowiednim przedziale
	{
		cout << "Wcisnij odpowiedni przycisk. " << endl; 
		cin >> pierwszy_wybor;
	}
	const int dalej = 1;
	const int zle = 0;
	const int zamow = 5;


	if (pierwszy_wybor == 'r' or pierwszy_wybor == 'R')
	{
		zamowione.clear();
		system("cls");
		cout << "\nZamowienie zresetowane. " << endl;
		zamowione.clear();
		przelacznik = zle;
	}
	else {
		switch (pierwszy_wybor)
		{
		case '0':
		{
			przelacznik = zamow;
		}
		default:
		{
			if (pierwszy_wybor != '0')
			{
				przelacznik = dalej;
				system("cls");
			}
		}
		}
	}
	wybor_pierwszy = pierwszy_wybor - '0';

}




void menu_poziom_pier(int wybor_pierwszy, vector<pozycja>menu, vector <string> kategorie, vector<int>& zamowione, int& przelacznik)  
{
	
	string kategoria;
	if (wybor_pierwszy > 0)
	{
		kategoria = kategorie[wybor_pierwszy - 1];
	}
	int lp = 1;
	int drugi_wybor;
	vector<int> dania_z_kategorii;
	unsigned long long  dlugosc = 0 ;
	double dlugosc2 = 2;
	
	
	
	
	for (unsigned int i = 0; i <unsigned(menu.size()); i++)
	{
		if (menu[i].kategoria == kategoria)
		{
			if (dlugosc < menu[i].nazwa.length())
			{
				dlugosc = menu[i].nazwa.length();
			}
			
			}
	}
	for (unsigned int i = 0; i <unsigned(menu.size()); i++)
	{
		if (menu[i].kategoria == kategoria)
		{
			if (lp == 1)
			{		
				int a = kategoria.length();				
				cout << "\n"  << setw(20)<<right << setfill('=') << kategoria << left<<"";
				cout << setw(20) << setfill('=') << left << "" << endl;
				cout << setw(0) << setfill(' ');
				cout << endl; 

				

			}
			if (menu[i].cena > 9)
			{
				dlugosc2 = 6;
			}
			cout << fixed;
			cout  << setfill(' ') << lp << " " << setw(dlugosc + 2) << menu[i].nazwa << setw(unsigned(dlugosc2)) << setprecision(2) << menu[i].cena  << "zl  " << menu[i].opis << endl;
			lp++;
			dania_z_kategorii.push_back(i);
		}
	}

	
	const int zle = 0;


	cout << "\nWybierz numer pozycji, lub 0 aby wrocic do wyboru kategorii. ";
	cin >> drugi_wybor;
	while (!cin.good())   // sprawdzanie czy wybor nie jest literka 
	{
		cin.clear();
		cin.ignore(1, '\n');
		cout << "\nwybierz od 0 do " << dania_z_kategorii.size() << endl;
		cin >> drugi_wybor;
	}

	if (drugi_wybor == 0)
	{
		system("cls");
		przelacznik = zle;
	}
	else if (unsigned (drugi_wybor) > 0 and  unsigned (drugi_wybor) <= dania_z_kategorii.size())  // drugi wybor jest w odpowiednim przedziale 
	{
		zamowione.push_back(dania_z_kategorii[drugi_wybor - 1]);
		system("cls");
		cout << "\nDodano " << menu[dania_z_kategorii[drugi_wybor - 1]].nazwa << " do zamowienia. ";
	}
	else if (drugi_wybor > 1 and dania_z_kategorii.size() == 1)
	{
		system("Cls");
		cout << "\nWybierz pozycje 1 lub wroc do wyboru kategorii. ";
	}

	else
	{
		system("Cls");
		cout << "\nwybierz od 0 do " << dania_z_kategorii.size() << endl;
	}
}

void menu_poziom_drugi(vector<int>zamowione, double& do_zaplaty, vector<pozycja>menu)    //zlicza kwote do zaplaty
{
	double cena = 0;
	if (zamowione.size() < 1)
	{
		cout << "\nZamowienie jest puste";
		do_zaplaty=cena;
	}
	else
	{
		for (unsigned int i = 0; i < unsigned(zamowione.size()); i++)
		{
			cena = cena + menu[zamowione[i]].cena;
		}
		cout << "\n=================Dziekujemy za zlozenie zamowienia=================";
		do_zaplaty=cena;
	}

}





void rachunek(vector<int> zamowione, vector<pozycja>menu, double do_zaplaty, char* stolik)
{
	SYSTEMTIME st;
	GetSystemTime(&st);
	string stolik_s = stolik;
	string godzina = to_string(st.wHour + 1);
	string minuta = to_string(st.wMinute);
	string nazwa = "S" + stolik_s + "_" + godzina + "_" + minuta;
	ofstream plik;

	if (zamowione.size() > 0)    // sprawdzenie czy uzytkownik cos zamowil
	{
		plik.open(nazwa + ".txt");
		int dlugosc;
		dlugosc = 0;


		for (unsigned int i = 0; i < zamowione.size(); i++)
		{
			if (unsigned(dlugosc) < menu[zamowione[i]].nazwa.length())
			{
				dlugosc = menu[zamowione[i]].nazwa.length();

			}
		}
		dlugosc += 3;

		if (plik.is_open())
		{
			plik << "Stolik nr " << stolik << endl;
			plik << st.wHour + 1 << ":" << st.wMinute << endl;

			if (do_zaplaty > 0)
			{

				for (unsigned int i = 0; i < unsigned(zamowione.size()); i++)
				{
					plik << fixed;
					plik << setfill(' ') << setw(dlugosc) << left << menu[zamowione[i]].nazwa << setprecision(2) << menu[zamowione[i]].cena  << endl;
				}
				plik << "\n=============" << endl;
				plik << "Do zaplaty: " << do_zaplaty << " zl";
			}
		}
	}
}




