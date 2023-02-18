#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : type_("") {
	std::cout << "AMateria()" << std::endl;
}

AMateria::AMateria(const std::string& type) : type_(type) {
	std::cout << "AMateria(type)" << std::endl;
}

AMateria::AMateria(const AMateria& src) : type_(src.type_){
	std::cout << "AMateria(src)" << std::endl;
}

AMateria::~AMateria() {
	std::cout << "~AMateria()" << std::endl;
}

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

