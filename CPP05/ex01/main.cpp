#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "<--------- Test 1 --------->\n";
    try
    {
        Bureaucrat bureaucrat1("bureaucrat1", 1);
		std::cout << bureaucrat1;
        Form form1("Form1", 1, 1);
		std::cout << form1 << "\n";
        bureaucrat1.signForm(form1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "<--------- Test 2 --------->\n";
    try
    {
        Bureaucrat bureaucrat2("bureaucrat2", 150);
		std::cout << bureaucrat2;
        Form form2("Form2", 1, 1);
        std::cout << form2 << "\n";
        bureaucrat2.signForm(form2);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "<--------- Test 3 --------->\n";
    try
    {
        Bureaucrat bureaucrat3("bureaucrat3", 2);
		std::cout << bureaucrat3;
        Form form3("Form3", 1, 1);
		std::cout << form3 << "\n";
        bureaucrat3.signForm(form3);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "<--------- Test 4 --------->\n";
    try
    {
        Form form4("Form4", 0, 1);
        std::cout << form4 << "\n";
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << "<--------- Test 5 --------->\n";
    try
    {
        Form form5("Form5", 151, 1); // Expect GradeTooLowException
        std::cout << form5 << "\n";
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
