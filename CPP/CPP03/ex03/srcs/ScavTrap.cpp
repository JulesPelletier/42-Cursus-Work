/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:13:40 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/24 16:47:45 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called for : " << name << std::endl;
	this->_hp = 100;
	this->_ep = 50;
	this->_attack = 20;
}

ScavTrap::ScavTrap( const ScavTrap & src ) : ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called for : " << this->_name << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called for : " << this->_name << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap &				ScavTrap::operator=( ScavTrap const & rhs )
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

void 			ScavTrap::attack(const std::string& target)
{
	if (this->_ep <= 0)
		std::cout << Red "Not enough energy to attack"  Reset << std::endl;
	else
	{
		std::cout << Cyan "ScavTrap " << this->_name << " attacks " << target << std::endl;
		std::cout << Cyan "He dealt " << this->_attack << " damage to " << target << std::endl;
	}
}


void			ScavTrap::guardGate(void)
{
	std::cout << Cyan "ScavTrap " << this->_name << " is guarding the gate " Reset << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */