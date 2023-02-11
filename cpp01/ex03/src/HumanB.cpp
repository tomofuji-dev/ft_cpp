/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:42:34 by t.fuji            #+#    #+#             */
/*   Updated: 2023/02/11 13:11:13 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB() : _name(""), _weapon(nullptr) {
}

HumanB::HumanB(std::string const name) : _name(name), _weapon(nullptr) {
}

HumanB::HumanB(std::string const name, Weapon* weapon) : _name(name), _weapon(weapon) {
}

HumanB::HumanB(HumanB const &src) : _name(src.getName()), _weapon(src.getWeapon()) {
}

HumanB::~HumanB() {
}

HumanB&	HumanB::operator=(HumanB const &rhs) {
	_name = rhs.getName();
	_weapon = rhs.getWeapon();
	return *this;
}

void	HumanB::attack() const {
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

std::string	HumanB::getName() const {
	return _name;
}

Weapon*	HumanB::getWeapon() const {
	return _weapon;
}

void	HumanB::setWeapon(Weapon& weapon) {
	_weapon = &weapon;
}
