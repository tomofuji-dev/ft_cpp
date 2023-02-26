#pragma once
#include <string>

class Weapon {

public:

	Weapon();
	Weapon(std::string const type);
	Weapon(const Weapon& src);
	~Weapon();
	Weapon&	operator=(const Weapon& rhs);

	std::string	getType() const;
	void		setType(std::string src);

private:
	std::string _type;
};
