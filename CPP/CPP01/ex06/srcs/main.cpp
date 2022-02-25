/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:54:25 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/20 21:45:14 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Karen_filter.hpp"

void	display_title(void)
{
	std::cout << "  _  __          _____  ______ _   _ " << std::endl;
	std::cout << " | |/ /    /\\   |  __ \\|  ____| \\ | |" << std::endl;
	std::cout << " | ' /    /  \\  | |__) | |__  |  \\| |" << std::endl;
	std::cout << " |  <    / /\\ \\ |  _  /|  __| | . ` |" << std::endl;
	std::cout << " | . \\  / ____ \\| | \\ \\| |____| |\\  |" << std::endl;
	std::cout << " |_|\\_\\/_/    \\_\\_|  \\_\\______|_| \\_|" << std::endl;

}

int	main(int ac, char **av)
{	
	if (ac != 2)
	{
		std::cout << "Two params needed : ./karen_filter <category>" << std::endl;
		return (0);
	}	

	std::string		input;
	Karen_filter	karen_filter;
	
	karen_filter.complain(av[1]);
	return (0);
}