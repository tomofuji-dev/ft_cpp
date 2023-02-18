#pragma once
#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Cure : public AMateria {

public:

	Cure();
	Cure(const Cure& src);
	~Cure();
	Cure&	operator=(const Cure& rhs);

	std::string const& getMateriaName() const;
	Cure* clone() const;
	void use(ICharacter& target);

private:

	static const std::string materiaName_;

};
