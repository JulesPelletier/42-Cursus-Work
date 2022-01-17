/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:41:20 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/17 21:55:58 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Account.hpp"

Account::Account(int initial_deposit)
{
	//std::cout << "Constructor called !" << std::endl;
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
	std::cout << CYAN"index:"RESET << this->_accountIndex << ";";
	std::cout << GREEN"amount:"RESET << this->_amount << ";";
	std::cout << val << ";" << MAGENTA"deposits:"RESET;
	val = this->_nbDeposits;
	std::cout << val << ";" << BLUE"withdrawals:"RESET;
	val = this->_nbWithdrawals;
	std::cout << val << std::endl;
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

