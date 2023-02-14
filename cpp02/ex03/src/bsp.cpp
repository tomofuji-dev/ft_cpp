#include "Point.hpp"

Fixed cross(const Point lhs, const Point rhs) {
	return (lhs.get_x() * rhs.get_y()) -  (lhs.get_y() * rhs.get_x());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed b1 = cross(b - a, point - b);
	Fixed b2 = cross(c - b, point - c);
	Fixed b3 = cross(a - c, point - a);

	return (b1 > 0 && b2 > 0 && b3 > 0) || (b1 < 0 && b2 < 0 && b3 < 0) ;
}
