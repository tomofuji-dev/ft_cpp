#pragma once
#include <string>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

public:

	MateriaSource();
	MateriaSource(const MateriaSource& src);
	~MateriaSource();
	MateriaSource&	operator=(const MateriaSource& rhs);

	void learnMateria(AMateria* materia);
	AMateria* createMateria(std::string const & type);

private:

	const static size_t nSlots_ = 4;
	AMateria* materiaSourceSlots_[nSlots_];

	size_t get_empty_index() const;
	size_t search_index(const std::string& type) const;
};
