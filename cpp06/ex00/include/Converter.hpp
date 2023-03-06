#ifndef CONVERTER_HPP
#define CONVERTER_HPP
#include <string>

class Converter {
	public:
		static void Convert(const std::string& src);

	private:

		Converter();
        Converter(const Converter& from);
        Converter&  operator=(const Converter &rhs);
        ~Converter();

		static void printConversion(const char& val);
		static void printConversion(const int& val);
		static void printConversion(const float& val);
		static void printConversion(const double& val);

		template<typename T>
		static void printAsChar(T& val);
		template<typename T>
		static void printAsInt(T& val);
		template<typename T>
		static void printAsFloat(T val);
		template<typename T>
		static void printAsDouble(T val);

		static bool isDisplayableChar(const std::string& src);
		static bool isInt(const std::string& src);
		static bool isFloat(const std::string& src);
		static bool isDouble(const std::string& src);
		static bool isFloatingPoint(const std::string& src);

		template<typename T>
		static bool isInterpretableStr(const std::string& src);
		template<typename T>
		static T interpretStr(const std::string& src);
};

#endif
