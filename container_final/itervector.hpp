/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itervector.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:02:59 by julpelle          #+#    #+#             */
/*   Updated: 2022/08/25 11:18:26 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITERvector_HPP
# define ITERvector_HPP

# include "iterTraits.hpp"

namespace ft {

	template <class T>

	class Itervector : public ft::iterator<std::random_access_iterator_tag, T>
	{
		public:
			// Types
			typedef T				value_type;
			typedef T*				pointer;
			typedef T&				reference;
			typedef std::ptrdiff_t	difference_type;
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::iterator_category		iterator_category;
			
			// Constructors
			Itervector(void);
			Itervector(reference value);
			Itervector(pointer value);
			Itervector(const Itervector &it);

			// Destructor
			virtual ~Itervector(void);

			// Operators
			Itervector				&operator=(const Itervector &it);
			Itervector				&operator=(pointer it);
			bool					operator==(const Itervector &it) const;
			bool					operator!=(const Itervector &it) const;
			bool					operator<(const Itervector &it) const;
			bool					operator<=(const Itervector &it) const;
			bool					operator>(const Itervector &it) const;
			bool					operator>=(const Itervector &it) const;
			reference				operator*(void) const;
			pointer					operator->(void) const;
			reference				operator[](difference_type n) const;
			Itervector				&operator++(void);
			Itervector				operator++(int n);
			Itervector				&operator--(void);
			Itervector				operator--(int n);
			Itervector				operator+(difference_type n) const;
			difference_type 		operator-(difference_type n) const;
			Itervector				&operator+=(difference_type n);
			Itervector				&operator-=(difference_type n);

			// Variables
			
		private:
			value_type				*_val;
			
		
	};

	// Constructors
	template <class T>
	Itervector<T>::Itervector(void) : _val(0)
	{
	}
	
	template <class T>
	Itervector<T>::Itervector(reference value) : _val(&value)
	{
	}

	template <class T>
	Itervector<T>::Itervector(pointer value) : _val(value)
	{
	}

	template <class T>
	Itervector<T>::Itervector(const Itervector<T> &it) : _val(it._val)
	{
	}

	//  Destructor
	template <class T>
	Itervector<T>::~Itervector(void)
	{
	}

	template <class T>
	Itervector<T>
	&Itervector<T>::operator=(const Itervector &it)
	{
		_val = it._val;
		return (*this);
	}

	template <class T>
	Itervector<T>
	&Itervector<T>::operator=(pointer it)
	{
		_val = it;
		return (*this);
	}

	template <class T>
	bool
	Itervector<T>::operator==(const Itervector &it) const
	{
		return (_val == it._val);
	}

	template <class T>
	bool
	Itervector<T>::operator!=(const Itervector &it) const
	{
		return (!(_val == it._val));
	}

	template <class T>
	bool
	Itervector<T>::operator<(const Itervector &it) const
	{
		return (_val < it._val);
	}

	template <class T>
	bool
	Itervector<T>::operator<=(const Itervector &it) const
	{
		return (_val <= it._val);
	}

	template <class T>
	bool
	Itervector<T>::operator>(const Itervector &it) const
	{
		return (_val > it._val);
	}

	template <class T>
	bool
	Itervector<T>::operator>=(const Itervector &it) const
	{
		return (_val >= it._val);
	}

	template <class T>
	typename Itervector<T>::reference
	Itervector<T>::operator*(void) const
	{
		return (*_val);
	}

	template <class T>
	typename Itervector<T>::pointer
	Itervector<T>::operator->(void) const
	{
		return (_val);
	}

	template <class T>
	typename Itervector<T>::reference
	Itervector<T>::operator[](difference_type n) const
	{
		return (_val[n]);
	}


	template <class T>
	Itervector<T>
	&Itervector<T>::operator++(void)
	{
		++_val;
		return (*this);
	}

	template <class T>
	Itervector<T>
	Itervector<T>::operator++(int n)
	{
		Itervector	tmp(*this);

		++(*this);
		(void)n;
		return (tmp);
	}

	template <class T>
	Itervector<T>
	&Itervector<T>::operator--(void)
	{
		--_val;
		return (*this);
	}

	template <class T>
	Itervector<T>
	Itervector<T>::operator--(int n)
	{
		Itervector	tmp(*this);

		--(*this);
		(void)n;
		return (tmp);
	}


	template <class T>
	Itervector<T>		
	Itervector<T>::operator+(difference_type n) const
	{
		return (Itervector<T>(_val + n));
	}

	template <class T>
	typename Itervector<T>::difference_type	
	Itervector<T>::operator-(difference_type n) const
	{
		return (Itervector<T>(_val - n));
	}
	
	template <class T>
	Itervector<T>		
	&Itervector<T>::operator+=(difference_type n)
	{
		_val = _val + n;
		return (*this);
	}

	template <class T>
	Itervector<T>		
	&Itervector<T>::operator-=(difference_type n)
	{
		_val = _val - n;
		return (*this);
	}

}	// end of namespace

# endif