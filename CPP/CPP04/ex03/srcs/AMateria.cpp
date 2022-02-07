/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:42:00 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/07 16:12:23 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AMateria::AMateria(void)
{
	std::cout << Blue "Default constructor for AMateria" Reset << std::endl;
}

AMateria::AMateria( const AMateria & src )
{
	*this = src;
	std::cout << Blue "Copy constructor for AMateria" Reset << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type)
{
	std::cout << Blue "String constructor for AMateria" Reset << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AMateria::~AMateria()
{
	std::cout << Blue "Default destructor for AMateria" Reset << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AMateria &				AMateria::operator=( AMateria const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AMateria const & i )
{
	o << "Value = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string const		&AMateria::getType(void) const
{
	return (this->type);
}

void					AMateria::use(ICharacter &target)
{
	(void)target;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */