/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:50:19 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/26 01:05:40 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{

	public:

		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap( DiamondTrap const & src );
		virtual ~DiamondTrap(void);

		DiamondTrap &		operator=( DiamondTrap const & rhs );

		void 				whoAmI();
	
	protected:

	private:
		std::string			_name;
};

#endif /* ***************************************************** DIAMONDTRAP_H */