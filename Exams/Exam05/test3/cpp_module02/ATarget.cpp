/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:15:04 by julpelle          #+#    #+#             */
/*   Updated: 2022/06/28 20:37:09 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ATarget.hpp"

ATarget::ATarget(void)
{
	
}

ATarget::ATarget(std::string const &type)
{
	this->type = type;
}

ATarget::~ATarget(void)
{
	
}

ATarget		&ATarget::operator=(ATarget const &t)
{
	this->type = t.type;
	return (*this);
}


std::string const	&ATarget::getType(void) const
{
	return (this->type);
}

void	ATarget::getHitBySpell(ASpell const &s) const
{
	std::cout << this->type << " has been " << s.getEffects() << "!\n";
}