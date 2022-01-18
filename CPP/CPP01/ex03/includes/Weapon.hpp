#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{

	public:

		Weapon(std::string	type);
		~Weapon();

		void					setType(std::string const &newType);
		std::string const		&getType(void) const;

	private:
		std::string				type;
};


#endif /* ********************************************************** WEAPON_H */