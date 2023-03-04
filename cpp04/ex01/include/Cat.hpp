#ifndef CAT_H
#define CAT_H
#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public Animal {

public:

	Cat();
	Cat(const Cat& src);
	~Cat();
	Cat& operator=(const Cat& rhs);

	void			makeSound() const;
	const Brain*	getBrain() const;

private:
	Brain* brain_;
};

#endif
