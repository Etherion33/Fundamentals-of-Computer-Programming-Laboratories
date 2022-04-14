#include "stdafx.h"
#include "Stack.h"
#include <iostream>


void Stack::push(Movie & element)
{
	p.add(element);
}

Movie Stack::pop()
{

	return p.pop_stack();
}



bool Stack::is_full()
{
	if (top == (MAX - 1))
	{

		return true;
	}
	else
		return false;
}

bool Stack::is_empty()
{
	if (MAX == 0)
		return true;
	else
		return false;
}
