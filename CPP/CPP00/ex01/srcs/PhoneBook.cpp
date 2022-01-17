/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:39:55 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/17 18:40:26 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

// DISPLAY

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

int	display_full(void)
{
	std::cout << std::endl;
	std::cout << " ! Your phonebook is already Full ! " << std::endl;
	std::cout << std::endl;
	return (1);
}

void	print_string(std::string string)
{
	if (string.size() <= 10)
		while (string.length() < 10)
            string = string.insert(0, " ");
	else
	{
		string = string.substr(0, 10);
		string = string.insert(9, ".");
	}
	std::cout << string;
}

void	print_line(PhoneBook *book, int i)
{
	print_string(std::to_string(i + 1));
	std::cout << "|";
	print_string(book->list[i].first_name());
	std::cout << "|";
	print_string(book->list[i].last_name());
	std::cout << "|";
	print_string(book->list[i].nickname());
	std::cout << "|" << std::endl;
}

// COMMANDS

void	ft_end(void)
{
	std::cout << std::endl;
	std::cout << GREEN"You are exiting the phonebook" << std::endl;
	std::cout << std::endl;
}

int	ft_add(PhoneBook *book)
{
	int	i;

	i = 0;
	while (book->list[i].empty() == 0 && i < 8)
		i++;
	if (i == 8)
		return (display_full());
	book->list[i].get_info();
	book->list[i].is_empty = 0;
	return (0);
}


int	ft_search(PhoneBook *book)
{
	int	i;
	int	index;

	i = 0;
	index = -1;
	std::cout << "     index|first name| last name|  nickname" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
	while (book->list[i].empty() == 0)
	{
		print_line(book, i);
		i++;
	}
	std::cout << "Get info of contact number : > " && std::cin >> index;
	if (index <= 0 || index > 8 || book->list[i - 1].is_empty == 1)
		return (-1);
	else if ((index >= 1 && index <= 8) && book->list[i - 1].is_empty == 0)
		print_line(book, index - 1);
	return (0);
}

// UTILS

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

void	display_wrong_input()
{
	std::cout << RED"The index you entered cannot be linked to any contact"RESET << std::endl;
}

int	start_menu(std::string input, PhoneBook *book)
{
	if (input == "EXIT")
	{
		ft_end();
		return (-1);
	}
	if (input == "ADD")
	{
		ft_add(book);
		return (1);
	}
	if (input == "SEARCH")
	{
		if (ft_search(book) == -1)
		{
			display_wrong_input();
			return (0);
		}
		return (2);
	}
	else
	{
		display_wrong_command();
		return (0);
	}
}

void	start_loop(void)
{
	int				count;
	std::string		input;
	int				res;
	PhoneBook		book;

	count = 0;
	while (1)
	{
		std::cout << BLUE"What would you like to do ? > "CYAN;
		std::cin >> input;
		input = ft_uppercase(input);
		res = start_menu(input, &book);
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