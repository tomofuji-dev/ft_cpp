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
		if (N <= 20)
			print_wrapper(sp);
	}
	print_wrapper(sp);
	return SUCCESS;
}

// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }
