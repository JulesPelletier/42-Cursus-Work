/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:11:57 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/07 21:33:57 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Colors.hpp"
#include "../includes/Convert.hpp"

int main(int ac, char **av)
{
	int		i;

	i = 1;
	if (ac <= 1)
	{
		std::cout << "Not enough arguments : needed at least 1" << std::endl;
		return (0);
	}
	while (i < ac)
	{
		Convert conv(av[i]);

		std::cout << conv << std::endl;
		conv.convChar();
		conv.convInt();
		conv.convFloat();
		conv.convDouble();
		std::cout << std::endl;
		i++;
	}
}