#pragma once
#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Ice : public AMateria {

public:

	Ice();
	Ice(const Ice& src);
	~Ice();
	Ice&	operator=(const Ice& rhs);

	std::string const& getMateriaName() const;
	virtual Ice* clone() const;
	virtual void use(ICharacter& target);

private:

	static const std::string materiaName_;

};
