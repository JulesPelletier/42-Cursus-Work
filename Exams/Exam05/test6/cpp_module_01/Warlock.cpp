# include "Warlock.hpp"
# include "ASpell.hpp"

Warlock::Warlock(std::string const &name, std::string const &title)
{
	this->name = name;
	this->title = title;
	std::cout << this->name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
	std::map<std::string, ASpell *>::iterator b = spells.begin();
	std::map<std::string, ASpell *>::iterator e = spells.end();
	while (b != e)
	{
		delete b->second;
		++b;
	}
	this->spells.clear();
	std::cout << this->name << ": My job here is done!\n";
}

std::string	const	&Warlock::getName() const
{
	return (this->name);
}

std::string const	&Warlock::getTitle() const
{
	return (this->title);
}

void				Warlock::introduce() const
{
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!\n";
}

void				Warlock::setTitle(std::string const &title)
{
	this->title = title;
}

void				Warlock::learnSpell(ASpell *s)
{
	if (s)
		spells.insert(std::pair<std::string, ASpell *>(s->getName(), s->clone()));
}

void				Warlock::forgetSpell(std::string const &name) 
{
	std::map<std::string, ASpell *>::iterator it = this->spells.find(name);
	if (it != spells.end())
		delete it->second;
	spells.erase(name);
}

void				Warlock::launchSpell(std::string const &name, ATarget const &t)
{
	ASpell	*test = spells[name];
	if (test)
		test->launch(t);
}


