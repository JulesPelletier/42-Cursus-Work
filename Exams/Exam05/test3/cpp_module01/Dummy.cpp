/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:41:57 by julpelle          #+#    #+#             */
/*   Updated: 2022/06/28 20:44:47 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dummy.hpp"

Dummy::Dummy(void) : ATarget("Target Practice Dummy")
{

}

Dummy::~Dummy(void)
{

}

ATarget	*Dummy::clone(void) const
{
	return (new Dummy());
}
