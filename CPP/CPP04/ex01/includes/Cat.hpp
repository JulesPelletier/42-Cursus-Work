/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:48:08 by julpelle          #+#    #+#             */
/*   Updated: 2022/01/27 13:04:19 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{

	public:

		Cat(void);
		Cat( Cat const & src );
		~Cat(void);

		Cat 			&operator=( Cat const & rhs );
		Animal			&operator=( Animal const &rhs );
		std::string		getType(void) const;
		virtual Brain			*getBrain(void) const;

	private:
		Brain *brain;

};

std::ostream &			operator<<( std::ostream & o, Cat const & i );

#endif /* ************************************************************* CAT_H */