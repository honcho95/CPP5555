#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string name, int grade):name(name), grade(grade)
{
	if (grade < 1)
		throw(GradeTooHighException());
	if (grade > 150)
		throw(GradeTooLowException());
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : name(src.name), grade(src.grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		grade = other.grade;
	return (*this);
}

std::ostream& operator<<(std::ostream & ost, Bureaucrat const & bureaucrat)
{
	ost << bureaucrat.getName() << "'s grade is  "<< bureaucrat.getGrade() << "\n";
	return (ost);
}

const std::string Bureaucrat::getName() const
{
	return (name);
}

int	Bureaucrat::getGrade() const
{
	return (grade);
}

void Bureaucrat::upGrade()
{
	if (grade - 1 < 1)
		throw(GradeTooHighException());
	grade -= 1;
}

void Bureaucrat::downGrade()
{
	if (grade + 1 > 150)
		throw(GradeTooLowException());
	grade += 1;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high !");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low !");
}

void Bureaucrat::signForm(Form &form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->getName() << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(Form &other) const
{
	try
	{
		other.execute(*this);
		std::cout << this->getName() << " executes " << other << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " couldn’t execute " << other << " because " << e.what() << "\n";
	}
}