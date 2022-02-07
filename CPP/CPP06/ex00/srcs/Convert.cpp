/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:11:34 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/07 21:35:03 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Convert.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Convert::Convert(void) : _arg(0), _form(0)
{
	std::cout << Yellow "Default constructor called for Convert" Reset << std::endl;
}

Convert::Convert(std::string arg) : _arg(arg), _form(0)
{
	this->_form = strtold(arg.c_str(), 0);
	std::cout << Yellow "Default constructor called for Convert" Reset << std::endl;
}

Convert::Convert( const Convert & src )
{
	*this = src;
	std::cout << Purple "Copy constructor called for Convert" Reset << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Convert::~Convert(void)
{
	std::cout << Yellow "Default destructor called for Convert" Reset << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Convert &				Convert::operator=( Convert const & rhs )
{
	if ( this != &rhs )
	{
		this->_arg = rhs.getArg();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Convert const & i )
{
	o << "Arg : " << "\"" << i.getArg() << "\"" << std::endl;
	o << "Form : " << i.getForm() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string	const	&Convert::getArg(void) const
{
	return (this->_arg);
}

long double	const	&Convert::getForm(void) const
{
	return (this->_form);
}

void				Convert::convChar(void) const
{
	char	c = static_cast<char>(_form);

	if (c < 0 || c > 126)
		std::cout << Red "The character is not defined" Reset << std::endl;
	else if (c >= 0 && c < 32)
		std::cout << Red "The character is not printable" Reset << std::endl;
	else
		std::cout << Blue "Char value = " Reset << "\'" << c << "\'" << std::endl;
		
}

void				Convert::convInt(void) const
{
	int		i = static_cast<int>(_form);

	std::cout << Blue "Int value = " Reset << i << std::endl;
}

void				Convert::convFloat(void) const
{
	float	f = static_cast<float>(_form);

	std::cout << Blue "Float value = " Reset << f;
	if (_form - f == 0)
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;

}

void				Convert::convDouble(void) const
{
	double	d = static_cast<double>(_form);

	std::cout << Blue "Double value = " Reset << d << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */