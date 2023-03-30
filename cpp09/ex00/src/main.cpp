#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << ERR_ARGC << std::endl;
		return FAILURE;
	}
	try {
		BitcoinExchange be;
		be.api(argv[1]);
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
		return FAILURE;
	}
	return SUCCESS;
}
