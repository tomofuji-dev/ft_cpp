#pragma once
#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : ICharacter {

public:

	Character();
	Character(const Character& src);
	Character(const std::string& name);
	~Character();
	Character&	operator=(const Character& rhs);

	std::string const& getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

private:

	std::string name_;

	const static size_t nSlots_ = 4;
	AMateria* characterSlots_[nSlots_];

	size_t get_empty_index() const;

};
