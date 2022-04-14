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
	struct _Kategoria* nastepna;
	struct _Ksiazka* pierwszaKsiazka;
}Kategoria;

typedef struct _Ksiazka
{
	char autor[DL_MAX];
	char tytul[DL_MAX];
	struct _Ksiazka* nastepna;
}Ksiazka;

typedef struct _BazaKsiazek
{
	Kategoria* pierwszaKategoria;
}BazaKsiazek;
Kategoria* dodajKategorie(BazaKsiazek* bazaKsiazek, char* nowaKategoria);
void dodajKsiazke(Kategoria* kategoria, char* autor, char* tytul);
BazaKsiazek wczytajPlik(char* nazwaPliku);
void zapiszDane(BazaKsiazek baza, char* plikWyjsciowy);
void usunBaze(BazaKsiazek baza);