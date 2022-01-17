/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 22:08:31 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/17 22:46:32 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << " < " <<  this->_name << " > " << "\tBraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name) : _name(name)
{
	announce();
}

Zombie::~Zombie()
{
	//std::cout << " < " << Zombie::_name << " > "  << "BraiiiiiiinnnzzzZ..." << std::endl;
	std::cout << "Destructor for " << this->_name << " called !" << std::endl;
}

std::string	Zombie::get_name()
{
	return (this->_name);
}