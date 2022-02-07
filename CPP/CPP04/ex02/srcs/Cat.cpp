/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:43:33 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/27 18:38:25 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat(void)
{
	std::cout << Red " -- Default constructor for cat -- " Reset << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat( const Cat & src )
{
	*this = src;
	std::cout << Red "Copy constructor for cat" Reset << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat(void)
{
	delete this->brain;
	std::cout << Red " -- Default destructor for cat -- " Reset << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
{
	if (this != &rhs)
	{
		*(this->brain) = *(rhs.getBrain());
		this->type = rhs.getType();
	}
	return *this;
}

AAnimal		&Cat::operator=( AAnimal const &rhs )
{
	if (this != &rhs)
	{
		this->type = rhs.getType();
		*(this->brain) = *(rhs.getBrain());
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Cat const & i )
{
	o << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string	Cat::getType(void) const
{
	return (this->type);
}

Brain	*Cat::getBrain(void) const
{
	return (this->brain);
}

void	Cat::makeSound(void) const
{
	std::cout << "** Meow Meow Meow **" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */