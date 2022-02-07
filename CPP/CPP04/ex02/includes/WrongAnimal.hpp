/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:39:28 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/26 15:15:59 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>
# include "Colors.hpp"

class WrongAnimal
{

	public:

		WrongAnimal(void);
		WrongAnimal( WrongAnimal const & src );
		~WrongAnimal(void);

		WrongAnimal &		operator=( WrongAnimal const & rhs );
		std::string		getType(void) const;
		void			makeSound(void) const;
		
	protected:
		std::string		type;

	private:
		

};

std::ostream &			operator<<( std::ostream & o, WrongAnimal const & i );

#endif /* ********************************************************** ANIMAL_H */