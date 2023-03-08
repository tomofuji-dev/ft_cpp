#include "Span.hpp"
#include <iostream>

Span::Span(unsigned int N)
	: N_(N), elemN_(0), shortest_span_(UINT_MAX) {}

Span::Span(const Span &src)
	: N_(src.N_), elemN_(src.elemN_), content_(src.content_), shortest_span_(UINT_MAX) {}

Span::~Span() {}

Span& Span::operator=(const Span &rhs) {
	N_ = rhs.N_;
	elemN_ = rhs.elemN_;
	content_ = rhs.content_;
	shortest_span_ = rhs.shortest_span_;
	return *this;
}

void Span::addNumber(int num) {
	// process edge case
	if (N_ == elemN_) {
		throw ContentFullException();
	}
	if (content_.empty()) {
		content_.insert(num);
		elemN_++;
		return ;
	}

	// update shortest_span_
	unsigned int diff;
	if (num < *content_.begin()) {
		diff = *content_.begin() - num;
	}
	else if (num > *content_.rbegin()) {
		diff = num - *content_.rbegin();
	}
	else {
		diff = *content_.lower_bound(num) - num;
	}
	if (diff < shortest_span_) {
		shortest_span_ = diff;
	}

	// insert
	content_.insert(num);
	elemN_++;
}

unsigned int Span::shortestSpan() const {
	if (elemN_ == 0 || elemN_ == 1) {
		throw NotEnoughContentNumException();
	}
	return shortest_span_;
}
unsigned int Span::longestSpan() const {
	if (elemN_ == 0 || elemN_ == 1) {
		throw NotEnoughContentNumException();
	}
	return *content_.rbegin() - *content_.begin();
}

static void print_set(const std::set<int>& c) {
	std::cout << "[";
	for (std::set<int>::iterator it = c.begin(); it != c.end(); it++) {
		if (it != c.begin())
			std::cout << ", ";
		std::cout << *it;
	}
	std::cout << "]" << std::endl;
}

unsigned int	Span::getN() const {
	return N_;
}

unsigned int	Span::getElemN() const {
	return elemN_;
}

std::set<int>	Span::getContent() const {
	return content_;
}

std::ostream& operator<<(std::ostream& stream, const Span& value) {
	stream	<< "{ N_: " << value.getN()
			<< ", elemN_: " << value.getElemN()
			<< " }" << std::endl
			<< "    content_: "; print_set(value.getContent());
	stream  << "    shortest_span: " << value.shortestSpan() << std::endl
			<< "    longest_span: " << value.longestSpan() << std::endl;
	return stream;
}

