/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:08:11 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/08 15:34:54 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

int main(void)
{
	try
	{
		Span	v1(5);
	
		std::cout << Blue "Size : " Reset << v1.getSize() << std::endl;
		std::cout << Blue "Count : " Reset << v1.getCount() << std::endl;
	
		v1.addNumber(1);
		v1.addNumber(2);
		v1.addNumber(3);
		v1.addNumber(4);
	
		std::cout << Blue "Size : " Reset << v1.getSize() << std::endl;
		std::cout << Blue "Count : " Reset << v1.getCount() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		Span	v2(5);
	
		std::cout << Blue "Size : " Reset << v2.getSize() << std::endl;
		std::cout << Blue "Count : " Reset << v2.getCount() << std::endl;
	
		v2.addNumber(1);
		v2.addNumber(2);
		v2.addNumber(3);
		v2.addNumber(4);
		v2.addNumber(5);
		v2.addNumber(6);
	
		std::cout << Blue "Size : " Reset << v2.getSize() << std::endl;
		std::cout << Blue "Count : " Reset << v2.getCount() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		Span	shortspan(10);
		Span	longspan(10);
		int 	i;
		
		std::cout << Blue "Shortspan size : " Reset << shortspan.getSize() << std::endl;
		std::cout << Blue "Shortspan count : " Reset << shortspan.getCount() << std::endl;
		std::cout << Blue "Longspan size : " Reset << longspan.getSize() << std::endl;
		std::cout << Blue "Longspan count : " Reset << longspan.getCount() << std::endl;
		std::cout << std::endl;
		std::cout << Yellow " ==== Generating random ints ...... ==== " Reset << std::endl;
		i = 0;
		while (i < 10)
		{
			shortspan.addNumber(random() % 1000000);
			longspan.addNumber(random() % 1000000);
			i++;
		}
		std::cout << Blue "Shortspan size : " Reset << shortspan.getSize() << std::endl;
		std::cout << Blue "Shortspan count : " Reset << shortspan.getCount() << std::endl;
		std::cout << Blue "Longspan size : " Reset << longspan.getSize() << std::endl;
		std::cout << Blue "Longspan count : " Reset << longspan.getCount() << std::endl;

		std::cout << Yellow " ==== Inital Vectors ==== " Reset << std::endl;
		std::cout << Green " ---- Vector 1 ---- " Reset << std::endl;
		shortspan.showElem();
		std::cout << Green " ---- Vector 2 ---- " Reset << std::endl;
		longspan.showElem();
		std::cout << std::endl;
		std::cout << Yellow " ==== Starting sequence ==== " Reset << std::endl;

		long short1;
		long short2;
		long long1;
		long long2;

		short1 = shortspan.shortestSpan();
		short2 = longspan.shortestSpan();
		long1 = shortspan.longestSpan();
		long2 = longspan.longestSpan();
		
		std::cout << Green " --- Vector 1 --- " Reset << std::endl;
		std::cout << Blue"Shortest span : "Reset << short1 << std::endl;
		std::cout << Blue"Longest span : " Reset << long1 << std::endl;
		std::cout << Green " --- Vector 1 --- " Reset << std::endl;
		std::cout << Blue"Shortest span : " Reset << short2 << std::endl;
		std::cout << Blue"Longest span : " Reset << long2 << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		Span small(1);

		small.addNumber(1);

		int shortspan;
		int longspan;

		shortspan = small.shortestSpan();
		longspan = small.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		Span small(2);

		int shortspan;
		int longspan;

		shortspan = small.shortestSpan();
		longspan = small.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
	try
	{
		Span	ordre1(100);
		Span	ordre2(1000);
		Span	ordre3(10000);
		Span	ordre4(100000);
	
		std::cout << Blue "ordre1 Size : " Reset << ordre1.getSize() << std::endl;
		std::cout << Blue "ordre1 Count : " Reset << ordre1.getCount() << std::endl;
		std::cout << Blue "ordre2 Size : " Reset << ordre2.getSize() << std::endl;
		std::cout << Blue "ordre2 Count : " Reset << ordre2.getCount() << std::endl;
		std::cout << Blue "ordre3 Size : " Reset << ordre3.getSize() << std::endl;
		std::cout << Blue "ordre3 Count : " Reset << ordre3.getCount() << std::endl;
		std::cout << Blue "ordre4 Size : " Reset << ordre4.getSize() << std::endl;
		std::cout << Blue "ordre4 Count : " Reset << ordre4.getCount() << std::endl;
		
		int i;

		i = 0;
		while (i < 100)
		{
			ordre1.addNumber(random() % 1000000);
			i++;
		}
		i = 0;
		while (i < 1000)
		{
			ordre2.addNumber(random() % 1000000);
			i++;
		}
		i = 0;
		while (i < 10000)
		{
			ordre3.addNumber(random() % 1000000);
			i++;
		}
		i = 0;
		while (i < 100000)
		{
			ordre4.addNumber(random() % 1000000);
			i++;
		}
		
		long shortspan;
		long longspan;

		shortspan = ordre1.shortestSpan();
		longspan = ordre1.longestSpan();
		
		std::cout << Green " --- Vector 1 --- " Reset << std::endl;
		std::cout << Blue "Shortest span : "Reset << shortspan << std::endl;
		std::cout << Blue "Longest span : " Reset << longspan << std::endl;

		shortspan = ordre2.shortestSpan();
		longspan = ordre2.longestSpan();
		
		std::cout << Green " --- Vector 2 --- " Reset << std::endl;
		std::cout << Blue "Shortest span : "Reset << shortspan << std::endl;
		std::cout << Blue "Longest span : " Reset << longspan << std::endl;

		shortspan = ordre3.shortestSpan();
		longspan = ordre3.longestSpan();
		
		std::cout << Green " --- Vector 3 --- " Reset << std::endl;
		std::cout << Blue "Shortest span : "Reset << shortspan << std::endl;
		std::cout << Blue "Longest span : " Reset << longspan << std::endl;

	/*
		shortspan = ordre4.shortestSpan();
		longspan = ordre4.longestSpan();
		
		std::cout << Green " --- Vector 4 --- " Reset << std::endl;
		std::cout << Blue "Shortest span : "Reset << shortspan << std::endl;
		std::cout << Blue "Longest span : " Reset << longspan << std::endl;
		*/
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		Span 	test(10);
		int 	i;

		i = 0;
		while (i < 10)
		{
			test.addNumber(random() % 100);
			i++;
		}

		std::cout << test << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}