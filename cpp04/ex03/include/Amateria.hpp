#pragma once
#include <string>

class AMateria {

public:

	AMateria();
	AMateria(const std::string& type);
	AMateria(const AMateria& src);
	~AMateria();
	AMateria&	operator=(const AMateria& rhs);

protected:

};
