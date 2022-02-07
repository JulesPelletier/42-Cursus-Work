/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:45:05 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/28 18:19:21 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"


class Cure : public AMateria
{

	public:

		Cure(void);
		Cure( Cure const & src );
		~Cure(void);

		Cure 					&operator=( Cure const & rhs );
		virtual	AMateria		*clone(void) const;
		virtual void			use(ICharacter &target);
		
	private:

};

std::ostream &			operator<<( std::ostream & o, Cure const & i );

#endif /* ************************************************************ CURE_H */