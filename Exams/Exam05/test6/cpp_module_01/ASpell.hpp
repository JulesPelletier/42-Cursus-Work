# pragma once

# include <iostream>
# include "ATarget.hpp"

class	ATarget;

class	ASpell
{
	public:
		ASpell(std::string const &name, std::string const &effects);
		virtual ~ASpell();

		std::string const	&getName() const;
		std::string const	&getEffects() const;

		virtual ASpell *clone() const = 0;

		void				launch(ATarget const &t) const;
		
	private:
		ASpell();
		ASpell(ASpell const &s);
		ASpell &operator=(ASpell const &s);

	protected:
		std::string name;
		std::string effects;
};