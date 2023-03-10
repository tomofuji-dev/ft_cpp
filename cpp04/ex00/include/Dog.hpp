#pragma once
#include "Animal.hpp"
#include <string>

class Dog : public Animal {

public:

	Dog();
	Dog(const Dog& src);
	~Dog();
	Dog& operator=(const Dog& rhs);

	void	makeSound() const;

};
