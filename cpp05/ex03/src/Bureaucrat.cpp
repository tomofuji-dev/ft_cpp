#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Color.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : name_(""), grade_(Bureaucrat::gradeLowest_) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name) {
	assertGrade(grade);
	grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name_(src.name_), grade_(src.grade_) {}

Bureaucrat::~Bureaucrat() {
	std::cout << "~Bureaucrat()" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &rhs) {
	const_cast<std::string&>(name_) = rhs.name_;
	grade_ = rhs.grade_;
	return *this;
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& value) {
	return stream << "name: " << value.getName() << " grade: " << value.getGrade();
}

const std::string	Bureaucrat::getName() const {
	return name_;
}

void	Bureaucrat::assertGrade(const int grade) {
	if (grade > gradeLowest_) {
		throw Bureaucrat::GradeTooLowException();
	}
	else if (grade < gradeHighest_) {
		throw Bureaucrat::GradeTooHighException();
	}
	return ;
}

int		Bureaucrat::getGrade() const {
	return grade_;
}

void	Bureaucrat::incrementGrade() {
	assertGrade(grade_ - 1);
	grade_--;
}

void	Bureaucrat::decrementGrade() {
	assertGrade(grade_ + 1);
	grade_++;
}

void	Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
	}
	catch (AForm::GradeTooLowException& e) {
		std::cerr << RED << "bureaucrat_"<< name_ 
					<< " couldn\'t sign form_" << form.getName()
					<< " because " << e.what() << RESET << std::endl;
		return ;
	}
	std::cout << GREEN << "bureaucrat: " << name_ << " signed form: " << form.getName() << RESET << std::endl;
}

void	Bureaucrat::executeForm(const AForm& form) {
	try {
		form.execute(*this);
	}
	catch (AForm::ExecuteNotSignedException& e) {
		std::cerr << RED << "bureaucrat_"<< name_ 
					<< " couldn\'t execute form_" << form.getName()
					<< " because " << e.what() << RESET << std::endl;
		return ;
	}
	catch (AForm::GradeTooLowException& e) {
		std::cerr << RED << "bureaucrat_"<< name_ 
					<< " couldn\'t execute form_" << form.getName()
					<< " because " << e.what() << RESET << std::endl;
		return ;
	}
	catch (std::exception& e) {
		std::cerr << RED << "bureaucrat_"<< name_ 
					<< " couldn\'t execute form_" << form.getName()
					<< " because " << e.what() << RESET << std::endl;
		return ;
	}
	std::cout << GREEN << "bureaucrat: " << name_ << " executed form: " << form.getName() << RESET << std::endl;
}
