#include "RobotomyRequestForm.hpp"
#include "Color.hpp"
#include <iostream>
#include <fstream>
#include <random>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("", gradeToSignShrubbery_, gradeToExecuteShrubbery_), target_("") {
	std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm(target, gradeToSignShrubbery_, gradeToExecuteShrubbery_), target_(target) {
	std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute()), target_(src.target_) {
	std::srand(std::time(NULL));
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "~RobotomyRequestForm()" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	AForm::operator=(rhs);
	const_cast<std::string&>(target_) = rhs.target_;
	return *this;
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	AForm::assertExecutable(executor);
	std::cout << GREEN << "~~~ TAP-TAP ~~~" << RESET << std::endl;
	if (std::rand() % 2 == 1) {
		std::cout << GREEN << "    Success!" << RESET << std::endl;
	}
	else {
		std::cout << GREEN << "    Failed..." << RESET << std::endl;
	}
}
