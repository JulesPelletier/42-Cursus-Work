/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:32:14 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/20 15:21:20 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Replace.hpp"

Replace::Replace(void)
{
	//std::cout << "Constructor called !" << std::endl;
}

Replace::~Replace()
{
	//std::cout << "Destructor called !" << std::endl;
}

int		Replace::createFile(std::string file)
{
	if (file == "")
		return (-1);
	this->_input_file.open(file);
	
	this->_output_file = file + ".replace";
	this->_input_file >> this->_original;
	this->_replace = this->_original.substr(0, this->_original.length());
	std::cout << Cyan"Moved content" Reset << std::endl;
	std::cout << std::endl;
	std::cout << Cyan"Original content" Reset << std::endl;
	std::cout << this->_original << std::endl;
	std::cout << std::endl;
	std::cout << Cyan"New content" Reset << std::endl;
	std::cout << this->_replace << std::endl;
	std::cout << std::endl;
	//std::cout << "Input file : " << file << std::endl;
	//std::cout << "Output file : " <<  this->_output_file << std::endl;
	return (0);
}

std::string	Replace::replaceStrings(std::string s1, std::string s2)
{
	size_t		ret;
	size_t		i;

	if (s1 == "" || s2 == "")
		return (NULL);
	i = 0;
	ret = 0;
	while ((ret = this->_replace.find(s1, i)) != std::string::npos)
	{
		this->_replace.insert(ret, s2);
		this->_replace.erase(ret + s2.length(), s1.length());
		i = ret + s2.length();
	}
	return (this->_replace);
}
