#include "stdafx.h"
#include "Dynamic.h"
#define MAX 5

void Dynamic_Array::reallocate()
{

	int i = 0;
	Movie* temp = new Movie[size+1];
	std::copy(array_of_movies, array_of_movies+size, temp);
	delete [] array_of_movies;
	array_of_movies = temp;
	size++;
}

void Dynamic_Array::add(Movie & new_element)
{
	last_index++;
	if (last_index >= size)
		reallocate();
	array_of_movies[last_index] = new_element;
	
}

Dynamic_Array::~Dynamic_Array()
{
	delete [] array_of_movies;
}

Movie Dynamic_Array::operator[](int index)
{
	return array_of_movies[index];
}

Movie Dynamic_Array::pop_queue()
{
	Movie element_to_return = array_of_movies[0];
	return element_to_return;
	size--;
}

Movie Dynamic_Array::pop_stack()
{
	Movie element_to_return = array_of_movies[last_index];
	return element_to_return;
	size--;

	return element_to_return;
}



