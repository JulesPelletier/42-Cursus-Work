/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:37:41 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/07 21:53:27 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Colors.hpp"
#include "../includes/Serialize.hpp"

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int main(void)
{
	Data	seri;

	seri.str1 = "Hello World!\n";
	seri.str2 = "Bonjour Monde!\n";
	
	uintptr_t	u_ptr;
	Data		*d_ptr;

	u_ptr = serialize(&seri);
	d_ptr = deserialize(u_ptr);
	
	std::cout << std::endl;
	std::cout << Yellow " ===== Original data ===== " Reset << std::endl;
	std::cout << std::endl;
	std::cout << "Str 1 > " << seri.str1;
	std::cout << "Str 2 > " << seri.str2;
	std::cout << std::endl;
	std::cout << Yellow " ===== Data after serialize ===== " Reset << std::endl;
	std::cout << std::endl;
	std::cout << "Str 1 > " << d_ptr->str1;
	std::cout << "Str 2 > " << d_ptr->str2;

	return (0);
}