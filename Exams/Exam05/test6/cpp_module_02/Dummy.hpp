# include "ASpell.hpp"

class	Dummy : public ATarget
{
	public:
		Dummy();
		~Dummy();

		ATarget	*clone() const;
	private:

	protected:
};