/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:34:07 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/24 15:09:26 by julpelle         ###   ########.fr       */
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

	std::cout << Purple "> Jules attack Anthony " Reset << std::endl;
	jules.attack("Anthony");
	std::cout << Purple "> Bob takes 2 damage  " Reset << std::endl;
	bob.takeDamage(2);
	std::cout << Purple "> Bob gets 2 hp back  " Reset << std::endl;
	bob.beRepaired(2);
	std::cout << Purple "> Jules takes 4 damage  " Reset << std::endl;
	jules.takeDamage(4);
	std::cout << Purple "> Jules gets 4 hp back " Reset << std::endl;
	jules.beRepaired(4);
	std::cout << Purple "> Jules gets 10 hp back " Reset << std::endl;
	jules.beRepaired(10);

	std::cout << std::endl;
	std::cout << Yellow " ==================== " Reset << std::endl;
	std::cout << Yellow "     End of Round     " Reset << std::endl;
	std::cout << Yellow " ==================== " Reset << std::endl;
	std::cout << std::endl;
}