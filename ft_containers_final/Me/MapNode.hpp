/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapNode.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:47:36 by julpelle          #+#    #+#             */
/*   Updated: 2022/07/12 15:21:16 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MapNode_HPP
# define MapNode_HPP

# include "All.hpp"

namespace	ft
{

	template <typename T>
	struct MapNode
	{
		// Constructors
		MapNode(void);
		MapNode(const T &v, t_node typ, MapNode<T> *u = 0, MapNode<T> *l = 0, MapNode<T> *r = 0);
		MapNode(const MapNode<T> &t);

		// Destructor
		~MapNode(void);

		// Assignation
		MapNode<T>		&operator=(const MapNode<T> &m);

		// Atributes
		t_node		type;
		MapNode		*parent;
		MapNode		*l_child;
		MapNode		*r_child;
		T			val;
		T			*valptr;
	};
	
	// Constructors

	template <typename T>
	MapNode<T>::MapNode(void) : type(node), parent(this), l_child(this), r_child(this), val(), valptr(0)
	{

	}

	template <typename T>
	MapNode<T>::MapNode(const T &v, t_node typ, MapNode<T> *u, MapNode<T> *l,
	MapNode<T> *r) : type(typ), parent(u), l_child(l), r_child(r), val(v), valptr(0)
	{
		valptr = &val;
	}

	template <typename T>
	MapNode<T>::MapNode(const MapNode<T> &m) : type(node), parent(this), l_child(this), r_child(this), val(m.val), valptr(0)
	{
		if (!(m.valptr))
			valptr = 0;
		else
			valptr = m.valptr;
	}

	// Destructor

	template <typename T>
	MapNode<T>::~MapNode(void)
	{
	}

	// Assignation

	template <typename T>
	MapNode<T>
	&MapNode<T>::operator=(const MapNode<T> &m)
	{
		if (*this == m)
			return (*this);
		val = m.val;;
		if (!(m.valptr))
			valptr = 0;
		else
			valptr = m.valptr;
		return (*this);
	}



}	// end of namespace



# endif