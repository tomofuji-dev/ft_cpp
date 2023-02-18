#pragma once
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {

public:

	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &src);
	~ScavTrap();
	ScavTrap&	operator=(const ScavTrap &rhs);

	void attack(const std::string& target);
	void guardGate();

private:

	static const unsigned int init_hp = 100;
	static const unsigned int init_energy = 50;
	static const unsigned int init_damage = 20;

};

std::ostream& operator<<(std::ostream& stream, const ScavTrap& value);
