#include "ClapTrap.hpp"
#include <iostream>

#define R		"\033[31m"
#define G		"\033[32m"
#define Y		"\033[33m"
#define B		"\033[34m"
#define GRAY	"\033[m"
#define E		"\033[00m"

ClapTrap::ClapTrap(): 
	_name(""), _hp(ClapTrap::init_hp), 
	_energy(ClapTrap::init_energy), _damage(ClapTrap::init_damage)
{
	std::cout << "ClapTrap()" << std::endl;
	std::cout << *this << std::endl;
}

ClapTrap::ClapTrap(std::string name) : 
	_name(name), _hp(ClapTrap::init_hp), 
	_energy(ClapTrap::init_energy), _damage(ClapTrap::init_damage)
{
		std::cout << "ClapTrap(name)" << std::endl;
		std::cout << *this << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src):
	_name(src._name), _hp(src._hp), _energy(src._energy), _damage(src._damage){
	std::cout << "ClapTrap(src)" << std::endl;
	std::cout << *this << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << "~ClapTrap()" << std::endl;
	std::cout << *this << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &rhs){
	std::cout << "ClapTrap oerator=" << std::endl;
	_name = rhs._name;
	_hp = rhs._hp;
	_energy = rhs._energy;
	_damage = rhs._damage;
	std::cout << *this << std::endl;
	return (*this);
}

std::string		ClapTrap::get_name() const {
	return _name;
}

unsigned int	ClapTrap::get_hp() const {
	return _hp;
}

unsigned int	ClapTrap::get_energy() const {
	return _energy;
}

unsigned int	ClapTrap::get_damage() const {
	return _damage;
}

void ClapTrap::attack(const std::string& target) {
	if (_hp == 0 || _energy == 0) {
		std::cout << R
			<< "[ClapTrap] " << _name << ":"
			<< " tempted to attack " << target
			<< " but it has no hp or energy"
			<< E << std::endl;
		std::cout << *this << std::endl;
		return ;
	}
	std::cout << Y
		<< "[ClapTrap] " << _name << ":"
		<< " attack " << target
		<< " and caused " << _damage << " damage"
		<< E << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hp == 0) {
		std::cout << R
		<< "[ClapTrap] " << _name << ":"
		<< " takeDamege " << amount
		<< ", but it has no hp" 
		<< E << std::endl;
		std::cout << *this << std::endl;
		return ;
	}
	if (_hp < amount) {
		amount = _hp;
	}
	_hp -= amount;
	std::cout << B
		<< "[ClapTrap] " << _name << ":"
		<< " takeDamege " << amount 
		<< E << std::endl;
	std::cout << *this << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	_hp += amount;
	std::cout << G
		<< "[ClapTrap] " << _name  << ":"
		<< " beReparied " << amount
		<< E << std::endl;
	std::cout << *this << std::endl;
}

std::ostream& operator<<(std::ostream& stream, const ClapTrap& value) {
	return stream
			<< "    [ClapTrap]"
			<< " name: " << value.get_name()
			<< " hp: " << value.get_hp()
			<< " energy: " << value.get_energy()
			<< " damage: " << value.get_damage();
}
