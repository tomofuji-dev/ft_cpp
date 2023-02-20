#include <iostream>

#define USAGE	"* LOUD AND UNBEARABLE FEEDBACK NOISE *"
#define SUCCESS	0
#define FAILURE	1

int	main(int argc, char *argv[]) {
	if (argc == 1) {
		std::cout << USAGE << std::endl;
		return FAILURE;
	}
	for (int i = 1; i < argc; i++) {
		std::string	s = argv[i];
		for (size_t j = 0; j < s.size(); j++) {
			s[j] = std::toupper(s[j]);
		}
		std::cout << s;
	}
	std::cout << std::endl;
	return SUCCESS;
}
