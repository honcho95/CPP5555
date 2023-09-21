#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>

class Bureaucrat
{
    private:
	    const std::string   name;
	    int                 grade;

    public:
	    Bureaucrat(const std::string name, int grade);
	    Bureaucrat(Bureaucrat const & src);
	    ~Bureaucrat();
    	Bureaucrat &operator=(const Bureaucrat &other);
    	const std::string getName() const;
    	int getGrade() const;
    	void upGrade();
    	void downGrade();
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