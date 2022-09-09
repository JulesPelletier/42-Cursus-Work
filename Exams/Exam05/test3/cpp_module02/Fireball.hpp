/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:56:52 by julpelle          #+#    #+#             */
/*   Updated: 2022/06/28 20:41:48 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>

# include "ATarget.hpp"

class ATarget;

class Fireball: public ASpell
{
	public:
		Fireball(void);
		~Fireball(void);

		virtual ASpell	*clone(void) const;
};