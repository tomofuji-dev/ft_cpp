/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:41:56 by t.fuji            #+#    #+#             */
/*   Updated: 2023/02/13 13:21:57 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Fixed {

public:

	Fixed();
	Fixed(Fixed const &src);
	~Fixed();
	Fixed&	operator=(Fixed const &rhs);

	int		getRawBits() const;
	void	setRawBits(int const raw);

private:

	int					_value;
	static const int	fracBit = 8;

};
