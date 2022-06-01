/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IterVector.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:02:59 by julpelle          #+#    #+#             */
/*   Updated: 2022/03/25 14:40:14 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITERVECTOR_HPP
# define ITERVECTOR_HPP

# include "../All.hpp"

namespace ft {

	template <class Category, class T, class Distance = std::ptrdiff_t,
		class Pointer = T*, class Reference = T&>
	class IterVector
	{
		public:
			// Types
			typedef T				value_type;
			typedef Pointer			pointer;
			typedef Reference		reference;
			typedef Distance		difference_type;
			typedef Category		iterator_category;
			
			// Constructors
			IterVector(value_type *p = 0);
			IterVector(const IterVector &it);

			// Destructor
			~IterVector(void);

			// Operators
			IterVector				&operator=(const IterVector &it);
			bool					operator==(const IterVector &it) const;
			bool					operator!=(const IterVector &it) const;
			reference				operator*(void);
			pointer					operator->(void);
			reference				operator[](difference_type n) const;
			IterVector				&operator++(void);
			IterVector				operator++(int n);
			IterVector				&operator--(void);
			IterVector				operator--(int n);
			IterVector				operator+(difference_type n) const;
			IterVector				operator-(difference_type n) const;
			IterVector				&operator+=(difference_type n);
			IterVector				&operator-=(difference_type n);

			// Variables
			value_type				*_val;
			
		private:
			//Friendship :
			template <class Cat, class T2, class Dist, class Point, class Refer>
			friend Dist		operator-(const IterVector<Cat, T2, Dist, Point, Refer> &lhs,
				const IterVector<Cat, T2, Dist, Point, Refer> &rhs);
			template <class Cat, class T2, class Dist, class Point, class Refer>
			friend bool		operator<(const IterVector<Cat, T2, Dist, Point, Refer> &lhs,
				const IterVector<Cat, T2, Dist, Point, Refer> &rhs);
		
	};

	// Constructors
	template <class Category, class T, class Distance, class Pointer, class Reference>
	IterVector<Category, T, Distance, Pointer, Reference>::IterVector(value_type *p) : _val(p)
	{
	}

	template <class Category, class T, class Distance, class Pointer, class Reference>
	IterVector<Category, T, Distance, Pointer, Reference>::IterVector(const IterVector<Category, T, Distance, Pointer, Reference> &it) : _val(it._val)
	{
	}

	//  Destructor
	template <class Category, class T, class Distance, class Pointer, class Reference>
	IterVector<Category, T, Distance, Pointer, Reference>::~IterVector(void)
	{
	}

	template <class Category, class T, class Distance, class Pointer, class Reference>
	IterVector<Category, T, Distance, Pointer, Reference>
	&IterVector<Category, T, Distance, Pointer, Reference>::operator=(const IterVector &it)
	{
		if (&it == this)
			return (*this);
		_val = it._val;
		return (*this);
	}

	template <class Category, class T, class Distance, class Pointer, class Reference>
	bool
	IterVector<Category, T, Distance, Pointer, Reference>::operator==(const IterVector &it) const
	{
		return (_val == it._val);
	}

	template <class Category, class T, class Distance, class Pointer, class Reference>
	bool
	IterVector<Category, T, Distance, Pointer, Reference>::operator!=(const IterVector &it) const
	{
		return (!(_val == it._val));
	}

	template <class Category, class T, class Distance, class Pointer, class Reference>
	Reference
	IterVector<Category, T, Distance, Pointer, Reference>::operator*(void)
	{
		return (*_val);
	}

	template <class Category, class T, class Distance, class Pointer, class Reference>
	Pointer
	IterVector<Category, T, Distance, Pointer, Reference>::operator->(void)
	{
		return (_val);
	}

	template <class Category, class T, class Distance, class Pointer, class Reference>
	Reference
	IterVector<Category, T, Distance, Pointer, Reference>::operator[](difference_type n) const
	{
		return (*(_val + n));
	}


	template <class Category, class T, class Distance, class Pointer, class Reference>
	IterVector<Category, T, Distance, Pointer, Reference>
	&IterVector<Category, T, Distance, Pointer, Reference>::operator++(void)
	{
		++_val;
		return (*this);
	}

	template <class Category, class T, class Distance, class Pointer, class Reference>
	IterVector<Category, T, Distance, Pointer, Reference>
	IterVector<Category, T, Distance, Pointer, Reference>::operator++(int n)
	{
		IterVector	tmp(*this);

		++_val;
		(void)n;
		return (tmp);
	}

	template <class Category, class T, class Distance, class Pointer, class Reference>
	IterVector<Category, T, Distance, Pointer, Reference>
	&IterVector<Category, T, Distance, Pointer, Reference>::operator--(void)
	{
		--_val;
		return (*this);
	}

	template <class Category, class T, class Distance, class Pointer, class Reference>
	IterVector<Category, T, Distance, Pointer, Reference>
	IterVector<Category, T, Distance, Pointer, Reference>::operator--(int n)
	{
		IterVector	tmp(*this);

		(void)n;
		--_val;
		return (tmp);
	}


	template <class Category, class T, class Distance, class Pointer, class Reference>
	IterVector<Category, T, Distance, Pointer, Reference>		
	IterVector<Category, T, Distance, Pointer, Reference>::operator+(difference_type n) const
	{
		IterVector	tmp(*this);

		tmp._val = tmp._val + n;
		return (tmp);
	}

	template <class Category, class T, class Distance, class Pointer, class Reference>
	IterVector<Category, T, Distance, Pointer, Reference>		
	IterVector<Category, T, Distance, Pointer, Reference>::operator-(difference_type n) const
	{
		IterVector	tmp(*this);

		tmp._val = tmp._val - n;
		return (tmp);
	}
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	IterVector<Category, T, Distance, Pointer, Reference>		
	&IterVector<Category, T, Distance, Pointer, Reference>::operator+=(difference_type n)
	{
		_val = _val + n;
		return (*this);
	}

	template <class Category, class T, class Distance, class Pointer, class Reference>
	IterVector<Category, T, Distance, Pointer, Reference>		
	&IterVector<Category, T, Distance, Pointer, Reference>::operator-=(difference_type n)
	{
		_val = _val - n;
		return (*this);
	}


	// Friendship

	template <class Category, class T, class Distance, class Pointer, class Reference>
	IterVector<Category, T, Distance, Pointer, Reference>
	operator+(typename IterVector<Category, T, Distance, Pointer, Reference>::
		difference_type n, const IterVector<Category, T, Distance, Pointer, Reference> &v)
	{
		return (v + n);
	}
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	Distance
	operator-(const IterVector<Category, T, Distance, Pointer, Reference> &lhs,
		const IterVector<Category, T, Distance, Pointer, Reference> &rhs)
	{
		return (lhs._val - rhs._val);
	}
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	bool	
	operator<(const IterVector<Category, T, Distance, Pointer, Reference> &lhs,
		const IterVector<Category, T, Distance, Pointer, Reference> &rhs)
	{
		return (lhs._val < rhs._val);
	}
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	bool	
	operator<=(const IterVector<Category, T, Distance, Pointer, Reference> &lhs,
		const IterVector<Category, T, Distance, Pointer, Reference> &rhs)
	{
		return (!(lhs > rhs));
	}
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	bool	
	operator>(const IterVector<Category, T, Distance, Pointer, Reference> &lhs,
		const IterVector<Category, T, Distance, Pointer, Reference> &rhs)
	{
		return (rhs < lhs);
	}
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	bool	
	operator>=(const IterVector<Category, T, Distance, Pointer, Reference> &lhs,
		const IterVector<Category, T, Distance, Pointer, Reference> &rhs)
	{
		return (!(lhs < rhs));
	}

}	// end of namespace

# endif