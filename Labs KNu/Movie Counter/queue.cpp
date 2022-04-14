
#include "queue.h"

MyQueue::MyQueue()
{
    movie = new Movie[100];

}
MyQueue::~MyQueue()
{

}

bool MyQueue::is_full()
{
	return top == capacity;
}

void MyQueue::add_queue(Movie &element)
{
    //arr.add_queue(element);
}

void MyQueue::delete_queue()
{

}

