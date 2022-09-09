# include "ASpell.hpp"

ASpell::ASpell()
{

}

ASpell::ASpell(ASpell const &s)
{
	*this = s;
}

ASpell::ASpell(std::string const &name, std::string const &effects)
{
	this->name = name;
	this->effects = effects;
}

ASpell::~ASpell()
{

}

ASpell &ASpell::operator=(ASpell const &s)
{
	this->name = s.name;
	this->effects = s.effects;
	return (*this);
}


std::string const	&ASpell::getName() const
{
	return (this->name);
}

std::string const	&ASpell::getEffects() const
{
	return (this->effects);
}

void				ASpell::launch(ATarget const &t)
{
	t.getHitBySpell((*this));
}

