#pragma once
#include <string>
#include "AMateria.hpp"

class MateriaSource {

public:

	MateriaSource();
	MateriaSource(const MateriaSource& src);
	~MateriaSource();
	MateriaSource&	operator=(const MateriaSource& rhs);

	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;

private:

	const static size_t nSlots_ = 4;
	AMateria* MateriaSourceSlots[nSlots_];

};
