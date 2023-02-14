#pragma once
#include "Fixed.hpp"

class Point {

public:

	Point();
	Point(const float x_float, const float y_float);
	Point(const Fixed x_fixed, const Fixed y_fixed);
	Point(const Point &src);
	~Point();
	const Point&	operator=(const Point &rhs);
	const Point		operator-(const Point &rhs) const;

	const Fixed&	get_x() const;
	const Fixed&	get_y() const;

private:

	const Fixed x;
	const Fixed y;
};
