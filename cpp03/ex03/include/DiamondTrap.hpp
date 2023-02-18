#pragma once
#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {

public:

	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &src);
	~DiamondTrap();
	DiamondTrap&	operator=(const DiamondTrap &rhs);

	std::string		get_name() const;
	void attack(const std::string& target);
	void whoAmI() const;

private:

	std::string _name;
	static const unsigned int init_hp = FragTrap::init_hp;
	static const unsigned int init_energy = ScavTrap::init_energy;
	static const unsigned int init_damage = FragTrap::init_damage;

};

std::ostream& operator<<(std::ostream& stream, const DiamondTrap& value);
