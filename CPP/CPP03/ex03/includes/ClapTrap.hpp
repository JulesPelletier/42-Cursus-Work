/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:03:52 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/24 17:41:12 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>
# include "Colors.hpp"

class ClapTrap
{

	public:

		ClapTrap(std::string str);
		ClapTrap( ClapTrap const & src );
		ClapTrap(void);
		~ClapTrap();

		ClapTrap &		operator=( ClapTrap const & rhs );

		void 			attack(const std::string& target);
		void 			takeDamage(unsigned int amount);
		void 			beRepaired(unsigned int amount);

	protected:
		
		std::string		_name;
		int				_hp;
		int				_ep;
		int				_attack;

};

#endif /* ******************************************************** CLAPTRAP_H */