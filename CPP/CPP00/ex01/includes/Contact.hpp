/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:59:08 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/14 15:53:04 by julpelle         ###   ########.fr       */
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

	private:
		std::string		first_name;
		std::string		last_name;
		std::string		nickname;
		std::string		phone_number;
		std::string		darkest_secret;
};

#endif /* ********************************************************* CONTACT_H */