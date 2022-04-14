#include "stdafx.h"
#include <iostream>
#include "string"

class Movie
{
public:
	std::string title;
	int production_year;
	int rating;
	Movie();
	Movie(std::string t, int p_year, int r);
	void show_movie();
};