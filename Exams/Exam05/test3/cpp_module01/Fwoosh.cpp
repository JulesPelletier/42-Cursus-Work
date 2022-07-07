/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:41:57 by julpelle          #+#    #+#             */
/*   Updated: 2022/06/28 20:43:23 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fwoosh.hpp"

Fwoosh::Fwoosh(void) : ASpell("Fwoosh", "fwooshed")
{

}

Fwoosh::~Fwoosh(void)
{

}

ASpell	*Fwoosh::clone(void) const
{
	return (new Fwoosh());
}
