# pragma once

# include <iostream>

class	ASpell;

class	ATarget
{
	private:
		std::string	type;

	public:
		ATarget();
		ATarget(ATarget const &t);
		ATarget(std::string const &type);
		virtual ~ATarget();
		
		ATarget &operator=(ATarget const &t);

		std::string const 	&getType(void) const;
		virtual ATarget		*clone(void) const = 0;
		void				getHitBySpell(ASpell const &s) const;
	
	protected:
};

# include "ASpell.hpp"