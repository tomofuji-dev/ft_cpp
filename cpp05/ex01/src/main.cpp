#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <string>

void print(Bureaucrat& b, Form& f) {
	std::cout << "    " << b << std::endl;
	std::cout << "    " << f << std::endl;
}

void test_signForm(Bureaucrat b, Form f, int n = 1) {
	Form form(f);
	Bureaucrat bureaucrat(b);
	
	std::cout << "=== init ===" << std::endl;
	print(bureaucrat, form);
	std::cout << "=== signform ===" << std::endl;
	bureaucrat.signForm(form);
	print(bureaucrat, form);
	std::cout << "=== b++(" << n << ")===" << std::endl;
	try {
		for (int i = 0; i < n; i++) {
			bureaucrat.decrementGrade();
		}
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}
	print(bureaucrat, form);
	std::cout << "=== signform ===" << std::endl;
	bureaucrat.signForm(form);
	print(bureaucrat, form);
	std::cout << "=== b--(" << n << ")===" << std::endl;
	try {
		for (int i = 0; i < 2 * n; i++) {
			bureaucrat.incrementGrade();
		}
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}
	print(bureaucrat, form);
	std::cout << "=== signform ===" << std::endl;
	bureaucrat.signForm(form);
	print(bureaucrat, form);
}

void test_initForm(int i, int j) {
	Form f;
	std::cout << "Form(\"testForm\", " << i << ", " << j << ")" << std::endl;
	try {
		f = Form("testForm", i, j);
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
		return;
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
		return;
	}
	std::cout << "success to instance: " << f << std::endl;
}

int main() {

	std::cout << "+++++ test initFrom +++++" << std::endl;
	test_initForm(151, 150);
	test_initForm(150, 151);
	test_initForm(150, 151);
	test_initForm(0, 1);
	test_initForm(1, 0);
	test_initForm(1, 1);
	test_initForm(150, 150);

	std::cout << "+++++ test signForm +++++" << std::endl;
	Form form1("testForm1", 1, 1);
	Bureaucrat bureaucrat1("testBureaucrat1", 2);

	test_signForm(bureaucrat1, form1, 3);

	Form form2("testForm2", 148, 148);
	Bureaucrat bureaucrat2("testBureaucrat2", 150);

	test_signForm(bureaucrat2, form2, 3);
}