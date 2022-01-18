/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:33:32 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/18 13:41:22 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	std::cout << this->_name << " Constructed !" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

HumanA::~HumanA()
{
	std::cout << this->_name << " Destroyed !" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/


/*
** --------------------------------- METHODS ----------------------------------
*/


void	HumanA::attack(void) const
{
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}

Weapon	&HumanA::getWeapon(void) const
{
	return (this->_weapon);
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */