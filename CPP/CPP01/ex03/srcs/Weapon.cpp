/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:33:42 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/18 13:38:19 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Weapon::Weapon(std::string type) : type(type)
{
	std::cout << "Constructor Weapon called ! " << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Weapon::~Weapon()
{
	std::cout << "Destructor Weapon called ! " << std::endl;
}

void	Weapon::setType(std::string const &newType)
{
	this->type = newType;
}

std::string	const &Weapon::getType(void) const
{
	return (this->type);
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */