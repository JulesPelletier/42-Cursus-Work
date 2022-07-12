/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IterRev.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:07:26 by julpelle          #+#    #+#             */
/*   Updated: 2022/06/04 17:27:38 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITERREV_HPP
# define ITERREV_HPP

# include "../All.hpp"

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
			IterRev(const IterRev<iterator_type> &it);

			// Destructor
			~IterRev(void);

			// Operators
			iterator_type		base() const;
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

			// Variables
			iterator_type				_base;
			
		private:
			template <class Iter2>
			friend bool
			operator==(const IterRev<Iter2> &lhs, const IterRev<Iter2> &rhs);
			template <class Iter2>
			friend bool
			operator<(const IterRev<Iter2> &lhs, const IterRev<Iter2> &rhs);
			template <class Iter2>
			friend typename Iter2::difference_type
			operator-(const IterRev<Iter2> &lhs, const IterRev<Iter2> &rhs);
	};

	// Constructors
	template <class Iterator>
	IterRev<Iterator>::IterRev(void) : _base(0)
	{
	}

	template <class Iterator>
	IterRev<Iterator>::IterRev(iterator_type it) : _base(it)
	{
	}

	template <class Iterator>
	IterRev<Iterator>::IterRev(const IterRev<Iterator> &it) : _base(it._base)
	{
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
		_base = it._base;
		return (*this);
	}

	template <class Iterator>
	typename Iterator::reference
	IterRev<Iterator>::operator*(void) const
	{
		Iterator	tmp(_base);
		
		return (*(--tmp));
	}

	template <class Iterator>
	typename Iterator::pointer
	IterRev<Iterator>::operator->(void) const
	{
		Iterator	tmp(_base);

		return ((--tmp).operator->());
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
		--_base;
		return (*this);
	}

	template <class Iterator>
	IterRev<Iterator>
	IterRev<Iterator>::operator++(int n)
	{
		Iterator	tmp(*this);

		--_base;
		(void)n;
		return (IterRev<Iterator>(tmp));
	}

	template <class Iterator>
	IterRev<Iterator>
	&IterRev<Iterator>::operator--(void)
	{
		++_base;
		return (*this);
	}

	template <class Iterator>
	IterRev<Iterator>
	IterRev<Iterator>::operator--(int n)
	{
		Iterator	tmp(*this);

		(void)n;
		++_base;
		return (IterRev<Iterator>(tmp));
	}


	template <class Iterator>
	IterRev<Iterator>		
	IterRev<Iterator>::operator+(difference_type n) const
	{
		return (IterRev<Iterator>(_base - n));
	}

	template <class Iterator>
	IterRev<Iterator>		
	IterRev<Iterator>::operator-(difference_type n) const
	{
		return (IterRev<Iterator>(_base + n));
	}
	
	template <class Iterator>
	IterRev<Iterator>		
	&IterRev<Iterator>::operator+=(difference_type n)
	{
		_base = _base + n;
		return (*this);
	}

	template <class Iterator>
	IterRev<Iterator>		
	&IterRev<Iterator>::operator-=(difference_type n)
	{
		_base = _base - n;
		return (*this);
	}

	template <class Iterator>
	bool
	operator==(const IterRev<Iterator> &lhs, const IterRev<Iterator> &rhs)
	{
		return (lhs._base == rhs._base);
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
		return (lhs._base > rhs._base);
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
		return (rhs._base - lhs._base);
	}
	
}	// end of namespace

# endif