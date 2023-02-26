#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm()
	: name_(""), isSigned_(false), gradeToSign_(AForm::gradeLowest_), gradeToExecute_(AForm::gradeLowest_){}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute)
	: name_(name), isSigned_(false),
		gradeToSign_(assertGrade(gradeToSign)), gradeToExecute_(assertGrade(gradeToExecute)){}

AForm::AForm(const AForm &src)
	: name_(src.name_), isSigned_(src.isSigned_), gradeToSign_(src.gradeToSign_), gradeToExecute_(src.gradeToExecute_){}

AForm::~AForm() {
	std::cout << "~AForm()" << std::endl;
}

AForm&	AForm::operator=(const AForm &rhs)
{
	const_cast<std::string&>(name_) = rhs.name_;
	isSigned_ = rhs.isSigned_;
	const_cast<int&>(gradeToSign_) = rhs.gradeToSign_;
	const_cast<int&>(gradeToExecute_) = rhs.gradeToExecute_;
	return *this;
}

int	AForm::assertGrade(const int grade) {
	if (grade > gradeLowest_) {
		throw Bureaucrat::GradeTooLowException();
	}
	else if (grade < gradeHighest_) {
		throw Bureaucrat::GradeTooHighException();
	}
	return grade;
}

const std::string	AForm::getName() const {
	return name_;
}

bool	AForm::getIsSigned() const {
	return isSigned_;
}

int	AForm::getGradeToSign() const {
	return gradeToSign_;
}

int	AForm::getGradeToExecute() const {
	return gradeToExecute_;
}

void	AForm::assertExecutable(const Bureaucrat& bureaucrat) const {
	if (isSigned_ == false) {
		throw ExecuteNotSignedException();
	}
	if (bureaucrat.getGrade() > gradeToExecute_) {
		throw GradeTooLowException();
	}
}

void	AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > gradeToSign_) {
		throw GradeTooLowException();
	}
	isSigned_ = true;
}

std::ostream&	operator<<(std::ostream& stream, const AForm& value) {
	return stream << "name: " << value.getName()
			<< " isSigned: " << value.getIsSigned()
			<< " gradeToSign: " << value.getGradeToSign()
			<< " gradeToExecute: " << value.getGradeToExecute();
}
