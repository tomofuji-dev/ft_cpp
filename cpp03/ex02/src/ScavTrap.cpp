#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(): ClapTrap() {
	_hp = ScavTrap::init_hp;
	_energy = ScavTrap::init_energy;
	_damage = ScavTrap::init_damage;
	std::cout << "ScavTrap()" << std::endl;
	std::cout << *this << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	_hp = ScavTrap::init_hp;
	_energy = ScavTrap::init_energy;
	_damage = ScavTrap::init_damage;
	std::cout << "ScavTrap(name)" << std::endl;
	std::cout << *this << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src): ClapTrap(src) {
	_hp = src._hp;
	_energy = src._energy;
	_damage = src._damage;
	std::cout << "ScavTrap(src)" << std::endl;
	std::cout << *this << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "~ScavTrap()" << std::endl;
	std::cout << *this << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &rhs){
	std::cout << "ScavTrap oerator=" << std::endl;
	_name = rhs._name;
	_hp = rhs._hp;
	_energy = rhs._energy;
	_damage = rhs._damage;
	std::cout << *this << std::endl;
	return (*this);
}

void ScavTrap::attack(const std::string& target) {
	if (_hp == 0 || _energy == 0) {
		std::cout << R
			<< "[ScavTrap] " << _name << ":"
			<< " tempted to attack " << target
			<< " but it has no hp or energy"
			<< E << std::endl;
		std::cout << *this << std::endl;
		return ;
	}
	std::cout << Y
		<< "[ScavTrap] " << _name << ":"
		<< " attack " << target
		<< " and caused " << _damage << " damage"
		<< E << std::endl;
}

void	ScavTrap::guardGate() {
	std::cout << B
		<< "[ScavTrap] " << _name << ":"
		<< " guardGate"
		<< E << std::endl;
}

std::ostream& operator<<(std::ostream& stream, const ScavTrap& value) {
	return stream
			<< "    [ScavTrap]"
			<< " | name: " << value.get_name()
			<< " | hp: " << value.get_hp()
			<< " | energy: " << value.get_energy()
			<< " | damage: " << value.get_damage();
}
