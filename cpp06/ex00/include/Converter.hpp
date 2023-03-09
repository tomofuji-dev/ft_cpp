#ifndef CONVERTER_HPP
#define CONVERTER_HPP
#include <string>
#include <iostream>
#include <sstream>
#include <float.h>
#include <math.h>
#include "Const.hpp"

class Converter {
	public:
		static void Convert(const std::string& src);

	private:

		Converter();
        Converter(const Converter& from);
        Converter&  operator=(const Converter &rhs);
        ~Converter();

		// template <typename T>
		// static void printConversion(T val);
		static void printConversion(const char& val);
		static void printConversion(const int& val);
		static void printConversion(const float& val);
		static void printConversion(const double& val);

		template<typename T>
		static void printAsChar(T val);
		template<typename T>
		static void printFloatingPointAsChar(T val);
		template<typename T>
		static void printAsInt(T val);
		template<typename T>
		static void printFloatingPointAsInt(T val);
		template<typename T>
		static void printAsFloat(T val, std::streamsize p = PREC_INT);
		template<typename T>
		static void printFloatingPointAsFloat(T val);
		template<typename T>
		static void printAsDouble(T val, std::streamsize p = PREC_INT);
		template<typename T>
		static void printFloatingPointAsDouble(T val);

		static bool	isDisplayableChar(const std::string& src);
		static bool	isInt(const std::string& src);
		static bool	isFloat(const std::string& src);
		static bool	isDouble(const std::string& src);
		static bool	isFloatingPoint(const std::string& src);

		template<typename T>
		static bool	isInterpretableStr(const std::string& src);
		template<typename T>
		static T	interpretStr(const std::string& src);
};

#include "Converter.tpp"
#endif
