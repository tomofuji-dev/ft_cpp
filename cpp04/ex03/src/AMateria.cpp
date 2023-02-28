#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : type_("") {}

AMateria::AMateria(const std::string& type) : type_(type) {}

AMateria::AMateria(const AMateria& src) : type_(src.type_) {}

AMateria::~AMateria() {}

AMateria&	AMateria::operator=(const AMateria& rhs) {
	type_ = rhs.type_;
	return *this;
}

std::string const& AMateria::getType() const {
	return type_;
};

void AMateria::use(ICharacter& target) {
	std::cout << "AMateria.use(" << target.getName() << ")" << std::endl;
};

