# pragma once

# include <iostream>

class	ATarget;

class	ASpell
{
	public:
		ASpell(std::string const &name, std::string const &effects);
		virtual ~ASpell();

		ASpell &operator=(ASpell const &s);

		std::string const	&getName() const;
		std::string const	&getEffects() const;
		virtual ASpell		*clone() const = 0;

		void				launch(ATarget const &t);

	private:
		ASpell();
		ASpell(ASpell const &s);

	protected:
		std::string	name;
		std::string effects;

};

# include "ATarget.hpp"