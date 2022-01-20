/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen_filter.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:52:43 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/20 21:42:53 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

#include <iostream>
#include <string.h>
#include "Colors.hpp"

class Karen_filter
{
	public:
		Karen_filter();
		~Karen_filter();

		void	complain(std::string level);
		void	start(Karen_filter *karen);
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	
	private:

};

void	display_title(void);


#endif