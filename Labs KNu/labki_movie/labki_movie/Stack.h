
#pragma once
#include"stdafx.h"
#include<iostream>
//#include "Movie.h"
#include "Dynamic.h"
//#define MAX_SIZE 3
class Stack
{
	Dynamic_Array p;
	//Movie p[MAX_SIZE];
	//int size=MAX_SIZE;
	int top=-1;
public:
	void push(Movie& element);
	Movie pop();
	bool is_full();
	bool is_empty();
};
