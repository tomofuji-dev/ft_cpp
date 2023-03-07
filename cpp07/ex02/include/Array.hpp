#pragma once
# include <iostream>
# include <exception>

template <class T>
class Array {

public:

	Array(unsigned int size = 0);
	Array(const Array& src);
	~Array();
	Array&		operator=(const Array& rhs);
	T&			operator[](const std::size_t i);
	const T&	operator[](const std::size_t i) const;

	unsigned int	size() const;

private:

	unsigned int	size_;
	T*				content_;

};

#include "Array.tpp"
