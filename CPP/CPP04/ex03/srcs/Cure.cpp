/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:45:31 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/01 19:00:30 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cure::Cure(void) : AMateria("cure")
{
	std::cout << Yellow "Default constructor for Cure" Reset << std::endl;
}

Cure::Cure( const Cure & src ) : AMateria("cure")
{
	*this = src;
	std::cout << Yellow "Copy constructor for Cure" Reset << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cure::~Cure(void)
{
	std::cout << Yellow "Default destructor for Cure" Reset << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cure &				Cure::operator=( Cure const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Cure const & i )
{
	o << "Type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

AMateria				*Cure::clone(void) const
{
	AMateria *clone;

	clone = new Cure(*this);
	return (clone);
}

void					Cure::use(ICharacter &target)
{
	std::cout << "Check ! " << std::endl;
	std::cout << "* heals " + target.getName() + "’s wounds *" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */