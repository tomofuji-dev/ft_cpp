/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: t.fuji <t.fuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:30:01 by t.fuji            #+#    #+#             */
/*   Updated: 2023/02/10 14:02:51 by t.fuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() : _type("") {
}

Weapon::Weapon(std::string const type) : _type(type) {
}

Weapon::Weapon(Weapon const &src) : _type(src.getType()){
}

Weapon::~Weapon() {
}

Weapon&	Weapon::operator=(Weapon const &rhs) {
	_type = rhs.getType();
	return *this;
}

std::string	Weapon::getType() const {
	return _type;
}

void	Weapon::setType(std::string src) {
	_type = src;
}