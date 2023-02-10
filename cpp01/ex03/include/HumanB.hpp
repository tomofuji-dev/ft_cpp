/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: t.fuji <t.fuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:36:57 by t.fuji            #+#    #+#             */
/*   Updated: 2023/02/10 14:30:39 by t.fuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include "Weapon.hpp"

class HumanB {

public:

	HumanB();
	HumanB(std::string const name);
	HumanB(std::string const name, Weapon* weapon);
	HumanB(HumanB const &src);
	~HumanB();
	HumanB&	operator=(HumanB const &rhs);

	void		attack() const;
	std::string	getName() const;
	Weapon*		getWeapon() const;
	void		setWeapon(Weapon* weapon);
	void		setWeapon(Weapon weapon);

private:
	std::string _name;
	Weapon*		_weapon;
};
