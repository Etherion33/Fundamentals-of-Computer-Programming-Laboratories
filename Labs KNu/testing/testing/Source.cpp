#include "stdafx.h"
#include "Header.h"
BazaKsiazek wczytajPlik(char* nazwaPliku)
{
	//int rozmiar = 0;
	FILE* plik = fopen(nazwaPliku, "r");
	if (plik == NULL)
	{
		printf("Nie mozna otworzyc pliku do odczytu!");
		system("PAUSE");
		exit(-1);
	}
	int udanyOdczyt = 1;
	int i, j, k;

	BazaKsiazek bazaKsiazek;
	bazaKsiazek.ksiazki = (Ksiazka*)malloc(0 * sizeof(Ksiazka));

	i = 0;
	do
	{
		char bufor[BUFOR];

		if (fgets(bufor, BUFOR, plik) == NULL) //fgtets zamiast fscan
			udanyOdczyt = 0;
		else
		{
			bazaKsiazek.ksiazki = (Ksiazka*)realloc(bazaKsiazek.ksiazki, (i + 1) * sizeof(Ksiazka));

			char kategorie[BUFOR];
			char dzielnik = ';';
			int pierwszySrednik = -1;
			int drugiSrednik = -1;
			int poprzedniPrzecinek = -1;
			int nastepnyPrzecinek;
			//podzial na elementy wzgledem ;
			for (j = 0; j < strlen(bufor); j++)
			{
				if (bufor[j] == dzielnik && pierwszySrednik == -1)
					pierwszySrednik = j;
				if (bufor[j] == dzielnik && pierwszySrednik != -1)
					drugiSrednik = j;
			}

			if (pierwszySrednik == -1 || drugiSrednik == -1)
				continue;

			strncpy(bazaKsiazek.ksiazki[i].autor, bufor, pierwszySrednik); //przypisanie autora
			bazaKsiazek.ksiazki[i].autor[pierwszySrednik] = '\0';
			strncpy(bazaKsiazek.ksiazki[i].tytul, bufor + pierwszySrednik + 1, drugiSrednik - pierwszySrednik - 1); //przypisanie tytulu
			bazaKsiazek.ksiazki[i].tytul[drugiSrednik - pierwszySrednik - 1] = '\0';


			bazaKsiazek.ksiazki[i].iloscKategorii = 0; //wyzerowanie liczby kateogrii
			if (kategorie[strlen(kategorie)] == '\n')
				strncpy(kategorie, bufor + drugiSrednik + 1, strlen(bufor) - drugiSrednik - 2);//kopiowanie kategorii bez znaku nowej linii
			else
				strncpy(kategorie, bufor + drugiSrednik + 1, strlen(bufor) - drugiSrednik - 1);//kopiowanie kategorii w którym nie ma na koñcu nowej linii
			kategorie[strlen(bufor) - drugiSrednik - 2] = '\0';

			for (j = 0; j < strlen(kategorie); j++)
			{
				if (kategorie[j] == ',')
					bazaKsiazek.ksiazki[i].iloscKategorii++;
			}
			bazaKsiazek.ksiazki[i].iloscKategorii++;//po ostatnim slowie
			bazaKsiazek.ksiazki[i].kategorie = (Kategoria*)malloc(bazaKsiazek.ksiazki[i].iloscKategorii * sizeof(Kategoria));//inicjowanie kategorii


			for (j = 0; j < bazaKsiazek.ksiazki[i].iloscKategorii; j++)
			{

				poprzedniPrzecinek++; //zeby pozbyc sie przecinka
				for (k = poprzedniPrzecinek; k < strlen(kategorie); k++)
				{
					if (kategorie[k] == ',')
					{
						nastepnyPrzecinek = k;
						break;
					}
				}
				if (k == strlen(kategorie))
					nastepnyPrzecinek = k;  // przy ostatniej kategorii, której nie kończy przecinek

				while (!isalpha(kategorie[poprzedniPrzecinek]))
					poprzedniPrzecinek++;

				strncpy(bazaKsiazek.ksiazki[i].kategorie[j].nazwa, kategorie + poprzedniPrzecinek, nastepnyPrzecinek - poprzedniPrzecinek);
				bazaKsiazek.ksiazki[i].kategorie[j].nazwa[nastepnyPrzecinek - poprzedniPrzecinek] = '\0';
				poprzedniPrzecinek = nastepnyPrzecinek;
			}
			i++; //przesuwamy siê do nowego miejsca w bazie ksi¹¿ek
			bazaKsiazek.rozmiar = i;
		}

	} while (udanyOdczyt == 1);
	fclose(plik);
	return bazaKsiazek;
}

 void zapiszDane(BazaKsiazek baza, char* plikWyjsciowy)
{

	int i, j, k, l;
	int rozmiarWypisanych = 0;
	FILE* plik = fopen(plikWyjsciowy, "w");

	if (plik == NULL)
	{
		printf("Nie mozna otworzyc pliku do zapisu!");
		return;
	}

	Kategoria* wypisane = (Kategoria*)malloc(0);
	for (i = 0; i < baza.rozmiar; i++)
	{
		for (j = 0; j < baza.ksiazki[i].iloscKategorii; j++)
		{
			//sprawdzenie czy kategoriê juz wypisano
			int niewypisana = 1;
			for (k = 0; k < rozmiarWypisanych; k++)
				if (strcmp(wypisane[k].nazwa, baza.ksiazki[i].kategorie[j].nazwa) == 0)
					niewypisana = 0;

			if (niewypisana == 1)
			{
				//dodanie do 
				rozmiarWypisanych++;
				wypisane = (Kategoria*)realloc(wypisane, rozmiarWypisanych * sizeof(Kategoria));
				memcpy(&wypisane[rozmiarWypisanych - 1], &baza.ksiazki[i].kategorie[j], sizeof(Kategoria));

				//wypisanie do pliku
				fprintf(plik, "%s:\n", baza.ksiazki[i].kategorie[j].nazwa);
				for (l = i; l < baza.rozmiar; l++)
				{
					for (k = 0; k < baza.ksiazki[l].iloscKategorii; k++)
					{
						if (strcmp(baza.ksiazki[i].kategorie[j].nazwa, baza.ksiazki[l].kategorie[k].nazwa) == 0)
							fprintf(plik, "\t%s\t%s\n", baza.ksiazki[l].autor, baza.ksiazki[l].tytul);
					}
				}
				fprintf(plik, "\n");
			}
		}
	}
	fclose(plik);
}

void usunBaze(BazaKsiazek baza)
{
	int i;
	for (i = 0; i < baza.rozmiar; i++)
	{
		free(baza.ksiazki[i].kategorie);
	}
	free(baza.ksiazki);
}