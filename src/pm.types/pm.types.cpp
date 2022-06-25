// pm.types.cpp : Defines the functions for the static library.
//

#include "pch.h"

typedef int (*calc_t)(int, int);

constexpr int sum(const int& a, const int& b)
{
	return a + b;
}

void main()
{
	// With function pointers
	int (*calc)(const int& a, const int& b) = sum;
	int c = calc(5, 6);

	auto sumLambda = [c](int a, int b) { return a + b + c; };
	int d = sumLambda(7, 8);
}