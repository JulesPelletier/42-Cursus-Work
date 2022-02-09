/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IterVector.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:12:02 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/09 01:18:50 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERVECTOR_HPP
# define ITERVECTOR_HPP

# include <iostream>
# include <string>
# include "../AllContainers.hpp"

namespace ft
{

template<class T>
class IterVector
{
	public:
		// Type Defs
		typedef T				value_type;
		typedef	T&				reference;
		typedef T*				pointer;
		typedef std::ptrdiff_t	difference_type;
		typedef size_t			size_type;
		typedef std::string		iterator_type;
		
		//Constructors & Destructors
		IterVector(void);
		IterVector(value_type *p);
		IterVector(const IterVector &v);
		~IterVector(void);

		// Assignation
		IterVector &		operator=( IterVector const & rhs );

		// Operators
		bool				operator==(const IterVector &x) const;
		bool				operator!=(const IterVector &x) const;
		IterVector			&operator*(void);
		IterVector			*operator->(void);
		IterVector			&operator[](difference_type index) const;
		IterVector			&operator++(void);
		IterVector			&operator--(void);
		IterVector			&operator+(difference_type inc) const;
		IterVector			operator-(difference_type dec) const;
		IterVector			&operator+=(difference_type inc);
		IterVector			operator-=(difference_type dec);
		
	private:
		value_type		*_ptr;

};

// Constructors & Destructors

template<class T>
IterVector<T>::IterVector(void) : _ptr(0)
{
	std::cout << Yellow "Default constructor called for iterator" Reset << std::endl;
}

template<class T>
IterVector<T>::IterVector(value_type *p) : _ptr(p)
{
	std::cout << Yellow "Default constructor called for iterator" Reset << std::endl;
}

template<class T>
IterVector<T>::IterVector(const IterVector &v) : _ptr(v._ptr)
{
	*this = v;
	std::cout << Yellow "Copy constructor called for iterator" Reset << std::endl;
}

template<class T>
IterVector<T>::~IterVector(void)
{
	std::cout << Yellow "Default destructor called for iterator" Reset << std::endl;
}

// Assignation
template<class T>
IterVector<T> 				&IterVector<T>::operator=( IterVector const & rhs )
{
	if (this == rhs)
		return (*this);
	this->_ptr = rhs._ptr;
	return (*this);
}

// Operators
template<class T>
bool				IterVector<T>::operator==(const IterVector &x) const
{
	if (this->_ptr == x._ptr)
		return (true);
	return (false);
}
template<class T>
bool				IterVector<T>::operator!=(const IterVector &x) const
{
	if (this->_ptr == x._ptr)
		return (false);
	return (true);
}

template<class T>
IterVector<T>			&IterVector<T>::operator*(void)
{
	return (*this->_ptr);
}

template<class T>
IterVector<T>			*IterVector<T>::operator->(void)
{
	return (this->_ptr);
}

template<class T>
IterVector<T>			&IterVector<T>::operator[](difference_type index) const
{
	return (*(this->_ptr + index));
}

template<class T>
IterVector<T>			&IterVector<T>::operator++(void)
{
	++this->_ptr;
	return (*this);
}

template<class T>
IterVector<T>			&IterVector<T>::operator--(void)
{
	--this->_ptr;
	return (*this);
}

template<class T>
IterVector<T>			&IterVector<T>::operator+(difference_type inc) const
{
	IterVector	copy(*this);

	copy->_ptr = copy->_ptr + inc;
	return (copy);
}

template<class T>
IterVector<T>			IterVector<T>::operator-(difference_type dec) const
{
	IterVector	copy(*this);

	copy->_ptr = copy->_ptr - dec;
	return (copy);
}

template<class T>
IterVector<T>			&IterVector<T>::operator+=(difference_type inc)
{
	this->ptr = this->_ptr + inc;
	return (*this);
}

template<class T>
IterVector<T>			IterVector<T>::operator-=(difference_type dec)
{
	this->ptr = this->_ptr - dec;
	return (*this);
}

// Stream
template<class T>
std::ostream &			operator<<( std::ostream & o, IterVector<T> const & i );

} // End of namespace

#endif /* ****************************************************** ITERVECTOR_H */