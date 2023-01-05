#include "PhoneBook.hpp"

# define INDEX 				0
# define FIRST_NAME 		1
# define LAST_NAME 			2
# define NICKNAME 			3
# define PHONE				4
# define SECRET				5
# define LIST_FIELD_COL 	4
# define FIELD_COL 			6
# define WSIZE 				10
# define ERR_RANGE			"Invalid range"
# define ERR_KEY			"Invalid key: please enter 'ADD', 'SEARCH', or 'EXIT'"

PhoneBook::PhoneBook(): latest_index(0) {
	std::cout << "PhoneBook constructor is called." << std::endl;
	for (int i = 0; i < PHONEBOOK_LEN; i++) {
		this->contacts[i] = Contact();
	}
}

PhoneBook::PhoneBook(PhoneBook const & src): latest_index(src.latest_index) {
	std::cout << "PhoneBook constructor is called." << std::endl;
	for (int i = 0; i < PHONEBOOK_LEN; i++) {
		this->contacts[i] = src.contacts[i];
	}
}

PhoneBook::~PhoneBook() {
	std::cout << "PhoneBook destructor is called." << std::endl;
}

PhoneBook &	PhoneBook::operator=(PhoneBook const &rhs) {
	for (int i = 0; i < PHONEBOOK_LEN; i++) {
		this->contacts[i] = rhs.contacts[i];
	}
	this->latest_index = rhs.latest_index;
	return (*this);
}

void	PhoneBook::prompt() {
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

void	PhoneBook::add() {
	this->contacts[latest_index % PHONEBOOK_LEN] = new_contact;
	this->latest_index++;
}

void	PhoneBook::search() {
	std::string	input;
	int			i, index;
	bool		invalid_input = true;

	this->print_all_contracts();
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
	i = (index + this->latest_index) % PHONEBOOK_LEN;
	this->contacts[i].print_all_fields();
}

void	PhoneBook::print_all_contracts() {
	int i, len;
	std::string contact_field[LIST_FIELD_COL];
	std::string header[LIST_FIELD_COL] = {"index", "first name", "last name", "nickname"};

	print_row(LIST_FIELD_COL, header);
	len = this->latest_index > PHONEBOOK_LEN ? PHONEBOOK_LEN : this->latest_index;
	for (int index = 0; index < len; index++) {
		i = (index + this->latest_index) % PHONEBOOK_LEN;
		contact_field[INDEX] = std::to_string(index);
		contact_field[FIRST_NAME] = this->contacts[i].get_first_name();
		contact_field[LAST_NAME] = this->contacts[i].get_last_name();
		contact_field[NICKNAME] = this->contacts[i].get_nickname();
		print_row(LIST_FIELD_COL, contact_field);
	}
}

static	void	print_row(int n, std::string str[]) {
	for (int i = 0; i < n; i++) {
		std::cout << "|" << std::right << std::setw(WSIZE) << str[i];
	}
	std::cout << "|" << std::endl;
}
