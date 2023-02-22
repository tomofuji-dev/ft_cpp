#include "Form.hpp"

const char* Form::GradeTooHighException::what() const _NOEXCEPT {
    return "Grade is too high.";
}

const char* Form::GradeTooLowException::what() const _NOEXCEPT {
    return "Grade is too low.";
}