# pragma once

# include <iostream>
# include "ATarget.hpp"

class	ATarget;

class	ASpell
{
	public:
		ASpell();
		ASpell(ASpell const &s);
		ASpell(std::string const &name, std::string const &effects);
		virtual ~ASpell();

		ASpell &operator=(ASpell const &s);

		virtual	ASpell		*clone() const = 0;

		std::string const	&getName() const;
		std::string const	&getEffects() const;

		void				launch(ATarget const &t);

	private:

	protected:
		std::string name;
		std::string effects;
};