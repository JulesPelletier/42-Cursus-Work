/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:58:06 by julpelle          #+#    #+#             */
/*   Updated: 2022/03/25 16:06:59 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef STACK_HPP
# define STACK_HPP

# include "../All.hpp"
# include "../Iterators/IterRev.hpp"
# include "../Iterators/IterVector.hpp"
# include "../Iterators/Types.hpp"

namespace ft 
{

	template <class T, class Container = std::deque<T> >
	class Stack
	{
		public:
			// Types
			typedef T						value_type;
			typedef size_t 					size_type;
			typedef Container				container_type;
			
			// Constructors
			explicit Stack(const container_type & ctnr = container_type());
			explicit Stack(const Stack &s);

			// Destructor
			~Stack(void);

			// Assignation
			Stack							&operator=(const Stack &s);

			// Capacity		
			bool 							empty (void) const;
			size_type 						size (void) const;
			value_type						&top (void);
			const value_type				&top (void) const;
			void 							push (const value_type& val);
			void 							pop (void);

		private:
			container_type	_cont;
	};
	
	// Constructors

	template <class T, class Container>
	Stack<T, Container>::Stack(const container_type &cntr) : _cont(cntr)
	{
	}

	template <class T, class Container>
	Stack<T, Container>::Stack(const Stack &s) : _cont(s._cont)
	{
	}

	// Destructor
	
	template <class T, class Container>
	Stack<T, Container>::~Stack(void)
	{
	}
	
	// Assignation 

	template <class T, class Container>
	Stack<T, Container>				
	&Stack<T, Container>::operator=(const Stack &s)
	{
		if (this == &s)
			return (*this);
		_cont = s._cont;
		return (*this);
	}

	// Capacity		
	template <class T, class Container>
	bool 							
	Stack<T, Container>::empty (void) const
	{
		return (_cont.empty());
	}
	
	template <class T, class Container>
	typename Stack<T,Container>::size_type 						
	Stack<T, Container>::size (void) const
	{
		return (_cont.size());
	}
	
	template <class T, class Container>
	typename Stack<T,Container>::value_type						
	&Stack<T, Container>::top (void)
	{
		return (_cont.back());
	}
	
	template <class T, class Container>
	const typename Stack<T,Container>::value_type				
	&Stack<T, Container>::top (void) const
	{
		return (_cont.back());

	}
	
	template <class T, class Container>
	void 							
	Stack<T, Container>::push (const value_type& val)
	{
		return (_cont.push_back(val));
	}
	
	template <class T, class Container>
	void 							
	Stack<T, Container>::pop (void)
	{
		return (_cont.pop_back());
	}

	// Relational Operators

	template <class T, class Container>
	bool
	operator==(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return (!(lhs != rhs));
	}
	
	template <class T, class Container>
	bool
	operator!=(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return (lhs < rhs || rhs < lhs);
	}
	
	template <class T, class Container>
	bool
	operator<(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return (lhs._cont < rhs._cont);
	}
	
	template <class T, class Container>
	bool
	operator<=(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return (!(lhs > rhs));
	}
	
	template <class T, class Container>
	bool
	operator>(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return (rhs < lhs);
	}
	
	template <class T, class Container>
	bool
	operator>=(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return (!(lhs < rhs));
	}
	
}	// end of namespace

# endif