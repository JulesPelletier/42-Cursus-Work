# pragma once

# include <iostream>
# include "ASpell.hpp"
# include <map>

class	SpellBook
{
	public:
		SpellBook();
		~SpellBook();

		void	learnSpell(ASpell *s);
		void	forgetSpell(std::string const &name);
		ASpell	*createSpell(std::string const &name);

		
	private:
		SpellBook(SpellBook const &sb);
		SpellBook &operator=(SpellBook const &sb);
		
		std::map<std::string, ASpell *>	book;


	protected:
};
