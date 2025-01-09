#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include "Strings.h"

template<typename Type>
void swap(Type &a, Type &b)
{
	Type temp = a;
	a = b;
	b = temp;
}

template<typename Type>
Type min(Type &a, Type &b)
{
	if (a < b)
		return a;
	else if (b < a)
		return b;
	else // if (b == a)
		return b;
}

template<typename Type>
Type max(Type &a, Type &b)
{
	if (a > b)
		return a;
	else if (b > a)
		return b;
	else // if (b == a)
		return b;
}

#endif