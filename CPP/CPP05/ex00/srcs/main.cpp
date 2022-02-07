/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:27:14 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/07 17:06:35 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	Bureaucrat	guest;
	Bureaucrat	me("Jules", 120);
	Bureaucrat	error1("Error Min", 149);
	Bureaucrat	error2("Error Max", 1);

	std::cout << Blue "Name > " Reset << guest.getName() << std::endl;
	std::cout << Blue "Grade > " Reset << guest.getGrade() << std::endl;

	std::cout << Blue "Name > " Reset << me.getName() << std::endl;
	std::cout << Blue "Grade > " Reset << me.getGrade() << std::endl;

	std::cout << Blue "Name > " Reset << error1.getName() << std::endl;
	std::cout << Blue "Grade > " Reset << error1.getGrade() << std::endl;

	std::cout << Blue "Name > " Reset << error2.getName() << std::endl;
	std::cout << Blue "Grade > " Reset << error2.getGrade() << std::endl;

	me.bettergrade();
	me.bettergrade();
	me.bettergrade();
	guest.bettergrade();
	guest.bettergrade();
	guest.worsegrade();
	error1.worsegrade();
	//error2.bettergrade();
	//error.worsegrade();

	
	std::cout << std::endl;
	std::cout << " ====== Final Results ====== " << std::endl;
	std::cout << std::endl;
	std::cout << me << std::endl;
	std::cout << guest << std::endl;
	std::cout << error1 << std::endl;
	std::cout << error2 << std::endl;
}