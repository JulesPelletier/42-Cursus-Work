/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:39:27 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/26 15:04:28 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal(void)
{
	this->type = "Standard animal";
	std::cout << " ==== Animal default constructor ==== " << std::endl;
}

Animal::Animal( const Animal & src )
{
	*this = src;
	std::cout << " ==== Animal copy constructor ==== " << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal(void)
{
	std::cout << " ==== Animal destructor ==== " << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &				Animal::operator=( Animal const & rhs )
{
	(void)rhs;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Animal const & i )
{
	(void)i;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string	Animal::getType(void) const
{
	return (this->type);
}

void		Animal::makeSound(void) const
{
	if (this->type == "Dog")
		std::cout << "** Bark Bark Bark **" << std::endl;
	else if (this->type == "Cat")
		std::cout << "** Meowww Meowww Meowww **" << std::endl;
	else
		std::cout << "** can't define a sound for the standard animal **" << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */