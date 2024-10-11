#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <sstream>
#include <stdexcept>
#include <limits.h>

class ScalarConverter
{
	private:

	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		virtual ~ScalarConverter() = 0;
		ScalarConverter &operator=(const ScalarConverter &src);

		static void convert(const std::string &str);
};

std::string convertToChar(const std::string &str);
std::string convertToInt(const std::string &str);
std::string convertToFloat(const std::string &str);
std::string convertToDouble(const std::string &str);

#endif
