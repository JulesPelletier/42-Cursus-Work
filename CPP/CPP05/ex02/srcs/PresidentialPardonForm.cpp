/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:11:41 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/07 19:47:43 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

 PresidentialPardonForm:: PresidentialPardonForm(void) : Form("PresidentialForm", 72, 45), _target("Default")
{
	std::cout << Yellow "Default constructor called for PresidentialPardonForm" << std::endl;
}

 PresidentialPardonForm:: PresidentialPardonForm(std::string target) : Form("PresidentialForm", 72, 45), _target(target)
{
	std::cout << Yellow "Default constructor called for PresidentialPardonForm" << std::endl;
}

 PresidentialPardonForm:: PresidentialPardonForm( const  PresidentialPardonForm & src ) : Form(src), _target("target")
{
	std::cout << Purple "Copy constructor called for PresidentialPardonForm" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

 PresidentialPardonForm::~ PresidentialPardonForm(void)
{
	std::cout << Yellow "Default destructor called for PresidentialPardonForm" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

 PresidentialPardonForm &				 PresidentialPardonForm::operator=(  PresidentialPardonForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_target = rhs.getTarget();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o,  PresidentialPardonForm const & i )
{
	(void)i;
	o << Blue << i.getTarget() + " has been forgiven by Zafod Beeblebrox" << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string const 				&PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void							PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	this->checkGrade(executor);

	std::cout << std::endl;
	std::cout << Blue << this->_target << Reset " has been forgiven by Zafod Beeblebrox" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */