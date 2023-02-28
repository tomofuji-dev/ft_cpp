#include "Ice.hpp"
#include "Color.hpp"
#include <iostream>

const std::string Ice::materiaName_ = "ice";

Ice::Ice() : AMateria(materiaName_) {}

Ice::Ice(const Ice& src) : AMateria(src) {}

Ice::~Ice() {}

Ice&	Ice::operator=(const Ice& rhs) {
	AMateria::type_ = rhs.AMateria::type_;
	return *this;
}

Ice* Ice::clone() const {
	Ice*	new_ice;

	new_ice = new Ice(*this);
	std::cout << Y << "this: " << this << ", cloned: " << new_ice << E << std::endl;
	return new_ice;
};

void Ice::use(ICharacter& target) {
	std::cout << B << "* shoots an ice bolt at " << target.getName() << " *" << E << std::endl;
};
