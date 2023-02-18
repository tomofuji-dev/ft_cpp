#pragma once
#include <string>
#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {

public:

	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &src);
	~FragTrap();
	FragTrap&	operator=(const FragTrap &rhs);

	void attack(const std::string& target);
	void highFivesGuys();

private:
	static const unsigned int init_hp = 100;
	static const unsigned int init_energy = 100;
	static const unsigned int init_damage = 30;

};

std::ostream& operator<<(std::ostream& stream, const FragTrap& value);
