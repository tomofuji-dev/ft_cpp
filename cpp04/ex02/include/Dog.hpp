#pragma once
#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public Animal {

public:

	Dog();
	Dog(const Dog& src);
	~Dog();
	Dog& operator=(const Dog& rhs);

	void			makeSound() const;
	const Brain*	getBrain() const;

private:

	Brain* brain_;

};
