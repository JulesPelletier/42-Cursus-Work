/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:58:48 by julpelle          #+#    #+#             */
/*   Updated: 2022/08/25 12:31:29 by julpelle         ###   ########.fr       */
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
			
			typedef ft::Itervector<T>			iterator;
			typedef ft::Itervector<const T>		const_iterator;
			typedef ft::IterRev<iterator>		reverse_iterator;
			typedef ft::IterRev<const_iterator>	const_reverse_iterator;

			// Constructors
			
			explicit vector(const allocator_type& alloc = allocator_type()) 
			: _val(0), _len(0), _cap(0), _all(alloc), _old_cap(0)
			{
			}
			
			explicit vector(size_type n, const value_type &val = value_type(),
				const allocator_type& alloc = allocator_type())
			: _val(0), _len(0), _cap(0), _all(alloc), _old_cap(0)
			{
				assign(n, val);
			}
			
			template <class InputIterator>
			vector(InputIterator first, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type last,
				const allocator_type& alloc = allocator_type())
				: _val(0), _len(0), _cap(0), _all(alloc), _old_cap(0)
			{
				assign(first, last);
			}
			
			vector(const vector &v) : _val(0), _len(0), _cap(0), _old_cap(0)
			{
				*this = v;
			}

			// Destructor
			
			virtual ~vector(void)
			{
				if (_cap)
				{
					for (size_type i = 0; i < _len; i++)
					{
						_all.destroy(&_val[i]);
					}
					_all.deallocate(_val, _cap);
				}
			}

			// Operator
			
			vector							&operator=(const vector &v)
			{
				if (this != &v)
				{
					_all = v._all;
					assign(v.begin(), v.end());
				}
				return (*this);
			}

			// Iterators
			
			iterator						begin (void)
			{
				return (iterator(_val[0]));
			}
			
			const_iterator					begin (void) const
			{
				return (const_iterator(_val[0]));
			}
			
			iterator						end (void)
			{
				return (iterator(_val[_len]));
			}

			const_iterator					end (void) const
			{
				return (const_iterator(_val[_len]));
			}
			
			reverse_iterator				rbegin (void)
			{
				return (reverse_iterator(end()));
			}
			
			const_reverse_iterator			rbegin (void) const
			{
				return (const_reverse_iterator(end()));
			}
			
			reverse_iterator				rend (void)
			{
				return (reverse_iterator(begin()));
			}
			
			const_reverse_iterator			rend (void) const
			{
				return (const_reverse_iterator(begin()));
			}
		
			// Capacity	
				
			size_type 						size (void) const
			{
				return (_len);
			}
			
			size_type 						max_size (void) const
			{
				return (_all.max_size());
			}
			
			void							resize (size_type n, value_type val = value_type())
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
			
  			size_type						capacity (void) const
			{
				return (_cap);
			}
			
			bool 							empty (void) const
			{
				if (_len == 0)
					return (true);
				return (false);
			}
  			void							reserve (size_type n)
			{
				if (n > _all.max_size())
					throw (std::length_error("vector::reserve"));
				if (n > _cap)
				{
					pointer		tmp = &_all.allocate(n + 2)[1];
	
					if (_cap)
					{
						for (size_type i = 0; i < _len; i++)
							_all.construct(&tmp[i], _val[i]);
						for (size_type i = 0; i < _len; i++)
							_all.destroy(&_val[i]);
						_all.deallocate(&_val[-1], _cap + 2);
					}
					_val = tmp;
					_cap = n;
				}
			}
		
			// Element Access
			
			reference 						operator[] (size_type n)
			{
				return (at(n));
			}
			
			const_reference 				operator[] (size_type n) const
			{
				return (at(n));
			}
			
			reference 						at (size_type n)
			{
				if (n >= _len)
					throw std::out_of_range("");
				else
					return (_val[n]);
			}

			const_reference 				at (size_type n) const
			{
				if (n >= _len)
					throw std::out_of_range("");
				else
					return (_val[n]);
			}
			
			reference 						front (void)
			{
				return (_val[0]);
			}
			
			const_reference 				front (void) const
			{
				return (_val[0]);
			}
			
			reference 						back (void)
			{
				return (_val[_len]);
			}

			const_reference 				back (void) const
			{
				return (_val[_len]);
			}
			
			// Modifiers	
				
			template <class InputIterator>
			void							assign (InputIterator first, InputIterator last)
			{
				size_type	len = last - first;
				_save();
				if (_cap < len)
				{
					_cap = 0;
					reserve(len);
				}
				size_type	i = 0;
				for (InputIterator it = first; it != last; it++)
				{
					_all.construct(&_val[i], *it);
					i++;
				}
				_len = i;
				_destroy_alloc();
			}
			
			void							assign (size_type n, const value_type &val)
			{
				_save();
				if (_cap < n)
				{
					_cap = 0;
					reserve(n);
				}
				for (size_type i = 0; i < n; i++)
				{
					_all.construct(&_val[i], val);
				}
				_len = n;
				_destroy_alloc();
			}
			
			void 							push_back (const value_type& val)
			{
				insert(end(), val);
			}

			void 							pop_back(void)
			{
				erase(end() - 1);
			}

			iterator						insert (iterator it, const value_type &val)
			{
				size_type		diff = it - begin();

				insert(it, 1, val);
				return(begin() + diff);
			}
			
			void							insert (iterator it, size_type n, const value_type &val)
			{
				size_type		diff = it - begin();
				bool			new_alloc = _preinsert(diff, n);

				for (size_type i = diff; i < diff + n; i++)
				{
					if (i < _len && !new_alloc)
						_val[i] = val;
					else
						_all.construct(&_val[i], val);
				}
				_len += n;
				_destroy_alloc();
			}
			
			template <class	InputIterator>
			void							insert (iterator it, InputIterator fst, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type lst)
			{
				size_type		diff = it - begin();
				size_type		n = lst - fst;
				bool			new_alloc = _preinsert(diff, n);
	
				for (size_type i = diff; i < diff + n; i++)
				{
					if (i < _len && !new_alloc)
						_val[i] = *fst;
					else
						_all.construct(&_val[i], *fst);
					fst++;
				}
				_len += n;
				_destroy_alloc();
			}
			
			iterator 						erase (iterator position)
			{
				for (iterator it = position; it != end() - 1; it++)
				{
					*it = *(it + 1);
				}
				_all.destroy(&_val[_len - 1]);
				_len--;
				return position;
			}
			
			iterator 						erase (iterator first, iterator last)
			{
				size_type	len = last - first;

				for (iterator it = first; it != end() - len; it++)
						*it = *(it + len);
				for (iterator it = end() - len; it != end(); it++)
					_all.destroy(&(*it));
				_len -= len;
				return first;
			}

			void 							swap (vector& x)
			{
				pointer				tmp_val;
				size_type			tmp;
	
				tmp = _cap;
				_cap = x._cap;
				x._cap = tmp;
				tmp = _len;
				_len = x._len;
				x._len = tmp;
				tmp_val = _val;
				_val = x._val;
				x._val = tmp_val;
			}
			
			void							clear (void)
			{
				erase(begin(), end());
			}
			
			// Allocator
			
			allocator_type 					get_allocator (void) const
			{
				return (_all);
			}

		private:
			pointer			_val;
			size_type		_len;
			size_type		_cap;
			allocator_type	_all;
			pointer			_old_val;
			size_type		_old_cap;
			size_type		_old_len;

			void	_save(void)
			{
				_old_val = _val;
				_old_cap = _cap;
				_old_len = _len;
			}

			bool	_preinsert(size_type diff, size_type n)
			{
				bool	new_alloc = false;
				
				if (_cap < _len + n)
				{
					if (n == 1 && !_len)
						_reserve_util(1, diff, n);
					else if (_len << 1 < _len + n)
						_reserve_util(_len + n, diff, n);
					else
						_reserve_util(_len << 1, diff, n);
					new_alloc = true;
				}
				else
					_reserve_util(0, diff, n);
				return new_alloc;
			}

			void	_destroy_alloc()
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

			void	_reserve_util(size_type n, size_type diff, size_type n_new)
			{
				if (n > _all.max_size())
					throw (std::length_error("vector::reserve"));
				if (n > _cap)
				{
					_save();
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
	
}	// end of namespace

# endif