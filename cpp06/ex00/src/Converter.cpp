#include "Converter.hpp"
#include "Const.hpp"

void Converter::Convert(const std::string& src) {
	if (isDisplayableChar(src))
		printConversion(src[0]);
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

// digit char is false ('1' ... '9')
bool Converter::isDisplayableChar(const std::string& src) {
	if (src.size() != 1) return false;
	return !std::isdigit(src[0]) && std::isprint(src[0]);
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
