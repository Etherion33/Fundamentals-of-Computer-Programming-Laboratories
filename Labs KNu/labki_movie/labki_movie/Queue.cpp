#include "stdafx.h"
#include "Queue.h"

void Queue::push(Movie& element)
{
		top++;
		size++;
		p[top] = element;
		
}

void Queue::pop()
{


}

void Queue::is_full()
{
}

void Queue::is_empty()
{
}
