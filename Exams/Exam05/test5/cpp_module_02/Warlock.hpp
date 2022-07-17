# pragma once

# include <iostream>
# include <map>
# include "ASpell.hpp"
# include "ATarget.hpp"
# include "SpellBook.hpp"

class	Warlock
{
	public:
		Warlock (std::string const &name, std::string const &title);
		~Warlock();


		std::string	const	&getName() const;
		std::string const	&getTitle() const;
		void				setTitle(std::string const &title);
		void				introduce() const;

		void				learnSpell(ASpell *s);
		void				forgetSpell(std::string const &name);
		void				launchSpell(std::string const &name, ATarget const &t);


	private:
		Warlock();
		Warlock(Warlock const &w);
		Warlock	&operator=(Warlock const &w);


		std::string name;
		std::string title;
		SpellBook	book;


	protected:
};
