/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:47:33 by julpelle          #+#    #+#             */
/*   Updated: 2022/08/25 11:25:11 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef EQUAL_HPP
# define EQUAL_HPP

# include "All.hpp"

namespace	ft
{
	
	template <class InputIterator1, class InputIterator2>
	bool
	equal(InputIterator1 first1, InputIterator1 last, InputIterator2 first2)
	{
		while (first1 != last)
		{
			if (!(*first1 == *first2))
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}

	template <class InputIterator1, class InputIterator2>
	bool
	equal(InputIterator1 first1, InputIterator1 last, InputIterator2 first2, Binary_Function<InputIterator1, InputIterator2, bool> pred)
	{
		while (first1 != last)
		{
			if (!pred(first1, first2))
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}

	template< class InputIt1, class InputIt2 >
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
	{
		for ( ; first1 != last1; first1++)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			if (*first1 < *first2)
				return true;
			first2++;
		}
		return (first2 != last2);
	}
	
	template< class InputIt1, class InputIt2, class Compare >
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp)
	{
		for ( ; first1 != last1; first1++)
		{
			if (first2 == last2 || comp(*first2, *first1))
				return false;
			if (comp(*first1, *first2))
				return true;
			first2++;
		}
		return true;
	}

}


# endif