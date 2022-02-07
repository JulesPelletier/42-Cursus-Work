/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:41:01 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/07 16:05:33 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

int	main(void)
{

	std::cout << " ==== Testing default constructors ==== " << std::endl;
	Cure	cure;
	Ice		ice;
	std::cout << cure.getType() << std::endl;
	std::cout << ice.getType() << std::endl;
	std::cout << " ==== Testing copy constructors ==== " << std::endl;
	Cure	cure_copy(cure);
	Ice		ice_copy(ice);
	std::cout << cure_copy.getType() << std::endl;
	std::cout << ice_copy.getType() << std::endl;

	std::cout << " ==== More Tests ==== " << std::endl;
	std::cout << Blue "> Creation  " Reset << std::endl;
	ICharacter	*perso_1 = new Character;
	ICharacter	*perso_2 = new Character("Bob");
	ICharacter	*perso_3 = new Character("Eddy");

	std::cout << Blue "> Names  " Reset << std::endl;
	std::cout << std::endl;
	std::cout << perso_1->getName() << std::endl;
	std::cout << perso_2->getName() << std::endl;
	std::cout << std::endl;

	std::cout << Blue "> Actions  " Reset << std::endl;
	std::cout << Cyan "Equip materias" Reset << std::endl;
	perso_1->equip(&cure);
	perso_1->equip(&ice);
	perso_1->equip(&ice);
	perso_1->equip(&cure);
	perso_1->equip(&ice);
	perso_2->equip(&ice);
	
	std::cout << Cyan "Using materias" Reset << std::endl;
	perso_1->use(1, *perso_2);
	perso_1->use(2, *perso_2);
	//perso_2->use(1, *perso_1);
	//perso_2->use(3, *perso_1);
	perso_1->use(3, *perso_1);
	perso_2->use(6, *perso_1);

	std::cout << Cyan "Unequip first materia and use the new '1st' one" Reset << std::endl;
	perso_1->unequip(1);
	perso_1->use(1, *perso_2);
	perso_1->unequip(1);
	perso_1->use(1, *perso_2);


	std::cout << Cyan "Unequip empty inventory " Reset << std::endl;
	perso_3->unequip(0);


	std::cout << std::endl;
	delete	perso_1;
	delete	perso_2;
	delete	perso_3;
	
	std::cout << " ==== Original Main Test ==== " << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(1, *bob);
	//me->use(2, *bob);
	delete bob;
	delete me;
	delete src;

	return (0);
}