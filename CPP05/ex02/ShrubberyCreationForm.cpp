#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():Form("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):Form("ShrubberyCreationForm", 145, 137)
{
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
{
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if (this != &other)
		_target = other._target;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	// if (isSigned() == false)
	// 	throw(Form::FormNotSignedException());
	std::cout << executor.getGrade() << "]" << getGradeToExec() << "\n";
	 if (executor.getGrade() > getGradeToExec())
		throw(Form::GradeTooLowException());
	std::ofstream file((_target + "_shrubbery").c_str());

    file << "              %%%,%%%%%%%" << std::endl;
    file << "            ,'%% \\-*%%%%%%%" << std::endl;
    file << "      ;%%%%%*%   _%%%%\"" << std::endl;
    file << "       ,%%%       \\(_.*%%%%." << std::endl;
    file << "       % *%%, ,%%%%*(    '" << std::endl;
    file << "     %^     ,*%%% )\\|,%%*%,_" << std::endl;
    file << "          *%    \\/ #).-\"*%%*" << std::endl;
    file << "              _.) ,/ *%," << std::endl;
    file << "      _________/)#(_____________" << std::endl;

	file.close();
}