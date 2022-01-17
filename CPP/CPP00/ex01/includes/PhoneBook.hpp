/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:43:48 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/14 17:02:23 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

// Libraries
#include <iostream>
#include <ctype.h>

# include "../includes/Contact.hpp"

# define RESET	"\033[0m"
# define BLACK   "\033[30m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"

// Class Prototypes
class	PhoneBook;

// Class Definitions
class	PhoneBook
{
	public:
		Contact	list[8];

	private:
};

// Functions
void			display_title(void);
void			display_instructions(void);
void			end(void);
int				start_menu(std::string input, PhoneBook book);
std::string		ft_uppercase(std::string string);
void			start_loop(void);
#endif