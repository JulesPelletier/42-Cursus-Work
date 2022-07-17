# include "Warlock.hpp"

Warlock::Warlock (std::string const &name, std::string const &title)
{
	this->name = name;
	this->title = title;
	std::cout << this->name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
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
	this->book.learnSpell(s);
}

void				Warlock::forgetSpell(std::string const &name)
{
	this->book.forgetSpell(name);
}

void				Warlock::launchSpell(std::string const &name, ATarget const &t)
{
	ATarget const *test = 0;
	if (test == &t)
		return ;
	ASpell *tmp = book.createSpell(name);
	if (tmp)
		tmp->launch(t);
}



