/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:43:48 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/14 16:08:46 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <ctype.h>

# include "Contact.hpp"

# define RESET	"\033[0m"
# define BLACK   "\033[30m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"

void			display_title(void);
void			display_instructions(void);
void			end(void);
int				start_menu(std::string input);
std::string		ft_uppercase(std::string string);
void			start_loop(void);
#endif