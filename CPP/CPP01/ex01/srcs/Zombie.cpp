/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 22:08:31 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/17 23:17:35 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie()
{
	std::cout << MAGENTA"Constructor called !"RESET << std::endl;
}

Zombie::~Zombie()
{
	std::cout << CYAN"Setting name to " << this->_name << std::endl;
	std::cout << MAGENTA"Destructor for "RESET << this->_name << MAGENTA" called !"RESET << std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->_name = name;
}