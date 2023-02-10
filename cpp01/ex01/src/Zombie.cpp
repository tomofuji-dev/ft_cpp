/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: t.fuji <t.fuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:42:46 by t.fuji            #+#    #+#             */
/*   Updated: 2023/02/10 14:01:19 by t.fuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : _name(std::string()) {
	std::cout << "constructor: " << _name << std::endl;
}

Zombie::Zombie(std::string const name) : _name(name) {
	std::cout << "constructor: " << _name << std::endl;
}

Zombie::Zombie(Zombie const &src) : _name(src.getName()){
	std::cout << "copy constructor: " << _name << std::endl;
}

Zombie::~Zombie() {
	std::cout << "destructor: " << _name << std::endl;
}

Zombie&	Zombie::operator=(Zombie const &rhs) {
	_name = rhs.getName();
	return *this;
}

std::string	Zombie::getName() const {
	return _name;
}

void	Zombie::setName(std::string name) {
	_name = name;
}

void	Zombie::announce() const {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
