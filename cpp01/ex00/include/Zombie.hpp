#pragma once

#include<string>

class Zombie {

public:

	Zombie();
	Zombie(std::string);
	Zombie(const Zombie& src);
	~Zombie();
	Zombie&	operator=(const Zombie& rhs);

	void		announce() const;
	std::string	getName() const;

private:

	std::string	_name;

};

Zombie* newZombie( std::string name );
void 	randomChump( std::string name );
