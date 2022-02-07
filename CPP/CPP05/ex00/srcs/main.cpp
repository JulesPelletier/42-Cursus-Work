/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:27:14 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/07 17:49:20 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	try
	{
		Bureaucrat	guest;

		std::cout << Blue "Name > " Reset << guest.getName() << std::endl;
		std::cout << Blue "Grade > " Reset << guest.getGrade() << std::endl;

		guest.bettergrade();
		guest.bettergrade();
		guest.worsegrade();

		std::cout << guest << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		Bureaucrat	me("Jules", 120);
		
		std::cout << Blue "Name > " Reset << me.getName() << std::endl;
		std::cout << Blue "Grade > " Reset << me.getGrade() << std::endl;
		
		me.bettergrade();
		me.bettergrade();
		me.bettergrade();

		std::cout << me << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
	try
	{
		Bureaucrat	error1("Error Min", 149);

		std::cout << Blue "Name > " Reset << error1.getName() << std::endl;
		std::cout << Blue "Grade > " Reset << error1.getGrade() << std::endl;
		
		error1.worsegrade();
		error1.worsegrade();

		std::cout << error1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		Bureaucrat	error2("Error Max", 1);

		std::cout << Blue "Name > " Reset << error2.getName() << std::endl;
		std::cout << Blue "Grade > " Reset << error2.getGrade() << std::endl;
	
		error2.bettergrade();
		
		std::cout << error2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}