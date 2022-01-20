/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:52:43 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/20 16:19:41 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

#include <iostream>
#include <string.h>
#include "Colors.hpp"

class Karen
{
	public:
		Karen();
		~Karen();

		void	complain(std::string level);
		void	start(Karen *karen);
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	
	private:

};

void	display_title(void);


#endif