#include "FragTrap.hpp"

int main() {
	FragTrap a;
	FragTrap b("hoge");
	FragTrap c(b);
	a = b;
	a.attack("fuga");

	for (int i = 1; i < 4; i++) {
		a.takeDamage(i * 40);
	}

	a.attack("fuga");

	for (int i = 1; i < 4; i++) {
		a.beRepaired(i * 40);
	}
	a.highFivesGuys();
}