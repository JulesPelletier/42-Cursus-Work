/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:18:34 by julpelle          #+#    #+#             */
/*   Updated: 2022/06/28 20:55:38 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include <map>

# include "ASpell.hpp"

class ASpell;

class Warlock
{
	private:
		std::string		name;
		std::string		title;
		std::map<std::string, ASpell *> arr;

		Warlock(Warlock const &w);
		Warlock(void);
		Warlock &operator=(Warlock const &w);
	public:
		Warlock(std::string const &name, std::string const &title);
		~Warlock(void);
		
		std::string		const &getName(void) const;
		std::string 	const &getTitle(void) const;
		
		void			setTitle(std::string const &title);
		void			introduce(void) const;

		void			learnSpell(ASpell *s);
		void			forgetSpell(std::string name);
		void			launchSpell(std::string name, ATarget const &t);
};