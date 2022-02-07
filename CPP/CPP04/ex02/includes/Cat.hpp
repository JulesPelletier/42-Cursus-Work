/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:48:08 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/27 18:31:24 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{

	public:

		Cat(void);
		Cat( Cat const & src );
		~Cat(void);

		virtual	Cat 			&operator=( Cat const & rhs );
		virtual AAnimal			&operator=( AAnimal const &rhs );
		virtual std::string		getType(void) const;
		virtual void			makeSound(void) const;
		virtual Brain			*getBrain(void) const;

	private:
		Brain *brain;

};

std::ostream &			operator<<( std::ostream & o, Cat const & i );

#endif /* ************************************************************* CAT_H */