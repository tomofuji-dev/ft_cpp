#include "WrongCat.hpp"
#include "iostream"

WrongCat::WrongCat() : WrongAnimal("WrongCat"){
	std::cout << "WrongCat()" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src) {
	std::cout << "WrongCat(src)" << std::endl;
}

WrongCat::~WrongCat(){
	std::cout << "~WrongCat()" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat &rhs){
	WrongAnimal::type_ = rhs.WrongAnimal::type_;
	return *this;
}

void	WrongCat::makeSound() const {
	std::cout << G << "MEOW~" << E << std::endl;
}
