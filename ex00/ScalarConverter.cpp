#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = src;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter default destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	std::cout << "ScalarConverter assignation operator called" << std::endl;
	(void)src;
	return (*this);
}

static bool checkString(const std::string &str)
{
	if (str == "nan" || str == "NaN" || str == "+inff" || str == "+inf" || str == "inff" || str == "inf" || str == "-inff" || str == "-inf")
		return (false);
	if (str.length() > 1 && !isdigit(str[0]) && str[0] != '-' && str[0] != '+')
		return (true);
	if (str.length() > 1)
	{
		int i = 0;
		bool flag = false;
		bool flag2 = false;

		if (str[i] == '-' || str[i] == '+')
			i++;
		while (str[i] && isdigit(str[i]))
			i++;
		if (str[i] && str[i] == '.')
		{
			i++;
			flag = true;
		}
		while (str[i] && isdigit(str[i]))
		{
			i++;
			flag2 = true;
		}
		if (str[i] && str[i] == 'f' && flag2 && flag)
			i++;
		if (str[i] == '\0')
			return (false);
		return (true);
	}
	else if (str[0] < 0 || str[0] > 127)
		return (true);
	return (false);
}

void ScalarConverter::convert(const std::string &str)
{
	std::string s = str;
	if (checkString(str))
	{
		std::cout << "The string is not a valid input please write a char, int, float or double" << std::endl;
		return;
	}
	if (str[str.length() - 1] == 'f' && str.length() > 1)
		s = str.substr(0, str.length() - 1);
	else if (str.find('.') != std::string::npos && str[str.length() - 1] == 'f')
		s = str.substr(0, str.length() - 1);
	else if (str.length() == 1 && isdigit(str[0]))
		s = str[0] -48;

	std::cout << "char: " << convertToChar(s) << std::endl;
	std::cout << "int: " << convertToInt(s) << std::endl;
	std::cout << "float: " << convertToFloat(s) << std::endl;
	std::cout << "double: " << convertToDouble(s) << std::endl;
}

static std::string intToString(int num)
{
	std::ostringstream oss;
	int n = num;

	oss << n;
	return (oss.str());
}
static std::string doubleToString(double num)
{
	std::ostringstream oss;
	double n = num;

	oss << n;
	if (oss.str().find('.') == std::string::npos)
		oss << ".0";
	return (oss.str());
}

static double toDouble(const std::string &str)
{
	double num = 0;
	std::istringstream iss(str);
	iss >> num;
	return (num);
}

static long toInt(const std::string &str)
{
	int num;
	std::istringstream iss(str);
	iss >> num;
	if (iss.fail())
	{
		return 9999999999;
	}
	return (num);
}

std::string convertToChar(const std::string &str)
{
	std::string ret;

	if (str == "nan" || str == "NaN")
		return ("impossible");
	else if (str == "+inff" || str == "+inf" || str == "inff" || str == "inf")
		return ("∞");
	else if (str == "-inff" || str == "-inf")
		return ("-∞");
	else if (str.length() == 1 && !isdigit(str[0]))
	{
		char c = str[0];
		if (c < 0 || c > 127)
			return ("Not an ASCII char");
		else if (c < 32 || c > 126)
			return ("Non displayable");
		std::string ret = "'";
		ret += c;
		ret += "'";
		return (ret);
	}
	else if (str.length() == 1 && isdigit(str[0]))
	{
		return ("Non displayable");
	}
	else
	{
		for (int i = 0; str[i]; i++)
		{
			int j = i;
			while (isdigit(str[j]) || ((str[j]== '-' || str[j] == '+') && j == i))
				j++;
			if (j == i)
				ret += str[i];
			else
			{
				std::string tmp = str.substr(i, j - i);
				int num = toInt(tmp);
				if (num < 0 || num > 127)
					return ("Not an ASCII char");
				else if (num < 32 || num > 126)
					return ("Non displayable");
				ret += "'";
				ret += static_cast<char>(num);
				ret += "'";
				i = j - 1;
				if (str[j] == '.' || str[j] == 'f')
					break;
			}
		}
	}
	return (ret);
}

