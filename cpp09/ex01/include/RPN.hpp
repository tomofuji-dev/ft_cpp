#pragma once
#include <stack>
#include <string>
#include <iterator>
#include <iostream>

typedef	std::string::const_iterator	const_str_iter;

class RPN {
	public:
		RPN();
		RPN(const RPN& src);
		~RPN();
		RPN&	operator=(const RPN& rhs);
		int	calc(const std::string input);

	private:
		std::stack<int>		rpnStack_;
		std::string			input_;
		
		bool				is_operator(const char c) const;
		bool				is_valid_token(const char c) const;
		const_str_iter		popFromInput(const_str_iter& it) const;
		int					popFromStack();
		
		int					add(int lhs, int rhs) const;
		int					sub(int lhs, int rhs) const;
		int					mul(int lhs, int rhs) const;
		int					div(int lhs, int rhs) const;
};
