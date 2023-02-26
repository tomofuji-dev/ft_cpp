#include "Zombie.hpp"
#include <iostream>

#define NUM_ZOMBIE 3

int	main() {
	try {
		Zombie	*zombies = zombieHorde(NUM_ZOMBIE, "hoge");
		for (int i = 0; i < NUM_ZOMBIE; i++) {
			std::cout << &zombies[i] << std::endl;
			zombies[i].announce();
		}
		delete[] zombies;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::cout;
		return 1;
	}
	return 0;
}

__attribute__((destructor))
static void destructor() {
	system("leaks -q exe");
}
