#include "Form.hpp"

Form::Form() : name("Default"), gradeToSign(150), gradeToExec(150)
{
	_signed = false;
}

Form::Form(std::string name, int sign_grade, int exec_grade):name(name),gradeToSign(sign_grade), gradeToExec(exec_grade)
{
	
	if (gradeToExec < 1 || gradeToSign < 1)
		throw(GradeTooHighException());
	if (gradeToExec > 150 || gradeToSign > 150)
		throw(GradeTooLowException());
	_signed = false;
}

Form::Form(const Form &other) : gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec)
{
	*this = other;
}

Form::~Form() {}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		_signed = other._signed;
	return (*this);
}

std::ostream &operator<<(std::ostream &ost, Form const &bureaucrat)
{
	ost << "Form: " << bureaucrat.getName() << ", Signed: " << bureaucrat.isSigned()
		<< ", Grade to sign: " << bureaucrat.getGradeToSign()
		<< ", Grade to exec: " << bureaucrat.getGradeToExec();
	return (ost);
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
	return ("Required grade too high ! (less than 1)");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Required grade too low ! (more than 150)");
}

void Form::beSigned(const Bureaucrat &other)
{
	if (other.getGrade() <= gradeToSign)
		_signed = true;
	else
		throw(GradeTooLowException());
}