/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:34:07 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/24 18:03:33 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/DiamondTrap.hpp"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;

	DiamondTrap	leo("Leo");
	
	std::cout << std::endl;
	std::cout << Yellow " ==================== " Reset << std::endl;
	std::cout << Yellow "     Begin Round      " Reset << std::endl;
	std::cout << Yellow " ==================== " Reset << std::endl;
	std::cout << std::endl;
	
	leo.whoAmI();
	leo.attack("Test");
	leo.beRepaired(20);
	leo.guardGate();
	leo.highFivesGuys();
	leo.takeDamage(30);

	std::cout << std::endl;
	std::cout << Yellow " ==================== " Reset << std::endl;
	std::cout << Yellow "     End of Round     " Reset << std::endl;
	std::cout << Yellow " ==================== " Reset << std::endl;
	std::cout << std::endl;
}