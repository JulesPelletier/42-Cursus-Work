# include "ATarget.hpp"

ATarget::ATarget(std::string const &type)
{
	this->type = type;
}

ATarget::~ATarget()
{

}

std::string	const	&ATarget::getType() const
{
	return (this->type);
}

void				ATarget::getHitBySpell(ASpell const &s) const
{
	std::cout << this->type << " has been " << s.getEffects() << "!\n";
}
