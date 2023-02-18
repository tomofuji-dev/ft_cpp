#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap():
	ClapTrap("NONAME_clap_name"), FragTrap(), ScavTrap(), _name("NONAME")
{
	_hp = init_hp;
	_energy = init_energy;
	_damage = init_damage;
	std::cout << "DiamondTrap()" << std::endl;
	std::cout << *this << std::endl;
}

DiamondTrap::DiamondTrap(std::string name):
	ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	_hp = init_hp;
	_energy = init_energy;
	_damage = init_damage;
	std::cout << "DiamondTrap(name)" << std::endl;
	std::cout << *this << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src):
	ClapTrap(src), FragTrap(src), ScavTrap(src), _name(src._name)
{
	_hp = src._hp;
	_energy = src._energy;
	_damage = src._damage;
	std::cout << "DiamondTrap(src)" << std::endl;
	std::cout << *this << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "~FragTrap()" << std::endl;
	std::cout << *this << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &rhs){
	std::cout << "DiamondTrap oerator=" << std::endl;
	_name = rhs._name;
	ClapTrap::_name = rhs.ClapTrap::_name;
	_hp = rhs._hp;
	_energy = rhs._energy;
	_damage = rhs._damage;
	std::cout << *this << std::endl;
	return (*this);
}

std::string		DiamondTrap::get_name() const {
	return _name;
}

void DiamondTrap::attack(const std::string& target) {
	std::cout << Y << "DiamondTrap attack call ScavTrap::atack()" << E << std::endl;
	this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() const {
	std::cout << B
		<< "[DiamondTrap] " << _name << ":"
		<< " whoAmI\n"
		<< "    diamond name: " << _name 
		<< "    claptrap name: " << ClapTrap::_name
		<< E << std::endl;
}

std::ostream& operator<<(std::ostream& stream, const DiamondTrap& value) {
	return stream
		<< "    [DiamondTrap]"
		<< " | diamond name: " << value.DiamondTrap::get_name()
		<< " | claptrap name: " << value.ClapTrap::get_name()
		<< " | hp: " << value.get_hp()
		<< " | energy: " << value.get_energy()
		<< " | damage: " << value.get_damage();
}
