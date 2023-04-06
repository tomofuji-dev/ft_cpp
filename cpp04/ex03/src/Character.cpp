#include "Character.hpp"
#include "Color.hpp"
#include <iostream>
#include <cstdlib>

Character::Character() : name_("") {
	for (size_t i = 0; i < nSlots_; i++) {
		characterSlots_[i] = NULL;
	}
}

Character::Character(const std::string& name) : name_(name) {
	for (size_t i = 0; i < nSlots_; i++) {
		characterSlots_[i] = NULL;
	}
}

Character::Character(const Character& src) : name_(src.name_) {
	for (size_t i = 0; i < nSlots_; i++) {
		characterSlots_[i] = NULL;
	}
	*this = src;
}

Character::~Character() {
	for (size_t i = 0; i < nSlots_; i++) {
		delete characterSlots_[i];
	}
}

Character&	Character::operator=(const Character& rhs) {
	if (this == &rhs) {
		return *this;
	}
	name_ = rhs.name_;
	for (size_t i = 0; i < nSlots_; i++) {
		delete characterSlots_[i];
		if (rhs.characterSlots_[i])
			characterSlots_[i] = rhs.characterSlots_[i]->clone();
		else
			characterSlots_[i] = NULL;
	}
	return *this;
}

std::string const& Character::getName() const {
	return name_;
}

void Character::equip(AMateria* m) {
	const size_t idx = get_empty_index();

	if (idx == nSlots_) {
		std::cout << R << "[ERROR] equip: " << name_ << "\'s slot is full" << E << std::endl;
		return ;
	}

	characterSlots_[idx] = m;
}

void Character::unequip(int idx) {
	if (characterSlots_[idx] == NULL) {
		std::cout << R << "[ERROR] unequip: " << name_ << "\'s slot[" << idx << "] is empty" << E << std::endl;
		return ;
	}
	characterSlots_[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (!(0 <= idx && (size_t)idx < nSlots_)) {
		std::cout << R << "[ERROR] use: idx is out of range" << E << std::endl;
		return ;
	}
	if (characterSlots_[idx] == NULL) {
		std::cout << R << "[ERROR] use:" << name_ << "\'s slot[" << idx << "] is empty" << E << std::endl;
		return ;
	}
	characterSlots_[idx]->use(target);
}

size_t Character::get_empty_index() const {
	size_t i = 0;
	for (; i < nSlots_; i++) {
		if (characterSlots_[i] == NULL)
			break ;
	}
	return i;
}
