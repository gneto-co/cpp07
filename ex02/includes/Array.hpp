#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "Strings.h"

template <typename Type>
class Array
{
private:
	/* attributes */
	Type *_array;
	unsigned int _size;

public:
	/* constructors destructors */
	Array();
	Array(unsigned int n);
	Array(const Array &copy);
	~Array();

	/* methods */
	unsigned int size() const;

	/* operators */
	Array &operator=(const Array &src);
	Type &operator[](unsigned int i);
	Type const &operator[](unsigned int i) const;

	/* exceptions */
	class OutOfBoundsException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};
#include "Array.tpp"

#endif