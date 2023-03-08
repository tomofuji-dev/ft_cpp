#pragma once
#include <set>

class Span {

public:

	class ContentFullException : public std::exception {
		public:
			const char* what() const _NOEXCEPT;
	};

	class NotEnoughContentNumException : public std::exception {
		public:
			const char* what() const _NOEXCEPT;
	};

	Span(unsigned int N);
	Span(const Span& src);
	~Span();
	Span&	operator=(const Span& rhs);

	void			addNumber(int num);
	unsigned int	shortestSpan() const;
	unsigned int	longestSpan() const;

	unsigned int	getN() const;
	unsigned int	getElemN() const;
	std::set<int>	getContent() const;

private:
	
	Span();
	unsigned int	N_;
	unsigned int	elemN_;
	std::set<int>	content_;
	unsigned int	shortest_span_;

};

std::ostream& operator<<(std::ostream& stream, const Span& value);
