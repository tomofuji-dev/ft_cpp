#include "DiamondTrap.hpp"

int main() {
	DiamondTrap a;
	DiamondTrap b("hoge");
	DiamondTrap c(b);
	a = b;
	a.attack("fuga");

	for (int i = 1; i < 4; i++) {
		a.takeDamage(i * 40);
	}

	a.attack("fuga");

	for (int i = 1; i < 4; i++) {
		a.beRepaired(i * 40);
	}
	a.guardGate();
	a.highFivesGuys();
	a.whoAmI();
}