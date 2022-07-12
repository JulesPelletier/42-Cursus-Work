/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterMap.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:41:31 by julpelle          #+#    #+#             */
/*   Updated: 2022/07/12 18:57:27 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITERmap_HPP
# define ITERmap_HPP

# include "../All.hpp"
# include "../map/mapNode.hpp"

namespace	ft
{

	template <class Category, class T, class Distance = std::ptrdiff_t,
		class Pointer = T*, class Reference = T&>
	class Itermap
	{
		public:
			// Types
			typedef T				value_type;
			typedef Pointer			pointer;
			typedef Reference		reference;
			typedef Distance		difference_type;
			typedef Category		iterator_category;
			
			// Constructors
			Itermap(mapNode<value_type> *n = 0);
			Itermap(const Itermap &it);

			// Destructor
			~Itermap(void);

			// Assignation
			Itermap			&operator=(const Itermap &i);

			// Operators
			bool			operator==(const Itermap &i);
			bool			operator!=(const Itermap &i);
			
			reference		operator*(void);
			pointer			operator->(void);
			Itermap			&operator++(void);
			Itermap			operator++(int val);
			Itermap			&operator--(void);
			Itermap			operator--(int val);

			// Attributes
			mapNode<value_type>		*node;

	};
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	Itermap<Category, T, Distance, Pointer, Reference>::Itermap(mapNode<value_type> *n) : node(n)
	{
	}
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	Itermap<Category, T, Distance, Pointer, Reference>::Itermap(const Itermap &m) : node(m.node)
	{
	}

	template <class Category, class T, class Distance, class Pointer, class Reference>
	Itermap<Category, T, Distance, Pointer, Reference>::~Itermap(void)
	{
	}

	template <class Category, class T, class Distance, class Pointer, class Reference>
	Itermap<Category, T, Distance, Pointer, Reference>			
	&Itermap<Category, T, Distance, Pointer, Reference>::operator=(const Itermap &i)
	{
		if (&i == this)
			return (*this);
		node = i.node;
		return (*this);
	}
	template <class Category, class T, class Distance, class Pointer, class Reference>
	bool			
	Itermap<Category, T, Distance, Pointer, Reference>::operator==(const Itermap &i)
	{
		return (node == i.node);
	}
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	bool			
	Itermap<Category, T, Distance, Pointer, Reference>::operator!=(const Itermap &i)
	{
		return (!(*this == i));
	}
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	typename Itermap<Category, T, Distance, Pointer, Reference>::reference		
	Itermap<Category, T, Distance, Pointer, Reference>::operator*(void)
	{
		return (*(node->valptr));
	}
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	typename Itermap<Category, T, Distance, Pointer, Reference>::pointer			
	Itermap<Category, T, Distance, Pointer, Reference>::operator->(void)
	{
		return (node->valptr);
	}
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	Itermap<Category, T, Distance, Pointer, Reference>			
	&Itermap<Category, T, Distance, Pointer, Reference>::operator++(void)
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
	Itermap<Category, T, Distance, Pointer, Reference>			
	Itermap<Category, T, Distance, Pointer, Reference>::operator++(int val)
	{
		Itermap<Category, T, Distance, Pointer, Reference>		tmp;

		(void)val;
		tmp = *this;
		++(*this);
		return (tmp);
	}
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	Itermap<Category, T, Distance, Pointer, Reference>			
	&Itermap<Category, T, Distance, Pointer, Reference>::operator--(void)
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
	Itermap<Category, T, Distance, Pointer, Reference>			
	Itermap<Category, T, Distance, Pointer, Reference>::operator--(int val)
	{
		Itermap<Category, T, Distance, Pointer, Reference>		tmp;

		(void)val;
		tmp = *this;
		--(*this);
		return (tmp);
	}
	
}	// end of namespace

# endif