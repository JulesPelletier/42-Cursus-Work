/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:42:03 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/01 18:46:53 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{

	public:

		AMateria(void);
		AMateria( AMateria const & src );
		AMateria(std::string const &type);
		virtual ~AMateria(void);

		AMateria &			operator=( AMateria const & rhs );
		std::string	const	&getType(void) const;
		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target);
	protected:
		std::string			type;

};

std::ostream &			operator<<( std::ostream & o, AMateria const & i );

#endif /* ******************************************************** AMATERIA_H */