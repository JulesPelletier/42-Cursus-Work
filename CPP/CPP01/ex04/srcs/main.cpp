/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:46:41 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/20 15:21:56 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Replace.hpp"

int	display_error(int n)
{
	std::cout << BRed "Error : " Reset;
	if (n == 1)
		std::cout << Red "Not enough params : ./replace <filename> <string1> <string2>" Reset << std::endl;
	if (n == 2)
		std::cout << Red "One of the params is NULL" Reset << std::endl;
	if (n == 3)
		std::cout << Red "The file doesn't exist" Reset << std::endl;
	if (n == 4)
		std::cout << Red "One of the two strings is empty (or both)" Reset << std::endl;
	return (-1);
}

int	start(Replace *Replace, char **av)
{
	std::string	res;

	if (Replace->createFile(av[1]) == -1)
		return (display_error(3));
	res = Replace->replaceStrings(av[2], av[3]);
	if (res == "")
		return (display_error(4));
	std::cout << Cyan "New content after replace : >" Reset << std::endl;
	std::cout << res << std::endl;

	return (0);
}

int	main(int ac, char **av)
{
	Replace	Replace;
	
	(void)av;
	if (ac != 4)
		return (display_error(1));
	if (start(&Replace, av) == -1)
	{
		std::cout << Yellow "Exiting program ....." Reset << std::endl;
		return (-1);
	}
	return (0);
}