#pragma once
#include <string>

class Bureaucrat;

class AForm {

public:

	class GradeTooHighException : public std::exception {
		public:
			const char* what() const _NOEXCEPT;
	};

	class GradeTooLowException : public std::exception {
		public:
			const char* what() const _NOEXCEPT;
	};

	class ExecuteNotSignedException : public std::exception {
		public:
			const char* what() const _NOEXCEPT;
	};

	AForm();
	AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
	AForm(const AForm& src);
	virtual ~AForm();
	AForm&	operator=(const AForm& rhs);

	const std::string	getName() const;
	bool				getIsSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;
	void				beSigned(const Bureaucrat& bureaucrat);
	void				assertExecutable(const Bureaucrat& bureaucrat) const;
	virtual void		execute(Bureaucrat const& executor) const = 0;

private:

	const std::string	name_;
	bool				isSigned_;
	const int			gradeToSign_;
	const int			gradeToExecute_;

	const static int	gradeHighest_ = 1;
	const static int	gradeLowest_ = 150;
	static int			assertGrade(const int grade);

};

std::ostream& operator<<(std::ostream& stream, const AForm& value);
