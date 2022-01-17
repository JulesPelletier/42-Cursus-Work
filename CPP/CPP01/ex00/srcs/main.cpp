/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 22:12:07 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/17 22:54:35 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int	main(int ac, char **av)
{
	(void)av;
	(void)ac;
	Zombie	zombie("Arthur");
	Zombie	zombie2("Jules");
	Zombie	zombie3("Marine");

	Zombie	*zombie4;
	Zombie	*zombie5;
	Zombie	*zombie6;
	zombie4 = newZombie("Curtis");
	zombie5 = newZombie("Mao");
	zombie6 = newZombie("David");
	delete(zombie4);
	delete(zombie5);
	delete(zombie6);

	randomChump("Marty");
	return (0);
}