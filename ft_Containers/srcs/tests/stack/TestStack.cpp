#include "TestStack.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

TestStack::TestStack()
{
}

TestStack::TestStack( const TestStack & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

TestStack::~TestStack()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

TestStack &				TestStack::operator=( TestStack const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, TestStack const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */