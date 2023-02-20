#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : name_(""), grade_(Bureaucrat::gradeLowest_) {
	std::cout << "Bureaucrat()" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name) {
	std::cout << "Bureaucrat(name, grade)" << std::endl;
	checkGrade(grade);
	grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name_(src.name_), grade_(src.grade_) {
	std::cout << "Bureaucrat(src)" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "~Bureaucrat()" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &rhs) {
	const_cast<std::string&>(name_) = rhs.name_;
	grade_ = rhs.grade_;
	return *this;
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& value) {
	return stream << value.getName() << ": " << value.getGrade() << std::endl;
}

const std::string	Bureaucrat::getName() const {
	return name_;
}

void	Bureaucrat::checkGrade(const int grade) {
	if (grade < gradeLowest_) {
		throw Bureaucrat::GradeTooLowException();
	}
	else if (grade > gradeHighest_) {
		throw Bureaucrat::GradeTooHighException();
	}
	return ;
}

int		Bureaucrat::getGrade() const {
	return grade_;
}

void	Bureaucrat::incrementGrade() {
	checkGrade(grade_ + 1);
	grade_++;
}

void	Bureaucrat::decrementGrade() {
	checkGrade(grade_ - 1);
	grade_--;
}
