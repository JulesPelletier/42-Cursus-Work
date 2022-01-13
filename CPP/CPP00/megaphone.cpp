/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:26:38 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/13 15:35:22 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <iostream>

int	main(int ac, char **av)
{
	int	i;
	int	j;
	
	if (ac == 1)
		std::cout << "* LOUD UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i = 1;
		while (av[i])
		{
			j = 0;
			while (av[i][j])
			{
				av[i][j] = toupper(av[i][j]);
				j++;
			}
			std::cout << av[i];
			i++;
		}
		std::cout << std::endl;
	}
}