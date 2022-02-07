/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:03:45 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/24 17:40:26 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{

	public:

		ScavTrap(std::string name);
		ScavTrap( ScavTrap const & src );
		ScavTrap(void);
		~ScavTrap();

		ScavTrap 		&operator=( ScavTrap const & rhs );

		void			guardGate(void);
		void 			attack(const std::string& target);
	
	protected:
};

#endif /* ******************************************************** SCAVTRAP_H */