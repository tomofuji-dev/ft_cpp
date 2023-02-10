/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: t.fuji <t.fuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:41:56 by t.fuji            #+#    #+#             */
/*   Updated: 2023/02/10 14:00:43 by t.fuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Weapon {

public:

	Weapon();
	Weapon(std::string const type);
	Weapon(Weapon const &src);
	~Weapon();
	Weapon&	operator=(Weapon const &rhs);

	std::string	getType() const;
	void		setType(std::string src);

private:
	std::string _type;
};
