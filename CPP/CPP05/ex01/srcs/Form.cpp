#include "../includes/Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form(void) : _name("default"), _signed(false), _grade_to_sign(75), _grade_to_exe(100)
{
	std::cout << Yellow "Default constructor called for Form" Reset << std::endl;
}

Form::Form(std::string name, int gsign, int gexe) : _signed(false)
{
	this->_name = name;
	this->_grade_to_sign = gsign;
	this->_grade_to_exe = gexe;
	std::cout << Yellow "Default constructor called for Form" Reset << std::endl;
}

Form::Form( const Form & src ) : _name(src.getName()), _signed(src.getSigned()), _grade_to_sign(src.getGSign()), _grade_to_exe(src.getGExe())
{
	std::cout << Purple "Copy constructor called for Form" Reset << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form(void)
{
	std::cout << Yellow "Default destructor called for Form" Reset << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
	{
		this->_name = rhs.getName();
		this->_signed = rhs.getSigned();
		this->_grade_to_exe = rhs.getGExe();
		this->_grade_to_sign = rhs.getGSign();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << Cyan "Name = " Reset << i.getName() << std::endl;
	o << Cyan "Is signed = " Reset << i.getSigned() << std::endl;
	o << Cyan "Grade to sign = " Reset << i.getGSign() << std::endl;
	o << Cyan "Grade to execute = " Reset << i.getGExe() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string const		&Form::getName(void) const
{
	return (this->_name);
}

bool		const		&Form::getSigned(void) const
{
	return (this->_signed);
}

int			const		&Form::getGExe(void) const
{
	return (this->_grade_to_exe);
}

int			const		&Form::getGSign(void) const
{
	return (this->_grade_to_sign);
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return (Red "Grade is too high" Reset);
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return (Red "Grade is too low" Reset);
}

void		Form::beSigned(Bureaucrat const &src)
{
	if (this->_grade_to_sign < src.getGrade())
		throw GradeTooLowException();
	else
		this->_signed = true;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */