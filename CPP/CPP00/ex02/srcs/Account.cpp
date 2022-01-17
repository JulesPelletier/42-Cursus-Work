/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:41:20 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/17 22:03:58 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "../includes/Account.hpp"

# define RESET	"\033[0m"
# define BLACK   "\033[30m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"

Account::Account(int initial_deposit)
{
	//std::cout << "Constructor called !" << std::endl;
	_displayTimestamp();
	this->_accountIndex = this->_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	std::cout << CYAN"index:"RESET << this->_accountIndex << ";";
	std::cout << GREEN"amount:"RESET << this->_amount << ";";
	std::cout << MAGENTA"created"RESET << std::endl;
	this->_totalAmount = this->_totalAmount + initial_deposit;
	this->_nbAccounts++;
	return ;
}

Account::~Account(void)
{
	//std::cout << "Destructor called !" << std::endl;
	_displayTimestamp();
	std::cout << CYAN"index:"RESET << this->_accountIndex << ";";
	std::cout << GREEN"amount:"RESET << this->_amount << ";";
	std::cout << MAGENTA"closed"RESET << std::endl;
	return ;
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << CYAN"index:"RESET << this->_accountIndex << ";" << GREEN"p_amount:"RESET;
	std::cout << this->_amount << ";" << MAGENTA"deposit:"RESET;
	if (deposit < 0)
		return ;
	this->_amount = this->_amount + deposit;
	std::cout << deposit << ";" << BLUE"amount:"RESET;
	std::cout << this->_amount << ";" << RED"nb_deposits:"RESET;
	this->_nbDeposits++;
	std::cout << this->_nbDeposits << std::endl;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal < 0)
		return (false);
	_displayTimestamp();
	std::cout << CYAN"index:"RESET << this->_accountIndex << ";" << GREEN"p_amount:"RESET;
	std::cout << this->_amount << ";" << MAGENTA"withdrawal:"RESET;
	if (withdrawal >= 0 && withdrawal < this->_amount)
		this->_amount = this->_amount - withdrawal;
	else
	{
		std::cout << RED"refused" << std::endl;
		return (false);
	}
	std::cout << withdrawal << ";" << BLUE"amount:"RESET;
	std::cout << this->_amount << ";" << RED"nb_withdrawals:"RESET;
	this->_nbWithdrawals++;
	std::cout << Account::_nbWithdrawals << std::endl;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	return (true);
}

void	Account::displayAccountsInfos(void)
{
	int	val;

	_displayTimestamp();
	val = Account::getNbAccounts();
	std::cout << YELLOW"acounts:"RESET << val << ";" << YELLOW"total:"RESET;
	val = Account::getTotalAmount();
	std::cout << val << ";" << YELLOW"deposits:"RESET;
	val = Account::getNbDeposits();
	std::cout << val << ";" << YELLOW"withdrawals:"RESET;
	val = Account::getNbWithdrawals();
	std::cout << val << std::endl;
}

void	Account::displayStatus( void ) const
{
	int	val;

	val = 0;
	_displayTimestamp();
	std::cout << CYAN"index:"RESET << this->_accountIndex << ";";
	std::cout << GREEN"amount:"RESET << this->_amount << ";";
	std::cout << val << ";" << MAGENTA"deposits:"RESET;
	val = this->_nbDeposits;
	std::cout << val << ";" << BLUE"withdrawals:"RESET;
	val = this->_nbWithdrawals;
	std::cout << val << std::endl;
}

void	Account::_displayTimestamp(void)
{
	char		message[30];
	std::time_t	actual;
	std::tm		*timeptr;

	time(&actual);
	timeptr = localtime(&actual);
	strftime(message, 30, RESET"[%Y%m%d_%H%M%S] ", timeptr);
	std::cout << message;
}

int		Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int		Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int		Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int		Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

