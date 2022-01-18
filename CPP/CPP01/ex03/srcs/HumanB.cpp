/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:33:38 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/18 13:43:41 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) 
{
	std::cout << this->_name << " Constructed !" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

HumanB::~HumanB()
{
	std::cout << this->_name << " Destroyed !" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

void	HumanB::attack(void) const
{
	if (!this->_weapon)
		std::cout << "Human B is attacking barehanded" << std::endl;
	else
		std::cout << "Human B is attacking with his " << this->_weapon->getType() << std::endl;
}

Weapon *HumanB::getWeapon(void) const
{
	return(this->_weapon);
}

bool	HumanB::setWeapon( Weapon& newWeapon )
{
	if (newWeapon.getType() == "")
	{
		std::cerr << "New weapon can't be nothing" << std::endl;
		return (false);
	}
	this->_weapon = &newWeapon;
	return (true);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */