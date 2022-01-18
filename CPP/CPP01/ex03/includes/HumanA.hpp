#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA
{

	public:

		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);

		void			attack(void) const;
		void			setType(std::string type);
		Weapon			&getWeapon(void) const;

	private:
		std::string		_name;
		Weapon&			_weapon;

};


#endif /* ********************************************************** HUMANA_H */