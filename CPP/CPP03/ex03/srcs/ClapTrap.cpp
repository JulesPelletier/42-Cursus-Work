/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:34:24 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/24 18:09:21 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap(void)
{
	std::cout << "Default constructor called for : " << this->_name << std::endl;
}

ClapTrap::ClapTrap(std::string str) : _hp(10), _ep(10), _attack(0)
{
	this->_name = str;
	std::cout << "Constructor called for : " << this->_name << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap & src )
{
	*this = src;
	std::cout << "Constructor copy called for : "<< this->_name << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called for : " << this->_name << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &				ClapTrap::operator=( ClapTrap const & rhs )
{
	if ( this != &rhs )
	{
		this->_name = rhs._name;
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_attack = rhs._attack;
	}
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void 			ClapTrap::attack(const std::string& target)
{
	if (this->_ep <= 0)
		std::cout << Red "Not enough energy to attack"  Reset << std::endl;
	if (this->_hp <= 0)
		std::cout << this->_name << Red " has already died " Reset << std::endl;
	else
	{
		std::cout << Cyan "ClapTrap " << this->_name << " attacks " << target << std::endl;
		std::cout << Cyan "He dealt " << this->_attack << " damage to " << target << std::endl;
	}
}

void 			ClapTrap::takeDamage(unsigned int amount)
{
	if (amount <= 0)
		std::cout << this->_name << Red " can't take negative damage " Reset << std::endl;
	if (this->_hp <= 0)
		std::cout << this->_name << Red " has already died " Reset << std::endl;
	else
	{
		std::cout << Cyan"ClapTrap " << this->_name << " took " << amount << " damage " << std::endl;
		this->_hp = this->_hp - amount;
		std::cout << Reset << this->_name << " has " << this->_hp << " HP left " << std::endl;
	}
}

void 			ClapTrap::beRepaired(unsigned int amount)
{
	if (amount <= 0)
		std::cout << this->_name << Red " can't get negative hp back " Reset << std::endl;
	std::cout << Cyan << "" << this->_name << " got " << amount << " HP back " << std::endl;
	this->_hp = this->_hp + amount;
	std::cout << Reset << this->_name << " has " << this->_hp << " HP left " << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */