#pragma once
#include <string>

class AForm;

class Bureaucrat {

public:

	class GradeTooHighException : public std::exception {
		public:
			const char* what() const _NOEXCEPT;
	};

	class GradeTooLowException : public std::exception {
		public:
			const char* what() const _NOEXCEPT;
	};

	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& src);
	~Bureaucrat();
	Bureaucrat&	operator=(const Bureaucrat& rhs);

	const std::string	getName() const;
	int					getGrade() const;
	void				incrementGrade();
	void				decrementGrade();
	void				signForm(AForm& form);
	void				executeForm(const AForm& form);

private:

	const std::string	name_;
	int 				grade_;
	const static int	gradeHighest_ = 1;
	const static int	gradeLowest_ = 150;

	static void	assertGrade(const int grade);

};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& value);
