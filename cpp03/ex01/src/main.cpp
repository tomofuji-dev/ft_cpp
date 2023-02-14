#include "ScavTrap.hpp"

int main() {
	ScavTrap a;
	ScavTrap b("hoge");
	ScavTrap c(b);
	a = b;
	a.attack("fuga");

	for (int i = 1; i < 4; i++) {
		a.takeDamage(i * 40);
	}

	a.attack("fuga");

	for (int i = 1; i < 4; i++) {
		a.beRepaired(i * 40);
	}
}