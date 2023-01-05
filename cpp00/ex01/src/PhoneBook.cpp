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
