# include "SpellBook.hpp"

SpellBook::SpellBook()
{
	
}

SpellBook::~SpellBook()
{
	std::map<std::string, ASpell *>::iterator b = book.begin();
	std::map<std::string, ASpell *>::iterator e = book.end();
	while (b != e)
	{
		delete b->second;
		++b;
	}
	this->book.clear();
}

void	SpellBook::learnSpell(ASpell *s)
{
	if (s)
		book.insert(std::pair<std::string, ASpell *>(s->getName(), s->clone()));
}

void	SpellBook::forgetSpell(std::string const &name)
{
	std::map<std::string, ASpell *>::iterator it = this->book.find(name);
	if (it != book.end())
		delete it->second;
	book.erase(name);
}

ASpell	*SpellBook::createSpell(std::string const &name)
{
	std::map<std::string, ASpell *>::iterator it = this->book.find(name);
	if (it != book.end())
		return book[name];
	return NULL;
}
