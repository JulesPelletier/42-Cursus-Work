/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShowContainer.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:23:30 by julpelle          #+#    #+#             */
/*   Updated: 2022/03/25 15:59:11 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SHWOCONTAINER_HPP
# define SHWOCONTAINER_HPP

# include "../../includes/All.hpp"

template <class T>
void	
show_vector(const T &cont, std::string name)
{
	typename T::const_iterator	it;
	std::cout << BCyan << "\t******** Vector " << name << " ******** \n\t  [ " << Cyan;
	for (typename T::const_iterator jt(cont.begin()); jt != cont.end(); ++jt)
	{
		it = jt;
		std::cout << *jt << (++it != cont.end() ? ", " : "");
	}
	std::cout << BCyan << " ]\n" << Reset;
}

template <class T>
void	
rshow_vector(const T &cont, std::string name)
{
	typename T::const_reverse_iterator	it;

	std::cout << BCyan << "\t******** Vector " << name << " ******** \n\t  [ " << Cyan;
	for (typename T::const_reverse_iterator jt(cont.rbegin()); jt != cont.rend(); ++jt)
	{
		it = jt;
		std::cout << *jt << (++it != cont.rend() ? ", " : "");
	}
	std::cout << Reset << " ] \n";
}


# endif