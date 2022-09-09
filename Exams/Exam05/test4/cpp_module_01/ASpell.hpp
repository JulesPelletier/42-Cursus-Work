# pragma once

# include <iostream>

class	ATarget;

class	ASpell
{
	private:

	public:
		ASpell();
		ASpell(ASpell const &s);
		ASpell(std::string const &name, std::string const &effects);
		virtual ~ASpell();

		ASpell &operator=(ASpell const &s);


		std::string const	&getName(void) const;
		std::string const	&getEffects(void) const;
		void				launch(ATarget const &t) const;

		virtual ASpell		*clone(void) const = 0;
	protected:
		std::string	name;
		std::string effects;
};

# include "ATarget.hpp"