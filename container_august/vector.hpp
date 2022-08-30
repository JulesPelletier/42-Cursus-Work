/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:58:48 by julpelle          #+#    #+#             */
/*   Updated: 2022/08/25 11:33:53 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef vector_HPP
# define vector_HPP

# include "All.hpp"
# include "iterRev.hpp"
# include "itervector.hpp"
# include "iterTraits.hpp"
# include "types.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include <limits.h>

namespace ft {

	template <class T, class Alloc = std::allocator<T> >
	class vector
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
			
			typedef Itervector<T>			iterator;
			typedef Itervector<const T>		const_iterator;
			typedef IterRev<iterator>		reverse_iterator;
			typedef IterRev<const_iterator>	const_reverse_iterator;

			// Constructors
			explicit vector(const allocator_type& alloc = allocator_type());
			explicit vector(size_type n, const value_type &val = value_type(),
				const allocator_type& alloc = allocator_type());
			template <class InputIterator>
			vector(InputIterator first, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type last,
				const allocator_type& alloc = allocator_type());
			vector(const vector &v);

			// Destructor
			~vector(void);

			// Operator
			
			vector							&operator=(const vector &v);

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
			void							insert (iterator it, InputIterator fst, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type last);
			iterator 						erase (iterator position);
			iterator 						erase (iterator first, iterator last);
			void 							swap (vector& x);
			void							clear (void);
			
			// Allocator
			allocator_type 					get_allocator (void) const;

			// Utils


		private:
			size_type		_len;
			size_type		_cap;
			size_type		_val;
			value_type		*_tab;
			allocator_type	_all;
			pointer			_old_val;
			size_type		_old_cap;
			size_type		_old_len;

			void	_save_old(void)
			{
				_old_val = _val;
				_old_cap = _cap;
				_old_len = _len;
			}

			bool	_prepare_insert(size_type diff, size_type n)
			{
				bool	new_alloc = false;
				
				if (_cap < _len + n)
				{
					if (n == 1 && !_len)
						_reserve_no_destroy_move(1, diff, n);
					else if (_len << 1 < _len + n)
						_reserve_no_destroy_move(_len + n, diff, n);
					else
						_reserve_no_destroy_move(_len << 1, diff, n);
					new_alloc = true;
				}
				else
					_reserve_no_destroy_move(0, diff, n);
				return new_alloc;
			}

			void	_destroy_dealloc_old()
			{
				if (_old_cap)
				{
					for (size_type i = 0; i < _old_len; i++)
					{
						_all.destroy(&_old_val[i]);
					}
					if (_old_cap < _cap)
						_all.deallocate(&_old_val[-1], _old_cap + 2);
					_old_cap = 0;
				}
			}

			void	_reserve_no_destroy_move(size_type n, size_type diff, size_type n_new)
			{
				if (n > _all.max_size())
					throw (std::length_error("vector::reserve"));
				if (n > _cap)
				{
					_save_old();
					_val = &_all.allocate(n + 2)[1];
	
					if (_cap && _len)
					{
						for (size_type i = 0; i < diff; i++)
						{
							_all.construct(&_val[i], _old_val[i]);
						}
						for (size_type i = _len - 1; i >= diff; i--)
						{
							_all.construct(&_val[i + n_new], _old_val[i]);
							if (!i)
								break;
						}
					}
					_cap = n;
				}
				else if (_len)
					for (size_type i = _len - 1; i >= diff; i--)
					{
						if (i + n_new < _len)
							_val[i + n_new] = _val[i];
						else
							_all.construct(&_val[i + n_new], _val[i]);
						if (!i)
								break;
					}
			}

	};
	
	// Constructors
	template <class T, class Alloc>
	vector<T, Alloc>::vector(const allocator_type& alloc) : _len(0), _cap(0), _tab(0),  _all(alloc)
	{
	}
	
	template <class T, class Alloc>
	vector<T, Alloc>::vector(size_type n, const value_type &val,
		const allocator_type& alloc) : _len(0), _cap(0), _tab(0), _all(alloc)
	{
		assign(n, val);
	}

	template <class T, class Alloc>
	template <class InputIterator>
	vector<T, Alloc>::vector(InputIterator first, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type last,
		const allocator_type& alloc) : _val(0), _len(0), _cap(0), _tab(0), _all(alloc)
	{
		assign(first, last);
	}
	
	template <class T, class Alloc>
	vector<T, Alloc>::vector(const vector &v) : _len(0), _cap(0), _tab(0)
	{
		*this = v;
	}
	
	// Destructor
	
	template <class T, class Alloc>
	vector<T, Alloc>::~vector(void)
	{
		if (_cap)
			{
				for (size_type i = 0; i < _len; i++)
				{
					_all.destroy(&_tab[i]);
				}
				_all.deallocate(_tab, _cap);

			}
	}

	template <class T, class Alloc>
	vector<T, Alloc>
	&vector<T, Alloc>::operator=(const vector &v)
	{
		if (&v == this)
			return (*this);
		_all = v.get_allocator();
		assign(v.begin(), v.end());
		return (*this);
	}

	// Iterators

	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator
	vector<T, Alloc>::begin(void)
	{
		return (iterator(_tab));
	}
	
	template <class T, class Alloc>
	typename vector<T, Alloc>::const_iterator
	vector<T, Alloc>::begin(void) const
	{
		return (const_iterator(reinterpret_cast<const T*>(_tab)));
	}
	
	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator
	vector<T, Alloc>::end(void)
	{
		return (iterator(_tab + _len));
	}
	
	template <class T, class Alloc>
	typename vector<T, Alloc>::const_iterator
	vector<T, Alloc>::end(void) const
	{
		return (const_iterator(reinterpret_cast<const T*>(_tab + _len)));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reverse_iterator				
	vector<T, Alloc>::rbegin(void)
	{
		return (reverse_iterator(end()));
	}
	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reverse_iterator			
	vector<T, Alloc>::rbegin(void) const
	{
		return (const_reverse_iterator(end()));
	}
	
	template <class T, class Alloc>
	typename vector<T, Alloc>::reverse_iterator			
	vector<T, Alloc>::rend(void)
	{
		return (reverse_iterator(begin()));
	}
	
	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reverse_iterator			
	vector<T, Alloc>::rend(void) const
	{
		return (const_reverse_iterator(begin()));
	}

	// Capacity

	template<class T, class Alloc>
	typename vector<T, Alloc>::size_type
	vector<T, Alloc>::size(void) const
	{
		return (_len);
	}
	
	template<class T, class Alloc>
	typename vector<T, Alloc>::size_type
	vector<T, Alloc>::max_size(void) const
	{
		return (_all.max_size());
	}

	template <class T, class Alloc>
	void
	vector<T, Alloc>::resize(size_type n, value_type val)
	{
		if (n < _len)
				for (size_t	i = n; i < _len; i++)
					_all.destroy(&_val[i]);
			else if (n > _len)
			{
				insert(end(), n - _len, val);
			}
			_len = n;
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::size_type
	vector<T, Alloc>::capacity(void) const
	{
		if (_cap >= _len)
			return (_cap);
		else
			return (!_cap ? 0 : powl(2, _cap - 1));
	}

	template<class T, class Alloc>
	bool
	vector<T, Alloc>::empty(void) const
	{
		if (_len == 0)
			return (true);
		return (false);
	}

	template <class T, class Alloc>
	void
	vector<T, Alloc>::reserve(size_type n)
	{
		std::allocator<T>	alloc;
		size_type			old_cap = capacity();
		T		 			*new_space;
	
		if (n > max_size())
			throw std::length_error("vector::reserve");
		if (n > _cap)
		{
			value_type *tmp = _tab;
			_cap = n;
			if (n <= (2 * _len))
				_cap = 2 * _len;
			if (_cap)
				_tab = _all.allocate(_cap);
			else
				_tab = NULL;
			for (size_type i = 0; i < _len && tmp && i < _cap; i++)
				_all.construct(_tab + i, tmp[i]);
			for(size_type i = 0; i < _len && tmp; i++)
				_all.destroy(tmp + i);
			if (tmp)
				_all.deallocate(tmp, old_cap);
		}
	}

	// Element Access

	template <class T, class Alloc>
	typename vector<T, Alloc>::reference
	vector<T, Alloc>::operator[] (size_type n)
	{
		return (at(n));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reference
	vector<T, Alloc>::operator[] (size_type n) const
	{
		return (at(n));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reference
	vector<T, Alloc>::at (size_type n)
	{
		return (_tab[n]);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reference
	vector<T, Alloc>::at (size_type n) const
	{
		return (_tab[n]);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reference
	vector<T, Alloc>::front (void)
	{
		return (*begin());
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reference
	vector<T, Alloc>::front (void) const
	{
		return (*begin());
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reference
	vector<T, Alloc>::back (void)
	{
		return (*(end() - 1));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reference
	vector<T, Alloc>::back (void) const
	{
		return (*(end() - 1));
	}

	// Modifiers

	template <class T, class Alloc>
	template <class InputIterator>
	void
	vector<T, Alloc>::assign(InputIterator first, InputIterator last)
	{
		clear();
		insert(end(), first, last);
	}

	template <class T, class Alloc>
	void
	vector<T, Alloc>::assign(size_type n, const value_type &val)
	{
		clear();
		insert(end(), n, val);
	}


	template <class T, class Alloc>
	void
	vector<T, Alloc>::push_back (const value_type& val)
	{
		insert(end(), val);
	}

	template <class T, class Alloc>	
	void
	vector<T, Alloc>::pop_back()
	{
		if (_len)
			erase(end() - 1);
	}
	

	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator
	vector<T, Alloc>::insert(iterator it, const value_type &val)
	{
		difference_type		diff = it - begin();
	
		insert(it, (size_type)1, val);
		return (begin() + diff);
	}

	template <class T, class Alloc>
	void
	vector<T, Alloc>::insert(iterator it, size_type n, const value_type &val)
	{
		size_type		diff = it - begin();
		bool			new_alloc = _prepare_insert(diff, n);
		
		for (size_type i = diff; i < diff + n; i++)
		{
			if (i < _len && !new_alloc)
				_val[i] = val;
			else
				_all.construct(&_val[i], val);
		}
		_len += n;
		_destroy_dealloc_old();
	}

	template <class T, class Alloc>
	template <class InputIterator>
	void
	vector<T, Alloc>::insert(iterator it, InputIterator fst, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type lst)
	{
		size_type		diff = it - begin();
		size_type		n = lst - fst;
		bool			new_alloc = _prepare_insert(diff, n);
		
		for (size_type i = diff; i < diff + n; i++)
		{
			if (i < _len && !new_alloc)
				_val[i] = *fst;
			else
				_all.construct(&_val[i], *fst);
			fst++;
		}
		_len += n;
		_destroy_dealloc_old();
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator
	vector<T, Alloc>::erase (iterator position)
	{
		return (erase(position, position + 1));
	}
	
	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator
	vector<T, Alloc>::erase (iterator first, iterator last)
	{
		iterator	tmp(first);

		for (; last != end(); ++first, ++last)
			*first = *last;
		resize(_len - (last - first));
		return (tmp);
	}
	
	template <class T, class Alloc>
	void 
	vector<T, Alloc>::swap (vector & x)
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
	vector<T, Alloc>::clear(void)
	{
		resize(0);
	}

	// Allocator

	template <class T, class Alloc>
	typename vector<T, Alloc>::allocator_type 
	vector<T, Alloc>::get_allocator() const
	{
		return (_all);
	}

	// Relational Operators
	
	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
	
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}
	
	template <class T, class Alloc>
	bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs > rhs));
	}
	
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs == rhs || lhs < rhs));
	}
	
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}


	template <class T>
	void
	swap(vector<T> &x, vector<T> &y)
	{
		x.swap(y);
	}

  
}	// end of namespace

# endif