# include <iostream>

class	ATarget
{
	public:
		ATarget(std::string const &type);
		~ATarget(void);
		std:string const	&getType(void) const;
		ATarget				*clone(void) = 0;

	private:
		std::string		_type;

	protected:
};