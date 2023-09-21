#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
	const std::string name;
	bool _signed;
	const int gradeToSign;
	const int gradeToExec;

public:
	Form();
	Form(std::string name, int sign_grade, int exec_grade);
	Form(const Form &other);
	virtual ~Form();
	Form &operator=(const Form &other);
	const std::string& getName() const;
	bool isSigned() const;
	int getGradeToSign() const;
	int getGradeToExec() const;
	class GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
		const char *what() const throw();
	};
	void beSigned(Bureaucrat &other);
	virtual void execute(Bureaucrat const &exec) const = 0;
};

std::ostream &operator<<(std::ostream &out, Form const &in);
#endif