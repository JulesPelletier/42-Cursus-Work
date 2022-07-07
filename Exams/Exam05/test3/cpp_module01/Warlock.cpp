/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:31:53 by julpelle          #+#    #+#             */
/*   Updated: 2022/07/07 14:00:20 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title)
{
	this->name = name;
	this->title = title;
	std::cout << this->name << ": This looks like another boring day.\n";
}

Warlock::~Warlock(void)
{
	std::cout << this->name << ": My job here is done.\n";
	std::map<std::string, ASpell *>::iterator it_b = this->arr.begin();
	std::map<std::string, ASpell *>::iterator it_e = this->arr.end();
	while (it_b != it_e)
	{
		delete it_b->second;
		++it_b;
	}
	this->arr.clear();
}

std::string		const &Warlock::getName(void) const
{
	return (this->name);
}

std::string 	const &Warlock::getTitle(void) const
{
	return (this->title);
}

void			Warlock::introduce(void) const
{
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!\n";
}

void			Warlock::setTitle(std::string const &title)
{
	this->title = title;
}

void			Warlock::learnSpell(ASpell *s)
{
	if (s)
		arr.insert(std::pair<std::string, ASpell *>(s->getName(), s->clone()));
}

void			Warlock::forgetSpell(std::string name)
{
	std::map<std::string, ASpell *>::iterator it = arr.find(name);
	if (it != arr.end())
		delete it->second;
	arr.erase(name);
}

void			Warlock::launchSpell(std::string name, ATarget const &t)
{
	ASpell *spell = arr[name];
	if (spell)
		spell->launch(t);
}
		