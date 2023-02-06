#include "Contact.hpp"

Contact::Contact(): first_name(std::string()), \
						last_name(std::string()), \
						nickname(std::string()), \
						phone_number(std::string()), \
						darkest_secret(std::string()){
}

Contact::Contact(std::string first_name, \
				std::string last_name, \
				std::string nickname, \
				std::string phone_number, \
				std::string darkest_secret): \
										first_name(first_name), \
										last_name(last_name), \
										nickname(nickname), \
										phone_number(phone_number), \
										darkest_secret(darkest_secret){
}

Contact::Contact(Contact const & src): first_name(src.get_first_name()), \
										last_name(src.get_last_name()), \
										nickname(src.get_nickname()), \
										phone_number(src.get_phone_number()), \
										darkest_secret(src.get_darkest_secret()) {
}

Contact::~Contact() {
}

Contact &	Contact::operator=(Contact const &rhs) {
	this->first_name = rhs.get_first_name();
	this->last_name = rhs.get_last_name();
	this->nickname = rhs.get_nickname();
	this->phone_number = rhs.get_phone_number();
	this->darkest_secret = rhs.get_darkest_secret();
	return *this;
}

std::string	Contact::get_first_name() const {
	return this->first_name;
}

std::string	Contact::get_last_name() const {
	return this->last_name;
}

std::string	Contact::get_nickname() const {
	return this->nickname;
}

std::string	Contact::get_phone_number() const {
	return this->phone_number;
}

std::string	Contact::get_darkest_secret() const {
	return this->darkest_secret;
}

void Contact::print_all_fields() const {
	std::cout << "    first name :" << this->first_name << std::endl;
	std::cout << "     last name :" << this->last_name << std::endl;
	std::cout << "      nickname :" << this->nickname << std::endl;
	std::cout << "  phone number :" << this->phone_number << std::endl;
	std::cout << "darkest secret :" << this->darkest_secret << std::endl;
}
