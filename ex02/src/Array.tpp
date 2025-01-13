#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Strings.h"

/* SECTION - constructors destructors */

template <typename Type>
Array<Type>::Array() : _array(NULL), _size(0)
{
    FT_MSG("Array() Constructor")
}

template <typename Type>
Array<Type>::Array(unsigned int nb) : _array(new Type[nb]), _size(nb)
{
    FT_MSG("Array(unsigned int) Constructor")
}

template <typename Type>
Array<Type>::Array(Array const &copy) : _array(new Type[copy._size]), _size(copy._size)
{
	FT_MSG("Array(Array copy) Constructor")
    *this = copy;
}

template <typename Type>
Array<Type>::~Array()
{
	FT_MSG("~Array Destructor")
    delete[] _array;
}

/* !SECTION */

/* SECTION - methods */

template <typename Type>
unsigned int Array<Type>::size() const
{
    return (_size);
}

/* !SECTION */

/* SECTION - operators */

template <typename Type>
Array<Type> &Array<Type>::operator=(Array const &src)
{
    if (this != &src)
    {
        delete[] _array;
        _size = src._size;
        _array = new Type[_size];
        for (unsigned int i = 0; i < _size; i++)
            _array[i] = src._array[i];
    }

    return (*this);
}

template <typename Type>
Type &Array<Type>::operator[](unsigned int i)
{
    if (i >= _size)
        throw OutOfBoundsException();
    return (_array[i]);
}

template <typename Type>
Type const &Array<Type>::operator[](unsigned int i) const
{
    if (i >= _size)
        throw OutOfBoundsException();
    return (_array[i]);
}

/* !SECTION */

/* SECTION - exceptions */

template <typename Type>
const char *Array<Type>::OutOfBoundsException::what() const throw()
{
    return ("Index out of bounds");
}

/* !SECTION */

#endif