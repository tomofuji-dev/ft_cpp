#pragma once
#include <string>

#define R		"\033[31m"
#define G		"\033[32m"
#define Y		"\033[33m"
#define B		"\033[34m"
#define E		"\033[00m"

class Animal {

public:

	Animal();
	Animal(const std::string type);
	Animal(const Animal& src);
	virtual ~Animal();
	Animal&	operator=(const Animal& rhs);

	virtual void 		makeSound() const;
	const std::string&	getType() const;

protected:

	std::string type_;

};
