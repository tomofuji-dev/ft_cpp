#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Color.hpp"
#include <iostream>

const std::string Intern::formNames_[formNum_] = {
    "ShrubberyCreationForm",
    "RobotomyRequestForm",
    "PresidentialPardonForm"
};

Intern::Intern() {}

Intern::Intern(const Intern &src) {
	(void)src;
}

Intern::~Intern(){
	std::cout << "~Intern()" << std::endl;
}

Intern&	Intern::operator=(const Intern &rhs) {
	(void)rhs;
	return *this;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
	AForm* form;

	switch (indexFormName(formName)) {
		case 0:
			form = new ShrubberyCreationForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
		default:
			std::cerr << RED << formName << "is not appropriate form name" << RESET << std::endl;
			return NULL;
	}
	std::cout << GREEN << "intern created " << formName << RESET << std::endl;
	return form;
}

std::size_t Intern::indexFormName(const std::string& formName) {
	std::size_t index = 0;

	for (; index < formNum_; index++) {
		if (formName == formNames_[index]) {
			break;
		}
	}
	return index;
}

