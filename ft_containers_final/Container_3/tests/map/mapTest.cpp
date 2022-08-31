/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapTest.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:14:13 by julpelle          #+#    #+#             */
/*   Updated: 2022/08/31 11:48:07 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "mapTest.hpp"
# include <map>

void	test_m::test_map(void)
{
	NAMESPACE::pair<std::string, int>		si_init[] = {
		NAMESPACE::make_pair("un", 1),
		NAMESPACE::make_pair("deux", 2),
		NAMESPACE::make_pair("trois", 3),
		NAMESPACE::make_pair("quatre", 4),
		NAMESPACE::make_pair("cinq", 5),
		NAMESPACE::make_pair("six", 6),
		NAMESPACE::make_pair("sept", 7),
		NAMESPACE::make_pair("huit", 8),
		NAMESPACE::make_pair("neuf", 9),
		NAMESPACE::make_pair("dix", 10),
		NAMESPACE::make_pair("onze", 11),
		NAMESPACE::make_pair("douze", 12),
	};
	NAMESPACE::pair<int, std::string>		is_init[] = {
		NAMESPACE::make_pair(1, "un"),
		NAMESPACE::make_pair(2, "deux"),
		NAMESPACE::make_pair(3, "trois"),
		NAMESPACE::make_pair(4, "quatre"),
		NAMESPACE::make_pair(5, "cinq"),
		NAMESPACE::make_pair(6, "six"),
		NAMESPACE::make_pair(7, "sept"),
		NAMESPACE::make_pair(8, "huit"),
		NAMESPACE::make_pair(9, "neuf"),
		NAMESPACE::make_pair(10, "dix"),
		NAMESPACE::make_pair(11, "onze"),
		NAMESPACE::make_pair(12, "douze"),
	};

	NAMESPACE::pair<int, std::string>		test_double[] = {
		NAMESPACE::make_pair(1, "un"),
		NAMESPACE::make_pair(2, "deux"),
		NAMESPACE::make_pair(4, "quatre"),
		NAMESPACE::make_pair(5, "cinq"),
		NAMESPACE::make_pair(6, "six"),
		NAMESPACE::make_pair(2, "deux"),
		NAMESPACE::make_pair(2, "deux"),
		NAMESPACE::make_pair(7, "sept"),
		NAMESPACE::make_pair(8, "huit"),
		NAMESPACE::make_pair(9, "neuf"),
		NAMESPACE::make_pair(10, "dix"),
		NAMESPACE::make_pair(1, "un"),
		NAMESPACE::make_pair(11, "onze"),
		NAMESPACE::make_pair(12, "douze"),
	};



	print_header(" map", "header");		  
	print_header("CONSTRUCTORS", "title");
	print_header("Int values", "subtitle");
	test_capacity<NAMESPACE::map<int, std::string> >(is_init, 12);
	print_header("String values", "subtitle");
	test_capacity<NAMESPACE::map<std::string, int> >(si_init, 12);
	
	print_header("ACCESS", "title");
	print_header("Int values", "subtitle");
	test_access<NAMESPACE::map<int, std::string> >(is_init, 12);
	print_header("String values", "subtitle");
	test_access<NAMESPACE::map<std::string, int> >(si_init, 12);

	print_header("MODIFIERS", "title");
	print_header("Int values", "subtitle");
	test_modifiers<NAMESPACE::map<int, std::string> >(is_init, 12);
	print_header("String values", "subtitle");
	test_modifiers<NAMESPACE::map<std::string, int> >(si_init, 12);

	print_header("OBSERVERS", "title");
	print_header("Key Compare", "subtitle");
	test_observers<NAMESPACE::map<int, std::string> >(is_init, 12);
	print_header("Value Compare", "subtitle");
	test_observers<NAMESPACE::map<std::string, int> >(si_init, 12);

	print_header("OPERATIONS", "title");
	print_header("Int Values", "subtitle");
	test_operations<NAMESPACE::map<int, std::string> >(is_init, 12);
	print_header("String Values", "subtitle");
	test_operations<NAMESPACE::map<std::string, int> >(si_init, 12);
	print_header("Double Values", "subtitle");
	test_operations<NAMESPACE::map<int, std::string> >(test_double, 14);
	
}