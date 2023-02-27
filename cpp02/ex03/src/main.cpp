#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) ;

int main( void ) {
	Point O(0, 0);
	Point X(1, 0);
	Point Y(0, 1);
	Point P1(0, 0);
	Point P2(1, 0);
	Point P3(0, 1);
	Point P4(0.5, 0.5);
	Point P5(0, 0.5);
	Point P6(0.5, 0);
	Point P7(0.5, 0.5);
	Point P8(0.25, 0.25);

	std::cout << bsp(O, X, Y, P1) << std::endl;
	std::cout << bsp(O, X, Y, P2) << std::endl;
	std::cout << bsp(O, X, Y, P3) << std::endl;
	std::cout << bsp(O, X, Y, P4) << std::endl;
	std::cout << bsp(O, X, Y, P5) << std::endl;
	std::cout << bsp(O, X, Y, P6) << std::endl;
	std::cout << bsp(O, X, Y, P7) << std::endl;
	std::cout << bsp(O, X, Y, P8) << std::endl;
}