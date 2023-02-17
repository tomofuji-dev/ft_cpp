#pragma once
#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public Animal {

public:

	Cat();
	Cat(const Cat& src);
	~Cat();
	Cat& operator=(const Cat& rhs);

	void	makeSound() const;

private:

	Brain* brain_;

};
