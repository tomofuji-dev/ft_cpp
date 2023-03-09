#pragma once
#include <deque>
#include <stack>

template < class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {

public:

	typedef typename Container::iterator iterator;

	MutantStack() : std::stack<T, Container>() {};
	MutantStack(const MutantStack& src) : std::stack<T, Container>(src) {};
	~MutantStack() {};

	iterator begin(void) {
		return this->c.begin();
	}

	iterator end(void) {
		return this->c.end();
	}
};
