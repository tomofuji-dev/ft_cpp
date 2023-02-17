#include "Cat.hpp"
#include "iostream"

Cat::Cat() : Animal("Cat"), brain_(new Brain()){
	std::cout << "Cat()" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src) {
	std::cout << "Cat(src)" << std::endl;
	*this = src;
}

Cat::~Cat(){
	std::cout << "~Cat()" << std::endl;
	delete brain_;
}

Cat&	Cat::operator=(const Cat &rhs){
	Animal::type_ = rhs.Animal::type_;
	brain_ = rhs.brain_;
	return *this;
}

void	Cat::makeSound() const {
	std::cout << G << "MEOW~" << E << std::endl;
}
