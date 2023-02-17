#include "WrongAnimal.hpp"
#include "iostream"

WrongAnimal::WrongAnimal() : type_("") {
	std::cout << "WrongAnimal()" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string type) : type_(type) {
	std::cout << "WrongAnimal(type)" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src) : type_(src.type_) {
	std::cout << "WrongAnimal(src)" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "~WrongAnimal()" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& rhs) {
	type_ = rhs.type_;
	return *this;
}

const std::string&	WrongAnimal::getType() const {
	return type_;
}

void	WrongAnimal::makeSound() const {
	std::cout << B << "............." << E << std::endl;
}
