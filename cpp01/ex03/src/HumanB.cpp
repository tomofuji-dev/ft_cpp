#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB() : _name(""), _weapon(NULL) {
}

HumanB::HumanB(std::string const name) : _name(name), _weapon(NULL) {
}

HumanB::HumanB(std::string const name, Weapon* weapon) : _name(name), _weapon(weapon) {
}

HumanB::HumanB(const HumanB& src) : _name(src._name), _weapon(src._weapon) {
}

HumanB::~HumanB() {
}

HumanB&	HumanB::operator=(const HumanB& rhs) {
	_name = rhs.getName();
	_weapon = rhs.getWeapon();
	return *this;
}

void	HumanB::attack() const {
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

std::string	HumanB::getName() const {
	return _name;
}

Weapon*	HumanB::getWeapon() const {
	return _weapon;
}

void	HumanB::setWeapon(Weapon& weapon) {
	_weapon = &weapon;
}
