/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterTraits.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:41:31 by julpelle          #+#    #+#             */
/*   Updated: 2022/08/10 13:13:02 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITERTRAITS_HPP
# define ITERTRAITS_HPP

# include "All.hpp"

namespace	ft
{

	struct input_iterator_tag { };
	struct output_iterator_tag { };
	struct forward_iterator_tag : public input_iterator_tag { };
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };

    template<typename Category, typename T, typename Distance = ptrdiff_t,
                        typename Pointer = T*, typename Reference = T&>
    struct iterator
    {
        typedef Category	iterator_category;
        typedef T			value_type;
        typedef Distance	difference_type;
        typedef Pointer	    pointer;
        typedef Reference	reference;
    };
	
	template<class iterator>
	struct iterator_traits
	{
		typedef typename iterator::iterator_category	iterator_category;
		typedef typename iterator::value_type			value_type;
		typedef typename iterator::difference_type		difference_type;
		typedef typename iterator::pointer				pointer;
		typedef typename iterator::reference			reference;
	};
	
	template<class T>
	struct iterator_traits<T*>
	{
		typedef random_access_iterator_tag	iterator_category;
		typedef T							value_type;
		typedef ptrdiff_t					difference_type;
		typedef T*						    pointer;
		typedef T&						    reference;
	};
	
	template<class T>
	struct iterator_traits<const T*>
	{
		typedef random_access_iterator_tag	iterator_category;
		typedef T							value_type;
		typedef ptrdiff_t					difference_type;
		typedef const T*					pointer;
		typedef const T&					reference;
	};
	
}	// end of namespace

# endif