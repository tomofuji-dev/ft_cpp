#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("", gradeToSignShrubbery_, gradeToExecuteShrubbery_), target_("") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm(target, gradeToSignShrubbery_, gradeToExecuteShrubbery_), target_(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute()), target_(src.target_) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "~ShrubberyCreationForm()" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	AForm::operator=(rhs);
	const_cast<std::string&>(target_) = rhs.target_;
	return *this;
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	AForm::assertExecutable(executor);
	std::string filename = target_ + "_shrubbery";
	std::ofstream ofs;
    ofs.exceptions(std::ios::failbit | std::ios::badbit);
    ofs.open(filename);
	{
		ofs
		<< "\033[38;5;034m                                                                   @@"			<< std::endl
		<< "\033[38;5;034m                                                               @@@@@@"			<< std::endl
		<< "\033[38;5;034m                                                            @@@@@@@@"				<< std::endl
		<< "\033[38;5;034m                                                          @@@@@@@@@@"				<< std::endl
		<< "\033[38;5;034m                                                         @@@@@@@@@@"				<< std::endl
		<< "\033[38;5;034m                                                        @@@@@@@@@@"				<< std::endl
		<< "\033[38;5;034m                                                        @@@@@@@@"					<< std::endl
		<< "\033[38;5;034m                                                       @@@@@@"					<< std::endl
		<< "\033[38;5;034m                                                       @@"						<< std::endl
		<< "\033[38;5;034m                                      @@@@@@@@@@@@        @@@@@@@@@@@@@@@"		<< std::endl
		<< "\033[38;5;034m                                   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"		<< std::endl
		<< "\033[38;5;034m                                 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"	<< std::endl
		<< "\033[38;5;034m                               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"		<< std::endl
		<< "\033[38;5;226m                              @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"		<< std::endl
		<< "\033[38;5;226m                             @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"		<< std::endl
		<< "\033[38;5;226m                            @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"			<< std::endl
		<< "\033[38;5;226m                            @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"			<< std::endl
		<< "\033[38;5;208m                            @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"			<< std::endl
		<< "\033[38;5;208m                            @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"			<< std::endl
		<< "\033[38;5;208m                            @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"			<< std::endl
		<< "\033[38;5;208m                            @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"			<< std::endl
		<< "\033[38;5;196m                            @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"		<< std::endl
		<< "\033[38;5;196m                            @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"		<< std::endl
		<< "\033[38;5;196m                             @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"	<< std::endl
		<< "\033[38;5;196m                              @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"	<< std::endl
		<< "\033[38;5;129m                               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"	<< std::endl
		<< "\033[38;5;129m                                @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"	<< std::endl
		<< "\033[38;5;129m                                 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"	<< std::endl
		<< "\033[38;5;129m                                  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"		<< std::endl
		<< "\033[38;5;038m                                   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"		<< std::endl
		<< "\033[38;5;038m                                     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"		<< std::endl
		<< "\033[38;5;038m                                       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"			<< std::endl
		<< "\033[38;5;038m                                         @@@@@@@@@          @@@@@@@@@"			<< std::endl
		<< "\033[0m";
	}
}
