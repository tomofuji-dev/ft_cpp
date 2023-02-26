#include "PresidentialPardonForm.hpp"
#include "Color.hpp"
#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <unistd.h>

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("", gradeToSignShrubbery_, gradeToExecuteShrubbery_), target_("") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	: AForm(target, gradeToSignShrubbery_, gradeToExecuteShrubbery_), target_(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
	: AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute()), target_(src.target_) {}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "~PresidentialPardonForm()" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	AForm::operator=(rhs);
	const_cast<std::string&>(target_) = rhs.target_;
	return *this;
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	AForm::assertExecutable(executor);
	std::cout << GREEN <<  target_ << " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;
}
