/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:15:29 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/07 19:36:53 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("ShrubberyForm", 145, 137), _target("Default")
{
	std::cout << Yellow "Default constructor called for ShrubberyForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyForm", 145, 137), _target(target)
{
	std::cout << Yellow "Default constructor called for ShrubberyForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) : Form(src), _target("target")
{
	std::cout << Purple "Copy constructor called for ShrubberyForm" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << Yellow "Default destructor called for ShrubberyForm" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_target = rhs.getTarget();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i )
{
	o << Blue "The file name is " Reset << i.getTarget() + "_shrubbery" << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string	const					&ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void						ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	this->checkGrade(executor);
	
	std::stringstream	content;
	std::string			str;
	std::string			file;
	
	content << Reset "          .     .  .      +     .      .          ."<< std::endl;
	content << "     .       .      .     #       .           ."<< std::endl;
	content << "        .      .         ###            .      .      ." << std::endl;
	content << "      .      .   '#:. .:##'##:. .:#'  .      ." << std::endl;
	content << "          .      . '####'###'####'  ."<< std::endl;
	content << "       .     '#:.    .:#'###'#:.    .:#'  .        .       ."<< std::endl;
	content << "  .             '#########'#########'        .        ."<< std::endl;
	content << "        .    '#:.  '####'###'####'  .:#'   .       ."<< std::endl;
	content << "     .     .  '#######''##'##''#######'                  ."<< std::endl;
	content << "                .'##'#####'#####'##''           .      ."<< std::endl;
	content << "    .   '#:. ...  .:##'###'###'##:.  ... .:#'     ."<< std::endl;
	content << "      .     '#######'##'#####'##'#######'      .     ."<< std::endl;
	content << "    .    .     '#####''#######''#####'    .      ."<< std::endl;
	content << "            .     ''      000      '    .     ."<< std::endl;
	content << "        .         .   .   000     .        .       ."<< std::endl;
	content << " .. .. ..................O000O........................ ......"<< std::endl;

	str = content.str();
	file = this->getTarget() + "_shrubbery";
	std::ofstream ofs(file.c_str());
	ofs << str;
	ofs.close();
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */