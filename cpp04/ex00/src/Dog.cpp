#include "Dog.hpp"
#include "iostream"

Dog::Dog() : Animal("Dog"){
	std::cout << "Dog()" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src) {
	std::cout << "Dog(src)" << std::endl;
}

Dog::~Dog(){
	std::cout << "~Dog()" << std::endl;
}

Dog&	Dog::operator=(const Dog &rhs){
	Animal::type_ = rhs.Animal::type_;
	return *this;
}

void	Dog::makeSound() const {
	std::cout << Y << "BOWWOW!" << E << std::endl;
}
