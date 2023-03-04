#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog"), brain_(new Brain()) {
	std::cout << "Dog()" << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src), brain_(NULL) {
	std::cout << "Dog(src)" << std::endl;
	*this = src;
}

Dog::~Dog(){
	std::cout << "~Dog()" << std::endl;
	delete brain_;
}

Dog&	Dog::operator=(const Dog& rhs){
	Brain* tmp = brain_;
	type_ = rhs.type_;
	brain_ = new Brain(*rhs.brain_);
	delete tmp;
	return *this;
}

void	Dog::makeSound() const {
	std::cout << Y << "BOWWOW!" << E << std::endl;
}

const Brain*	Dog::getBrain() const {
	return brain_;
}
