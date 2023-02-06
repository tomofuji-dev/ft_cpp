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

# define SUCCESS 			0
# define FAILURE 			1

# define ERR_RANGE			"Invalid range"
# define ERR_PHONE			"Phone number must all digit."
# define ERR_KEY			"Invalid key: please enter 'ADD', 'SEARCH', or 'EXIT'"

PhoneBook::PhoneBook(): latest_index(0) {
	for (int i = 0; i < PHONEBOOK_LEN; i++) {
		this->contacts[i] = Contact();
	}
}

PhoneBook::PhoneBook(PhoneBook const & src): latest_index(src.latest_index) {
	for (int i = 0; i < PHONEBOOK_LEN; i++) {
		this->contacts[i] = src.contacts[i];
	}
}

PhoneBook::~PhoneBook() {
}

PhoneBook &	PhoneBook::operator=(PhoneBook const &rhs) {
	for (size_t i = 0; i < PHONEBOOK_LEN; i++) {
		this->contacts[i] = rhs.contacts[i];
	}
	this->latest_index = rhs.latest_index;
	return *this;
}

static	void	print_row(int n, std::string str[]) {
	for (int i = 0; i < n; i++) {
		std::cout << "|" << std::right << std::setw(WSIZE) << str[i];
	}
	std::cout << "|" << std::endl;
}

static bool	is_all_digit(std::string str) {
	for (size_t i=0; i < str.size(); i++) {
		if (!('0' <= str[i] && str[i] <= '9'))
			return (false);
	}
	return (true);
}

void	PhoneBook::prompt() {
	std::string	input;

	while (true) {
		std::cout << "command: ";
		if (!std::getline(std::cin, input)) {
			continue ;
		};
		if (input == "ADD") {
			this->add();
		}
		else if (input == "SEARCH") {
			this->search();
		}
		else if (input == "EXIT") {
			return ;
		}
		else {
			std::cerr << ERR_KEY << std::endl;
		}
	}
}

void	PhoneBook::add() {
	std::string	first_name, last_name, nickname, phone_number, darkest_secret;

	while (true) {
		std::cout << "first name: ";
		if (!std::getline(std::cin, first_name)) {
			continue ;
		};
		std::cout << "last name: ";
		if (!std::getline(std::cin, last_name)) {
			continue ;
		};
		std::cout << "nickname: ";
		if (!std::getline(std::cin, nickname)) {
			continue ;
		};
		std::cout << "phone number: ";
		if (!std::getline(std::cin, phone_number)) {
			continue ;
		};
		if (!is_all_digit(phone_number)) {
			std::cerr << ERR_PHONE << std::endl;
			continue ;
		}
		std::cout << "darkest secret: ";
		if (!std::getline(std::cin, darkest_secret)) {
			continue ;
		};
		break ;
	}
	this->contacts[this->latest_index % PHONEBOOK_LEN] \
		= Contact(first_name, last_name, nickname, phone_number, darkest_secret);
	this->latest_index++;
}

void	PhoneBook::search() {
	std::string	input;
	int			index;
	size_t		start;
	bool		invalid_input = true;

	if (this->latest_index == 0) {
		std::cout << "no record in phonebook." << std::endl;
		return ;
	}
	while (invalid_input) {
		this->print_all_contacts();
		std::cout << "search index: ";
		if (!std::getline(std::cin, input)) {
			continue ;
		};
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
	start = this->latest_index <= PHONEBOOK_LEN ? 0 : this->latest_index % PHONEBOOK_LEN;
	this->contacts[((index + start) % PHONEBOOK_LEN)].print_all_fields();
}

void	PhoneBook::print_all_contacts() {
	size_t index, len, start;
	std::string contact_field[LIST_FIELD_COL];
	std::string header[LIST_FIELD_COL] = {"index", "first name", "last name", "nickname"};

	print_row(LIST_FIELD_COL, header);
	len = this->latest_index <= PHONEBOOK_LEN ? this->latest_index : PHONEBOOK_LEN;
	start = this->latest_index <= PHONEBOOK_LEN ? 0 : this->latest_index % PHONEBOOK_LEN;
	std::cout << "start: " << start << std::endl;
	for (size_t i = 0; i < len; i++) {
		index = (start + i) % PHONEBOOK_LEN;
		contact_field[INDEX] = std::to_string(i);
		contact_field[FIRST_NAME] = this->contacts[index].get_first_name();
		contact_field[LAST_NAME] = this->contacts[index].get_last_name();
		contact_field[NICKNAME] = this->contacts[index].get_nickname();
		print_row(LIST_FIELD_COL, contact_field);
	}
}