std::string convertToInt(const std::string &str)
{
	std::string ret;

	if (str == "nan" || str == "NaN")
		return ("impossible");
	else if (str == "+inff" || str == "+inf" || str == "inff" || str == "inf")
		return ("∞");
	else if (str == "-inff" || str == "-inf")
		return ("-∞");
	else if (str.length() == 1 && !isdigit(str[0]))
	{
		int num = static_cast<int>(str[0]);
		return (intToString(num));
	}
	else if (str.length() == 1 && isdigit(str[0]))
		return (intToString(str[0]));
	else if (str[0] == '.')
		return ("0");
	else
	{
		for (int i = 0; str[i]; i++)
		{
			int j = i;
			while (isdigit(str[j]) || ((str[j]== '-' || str[j] == '+') && j == i))
				j++;
			if (j != i)
			{
				std::string tmp = str.substr(i, j - i);
				long num = toInt(tmp);
				if (num > INT_MAX)
					return ("Is out of INT range");
				ret += intToString(num);
				i = j - 1;
			}
			else if (str[i] != '.')
			{
				ret += str[i];
			}
			if (str[i] == '.')
			{
				i++;
				while (isdigit(str[i]) || str[i] == '.')
					i++;
				i--;
			}
		}
	}
	return (ret);
}

std::string convertToFloat(const std::string &str)
{
	std::string ret;

	if (str[0] == '-' && str.length() > 1)
		std::cout << "-";
	if (str == "nan" || str == "NaN")
		return ("nanf");
	else if (str == "+inff" || str == "+inf" || str == "inff" || str == "inf" || str == "-inff" || str == "-inf")
		return ("inff");
	else if (str.length() == 1 && !isdigit(str[0]))
	{
		int num = static_cast<int>(str[0]);
		return (doubleToString(static_cast<float>(num)) + "f");
	}
	else if (str.length() == 1 && isdigit(str[0]))
	{
		int num = static_cast<int>(str[0]);
		return (doubleToString(static_cast<float>(num)) + "f");
	}
	else
	{
		for (int i = 0; str[i]; i++)
		{
			if (str[i] == '-')
				i++;
			int j = i;
			bool flag = true;
			while (isdigit(str[j]) || (str[j] == '.' && j != i && flag))
			{
				if (str[j] == '.')
					flag = false;
				j++;
			}
			if (j != i)
			{
				std::string tmp = str.substr(i, j - i);
				double num = toDouble(tmp);
				ret += doubleToString(static_cast<float>(num)) + "f";
				i = j - 1;
			}
			else if (str[i] != '.' && j == i)
			{
				std::string tmp = "0";
				tmp += str[i];
				double num = toDouble(tmp);
				ret += doubleToString(static_cast<double>(num));
				i = str.length();
			}
		}
	}
	return (ret);
}

std::string convertToDouble(const std::string &str)
{
	std::string ret;

	if (str[0] == '-' && str.length() > 1)
		std::cout << "-";
	if (str == "nan" || str == "NaN")
		return ("nan");
	else if (str == "+inff" || str == "+inf" || str == "inff" || str == "inf" || str == "-inff" || str == "-inf")
		return ("inf");
	else if (str.length() == 1 && !isdigit(str[0]))
	{
		int num = static_cast<int>(str[0]);
		return (doubleToString(static_cast<double>(num)));
	}
	else if (str.length() == 1 && isdigit(str[0]))
	{
		int num = static_cast<int>(str[0]);
		return (doubleToString(static_cast<double>(num)));
	}
	else
	{
		for (int i = 0; str[i]; i++)
		{
			if (str[i] == '-')
				i++;
			int j = i;
			bool flag = true;
			while (isdigit(str[j]) || (str[j] == '.' && j != i && flag))
			{
				if (str[j] == '.')
					flag = false;
				j++;
			}
			if (j != i)
			{
				std::string tmp = str.substr(i, j - i);
				double num = toDouble(tmp);
				ret += doubleToString(static_cast<double>(num));
				i = j - 1;
			}
			else if (str[i] != '.' && j == i)
			{
				std::string tmp = "0";
				tmp += str[i];
				double num = toDouble(tmp);
				ret += doubleToString(static_cast<double>(num));
				i = str.length();
			}
		}
	}
	return (ret);
}