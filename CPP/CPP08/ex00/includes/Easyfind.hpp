/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:17:19 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/08 13:07:24 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <list>

template<typename T>
typename T::const_iterator easyfind(T const &array, int elem)
{
	typename	T::const_iterator it;

	it = find(array.begin(), array.end(), elem);
	return (it);
}

#endif /* ******************************************************** EASYFIND_H */