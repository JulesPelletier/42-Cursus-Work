/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:31:59 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/07 16:16:52 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character(void) : _size(4)
{
	this->_name = "Default";
	for (int i = 0; i < 4 ; i++)
		this->inventory[i] = 0;
	std::cout << "Default constructor for Character" << std::endl;
}

Character::Character(std::string name) : _size(4)
{
	for (int i = 0; i < 4 ; i++)
		this->inventory[i] = 0;
	*this = Character();
	this->_name = name;
	std::cout << "Default constructor for Character" << std::endl;
}


Character::Character( const Character & src )
{
	for (int i = 0; i < 4 ; i++)
		this->inventory[i] = 0;
	*this = src;
	std::cout << "Copy constructor for Character" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character(void)
{
	std::cout << "Default destructor for Character" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & rhs )
{
	if ( this != &rhs )
	{
		this->_name = rhs.getName();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Character const & i )
{
	o << "Name = " << i.getName();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string const 			&Character::getName(void) const
{
	return (this->_name);
}

void						Character::equip(AMateria *m)
{
	int	i;

	i = 0;
	while (i < this->_size)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			break;
		}
		i++;
	}
	if (i == 4)
		std::cout << Red "Inventory already full" Reset << std::endl;
}

void				Character::unequip(int idx)
{
	int	i;

	i = 0;
	if (!this->inventory[0])
		std::cout << Red "Inventory is empty ! " Reset << std::endl;
	if (idx <= 0 || idx > 4)
		std::cout << Red "Incorrect index ! " Reset << std::endl;
	while (i < this->_size)
	{
		if (i >= idx - 1 && i + 1 < 4)
			this->inventory[i] = this->inventory[i + 1];
		i++;
	}
	return;
}

void				Character::use(int idx, ICharacter &target)
{
	std::cout << Yellow "Check" Reset << std::endl;
	if (idx <= 0 || idx > 4)
		std::cout << Red "Impossible index (between 1 and 4)" Reset << std::endl;
	else
	{
		std::cout << "index " << idx << std::endl;
		if (this->inventory[idx - 1] != 0)
		{
			std::cout << "in loop " << idx << std::endl;
			std::cout << "Type : " << this->inventory[idx - 1]->getType() << std::endl;
			this->inventory[idx - 1]->use(target);
		}
		else
			std::cout << Red "Slot is empty" Reset << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */