/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:04:14 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/24 17:04:14 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

	public:

		ScavTrap(std::string name);
		ScavTrap( ScavTrap const & src );
		~ScavTrap();

		ScavTrap 		&operator=( ScavTrap const & rhs );

		void			guardGate(void);
		void 			attack(const std::string& target);
};

#endif /* ******************************************************** SCAVTRAP_H */