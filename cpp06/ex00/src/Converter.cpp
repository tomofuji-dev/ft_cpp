#include <iostream>
#include <sstream>
#include <float.h>
#include <math.h>
#include "Converter.hpp"
#include "Const.hpp"

void Converter::Convert(const std::string& src) {
	if (isDisplayableChar(src)) {
		if (std::isdigit(src[0]))
			printConversion(std::atoi(&src[0]));
		else
			printConversion(src[0]);
	}
	else if (isInt(src))
		printConversion(interpretStr<int>(src));
	else if (isFloat(src))
		printConversion(interpretStr<float>(src.substr(0, src.size()-1)));
	else if (isDouble(src))
		printConversion(interpretStr<double>(src));
	else
		std::cerr << RED << ERR_INTERP << RESET << std::endl;
}

void Converter::printConversion(const char& val) {
	std::cout << "char: ";		printAsChar(val);
	std::cout << "int: ";		printAsInt(val);
	std::cout << "float: ";		printAsFloat<const char>(val);
	std::cout << "double: ";	printAsDouble<const char>(val);
}

void Converter::printConversion(const int& val) {
	std::cout << "char: ";		printAsChar(val);
	std::cout << "int: ";		printAsInt(val);
	std::cout << "float: ";		printAsFloat<const int>(val);
	std::cout << "double: ";	printAsDouble<const int>(val);
}

void Converter::printConversion(const float& val) {
	std::cout << "char: ";		printFloatingPointAsChar(val);
	std::cout << "int: ";		printFloatingPointAsInt(val);
	std::cout << "float: ";		printFloatingPointAsFloat(val);
	std::cout << "double: ";	printFloatingPointAsDouble(val);
}

void Converter::printConversion(const double& val) {
	std::cout << "char: ";		printFloatingPointAsChar(val);
	std::cout << "int: ";		printFloatingPointAsInt(val);
	std::cout << "float: ";		printFloatingPointAsFloat(val);
	std::cout << "double: ";	printFloatingPointAsDouble(val);
}

template<typename T>
void Converter::printAsChar(T val) {
	char c = static_cast<char>(val);
	if (!(CHAR_MIN <= val && val <= CHAR_MAX)) {
		std::cout << YELLOW << "impossible" << RESET << std::endl;
	}
	else if (!std::isprint(c)) {
		std::cout << YELLOW << "Non displayable" << RESET << std::endl;
	}
	else {
		std::cout << "\'" << c << "\'" << std::endl;
	}
}

template<typename T>
void Converter::printFloatingPointAsChar(T val) {
	if (isnan(val) || isinf(val)) {
		std::cout << YELLOW << "impossible" << RESET << std::endl;
	}
	else {
		printAsChar(val);
	}
}

template<typename T>
void Converter::printAsInt(T val) {
	if (!(INT_MIN <= val && val <= INT_MAX)) {
		std::cout << YELLOW << "impossible" << RESET << std::endl;
	}
	else {
		std::cout << static_cast<int>(val) << std::endl;
	}
}

template<typename T>
void Converter::printFloatingPointAsInt(T val) {
	if (isnan(val) || isinf(val)) {
		std::cout << YELLOW << "impossible" << RESET << std::endl;
	}
	else {
		printAsInt(val);
	}
}

template<typename T>
void Converter::printAsFloat(T val, std::streamsize p) {
	std::cout.precision(p);
	std::cout
		<< std::showpoint
        << std::fixed 
		<< static_cast<float>(val) << "f"
		<< std::defaultfloat
		<< std::endl;
}

template<typename T>
void Converter::printFloatingPointAsFloat(T val) {
	if (isnan(val) || isinf(val)) {
		std::cout << static_cast<float>(val) << "f" << std::endl;
	}
	else if (-FLT_MAX <= val && val <= FLT_MAX) {
		printAsFloat<T>(val, PREC_FLT);
	}
	else {
		std::cout << YELLOW << "impossible" << RESET << std::endl;
	}
}

template<typename T>
void Converter::printAsDouble(T val, std::streamsize p) {
	std::cout.precision(p);
	std::cout
		<< std::showpoint
        << std::fixed 
		<< static_cast<double>(val)
		<< std::defaultfloat
		<< std::endl;
}

template<typename T>
void Converter::printFloatingPointAsDouble(T val) {
	if (isnan(val) || isinf(val)) {
		std::cout << static_cast<double>(val) << std::endl;
	}
	else if (-DBL_MAX <= val && val <= DBL_MAX) {
		printAsDouble<T>(val, PREC_DBL);
	}
	else {
		std::cout << YELLOW << "impossible" << RESET << std::endl;
	}
}

// non-displayable char is false
bool Converter::isDisplayableChar(const std::string& src) {
	if (src.size() != 1) return false;
	return std::isprint(src[0]);
}

bool Converter::isInt(const std::string& src) {
	size_t i = 0;

	if (src[0] == '-' || src[0] == '+') i++;
	for (; i < src.size(); i++) {
		if (!std::isdigit(src[i])) return false;
	}
	return isInterpretableStr<int>(src);
}

bool Converter::isFloat(const std::string& src) {
	const size_t		len = src.size();

	if (len < 2 || src[len - 1] != 'f') return false;
	std::string trimf = src.substr(0, src.size() - 1);
	return isFloatingPoint(trimf) && isInterpretableStr<float>(trimf);
}

bool Converter::isDouble(const std::string& src) {
	return isFloatingPoint(src) && isInterpretableStr<double>(src);
}

bool Converter::isFloatingPoint(const std::string& src) {
	size_t i = 0;
	bool dot = false;

	if (src == "nan" || src == "+nan" || src == "-nan") return true;
	if (src == "inf" || src == "+inf" || src == "-inf") return true;

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

template<typename T>
bool Converter::isInterpretableStr(const std::string& src) {
	std::stringstream ss(src);
	T dest;
	ss >> dest;
	return !ss.fail();
}

template<typename T>
T Converter::interpretStr(const std::string& src) {
	std::stringstream ss(src);
	T dest;
	ss >> dest;
	return dest;
}
