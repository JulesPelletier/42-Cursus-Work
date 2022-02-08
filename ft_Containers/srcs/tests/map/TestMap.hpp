#ifndef TESTMAP_HPP
# define TESTMAP_HPP

# include <iostream>
# include <string>

class TestMap
{

	public:

		TestMap();
		TestMap( TestMap const & src );
		~TestMap();

		TestMap &		operator=( TestMap const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, TestMap const & i );

#endif /* ********************************************************* TESTMAP_H */