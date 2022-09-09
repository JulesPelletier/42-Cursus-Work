/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:56:52 by julpelle          #+#    #+#             */
/*   Updated: 2022/07/07 13:58:21 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>

# include "ATarget.hpp"

class ATarget;

class ASpell
{
	private:
		std::string	 	name;
		std::string 	effects;
		
	public:
		ASpell(void);
		ASpell(std::string const &name, std::string const &effects);
		ASpell(ASpell const &s);
		virtual ~ASpell(void);
		ASpell	&operator=(ASpell const &s);

		
		std::string const	&getName(void) const;
		std::string const	&getEffects(void) const;

		void				launch(ATarget const &t) const;

		virtual ASpell		*clone(void) const = 0;
	protected:
};