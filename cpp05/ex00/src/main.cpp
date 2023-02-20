#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

int main() {

	std::cout << "Bureaucrat tmp;" << std::endl;
	Bureaucrat tmp;
	std::cout << tmp << std::endl;
	for (int i = -5; i < 3; i++) {
		std::cout << "Bureaucrat tmp(" << i << ")" << std::endl;
		try {
			tmp = Bureaucrat(std::to_string(i), i);
			std::cout << tmp << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException& e) {
			std::cerr << e.what() << std::endl;
			continue;
		}
		catch (Bureaucrat::GradeTooLowException& e) {
			std::cerr << e.what() << std::endl;
			continue;
		}
	}
	for (int i = 148; i < 153; i++) {
		std::cout << "Bureaucrat tmp(" << i << ")" << std::endl;
		try {
			tmp = Bureaucrat(std::to_string(i), i);
			std::cout << tmp << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException& e) {
			std::cerr << e.what() << std::endl;
			continue;
		}
		catch (Bureaucrat::GradeTooLowException& e) {
			std::cerr << e.what() << std::endl;
			continue;
		}
	}
}