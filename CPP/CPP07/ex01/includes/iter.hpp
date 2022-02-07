/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 23:26:58 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/07 23:48:34 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>
# include "Colors.hpp"

template<typename T>
void	function1(T &src)
{
	src = src * src;
	std::cout << src <<  " | ";
}

template<typename T>
void	function2(T &src)
{
	src = src + 4;
	std::cout << src <<  " | ";
}

template<typename T>
void	iter(T *array, int len, void (*f)(T &))
{
	int	i;

	i = 0;
	while (i < len)
	{
		(*f)(array[i]);
		i++;
	}
}

#endif /* ************************************************************ ITER_H */