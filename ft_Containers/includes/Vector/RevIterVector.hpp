#ifndef REVITERVECTOR_HPP
# define REVITERVECTOR_HPP

# include <iostream>
# include <string>
# include "../AllContainers.hpp"

namespace ft
{

template<class T>
class RevIterVector
{

	public:
		// Type Defs
		typedef T				value_type;
		typedef	T&				reference;
		typedef T*				pointer;
		typedef std::ptrdiff_t	difference_type;
		typedef size_t			size_type;
		typedef std::string		iterator_type;

		//Constructors & Destructors
		RevIterVector(void);
		RevIterVector(value_type *p);
		RevIterVector(const RevIterVector &v);
		~RevIterVector(void);

		// Assignation
		RevIterVector &		operator=( RevIterVector const & rhs );

		// Operators
		bool				operator==(const RevIterVector &x) const;
		bool				operator!=(const RevIterVector &x) const;
		RevIterVector		&operator*(void);
		RevIterVector		*operator->(void);
		RevIterVector		&operator[](difference_type index) const;
		RevIterVector		&operator++(void);
		RevIterVector		&operator--(void);
		RevIterVector		&operator+(difference_type inc) const;
		RevIterVector		operator-(difference_type dec) const;
		RevIterVector		&operator+=(difference_type inc);
		RevIterVector		operator-=(difference_type dec);

	private:

};

template<class T>
std::ostream &			operator<<( std::ostream & o, RevIterVector<T> const & i );

} // End of namespace

#endif /* *************************************************** REVITERVECTOR_H */