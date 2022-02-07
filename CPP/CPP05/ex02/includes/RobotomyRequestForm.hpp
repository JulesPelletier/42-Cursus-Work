/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:01:55 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/07 19:19:32 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
# include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form
{

	public:

		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm( RobotomyRequestForm const & src );
		~RobotomyRequestForm(void);

		RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );
		std::string			const	&getTarget(void) const;
		virtual void 				execute(Bureaucrat const &executor) const;

	private:
		std::string		_target;

};

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i );

#endif /* ********************************************* ROBOTOMYREQUESTFORM_H */