#include <iostream>
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << "=== TEST IN SUBJECT ===" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	std::cout << "=== TEST MATERIA SOURCE ===" << std::endl;
	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	AMateria *materia = new Ice();
	src->learnMateria(materia);
	delete materia;
	materia = new Cure();
	src->learnMateria(materia);
	delete materia;
	tmp = src->createMateria("Ice");
	tmp = src->createMateria("Cure");
	me = new Character("me");
	AMateria* tmp1;
	AMateria* tmp2;
	for (size_t i = 0; i < 3; i++) {
		tmp1 = src->createMateria("ice");
		me->equip(tmp1);
		tmp2 = src->createMateria("cure");
		me->equip(tmp2);
	}
	delete tmp1;
	delete tmp2;
	bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);
	delete bob;
	delete me;
	delete src;

	std::cout << "=== TEST CHARACTER - MATERIA ===" << std::endl;
	ICharacter* chara = new Character("chara");
	AMateria* cure1 = new Cure();
	AMateria* cure2 = new Cure();
	AMateria* cure3 = new Cure();
	AMateria* cure4 = new Cure();
	chara->equip(cure1);
	chara->equip(cure2);
	chara->equip(cure3);
	chara->equip(cure4);
	chara->equip(cure1);
	chara->unequip(1);
	chara->equip(cure2);
	chara->unequip(3);
	chara->equip(cure4);
	chara->unequip(2);
	chara->equip(cure3);
	chara->unequip(0);
	chara->equip(cure1);
	chara->use(0, *chara);
	chara->use(1, *chara);
	chara->use(3, *chara);
	chara->use(2, *chara);
	delete chara;

	std::cout << "=== TEST CHARACTER DEEP COPY ===" << std::endl;
	Character* chara1 = new Character("chara");
	cure1 = new Cure();
	cure2 = new Cure();
	cure3 = new Cure();
	cure4 = new Cure();
	chara1->equip(cure1);
	chara1->equip(cure2);
	chara1->equip(cure3);
	chara1->equip(cure4);
	chara1->equip(cure1);
	Character* chara2 = new Character("chara");
	*chara2 = *chara1;
	delete chara1;
	delete chara2;
}

__attribute__((destructor))
static void	destructor(void) {
	system("leaks -q exe");
}
