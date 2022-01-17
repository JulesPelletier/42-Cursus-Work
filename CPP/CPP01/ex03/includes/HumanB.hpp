#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{

	public:

		HumanB(std::string name);
		~HumanB();

		void	attack(void) const;
		int		setWeapon(Weapon type);
		Weapon	*getWeapon(void) const;
	private:
		std::string	name;
		Weapon	*weapon;

};

#endif /* ********************************************************** HUMANB_H */