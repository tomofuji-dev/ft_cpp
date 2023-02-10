/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: t.fuji <t.fuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:20:03 by t.fuji            #+#    #+#             */
/*   Updated: 2023/02/10 12:29:33 by t.fuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <iostream>

int main() {
	std::string	stringRAW("HI THIS IS BRAIN");
	std::string	*stringPTR = &stringRAW;
	std::string	&stringREF = stringRAW;

	std::cout << "=== memory address ===" << std::endl;
	std::cout << "stringRAW: " << &stringRAW << std::endl;
	std::cout << "stringPTR: " << stringPTR << std::endl;
	std::cout << "stringREF: " << &stringREF << std::endl;

	std::cout << "=== value ===" << std::endl;
	std::cout << "stringRAW: " << stringRAW << std::endl;
	std::cout << "stringPTR: " << *stringPTR << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;
}