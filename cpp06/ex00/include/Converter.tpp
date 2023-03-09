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
