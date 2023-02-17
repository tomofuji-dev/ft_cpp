#pragma once
#include "WrongAnimal.hpp"
#include <string>

class WrongCat : public WrongAnimal {

public:

	WrongCat();
	WrongCat(const WrongCat &src);
	~WrongCat();
	WrongCat& operator=(const WrongCat &rhs);

	void	makeSound() const;

};
