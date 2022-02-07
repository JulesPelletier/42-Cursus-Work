/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:50:42 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/07 20:03:54 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern(void)
{
	std::cout << Yellow "Default constructor called for Intern" Reset << std::endl;
}

Intern::Intern( const Intern & src )
{
	(void)src;
	std::cout << Purple "Copy constructor called for Intern" Reset << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern(void)
{
	std::cout << Yellow "Default destructor called for Intern" Reset << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	if ( this != &rhs )
		return (*this);
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Intern const & i )
{
	(void)i;
	o << "Intern created the form" << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

Form			*Intern::makeForm(std::string type, std::string target)
{
	Form *form;
	if (type == "PresidentialPardonForm")
		form = new PresidentialPardonForm(target);
	if (type == "RobotomyRequestForm")
		form = new RobotomyRequestForm(target);
	if (type == "ShrubberyCreationForm")
		form = new ShrubberyCreationForm(target);
	std::cout << Green "Intern created the form" Reset << std::endl;
	return (form);
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */