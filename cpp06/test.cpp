#include <iostream>
#include <sstream>
#include "./include/Const.hpp"
#define N 52

template<typename T>
void show_cast(std::string str) {

	std::stringstream ss(str);
	T  d;
	
	ss >> d;
	if (!ss.fail()) {
		std::cout << GREEN << d << RESET;
	}
	else {
		std::cout << RED << " fail" << RESET;
	}
}

int main(void) {
	double test = std::numeric_limits<float>::quiet_NaN();
	std::cout << static_cast<int>(test) << std::endl;
	test = std::numeric_limits<float>::infinity();
	std::cout << static_cast<int>(test) << std::endl;
	std::string argv[N] = {
		"a",
		"01",
		"\a",
		"\v",
		"3.f",
		".1f",
		"3.141592656359798f",
		"3.141592656359798F",
		"+3.141592656359798f",
		"+3.141592656359798F",
		"3.",
		".1",
		"3.141592656359798",
		"+3.141592656359798",
		"-3.141592656359798",
		"0",
		"2147483647",
		"+2147483647",
		"-2147483647",
		"-2147483648",
		"2147483648",
		"+2147483648",
		"inff",
		"-inff",
		"+inff",
		"nanf",
		"inf",
		"-inf",
		"+inf",
		"nan",
		"+",
		"-",
		"+.",
		"+.",
		"-.",
		".+",
		".-",
		".",
		"+.0",
		"-.0",
		"+0.",
		"-0.",
		"+-0.",
		"++0.",
		"-+0.",
		"--0.",
		"+-.1",
		"++.1",
		"-+.1",
		"--.1",
		"a",
		"'a'"
	};
	for (int i = 0; i < N; i++) {
		std::cout << YELLOW << argv[i] << RESET << std::endl;
		std::cout << "    int: ";		show_cast<int>(argv[i]);	std::cout << std::endl;
		std::cout << "    float: ";		show_cast<float>(argv[i]);	std::cout << std::endl;
		std::cout << "    double: ";	show_cast<double>(argv[i]);	std::cout << std::endl;
	}
	return 0;
}
