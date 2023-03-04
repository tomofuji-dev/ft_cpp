#include "Cure.hpp"
#include "Color.hpp"
#include <iostream>

const std::string Cure::materiaName_ = "cure";

Cure::Cure() : AMateria(materiaName_) {}

Cure::Cure(const Cure& src) : AMateria(src) {}

Cure::~Cure() {}

Cure&	Cure::operator=(const Cure& rhs) {
	AMateria::type_ = rhs.AMateria::type_;
	return *this;
}

Cure* Cure::clone() const {
	Cure*	new_cure;

	new_cure = new Cure(*this);
	std::cout << Y << "this: " << this << ", cloned: " << new_cure << E << std::endl;
	return new_cure;
};

void Cure::use(ICharacter& target) {
	std::cout << G << "* heals " << target.getName() << "’s wounds *" << E << std::endl;
};
