#include "MateriaSource.hpp"
#include "Color.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
	for (size_t i = 0; i < nSlots_; i++) {
		materiaSourceSlots_[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& src) {
	for (size_t i = 0; i < nSlots_; i++) {
		materiaSourceSlots_[i] = NULL;
	}
	*this = src;
}

MateriaSource::~MateriaSource() {
	for (size_t i = 0; i < nSlots_; i++) {
		delete materiaSourceSlots_[i];
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& rhs) {
	for (size_t i = 0; i < nSlots_; i++) {
		delete materiaSourceSlots_[i];
		if (rhs.materiaSourceSlots_[i])
			materiaSourceSlots_[i] = rhs.materiaSourceSlots_[i]->clone();
		else
			materiaSourceSlots_[i] = NULL;
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* materia) {
	size_t idx = get_empty_index();
	
	if (idx == nSlots_) {
		std::cout << R << "[ERROR] learnMateria: " << "MateriaSource\'s slot is full" << E << std::endl;
		return ;
	}
	materiaSourceSlots_[idx] = materia;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	size_t idx = search_index(type);

	if (idx == nSlots_) {
		std::cout << R << "[ERROR] createMateria: " << "MateriaSource don\'t have " << type << E << std::endl;
		return NULL;
	}
	return materiaSourceSlots_[idx]->clone();
}

size_t MateriaSource::get_empty_index() const {
	size_t i = 0;
	for (; i < nSlots_; i++) {
		if (materiaSourceSlots_[i] == NULL)
			break ;
	}
	return i;
}

size_t MateriaSource::search_index(const std::string& type) const {
	size_t i = 0;
	for (; i < nSlots_; i++) {
		if (materiaSourceSlots_[i] && materiaSourceSlots_[i]->getType() == type)
			break ;
	}
	return i;
}
