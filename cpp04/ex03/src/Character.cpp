#include "Character.hpp"
#include "Color.hpp"
#include <iostream>
#include <cstdlib>

Character::Character() : name_("") {
	std::cout << "Character()" << std::endl;
	for (size_t i = 0; i < nSlots_; i++) {
		characterSlots_[i] = nullptr;
	}
}

Character::Character(const std::string& name) : name_(name) {
	std::cout << "Character(name)" << std::endl;
	for (size_t i = 0; i < nSlots_; i++) {
		characterSlots_[i] = nullptr;
	}
}

Character::Character(const Character& src) : name_(src.name_) {
	std::cout << "Character(src)" << std::endl;
	*this = src;
}

Character::~Character() {
	std::cout << "~Character()" << std::endl;
	for (size_t i = 0; i < nSlots_; i++) {
		delete characterSlots_[i];
	}
}

Character&	Character::operator=(const Character& rhs) {
	name_ = rhs.name_;
	for (size_t i = 0; i < nSlots_; i++) {
		delete characterSlots_[i];
		if (rhs.characterSlots_[i])
			characterSlots_[i] = rhs.characterSlots_[i]->clone();
		else
			characterSlots_[i] = nullptr;
		std::cout << Y << "this[i]: " << characterSlots_[i] << ", rhs[i]: " << rhs.characterSlots_[i] << E << std::endl;
	}
	return *this;
}

std::string const& Character::getName() const {
	return name_;
}

void Character::equip(AMateria* m) {
	std::cout << name_ << " equip " << m->getType() << std::endl;
	const size_t idx = get_empty_index();

	if (idx == nSlots_) {
		std::cout << R << "[ERROR] " << name_ << "\'s slot is full" << E << std::endl;
		return ;
	}

	characterSlots_[idx] = m;
}

void Character::unequip(int idx) {
	std::cout << name_ << " unequip " << idx << " slot" << std::endl;
	if (characterSlots_[idx] == nullptr) {
		std::cout << R << "[ERROR] " << name_ << "\'s slot[" << idx << "] is empty" << E << std::endl;
		return ;
	}
	characterSlots_[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target) {
	if (!(0 <= idx && (size_t)idx < nSlots_)) {
		std::cout << R << "[ERROR] idx is out of range" << E << std::endl;
		return ;
	}
	if (characterSlots_[idx] == nullptr) {
		std::cout << R << "[ERROR] " << name_ << "\'s slot[" << idx << "] is empty" << E << std::endl;
		return ;
	}
	characterSlots_[idx]->use(target);
}

size_t Character::get_empty_index() const {
	size_t i = 0;
	for (; i < nSlots_; i++) {
		if (characterSlots_[i] == nullptr)
			break ;
	}
	return i;
}
