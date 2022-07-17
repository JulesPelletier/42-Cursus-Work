# pragma once

# include <iostream>

class	ASpell;

class	ATarget
{
	public:
		ATarget(std::string const &type);
		virtual ~ATarget();

		ATarget &operator=(ATarget const &s);

		std::string const	&getType() const;
		virtual ATarget		*clone() const = 0;
		void				getHitBySpell(ASpell const &s) const;


	private:
		ATarget();
		ATarget(ATarget const &s);

		std::string type;	

	protected:

};

# include "ASpell.hpp"