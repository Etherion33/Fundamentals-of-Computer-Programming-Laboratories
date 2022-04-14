#pragma once

#include <cctype>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stdafx.h"

#define DL_MAX 64
#define BUFOR 2048

typedef struct _Kategoria
{
	char nazwa[DL_MAX];
}Kategoria;

typedef struct _Ksiazka
{
	char autor[DL_MAX];
	char tytul[DL_MAX];
	int iloscKategorii;
	Kategoria* kategorie;
}Ksiazka;

typedef struct _BazaKsiazek
{
	int rozmiar;
	Ksiazka* ksiazki;
}BazaKsiazek;
void usunBaze(BazaKsiazek baza);
void zapiszDane(BazaKsiazek baza, char* plikWyjsciowy);
BazaKsiazek wczytajPlik(char* nazwaPliku);