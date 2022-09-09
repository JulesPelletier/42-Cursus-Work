# include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title)
{
	this->name = name;
	this->title = title;
	std::cout << this->name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
	std::cout << this->name << ": My job here is done!\n";
	std::map<std::string, ASpell *>::iterator it = this->tab.begin();
	std::map<std::string, ASpell *>::iterator jt = this->tab.end();
	while (it != jt)
	{
		delete it->second;
		it++;
	}
	this->tab.clear();
}

std::string	const 	&Warlock::getName(void) const
{
	return (this->name);
}

std::string const 	&Warlock::getTitle(void) const
{
	return (this->title);
}

void				Warlock::setTitle(std::string const &title)
{
	this->title = title;
}

void				Warlock::introduce(void) const
{
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!\n";
}

void				Warlock::learnSpell(ASpell *s)
{
	if (s)
		this->tab.insert(std::pair<std::string, ASpell *>(s->getName(), s->clone()));
}

void				Warlock::forgetSpell(std::string const &spell)
{
	std::map<std::string, ASpell *>::iterator it = this->tab.find(spell);
	if (it != this->tab.end())
		delete it->second;
	this->tab.erase(spell);
}

void				Warlock::launchSpell(std::string const &spell, ATarget const &t)
{
	ASpell	*s = tab[spell];
	if (s)
		s->launch(t);
}
