/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: t.fuji <t.fuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:01:43 by t.fuji            #+#    #+#             */
/*   Updated: 2023/02/10 11:20:56 by t.fuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	Zombie	z("stack");
	z.announce();
	
	Zombie *heap = newZombie("heap");
	heap->announce();
	delete heap;

	randomChump("randomChump");
	return (0);
}
