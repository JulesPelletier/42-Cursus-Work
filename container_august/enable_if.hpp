/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:19:13 by julpelle          #+#    #+#             */
/*   Updated: 2022/08/09 18:33:42 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

namespace ft
{
	template <bool Cond, class T = void>
	struct 
	enable_if
	{
	};

	template <class T>
	struct 
	enable_if <true, T>
	{
		typedef	T type;
	};
}



# endif