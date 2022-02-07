/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:48:10 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/27 13:03:36 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{

	public:

		Dog(void);
		Dog( Dog const & src );
		~Dog(void);

		Dog 			&operator=( Dog const & rhs );
		Animal			&operator=( Animal const &rhs );
		std::string		getType(void) const;
		virtual Brain			*getBrain(void) const;
		
	private:
		Brain *brain;
};

std::ostream &			operator<<( std::ostream & o, Dog const & i );

#endif /* ************************************************************* DOG_H */