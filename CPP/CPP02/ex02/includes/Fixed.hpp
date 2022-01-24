/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:53:39 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/24 14:29:16 by julpelle         ###   ########.fr       */
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

		Fixed 					& operator=( Fixed const & rhs );

		bool					operator>(Fixed const & rhs);
		bool					operator<(Fixed const & rhs);
		bool					operator>=(Fixed const & rhs);
		bool					operator<=(Fixed const & rhs);
		bool					operator!=(Fixed const & rhs);
		bool					operator==(Fixed const & rhs);

		Fixed					operator+(Fixed const & rhs);
		Fixed					operator-(Fixed const & rhs);
		Fixed					operator*(Fixed const & rhs);
		Fixed					operator/(Fixed const & rhs);

		Fixed					&operator++(void);
		Fixed					operator++(int);
		Fixed					&operator--(void);
		Fixed					operator--(int);

		static Fixed			&min(Fixed &a, Fixed &b);
		static Fixed			&max(Fixed &a, Fixed &b);
		static Fixed const		&min(Fixed const &a, Fixed const &b);
		static Fixed const 		&max(Fixed const &a, Fixed const &b);

		int						getRawBits(void) const;
		void					setRawBits(int const raw);
		float 					toFloat(void) const;
		int 					toInt(void) const;

	private:
		int						val;
		static const int		bits = 8;
};

std::ostream	& operator<<(std::ostream & os, Fixed const & rhs);
Fixed			&min(Fixed &a, Fixed &b);
Fixed			&max(Fixed &a, Fixed &b);

#endif /* *********************************************************** FIXED_H */