#pragma once
#include <map>

class BitcoinExchange {

public:

	BitcoinExchange(const std::string dataPath = "./data.csv");
	BitcoinExchange(const BitcoinExchange& src);
	~BitcoinExchange();
	BitcoinExchange&	operator=(const BitcoinExchange& rhs);
	void	api(const std::string inputPath);

private:

	std::map<std::string, double> rate_;
};
