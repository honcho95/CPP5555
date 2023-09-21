#include "AForm.hpp"

Form::Form() :  name("Default"), gradeToSign(150), gradeToExec(150)
{
	_signed = false;
	std::cout << "Form Default constructor called\n";
}

Form::Form(std::string name, int sign_grade, int exec_grade):name(name),gradeToSign(sign_grade), gradeToExec(exec_grade)
{
	if (gradeToExec < 1 || gradeToSign < 1)
		throw(GradeTooHighException());
	if (gradeToExec > 150 || gradeToSign > 150)
		throw(GradeTooLowException());
				
}

Form::Form(const Form &other) : gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec)
{
	*this = other;
	std::cout << "Form Copy constructor called\n";
}

Form::~Form()
{
	std::cout << "Form Destructor called\n";
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		_signed = other._signed;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, Form const &in)
{
	out << "Form: " << in.getName() << ", Signed: " << in.isSigned()
		<< ", Grade to sign: " << in.getGradeToSign()
		<< ", Grade to exec: " << in.getGradeToExec();
	return (out);
}

const std::string &Form::getName() const
{
	return (name);
}

bool Form::isSigned() const
{
	return (_signed);
}

int Form::getGradeToSign() const
{
	return (gradeToSign);
}

int Form::getGradeToExec() const
{
	return (gradeToExec);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Error: GradeTooHighException");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Error: GradeTooLowException");
}

const char *Form::FormNotSignedException::what() const throw()
{
	return ("Error: FormNotSignedException");
}

void Form::beSigned(Bureaucrat &other)
{
	if (other.getGrade() <= gradeToSign)
		_signed = true;
	else
		throw(GradeTooLowException());
}