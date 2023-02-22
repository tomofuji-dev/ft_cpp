#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const _NOEXCEPT {
    return "Grade is too high.";
}

const char* Bureaucrat::GradeTooLowException::what() const _NOEXCEPT {
    return "Grade is too low.";
}