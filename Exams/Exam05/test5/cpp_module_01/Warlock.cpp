# include "Warlock.hpp"

Warlock::Warlock (std::string const &name, std::string const &title)
{
	this->name = name;
	this->title = title;
	std::cout << this->name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
	std::map<std::string, ASpell *>::iterator b = items.begin();
	std::map<std::string, ASpell *>::iterator e = items.end();
	while (b != e)
	{
		delete b->second;
		++b;
	}
	this->items.clear();
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

void				Warlock::setTitle(std::string const &title)
{
	this->title = title;
}

void				Warlock::introduce() const
{
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!\n";
}

void				Warlock::learnSpell(ASpell *s)
{
	if (s)
		items.insert(std::pair<std::string, ASpell *>(s->getName(), s->clone()));
}

void				Warlock::forgetSpell(std::string const &name)
{
	std::map<std::string, ASpell *>::iterator it = items.find(name);
	if (it != items.end())
		delete it->second;
	items.erase(name);
}

void				Warlock::launchSpell(std::string const &name, ATarget const &t)
{
	ASpell	*spell = items[name];
	if (spell)
		spell->launch(t);
}



