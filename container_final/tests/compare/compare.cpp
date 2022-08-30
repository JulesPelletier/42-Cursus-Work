/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:17:34 by julpelle          #+#    #+#             */
/*   Updated: 2022/08/09 15:45:17 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../All.hpp"

void	test_comp::test_compare(void)
{

	int					int_init[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::string			string_init[] = { "A", "B", "C", "D", "E", "F", "G",
										  "H", "I" };
										  
	print_header("vector", "header");
	test_constructor<ft::vector<int>, std::vector<int>, int>(int_init, 9, 0, 9);
}