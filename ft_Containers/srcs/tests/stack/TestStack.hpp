#ifndef TESTSTACK_HPP
# define TESTSTACK_HPP

# include <iostream>
# include <string>

class TestStack
{

	public:

		TestStack();
		TestStack( TestStack const & src );
		~TestStack();

		TestStack &		operator=( TestStack const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, TestStack const & i );

#endif /* ******************************************************* TESTSTACK_H */