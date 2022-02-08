/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:10:13 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/08 15:32:26 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span(void) : _n(0), _count(0)
{
	std::cout << Yellow "Default constructor called for Span" Reset << std::endl;
}

Span::Span(unsigned int n) : _n(n), _count(0)
{
	std::cout << Purple "Constructor called for Span" Reset << std::endl;
}

Span::Span( const Span & src ) : _n(src.getSize()), _count(src.getCount())
{
	*this = src;
	std::cout << Purple "Copy constructor called for Span" Reset << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span(void)
{
	std::cout << Yellow "Default destructor called for Span" Reset << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const & rhs )
{
	if ( this != &rhs )
	{
		this->_n = rhs.getSize();
	}
	return *this;
}

std::ostream 			&operator<<( std::ostream & o, Span const & i )
{
	o << "Shortest Span = " << i.shortestSpan() << std::endl;
	o << "Longest Span = " << i.longestSpan() << std::endl;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::vector<long> const	&Span::getVector(void) const
{
	return (this->tab);
}

unsigned int	const	&Span::getSize(void) const
{
	return (this->_n);
}

long			const	&Span::getElem(int index) const
{
	return (this->tab[index]);
}


unsigned int			Span::size(void) const
{
	return (this->tab.size());
}

unsigned int	const	&Span::getCount(void) const
{
	return (this->_count);
}

void					Span::addNumber(int elem)
{
	if (this->getCount() == this->getSize())
		throw ArrayFull();
	this->tab.push_back(elem);
	this->_count++;
}

const char				*Span::ArrayFull::what(void) const throw()
{
	return (Red "Error : array is full" Reset);
}

const char				*Span::NotEnoughElems::what(void) const throw()
{
	return (Red "Error : vector too small to do a span" Reset);
}

const char				*Span::NotEnoughElemsAdded::what(void) const throw()
{
	return (Red "Error : there aren't enough values to do a span" Reset);
}

void					Span::showElem(void)
{
	unsigned int i;

	i = 0;
	while (i < this->_n)
	{
		std::cout << "Tab [" << i << "] : " << this->tab[i] << std::endl;
		i++;
	}
}

long					Span::shortestSpan(void) const
{
	std::vector<long>				array;
	std::vector<long>::iterator		i;
	std::vector<long>::iterator		j;
	long							span;

	if (this->_n < 2)
		throw NotEnoughElems();
	if (this->_count < 2)
		throw NotEnoughElemsAdded();
	
	array = getVector();
	span = UINT_MAX;
	i = array.begin();
	while (i < array.end())
	{
		j = i + 1;
		while (j < array.end())
		{
			//std::cout << "value 1 : " << *i << " | Value 2 : " << *j << " | Diff : " << abs(*i - *j) << std::endl;
			if ((abs(*i - *j)) < span)
				span = (abs(*i - *j));
			//std::cout << span << std::endl;
			j++;
		}
		i++;
	}
	return (span);
}

long					Span::longestSpan(void) const
{
	std::vector<long>				array;
	std::vector<long>::iterator		i;
	std::vector<long>::iterator		j;
	long							span;

	if (this->_n < 2)
		throw NotEnoughElems();
	if (this->_count < 2)
		throw NotEnoughElemsAdded();

	array = getVector();
	sort(array.begin(), array.end());
	span = abs(*(array.begin()) - *(array.end() - 1));
	return (span);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */