#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include <cstdlib>

class Form;
class Bureaucrat
{
    private:
	    const std::string   name;
	    int                 grade;

    public:
		Bureaucrat();
	    Bureaucrat(const std::string name, int grade);
	    Bureaucrat(Bureaucrat const & src);
	    ~Bureaucrat();
    	Bureaucrat &operator=(const Bureaucrat &other);
    	const std::string getName() const;
    	int getGrade() const;
    	void upGrade();
    	void downGrade();
		void signForm(Form &form) const;
		void executeForm(Form &other) const;
    	class GradeTooHighException : public std::exception
    	{
    		const char *what() const throw();
    	};
    	class GradeTooLowException : public std::exception
    	{
    		const char *what() const throw();
    	};
};

std::ostream &operator<<(std::ostream &ost, Bureaucrat const &bureaucrat);

#endif