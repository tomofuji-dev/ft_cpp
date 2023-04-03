#pragma once
#include <map>
#include <fstream>

#define DATA_PATH		"./data.csv"
#define SUCCESS			0
#define FAILURE			1
#define LEN_DATE		10
#define DELIM_DATA		","
#define DELIM_INPUT		" | "
#define HEAD_DATA		"date,exchange_rate"
#define HEAD_INPUT		"date | value"
#define FORM_DATE		"%Y-%m-%d"

#define ERR_ARGC		"Error: argc is invalid"
#define ERR_OPEN		"Error: could not open file"
#define ERR_READ		"Error: could not read file"
#define ERR_DATA_CSV	"Error: error in data.csv"
#define ERR_LINE_FORM	"Error: error about line form in input.txt"
#define ERR_NOT_POS		"Error: not a positive number"
#define ERR_DOUBLE		"Error: bad input for double"
#define ERR_DATE		"Error: bad input for date"
#define ERR_KEY			"Error: input key has no lower bound"
#define ERR_HEADER		"Error: bad header"

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& src);
		~BitcoinExchange();
		BitcoinExchange&	operator=(const BitcoinExchange& rhs);
		void	api(const std::string& inputPath) const;

	private:
		std::map<std::string, double> rate_;
		
		double		ref_rate(const std::string& date) const;
		static void	parse_line(const std::string& line, const std::string& delim, \
								std::string& date, double& val);
		static void parse_date(std::string& dst, const std::string& src);
		static void assert_delim(const std::string& str, const std::string& delim);
		static void parse_double(double& dst, const std::string& src);
		static bool isFloatingPoint(const std::string& src);
		static void	assert_ifstream(const std::ifstream& file);
		static void assert_header(std::ifstream& file, const std::string header);
};
