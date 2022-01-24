/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:53:43 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/21 15:07:13 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed(void) 
{
	std::cout << "> Default constructor called" << std::endl;
	this->val = 0;
}

Fixed::Fixed(const int value) 
{
	std::cout << "> Constructor with const int value called" << std::endl;
	this->val = value << this->bits;
}

Fixed::Fixed(const float value) 
{
	std::cout << "> Constructor with const float value called" << std::endl;
	this->val = roundf(value * (1 << this->bits));
}

Fixed::Fixed( const Fixed& src )
{
	std::cout << "> Copy constructor called" << std::endl;
	this->val = src.getRawBits();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed()
{
	std::cout << "> Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed				& Fixed::operator=( Fixed const & rhs )
{
	std::cout << Yellow " Calling operator = " Reset << std::endl;
	if ( this != &rhs )
	{
		this->val = rhs.getRawBits();
	}
	return *this;
}

std::ostream 	& operator<<(std::ostream & os, Fixed const & rhs)
{
	os << rhs.toFloat();
	return (os);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

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

float 			Fixed::toFloat(void) const
{
	return ((float)this->val / (float)(1 << this->bits));
}

int 			Fixed::toInt(void) const
{
	return ((int)(this->val >> this->bits));
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */