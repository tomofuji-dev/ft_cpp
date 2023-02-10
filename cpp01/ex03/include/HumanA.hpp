/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: t.fuji <t.fuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:36:57 by t.fuji            #+#    #+#             */
/*   Updated: 2023/02/10 14:13:21 by t.fuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include "Weapon.hpp"

class HumanA {

public:

	HumanA(std::string const name, Weapon& weapon);
	HumanA(HumanA const &src);
	~HumanA();
	HumanA&	operator=(HumanA const &rhs);

	void		attack() const;
	std::string	getName() const;
	Weapon&		getWeapon() const;

private:
	std::string _name;
	Weapon&		_weapon;
};
