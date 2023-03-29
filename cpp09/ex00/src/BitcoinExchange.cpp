#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string dataPath){
	/*
		read dataPath
		for each line:
			try:
				parse_line(line);
			catch(parse_line_error e&): {
				throw("Error: logical error in parsing data.csv");
			}
			if rate <= 0: throw not_pos_double_error
			std::pair<iterator, bool> insert_result = map.insert({date, rate});
			if !insert_result.second: throw insersion_error
	*/
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src){
	*this = src;
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange &rhs){
	if (this != &rhs) {
		rate_ = rhs.rate_;
	}
	return *this;
}

void	BitcoinExchange::api(const std::string inputPath) {
	/*
		read inputPath
		for each line:
			try:
				parse_line(line);
			catch(parse_line_error e&): {
				std::cerr << e.what() << std::endl;
				continue;
			}
			rate = ref_rate(date)
			std::cout << date << " => " << vol << " = " << vol * rate;
	*/
}

void	BitcoinExchange::parse_line(const std::string, std::string date&, double val&) {
	/*
		if (len(line) <= DATE_LEN+DELIM_LEN):
			throw format_err;
		date = parse_date(line[:DATE_LEN])
		# throw format_date_error
		delim = parse_delim(line[DATE_LEN:DATE_LEN+DELIM_LEN])
		# throw format_delim_error if strcmp(" | ", line) == false
		val = parse_double(line[DATE_LEN+DELIM_LEN:])
		# throw format_double_error
		if val <= 0: throw not_pos_double_error
	*/
}

static std::string	read_file(const std::string fname) {
	std::ifstream is(fname);
	if (!is) {
		throw std::string(ERR_OPEN);
	}
	std::stringstream ss;
	ss << is.rdbuf();
	return ss.str();
}
