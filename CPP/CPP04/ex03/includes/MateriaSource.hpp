/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:53:04 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/01 18:46:34 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "IMateriaSource.hpp"

class IMateriaSource;

class MateriaSource : public IMateriaSource
{

	public:

		MateriaSource(void);
		MateriaSource( MateriaSource const & src );
		~MateriaSource(void);

		MateriaSource &		operator=( MateriaSource const & rhs );
		virtual void		learnMateria(AMateria*);
		virtual AMateria	*createMateria(std::string const &type);

	private:
		AMateria			*source[4];
};


#endif /* *************************************************** MATERIASOURCE_H */