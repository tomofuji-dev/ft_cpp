#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# define PHONEBOOK_LEN 8

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
private:
	Contact	contacts[PHONEBOOK_LEN];
	int	latest_index;

public:
	PhoneBook();
	PhoneBook(PhoneBook const & src);
	~PhoneBook();

	PhoneBook &	operator=(PhoneBook const &rhs);

	void	prompt();
	void	add();
	void	search();
	void	print_all_contracts();
};

#endif