#pragma once
#include <string>

#define R		"\033[31m"
#define G		"\033[32m"
#define Y		"\033[33m"
#define B		"\033[34m"
#define E		"\033[00m"

class WrongAnimal {

public:

	WrongAnimal();
	WrongAnimal(const std::string type);
	WrongAnimal(const WrongAnimal& src);
	~WrongAnimal();
	WrongAnimal&	operator=(const WrongAnimal& rhs);

	void 				makeSound() const;
	const std::string&	getType() const;

protected:

	std::string type_;

};
