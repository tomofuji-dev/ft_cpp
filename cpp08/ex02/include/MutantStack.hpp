#pragma once
#include <deque>
#include <stack>

template < class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {

public:

	typedef typename Container::iterator				iterator;
	typedef typename Container::const_iterator			const_iterator;
	typedef typename Container::reverse_iterator		reverse_iterator;
	typedef typename Container::const_reverse_iterator	const_reverse_iterator;

	MutantStack() : std::stack<T, Container>() {};
	MutantStack(const MutantStack& src) : std::stack<T, Container>(src) {};
	~MutantStack() {};

	iterator begin(void) {
		return this->c.begin();
	}

	iterator end(void) {
		return this->c.end();
	}

	const_iterator begin(void) const {
		return this->c.cbegin();
	}

	const_iterator end(void) const {
		return this->c.cend();
	}

	reverse_iterator rbegin(void) {
		return this->c.rbegin();
	}

	reverse_iterator rend(void) {
		return this->c.rend();
	}

	const_reverse_iterator rbegin(void) const {
		return this->c.crbegin();
	}

	const_reverse_iterator rend(void) const {
		return this->c.crend();
	}
};
