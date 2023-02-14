/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:41:56 by t.fuji            #+#    #+#             */
/*   Updated: 2023/02/14 10:04:14 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
