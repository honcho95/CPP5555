#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat Default constructor called\n";
}

Bureaucrat::Bureaucrat(const std::string name, int grade):name(name)
{
	_grade = grade;
	if (_grade < 1)
		throw(GradeTooHighException());
	if (_grade > 150)
		throw(GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &other):name(other.name)
{
	_grade = other._grade;
	std::cout << "Bureaucrat Copy constructor called\n";
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;	
	std::cout << "Bureaucrat Copy assignment operator called\n";
	return (*this);
}

std::ostream& operator<<(std::ostream& out, Bureaucrat const &in)
{
	out << in.getName() << ", bureaucrat grade "<< in.getGrade();
	return (out);
}

const std::string Bureaucrat::getName() const
{
	return (name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::increment()
{
	if (_grade - 1 < 1)
		throw(GradeTooHighException());
	_grade -= 1;
}

void Bureaucrat::decrement()
{
	if (_grade + 1 > 150)
		throw(GradeTooLowException());
	_grade += 1;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error: GradeTooHighException");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error: GradeTooLowException");
}

void  Bureaucrat::signForm(Form &other) const
{
	if (other.isSigned())
		std::cout << *this << " signed " << other << "\n";
	else
		std::cout << *this << " couldn’t sign " << other << " because GradeTooLow \n";
}

void Bureaucrat::excuteForm(Form &other) const
{
	try
	{
		other.execute(*this);
		std::cout << *this << " executes " << other << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << *this << " couldn’t execute " << other << " because " << e.what() << "\n";
	}
}