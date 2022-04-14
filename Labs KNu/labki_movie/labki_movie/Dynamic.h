#include "stdafx.h"
#include<iostream>
#include "Movie.h"
#define MAX 1

class Dynamic_Array
{
	unsigned int size=MAX;
	void reallocate();
	int last_index=-1;
	Movie* array_of_movies = new Movie[size];
public:
	void add(Movie& new_element);
	~Dynamic_Array();
	Movie operator[](int index);
	Movie pop_queue();
	Movie pop_stack();
};


