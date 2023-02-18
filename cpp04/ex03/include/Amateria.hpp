#pragma once
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria{

public:

	AMateria();
	AMateria(const std::string& type);
	AMateria(const AMateria& src);
	virtual ~AMateria();
	AMateria&	operator=(const AMateria& rhs);

	std::string const& getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

protected:

	std::string type_;

};
