#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type_("") {
	std::cout << "Animal()" << std::endl;
}

Animal::Animal(const std::string type) : type_(type) {
	std::cout << "Animal(type)" << std::endl;
}

Animal::Animal(const Animal& src) : type_(src.type_) {
	std::cout << "Animal(src)" << std::endl;
}

Animal::~Animal() {
	std::cout << "~Animal()" << std::endl;
}

Animal&	Animal::operator=(const Animal& rhs) {
	if (this == &rhs) {
		return *this;
	}
	type_ = rhs.type_;
	return *this;
}

const std::string&	Animal::getType() const {
	return type_;
}

void	Animal::makeSound() const {
	std::cout << B << "............." << E << std::endl;
}
