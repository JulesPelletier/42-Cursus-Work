/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterRev.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:07:26 by julpelle          #+#    #+#             */
/*   Updated: 2022/08/23 15:18:08 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITERREV_HPP
# define ITERREV_HPP

# include "iterTraits.hpp"

namespace ft	{

	template <class Iterator>
	class IterRev
	{
		public:
			// Types
			typedef Iterator								iterator_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::iterator_category	iterator_category;
			
			// Constructors
			IterRev(void);
			explicit IterRev(iterator_type it);
			IterRev(const IterRev<iterator_type> &it);

			// Destructor
			virtual ~IterRev(void);

			// Operators
			iterator_type		current(void) const;
			IterRev				&operator=(const IterRev &it);
			reference			operator*(void) const;
			pointer				operator->(void) const;
			reference			operator[](difference_type n) const;
			IterRev				&operator++(void);
			IterRev				operator++(int n);
			IterRev				&operator--(void);
			IterRev				operator--(int n);
			IterRev				operator+(difference_type n) const;
			IterRev				operator-(difference_type n) const;
			IterRev				&operator+=(difference_type n);
			IterRev				&operator-=(difference_type n);

		protected:
			// Variables
			iterator_type		base;
			
	};

	// Constructors
	template <class Iterator>
	IterRev<Iterator>::IterRev(void)
	{
		base = iterator_type();
	}

	template <class Iterator>
	IterRev<Iterator>::IterRev(iterator_type it) : base(it)
	{
	}

	template <class Iterator>
	IterRev<Iterator>::IterRev(const IterRev<Iterator> &it)
	{
		*this = it;
	}

	//  Destructor
	template <class Iterator>
	IterRev<Iterator>::~IterRev(void)
	{
	}

	template <class Iterator>
	IterRev<Iterator>
	&IterRev<Iterator>::operator=(const IterRev &it)
	{
		if (&it == this)
			return (*this);
		base = it.base;
		return (*this);
	}
	
	template <class Iterator>
	typename Iterator::iterator_type
	IterRev<Iterator>::current(void) const
	{
		Iterator	tmp(base);
		
		return (*(--tmp));
	}

	template <class Iterator>
	typename Iterator::reference
	IterRev<Iterator>::operator*(void) const
	{
		Iterator	tmp(base);
		
		return (*(--tmp));
	}

	template <class Iterator>
	typename Iterator::pointer
	IterRev<Iterator>::operator->(void) const
	{
		Iterator	tmp(base);

		return (&(*(--tmp)));
	}

	template <class Iterator>
	typename Iterator::reference
	IterRev<Iterator>::operator[](difference_type n) const
	{
		return (*((*this + n)));
	}


	template <class Iterator>
	IterRev<Iterator>
	&IterRev<Iterator>::operator++(void)
	{
		--base;
		return (*this);
	}

	template <class Iterator>
	IterRev<Iterator>
	IterRev<Iterator>::operator++(int n)
	{
		Iterator	tmp(*this);

		--base;
		(void)n;
		return (IterRev<Iterator>(tmp));
	}

	template <class Iterator>
	IterRev<Iterator>
	&IterRev<Iterator>::operator--(void)
	{
		++base;
		return (*this);
	}

	template <class Iterator>
	IterRev<Iterator>
	IterRev<Iterator>::operator--(int n)
	{
		Iterator	tmp(*this);

		(void)n;
		++base;
		return (IterRev<Iterator>(tmp));
	}


	template <class Iterator>
	IterRev<Iterator>		
	IterRev<Iterator>::operator+(difference_type n) const
	{
		return (IterRev<Iterator>(base - n));
	}

	template <class Iterator>
	IterRev<Iterator>		
	IterRev<Iterator>::operator-(difference_type n) const
	{
		return (IterRev<Iterator>(base + n));
	}
	
	template <class Iterator>
	IterRev<Iterator>		
	&IterRev<Iterator>::operator+=(difference_type n)
	{
		base = base + n;
		return (*this);
	}

	template <class Iterator>
	IterRev<Iterator>		
	&IterRev<Iterator>::operator-=(difference_type n)
	{
		base = base - n;
		return (*this);
	}

	template <class Iterator>
	bool
	operator==(const IterRev<Iterator> &lhs, const IterRev<Iterator> &rhs)
	{
		return (lhs.base == rhs.base);
	}
	
	template <class Iterator>
	bool
	operator!=(const IterRev<Iterator> &lhs, const IterRev<Iterator> &rhs)
	{
		return (!(lhs == rhs));
	}
	
	template <class Iterator>
	bool
	operator<(const IterRev<Iterator> &lhs, const IterRev<Iterator> &rhs)
	{
		return (lhs.base > rhs.base);
	}
	
	template <class Iterator>
	bool
	operator<=(const IterRev<Iterator> &lhs, const IterRev<Iterator> &rhs)
	{
		return (!(lhs > rhs));
	}
	
	template <class Iterator>
	bool
	operator>(const IterRev<Iterator> &lhs, const IterRev<Iterator> &rhs)
	{
		return (rhs < lhs);
	}
	
	template <class Iterator>
	bool
	operator>=(const IterRev<Iterator> &lhs, const IterRev<Iterator> &rhs)
	{
		return (!(lhs < rhs));
	}
	
	template <class Iterator>
	IterRev<Iterator>
	operator+(typename IterRev<Iterator>::difference_type n, const IterRev<Iterator> &rev_it)
	{
		return (rev_it + n);
	}
	
	template <class Iterator>
	typename Iterator::difference_type
	operator-(const IterRev<Iterator> &lhs, const IterRev<Iterator> &rhs)
	{
		return (rhs.base - lhs.base);
	}
	
}	// end of namespace

# endif