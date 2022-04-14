#ifndef __QUEUE_H_
#define __QUEUE_H_
#define MAX 5
#include "Movie.h"
#include <iostream>
#include <string>

class MyQueue{
public:
    int capacity = MAX;
	Library arr;
	int top = -1;
	bool is_full();
    void add_queue(Movie &element);
    void delete_queue();
    void print_queue();
    MyQueue();
    ~MyQueue();
private:
    Movie * movie;
    MyQueue * next;
};

#endif // __QUEUE_H_
