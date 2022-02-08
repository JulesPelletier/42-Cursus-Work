/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:59:04 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/08 13:05:04 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Easyfind.hpp"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;

	std::list<int> 					list;
	std::list<int>::iterator 		it;
	std::list<int>::const_iterator	i;

	it = list.begin();
	list.insert(it, 4);
	list.insert(it, 12);
	list.insert(it, -3);

	i = easyfind(list, -2);
	if (i != list.end())
		std::cout << "Item " << *i << " found at index : " << *it << std::endl;
	else
		std::cout << "Item " << *i <<  " not in list" << std::endl;
	i = easyfind(list, 12);
	if (i != list.end())
		std::cout << "Item " << *i << " found at index : " << *it << std::endl;
	else
		std::cout << "Item " << *i << " not in list" << std::endl;

	std::vector<int> 					vector;
	std::vector<int>::iterator 			jt;
	std::vector<int>::const_iterator	j;


	jt = vector.begin();
	vector.push_back(4);
	vector.push_back(-4);
	vector.push_back(3);
	vector.push_back(12);

	j = easyfind(vector, -2);
	if (j != vector.end())
		std::cout << "Item " << *j << " found" << std::endl;
	else
		std::cout << "Item not in list" << std::endl;
	j = easyfind(vector, -4);
	if (j != vector.end())
		std::cout << "Item " << *j << " found" << std::endl;
	else
		std::cout << "Item not in list" << std::endl;
	j = easyfind(vector, 4);
	if (j != vector.end())
		std::cout << "Item " << *j << " found " << std::endl;
	else
		std::cout << "Item not in list" << std::endl;
	return (0);
}