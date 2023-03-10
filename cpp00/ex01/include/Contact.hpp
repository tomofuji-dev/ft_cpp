#ifndef CONTACT_H
# define CONTACT_H

# define CONTACT_FIELD_LEN 5

#include <iostream>

class Contact {
private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

public:
	Contact();
	Contact(std::string first_name, \
			std::string last_name, \
			std::string nickname, \
			std::string phone_number, \
			std::string darkest_secret);
	Contact(Contact const & src);
	~Contact();

	Contact &	operator=(Contact const &rhs);

	std::string	get_first_name() const;
	std::string	get_last_name() const;
	std::string	get_nickname() const;
	std::string	get_phone_number() const;
	std::string	get_darkest_secret() const;
	void		print_all_fields() const;
};

#endif