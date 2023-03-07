#include "whatever.hpp"
#include <iostream>

int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}

// template <typename T>
// void test(T& a, T& b) {
// 	std::cout << "a: " << a << " , b: " << b << std::endl;
// 	swap(a, b);
// 	std::cout << "swap: a: " << a << " , b: " << b << std::endl;
// 	std::cout << "min: " << min(a, b) << std::endl;
// 	std::cout << "min: " << max(a, b) << std::endl;
// }

// int main() {
// 	{
// 		int a = 1;
// 		int b = 10;
// 		test<int>(a, b);
// 	}
// 	{
// 		int a = 5;
// 		int b = 5;
// 		test<int>(a, b);
// 	}
// 	{
// 		float a = 1.5f;
// 		float b = 15.0f;
// 		test<float>(a, b);
// 	}
// }
