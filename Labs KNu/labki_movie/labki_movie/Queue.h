#pragma once
#include"stdafx.h"
#include<iostream>
#include "Movie.h"
#define MAX 5
class Queue
{
public:	
	int size = MAX;
	Movie p[MAX];
	int top=-1;

	void push(Movie &element);
	void pop();
	void is_full();
	void is_empty();

};