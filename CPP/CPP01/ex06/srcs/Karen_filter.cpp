/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen_filter.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:53:04 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/20 21:48:15 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Karen_filter.hpp"

Karen_filter::Karen_filter(void)
{
	std::cout << "Karen constructor called" << std::endl;
}

Karen_filter::~Karen_filter(void)
{
	std::cout << "Karen destructor called" << std::endl;
}

void	Karen_filter::complain(std::string level)
{
	int			flag;
	std::string	list[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void		(Karen_filter::*complain[])(void) = {&Karen_filter::debug, \
		&Karen_filter::info, &Karen_filter::warning, &Karen_filter::error};

	flag = 0;
	for (int i = 0; i < 4; i++)
	{
		if (flag == 1)
			(this->*complain[i])();
		if (list[i] == level)
		{
			(this->*complain[i])();
			flag = 1;
		}
		
	}
	if (flag == 0)
	{
		std::cout << Yellow " You seem to be complaining about something" Reset<< std::endl;
		std::cout << std::endl;
	}
}

void	Karen_filter::debug(void)
{
	std::cout << Reset "[ DEBUG ] : > " << std::endl;
	std::cout << BRed " Currently debugging the process " Reset << std::endl;
	std::cout << std::endl;
}

void	Karen_filter::info(void)
{
	std::cout << Reset "[ INFO ] : > " << std::endl;
	std::cout << BRed " I'd like to have some info " Reset<< std::endl;
	std::cout << std::endl;
}

void	Karen_filter::warning(void)
{
	std::cout << Reset "[ WARNING ] : > " << std::endl;
	std::cout << BRed " !WARNING! : this will be your last" Reset << std::endl;
	std::cout << std::endl;
}

void	Karen_filter::error(void)
{
	std::cout << Reset "[ ERROR ] : > " << std::endl;
	std::cout << BRed " There seems to be an error " Reset << std::endl;
	std::cout << std::endl;
}