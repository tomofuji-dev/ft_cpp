#include "RPN.hpp"
#define FAILURE 1
#define SUCCESS 0

int main(int argc, char* argv[]) {
	RPN rpn;
	if (argc != 2) {
		std::cerr << "argc error." << std::endl;
		return FAILURE;
	}
	try {
		std::cout << rpn.calc(std::string(argv[1])) << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return FAILURE;
	}
	return SUCCESS;
}