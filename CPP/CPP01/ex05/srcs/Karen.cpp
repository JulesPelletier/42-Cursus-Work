/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:53:04 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/20 21:38:23 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Karen.hpp"

Karen::Karen(/* args */)
{
	std::cout << "Karen constructor called" << std::endl;
}

Karen::~Karen()
{
	std::cout << "Karen destructor called" << std::endl;
}

void	Karen::complain(std::string level)
{

	std::string	list[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void		(Karen::*complain[])(void) = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};

	for (int i = 0; i < 4; i++)
	{
		if (list[i] == level)
			(this->*complain[i])();
	}
}

void	Karen::debug(void)
{
	std::cout << BRed " Currently debugging the process " Reset << std::endl;
}

void	Karen::info(void)
{
	std::cout << BRed " I'd like to have some info " Reset<< std::endl;
}

void	Karen::warning(void)
{
	std::cout << BRed " !WARNING! : this will be your last" Reset << std::endl;
}

void	Karen::error(void)
{
	std::cout << BRed " There seems to be an error " Reset << std::endl;
}