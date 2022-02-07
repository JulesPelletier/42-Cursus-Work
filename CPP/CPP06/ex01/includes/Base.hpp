/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:54:29 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/07 23:14:43 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <string>
# include "Colors.hpp"

class Base
{

	public:
		virtual ~Base(void) {}

	private:

};

Base *generate(void);

#endif /* ************************************************************ BASE_H */