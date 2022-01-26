/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:41:15 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/26 15:17:58 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/WrongAnimal.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << std::endl;
	std::cout << Yellow " xxxxxx Showing Types xxxxxx " Reset << std::endl;
	std::cout << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << std::endl;
	std::cout << Yellow " xxxxxx Showing Sounds xxxxxx " Reset << std::endl;
	std::cout << std::endl;
	i->makeSound(); 
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	std::cout << Yellow " xxxxxx Other Test xxxxxx " Reset << std::endl;
	std::cout << std::endl;


	Cat	a;
	Dog	b;
	
	std::cout << a.getType() << " " << std::endl;
	std::cout << b.getType() << " " << std::endl;
	a.makeSound(); 
	b.makeSound(); 

	std::cout << std::endl;
	std::cout << Yellow " xxxxxx Other Test ++ xxxxxx " Reset << std::endl;
	std::cout << std::endl;

	WrongCat	wrongcat;
	WrongAnimal	wronganimal;

	std::cout << wrongcat.getType() << " " << std::endl;
	std::cout << wronganimal.getType() << " " << std::endl;


	wrongcat.makeSound(); 
	wronganimal.makeSound(); 
	std::cout << std::endl;
	std::cout << std::endl;

	delete meta;
	delete i;
	delete j;
	
	return 0;
}