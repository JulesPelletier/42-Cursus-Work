/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:39:27 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/27 18:34:06 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AAnimal::~AAnimal(void)
{
	std::cout << " ==== Animal destructor ==== " << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AAnimal &				AAnimal::operator=( AAnimal const & rhs )
{
	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AAnimal const & i )
{
	o << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string	AAnimal::getType(void) const
{
	return (this->type);
}

void		AAnimal::makeSound(void) const
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