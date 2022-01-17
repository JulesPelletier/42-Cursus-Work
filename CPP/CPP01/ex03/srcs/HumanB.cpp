/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:33:38 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/18 00:09:35 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

HumanB::HumanB(std::string name) : name(name), weapon(NULL) 
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

HumanB::~HumanB()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

void	HumanB::attack(void) const
{
	if (!this->weapon)
		std::cout << "Human B is attacking barehanded" << std::endl;
	else
		std::cout << "Human B is attacking with his " << this->weapon << std::endl;
}

Weapon *HumanB::getWeapon(void) const
{
	return(this->weapon);
}

bool	HumanB::setWeapon( Weapon& newWeapon )
{
	if (newWeapon.getType() == "")
	{
		std::cerr << "New weapon can't be nothing" << std::endl;
		return (false);
	}
	this->weapon = &newWeapon;
	return (true);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */