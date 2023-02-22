#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form()
	: name_(""), isSigned_(false), gradeToSign_(Form::gradeLowest_), gradeToExecute_(Form::gradeLowest_)
{
	std::cout << "Form()" << std::endl;
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute)
	: name_(name), isSigned_(false),
		gradeToSign_(checkGrade(gradeToSign)), gradeToExecute_(checkGrade(gradeToExecute))
{
	std::cout << "Form(name, gradeToSign, gradeToExecute)" << std::endl;
}

Form::Form(const Form &src) 
	: name_(src.name_), isSigned_(src.isSigned_), gradeToSign_(src.gradeToSign_), gradeToExecute_(src.gradeToExecute_)
{
	std::cout << "Form(src)" << std::endl;
}

Form::~Form() {
	std::cout << "~Form()" << std::endl;
}

Form&	Form::operator=(const Form &rhs)
{
	const_cast<std::string&>(name_) = rhs.name_;
	isSigned_ = rhs.isSigned_;
	const_cast<int&>(gradeToSign_) = rhs.gradeToSign_;
	const_cast<int&>(gradeToExecute_) = rhs.gradeToExecute_;
	return *this;
}

int	Form::checkGrade(const int grade) {
	if (grade > gradeLowest_) {
		throw Bureaucrat::GradeTooLowException();
	}
	else if (grade < gradeHighest_) {
		throw Bureaucrat::GradeTooHighException();
	}
	return grade;
}

const std::string	Form::getName() const {
	return name_;
}

bool	Form::getIsSigned() const {
	return isSigned_;
}

int	Form::getGradeToSign() const {
	return gradeToSign_;
}

int	Form::getGradeToExecute() const {
	return gradeToExecute_;
}

void	Form::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > gradeToSign_) {
		throw GradeTooLowException();
	}
	isSigned_ = true;
}

std::ostream&	operator<<(std::ostream& stream, const Form& value) {
	return stream << "name: " << value.getName()
			<< " isSigned: " << value.getIsSigned()
			<< " gradeToSign: " << value.getGradeToSign()
			<< " gradeToExecute: " << value.getGradeToExecute() << std::endl;
}
