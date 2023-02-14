#pragma once

# include <iostream>

class Fixed {

public:

	Fixed();
	Fixed(int const val);
	Fixed(float const val);
	Fixed(const Fixed &src);
	~Fixed();
	Fixed&	operator=(const Fixed &rhs);
	Fixed&	operator++();
	Fixed&	operator--();
	Fixed	operator++(int);
	Fixed	operator--(int);

	Fixed operator+(const Fixed& rhs) const;
	Fixed operator-(const Fixed& rhs) const;
	Fixed operator*(const Fixed& rhs) const;
	Fixed operator/(const Fixed& rhs) const;

	bool operator<(const Fixed& rhs) const;
	bool operator>(const Fixed& rhs) const;
	bool operator<=(const Fixed& rhs) const;
	bool operator>=(const Fixed& rhs) const;
	bool operator==(const Fixed& rhs) const;
	bool operator!=(const Fixed& rhs) const;

	int		getRawBits() const;
	void	setRawBits(int const raw);
	float	toFloat() const;
	int		toInt() const;

	static Fixed&		min(Fixed& f1, Fixed& f2);
	static const Fixed&	min(const Fixed& f1, const Fixed& f2);
	static Fixed&		max(Fixed& f1, Fixed& f2);
	static const Fixed&	max(const Fixed& f1, const Fixed& f2);

private:

	int					_bits;
	static const int	fracBit = 8;

};

std::ostream& operator<<(std::ostream& stream, const Fixed& value);
