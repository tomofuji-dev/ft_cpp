#include <iostream>
#include <sstream>

#define BLACK	"\e[0;30m" // Black - Regular
#define RED		"\e[0;31m" // Red
#define GREEN	"\e[0;32m" // Green
#define YELLOW	"\e[0;33m" // Yellow
#define BLUE	"\e[0;34m" // Blue
#define PURPLE	"\e[0;35m" // Purple
#define CYAN	"\e[0;36m" // Cyan
#define WHITE	"\e[0;37m" // White
#define RESET 	"\e[0m" 

#define N 48

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
	std::string argv[N] = {
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
}
