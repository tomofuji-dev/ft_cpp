/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:41:56 by t.fuji            #+#    #+#             */
/*   Updated: 2023/02/13 17:34:49 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	Fixed operator+(const Fixed& rhs);
	Fixed operator-(const Fixed& rhs);
	Fixed operator*(const Fixed& rhs);
	Fixed operator/(const Fixed& rhs);

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
