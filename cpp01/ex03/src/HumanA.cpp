/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: t.fuji <t.fuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:42:34 by t.fuji            #+#    #+#             */
/*   Updated: 2023/02/10 14:15:11 by t.fuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string const name, Weapon& weapon) : _name(name), _weapon(weapon) {
}

HumanA::HumanA(HumanA const &src) : _name(src.getName()), _weapon(src.getWeapon()) {
}

HumanA::~HumanA() {
}

HumanA&	HumanA::operator=(HumanA const &rhs) {
	_name = rhs.getName();
	_weapon = rhs.getWeapon();
	return *this;
}

void	HumanA::attack() const {
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}

std::string	HumanA::getName() const {
	return _name;
}

Weapon&	HumanA::getWeapon() const {
	return _weapon;
}