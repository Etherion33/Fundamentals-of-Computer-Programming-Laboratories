#include "stdafx.h"
#include "Header.h"
Kategoria* dodajKategorie(BazaKsiazek* bazaKsiazek, char* nowaKategoria)
{
	Kategoria* obecna = bazaKsiazek->pierwszaKategoria;
	Kategoria* poprzednia = NULL;

	//szukanie kategorii jesli zostala juz dodana
	while (obecna != NULL)
	{
		if (strcmp(obecna->nazwa, nowaKategoria) == 0)
			return obecna;

		//przejscie po liscie z zachowaniem poprzednika
		poprzednia = obecna;
		obecna = obecna->nastepna;
	}

	//nie znaleziono takiej kategorii - tworzenie nowej
	Kategoria* kategoria = (Kategoria*)malloc(sizeof(Kategoria));
	strcpy(kategoria->nazwa, nowaKategoria);
	kategoria->nastepna = NULL;
	kategoria->pierwszaKsiazka = NULL;

	//dowiazanie nowej kategorii do bazy (jako pierwszy element lub na koncu listy)
	if (poprzednia == NULL)
		bazaKsiazek->pierwszaKategoria = kategoria;
	else
		poprzednia->nastepna = kategoria;
	return kategoria;
}

void dodajKsiazke(Kategoria* kategoria, char* autor, char* tytul)
{
	Ksiazka* obecna = kategoria->pierwszaKsiazka;
	Ksiazka* poprzednia = NULL;

	Ksiazka* nowaKsiazka = (Ksiazka*)malloc(sizeof(Ksiazka));
	strcpy(nowaKsiazka->autor, autor);
	strcpy(nowaKsiazka->tytul, tytul);
	nowaKsiazka->nastepna = NULL;

	//przejscie do ostateniej ksiazki w kategorii z zachowaniem poprzednika
	while (obecna != NULL)
	{
		poprzednia = obecna;
		obecna = obecna->nastepna;
	}

	//dowiazanie nowej ksiazki do bazy (jako pierwsza ksiazka lub na koncu listy)
	if (poprzednia == NULL)
		kategoria->pierwszaKsiazka = nowaKsiazka;
	else
		poprzednia->nastepna = nowaKsiazka;
}

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
	int j, k;

	BazaKsiazek bazaKsiazek;
	bazaKsiazek.pierwszaKategoria = NULL;

	do
	{
		char bufor[BUFOR];

		if (fgets(bufor, BUFOR, plik) == NULL) //fgtets zamiast fscan
			udanyOdczyt = 0;
		else
		{
			char kategorie[BUFOR];
			char autor[DL_MAX];
			char tytul[DL_MAX];
			int iloscKategorii = 0;
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

			strncpy(autor, bufor, pierwszySrednik); //przypisanie autora
			autor[pierwszySrednik] = '\0';
			strncpy(tytul, bufor + pierwszySrednik + 1, drugiSrednik - pierwszySrednik - 1); //przypisanie tytulu
			tytul[drugiSrednik - pierwszySrednik - 1] = '\0';


			if (kategorie[strlen(kategorie)] == '\n')
				strncpy(kategorie, bufor + drugiSrednik + 1, strlen(bufor) - drugiSrednik - 2);//kopiowanie kategorii bez znaku nowej linii
			else
				strncpy(kategorie, bufor + drugiSrednik + 1, strlen(bufor) - drugiSrednik - 1);//kopiowanie kategorii w którym nie ma na koñcu nowej linii
			kategorie[strlen(bufor) - drugiSrednik - 2] = '\0';

			for (j = 0; j < strlen(kategorie); j++)
			{
				if (kategorie[j] == ',')
					iloscKategorii++;
			}
			iloscKategorii++;//po ostatnim slowie

			for (j = 0; j < iloscKategorii; j++)
			{
				char nazwaKategorii[DL_MAX];

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
					nastepnyPrzecinek = k;

				while (!isalpha(kategorie[poprzedniPrzecinek]))
					poprzedniPrzecinek++;

				strncpy(nazwaKategorii, kategorie + poprzedniPrzecinek, nastepnyPrzecinek - poprzedniPrzecinek);
				nazwaKategorii[nastepnyPrzecinek - poprzedniPrzecinek] = '\0';
				poprzedniPrzecinek = nastepnyPrzecinek;

				Kategoria* docelowaKategoria = dodajKategorie(&bazaKsiazek, nazwaKategorii);
				dodajKsiazke(docelowaKategoria, autor, tytul);
			}
		}
	} while (udanyOdczyt == 1);
	fclose(plik);
	return bazaKsiazek;
}

void zapiszDane(BazaKsiazek baza, char* plikWyjsciowy)
{

	FILE* plik = fopen(plikWyjsciowy, "w");
	Kategoria* obecna = baza.pierwszaKategoria;

	if (plik == NULL)
	{
		printf("Nie mozna otworzyc pliku do zapisu!");
		return;
	}

	//przejscie po wszystkich kategoriach i wypisanie ich
	while (obecna != NULL)
	{
		fprintf(plik, "%s:\n", obecna->nazwa);
		Ksiazka* ksiazkaDoWypisania = obecna->pierwszaKsiazka;

		//przejscie po wszystkich ksiazkach i wypisanie ich
		while (ksiazkaDoWypisania != NULL)
		{
			fprintf(plik, "\t%s\t%s\n", ksiazkaDoWypisania->autor, ksiazkaDoWypisania->tytul);
			ksiazkaDoWypisania = ksiazkaDoWypisania->nastepna;
		}
		fprintf(plik, "\n");
		obecna = obecna->nastepna;
	}

	fclose(plik);
}

void usunBaze(BazaKsiazek baza)
{
	Kategoria* obecnaKategoria = baza.pierwszaKategoria;
	Kategoria* kategoriaDoUsuniecia;

	while (obecnaKategoria != NULL)
	{
		Ksiazka* obecnaKsiazka = obecnaKategoria->pierwszaKsiazka;
		Ksiazka* ksiazkaDoUsuniecia;
		while (obecnaKsiazka != NULL)
		{
			ksiazkaDoUsuniecia = obecnaKsiazka;
			obecnaKsiazka = obecnaKsiazka->nastepna;
			free(ksiazkaDoUsuniecia);
		}
		kategoriaDoUsuniecia = obecnaKategoria;
		obecnaKategoria = obecnaKategoria->nastepna;
		free(kategoriaDoUsuniecia);
	}
}