#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

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

	std::cout << R << "=== CHECK LEAKS IN LIST OBJS (as Animal) ===" << E << std::endl;
	Animal* test1[6];

	test1[0] = new Animal();
	test1[1] = new Animal();
	test1[2] = new Dog();
	test1[3] = new Dog();
	test1[4] = new Cat();
	test1[5] = new Cat();
	
	for (int i = 0; i < 6; i++) {
		delete test1[i];
	}

	std::cout << R << "=== CHECK LEAKS IN LIST OBJS (as Dog) ===" << E << std::endl;
	Dog* test2[2];
	test2[0] = new Dog();
	test2[1] = new Dog();
	
	for (int i = 0; i < 2; i++) {
		delete test2[i];
	}

	std::cout << R << "=== CHECK LEAKS IN LIST OBJS (as Cat) ===" << E << std::endl;
	Cat* test3[2];
	test3[0] = new Cat();
	test3[1] = new Cat();
	
	for (int i = 0; i < 2; i++) {
		delete test3[i];
	}

	std::cout << R << "=== TEST DEEP COPY ===" << E << std::endl;
	Cat test4;
	Cat test5(test4);
	std::cout << test4.getBrain() << std::endl;
	std::cout << test5.getBrain() << std::endl;


	std::cout << R << "=== TEST DEEP COPY ===" << E << std::endl;
	Dog test6;
	Dog test7(test6);
	std::cout << test6.getBrain() << std::endl;
	std::cout << test7.getBrain() << std::endl;
	return 0;
}

// __attribute__((destructor))
// static void	destructor(void) {
// 	system("leaks -q exe");
// }
