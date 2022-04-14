// testing.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#define _CRT_SECURE_NO_WARNINGS


#include <string.h>
#include "Header.h"



int main(int argc, char *argv[])
{
	if (argc != 5)
		printf("Za mala ilosc argumentow. poprawne uzycie: <nazwa programu> -i <sciezkaPlikuWejsciowego> -o <sciezkaPlikuWyjsciowego>");
	else
	{
		int i, pobraniePlikuWe, pobraniePlikuWy;
		char inp[100], outp[100];
		pobraniePlikuWe = pobraniePlikuWy = 0; //flaga 0 - brak sukcesu
		for (i = 1; i <= 3; i += 2) //pêtla tylko dla i=1 i i=3, wtedy nazwy plików to 2gi i 4ty argument
		{
			if (strcmp(argv[i], "-i") == 0)
			{
				strcpy(inp, argv[i + 1]);
				pobraniePlikuWe = 1;
			}
			if (strcmp(argv[i], "-o") == 0)
			{
				strcpy(outp, argv[i + 1]);
				pobraniePlikuWy = 1;
			}
		}

		if (pobraniePlikuWe == 0)
		{
			printf("Niepoprawny plik wejsciowy");
			return -1; //wyjscie z programu z bledem
		}

		if (pobraniePlikuWy == 0)
		{
			printf("Niepoprawny plik wyjsciowy");
			return -1;//wyjscie z programu z bledem
		}

		BazaKsiazek baza = wczytajPlik(inp);
		zapiszDane(baza, outp);
		usunBaze(baza);

		system("PAUSE");
		return 0;
	}
}