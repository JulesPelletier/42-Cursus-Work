/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackTest.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:43:03 by julpelle          #+#    #+#             */
/*   Updated: 2022/03/25 19:22:19 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "StackTest.hpp"

void	test_s::test_stack(void)
{
	int					int_init[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::string			string_init[] = { "A", "B", "C", "D", "E", "F", "G",
										  "H", "I" };
	
	print_header(" STACK", "header");		  
	print_header("CAPACITY", "title");
	print_header("Int values", "subtitle");
	testing_stack<ft::Stack<int>, int>(int_init, "");
}

/* ************************************************************************** */