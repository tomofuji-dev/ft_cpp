#pragma once

#include<string>

class Zombie {

public:

	Zombie();
	Zombie(std::string);
	Zombie(Zombie const & src);
	~Zombie();
	Zombie&	operator=(Zombie const &rhs);

	void		announce() const;
	std::string	getName() const;

private:

	std::string	_name;

};

Zombie* newZombie( std::string name );
void 	randomChump( std::string name );
