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
		value_type		*_ptr;
};

template<class T>
RevIterVector<T>::RevIterVector(void) : _ptr(0)
{
	std::cout << Yellow "Default constructor called for iterator" Reset << std::endl;
}

template<class T>
RevIterVector<T>::RevIterVector(value_type *p) : _ptr(p)
{
	std::cout << Yellow "Default constructor called for iterator" Reset << std::endl;
}

template<class T>
RevIterVector<T>::RevIterVector(const RevIterVector &v) : _ptr(v._ptr)
{
	*this = v;
	std::cout << Yellow "Copy constructor called for iterator" Reset << std::endl;
}

template<class T>
RevIterVector<T>::~RevIterVector(void)
{
	std::cout << Yellow "Default destructor called for iterator" Reset << std::endl;
}

// Assignation
template<class T>
RevIterVector<T> 				&RevIterVector<T>::operator=( RevIterVector const & rhs )
{
	if (this == rhs)
		return (*this);
	this->_ptr = rhs._ptr;
	return (*this);
}

// Operators
template<class T>
bool				RevIterVector<T>::operator==(const RevIterVector &x) const
{
	if (this->_ptr == x._ptr)
		return (true);
	return (false);
}
template<class T>
bool				RevIterVector<T>::operator!=(const RevIterVector &x) const
{
	if (this->_ptr == x._ptr)
		return (false);
	return (true);
}

template<class T>
RevIterVector<T>			&RevIterVector<T>::operator*(void)
{
	return (*this->_ptr);
}

template<class T>
RevIterVector<T>			*RevIterVector<T>::operator->(void)
{
	return (this->_ptr);
}

template<class T>
RevIterVector<T>			&RevIterVector<T>::operator[](difference_type index) const
{
	return (*(this->_ptr + index));
}

template<class T>
RevIterVector<T>			&RevIterVector<T>::operator++(void)
{
	++this->_ptr;
	return (*this);
}

template<class T>
RevIterVector<T>			&RevIterVector<T>::operator--(void)
{
	--this->_ptr;
	return (*this);
}

template<class T>
RevIterVector<T>			&RevIterVector<T>::operator+(difference_type inc) const
{
	RevIterVector	copy(*this);

	copy->_ptr = copy->_ptr + inc;
	return (copy);
}

template<class T>
RevIterVector<T>			RevIterVector<T>::operator-(difference_type dec) const
{
	RevIterVector	copy(*this);

	copy->_ptr = copy->_ptr - dec;
	return (copy);
}

template<class T>
RevIterVector<T>			&RevIterVector<T>::operator+=(difference_type inc)
{
	this->ptr = this->_ptr + inc;
	return (*this);
}

template<class T>
RevIterVector<T>			RevIterVector<T>::operator-=(difference_type dec)
{
	this->ptr = this->_ptr - dec;
	return (*this);
}

// Stream
template<class T>
std::ostream &			operator<<( std::ostream & o, RevIterVector<T> const & i );

} // End of namespace

#endif /* *************************************************** REVITERVECTOR_H */