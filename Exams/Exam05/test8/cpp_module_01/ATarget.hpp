# pragma once

# include <iostream>
# include "ASpell.hpp"

class	ASpell;

class	ATarget
{
	public:
		ATarget();
		ATarget(ATarget const &t);
		ATarget(std::string const &type);
		virtual ~ATarget();

		ATarget	&operator=(ATarget const &t);
		
		virtual	ATarget	 	*clone() const = 0;

		std::string const	&getType() const;
		void				getHitBySpell(ASpell const &s) const;

	private:
		std::string	type;
	protected:
};