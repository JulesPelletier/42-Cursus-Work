/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:04:37 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/17 18:27:07 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

int	main(int ac, char **av)
{
	std::string	input;
	
	(void)ac;
	(void)av;
	std::cout << "Welcome to your phonebook !" << std::endl << std::endl;
	display_title();
	display_instructions();

	start_loop();
	return (0);
}