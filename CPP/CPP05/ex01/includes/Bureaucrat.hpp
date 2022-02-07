#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Colors.hpp"
# include "Form.hpp"

class Form;

class Bureaucrat
{

	public:

		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat(void);

		Bureaucrat 			&operator=( Bureaucrat const & rhs );
		std::string	const	&getName(void) const;
		int			const 	&getGrade(void) const;
		void				bettergrade(void);
		void				worsegrade(void);
		void				checkGrade(void);
		void				signForm(Form &form);

		class				GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

		class				GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

	private:
		std::string		_name;
		int				_grade;

};


std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */