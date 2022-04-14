#pragma once
#include "stdafx.h"
#include <iostream>
#include "Dynamic.h"

class Kolejka
{
	int capacity = MAX;
	Dynamic_Array arr;
	int top = -1;
	bool is_full();

public:
	void add(Movie& element);
	Movie get();
	

};