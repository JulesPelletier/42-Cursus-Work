# include "ASpell.hpp"

class	BrickWall : public ATarget
{
	public:
		BrickWall();
		~BrickWall();

		ATarget	*clone() const;
	private:

	protected:
};