/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:14:16 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/07 19:37:20 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm(void) : Form("RobotomyForm", 25, 5), _target("Default")
{
	std::cout << Yellow "Default constructor called for RobotomyRequestForm" Reset << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyForm", 25, 5), _target(target)
{
	std::cout << Yellow "Copy constructor called for RobotomyRequestForm" Reset << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) : Form(src), _target("target")
{
	std::cout << Purple "Copy constructor called for RobotomyRequestForm" Reset << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << Yellow "Default destructor called for RobotomyRequestForm" Reset << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_target = rhs.getTarget();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i )
{
	o << Blue << i.getTarget() << Reset " makes a kind of Brrrrrr sound " << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string			const	&RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void 						RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	this->checkGrade(executor);
	
	std::cout << "    ..... BbrrrrrrrrrrrrrBrrrrrrrrr ......" << std::endl;
	std::cout << "... BbrrrrrrrBrrrr BbrrrrrrrBrrrr ......" << std::endl;
	std::cout << "    ..... BbrrrrrrrrrrrrrBrrrrrrrrr ......" << std::endl;
	std::cout << "... BbrrrrrrrBrrrr BbrrrrrrrBrrrr ......" << std::endl;
	std::cout << "    ..... BbrrrrrrrrrrrrrBrrrrrrrrr ......" << std::endl;
	std::cout << "... BbrrrrrrrBrrrr BbrrrrrrrBrrrr ......" << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */