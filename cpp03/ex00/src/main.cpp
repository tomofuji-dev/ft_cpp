#include "ClapTrap.hpp"

int main() {
	ClapTrap a;
	ClapTrap b("hoge");
	ClapTrap c(b);
	a = b;
	a.attack("fuga");

	for (int i = 1; i < 4; i++) {
		a.takeDamage(i * 4);
	}

	for (int i = 1; i < 4; i++) {
		a.beRepaired(i * 4);
	}
}