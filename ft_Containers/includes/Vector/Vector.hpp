/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:40:13 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/09 01:56:13 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include "../AllContainers.hpp"
# include "IterVector.hpp"
# include "RevIterVector.hpp"

namespace ft {

template<class T>
class Vector
{

	public:

		// Type Defs
		typedef T						value_type;
		typedef	T&						reference;
		typedef T*						pointer;
		typedef const T&				const_reference;
		typedef const T*				const_pointer;
		typedef IterVector<T>			iterator;
		typedef IterVector<const T>		const_iterator;
		typedef	RevIterVector<T>		reverse_iterator;
		typedef	RevIterVector<const T>	const_reverse_iterator;
		typedef std::ptrdiff_t			difference_type;
		typedef size_t					size_type;

		// Constructor
		explicit	Vector(void);
		explicit	Vector(size_type n, const value_type &val = value_type());
		
		template <class InputIterator>
					Vector(InputIterator first, InputIterator last);
					
					Vector(const Vector &x);

		// Destructor
					~Vector(void);

		// Iterators
		iterator					begin(void);
		const_iterator				begin(void) const;
		iterator					end(void);
		const_iterator				end(void) const;
		iterator					rbegin(void);
		const_reverse_iterator		rbegin(void) const;
		iterator					rend(void);
		const_reverse_iterator		rend(void) const;

		// Capacity
		size_type 				size(void) const;
		size_type 				max_size(void) const;
		//void 					resize(size_type n, value_type val = value_type());
		size_type 				capacity(void) const;
		bool 					empty(void) const;

		// Element Access

		// Modifiers

		// Allocator


		// Overload Operators
		Vector 			&operator=(const Vector &x);
		

	private:
		size_type		_len;
		value_type		*_values;

};

// Constructors

template<class T>
Vector<T>::Vector(void) : _len(0), _values(0)
{
	//std::cout << Yellow "Default constructor called for Vector Container" << std::endl;
}

template<class T>
Vector<T>::Vector(size_type n, const value_type &val) : _len(0), _values(0)
{
	(void)n;
	(void)val;
	//std::cout << Yellow "Fill constructor called for Vector Container" << std::endl;
}

template<class T>
template<class InputIterator>
Vector<T>::Vector(InputIterator first, InputIterator last) : _len(0), _values(0)
{
	(void)first;
	(void)last;
	//std::cout << Yellow "Range constructor called for Vector Container" << std::endl;

}

template<class T>
Vector<T>::Vector(const Vector &x) : _len(x._len), _values(x._values)
{
	(void)x;
	//std::cout << Yellow "Copy constructor called for Vector Container" << std::endl;
}

// Destructor

template<class T>
Vector<T>::~Vector(void)
{
	//std::cout << Yellow "Default destructor called for Vector Container" << std::endl;
}

// Iterators

template<class T>
typename Vector<T>::iterator					Vector<T>::begin(void)
{
	return (iterator(this->_values));
}

template<class T>
typename Vector<T>::const_iterator				Vector<T>::begin(void) const
{
	return (const_iterator(reinterpret_cast<const T*>(this->_values)));
}

template<class T>
typename Vector<T>::iterator					Vector<T>::end(void)
{
	return (iterator(this->_values + this->size()));
}

template<class T>
typename Vector<T>::const_iterator				Vector<T>::end(void) const
{
	return (iterator(reinterpret_cast<const T*>(this->_values) + this->size()));
}

template<class T>
typename Vector<T>::iterator					Vector<T>::rbegin(void)
{
	return (reverse_iterator(end()));
}

template<class T>
typename Vector<T>::const_reverse_iterator		Vector<T>::rbegin(void) const
{
	return (const_reverse_iterator(end()));
}

template<class T>
typename Vector<T>::iterator					Vector<T>::rend(void)
{
	return (reverse_iterator(begin()));
}
template<class T>
typename Vector<T>::const_reverse_iterator		Vector<T>::rend(void) const
{
	return (const_reverse_iterator(begin()));
}


// Capacity

template<class T>
typename Vector<T>::size_type 					Vector<T>::size(void) const
{
	return (_len);
}

template<class T>
typename Vector<T>::size_type 					Vector<T>::max_size(void) const
{
	return (std::numeric_limits<difference_type>::max() / 2);
}

/*
template<class T>
void 								Vector<T>::resize(size_type n, value_type val)
{
	size_type			current_size;
	size_type			new_size;
	std::allocator<T>	res;
	iterator			i;

	current_size = this->size();
	if (current_size > n)
	{
		new_size = n;
		i = end();
		while (i > n)
	}
}
*/


template<class T>
typename Vector<T>::size_type 					Vector<T>::capacity(void) const
{
	size_type	i;
	size_type	capacity;

	i = 0;
	capacity = 0;
	while (capacity < this->size())
	{
		i++;
		capacity = pow(i, 2);
		std::cout << "cap : " << capacity << std::endl;
	}
	return (capacity);
}

template<class T>
bool 											Vector<T>::empty(void) const
{
	if (this->size() == 0)
		return (true);
	return (false);
}

// Overload Operators

template<class T>
Vector<T>										&Vector<T>::operator=(const Vector &x)
{
	if (&x == this)
		return (*this);
	this->_len = x._len;
	this->_values = x._values;
	return (*this);
}

template<class T>
bool			operator==(const Vector<T> &x, const Vector<T> &y)
{
	if (x < y || y < x)
		return (false);
	return (true);
}

template<class T>
bool			operator!=(const Vector<T> &x, const Vector<T> &y)
{
	if (!(x == y))
		return (true);
	return (false);
}

template<class T>
bool			operator<(const Vector<T> &x, const Vector<T> &y)
{
	typename	Vector<T>::const_iterator  it_x;
	typename	Vector<T>::const_iterator  it_y;
	
	it_x = x.begin();
	it_y = y.begin();

	while(it_y != y.end())
	{
		if (it_x == x.end() || *it_x < *it_y)
			return (true);
		it_x++;
		it_y++;
	}
	return (false);
}

template<class T>
bool			operator>(const Vector<T> &x, const Vector<T> &y)
{
	if (x < y || x == y)
		return (false);
	return (true);
}

template<class T>
bool			operator>=(const Vector<T> &x, const Vector<T> &y)
{
	if (x > y || x == y)
		return (true);
	return (false);
}

template<class T>
bool			operator<=(const Vector<T> &x, const Vector<T> &y)
{
	if (x < y || x == y)
		return (true);
	return (false);
}

template<class T>
std::ostream 	&operator<<( std::ostream & o, Vector<T> const & i )
{
	o << "Vector size : " << i._len << std::endl;

}

} // End of namespace

#endif /* ********************************************************** VECTOR_H */