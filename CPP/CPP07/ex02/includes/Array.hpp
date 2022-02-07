/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 23:26:58 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/08 00:46:54 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include "Colors.hpp"

template<typename T>
class Array
{
	public:
		Array(void);
		Array(int len);
		Array(Array const &src);
		~Array(void);

		Array 			&operator=( Array const & rhs );
		T				&operator[](int const &index);
		int		const	&getSize(void) const;
		int		const	&size(void) const;
		int		const	&getElem(int const &index) const;
		int		const	&addElem(int const &index, int elem);


	private:
		int		_size;
		int		_fill;
		T		*tab;
};

template<typename T>
Array<T>::Array(void) : _size(0), _fill(0)
{
	tab = new T[1];
	std::cout << Yellow "Default constructor called for Array" Reset << std::endl;
}

template<typename T>
Array<T>::Array(int len) : _size(len), _fill(0)
{
	if (len == 0)
		tab = new T[1];
	else
	{
		int	i;

		i = 0;
		tab = new T[len];
		while (i < len)
		{
			tab[i] = 0;
			i++;
		}
	}
	std::cout << Yellow "Constructor called for Array" Reset << std::endl;
}

template<typename T>
Array<T>::Array(Array const &src) : _size(src.getSize()), _fill(0)
{
	int i;

	i = 0;
	this->tab = new T[_size];
	while (i < this->_size)
	{
		this->tab[i] = src.getElem(i);
		i++;
	}
	std::cout << Yellow "Copy constructor called for Array" Reset << std::endl;
}

template<typename T>
Array<T>::~Array(void)
{
	if (this->tab)
		delete this->tab;
	std::cout << Yellow "Default destructor called for Array" Reset << std::endl;
}

template<typename T>
Array<T>			&Array<T>::operator=( Array const & rhs )
{
	if ( this != &rhs )
	{
		this->_size = rhs.getSize();
	}
	return *this;
}

template<typename T>
T 					&Array<T>::operator[](int const &index)
{
	return (this->getElem(index));
}

template<typename T>
int	const			&Array<T>::getSize(void) const
{
	return (this->_size);
}

template<typename T>
int	const			&Array<T>::size(void) const
{
	return (this->_size);
}

template<typename T>
int	const			&Array<T>::getElem(int const &index) const
{
	if (index < 0 || index >= this->_size)
		throw	std::exception();
	return (this->tab[index]);
}

template<typename T>
int	const			&Array<T>::addElem(int const &index, int elem)
{
	if (index < 0 || index >= this->_size || this->_fill == this->_size)
		throw	std::exception();
	_fill++;
	this->tab[index] = elem;
	return (this->tab[index]);
}


#endif /* ************************************************************ ITER_H */