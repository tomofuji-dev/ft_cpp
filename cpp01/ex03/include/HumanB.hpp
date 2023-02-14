#pragma once
#include <string>
#include "Weapon.hpp"

class HumanB {

public:

	HumanB();
	HumanB(std::string const name);
	HumanB(std::string const name, Weapon* weapon);
	HumanB(HumanB const &src);
	~HumanB();
	HumanB&	operator=(HumanB const &rhs);

	void		attack() const;
	std::string	getName() const;
	Weapon*		getWeapon() const;
	void		setWeapon(Weapon& weapon);

private:
	std::string _name;
	Weapon*		_weapon;
};
