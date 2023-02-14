#pragma once
#include <string>
#include "Weapon.hpp"

class HumanA {

public:

	HumanA(std::string const name, Weapon& weapon);
	HumanA(HumanA const &src);
	~HumanA();
	HumanA&	operator=(HumanA const &rhs);

	void		attack() const;
	std::string	getName() const;
	Weapon&		getWeapon() const;

private:
	std::string _name;
	Weapon&		_weapon;
};
