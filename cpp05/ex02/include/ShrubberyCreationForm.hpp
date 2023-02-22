#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

public:

	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& src);
	~ShrubberyCreationForm();
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& rhs);

	virtual void	execute(const Bureaucrat& executor) const;

private:

	const std::string target_;

	const static int	gradeToSignShrubbery_ = 145;
	const static int	gradeToExecuteShrubbery_ = 137;

};
