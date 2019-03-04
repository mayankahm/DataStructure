//============================================================================
// Name        : DS.cpp
// Author      : mdwalker
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Vector.h"

using namespace stl;

int main()
{
	Vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.pop();
	return 0;
}
