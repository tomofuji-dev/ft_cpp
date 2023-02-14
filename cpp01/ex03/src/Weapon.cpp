#include "Weapon.hpp"

Weapon::Weapon() : _type("") {
}

Weapon::Weapon(std::string const type) : _type(type) {
}

Weapon::Weapon(Weapon const &src) : _type(src.getType()){
}

Weapon::~Weapon() {
}

Weapon&	Weapon::operator=(Weapon const &rhs) {
	_type = rhs.getType();
	return *this;
}

std::string	Weapon::getType() const {
	return _type;
}

void	Weapon::setType(std::string src) {
	_type = src;
}