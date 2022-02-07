/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:48:10 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/27 18:31:32 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{

	public:

		Dog(void);
		Dog( Dog const & src );
		~Dog(void);

		virtual Dog 					&operator=( Dog const & rhs );
		virtual AAnimal					&operator=( AAnimal const &rhs );
		virtual std::string				getType(void) const;
		virtual void					makeSound(void) const;
		virtual Brain					*getBrain(void) const;
		
	private:
		Brain *brain;
};

std::ostream &			operator<<( std::ostream & o, Dog const & i );

#endif /* ************************************************************* DOG_H */