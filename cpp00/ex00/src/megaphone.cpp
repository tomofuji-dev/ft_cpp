#include <iostream>

bool	ft_islower(int c) {
	return ('a' <= c && c <= 'z');
}

char	ft_get_upper(char c) {
	if (ft_islower(c)) {
		return (c + 'A' - 'a');
	}
	else
		return (c);
}

int	main(int argc, char *argv[]) {
	const char	usage[] = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	if (argc == 1) {
		std::cout << usage << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++) {
		for (int j = 0; argv[i][j] != '\0'; j++) {
			std::cout << ft_get_upper(argv[i][j]);
		}
	}
	std::cout << std::endl;
	return (0);
}
