#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string const name, Weapon& weapon) : _name(name), _weapon(weapon) {
}

HumanA::HumanA(const HumanA& src) : _name(src._name), _weapon(src._weapon) {
}

HumanA::~HumanA() {
}

HumanA&	HumanA::operator=(const HumanA& rhs) {
	_name = rhs.getName();
	_weapon = rhs.getWeapon();
	return *this;
}

void	HumanA::attack() const {
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}

std::string	HumanA::getName() const {
	return _name;
}

Weapon&	HumanA::getWeapon() const {
	return _weapon;
}