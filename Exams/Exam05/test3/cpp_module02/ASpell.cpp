/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:10:06 by julpelle          #+#    #+#             */
/*   Updated: 2022/06/28 20:38:22 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ASpell.hpp"

ASpell::ASpell(void)
{

}

ASpell::ASpell(std::string const &name, std::string const &effects)
{
	this->name = name;
	this->effects = effects;
}

ASpell::ASpell(ASpell const &s)
{
	this->name = s.name;
	this->effects = s.effects;
}

ASpell::~ASpell(void)
{

}

ASpell			  &ASpell::operator=(ASpell const &s)
{
	this->name = s.name;
	this->effects = s.effects;
	return (*this);
}


std::string	const &ASpell::getName(void) const
{
	return (this->name);
}

std::string const &ASpell::getEffects(void) const
{
	return (this->effects);
}

void				ASpell::launch(ATarget const &t) const
{
	t.getHitBySpell(*(this));
}
