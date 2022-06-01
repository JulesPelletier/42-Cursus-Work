/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Less.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:25:53 by julpelle          #+#    #+#             */
/*   Updated: 2022/03/25 22:33:44 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LESS_HPP
# define LESS_HPP

# include "Binary.hpp"

namespace	ft
{

	template <class T>
	struct Less : ft::Binary_Function <T, T, bool>
  	{
		bool operator() (const T& x, const T& y) const;
	};

	template <class T>
	bool
	Less<T>::operator()(const T &x, const T &y) const
	{
		return (x < y);
	}
	
}	// end of namespace


# endif