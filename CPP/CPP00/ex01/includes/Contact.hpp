/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:59:08 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/17 18:17:52 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

// Libraries
# include <iostream>
# include <string>

// Class Prototypes
class	Contact;

// CLass Definitions
class Contact
{
	public:
		Contact();
		~Contact();

		int		is_empty;
		int		empty();
		void	get_info();
		void	display_info();
		std::string	first_name();
		std::string	last_name();
		std::string	nickname();
		
	private:
		std::string		_first_name;
		std::string		_last_name;
		std::string		_nickname;
		std::string		_phone_number;
		std::string		_darkest_secret;
};

#endif /* ********************************************************* CONTACT_H */