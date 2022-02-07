/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:27:14 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/07 17:00:22 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	Bureaucrat	guest;
	Bureaucrat	me("Jules", 120);
	Bureaucrat	error("Error", 149);

	std::cout << "Name > " << guest.getName() << std::endl;
	std::cout << "Grade > " << guest.getGrade() << std::endl;

	std::cout << "Name > " << me.getName() << std::endl;
	std::cout << "Grade > " << me.getGrade() << std::endl;

	me.bettergrade();
	me.bettergrade();
	me.bettergrade();
	guest.bettergrade();
	guest.bettergrade();
	guest.worsegrade();
	error.worsegrade();
	//error.worsegrade();
	std::cout << std::endl;
	std::cout << me << std::endl;
	std::cout << guest << std::endl;
	std::cout << error << std::endl;
}