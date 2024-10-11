#include "Data.hpp"

Data::Data() : s1(""), n(0), s2("") 
{
	std::cout << "Data default constructor called" << std::endl;
}

Data::Data(const std::string &s1, int n, const std::string &s2) : s1(s1), n(n), s2(s2)
{
	std::cout << "Data constructor called" << std::endl;
}

Data::~Data()
{
	std::cout << "Data default destructor called" << std::endl;
}

Data::Data(const Data &src) : s1(src.s1), n(src.n), s2(src.s2)
{
	std::cout << "Data copy constructor called" << std::endl;
}

Data &Data::operator=(const Data &src)
{
	std::cout << "Data assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	s1 = src.s1;
	n = src.n;
	s2 = src.s2;
	return *this;
}

std::string Data::getS1() const
{
	return s1;
}

int Data::getN() const
{
	return n;
}

std::string Data::getS2() const
{
	return s2;
}