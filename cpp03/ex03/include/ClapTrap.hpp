#pragma once
#include <string>

#define R		"\033[31m"
#define G		"\033[32m"
#define Y		"\033[33m"
#define B		"\033[34m"
#define GRAY	"\033[m"
#define E		"\033[00m"

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

	static const unsigned int init_hp = 10;
	static const unsigned int init_energy = 10;
	static const unsigned int init_damage = 0;
	
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
