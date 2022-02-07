/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:27:14 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/07 17:59:22 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	try
	{
		Bureaucrat	me("Jules", 120);
		Form		f_me("Jury 1", 100, 50);
		std::cout << Blue "Name > " Reset << me.getName() << std::endl;
		std::cout << Blue "Grade > " Reset << me.getGrade() << std::endl;
		
		me.signForm(f_me);
		std::cout << me << std::endl;
		std::cout << f_me << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
	try
	{
		Bureaucrat	me2("Theo", 78);
		Form		f_me2("Jury 2", 100, 50);

		std::cout << Blue "Name > " Reset << me2.getName() << std::endl;
		std::cout << Blue "Grade > " Reset << me2.getGrade() << std::endl;
		
		me2.signForm(f_me2);
		std::cout << me2 << std::endl;
		std::cout << f_me2 << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		Bureaucrat	me3("Blabla", 15);
		Form		f_me3("Jury 3", 100, 50);


		std::cout << Blue "Name > " Reset << me3.getName() << std::endl;
		std::cout << Blue "Grade > " Reset << me3.getGrade() << std::endl;
	
		me3.signForm(f_me3);
		
		std::cout << me3 << std::endl;
		std::cout << f_me3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
}