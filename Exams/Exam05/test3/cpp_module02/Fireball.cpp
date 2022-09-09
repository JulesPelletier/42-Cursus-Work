/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:41:57 by julpelle          #+#    #+#             */
/*   Updated: 2022/07/07 14:40:14 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fireball.hpp"

Fireball::Fireball(void) : ASpell("Fireball", "burnt to a crisp")
{

}

Fireball::~Fireball(void)
{

}

ASpell	*Fireball::clone(void) const
{
	return (new Fireball());
}
