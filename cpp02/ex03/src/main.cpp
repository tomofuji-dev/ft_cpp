#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) ;

int main( void ) {
	Point O(0, 0);
	Point X(1, 0);
	Point Y(0, 1);
	Point P(0.5, 0);

	std::cout << bsp(O, X, Y, P) << std::endl;
}