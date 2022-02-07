/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 23:20:32 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/07 23:25:14 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_HPP
# define SWAP_HPP

# include <iostream>
# include "Colors.hpp"

template<typename T>
void	swap(T &a, T &b)
{
	T 	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T const	&min(T const &a, T const &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

template<typename T>
T const	&max(T const &a, T const &b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

# endif