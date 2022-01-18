/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:46:41 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/18 13:56:43 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/replace.hpp"

int	display_error(int n)
{
	if (n == 1)
		std::cout << "Not enough params : ./replace <filename> <string1> <string2>" << std::endl;
	if (n == 2)
		std::cout << "One of the params is NULL" << std::endl;
	return (-1);
}

int	main(int ac, char **av)
{
	std::string	s1;
	std::string	s2;
	std::string	file;
	std::ifstream	ifs;
	std::ofstream	ofs;
	
	if (ac != 4)
		return (display_error(1));
	file = av[1];
	s1 = av[2];
	s2 = av[3];
	ifs.open(file, std::ifstream::in);
	if (s1.length() == 0 || s2.length() == 0)
		return (display_error(2));
	return (0);
}