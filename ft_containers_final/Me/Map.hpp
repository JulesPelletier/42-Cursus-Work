/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:27:33 by julpelle          #+#    #+#             */
/*   Updated: 2022/07/12 15:20:55 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MAP_HPP
# define MAP_HPP

# include "Pair.hpp"
# include "Less.hpp"
# include "Binary.hpp"
# include "IterMap.hpp"
# include "IterRev.hpp"
# include "MapNode.hpp"

namespace	ft
{

	template < class Key, class T, class Compare = ft::Less<Key>, 
		class Alloc = std::allocator<Pair<const Key,T> > >
    class Map
	{
		public:
		// Typedefs
		typedef Key										key_type;
		typedef T										mapped_type;
		typedef Pair<const key_type, mapped_type>		value_type;
		typedef Less<key_type>							key_compare;
		class											value_compare;
		typedef Alloc									allocator_type;
		typedef value_type&								reference;
		typedef const value_type&						const_reference;
		typedef value_type*								pointer;
		typedef const value_type*						const_pointer;

		typedef IterMap<bidirectional_iterator_tag, value_type>				iterator;
		typedef IterMap<bidirectional_iterator_tag, const value_type>		const_iterator;
		typedef IterRev<iterator>											reverse_iterator;
		typedef IterRev<const_iterator>										const_reverse_iterator;

		typedef ptrdiff_t								difference_type;
		typedef size_t									size_type;

		// Constructors
		explicit Map(const key_compare &comp = key_compare());
		template <class InputIterator>
		Map(InputIterator first, InputIterator last,
			const key_compare &comp = key_compare());
		Map(const Map &m);

		// Destructor
		~Map(void);

		// Assignation
 		Map				&operator= (const Map& x);

		// Iterators
		iterator 										begin();
		const_iterator 									begin() const;
		iterator 										end();
		const_iterator 									end() const;
		reverse_iterator 								rbegin();
		const_reverse_iterator 							rbegin() const;
		reverse_iterator 								rend();
		const_reverse_iterator 							rend() const;
	
		//Capacity :	
		bool											empty(void) const;
		size_type										size(void) const;
		size_type										max_size(void) const;
					
		//Element access :					
		mapped_type										&operator[](const key_type &k);
					
		//Modifiers :					
		ft::Pair<iterator, bool>						insert(const value_type &val);
		iterator										insert(iterator it, const value_type &val);
		template <class InputIterator>	
		void											insert(InputIterator fst, InputIterator lst);
		void											erase(iterator position);
		size_type										erase(const key_type &k);
		void											erase(iterator first, iterator last);
		void											swap(Map &x);
		void											clear(void);
					
		//Observers :					
		key_compare										key_comp(void) const;
		value_compare									value_comp(void) const;
		
		//Operations :	
		iterator										find(const key_type &k);
		const_iterator									find(const key_type &k) const;
		size_type										count(const key_type &k) const;
		iterator										lower_bound(const key_type &k);
		const_iterator									lower_bound(const key_type &k) const;
		iterator										upper_bound(const key_type &k);
		const_iterator									upper_bound(const key_type &k) const;
		ft::Pair<const_iterator, const_iterator>		equal_range(const key_type &k) const;
		ft::Pair<iterator, iterator>					equal_range(const key_type &k);

		// Others
		void					rec_insert(const MapNode<value_type> *n);
		
		private:
			key_compare				_comp;
			size_type				_size;
			allocator_type			_alloc;
			MapNode<value_type>		*_root;
			MapNode<value_type>		_front;
			MapNode<value_type>		_back;

	};

	///value_compare definition
	template <class Key, class T, class Compare, class Alloc>
	class	Map<Key, T, Compare, Alloc>::value_compare :
		public ft::Binary_Function<value_type, value_type, bool>
	{
		friend class	Map;
	
		public:
			typedef bool		result_type;
			typedef value_type	first_argument_type;
			typedef value_type	second_argument_type;
			bool	operator()(const value_type &x, const value_type &y) const;
		protected:
			Compare comp;
			value_compare(Compare c);
	};
	
	template <class Key, class T, class Compare, class Alloc>
	bool
	Map<Key, T, Compare, Alloc>::value_compare::operator()(const value_type &x,
		const value_type &y) const
	{
		return comp(x.a, y.a);
	}
	
	template <class Key, class T, class Compare, class Alloc>
	Map<Key, T, Compare, Alloc>::value_compare::value_compare(Compare c) : comp(c)
	{
	}
	
	///Map functions definitions
	template <class Key, class T, class Compare, class Alloc>
	Map<Key, T, Compare, Alloc>::Map(const key_compare &comp) : _comp(comp), _size(0), _root(0), _front(),
		_back()
	{
		_front.type = left;
		_back.type = right;
	}
	
	template <class Key, class T, class Compare, class Alloc>
	template <class InputIterator>
	Map<Key, T, Compare, Alloc>::Map(InputIterator first, InputIterator last,
		const key_compare &comp) : _comp(comp), _size(0), _root(0), _front(), _back()
	{
		_front.type = left;
		_back.type = right;
		for (; first != last; ++first)
		{
			insert(*first);
		}
	}
	
	template <class Key, class T, class Compare, class Alloc>
	void
	Map<Key, T, Compare, Alloc>::rec_insert(const MapNode<value_type> *n)
	{
		if (!n || !n->valptr)
			return ;
		insert(*(n->valptr));
		rec_insert(n->l_child);
		rec_insert(n->r_child);
	}
	
	template <class Key, class T, class Compare, class Alloc>
	Map<Key, T, Compare, Alloc>::Map(const Map &m) : _comp(m._comp), _size(0), _root(0), _front(), _back()
	{
		_front.type = left;
		_back.type = right;
		rec_insert(m._root);
	}

	template <class Key, class T, class Compare, class Alloc>
	Map<Key, T, Compare, Alloc>::~Map(void)
	{
		//clear();
	}

	// Iterators

	
	template <class Key, class T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::iterator
	Map<Key, T, Compare, Alloc>::begin(void)
	{
		return (iterator(_front.parent));
	}
	
	template <class Key, class T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::const_iterator
	Map<Key, T, Compare, Alloc>::begin(void) const
	{
		return (const_iterator(reinterpret_cast<MapNode<const value_type> *>(_front.parent)));
	}
	
	template <class Key, class T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::iterator
	Map<Key, T, Compare, Alloc>::end(void)
	{
		return (_size ? iterator(&_back) : begin());
	}
	
	template <class Key, class T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::const_iterator
	Map<Key, T, Compare, Alloc>::end(void) const
	{
		return (const_iterator(_size ?
			reinterpret_cast<MapNode<const value_type> *>(_back.parent->r_child) : begin()));
	}
	
	template <class Key, class T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::reverse_iterator
	Map<Key, T, Compare, Alloc>::rbegin()
	{
		return (reverse_iterator(end()));
	}
	
	template <class Key, class T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::const_reverse_iterator
	Map<Key, T, Compare, Alloc>::rbegin() const
	{
		return (const_reverse_iterator(end()));
	}
	
	template <class Key, class T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::reverse_iterator
	Map<Key, T, Compare, Alloc>::rend()
	{
		if (_size)
			return (reverse_iterator(begin()));
		else
			return (rbegin());
	}
	
	template <class Key, class T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::const_reverse_iterator
	Map<Key, T, Compare, Alloc>::rend() const
	{
		if (_size)
			return (const_reverse_iterator(begin()));
		else
			return (rbegin());
	}
	
	//Capacity :	
	
	template <class Key, class T, class Compare, class Alloc>
	bool											
	Map<Key, T, Compare, Alloc>::empty(void) const
	{
		if (_size)
			return (true);
		return (false);
	}

	
	template <class Key, class T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::size_type										
	Map<Key, T, Compare, Alloc>::size(void) const
	{
		return (_size);
	}

	
	template <class Key, class T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::size_type										
	Map<Key, T, Compare, Alloc>::max_size(void) const
	{
		return (std::numeric_limits<size_type>::max());
	}

	// Access

	template <class Key, class T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::mapped_type										
	&Map<Key, T, Compare, Alloc>::operator[](const key_type &k)
	{
		return ((*((insert(ft::make_pair(k, mapped_type()))).a)).b);
	}

	// Modifiers

	template <class Key, class T, class Compare, class Alloc>
	ft::Pair<typename Map<Key, T, Compare, Alloc>::iterator, bool>
	Map<Key, T, Compare, Alloc>::insert(const value_type &val)
	{
		MapNode<value_type>		*ptr = _root;
		MapNode<value_type>		*tmp;
	
		if (!_size)
		{
			_root = new MapNode<value_type>(val, node, 0, &_front, &_back);
			_root->parent = _root;
			_back.parent = _root;
			_front.parent = _root;
			++_size;
			return (ft::make_pair(iterator(_root), true));
		}
		while (42)
		{
			if (_comp(val.a, ptr->valptr->a))
			{
				tmp = ptr->l_child;
				if (!tmp || !tmp->valptr)
				{
					ptr->l_child = new MapNode<value_type>(val, left, ptr);
					if (tmp)
					{
						ptr->l_child->l_child = tmp;
						tmp->parent = ptr->l_child;
					}
					++_size;
					return (ft::make_pair(iterator(ptr->l_child), true));
				}
				ptr = tmp;
			}
			else if (_comp(ptr->valptr->a, val.a))
			{
				tmp = ptr->r_child;
				if (!tmp || !tmp->valptr)
				{
					ptr->r_child = new MapNode<value_type>(val, right, ptr);
					if (tmp)
					{
						ptr->r_child->r_child = tmp;
						tmp->parent = ptr->r_child;
					}
					++_size;
					return (ft::make_pair(iterator(ptr->r_child), true));
				}
				ptr = tmp;
			}
			else
				return (ft::make_pair(iterator(ptr), false));
		}
	}

	template <class Key, class T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::iterator
	Map<Key, T, Compare, Alloc>::insert(iterator it, const value_type &val)
	{
		(void)it;
		insert(val);
	}

	template <class Key, class T, class Compare, class Alloc>
	template <class InputIterator>
	void
	Map<Key, T, Compare, Alloc>::insert(InputIterator fst, InputIterator lst)
	{
		for (; fst != lst; ++fst)
			insert(*fst);
	}

	template <class Key, class T, class Compare, class Alloc>
	void											
	Map<Key, T, Compare, Alloc>::erase(iterator position)
	{
		MapNode<value_type>		*ptr = position.node;
		MapNode<value_type>		*a;
		MapNode<value_type>		*b;

		if (ptr->type == left)
		{
			if (ptr->r_child)
			{
				for (a = ptr->r_child, b = a; b->l_child; b = b->l_child);
				a->parent = ptr->parent;
				b->l_child = ptr->l_child;
			}
			else
			{
				a = ptr->l_child;
				b = ptr->parent;
			}
			ptr->parent->l_child = a;
			if (ptr->l_child)
				ptr->l_child->parent = b;
			if (a)
				a->type = left;
			delete(ptr);
			_size--;
		}
		else if (ptr->type == right)
		{
			if (ptr->l_child)
			{
				for (a = ptr->l_child, b = a; b->r_child; b = b->r_child);
				a->parent = ptr->parent;
				b->r_child = ptr->r_child;
			}
			else
			{
				a = ptr->r_child;
				b = ptr->parent;
			}
			ptr->parent->r_child = a;
			if (ptr->r_child)
				ptr->r_child->parent = b;
			if (a)
				a->type = right;
			delete(ptr);
			_size--;
		}
		else
		{
			if (ptr->l_child && ptr->l_child->valptr)
			{
				for (a = ptr->l_child, b = a; b->r_child; b = b->r_child);
				b->r_child = ptr->r_child;
				ptr->r_child->parent = b;
			}
			else if (ptr->r_child && ptr->r_child->valptr)
			{
				for (a = ptr->r_child, b = a; b->l_child; b = b->l_child);
				b->l_child = ptr->l_child;
				ptr->l_child->parent = b;
			}
			else
			{
				_root = 0;
				_front.parent = &_front;
				_back.parent = &_back;delete(ptr);
				return ;
			}
			_root = a;
			a->parent = a;
			a->type = node;
			delete(ptr);
			_size--;
		}
	}

	template <class Key, class T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::size_type										
	Map<Key, T, Compare, Alloc>::erase(const key_type &k)
	{
		ft::Pair<iterator, bool>	pair(insert(ft::make_pair(k, mapped_type())));

		erase(pair.a);
		return (pair.b ? 0 : 1);
	}

	template <class Key, class T, class Compare, class Alloc>
	void											
	Map<Key, T, Compare, Alloc>::erase(iterator first, iterator last)
	{
		iterator		it(first++);

		for (; it != last; it = first++)
			erase(it);
	}
	
	template <class Key, class T, class Compare, class Alloc>
	void										
	Map<Key, T, Compare, Alloc>::swap(Map &x)
	{
		MapNode<value_type>		*cpy = _root;
		size_type				size = _size;

		_root = x._root;
		x._root = cpy;
		if (_size)
		{
			_front.parent->l_child = &(x._front);
			_back.parent->r_child = &(x._back);
		}
		if (x._size)
		{
			x._front.parent->l_child = &_front;
			x._back.parent->r_child = &_back;
		}
		cpy = _front.parent;
		_front.parent = x._size ? x._front.parent : &_front;
		x._front.parent = _size ? cpy : &(x._front);
		cpy = _back.parent;
		_back.parent = x._size ? x._back.parent : &_back;
		x._back.parent = _size ? cpy : &(x._back);
		_size = x._size;
		x._size = size;
	}

	template <class Key, class T, class Compare, class Alloc>
	void											
	Map<Key, T, Compare, Alloc>::clear(void)
	{
		while (_size != 0)
		{
			erase(begin());
			_size--;
		}
	}

	// Observers

	template <class Key, class T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::key_compare
	Map<Key, T, Compare, Alloc>::key_comp(void) const
	{
		return (key_compare());
	}
	
	template <class Key, class T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::value_compare
	Map<Key, T, Compare, Alloc>::value_comp(void) const
	{
		return (value_compare(Compare()));
	}

	// Operations

	template <class Key, class T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::iterator										
	Map<Key, T, Compare, Alloc>::find(const key_type &k)
	{
		iterator		res(begin());

		for (; res != end() && (key_comp()(k, res->a) || key_comp()(res->a, k)); ++res);
		return (res);
	}

	template <class Key, class T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::const_iterator									
	Map<Key, T, Compare, Alloc>::find(const key_type &k) const
	{
		const_iterator		res(begin());

		for (; res != end() && (key_comp()(k, res->a) || key_comp()(res->a, k)); ++res);
		return (res);
	}
	
	template <class Key, class T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::size_type										
	Map<Key, T, Compare, Alloc>::count(const key_type &k) const
	{
		const_iterator	it(begin());

		for (; it != end() && (key_comp()(k, it->a) || key_comp()(it->a, k)); ++it);
		return (it == end() ? 0 : 1);
	}
	
	template <class Key, class T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::iterator										
	Map<Key, T, Compare, Alloc>::lower_bound(const key_type &k)
	{
		iterator	it(begin());

		for (; it != end() && key_comp()(it->a, k); ++it);
		return (it);
	}
	
	template <class Key, class T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::const_iterator									
	Map<Key, T, Compare, Alloc>::lower_bound(const key_type &k) const
	{
		const_iterator	it(begin());

		for (; it != end() && key_comp()(it->a, k); ++it);
		return (it);
	}
	
	template <class Key, class T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::iterator										
	Map<Key, T, Compare, Alloc>::upper_bound(const key_type &k)
	{
		iterator	it(begin());

		for (; it != end() && key_comp()(k, it->a); ++it);
		return (it);
	}
	
	template <class Key, class T, class Compare, class Alloc>
	typename Map<Key, T, Compare, Alloc>::const_iterator									
	Map<Key, T, Compare, Alloc>::upper_bound(const key_type &k) const
	{
		const_iterator	it(begin());

		for (; it != end() && key_comp()(k, it->a); ++it);
		return (it);
	}
	
	template <class Key, class T, class Compare, class Alloc>
	ft::Pair<typename Map<Key, T, Compare, Alloc>::const_iterator, typename Map<Key, T, Compare, Alloc>::const_iterator>		
	Map<Key, T, Compare, Alloc>::equal_range(const key_type &k) const
	{
		return (ft::make_pair(lower_bound(k), upper_bound(k)));
	}
	
	template <class Key, class T, class Compare, class Alloc>
	typename ft::Pair<typename Map<Key, T, Compare, Alloc>::iterator, typename Map<Key, T, Compare, Alloc>::iterator>					
	Map<Key, T, Compare, Alloc>::equal_range(const key_type &k)
	{
		return (ft::make_pair(lower_bound(k), upper_bound(k)));
	}
	

}	// end of namespace

# endif

