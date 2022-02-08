/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 23:30:10 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/08 00:56:01 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"
#include <math.h>

int	main(int ac, char **av)
{
	Array<int> 	empty;
	Array<int> 	tab(4);
	Array<int> 	dup(tab);
	
	(void)ac;
	(void)av;
	std::cout << Blue" ===== Printing Sizes ===== " Reset << std::endl;
	std::cout << "Size : " << empty.getSize() << std::endl;
	std::cout << "Size : " << tab.getSize() << std::endl;
	std::cout << "Size : " << dup.getSize() << std::endl;

	std::cout << Blue" ===== Printing Original Tab ===== " Reset << std::endl;
	std::cout << "Tab[0] : " << tab.getElem(0) << " | Dup[0] : " << dup.getElem(0) << std::endl;
	std::cout << "Tab[1] : " << tab.getElem(1) << " | Dup[1] : " << dup.getElem(1) << std::endl;
	std::cout << "Tab[2] : " << tab.getElem(2) << " | Dup[2] : " << dup.getElem(2) << std::endl;
	std::cout << "Tab[3] : " << tab.getElem(3) << " | Dup[3] : " << dup.getElem(3) << std::endl;


	tab.addElem(1, 2);
	tab.addElem(2, 4);
	tab.addElem(3, 6);

	std::cout << Blue" ===== Printing Changed Tab ===== " Reset << std::endl;
	std::cout << "Tab[0] : " << tab.getElem(0) << " | Dup[0] : " << dup.getElem(0) << std::endl;
	std::cout << "Tab[1] : " << tab.getElem(1) << " | Dup[1] : " << dup.getElem(1) << std::endl;
	std::cout << "Tab[2] : " << tab.getElem(2) << " | Dup[2] : " << dup.getElem(2) << std::endl;
	std::cout << "Tab[3] : " << tab.getElem(3) << " | Dup[3] : " << dup.getElem(3) << std::endl;

	dup.addElem(0, -3);
	dup.addElem(1, 3);
	dup.addElem(2, -3);
	dup.addElem(3, 3);

	std::cout << Blue" ===== Printing Changed Dup ===== " Reset << std::endl;
	std::cout << "Tab[0] : " << tab.getElem(0) << " | Dup[0] : " << dup.getElem(0) << std::endl;
	std::cout << "Tab[1] : " << tab.getElem(1) << " | Dup[1] : " << dup.getElem(1) << std::endl;
	std::cout << "Tab[2] : " << tab.getElem(2) << " | Dup[2] : " << dup.getElem(2) << std::endl;
	std::cout << "Tab[3] : " << tab.getElem(3) << " | Dup[3] : " << dup.getElem(3) << std::endl;
	return (0);
}