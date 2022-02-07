/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:01:52 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/07 19:35:32 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include "Colors.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

	public:

		Form(void);
		Form( Form const & src );
		Form(std::string name, int gsign, int gexe);
		virtual ~Form(void);

		Form &		operator=( Form const & rhs );
		std::string const		&getName(void) const;
		bool		const		&getSigned(void) const;
		int			const		&getGExe(void) const;
		int			const		&getGSign(void) const;
		void					beSigned(Bureaucrat const &src);
		virtual void			execute(Bureaucrat const &executor) const = 0;
		void					checkGrade(Bureaucrat const &src) const;

		class					GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

		class					GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

		class					NotSigned : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

	private:
		std::string 			_name;
		bool					_signed;
		int						_grade_to_sign;
		int						_grade_to_exe;
};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */