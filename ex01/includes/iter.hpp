#ifndef ITER_HPP
#define ITER_HPP

#include "Strings.h"

template<typename Array_Type, typename Function_Type>
void iter(Array_Type *a, size_t len, Function_Type function)
{
	for (size_t i = 0; i < len; i++)
		function(a[i]);
}

#endif