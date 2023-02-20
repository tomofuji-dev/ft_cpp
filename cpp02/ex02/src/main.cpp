#include <iostream>
#include "Fixed.hpp"

#include <iostream>
int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;


	Fixed c;
	Fixed d;
	d = ( Fixed( 5.05f ) / Fixed( 2 ) );
	std::cout << c << std::endl;
	std::cout << --c << std::endl;
	std::cout << c << std::endl;
	std::cout << c-- << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << Fixed::min( c, d ) << std::endl;

	try {
		d = ( Fixed( 5.05f ) / Fixed( 0 ) );
	}
	catch(std::invalid_argument&) {
		std::cerr << "divided by 0" << std::endl;
		return 1;
	}
	return 0;
}