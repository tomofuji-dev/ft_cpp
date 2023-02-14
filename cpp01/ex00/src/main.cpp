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

__attribute__((destructor))
static void destructor() {
	system("leaks -q exe");
}
