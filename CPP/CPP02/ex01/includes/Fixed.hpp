/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:53:39 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/21 14:57:17 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <ostream>
# include <math.h>

# include "Colors.hpp"

class Fixed
{

	public:

		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed( const Fixed& src );
		~Fixed();

		Fixed 			& operator=( Fixed const & rhs );


		int				getRawBits(void) const;
		void			setRawBits(int const raw);
		float 			toFloat(void) const;
		int 			toInt(void) const;

	private:
		int					val;
		static const int	bits = 8;
};

std::ostream	& operator<<(std::ostream & os, Fixed const & rhs);

#endif /* *********************************************************** FIXED_H */