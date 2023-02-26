#pragma once
#include <string>
#include "AForm.hpp"

class Intern {

public:

	Intern();
	Intern(const Intern& src);
	~Intern();
	Intern&	operator=(const Intern& rhs);

	AForm* makeForm(const std::string& formName, const std::string& target) const;

private:
	
	static const std::size_t formNum_ = 3;
    static const std::string formNames_[formNum_];
	static std::size_t indexFormName(const std::string& formName);

};

std::ostream& operator<<(std::ostream& stream, const Intern& value);
