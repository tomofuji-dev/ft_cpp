#include "BitcoinExchange.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <ctime>

BitcoinExchange::BitcoinExchange() {
	std::ifstream file(DATA_PATH);
	assert_ifstream(file);
	assert_header(file, HEAD_DATA);

	std::string	line;
	std::string	date;
	double		val;
	std::pair<std::map<std::string, double>::iterator, bool> insert_result;

	while (std::getline(file, line)) {
		try {
			parse_line(line, DELIM_DATA, date, val);
		} 
		catch (std::runtime_error& e) {
			throw std::runtime_error(ERR_DATA_CSV);
		}
		if (val < 0) {
			throw std::runtime_error(ERR_DATA_CSV);
		}
		std::pair<std::string, double> entry(date, val);
		insert_result = rate_.insert(entry);
		if (!insert_result.second) {
			throw std::runtime_error(ERR_DATA_CSV);
		}
	}
	file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {
	*this = src;
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& rhs) {
	if (this != &rhs) {
		rate_ = rhs.rate_;
	}
	return *this;
}

void	BitcoinExchange::api(const std::string& inputPath) const {
	std::ifstream file(inputPath);
	assert_ifstream(file);
	assert_header(file, HEAD_INPUT);

	std::string	line;
	std::string	date;
	double		vol, rate;
	std::pair<std::map<std::string, double>::iterator, bool> insert_result;

	while (std::getline(file, line)) {
		try {
			parse_line(line, DELIM_INPUT, date, vol);
		} 
		catch (std::runtime_error& e) {
			std::cerr << e.what() << std::endl;
			continue;
		}
		if (vol <= 0) {
			std::cerr << ERR_NOT_POS << std::endl;
			continue;
		}
		rate = ref_rate(date);
		std::cout << date << " => " << vol << " = " << vol * rate << std::endl;
	}
	file.close();
}

double	BitcoinExchange::ref_rate(const std::string& date) const {
	std::map<std::string, double>::const_iterator it = rate_.lower_bound(date);

	if (it != rate_.end() && it->first == date) {
		return it->second;
	}

	if (it != rate_.begin()) {
		--it;
		return it->second;
	}

	throw std::runtime_error(ERR_KEY);
}

void	BitcoinExchange::parse_line(const std::string& line, const std::string& delim, \
										std::string& date, double& val)
{
	if (line.length() <= LEN_DATE + delim.length()) {
		throw std::runtime_error(ERR_LINE_FORM);
	}
	parse_date(date, line.substr(0, LEN_DATE));
	assert_delim(line.substr(LEN_DATE, delim.length()), delim);
	parse_double(val, line.substr(LEN_DATE + delim.length()));
}

void BitcoinExchange::parse_date(std::string& dst, const std::string& src) {
	struct tm tm;
	std::istringstream ss(src);
	if (strptime(src.c_str(), FORM_DATE, &tm) == NULL) {
		throw std::runtime_error(ERR_DATE);
	}
	dst = src;
}

void BitcoinExchange::assert_delim(const std::string& str, const std::string& delim) {
	if (str != delim) {
		throw std::runtime_error(ERR_LINE_FORM);
	}
}

void BitcoinExchange::parse_double(double& dst, const std::string& src) {
	if (!isFloatingPoint(src)) {
		throw std::runtime_error(ERR_DOUBLE);
	}
	std::stringstream ss(src);
	ss >> dst;
	if (ss.fail()) {
		throw std::runtime_error(ERR_DOUBLE);
	}
}

bool BitcoinExchange::isFloatingPoint(const std::string& src) {
	size_t i = 0;
	bool dot = false;

	if (src[0] == '-' || src[0] == '+') i++;
	for (; i < src.size(); i++) {
		if (!std::isdigit(src[i])) {
			if (src[i] != '.') return false;
			if (dot) return false;
			dot = true;
		}
	}
	return true;
}

void	BitcoinExchange::assert_ifstream(const std::ifstream& file) {
	if (!file) {
		throw std::runtime_error(ERR_OPEN);
	}
	if (file.fail()) {
		throw std::runtime_error(ERR_READ);
	}
}

void	BitcoinExchange::assert_header(std::ifstream& file, const std::string header) {
	std::string	line;
	if (!std::getline(file, line)) {
		throw std::runtime_error(ERR_READ);
	}
	if (line != header) {
		throw std::runtime_error(ERR_HEADER);
	}
}
