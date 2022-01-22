/** @file */



#ifndef STRUKTURY_H  
#define STRUKTURY_H


#include <string>
using namespace::std;

/** Struktura zawieraj¹ca wszystkie informacje na temat dan  */
 struct pozycja
{
	int numer;   ///< numer dania
	string nazwa; ///< nazwa dania
	string kategoria; ///< kategoria dania
	double cena;   ///< cena dania
	string opis;   ///< opis dania
};

#endif
