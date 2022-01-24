/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:34:07 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/24 16:44:58 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;

	ClapTrap	jules("Jules");
	ScavTrap	anthony("Anthony");
	FragTrap	matteo("Matteo");
	
	std::cout << std::endl;
	std::cout << Yellow " ==================== " Reset << std::endl;
	std::cout << Yellow "     Begin Round      " Reset << std::endl;
	std::cout << Yellow " ==================== " Reset << std::endl;
	std::cout << std::endl;

	jules.attack("Matteo");
	jules.beRepaired(20);
	matteo.highFivesGuys();
	matteo.beRepaired(30);
	matteo.attack("Jules");
	
	std::cout << std::endl;
	std::cout << Yellow " Testing with copy " Reset << std::endl;
	std::cout << std::endl;

	FragTrap	copy(matteo);

	copy.beRepaired(20);
	copy.takeDamage(30);

	std::cout << std::endl;
	std::cout << Yellow " ==================== " Reset << std::endl;
	std::cout << Yellow "     End of Round     " Reset << std::endl;
	std::cout << Yellow " ==================== " Reset << std::endl;
	std::cout << std::endl;

}