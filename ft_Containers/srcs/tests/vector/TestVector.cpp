/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestVector.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:25:31 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/09 15:23:28 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/AllContainers.hpp"
#include "../../../includes/Vector/IterVector.hpp"
#include "../../../includes/Vector/RevIterVector.hpp"
#include "../../../includes/Vector/Vector.hpp"
#include "TestVector.hpp"

void	test_vector_constructor()
{
	std::cout << std::endl;
	std::cout << Blue " ======================================= " Reset << std::endl;
	std::cout << Blue " === Testing Constructors for Vector === " Reset << std::endl;
	std::cout << Blue " ======================================= " Reset << std::endl;
	std::cout << std::endl;
	
	std::vector<int>	vector_default;
	ft::Vector<int>		my_vector_default;
	std::vector<int>	vector_fill(10, 5);
	ft::Vector<int>		my_vector_fill(10, 5);
	std::vector<int>	vector_range(10, 5);
	ft::Vector<int>		my_vector_range(10, 5);
	std::vector<int>	vector_copy(vector_fill);
	ft::Vector<int>		my_vector_copy(my_vector_fill);
	std::vector<int> 	new_vector;
	ft::Vector<int> 	my_new_vector;

	new_vector = vector_copy;
	my_new_vector = my_vector_copy;
}

void	test_vector_iterators()
{
	std::cout << std::endl;
	std::cout << Blue " ==================================== " Reset << std::endl;
	std::cout << Blue " === Testing Iterators for Vector === " Reset << std::endl;
	std::cout << Blue " ==================================== " Reset << std::endl;
	std::cout << std::endl;
	
	std::vector<int>	test_iterators1(10, 0);
	ft::Vector<int> 	my_test_iterators1(10, 0);
	std::vector<int> 	test_iterators2(100, 1);
	ft::Vector<int> 	my_test_iterators2(100, 1);

	ft::IterVector<int> it1;
	ft::IterVector<int> it2;
	
	it1 = my_test_iterators1.begin();
	it2 = my_test_iterators2.begin();
	
	std::cout << Purple " --------- Checking begin --------- " Reset << std::endl;
	std::cout << Reset "Original : \t" Cyan << *test_iterators1.begin() << Reset " \t\t| My Vector : " Green << *it1 << std::endl;
	std::cout << Reset "Original : \t" Cyan << *test_iterators2.begin() << Reset " \t\t| My Vector : " Green << *it2 << std::endl;
}

void	test_vector_overload()
{
	
}

void	test_vector_capacity()
{
	std::cout << std::endl;
	std::cout << Blue " ============================================= " Reset << std::endl;
	std::cout << Blue " === Testing Capacity Functions for Vector === " Reset << std::endl;
	std::cout << Blue " ============================================= " Reset << std::endl;
	std::cout << std::endl;

	std::vector<int>	original1(5,10);
	std::vector<int>	original2(2000, 0);
	ft::Vector<int>		my_original1(5, 10);
	ft::Vector<int>		my_original2(2000,0);
	std::vector<int>	empty;
	ft::Vector<int>		my_empty;

	std::cout << Purple " --------- Checking size --------- " Reset << std::endl;
	std::cout << Reset "Original : \t" Cyan << original1.size() << Reset " \t\t| My Vector : " Green<< my_original1.size() << std::endl;
	std::cout << Reset "Original : \t" Cyan << original2.size() << Reset " \t\t| My Vector : " Green<< my_original2.size() << std::endl;
	std::cout << Purple " --------- Checking max_size --------- " Reset << std::endl;
	std::cout << Reset "Original : \t" Cyan << original1.max_size() << Reset " \t\t| My Vector : " Green<< my_original1.max_size() << std::endl;
	std::cout << Reset "Original : \t" Cyan << original2.max_size() << Reset " \t\t| My Vector : " Green<< my_original2.max_size() << std::endl;
	std::cout << Purple " --------- Checking resize --------- " Reset << std::endl;
	//std::cout << Reset "Original : \t" Cyan << original1.resize() << Reset " \t\t| My Vector : " Green<< my_original1.resize() << std::endl;
	//std::cout << Reset "Original : \t" Cyan << original2.resize() << Reset " \t\t| My Vector : " Green<< my_original2.resize() << std::endl;
	std::cout << Purple " --------- Checking capacity --------- " Reset << std::endl;
	std::cout << Reset "Original : \t" Cyan << original1.capacity() << Reset " \t\t| My Vector : " Green<< my_original1.capacity() << std::endl;
	std::cout << Reset "Original : \t" Cyan << original2.capacity() << Reset " \t\t| My Vector : " Green<< my_original2.capacity() << std::endl;
	std::cout << Purple " --------- Checking empty --------- " Reset << std::endl;
	std::cout << Reset "Original : \t" Cyan << empty.empty() << Reset " \t\t| My Vector : " Green<< empty.empty() << std::endl;
	std::cout << Reset "Original : \t" Cyan << original2.empty() << Reset " \t\t| My Vector : " Green<< my_original2.empty() << std::endl;
	std::cout << Purple " --------- Checking reserve --------- " Reset << std::endl;
	//std::cout << Reset "Original : \t" Cyan << empty.reserve() << Reset " \t\t| My Vector : " Green<< empty.reserve() << std::endl;
	//std::cout << Reset "Original : \t" Cyan << original1.reserve() << Reset " \t\t| My Vector : " Green<< my_original1.reserve() << std::endl;
	//std::cout << Reset "Original : \t" Cyan << original2.reserve() << Reset " \t\t| My Vector : " Green<< my_original2.reserve() << std::endl;
}

void	test_vector_element_access()
{
	
}

void	test_vector_modifiers()
{
	
}

void	test_vector_allocator()
{
	
}

void	test_vector_all()
{
	test_vector_constructor();
	test_vector_iterators();
	test_vector_capacity();
}

/* ************************************************************************** */