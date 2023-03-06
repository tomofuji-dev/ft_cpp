#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate(void) {
	Base* base = NULL;
	switch (std::rand() % 3) {
		case 0:
			base = new A;
			break;
		case 1:
			base = new B;
			break;
		case 2:
			base = new C;
			break;
	}
	return base;
}

void identify(Base* p) {

	if (dynamic_cast<A*>(p)) {
		std::cout << 'A' << std::endl;
	}
	else if (dynamic_cast<B*>(p)) {
		std::cout << 'B' << std::endl;
	}
	else if (dynamic_cast<C*>(p)) {
		std::cout << 'C' << std::endl;
	}
	else {
		std::cerr << "ERROR: unexpected pointer" << std::endl;
	}
}

void identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		static_cast<void>(a);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::bad_cast& e) {}
	try {
		B& b = dynamic_cast<B&>(p);
		static_cast<void>(b);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::bad_cast& e) {}
	try {
		C& c = dynamic_cast<C&>(p);
		static_cast<void>(c);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::bad_cast& e) {}
	std::cerr << "unexpected ref" << std::endl;
}

int main() {
	Base* base;
	std::srand(std::time(NULL));
	base = generate();
	std::cout << base << std::endl;
	std::cout << "id[pointer]: ";	identify(base);
	std::cout << "id[reference]: ";	identify(*base);
}
