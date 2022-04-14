#include <iostream>
#include "Library.h"
#include "queue.h"

int main()
{
    std::string title;
	int production_year;
	int rating;
    Library mleko;
    Movie kekeke;
    Movie Tmovies[2];


    MyQueue kolejka;
    for (int i = 0; i <2; i++)
	{
		std::cout << "Title:";
		std::cin >> title;
		std::cout << "Year:";
		std::cin>>production_year;
		std::cout << "Rating:";
		std::cin>> rating;

		Tmovies[i].set_Title(title);
		Tmovies[i].set_ProductionYear(production_year);
		Tmovies[i].set_Rating(rating);
		std::cout <<std::endl<< std::endl;
		kolejka.add_queue(Tmovies[i]);
	}
	Tmovies[1]=Tmovies[2];


    return 0;
}
