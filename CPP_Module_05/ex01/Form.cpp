#include "Form.hpp"

Form::Form()
	:name(""), sign(false), signRequest(150), execRequest(150)
{
}

Form::Form(std::string name, int signRequest, int execRequest)
	:name(name), sign(false), signRequest(signRequest), execRequest(execRequest)
{
	if (signRequest < HIGHEST_G || execRequest < HIGHEST_G)
		throw(Bureaucrat::GradeTooHighException());
	else if (signRequest > LOWEST_G || execRequest > LOWEST_G)
		throw(Bureaucrat::GradeTooLowException());
}

Form::Form(Form& copy)
	:	name(copy.getName()),
		sign(copy.getSign()),
		signRequest(copy.getSignRequest()),
		execRequest(copy.getExecRequest())
{
}

Form& Form::operator=(Form& copy)
{
	if (this != &copy)
	{
		sign = copy.getSign();
	}
	return (*this);
}

Form::~Form()
{
}

const std::string&	Form::getName() const
{
	return (name);
}

bool	Form::getSign() const
{
	return (sign);
}

const int&	Form::getSignRequest() const
{
	return (signRequest);
}

const int&	Form::getExecRequest() const
{
	return (execRequest);
}

void	Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > getSignRequest())
		throw (GradeTooLowException());
	if (sign == true)
		throw (SignException());
	else
		sign = true;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Your grade too high");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Your grade too low");
}

const char*	Form::SignException::what() const throw()
{
	return("This form is already signed");
}

std::ostream&	operator<<(std::ostream& out, const Form& Form)
{
	out << Form.getName()
		<< "'s informations" << std::endl
		<< " Sign : " << Form.getSign()
		<< " Sign Request : " << Form.getSignRequest()
		<< " Execute Request : " << Form.getExecRequest() << std::endl;
	return (out);
}
