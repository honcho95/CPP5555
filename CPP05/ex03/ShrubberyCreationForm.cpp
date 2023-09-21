#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():Form("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm Default constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):Form("ShrubberyCreationForm", 145, 137)
{
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
{
	*this = other;
	std::cout << "ShrubberyCreationForm Copy constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor called\n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if (this != &other)
		_target = other._target;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &exec) const
{
	// if (isSigned() == false)
	// 	throw(Form::FormNotSignedException());
	std::cout << exec.getGrade() << "]"<< getGradeToExec() << "\n";
	 if (exec.getGrade() > getGradeToExec())
		throw(Form::GradeTooLowException());
	std::ofstream file(_target + "_shrubbery");

    file << "        *" << std::endl;
    file << "       ***" << std::endl;
    file << "      *****" << std::endl;
    file << "     *******" << std::endl;
    file << "    *********" << std::endl;
    file << "   ***********" << std::endl;
    file << "  *************" << std::endl;
    file << " ***************" << std::endl;
    file << "*****************" << std::endl;
    file << "       ***" << std::endl;
    file << "       ***" << std::endl;
	file.close();
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (_target);
}