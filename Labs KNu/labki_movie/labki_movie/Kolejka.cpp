#include "stdafx.h"
#include "Kolejka.h"

bool Kolejka::is_full()
{
	return top == capacity;
}

void Kolejka::add(Movie & element)
{
	arr.add(element);
}

Movie Kolejka::get()
{
	return arr.pop_queue();
}