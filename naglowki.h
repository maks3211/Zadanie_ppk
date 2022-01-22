/** @file */

#pragma once    
#include <iostream>
#include <fstream>
#include <sstream>
#include<algorithm>
#include<vector>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <chrono>
#include <windows.h>
#include "struktury.h"
using namespace::std;

#ifndef FUNKCJE_H   
#define FUNKCJE_H

/** Funkcja odczytuje plik zawierajacy informacje o daniach.
  @param menu vector zawierajacy strukture dan
  @param nazwa_pliku nazwa pliku zawierajacego informacje o daniach
*/
void odczyt(vector<pozycja>& menu, string nazwa_pliku);


/** Funkcja wyswietlajaca kategorie (ekran ktory wsywietla sie na poczatku)
 @param kategorie vector zawierajacy niepowtarzajace sie kategorie dan
 @param zamowione vector vector zawierajacy indeksy zamowionych dan
 @param wybor_pierwszy wybrana kategoria
 @param przelacznik wyzwala odpowiedni ekran menu
 */
void wys_kategorie(vector<string>& kategorie, vector<int>& zamowione, int& wybor_pierwszy, int& przelacznik);


/** Funkcja tworzy plik 'rachunek' i uzupelnia go.
  @param zamowione vector zawierajacy indeksy zamowionych dan
  @param menu vector zawierajacy strukture dan
  @param do_zaplaty koncowa kwota jak nalezy zaplacic 
  @param stolik informacja dotyczaca numeru wybrnego stolika 
 */
void rachunek(vector<int> zamowione, vector<pozycja>menu, double do_zaplaty, char* stolik);



/** Funkcja wyswietlajaca dania z konkretnej kategorii 
  @param wybor_pierwszy numer wybrajen kategorii 
  @param menu vector zawierajacy strukture dan
  @param kategorie vector zawierajacy niepowtarzajace sie kategorie dan 
  @param zamowione vector vector zawierajacy indeksy zamowionych dan
  @param przelacznik wyzwala odpowiedni ekran menu
 */
void menu_poziom_pier(int wybor_pierwszy, vector<pozycja>menu, vector <string> kategorie, vector<int>& zamowione, int& przelacznik);



/** Funkcja zliczajaca koncowa kwote do zaplaty 
  @param zamowione vector vector zawierajacy indeksy zamowionych dan
  @param do_zaplaty koncowa kwota jak nalezy zaplacic 
  @param menu vector zawierajacy strukture dan
 */
void menu_poziom_drugi(vector<int>zamowione, double& do_zaplaty, vector<pozycja>menu);



#endif