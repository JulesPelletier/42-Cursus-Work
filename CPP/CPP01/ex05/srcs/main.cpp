/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:54:25 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/20 16:26:35 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Karen.hpp"

void	display_title(void)
{
	std::cout << "  _  __          _____  ______ _   _ " << std::endl;
	std::cout << " | |/ /    /\\   |  __ \\|  ____| \\ | |" << std::endl;
	std::cout << " | ' /    /  \\  | |__) | |__  |  \\| |" << std::endl;
	std::cout << " |  <    / /\\ \\ |  _  /|  __| | . ` |" << std::endl;
	std::cout << " | . \\  / ____ \\| | \\ \\| |____| |\\  |" << std::endl;
	std::cout << " |_|\\_\\/_/    \\_\\_|  \\_\\______|_| \\_|" << std::endl;

}

int	main(void)
{
	std::string		input;
	Karen			karen;
	
	display_title();
	while (1)
	{
		std::cout << Cyan "Enter the level of command you want to display : >  " Reset << std::endl;
		std::cin >> input;
		karen.complain(input);
	}
	return (0);
}