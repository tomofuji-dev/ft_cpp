#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "Brain()" << std::endl;
}

Brain::Brain(const Brain& src) {
	std::cout << "Brain(src)" << std::endl;
	*this = src;
}

Brain::~Brain() {
	std::cout << "~Brain()" << std::endl;
}

Brain&	Brain::operator=(const Brain& rhs){
	if (this == &rhs) {
		return *this;
	}
	for (size_t i = 0; i < nIdeas; i++) {
		ideas_[i] = rhs.ideas_[i];
	}
	return *this;
}
