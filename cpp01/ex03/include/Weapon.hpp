#pragma once
#include <string>

class Weapon {

public:

	Weapon();
	Weapon(std::string const type);
	Weapon(Weapon const &src);
	~Weapon();
	Weapon&	operator=(Weapon const &rhs);

	std::string	getType() const;
	void		setType(std::string src);

private:
	std::string _type;
};
