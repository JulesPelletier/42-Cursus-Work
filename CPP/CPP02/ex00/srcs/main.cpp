/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:54:20 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/21 14:27:08 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed b(a);
	Fixed c;
	
	c = b;
	
	std::cout << Green " ==== Printing initial elements ==== " Reset << std::endl;
	std::cout << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << std::endl;

	std::cout << Green " ==== Setting elements ==== " Reset << std::endl;
	std::cout << std::endl;
	a.setRawBits(6);
	b.setRawBits(12);
	std::cout << std::endl;

	std::cout << Green " ==== Copying B in C ==== " Reset << std::endl;
	std::cout << std::endl;
	
	c = b;
	std::cout << std::endl;
	std::cout << Green " ==== Printing new elements ==== " Reset << std::endl;
	std::cout << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << std::endl;

	std::cout << Green " ==== Setting elements ==== " Reset << std::endl;
	std::cout << std::endl;
	c.setRawBits(3);
	std::cout << c.getRawBits() << std::endl;
	a.setRawBits(12);
	std::cout << std::endl;

	std::cout << Green " ==== Copying A in B and B in C ==== " Reset << std::endl;
	std::cout << std::endl;
	b = a;
	c = b;
	std::cout << std::endl;
	std::cout << Green " ==== Printing new elements ==== " Reset << std::endl;
	std::cout << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << std::endl;

	
	return 0;
}