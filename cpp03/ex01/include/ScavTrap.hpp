#pragma once
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:

	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &src);
	~ScavTrap();
	ScavTrap&	operator=(const ScavTrap &rhs);

	void attack(const std::string& target);
	void guardGate();
};

std::ostream& operator<<(std::ostream& stream, const ScavTrap& value);
