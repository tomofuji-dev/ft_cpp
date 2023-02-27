#ifndef BRAIN_H
#define BRAIN_H
#include <string>

class Brain {

public:

	Brain();
	Brain(const Brain& src);
	~Brain();
	Brain&	operator=(const Brain& rhs);

	const static size_t nIdeas = 100;

private:
	std::string ideas_[nIdeas];
};

#endif
