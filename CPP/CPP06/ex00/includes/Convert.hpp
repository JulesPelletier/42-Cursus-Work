/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:11:49 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/07 20:50:06 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <string>
# include <cmath>
# include <limits.h>
# include "Colors.hpp"

class Convert
{

	public:

		Convert(void);
		Convert(std::string arg);
		Convert( Convert const & src );
		~Convert(void);

		Convert 			&operator=( Convert const & rhs );
		std::string	const	&getArg(void) const;
		long double	const	&getForm(void) const;
		void				convChar(void) const;
		void				convInt(void) const;
		void				convFloat(void) const;
		void				convDouble(void) const;
		

	private:
		std::string		_arg;
		long double		_form;

};

std::ostream &			operator<<( std::ostream & o, Convert const & i );

#endif /* ********************************************************* CONVERT_H */