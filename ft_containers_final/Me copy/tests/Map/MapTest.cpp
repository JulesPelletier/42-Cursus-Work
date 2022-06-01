/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapTest.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:14:13 by julpelle          #+#    #+#             */
/*   Updated: 2022/03/31 16:18:04 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MapTest.hpp"
# include <map>

void	test_m::test_map(void)
{
	ft::Pair<std::string, int>		si_init[] = {
		ft::make_pair("Belier", 1),
		ft::make_pair("Taureau", 2),
		ft::make_pair("Gémeaux", 3),
		ft::make_pair("Cancer", 4),
		ft::make_pair("Lion", 5),
		ft::make_pair("Vierge", 6),
		ft::make_pair("Balance", 7),
		ft::make_pair("Scorpion", 8),
		ft::make_pair("Sagitaire", 9),
		ft::make_pair("Capricorne", 10),
		ft::make_pair("Verseau", 11),
		ft::make_pair("Poissons", 12),
	};
	ft::Pair<int, std::string>		is_init[] = {
		ft::make_pair(1, "Belier"),
		ft::make_pair(2, "Taureau"),
		ft::make_pair(3, "Gémeaux"),
		ft::make_pair(4, "Cancer"),
		ft::make_pair(5, "Lion"),
		ft::make_pair(6, "Vierge"),
		ft::make_pair(7, "Balance"),
		ft::make_pair(8, "Scorpion"),
		ft::make_pair(9, "Sagitaire"),
		ft::make_pair(10, "Capricorne"),
		ft::make_pair(11, "Verseau"),
		ft::make_pair(12, "Poissons"),
	};

	ft::Pair<int, std::string>		test_double[] = {
		ft::make_pair(1, "Belier"),
		ft::make_pair(2, "Taureau"),
		ft::make_pair(4, "Cancer"),
		ft::make_pair(5, "Lion"),
		ft::make_pair(6, "Vierge"),
		ft::make_pair(2, "Taureau"),
		ft::make_pair(2, "Taureau"),
		ft::make_pair(7, "Balance"),
		ft::make_pair(8, "Scorpion"),
		ft::make_pair(9, "Sagitaire"),
		ft::make_pair(10, "Capricorne"),
		ft::make_pair(1, "Belier"),
		ft::make_pair(11, "Verseau"),
		ft::make_pair(12, "Poissons"),
	};



	print_header(" MAP", "header");		  
	print_header("CONSTRUCTORS", "title");
	print_header("Int values", "subtitle");
	test_capacity<ft::Map<int, std::string> >(is_init, 12);
	print_header("String values", "subtitle");
	test_capacity<ft::Map<std::string, int> >(si_init, 12);
	
	print_header("ACCESS", "title");
	print_header("Int values", "subtitle");
	test_access<ft::Map<int, std::string> >(is_init, 12);
	print_header("String values", "subtitle");
	test_access<ft::Map<std::string, int> >(si_init, 12);

	print_header("MODIFIERS", "title");
	print_header("Int values", "subtitle");
	test_modifiers<ft::Map<int, std::string> >(is_init, 12);
	print_header("String values", "subtitle");
	test_modifiers<ft::Map<std::string, int> >(si_init, 12);

	print_header("OBSERVERS", "title");
	print_header("Key Compare", "subtitle");
	test_observers<ft::Map<int, std::string> >(is_init, 12);
	print_header("Value Compare", "subtitle");
	test_observers<ft::Map<std::string, int> >(si_init, 12);

	print_header("OPERATIONS", "title");
	print_header("Int Values", "subtitle");
	test_operations<ft::Map<int, std::string> >(is_init, 12);
	print_header("String Values", "subtitle");
	test_operations<ft::Map<std::string, int> >(si_init, 12);
	print_header("Double Values", "subtitle");
	test_operations<ft::Map<int, std::string> >(test_double, 14);
	


	

	//t_map<ft::Map<std::string, int> >(si_init, 12, "String | Init");

}