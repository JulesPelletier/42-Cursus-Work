/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:53:43 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/21 14:24:56 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed(void) 
{
	std::cout << "Constructor called" << std::endl;
	this->val = 0;
}

Fixed::Fixed( const Fixed& src )
{
	std::cout << "Constructor with value called" << std::endl;
	this->val = src.getRawBits();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &				Fixed::operator=( Fixed const & rhs )
{
	if ( this != &rhs )
	{
		this->val = rhs.getRawBits();
	}
	return *this;
}

int		Fixed::getRawBits(void) const
{
	std::cout << Cyan "Calling getRawBits : " Reset << std::endl;
	return (this->val);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << Yellow "Setting getRawBits : " Reset << raw << std::endl;
	this->val = raw;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */