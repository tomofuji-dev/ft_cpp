#include "RPN.hpp"
#include <stdexcept>
#include <climits>

RPN::RPN() {}

RPN::RPN(const RPN &src) {
	*this = src;
}

RPN::~RPN() {}

RPN&	RPN::operator=(const RPN &rhs) {
	if (this == &rhs) {
		return *this;
	}
	input_ = rhs.input_;
	rpnStack_ = rhs.rpnStack_;
	return *this;
}

int RPN::popFromStack() {
	int	val;
	if (rpnStack_.empty()) {
		throw std::runtime_error("Error");
	}
	val = rpnStack_.top();
	rpnStack_.pop();
	return val;
}

int	RPN::calc(const std::string input) {
	input_			= input;
	rpnStack_		= std::stack<int>();

	const_str_iter	it = input_.begin();
	char			next_token;
	int				dest, src;

	while (it != input_.end()) {
		next_token = *popFromInput(it);
		if (std::isdigit(next_token)) {
			rpnStack_.push(next_token - '0');
			continue ;
		}
		src = popFromStack();
		dest = popFromStack();
		switch (next_token) {
			case '+':
				rpnStack_.push(add(dest, src));
				break ;
			case '-':
				rpnStack_.push(sub(dest, src));
				break ;
			case '*':
				rpnStack_.push(mul(dest, src));
				break ;
			case '/':
				rpnStack_.push(div(dest, src));
				break ;
			default:
				throw std::runtime_error("Error");
		};
	}
	if (rpnStack_.size() != 1) {
		throw std::runtime_error("Error");
	}
	return popFromStack();
}

int	RPN::add(int lhs, int rhs) const {
	if ((lhs > 0 && rhs > INT_MAX - lhs) || (lhs < 0 && rhs < INT_MIN - lhs)) {
		throw std::overflow_error("integer overflow in addition");
	}
	return lhs + rhs;
}

int	RPN::sub(int lhs, int rhs) const {
	if ((rhs > 0 && lhs < INT_MIN + rhs) || (rhs < 0 && lhs > INT_MAX + rhs)) {
		throw std::overflow_error("integer overflow in subtraction");
	}
	return lhs - rhs;
}

int	RPN::mul(int lhs, int rhs) const {
	if (lhs > 0) {
		if (rhs > 0) {
			if (lhs > INT_MAX / rhs) {
				throw std::overflow_error("integer overflow in multiplication");
			}
		} else if (rhs < INT_MIN / lhs) {
			throw std::overflow_error("integer overflow in multiplication");
		}
	} else if (lhs < 0) {
		if (rhs > 0) {
			if (lhs < INT_MIN / rhs) {
				throw std::overflow_error("integer overflow in multiplication");
			}
		} else if (rhs < INT_MAX / lhs) {
			throw std::overflow_error("integer overflow in multiplication");
		}
	}
	return lhs * rhs;
}

int RPN::div(int lhs, int rhs) const {
	if (rhs == 0) {
		throw std::runtime_error("division by zero");
	}
	if (lhs == INT_MIN && rhs == -1) {
		throw std::overflow_error("integer overflow in division");
	}
	return lhs / rhs;
}

bool	RPN::is_operator(const char c) const {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool	RPN::is_valid_token(const char c) const {
	return (std::isdigit(c) || is_operator(c));
}

const_str_iter	RPN::popFromInput(const_str_iter& it) const {
	const_str_iter	it_pop_word;
	it_pop_word = it;
	if (!is_valid_token(*it)) {
		throw std::runtime_error("Error");
	}
	it++;
	if (it == input_.end()) {
		return it_pop_word;
	}
	if (*it != ' ') {
		throw std::runtime_error("Error");
	}
	it++;
	if (it == input_.end()) {
		throw std::runtime_error("Error");
	}
	return it_pop_word;
}
