#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>
# include "Colors.hpp"

class ClapTrap
{

	public:

		ClapTrap(std::string str);
		ClapTrap( ClapTrap const & src );
		~ClapTrap();

		ClapTrap &		operator=( ClapTrap const & rhs );

		void 			attack(const std::string& target);
		void 			takeDamage(unsigned int amount);
		void 			beRepaired(unsigned int amount);

	protected:
		std::string		_name;
		int				_hp;
		int				_ep;
		int				_attack;

};

#endif /* ******************************************************** CLAPTRAP_H */