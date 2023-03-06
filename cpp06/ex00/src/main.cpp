#include <iostream>
#include <sstream>
#include "Const.hpp"
#include "Converter.hpp"

int main(int argc, char* argv[]) {
	
	if (argc != 2) {
		std::cerr << RED << std::string(ERR_ARGC) << RESET << std::endl;
		return FAILURE;
	}
	const std::string src(argv[1]);
	std::cout << GREEN << "[" << src << "]" << RESET << std::endl;
	Converter::Convert(src);
	return SUCCESS;
}
