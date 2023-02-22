#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const _NOEXCEPT {
    return "Grade is too high.";
}

const char* AForm::GradeTooLowException::what() const _NOEXCEPT {
    return "Grade is too low.";
}

const char* AForm::ExecuteNotSignedException::what() const _NOEXCEPT {
    return "Execute a form with no sign";
}
