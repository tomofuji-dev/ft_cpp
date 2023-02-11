/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:36:57 by t.fuji            #+#    #+#             */
/*   Updated: 2023/02/11 13:09:21 by tfujiwar         ###   ########.fr       */
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
	void		setWeapon(Weapon& weapon);

private:
	std::string _name;
	Weapon*		_weapon;
};
