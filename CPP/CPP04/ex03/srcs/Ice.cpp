/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:45:34 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/01 19:00:48 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Ice::Ice(void) : AMateria("ice")
{
	std::cout << Green "Default constructor for Ice" Reset << std::endl;
}

Ice::Ice( const Ice & src ) : AMateria("ice")
{
	*this = src;
	std::cout << Green "Copy constructor for Ice" Reset << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Ice::~Ice(void)
{
	std::cout << Green "Default destructor for Ice" Reset << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Ice &				Ice::operator=( Ice const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Ice const & i )
{
	o << "Type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

AMateria				*Ice::clone(void) const
{
	AMateria *clone;

	clone = new Ice(*this);
	return (clone);
}

void					Ice::use(ICharacter &target)
{
	std::cout << "Check ! " << std::endl;
	std::cout << "* shoots an ice bolt at " + target.getName() + " *" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */