# include "SpellBook.hpp"

SpellBook::SpellBook()
{
	
}

SpellBook::~SpellBook()
{
	std::map<std::string, ASpell *>::iterator it = spellbook.begin();
	std::map<std::string, ASpell *>::iterator jt = spellbook.end();
	while (it != jt)
	{
		delete it->second;
		++it;
	}
	this->spellbook.clear();
}

void	SpellBook::learnSpell(ASpell *s)
{
	if (s)
		this->spellbook.insert(std::pair<std::string, ASpell *>(s->getName(), s->clone()));
}

void	SpellBook::forgetSpell(std::string const &name)
{
	std::map<std::string, ASpell *>::iterator it = this->spellbook.find(name);
	if (it != spellbook.end())
		delete it->second;
	spellbook.erase(name);
}

ASpell	*SpellBook::createSpell(std::string const &name)
{
	std::map<std::string, ASpell *>::iterator it = spellbook.find(name);
	if (it != spellbook.end())
		return (spellbook[name]);
	return (NULL);
}
