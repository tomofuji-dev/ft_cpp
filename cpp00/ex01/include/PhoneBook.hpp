#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# define PHONEBOOK_LEN 8

#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"

class PhoneBook {
private:
	Contact	contacts[PHONEBOOK_LEN];
	size_t	latest_index;

	void			add();
	void			search();
	void			print_all_contacts();

public:
	PhoneBook();
	PhoneBook(PhoneBook const & src);
	~PhoneBook();

	PhoneBook&	operator=(PhoneBook const &rhs);
	void		prompt();
};

#endif