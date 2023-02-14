#include "Harl.hpp"
#include <iostream>

#define SUCCESS	0
#define FAILURE	1
#define R		"\033[1;31m"
#define E		"\033[00m"

int main(int argc, char *argv[]) {
	Harl	harl;
	if (argc != 2) {
		std::cerr << R << "invalid argc" << E << std::endl;
		return FAILURE;
	}
	harl.complain(argv[1]);
	return SUCCESS;
}