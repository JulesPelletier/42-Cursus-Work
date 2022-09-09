# include "ATarget.hpp"

ATarget::ATarget() 
{

}

ATarget::ATarget(ATarget const &t) 
{ 
	*this = t;
}

ATarget::ATarget(std::string const &type)
{
	this->type = type;
}

ATarget::~ATarget() {}

ATarget			&ATarget::operator=(ATarget const &t)
{
	this->type = t.type;
	return (*this);
}

std::string const 	&ATarget::getType(void) const
{
	return (this->type);
}

void				ATarget::getHitBySpell(ASpell const &s) const
{
	std::cout << this->type << " has been " << s.getEffects() << "!\n";
}
