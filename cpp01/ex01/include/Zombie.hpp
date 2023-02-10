/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: t.fuji <t.fuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:41:56 by t.fuji            #+#    #+#             */
/*   Updated: 2023/02/10 14:01:10 by t.fuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include<string>

class Zombie {

public:

	Zombie();
	Zombie(std::string const name);
	Zombie(Zombie const & src);
	~Zombie();
	Zombie&	operator=(Zombie const &rhs);

	void		announce() const;
	std::string	getName() const;
	void		setName(std::string name);

private:

	std::string	_name;

};

Zombie* zombieHorde( int N, std::string name );
