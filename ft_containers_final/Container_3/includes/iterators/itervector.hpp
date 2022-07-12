/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IterVector.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:02:59 by julpelle          #+#    #+#             */
/*   Updated: 2022/06/26 18:37:32 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITERvector_HPP
# define ITERvector_HPP

# include "../All.hpp"

namespace ft {

	template <class Category, class T, class Distance = std::ptrdiff_t,
		class Pointer = T*, class Reference = T&>
	class Itervector
	{
		public:
			// Types
			typedef T				value_type;
			typedef Pointer			pointer;
			typedef Reference		reference;
			typedef Distance		difference_type;
			typedef Category		iterator_category;
			
			// Constructors
			Itervector(value_type *p = 0);
			Itervector(const Itervector &it);

			// Destructor
			~Itervector(void);

			// Operators
			Itervector				&operator=(const Itervector &it);
			bool					operator==(const Itervector &it) const;
			bool					operator!=(const Itervector &it) const;
			reference				operator*(void);
			pointer					operator->(void);
			reference				operator[](difference_type n) const;
			Itervector				&operator++(void);
			Itervector				operator++(int n);
			Itervector				&operator--(void);
			Itervector				operator--(int n);
			Itervector				operator+(difference_type n) const;
			Itervector				operator-(difference_type n) const;
			Itervector				&operator+=(difference_type n);
			Itervector				&operator-=(difference_type n);

			// Variables
			value_type				*_val;
			
		private:
			//Friendship :
			template <class Cat, class T2, class Dist, class Point, class Refer>
			friend Dist		operator-(const Itervector<Cat, T2, Dist, Point, Refer> &lhs,
				const Itervector<Cat, T2, Dist, Point, Refer> &rhs);
			template <class Cat, class T2, class Dist, class Point, class Refer>
			friend bool		operator<(const Itervector<Cat, T2, Dist, Point, Refer> &lhs,
				const Itervector<Cat, T2, Dist, Point, Refer> &rhs);
		
	};

	// Constructors
	template <class Category, class T, class Distance, class Pointer, class Reference>
	Itervector<Category, T, Distance, Pointer, Reference>::Itervector(value_type *p) : _val(p)
	{
	}

	template <class Category, class T, class Distance, class Pointer, class Reference>
	Itervector<Category, T, Distance, Pointer, Reference>::Itervector(const Itervector<Category, T, Distance, Pointer, Reference> &it) : _val(it._val)
	{
	}

	//  Destructor
	template <class Category, class T, class Distance, class Pointer, class Reference>
	Itervector<Category, T, Distance, Pointer, Reference>::~Itervector(void)
	{
	}

	template <class Category, class T, class Distance, class Pointer, class Reference>
	Itervector<Category, T, Distance, Pointer, Reference>
	&Itervector<Category, T, Distance, Pointer, Reference>::operator=(const Itervector &it)
	{
		if (&it == this)
			return (*this);
		_val = it._val;
		return (*this);
	}

	template <class Category, class T, class Distance, class Pointer, class Reference>
	bool
	Itervector<Category, T, Distance, Pointer, Reference>::operator==(const Itervector &it) const
	{
		return (_val == it._val);
	}

	template <class Category, class T, class Distance, class Pointer, class Reference>
	bool
	Itervector<Category, T, Distance, Pointer, Reference>::operator!=(const Itervector &it) const
	{
		return (!(_val == it._val));
	}

	template <class Category, class T, class Distance, class Pointer, class Reference>
	Reference
	Itervector<Category, T, Distance, Pointer, Reference>::operator*(void)
	{
		return (*_val);
	}

	template <class Category, class T, class Distance, class Pointer, class Reference>
	Pointer
	Itervector<Category, T, Distance, Pointer, Reference>::operator->(void)
	{
		return (_val);
	}

	template <class Category, class T, class Distance, class Pointer, class Reference>
	Reference
	Itervector<Category, T, Distance, Pointer, Reference>::operator[](difference_type n) const
	{
		return (*(_val + n));
	}


	template <class Category, class T, class Distance, class Pointer, class Reference>
	Itervector<Category, T, Distance, Pointer, Reference>
	&Itervector<Category, T, Distance, Pointer, Reference>::operator++(void)
	{
		++_val;
		return (*this);
	}

	template <class Category, class T, class Distance, class Pointer, class Reference>
	Itervector<Category, T, Distance, Pointer, Reference>
	Itervector<Category, T, Distance, Pointer, Reference>::operator++(int n)
	{
		Itervector	tmp(*this);

		++_val;
		(void)n;
		return (tmp);
	}

	template <class Category, class T, class Distance, class Pointer, class Reference>
	Itervector<Category, T, Distance, Pointer, Reference>
	&Itervector<Category, T, Distance, Pointer, Reference>::operator--(void)
	{
		--_val;
		return (*this);
	}

	template <class Category, class T, class Distance, class Pointer, class Reference>
	Itervector<Category, T, Distance, Pointer, Reference>
	Itervector<Category, T, Distance, Pointer, Reference>::operator--(int n)
	{
		Itervector	tmp(*this);

		(void)n;
		--_val;
		return (tmp);
	}


	template <class Category, class T, class Distance, class Pointer, class Reference>
	Itervector<Category, T, Distance, Pointer, Reference>		
	Itervector<Category, T, Distance, Pointer, Reference>::operator+(difference_type n) const
	{
		Itervector	tmp(*this);

		tmp._val = tmp._val + n;
		return (tmp);
	}

	template <class Category, class T, class Distance, class Pointer, class Reference>
	Itervector<Category, T, Distance, Pointer, Reference>		
	Itervector<Category, T, Distance, Pointer, Reference>::operator-(difference_type n) const
	{
		Itervector	tmp(*this);

		tmp._val = tmp._val - n;
		return (tmp);
	}
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	Itervector<Category, T, Distance, Pointer, Reference>		
	&Itervector<Category, T, Distance, Pointer, Reference>::operator+=(difference_type n)
	{
		_val = _val + n;
		return (*this);
	}

	template <class Category, class T, class Distance, class Pointer, class Reference>
	Itervector<Category, T, Distance, Pointer, Reference>		
	&Itervector<Category, T, Distance, Pointer, Reference>::operator-=(difference_type n)
	{
		_val = _val - n;
		return (*this);
	}


	// Friendship

	template <class Category, class T, class Distance, class Pointer, class Reference>
	Itervector<Category, T, Distance, Pointer, Reference>
	operator+(typename Itervector<Category, T, Distance, Pointer, Reference>::
		difference_type n, const Itervector<Category, T, Distance, Pointer, Reference> &v)
	{
		return (v + n);
	}
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	Distance
	operator-(const Itervector<Category, T, Distance, Pointer, Reference> &lhs,
		const Itervector<Category, T, Distance, Pointer, Reference> &rhs)
	{
		return (lhs._val - rhs._val);
	}
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	bool	
	operator<(const Itervector<Category, T, Distance, Pointer, Reference> &lhs,
		const Itervector<Category, T, Distance, Pointer, Reference> &rhs)
	{
		return (lhs._val < rhs._val);
	}
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	bool	
	operator<=(const Itervector<Category, T, Distance, Pointer, Reference> &lhs,
		const Itervector<Category, T, Distance, Pointer, Reference> &rhs)
	{
		return (!(lhs > rhs));
	}
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	bool	
	operator>(const Itervector<Category, T, Distance, Pointer, Reference> &lhs,
		const Itervector<Category, T, Distance, Pointer, Reference> &rhs)
	{
		return (rhs < lhs);
	}
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	bool	
	operator>=(const Itervector<Category, T, Distance, Pointer, Reference> &lhs,
		const Itervector<Category, T, Distance, Pointer, Reference> &rhs)
	{
		return (!(lhs < rhs));
	}

}	// end of namespace

# endif