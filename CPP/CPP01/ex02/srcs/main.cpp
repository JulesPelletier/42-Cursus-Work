/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:19:03 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/17 23:29:58 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

# define RESET	"\033[0m"
# define BLACK   "\033[30m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"

int main(int ac, char **av)
{
	std::string str = "HI THIS IS BRAIN";
	std::string	*ptr = &str;
	std::string	&ref = str;

	(void)ac;
	(void)av;
	std::cout << CYAN"Adress of the string\t\t\t\t: "RESET << &str << std::endl;
	std::cout << CYAN"Adress of the string using stringPTR \t\t: "RESET << &(*ptr) << std::endl;
	std::cout << CYAN"Adress of the string using stringREF \t\t: "RESET << &ref << std::endl;
	std::cout << std::endl;
	std::cout << CYAN"String\t\t\t\t\t\t: "RESET << str << std::endl;
	std::cout << CYAN"String using stringPTR \t\t\t\t: "RESET << *ptr << std::endl;
	std::cout << CYAN"String using stringREF \t\t\t\t: "RESET << ref << std::endl;
	return (0);
}