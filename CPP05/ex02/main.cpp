#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

int main()
{
	try
	{
		Bureaucrat bureaucrat("ali", 10);
		PresidentialPardonForm presidentform("President");
		RobotomyRequestForm robotomyform("Robotomy");
		ShrubberyCreationForm shrubberyform("Home");

		std::cout << "<--------- Test 1 --------->\n";
		bureaucrat.signForm(presidentform);
		bureaucrat.executeForm(presidentform);
		shrubberyform.execute(bureaucrat);
		std::cout << "<--------- Test 2 --------->\n";
		bureaucrat.signForm(robotomyform);
		bureaucrat.executeForm(robotomyform);
		shrubberyform.execute(bureaucrat);
		std::cout << "<--------- Test 3 --------->\n";;
		bureaucrat.signForm(shrubberyform);
		bureaucrat.executeForm(shrubberyform);
		shrubberyform.execute(bureaucrat);
		std::cout << "<--------- ------ --------->\n";
	}
	catch (std::exception & e)
	{
		std::cout<<e.what()<< std::endl;
	}
	return (0);
}