#include "Span.hpp"
#include <iostream>

#define SUCCESS 0
#define FAILURE 1

void print_wrapper(Span& sp) {
	try{
		std::cout << sp;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "[ERROR] argc must be 2." << std::endl;
		return FAILURE;
	}
	int N;
	try {
		N = std::stoi(argv[1]);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return FAILURE;
	}
	srand(time(NULL));
	Span sp(N);
	print_wrapper(sp);
	for (int i = 0; i < N; i++) {
		sp.addNumber(rand() % N);
		if (N <= 10)
			print_wrapper(sp);
	}
	print_wrapper(sp);
	return SUCCESS;
}
