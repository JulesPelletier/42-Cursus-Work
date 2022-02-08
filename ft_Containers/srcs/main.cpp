/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:37:24 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/08 20:25:27 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AllContainers.hpp"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	
	ft::Vector<int>	vector_default;
	ft::Vector<int>	vector_fill(10, 5);
	ft::Vector<int>	vector_range(10, 5);
	ft::Vector<int>	vector_copy(vector_fill);
	ft::Vector<int> new_vector;

	new_vector = vector_copy;
	
	return (0);
}
