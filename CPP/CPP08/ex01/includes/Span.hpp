/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:09:26 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/08 15:32:07 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include "Colors.hpp"
# include <vector>

class Span
{

	public:

		Span(void);
		Span(unsigned int n);
		Span( Span const & src );
		~Span(void);

		Span 					&operator=( Span const & rhs );
		long		 		 	&operator[](int &index);
		unsigned int	const	&getSize(void) const;
		std::vector<long>const	&getVector(void) const;
		long			const	&getElem(int index) const;

		unsigned int			size(void) const;
		unsigned int	const	&getCount(void) const;
		void					addNumber(int elem);
		void					showElem(void);
		long					shortestSpan(void) const;
		long					longestSpan(void) const;

		class					ArrayFull : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

		class					NotEnoughElems : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

		class					NotEnoughElemsAdded : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

	private:
		unsigned int		_n;
		unsigned int		_count;
		std::vector<long>	tab;

};

std::ostream &			operator<<( std::ostream & o, Span const & i );

#endif /* ************************************************************ SPAN_H */