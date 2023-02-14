#include "Point.hpp"

Point::Point() : x(0), y(0){
}

Point::Point(const float x_float, const float y_float) : x(x_float), y(y_float) {
}

Point::Point(const Fixed x_fixed, const Fixed y_fixed) : x(x_fixed), y(y_fixed) {
}

Point::Point(const Point &src) : x(Fixed(src.get_x())), y(Fixed(src.get_y())) {
}

Point::~Point(){
}

const Point&	Point::operator=(const Point &rhs) {
	const_cast<Fixed&>(x) = rhs.get_x();
	const_cast<Fixed&>(y) = rhs.get_y();
	return *this;
}

const Point	Point::operator-(const Point &rhs) const {
	Point p(x - rhs.get_x(), y - rhs.get_y());
	return p;
}

const Fixed&	Point::get_x() const {
	return x;
}

const Fixed&	Point::get_y() const {
	return y;
}
