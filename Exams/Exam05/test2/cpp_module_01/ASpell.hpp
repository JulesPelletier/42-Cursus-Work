# include <iostream>

class	ASpell
{
	private:

	public:
		ASpell(std::string const &name, std::string const &effects);
		~ASpell(void);

		std::string	const	&getName(void) const;
		std::string const	&getEffects(void) const;
		ASpell				*clone(void) = 0;

	protected:
		std::string	_name;
		std::string	_effects;
};