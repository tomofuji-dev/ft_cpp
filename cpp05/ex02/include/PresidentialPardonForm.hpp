#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

public:

	PresidentialPardonForm();
	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& src);
	~PresidentialPardonForm();
	PresidentialPardonForm&	operator=(const PresidentialPardonForm& rhs);

	virtual void	execute(const Bureaucrat& executor) const;

private:

	const std::string target_;

	const static int	gradeToSignShrubbery_ = 25;
	const static int	gradeToExecuteShrubbery_ = 5;

};
