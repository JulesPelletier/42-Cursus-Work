#include "TestMap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

TestMap::TestMap()
{
}

TestMap::TestMap( const TestMap & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

TestMap::~TestMap()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

TestMap &				TestMap::operator=( TestMap const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, TestMap const & i )
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