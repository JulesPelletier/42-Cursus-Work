/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 22:12:07 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/17 23:14:26 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int	main(int ac, char **av)
{
	Zombie	*l_zombie;
	int		n;

	(void)av;
	(void)ac;
	std::cout << "Combien de zombies ? :> ";
	std::cin >> n;
	l_zombie = zombieHorde(n, "Charles");
	delete [] l_zombie;

	return (0);
}