/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:43:25 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/27 18:15:15 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog(void)
{
	std::cout << Blue " -- Default constructor for dog --" Reset << std::endl;
	this->type = "Dog";
	this->brain = new Brain();

}

Dog::Dog( const Dog & src )
{
	*this = src;
	std::cout << Blue "Copy constructor for dog" Reset << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog(void)
{
	delete this->brain;
	std::cout << Blue " -- Default destructor for dog -- " Reset << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog 		&Dog::operator=( Dog const & rhs )
{
	if (this != &rhs)
	{
		*(this->brain) = *(rhs.getBrain());
		this->type = rhs.getType();
	}
	return *this;
}

Animal		&Dog::operator=( Animal const &rhs )
{

	if (this != &rhs)
	{
		this->type = rhs.getType();
		*(this->brain) = *(rhs.getBrain());
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Dog const & i )
{
	o << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string	Dog::getType(void) const
{
	return (this->type);
}

Brain	*Dog::getBrain(void) const
{
	return (this->brain);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */