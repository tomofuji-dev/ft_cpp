/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:20:23 by tfujiwar          #+#    #+#             */
/*   Updated: 2023/02/07 14:00:25 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;

Account::Account( int initial_deposit ) : _amount(initial_deposit) {
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
};

void	Account::_displayTimestamp() {
	std::time_t now = std::time(nullptr);
	std::cout << "[" << std::put_time(std::localtime(&now), "%Y%m%d_%H%M%S") << "]";
};
