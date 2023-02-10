/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: t.fuji <t.fuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:38:41 by t.fuji            #+#    #+#             */
/*   Updated: 2023/02/10 11:53:37 by t.fuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

#define NUM_ZOMBIE 3

int	main() {
	Zombie	*zombies = zombieHorde(NUM_ZOMBIE, "hoge");
	for (int i = 0; i < NUM_ZOMBIE; i++) {
		std::cout << &zombies[i] << std::endl;
		zombies[i].announce();
	}
	delete zombies;
}

__attribute__((destructor))
static void destructor() {
	system("leaks -q ex01");
}
