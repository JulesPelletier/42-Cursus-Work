/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:01:44 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/07 19:08:45 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PRESIDENTIALPARDONFORM_HPP
# define  PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"
# include "Form.hpp"

class  PresidentialPardonForm : public Form
{

	public:

		 PresidentialPardonForm(void);
		 PresidentialPardonForm(std::string target);
		 PresidentialPardonForm(  PresidentialPardonForm const & src );
		 ~ PresidentialPardonForm(void);

		 PresidentialPardonForm 			&operator=(  PresidentialPardonForm const & rhs );
		 std::string 			const 		&getTarget(void) const;
		 virtual void						execute(Bureaucrat const &executor) const;


	private:
		std::string		_target;

};

std::ostream &			operator<<( std::ostream & o,  PresidentialPardonForm const & i );

#endif /* *****************************************  PRESIDENTIALPARDONFORM_H */