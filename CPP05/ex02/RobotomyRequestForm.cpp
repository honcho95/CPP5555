#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():Form("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target):Form("RobotomyRequestForm", 72, 45) , target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
{
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	if (this != &other)
		target = other.target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > getGradeToExec())
    {
        throw(Form::GradeTooLowException());
    }
    else 
    {
        std::cout << "**********Drilling noises**********\n";

        srand(time(NULL));
        if (rand() % 2 == 0)
        {
            std::cout << target << " has been robotomized successfully\n";
        }
        else
        {
            std::cout << target << " robotomization failed\n";
        }
    }
}