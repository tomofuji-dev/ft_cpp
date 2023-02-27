#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public Animal {

public:

	Dog();
	Dog(const Dog& src);
	~Dog();
	Dog& operator=(const Dog& rhs);

	void	makeSound() const;

private:

	Brain* brain_;

};

#endif
