/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 22:59:57 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/17 23:09:19 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie	*zombieHorde(int n, std::string name)
{
	Zombie	*l_zombie;
	int		i;

	l_zombie = new Zombie[n];
	i = 0;
	while (i < n)
	{
		l_zombie[i].set_name(name);
		i++;
	}
	return (l_zombie);
}