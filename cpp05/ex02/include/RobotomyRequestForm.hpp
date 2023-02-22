#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {

public:

	RobotomyRequestForm();
	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& src);
	~RobotomyRequestForm();
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& rhs);

	virtual void	execute(const Bureaucrat& executor) const;

private:

	const std::string target_;

	const static int	gradeToSignShrubbery_ = 72;
	const static int	gradeToExecuteShrubbery_ = 45;

};
