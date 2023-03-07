#include "iter.hpp"
#include <iostream> 

template<typename T>
void increment(T& i) {
	i++;
}

template<typename T>
void print(const T& p) {
	std::cout << p << " ";
}

int main() {
	static std::size_t	N = 5;
	static int			test1[] = {0,1,2,3,4};
	static const float	test2[] = {0.0,0.1,0.2,0.3,0.4};
	
	std::cout << "=== increment ===" << std::endl; 
	for (std::size_t i = 0; i < N; i++) {
		std::cout << test1[i] << " ";
	}
	std::cout << std::endl;
	iter<int>(test1, N, increment);
	for (std::size_t i = 0; i < N; i++) {
		std::cout << test1[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "=== print ===" << std::endl;
	iter<const float>(test2, N, print);
	std::cout << std::endl;
}
