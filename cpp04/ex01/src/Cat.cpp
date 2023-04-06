#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat"), brain_(new Brain()){
	std::cout << "Cat()" << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src), brain_(NULL) {
	std::cout << "Cat(src)" << std::endl;
	*this = src;
}

Cat::~Cat(){
	std::cout << "~Cat()" << std::endl;
	delete brain_;
}

Cat&	Cat::operator=(const Cat& rhs){
	if (this == &rhs) {
		return *this;
	}
	Brain* tmp = brain_;
	type_ = rhs.type_;
	brain_ = new Brain(*rhs.brain_);
	delete tmp;
	return *this;
}

void	Cat::makeSound() const {
	std::cout << G << "MEOW~" << E << std::endl;
}

const Brain*	Cat::getBrain() const {
	return brain_;
}
