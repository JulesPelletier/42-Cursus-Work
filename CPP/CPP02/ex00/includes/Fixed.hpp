/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:53:39 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/21 14:21:28 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

#include "Colors.hpp"

class Fixed
{

	public:

		Fixed();
		Fixed( const Fixed& src );
		~Fixed();

		Fixed &		operator=( Fixed const & rhs );

		int			getRawBits(void) const;
		void		setRawBits(int const raw);

	private:
		int					val;
		static const int	bits = 8;
};


#endif /* *********************************************************** FIXED_H */