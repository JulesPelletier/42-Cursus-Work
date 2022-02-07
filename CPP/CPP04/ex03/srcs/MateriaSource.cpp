/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:52:30 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/01 18:45:09 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MateriaSource::MateriaSource(void)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		this->source[i] = NULL;
		i++;
	}
	std::cout << "Default constructor for MateriaSource" << std::endl;
}

MateriaSource::MateriaSource( const MateriaSource & src )
{
	*this = src;
	std::cout << "Copy constructor for MateriaSource" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource(void)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		delete this->source[i];
		i++;
	}
	std::cout << "Default destructor for MateriaSource" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MateriaSource &				MateriaSource::operator=( MateriaSource const & rhs )
{
	int i;

	i = 0;
	if (this != &rhs)
	{
		while (i < 4)
		{
			//delete this->source[i];
			if (!rhs.source[i])
				this->source[i] = rhs.source[i]->clone();
			else
				this->source[i] = 0;
			i++;
		}
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void		MateriaSource::learnMateria(AMateria *m)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (this->source[i] == 0)
		{
			this->source[i] = m;
			break;
		}
		i++;
	}
	
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	int			i;

	i = 0;
	while (i < 4)
	{
		if (this->source[i] && this->source[i]->getType() == type)
			return (this->source[i]->clone());
		i++;
	}
	return (0);
}



/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */