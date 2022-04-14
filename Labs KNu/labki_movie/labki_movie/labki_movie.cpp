// labki_movie.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "string"
//#include "Dynamic.h"
//#include "Stack.h"
#include"Kolejka.h"
int main()
{


	std::string title;
	int production_year;
	int rating;
	Movie kek;
	Movie Tmovies[5];
	Kolejka tablica;

	for (int i = 0; i <5; i++)
	{
		std::cout << "title, production year, rating";
		std::cin >> title;
		std::cin>>production_year;
		std::cin>> rating;

		Tmovies[i].title=title;
		Tmovies[i].production_year = production_year;
		Tmovies[i].rating = rating;
		std::cout <<std::endl<< std::endl;
		tablica.add(Tmovies[i]);
	}
	kek=tablica.get();
	std::cout << kek.title;

	system("PAUSE");
    return 0;
}

