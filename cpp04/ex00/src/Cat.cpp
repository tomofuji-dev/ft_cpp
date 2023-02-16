#include "Cat.hpp"
#include "iostream"

Cat::Cat() : Animal("Cat"){
	std::cout << "Cat()" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src) {
	std::cout << "Cat(src)" << std::endl;
}

Cat::~Cat(){
	std::cout << "~Cat()" << std::endl;
}

Cat&	Cat::operator=(const Cat &rhs){
	Animal::type_ = rhs.Animal::type_;
	return *this;
}

void	Cat::makeSound() const {
	std::cout << G << "MEOW~" << E << std::endl;
}
