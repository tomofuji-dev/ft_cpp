#include "FragTrap.hpp"
#include <iostream>

#define R		"\033[31m"
#define G		"\033[32m"
#define Y		"\033[33m"
#define B		"\033[34m"
#define GRAY	"\033[m"
#define E		"\033[00m"

FragTrap::FragTrap(): ClapTrap() {
	_name = "";
	_hp = FragTrap::init_hp;
	_energy = FragTrap::init_energy;
	_damage = FragTrap::init_damage;
	std::cout << "FragTrap()" << std::endl;
	std::cout << *this << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	_name = name;
	_hp = FragTrap::init_hp;
	_energy = FragTrap::init_energy;
	_damage = FragTrap::init_damage;
	std::cout << "FragTrap(name)" << std::endl;
	std::cout << *this << std::endl;
}

FragTrap::FragTrap(const FragTrap &src): ClapTrap(src) {
	_name = src._name;
	_hp = src._hp;
	_energy = src._energy;
	_damage = src._damage;
	std::cout << "FragTrap(src)" << std::endl;
	std::cout << *this << std::endl;
}

FragTrap::~FragTrap(){
	std::cout << "~FragTrap()" << std::endl;
	std::cout << *this << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap &rhs){
	std::cout << "FragTrap oerator=" << std::endl;
	_name = rhs._name;
	_hp = rhs._hp;
	_energy = rhs._energy;
	_damage = rhs._damage;
	std::cout << *this << std::endl;
	return (*this);
}

void FragTrap::attack(const std::string& target) {
	if (_hp == 0 || _energy == 0) {
		std::cout << R
			<< "[FragTrap] " << _name << ":"
			<< " tempted to attack " << target
			<< " but it has no hp or energy"
			<< E << std::endl;
		std::cout << *this << std::endl;
		return ;
	}
	std::cout << Y
		<< "[FragTrap] " << _name << ":"
		<< " attack " << target
		<< " and caused " << _damage << " damage"
		<< E << std::endl;
}

void	FragTrap::highFivesGuys() {
	std::cout << B
		<< "[FragTrap] " << _name << ":"
		<< " highFivesGuys"
		<< E << std::endl;
}

std::ostream& operator<<(std::ostream& stream, const FragTrap& value) {
	return stream
			<< "    [FragTrap]"
			<< " name: " << value.get_name()
			<< " hp: " << value.get_hp()
			<< " energy: " << value.get_energy()
			<< " damage: " << value.get_damage();
}
