/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:03:03 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/17 18:17:46 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

Contact::Contact()
{
	//std::cout << RESET"Contact constructor called" << std::endl;
	this->is_empty = 1;
}

Contact::~Contact()
{
	//std::cout << RESET"Contact destructor called" << std::endl;
}

int	Contact::empty()
{
	return (this->is_empty);
}

std::string	Contact::first_name()
{
	return (this->_first_name);
}

std::string	Contact::last_name()
{
	return (this->_last_name);
}

std::string	Contact::nickname()
{
	return (this->_nickname);
}

void	Contact::get_info()
{
	int	i;

	i = 0;
	std::cout << std::endl;
	std::cout << RESET"Enter info :" << std::endl;
	std::cout << "First Name : >  "MAGENTA;
	std::cin >> this->_first_name;
	std::cout << RESET"Last Name : >  "MAGENTA;
	std::cin >> this->_last_name;
	std::cout << RESET"Nickname : >  "MAGENTA;
	std::cin >> this->_nickname;
	std::cout << RESET"Phone number : >  "MAGENTA;
	std::cin >> this->_phone_number;
	std::cout << RESET"Darkest Secret : >  "MAGENTA;
	std::cin >> this->_darkest_secret;
}