/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:40:13 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/08 23:00:42 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include "AllContainers.hpp"

namespace ft {

template<class T>
class Vector
{

	public:

		// Type Defs
		typedef T				value_type;
		typedef	T&				reference;
		typedef T*				pointer;
		typedef const T&		const_reference;
		typedef const T*		const_pointer;
		//typedef 				iterator;
		//typedef 				const_iterator;
		//typedef 				reverse_iterator;
		//typedef 				const_reverse_iterator;
		typedef std::ptrdiff_t	difference_type;
		typedef size_t			size_type;

		// Constructor
		explicit	Vector(void);
		explicit	Vector(size_type n, const value_type &val = value_type());
		
		template <class InputIterator>
					Vector(InputIterator first, InputIterator last);
					
					Vector(const Vector &x);

		// Destructor
					~Vector(void);

		// Member Functions



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
	std::cout << Yellow "Default constructor called for Vector Container" << std::endl;
}

template<class T>
Vector<T>::Vector(size_type n, const value_type &val) : _len(0), _values(0)
{
	(void)n;
	(void)val;
	std::cout << Yellow "Fill constructor called for Vector Container" << std::endl;
}

template<class T>
template<class InputIterator>
Vector<T>::Vector(InputIterator first, InputIterator last) : _len(0), _values(0)
{
	(void)first;
	(void)last;
	std::cout << Yellow "Range constructor called for Vector Container" << std::endl;

}

template<class T>
Vector<T>::Vector(const Vector &x) : _len(0), _values(0)
{
	(void)x;
	std::cout << Yellow "Copy constructor called for Vector Container" << std::endl;
}

// Destructor

template<class T>
Vector<T>::~Vector(void)
{
	std::cout << Yellow "Default destructor called for Vector Container" << std::endl;
}

// Member Functions


// Overload Operators

template<class T>
Vector<T>	&Vector<T>::operator=(const Vector &x)
{
	if (&x == this)
		return (*this);
	// Need copy all attributes
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
	o << "Vector size : " << << std::endl;

}

#endif /* ********************************************************** VECTOR_H */