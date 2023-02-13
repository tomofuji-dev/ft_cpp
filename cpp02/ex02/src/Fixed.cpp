#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _bits(0) {
}

Fixed::Fixed(int const val) {
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
	*this = src;
}

Fixed::~Fixed() {
}

Fixed&	Fixed::operator=(const Fixed &rhs) {
	_bits = rhs.getRawBits();
	return *this;
}

int	Fixed::getRawBits() const {
	return _bits;
}

void	Fixed::setRawBits(int const raw) {
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

// ++fixed;
Fixed&	Fixed::operator++() {
	_bits++;
	return *this;
}

// --fixed;
Fixed&	Fixed::operator--() {
	_bits--;
	return *this;
}

// fixed++;
Fixed	Fixed::operator++(int) {
	Fixed	tmp = *this;
	_bits++;
	return tmp;
}

// fixed--;
Fixed	Fixed::operator--(int) {
	Fixed	tmp = *this;
	_bits--;
	return tmp;
}

Fixed Fixed::operator+(const Fixed& rhs) {
	Fixed	f;
	f.setRawBits(this->getRawBits() + rhs.getRawBits());
	return f;
}

Fixed Fixed::operator-(const Fixed& rhs) {
	Fixed	f;
	f.setRawBits(this->getRawBits() - rhs.getRawBits());
	return f;
}

Fixed Fixed::operator*(const Fixed& rhs) {
	Fixed	f;
	f.setRawBits((this->getRawBits() * rhs.getRawBits()) >> fracBit);
	return f;
}

Fixed Fixed::operator/(const Fixed& rhs){
	Fixed	f;
	f.setRawBits((this->getRawBits() << fracBit) / rhs.getRawBits());
	return f;
}

bool Fixed::operator<(const Fixed& rhs) const {
	return this->getRawBits() < rhs.getRawBits();
}

bool Fixed::operator>(const Fixed& rhs) const {
	return this->getRawBits() > rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed& rhs) const {
	return this->getRawBits() <= rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed& rhs) const {
	return this->getRawBits() >= rhs.getRawBits();
}

bool Fixed::operator==(const Fixed& rhs) const {
	return this->getRawBits() == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed& rhs) const {
	return this->getRawBits() != rhs.getRawBits();
}

Fixed&		Fixed::min(Fixed& f1, Fixed& f2) {
	return (f1 < f2) ? f1 : f2;
}

const Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2) {
	return (f1 < f2) ? f1 : f2;
}

Fixed&		Fixed::max(Fixed& f1, Fixed& f2) {
	return (f1 > f2) ? f1 : f2;
}

const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2) {
	return (f1 > f2) ? f1 : f2;
}
