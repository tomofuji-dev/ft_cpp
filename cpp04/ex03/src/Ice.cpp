#include "Ice.hpp"
#include "Color.hpp"
#include <iostream>

const std::string Ice::materiaName_ = "ice";

Ice::Ice() : AMateria(materiaName_) {
	std::cout << "Ice()" << std::endl;
}

Ice::Ice(const Ice& src) : AMateria(src) {
	std::cout << "Ice(src)" << std::endl;
}

Ice::~Ice() {
	std::cout << "~Ice()" << std::endl;
}

Ice&	Ice::operator=(const Ice& rhs) {
	AMateria::type_ = rhs.AMateria::type_;
	return *this;
}

Ice* Ice::clone() const {
	Ice*	new_Ice;

	new_Ice = new Ice(*this);
	return new_Ice;
};

void Ice::use(ICharacter& target) {
	std::cout << B << "* shoots an ice bolt at " << target.getName() << " *" << E << std::endl;
};
