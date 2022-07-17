# pragma once

# include <iostream>
# include "ASpell.hpp"

class	ASpell;

class	ATarget
{
	public:
		ATarget(std::string const &type);
		virtual ~ATarget();


		std::string	const	&getType() const;
		virtual	ATarget		*clone() const = 0;
		void				getHitBySpell(ASpell const &s) const;

	private:
		ATarget();
		ATarget(ATarget const &t);

		ATarget &operator=(ATarget const &t);

		std::string type;

	protected:
};