/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:07:28 by julpelle          #+#    #+#             */
/*   Updated: 2022/07/07 13:58:32 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include <iostream>

# include "ASpell.hpp"

class ASpell;

class ATarget
{
	private:
		std::string 	type;

	public:
		ATarget(void);
		ATarget(std::string const &type);
		virtual ~ATarget(void);
		ATarget	&operator=(ATarget const &t);

		
		std::string const	&getType(void) const;
		
		virtual ATarget		*clone(void) const = 0;

		void	getHitBySpell(ASpell const &s) const;
		
	protected:
};