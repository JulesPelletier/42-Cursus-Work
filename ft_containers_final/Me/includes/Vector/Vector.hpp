/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:58:48 by julpelle          #+#    #+#             */
/*   Updated: 2022/03/25 15:02:36 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef VECTOR_HPP
# define VECTOR_HPP

# include "../All.hpp"
# include "../Iterators/IterRev.hpp"
# include "../Iterators/IterVector.hpp"
# include "../Iterators/Types.hpp"

namespace ft {

	template <class T, class Alloc = std::allocator<T> >
	class Vector
	{
		public:
			// Types
			typedef	Alloc					allocator_type;
			typedef T						value_type;
			typedef T*						pointer;
			typedef T&						reference;
			typedef const T*				const_pointer;
			typedef const T&				const_reference;
			typedef size_t 					size_type;
			typedef std::ptrdiff_t			difference_type;
			
			typedef IterVector<random_access_iterator_tag, T>			iterator;
			typedef IterVector<random_access_iterator_tag, const T>		const_iterator;
			typedef IterRev<iterator>									reverse_iterator;
			typedef IterRev<const_iterator>								const_reverse_iterator;

			// Constructors
			explicit Vector(const allocator_type& alloc = allocator_type());
			explicit Vector(size_type n, const value_type &val = value_type(),
				const allocator_type& alloc = allocator_type());
			template <class InputIterator>
			Vector(InputIterator first, InputIterator last, 
				const allocator_type& alloc = allocator_type());
			Vector(const Vector &v);

			// Destructor
			~Vector(void);

			// Operator
			
			Vector							&operator=(const Vector &v);

			// Iterators
			iterator						begin (void);
			const_iterator					begin (void) const;
			iterator						end (void);
			const_iterator					end (void) const;
			reverse_iterator				rbegin (void);
			const_reverse_iterator			rbegin (void) const;
			reverse_iterator				rend (void);
			const_reverse_iterator			rend (void) const;
		
			// Capacity		
			size_type 						size (void) const;
			size_type 						max_size (void) const;
			void							resize (size_type n, value_type val = value_type());
  			size_type						capacity (void) const;
			bool 							empty (void) const;
  			void							reserve (size_type n);
		
			// Element Access
			reference 						operator[] (size_type n);
			const_reference 				operator[] (size_type n) const;
			reference 						at (size_type n);
			const_reference 				at (size_type n) const;
			reference 						front (void);
			const_reference 				front (void) const;
			reference 						back (void);
			const_reference 				back (void) const;
			
			// Modifiers		
			template <class InputIterator>
			void							assign (InputIterator first, InputIterator last);
			void							assign (size_type n, const value_type &val);
			void 							push_back (const value_type& val);
			void 							pop_back();

			iterator						insert (iterator it, const value_type &val);
			void							insert (iterator it, size_type n, const value_type &val);
			template <class	InputIterator>
			void							insert (iterator it, InputIterator fst, InputIterator lst);
			iterator 						erase (iterator position);
			iterator 						erase (iterator first, iterator last);
			void 							swap (Vector& x);
			void							clear (void);
			
			// Allocator
			allocator_type 					get_allocator (void) const;

			// Utils

		private:
			size_type		_len;
			size_type		_cap;
			value_type		*_tab;
			allocator_type	_all;
	};
	
	// Constructors
	template <class T, class Alloc>
	Vector<T, Alloc>::Vector(const allocator_type& alloc) : _len(0), _cap(0), _tab(0),  _all(alloc)
	{
	}
	
	template <class T, class Alloc>
	Vector<T, Alloc>::Vector(size_type n, const value_type &val,
		const allocator_type& alloc) : _len(0), _cap(0), _tab(0), _all(alloc)
	{
		insert(begin(), n, val);
	}

	template <class T, class Alloc>
	template <class InputIterator>
	Vector<T, Alloc>::Vector(InputIterator first, InputIterator last,
		const allocator_type& alloc) : _len(0), _cap(0), _tab(0), _all(alloc)
	{
		insert(begin(), first, last);
	}
	
	template <class T, class Alloc>
	Vector<T, Alloc>::Vector(const Vector &v) : _len(0), _cap(0), _tab(0)
	{
		_all = v._all;
		if (v.size())
			insert(begin(), v.begin(), v.end());
	}
	
	// Destructor
	
	template <class T, class Alloc>
	Vector<T, Alloc>::~Vector(void)
	{
	}

	template <class T, class Alloc>
	Vector<T, Alloc>
	&Vector<T, Alloc>::operator=(const Vector &v)
	{
		if (&v == this)
			return (*this);
		_all = v.get_allocator();
		assign(v.begin(), v.end());
		return (*this);
	}

	// Iterators

	template <class T, class Alloc>
	typename Vector<T, Alloc>::iterator
	Vector<T, Alloc>::begin(void)
	{
		return (iterator(_tab));
	}
	
	template <class T, class Alloc>
	typename Vector<T, Alloc>::const_iterator
	Vector<T, Alloc>::begin(void) const
	{
		return (const_iterator(reinterpret_cast<const T*>(_tab)));
	}
	
	template <class T, class Alloc>
	typename Vector<T, Alloc>::iterator
	Vector<T, Alloc>::end(void)
	{
		return (iterator(_tab + _len));
	}
	
	template <class T, class Alloc>
	typename Vector<T, Alloc>::const_iterator
	Vector<T, Alloc>::end(void) const
	{
		return (const_iterator(reinterpret_cast<const T*>(_tab + _len)));
	}

	template <class T, class Alloc>
	typename Vector<T, Alloc>::reverse_iterator				
	Vector<T, Alloc>::rbegin(void)
	{
		return (reverse_iterator(end()));
	}
	template <class T, class Alloc>
	typename Vector<T, Alloc>::const_reverse_iterator			
	Vector<T, Alloc>::rbegin(void) const
	{
		return (const_reverse_iterator(end()));
	}
	
	template <class T, class Alloc>
	typename Vector<T, Alloc>::reverse_iterator			
	Vector<T, Alloc>::rend(void)
	{
		return (reverse_iterator(begin()));
	}
	
	template <class T, class Alloc>
	typename Vector<T, Alloc>::const_reverse_iterator			
	Vector<T, Alloc>::rend(void) const
	{
		return (const_reverse_iterator(begin()));
	}

	// Capacity

	template<class T, class Alloc>
	typename Vector<T, Alloc>::size_type
	Vector<T, Alloc>::size(void) const
	{
		return (_len);
	}
	
	template<class T, class Alloc>
	typename Vector<T, Alloc>::size_type
	Vector<T, Alloc>::max_size(void) const
	{
		return (std::numeric_limits<difference_type>::max() / 2);
	}

	template <class T, class Alloc>
	void
	Vector<T, Alloc>::resize(size_type n, value_type val)
	{
		size_type			nb;
		std::allocator<T>	alloc;

		if (n < _len)
		{
			for (iterator it = end() - (_len - n); it != end(); ++it)
				alloc.destroy(it._val);	
		}
		else if (n > _len)
		{
			reserve(n);
			nb = n - _len;
			for (iterator it = end(); nb; --nb, ++it)
				alloc.construct(it._val, val);
		}
		_len = n;
	}

	template <class T, class Alloc>
	typename Vector<T, Alloc>::size_type
	Vector<T, Alloc>::capacity(void) const
	{
		return (!_cap ? 0 : powl(2, _cap - 1));
	}

	template<class T, class Alloc>
	bool
	Vector<T, Alloc>::empty(void) const
	{
		if (_len == 0)
			return (true);
		return (false);
	}

	template <class T, class Alloc>
	void
	Vector<T, Alloc>::reserve(size_type n)
	{
		std::allocator<T>	alloc;
		size_type			old_cap = capacity();
		size_type			new_cap;
		T		 			*new_space;
	
		if (n <= old_cap)
			return ;
		while (n > (new_cap = capacity()))
			++_cap;
		new_space = alloc.allocate(new_cap);
		for (size_type i = 0; i < _len; ++i)
		{
			alloc.construct(new_space + i, _tab[i]);
			alloc.destroy(_tab + i);
		}
		alloc.deallocate(_tab, old_cap);
		_tab = new_space;
	}

	// Element Access

	template <class T, class Alloc>
	typename Vector<T, Alloc>::reference
	Vector<T, Alloc>::operator[] (size_type n)
	{
		return (at(n));
	}

	template <class T, class Alloc>
	typename Vector<T, Alloc>::const_reference
	Vector<T, Alloc>::operator[] (size_type n) const
	{
		return (at(n));
	}

	template <class T, class Alloc>
	typename Vector<T, Alloc>::reference
	Vector<T, Alloc>::at (size_type n)
	{
		return (_tab[n]);
	}

	template <class T, class Alloc>
	typename Vector<T, Alloc>::const_reference
	Vector<T, Alloc>::at (size_type n) const
	{
		return (_tab[n]);
	}

	template <class T, class Alloc>
	typename Vector<T, Alloc>::reference
	Vector<T, Alloc>::front (void)
	{
		return (*begin());
	}

	template <class T, class Alloc>
	typename Vector<T, Alloc>::const_reference
	Vector<T, Alloc>::front (void) const
	{
		return (*begin());
	}

	template <class T, class Alloc>
	typename Vector<T, Alloc>::reference
	Vector<T, Alloc>::back (void)
	{
		return (*(end() - 1));
	}

	template <class T, class Alloc>
	typename Vector<T, Alloc>::const_reference
	Vector<T, Alloc>::back (void) const
	{
		return (*(end() - 1));
	}

	// Modifiers

	template <class T, class Alloc>
	template <class InputIterator>
	void
	Vector<T, Alloc>::assign(InputIterator first, InputIterator last)
	{
		clear();
		insert(end(), first, last);
	}

	template <class T, class Alloc>
	void
	Vector<T, Alloc>::assign(size_type n, const value_type &val)
	{
		clear();
		insert(end(), n, val);
	}


	template <class T, class Alloc>
	void
	Vector<T, Alloc>::push_back (const value_type& val)
	{
		insert(end(), val);
	}

	template <class T, class Alloc>	
	void
	Vector<T, Alloc>::pop_back()
	{
		if (_len)
			erase(end() - 1);
	}
	

	template <class T, class Alloc>
	typename Vector<T, Alloc>::iterator
	Vector<T, Alloc>::insert(iterator it, const value_type &val)
	{
		difference_type		diff = it - begin();
	
		insert(it, (size_type)1, val);
		return (begin() + diff);
	}
	
	template <class T, class Alloc>
	void
	Vector<T, Alloc>::insert(iterator it, size_type n, const value_type &val)
	{
		std::allocator<T>	alloc;
		iterator			old_end(end());
		difference_type		diff = it - begin();
	
		if (!n)
			return ;
		reserve(_len + n);
		it = begin() + diff;
		_len += n;
		for (iterator b(end() - 1), a(b - n); a >= it; --a, --b)
		{
			if (b >= old_end)
				alloc.construct(b._val, *a);
			else
				*b = *a;
		}
		for (; n; --n, ++it)
		{
			if (it >= old_end)
				alloc.construct(it._val, val);
			else
				*it = val;
		}
	}

	template <class T, class Alloc>
	template <class InputIterator>
	void
	Vector<T, Alloc>::insert(iterator it, InputIterator fst, InputIterator lst)
	{
		std::allocator<T>	alloc;
		iterator			old_end(end());
		difference_type		diff = it - begin();
	
		if (fst == lst)
			return ;
		reserve(_len + (lst - fst));
		it = begin() + diff;
		_len += lst - fst;
		for (iterator b(end() - 1), a(b - (lst - fst)); a >= it; --a, --b)
		{
			if (b >= old_end)
				alloc.construct(b._val, *a);
			else
				*b = *a;
		}
		for (; fst != lst; ++fst, ++it)
		{
			if (it >= old_end)
				alloc.construct(it._val, *fst);
			else
				*it = *fst;
		}
	}

	template <class T, class Alloc>
	typename Vector<T, Alloc>::iterator
	Vector<T, Alloc>::erase (iterator position)
	{
		return (erase(position, position + 1));
	}
	
	template <class T, class Alloc>
	typename Vector<T, Alloc>::iterator
	Vector<T, Alloc>::erase (iterator first, iterator last)
	{
		iterator	tmp(first);

		for (; last != end(); ++first, ++last)
			*first = *last;
		resize(_len - (last - first));
		return (tmp);
	}
	
	template <class T, class Alloc>
	void 
	Vector<T, Alloc>::swap (Vector & x)
	{
			T			*new_tab(_tab);
			size_type	new_size(_len);
			size_type	new_cap(_cap);
		allocator_type	new_alloc(_all);

		_tab = x._tab;
		_len = x._len;
		_cap = x._cap;
		_all = x._all;
		x._tab = new_tab;
		x._len = new_size;
		x._cap = new_cap;
		x._all = new_alloc;
	}
	

	template <class T, class Alloc>
	void
	Vector<T, Alloc>::clear(void)
	{
		resize(0);
	}

	// Allocator

	template <class T, class Alloc>
	typename Vector<T, Alloc>::allocator_type 
	Vector<T, Alloc>::get_allocator() const
	{
		return (_all);
	}

	// Relational Operators

	template <class T>
	bool
	operator==(const Vector<T> &lhs, const Vector<T> &rhs)
	{
		return (lhs < rhs || rhs < lhs ? false : true);
	}
	
	template <class T>
	bool
	operator!=(const Vector<T> &lhs, const Vector<T> &rhs)
	{
		return (!(lhs == rhs));
	}
	
	template <class T>
	bool
	operator<(const Vector<T> &lhs, const Vector<T> &rhs)
	{
		typename Vector<T>::const_iterator		lhs_it(lhs.begin());
		typename Vector<T>::const_iterator		rhs_it(rhs.begin());
	
		for (; rhs_it != rhs.end(); ++lhs_it, ++rhs_it)
		{
			if (lhs_it == lhs.end() || *lhs_it < *rhs_it)
				return (true);
		}
		return (false);
	}
	
	template <class T>
	bool
	operator<=(const Vector<T> &lhs, const Vector<T> &rhs)
	{
		return (!(lhs > rhs));
	}
	
	template <class T>
	bool
	operator>(const Vector<T> &lhs, const Vector<T> &rhs)
	{
		return (rhs < lhs);
	}
	
	template <class T>
	bool
	operator>=(const Vector<T> &lhs, const Vector<T> &rhs)
	{
		return (!(lhs < rhs));
	}
	
	template <class T>
	void
	swap(Vector<T> &x, Vector<T> &y)
	{
		x.swap(y);
	}

  
}	// end of namespace

# endif