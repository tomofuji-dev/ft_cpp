/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:41:56 by t.fuji            #+#    #+#             */
/*   Updated: 2023/02/13 14:06:28 by tfujiwar         ###   ########.fr       */
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

	int		getRawBits() const;
	void	setRawBits(int const raw);

	float	toFloat() const;
	int		toInt() const;

private:

	int					_bits;
	static const int	fracBit = 8;

};

std::ostream& operator<<(std::ostream& stream, const Fixed& value);
