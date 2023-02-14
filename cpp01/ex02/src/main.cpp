#include <string.h>
#include <iostream>

int main() {
	std::string	stringRAW("HI THIS IS BRAIN");
	std::string	*stringPTR = &stringRAW;
	std::string	&stringREF = stringRAW;

	std::cout << "=== memory address ===" << std::endl;
	std::cout << "stringRAW: " << &stringRAW << std::endl;
	std::cout << "stringPTR: " << stringPTR << std::endl;
	std::cout << "stringREF: " << &stringREF << std::endl;

	std::cout << "=== value ===" << std::endl;
	std::cout << "stringRAW: " << stringRAW << std::endl;
	std::cout << "stringPTR: " << *stringPTR << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;
}