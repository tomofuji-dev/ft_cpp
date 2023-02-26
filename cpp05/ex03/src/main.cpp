#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Color.hpp"
#include <iostream>
#include <string>

void test_execute(int grade, AForm* form) {
	std::cout	<< BLUE 
				<< "--------------------------------------"	<< std::endl;
	std::cout 	<< "         test in grade: " << grade		<< std::endl;
	std::cout 	<< "--------------------------------------"	<< RESET << std::endl;
	Bureaucrat bureaucrat;
	try {
		bureaucrat = Bureaucrat("bureaucrat", grade);
	}
	catch (std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
		delete(form);
		return ;
	}
	std::cout << bureaucrat << std::endl;
	std::cout << *form << std::endl;
	bureaucrat.signForm(*form);
	std::cout << *form << std::endl;
	bureaucrat.executeForm(*form);
	delete(form);
}

int main() {
	Intern intern;

	std::cout 	<< CYAN 
				<< "======================================"	<< std::endl << std::endl;
	std::cout 	<< "             test intern "				<< std::endl << std::endl;
	std::cout 	<< "======================================"	<< RESET << std::endl;
	intern.makeForm("invalidFormName", "invalidFormName");
	intern.makeForm("shrubberycreationform", "invalidFormName");
	intern.makeForm("", "invalidFormName");

	std::cout 	<< CYAN 
				<< "======================================"	<< std::endl << std::endl;
	std::cout 	<< "         test in shrubberry "			<< std::endl << std::endl;
	std::cout 	<< "======================================"	<< RESET << std::endl;

	test_execute(0, intern.makeForm("ShrubberyCreationForm", "shrubbery"));
	test_execute(151, intern.makeForm("ShrubberyCreationForm", "shrubbery"));
	test_execute(1, intern.makeForm("ShrubberyCreationForm", "shrubbery"));
	test_execute(150, intern.makeForm("ShrubberyCreationForm", "shrubbery"));
	test_execute(137, intern.makeForm("ShrubberyCreationForm", "shrubbery"));
	test_execute(145, intern.makeForm("ShrubberyCreationForm", "shrubbery"));

	std::cout 	<< CYAN
				<< "======================================"	<< std::endl << std::endl;
	std::cout 	<< "         test in robotomy "				<< std::endl << std::endl;
	std::cout 	<< "======================================"	<< RESET << std::endl;

	test_execute(0, intern.makeForm("RobotomyRequestForm", "robotomy"));
	test_execute(151, intern.makeForm("RobotomyRequestForm", "robotomy"));
	test_execute(1, intern.makeForm("RobotomyRequestForm", "robotomy"));
	test_execute(150, intern.makeForm("RobotomyRequestForm", "robotomy"));
	test_execute(45, intern.makeForm("RobotomyRequestForm", "robotomy"));
	test_execute(72, intern.makeForm("RobotomyRequestForm", "robotomy"));

	std::cout 	<< CYAN
				<< "======================================"	<< std::endl << std::endl;
	std::cout 	<< "         test in pardon "				<< std::endl << std::endl;
	std::cout 	<< "======================================"	<< RESET << std::endl;

	test_execute(0, intern.makeForm("PresidentialPardonForm", "pardon"));
	test_execute(151, intern.makeForm("PresidentialPardonForm", "pardon"));
	test_execute(1, intern.makeForm("PresidentialPardonForm", "pardon"));
	test_execute(150, intern.makeForm("PresidentialPardonForm", "pardon"));
	test_execute(25, intern.makeForm("PresidentialPardonForm", "pardon"));
	test_execute(5, intern.makeForm("PresidentialPardonForm", "pardon"));
}

__attribute__((destructor))
static void	destructor(void) {
 	system("leaks -q exe");
}
