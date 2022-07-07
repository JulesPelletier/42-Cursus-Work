# include <iostream>

class	ATarget;

class	ASpell
{
	protected:
		std::string		name;
		std::string		effects;
	
	public:
		ASpell(void);
		ASpell(ASpell const &s);
		ASpell(std::string const &name, std::string const &effects);
		ASpell &operator=(const ASpell &s);
		virtual ~ASpell(void);

		std::string const	&getName(void) const;
		std::string const	&getEffects(void) const;

}