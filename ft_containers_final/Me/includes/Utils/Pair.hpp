/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:43:30 by julpelle          #+#    #+#             */
/*   Updated: 2022/03/30 19:35:58 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PAIR_HPP
# define PAIR_HPP

namespace	ft
{

	template <class T1, class T2>
	struct	Pair
	{
		public:
			// Types
			typedef T1		first_type;
			typedef T2		second_type;

			// Constructors
			Pair(void);
			template <class U, class V>
			Pair(const Pair<U, V> &pr);
			Pair (const first_type &a, const second_type &b);
			
			// Destructor
			~Pair(void);

			// Assignation
			Pair			&operator= (const Pair& pr);

			first_type		a;
			second_type		b;

		private:

	};

	// Constructors
	
	template <class T1, class T2>
	Pair<T1, T2>::Pair(void) : a(), b()
	{
	}

	template <class T1, class T2>
	template <class U, class V>
	Pair<T1, T2>::Pair(const Pair<U, V> &pr) : a(pr.a), b(pr.b)
	{
	}

	template <class T1, class T2>
	Pair<T1, T2>::Pair (const first_type &a, const second_type &b) : a(a), b(b)
	{
	}

	// Destructor
	template <class T1, class T2>
	Pair<T1, T2>::~Pair (void)
	{
	}

	template <class T1, class T2>
	Pair<T1, T2>		
	&Pair<T1, T2>::operator= (const Pair<T1, T2> &pr)
	{
		if (this == &pr)
			return (*this);
		a = pr.a;
		b = pr.b;
		return (*this);
	}

	template <class T1, class T2>
	bool
	operator== (const Pair<T1,T2>& lhs, const Pair<T1,T2>& rhs)
	{
		return (lhs.first==rhs.first && lhs.second==rhs.second);
	}
	
	template <class T1, class T2>
	bool
	operator!= (const Pair<T1,T2>& lhs, const Pair<T1,T2>& rhs)
	{
		return !(lhs==rhs);
	}
	
	template <class T1, class T2>
	bool operator<  (const Pair<T1,T2>& lhs, const Pair<T1,T2>& rhs)
	{
		return (lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second));
	}
	
	template <class T1, class T2>
	bool operator<= (const Pair<T1,T2>& lhs, const Pair<T1,T2>& rhs)
	{
		return (!(rhs<lhs));
	}
	
	template <class T1, class T2>
	bool operator>  (const Pair<T1,T2>& lhs, const Pair<T1,T2>& rhs)
	{
		return (rhs<lhs);
	}
	
	template <class T1, class T2>
	bool operator>= (const Pair<T1,T2>& lhs, const Pair<T1,T2>& rhs)
	{
		return (!(lhs<rhs));
	}

	template <class T1, class T2>
	Pair<T1, T2> make_pair (T1 x, T2 y)
	{
		//std::cout << "Pair made \n";
		return Pair<T1, T2>(x,y);
	}

	template <class T1, class T2>
	std::ostream &			operator<<( std::ostream & o, Pair<T1, T2> const & i )
	{
		std::cout << "Pair : \n\t 1st item : " << i.a << "\t 2nd item : " << i.b;
		return o;
	}

}	// end of namespace

# endif