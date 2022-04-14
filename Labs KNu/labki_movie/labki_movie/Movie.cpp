#include "stdafx.h"
#include <iostream>
#include <string>
#include "Movie.h"

void Movie::show_movie()
{
	std::cout << title << std::endl <<std::endl<< production_year << std::endl<<rating;
}

Movie::Movie()
{
}

Movie::Movie(std::string t_, int p_year, int r)
{
	title = t_;
	production_year = p_year;
	rating = r;
	
}
