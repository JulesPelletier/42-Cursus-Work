/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterRev.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:07:26 by julpelle          #+#    #+#             */
/*   Updated: 2022/08/23 15:55:19 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITERREV_HPP
# define ITERREV_HPP

# include "iterRev.hpp"

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
			IterRev(iterator_type it);
			IterRev(const IterRev<Iterator> & rhs);

			// Destructors
			virtual ~IterRev(void);

			// Operators
			IterRev& 		operator=( const IterRev<Iterator>& rhs);
			iterator_type 	current() const;
			reference 		operator*() const;
			pointer 		operator->() const;
			reference 		operator[](difference_type n) const;
			IterRev& 		operator++();
			IterRev& 		operator--();
			IterRev 		operator++(int);
			IterRev 		operator--(int);
			IterRev 		operator+( difference_type n ) const;
			IterRev 		operator-( difference_type n ) const;
			IterRev& 		operator+=( difference_type n );
			IterRev& 		operator-=( difference_type n );

		protected :
			iterator_type	base;
			
	};

	template <class Iterator>
	IterRev<Iterator>::IterRev(void)
	{
		base = iterator_type();
	}
	
	template <class Iterator>
	IterRev<Iterator>::IterRev(iterator_type it) : base(it)
	{
		base = it;
	}
	
	template <class Iterator>
	IterRev<Iterator>::IterRev(const IterRev<Iterator> & rhs)
	{
		*this = rhs;
	}

	template <class Iterator>
	IterRev<Iterator>::~IterRev(void)
	{
	}

	template <class Iterator>
	IterRev<Iterator>
	&IterRev<Iterator>::operator=( const IterRev<Iterator>& rhs)
	{
		base = rhs.current();
		return (*this);
	}
	
	template <class Iterator>
	typename IterRev<Iterator>::iterator_type
	IterRev<Iterator>::current() const
	{
		return base;
	}

	template <class Iterator>
	typename IterRev<Iterator>::reference
	IterRev<Iterator>::operator*() const
	{
		iterator_type tmp = base;
		return (*(--tmp));
	}
	
	template <class Iterator>
	typename IterRev<Iterator>::pointer
	IterRev<Iterator>::operator->() const
	{
		iterator_type tmp = base;
		return (&(*(--tmp)));
	}
	
	template <class Iterator>
	typename IterRev<Iterator>::reference
	IterRev<Iterator>::operator[](difference_type n) const
	{
		return (base[-n - 1]);
	}
	
	template <class Iterator>
	IterRev<Iterator>
	&IterRev<Iterator>::operator++()
	{
		base--;
		return (*this);
	}
	
	template <class Iterator>
	IterRev<Iterator>
	&IterRev<Iterator>::operator--()
	{
		base++;
		return (*this);
	}
	
	template <class Iterator>
	IterRev<Iterator>
	IterRev<Iterator>::operator++(int)
	{
		IterRev tmp = *this;

		++(*this);
		return (tmp);
	}
	
	template <class Iterator>
	IterRev<Iterator>
	IterRev<Iterator>::operator--(int)
	{
		IterRev tmp = *this;

		--(*this);
		return (tmp);
	}
	
	template <class Iterator>
	IterRev<Iterator>
	IterRev<Iterator>::operator+( difference_type n ) const
	{
		return IterRev(base + n);
	}
	
	template <class Iterator>
	IterRev<Iterator>
	IterRev<Iterator>::operator-( difference_type n ) const
	{
		return IterRev(base - n);
	}
	
	template <class Iterator>
	IterRev<Iterator>
	&IterRev<Iterator>::operator+=( difference_type n )
	{
		base += n;
		return (*this);
	}
	
	template <class Iterator>
	IterRev<Iterator>
	&IterRev<Iterator>::operator-=( difference_type n )
	{
		base -= n;
		return (*this);
	}

	template< class Iterator>
	bool operator==( const IterRev<Iterator>& lhs, const IterRev<Iterator>& rhs )
	{
		return lhs.base() == rhs.base();
	}
	template< class Iterator>
	bool operator!=( const IterRev<Iterator>& lhs, const IterRev<Iterator>& rhs )
	{
		return lhs.base() != rhs.base();
	}
	template< class Iterator>
	bool operator>( const IterRev<Iterator>& lhs, const IterRev<Iterator>& rhs )
	{
		return lhs.base() < rhs.base();
	}
	template< class Iterator>
	bool operator>=( const IterRev<Iterator>& lhs, const IterRev<Iterator>& rhs )
	{
		return lhs.base() <= rhs.base();
	}
	template< class Iterator>
	bool operator<( const IterRev<Iterator>& lhs, const IterRev<Iterator>& rhs )
	{
		return lhs.base() > rhs.base();
	}
	template< class Iterator>
	bool operator<=( const IterRev<Iterator>& lhs, const IterRev<Iterator>& rhs )
	{
		return lhs.base() >= rhs.base();
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