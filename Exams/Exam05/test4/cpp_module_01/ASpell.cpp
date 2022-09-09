# include "ASpell.hpp"

ASpell::ASpell()
{

}

ASpell::ASpell(ASpell const &s) 
{ 
	*this = s; 
}

ASpell::~ASpell() {}

ASpell::ASpell(std::string const &name, std::string const &effects)
{
	this->name = name;
	this->effects = effects;
}

ASpell		&ASpell::operator=(ASpell const &s)
{
	this->name = s.name;
	this->effects = s.effects;
	return (*this);
}


std::string const	&ASpell::getName(void) const
{
	return (this->name);
}

std::string const	&ASpell::getEffects(void) const
{
	return (this->effects);
}

void				ASpell::launch(ATarget const &t) const
{
	t.getHitBySpell((*this));
}
