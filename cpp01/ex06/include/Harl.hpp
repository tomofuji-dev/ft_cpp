/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:41:56 by t.fuji            #+#    #+#             */
/*   Updated: 2023/02/11 16:03:06 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Harl {

public:

	Harl();
	~Harl();

	void complain(std::string level);

private:

	void debug();
	void info();
	void warning();
	void error();
	void usage();
};
