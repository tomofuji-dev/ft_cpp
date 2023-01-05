#include "PhoneBook.hpp"

# define ERR_RANGE			"Invalid range"
# define ERR_KEY			"Invalid key: please enter 'ADD', 'SEARCH', or 'EXIT'"

void	add(PhoneBook *pb) {
	pb->contacts[latest_index % PHONEBOOK_LEN] = new_contact;
	pb->latest_index++;
}

void	search(PhoneBook *pb) {
	std::string	input;
	int			i, index;
	bool		invalid_input = true;

	pb->print_all_contracts();
	while (invalid_input) {
		std::cout << "search index: ";
		std::cin >> input;
		try {
			index = std::stoi(input);
			invalid_input = false;
		}
		catch (const std::invalid_argument& ex) {
			std::cerr << ex.what() << std::endl;
		}
		catch (const std::out_of_range& ex) {
			std::cerr << ex.what() << std::endl;
		}
		if (!(0 <= index && index < PHONEBOOK_LEN)) {
			std::cerr << ERR_RANGE << std::endl;
			invalid_input = true;
		}
	}
	i = (index + pb->latest_index) % PHONEBOOK_LEN;
	pb->contacts[i].print_all_fields();
}

void	prompt() {
	std::string	input;
	bool		invalid_input = true;

	while (invalid_input) {
		std::cout << "command: ";
		std::cin >> input;
		if (!(input == "ADD" || input == "SEARCH" || input == "EXIT")) {
			std::cerr << ERR_KEY << std::endl;
			invalid_input = true;
		}
		else {
			invalid_input = false;
		}
	}
	if (input == "ADD") {
		this->add();
	}
	else if (input == "SEARCH") {
		this->search();
	}
	else {
		return ;
	}
}