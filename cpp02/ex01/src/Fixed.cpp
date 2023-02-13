#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _bits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const val) {
	std::cout << "Int constructor called" << std::endl;
	int lshift = val << fracBit;
	int reshift = lshift >> fracBit;
	if (reshift != val) {
		_bits = val > 0 ? INT_MAX : INT_MIN;
	}
	else {
		_bits = lshift;
	}
}

Fixed::Fixed(float const val) {
	std::cout << "Float constructor called" << std::endl;
	double converter = (double)(1 << fracBit);
	double db = val * (converter);
	if (db >= INT_MAX) {
		_bits = INT_MAX;
	}
	else if (db <= INT_MIN) {
		_bits = INT_MIN;
	}
	else {
		_bits = roundf(db);
	}
}

Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	_bits = rhs.getRawBits();
	return *this;
}

int	Fixed::getRawBits() const {
	return _bits;
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_bits = raw;
}

float	Fixed::toFloat() const {
	double denom = (double)(1 << fracBit);
	return _bits / denom;
}

int	Fixed::toInt() const {
	return _bits >> fracBit;
}

std::ostream&	operator<<(std::ostream& stream, const Fixed& value) {
	return stream << value.toFloat();
}
