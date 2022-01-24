/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:34:07 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/24 16:12:39 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;

	ClapTrap	jules("Jules");
	ScavTrap	anthony("Anthony");
	
	std::cout << std::endl;
	std::cout << Yellow " ==================== " Reset << std::endl;
	std::cout << Yellow "     Begin Round      " Reset << std::endl;
	std::cout << Yellow " ==================== " Reset << std::endl;
	std::cout << std::endl;

	jules.attack("Anthony");
	anthony.attack("Jules");
	jules.beRepaired(20);
	jules.takeDamage(20);
	anthony.beRepaired(20);
	
	std::cout << std::endl;
	std::cout << Yellow "Creating a copy of ScavTrap Anthony" Reset << std::endl;
	ScavTrap	test2("Test");
	std::cout << std::endl;

	std::cout << std::endl;
	test2 = anthony;
	test2.beRepaired(20);
	test2.guardGate();
	std::cout << std::endl;


	std::cout << Yellow "Checking the copy's HP " Reset << std::endl;
	test2.beRepaired(20);
	anthony.takeDamage(30);
	anthony.guardGate();

	std::cout << std::endl;
	std::cout << Yellow " ==================== " Reset << std::endl;
	std::cout << Yellow "     End of Round     " Reset << std::endl;
	std::cout << Yellow " ==================== " Reset << std::endl;
	std::cout << std::endl;

}