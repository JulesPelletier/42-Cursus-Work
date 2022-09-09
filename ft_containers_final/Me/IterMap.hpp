/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IterMap.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:41:31 by julpelle          #+#    #+#             */
/*   Updated: 2022/07/12 15:21:08 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITERMAP_HPP
# define ITERMAP_HPP

# include "All.hpp"
# include "MapNode.hpp"

namespace	ft
{

	template <class Category, class T, class Distance = std::ptrdiff_t,
		class Pointer = T*, class Reference = T&>
	class IterMap
	{
		public:
			// Types
			typedef T				value_type;
			typedef Pointer			pointer;
			typedef Reference		reference;
			typedef Distance		difference_type;
			typedef Category		iterator_category;
			
			// Constructors
			IterMap(MapNode<value_type> *n = 0);
			IterMap(const IterMap &it);

			// Destructor
			~IterMap(void);

			// Assignation
			IterMap			&operator=(const IterMap &i);

			// Operators
			bool			operator==(const IterMap &i);
			bool			operator!=(const IterMap &i);
			
			reference		operator*(void);
			pointer			operator->(void);
			IterMap			&operator++(void);
			IterMap			operator++(int val);
			IterMap			&operator--(void);
			IterMap			operator--(int val);

			// Attributes
			MapNode<value_type>		*node;

	};
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	IterMap<Category, T, Distance, Pointer, Reference>::IterMap(MapNode<value_type> *n) : node(n)
	{
	}
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	IterMap<Category, T, Distance, Pointer, Reference>::IterMap(const IterMap &m) : node(m.node)
	{
	}

	template <class Category, class T, class Distance, class Pointer, class Reference>
	IterMap<Category, T, Distance, Pointer, Reference>::~IterMap(void)
	{
	}

	template <class Category, class T, class Distance, class Pointer, class Reference>
	IterMap<Category, T, Distance, Pointer, Reference>			
	&IterMap<Category, T, Distance, Pointer, Reference>::operator=(const IterMap &i)
	{
		if (&i == this)
			return (*this);
		node = i.node;
		return (*this);
	}
	template <class Category, class T, class Distance, class Pointer, class Reference>
	bool			
	IterMap<Category, T, Distance, Pointer, Reference>::operator==(const IterMap &i)
	{
		return (node == i.node);
	}
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	bool			
	IterMap<Category, T, Distance, Pointer, Reference>::operator!=(const IterMap &i)
	{
		return (!(*this == i));
	}
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	typename IterMap<Category, T, Distance, Pointer, Reference>::reference		
	IterMap<Category, T, Distance, Pointer, Reference>::operator*(void)
	{
		return (*(node->valptr));
	}
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	typename IterMap<Category, T, Distance, Pointer, Reference>::pointer			
	IterMap<Category, T, Distance, Pointer, Reference>::operator->(void)
	{
		return (node->valptr);
	}
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	IterMap<Category, T, Distance, Pointer, Reference>			
	&IterMap<Category, T, Distance, Pointer, Reference>::operator++(void)
	{
		if (node->r_child && node->r_child != node)
		{
			node = node->r_child;
			while (node->l_child && node->l_child != node)
				node = node->l_child;
		}
		else if (node->type == left)
			node = node->parent;
		else if (node->type == right && node->valptr)
		{
			do
				node = node->parent;
			while (node->type != left);
			node = node->parent;
		}
		return (*this);
	}
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	IterMap<Category, T, Distance, Pointer, Reference>			
	IterMap<Category, T, Distance, Pointer, Reference>::operator++(int val)
	{
		IterMap<Category, T, Distance, Pointer, Reference>		tmp;

		(void)val;
		tmp = *this;
		++(*this);
		return (tmp);
	}
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	IterMap<Category, T, Distance, Pointer, Reference>			
	&IterMap<Category, T, Distance, Pointer, Reference>::operator--(void)
	{
		if (node->l_child && node->l_child != node)
		{
			node = node->l_child;
			while (node->r_child && node->r_child != node)
				node = node->r_child;
		}
		else if (node->type == right)
			node = node->parent;
		else if (node->type == left && node->valptr)
		{
			do
				node = node->parent;
			while (node->type != right);
			node = node->parent;
		}
		return (*this);
	}
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	IterMap<Category, T, Distance, Pointer, Reference>			
	IterMap<Category, T, Distance, Pointer, Reference>::operator--(int val)
	{
		IterMap<Category, T, Distance, Pointer, Reference>		tmp;

		(void)val;
		tmp = *this;
		--(*this);
		return (tmp);
	}
	
}	// end of namespace

# endif