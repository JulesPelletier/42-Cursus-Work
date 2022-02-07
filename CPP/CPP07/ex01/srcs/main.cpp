/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 23:30:10 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/07 23:50:07 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"
#include <math.h>

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	int		tab1[4] = {0, 1, 2, 3};
	int		tab2[4] = {0, -1, -2, -3};
	
	std::cout << std::endl;
	std::cout << Yellow " ==== Positive squares ==== " Reset << std::endl;
	iter(tab1, 4, ::function1);
	std::cout << std::endl;
	std::cout << Yellow " ==== Negative squares ==== " Reset << std::endl;
	iter(tab2, 4, ::function1);
	std::cout << std::endl;


	char	char1[4] = {'a', 'b', 'c', 'd'};
	char	char2[4] = {'a', 'c', 'b', 'd'};
	
	std::cout << std::endl;
	std::cout << Yellow " ==== a - b - c - d ==== " Reset << std::endl;
	iter(char1, 4, ::function2);
	std::cout << std::endl;

	std::cout << Yellow " ==== a - c - b - d ==== " Reset << std::endl;
	iter(char2, 4, ::function2);
	std::cout << std::endl;

}