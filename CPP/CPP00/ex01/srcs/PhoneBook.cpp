/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:39:55 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/14 16:13:09 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

void	display_title(void)
{
	std::cout << YELLOW" __  __ ______ _____          _____  _    _  ____  _   _ ______ " << std::endl;
	std::cout << "|  \\/  |  ____/ ____|   /\\   |  __ \\| |  | |/ __ \\| \\ | |  ____|" << std::endl;
	std::cout << "| \\  / | |__ | |  __   /  \\  | |__) | |__| | |  | |  \\| | |__   " << std::endl;
	std::cout << "| |\\/| |  __|| | |_ | / /\\ \\ |  ___/|  __  | |  | | . ` |  __|  " << std::endl;
	std::cout << "| |  | | |___| |__| |/ ____ \\| |    | |  | | |__| | |\\  | |____ " << std::endl;
	std::cout << "|_|  |_|______\\_____/_/    \\_\\_|    |_|  |_|\\____/|_| \\_|______|"RESET << std::endl;
}

void	display_instructions(void)
{
	std::cout << std::endl;
	std::cout << "Here are all the commands available : " << std::endl;
	std::cout << "\t type ADD \t--> to enter a contact." << std::endl;
	std::cout << "\t type SEARCH \t--> to search for a contact." << std::endl;
	std::cout << "\t type EXIT \t--> to exit phonebook." << std::endl;
	std::cout << std::endl;
	std::cout << "Other commands are not tolerated" << std::endl;
	std::cout << std::endl;
}

void	end(void)
{
	std::cout << std::endl;
	std::cout << GREEN"You are exiting the phonebook" << std::endl;
	std::cout << std::endl;
}


std::string	ft_uppercase(std::string string)
{
	int			i;

	i = 0;
	while(string[i])
	{
		string[i] = toupper(string[i]);
		i++;
	}
	return (string);
}

void	display_wrong_command()
{
	std::cout << RED"The command you entered is invalid"RESET << std::endl;
}

int	start_menu(std::string input)
{
	if (input == "EXIT")
	{
		end();
		return (-1);
	}
	if (input == "ADD")
	{
		//add();
		return (1);
	}
	if (input == "SEARCH")
	{
		//search();
		return (2);
	}
	else
	{
		display_wrong_command();
		return (0);
	}
}

void	start_loop(Contact list[8])
{
	int				count;
	std::string		input;
	int				res;

	count = 0;
	while (1)
	{
		std::cout << BLUE"What would you like to do ? > "CYAN;
		std::cin >> input;
		input = ft_uppercase(input);
		res = start_menu(input);
		if (res == -1)
			break;
		if (res == 0)
			count++;
		if (count == 3)
		{
			display_instructions();
			count = 0;
		}
	}
}