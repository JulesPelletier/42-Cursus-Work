/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:54:20 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/21 14:58:56 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	
	a = Fixed(1234.4321f);
	
	std::cout << Cyan "a is " Reset << a << std::endl;
	std::cout << Cyan "b is " Reset << b << std::endl;
	std::cout << Cyan "c is " Reset << c << std::endl;
	std::cout << Cyan "d is " Reset << d << std::endl;
	std::cout << Yellow "a is " Reset << a.toInt() << " as integer" << std::endl;
	std::cout << Yellow "b is " Reset << b.toInt() << " as integer" << std::endl;
	std::cout << Yellow "c is " Reset << c.toInt() << " as integer" << std::endl;
	std::cout << Yellow "d is " Reset << d.toInt() << " as integer" << std::endl;


	
	return 0;
}