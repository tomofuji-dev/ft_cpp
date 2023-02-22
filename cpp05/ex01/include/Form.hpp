#pragma once
#include <string>

class Bureaucrat;

class Form {

public:

	class GradeTooHighException : public std::exception {
		public:
			const char* what() const _NOEXCEPT;
	};

	class GradeTooLowException : public std::exception {
		public:
			const char* what() const _NOEXCEPT;
	};

	Form();
	Form(const std::string name, const int gradeToSign, const int gradeToExecute);
	Form(const Form& src);
	~Form();
	Form&	operator=(const Form& rhs);

	const std::string	getName() const;
	bool				getIsSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;
	void				beSigned(Bureaucrat& bureaucrat);

private:

	const std::string	name_;
	bool				isSigned_;
	const int			gradeToSign_;
	const int			gradeToExecute_;

	const static int	gradeHighest_ = 1;
	const static int	gradeLowest_ = 150;
	static int			checkGrade(const int grade);

};

std::ostream& operator<<(std::ostream& stream, const Form& value);
