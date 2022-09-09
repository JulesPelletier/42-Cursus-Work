# pragma once 

# include <iostream>
# include "ASpell.hpp"
# include "ATarget.hpp"
# include <map>

class	Warlock
{
	public:
		Warlock(std::string const &name, std::string const &title);
		~Warlock();

		std::string	const 	&getName(void)const;
		std::string const 	&getTitle(void) const;

		void				setTitle(std::string const &title);
		void				introduce(void) const;
		void				learnSpell(ASpell *s);
		void				forgetSpell(std::string const &spell);
		void				launchSpell(std::string const &spell, ATarget const &t);


	private:
		Warlock(void);
		Warlock(Warlock const &w);
		Warlock	&operator=(Warlock const &w);

		
		std::string	name;
		std::string	title;
		std::map<std::string, ASpell *> tab;

	protected:
};