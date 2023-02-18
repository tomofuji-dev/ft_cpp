#include "Dog.hpp"
#include "iostream"

Dog::Dog() : Animal("Dog"), brain_(new Brain()) {
	std::cout << "Dog()" << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src) {
	std::cout << "Dog(src)" << std::endl;
	*this = src;
}

Dog::~Dog(){
	std::cout << "~Dog()" << std::endl;
	delete brain_;
}

Dog&	Dog::operator=(const Dog& rhs){
	Animal::type_ = rhs.Animal::type_;
	brain_ = rhs.brain_;
	return *this;
}

void	Dog::makeSound() const {
	std::cout << Y << "BOWWOW!" << E << std::endl;
}