#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
	// test from subject
	// const Animal* meta = new Animal();
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// std::cout << j->getType() << " " << std::endl;
	// std::cout << i->getType() << " " << std::endl;
	// i->makeSound();
	// j->makeSound();
	// meta->makeSound();

	std::cout << R << "===== TEST IN CORRECT CLASS =====" << E << std::endl;
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << R << "test getType()" << E << std::endl;
	std::cout << "    meta: " << meta->getType() << " " << std::endl;
	std::cout << "    dog:  " << dog->getType() << " " << std::endl;
	std::cout << "    cat:  " << cat->getType() << " " << std::endl;

	std::cout << R << "test makeSound()" << E << std::endl;
	std::cout << "    meta: ";
	meta->makeSound();
	std::cout << "    dog:  ";
	dog->makeSound();
	std::cout << "    cat:  ";
	cat->makeSound();

	std::cout << R << "delete" << E << std::endl;
	delete meta;
	delete dog;
	delete cat;

	std::cout << R << "===== TEST IN WRONG CLASS =====" << E << std::endl;
	const WrongAnimal* wrongmeta = new WrongAnimal();
	const WrongAnimal* wrongcat = new WrongCat();

	std::cout << R << "test getType()" << E << std::endl;
	std::cout << "    wrongmeta: " << wrongmeta->getType() << " " << std::endl;
	std::cout << "    wrongcat:  " << wrongcat->getType() << " " << std::endl;

	std::cout << R << "test makeSound()" << E << std::endl;
	std::cout << "    wrongmeta: ";
	wrongmeta->makeSound();
	std::cout << "    wrongcat:  ";
	wrongcat->makeSound();

	std::cout << R << "delete" << E << std::endl;
	delete wrongmeta;
	delete wrongcat;
	return 0;
}

// __attribute__((destructor))
// static void	destructor(void) {
// 	system("leaks -q exe");
// }
