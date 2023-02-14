#pragma once
#include <string>

class ClapTrap {

public:

	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &src);
	~ClapTrap();
	ClapTrap&	operator=(const ClapTrap &rhs);

	std::string		get_name() const;
	unsigned int	get_hp() const;
	unsigned int	get_energy() const;
	unsigned int	get_damage() const;
	
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

protected:
	std::string 	_name;
	unsigned int	_hp;
	unsigned int	_energy;
	unsigned int	_damage;
};

std::ostream& operator<<(std::ostream& stream, const ClapTrap& value);
