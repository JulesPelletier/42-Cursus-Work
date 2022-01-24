/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:34:07 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/24 15:06:24 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;

	ClapTrap	jules("Jules");
	ClapTrap	antho("Anthony");
	ClapTrap	bob(antho);
	
	std::cout << std::endl;
	std::cout << Yellow " ==================== " Reset << std::endl;
	std::cout << Yellow "     Begin Round      " Reset << std::endl;
	std::cout << Yellow " ==================== " Reset << std::endl;
	std::cout << std::endl;

	jules.attack("Anthony");
	bob.takeDamage(2);
	bob.beRepaired(2);
	jules.takeDamage(4);
	jules.beRepaired(4);
	jules.beRepaired(10);

	std::cout << std::endl;
	std::cout << Yellow " ==================== " Reset << std::endl;
	std::cout << Yellow "     End of Round     " Reset << std::endl;
	std::cout << Yellow " ==================== " Reset << std::endl;
	std::cout << std::endl;
}