#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : _name(std::string()) {
	std::cout << "constructor: " << _name << std::endl;
}

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << "constructor: " << _name << std::endl;
}

Zombie::Zombie(const Zombie& src) : _name(src.getName()){
	std::cout << "copy constructor: " << _name << std::endl;
}

Zombie::~Zombie() {
	std::cout << "destructor: " << _name << std::endl;
}

std::string	Zombie::getName() const {
	return _name;
}

Zombie&	Zombie::operator=(const Zombie& rhs) {
	_name = rhs.getName();
	return *this;
}

void	Zombie::announce() const {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
