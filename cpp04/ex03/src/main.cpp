#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	ICharacter* bob = new Character("bob");
	AMateria* cure1 = new Cure();
	AMateria* cure2 = new Cure();
	AMateria* cure3 = new Cure();
	AMateria* cure4 = new Cure();
	bob->equip(cure1);
	bob->equip(cure2);
	bob->equip(cure3);
	bob->equip(cure4);
	bob->equip(cure1);
	bob->unequip(1);
	bob->equip(cure2);
	bob->unequip(3);
	bob->equip(cure4);
	bob->unequip(2);
	bob->equip(cure3);
	bob->unequip(0);
	bob->equip(cure1);
	bob->use(0, *bob);
	bob->use(1, *bob);
	bob->use(3, *bob);
	bob->use(2, *bob);
	delete bob;
}

__attribute__((destructor))
static void	destructor(void) {
	system("leaks -q exe");
}
