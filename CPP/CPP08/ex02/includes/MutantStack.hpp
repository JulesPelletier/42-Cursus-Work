/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:37:10 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/08 16:17:12 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include "Colors.hpp"
# include <stack>
# include <vector>
# include <list>

template<typename T>
class MutantStack : public std::stack<T>
{

	public:

		MutantStack(void);
		MutantStack( MutantStack const & src );
		~MutantStack(void);

		MutantStack &		operator=( MutantStack const & rhs );

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator constant_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator reverse_constant_iterator;

		iterator						begin(void) { return (std::stack<T>::c.begin()); }
		iterator						end(void) { return (std::stack<T>::c.end()); }
		constant_iterator				constant_begin(void) const { return (std::stack<T>::c.begin()); }
		constant_iterator				constant_end(void) const { return (std::stack<T>::c.end()); }
		reverse_iterator				rbegin(void) { return (std::stack<T>::c.rbegin()); }
		reverse_iterator				rend(void) { return (std::stack<T>::c.rend()); }
		reverse_constant_iterator		const_rbegin(void) const { return (std::stack<T>::c.rbegin()); }
		reverse_constant_iterator		const_rend(void) const { return (std::stack<T>::c.rend()); }

	private:

};

template<typename T>
MutantStack<T>::MutantStack(void)
{
	std::cout << Yellow "Default constructor called for Mutantstack" Reset << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack( const MutantStack & src )
{
	this->c = src.c;
	std::cout << Yellow "Copy constructor called for Mutantstack" Reset << std::endl;
}

template<typename T>
MutantStack<T>::~MutantStack(void)
{
	std::cout << Yellow "Default destructor called for Mutantstack" Reset << std::endl;
}

template<typename T>
MutantStack<T> 			&MutantStack<T>::operator=( MutantStack const & rhs )
{
	if ( this != &rhs )
	{
		this->c = rhs.c;
	}
	return *this;
}

/*
template<typename T>
std::ostream 			&operator<<( std::ostream & o, MutantStack<T> const & i )
{
	o << "Begin it= " << i.getValue();
	o << "Begin it value = " << i.getValue();
	o << "End it = " << i.getValue();
	o << "End it value = " << i.getValue();
	return o;
}
*/

#endif /* ***************************************************** MUTANTSTACK_H */