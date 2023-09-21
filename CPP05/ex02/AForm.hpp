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
	~Form();
	Form &operator=(const Form &other);
	const std::string& getName() const;
	bool isSigned() const;
	int getGradeToSign() const;
	int getGradeToExec() const;
	void beSigned(const Bureaucrat &other);
	virtual void execute(Bureaucrat const &executor) const = 0;
	class GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};
	// class FormNotSignedException : public std::exception
	// {
	// 	const char *what() const throw();
	// };
};

std::ostream &operator<<(std::ostream &ost, Form const &bureaucrat);
#endif