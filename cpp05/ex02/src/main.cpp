#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
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
	std::cout 	<< YELLOW 
				<< "======================================"	<< std::endl << std::endl;
	std::cout 	<< "         test in shrubberry "			<< std::endl << std::endl;
	std::cout 	<< "======================================"	<< RESET << std::endl;

	test_execute(0, new ShrubberyCreationForm("shrubbery"));
	test_execute(1, new ShrubberyCreationForm("shrubbery"));
	test_execute(150, new ShrubberyCreationForm("shrubbery"));
	test_execute(137, new ShrubberyCreationForm("shrubbery"));
	test_execute(145, new ShrubberyCreationForm("shrubbery"));
}

__attribute__((destructor))
static void	destructor(void) {
 	system("leaks -q exe");
}
