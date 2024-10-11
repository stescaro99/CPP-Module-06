#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stdint.h>

struct Data
{
	private:
		std::string s1;
		int n;
		std::string s2;

	public:
		Data();
		Data(const std::string &s1, int n, const std::string &s2);
		virtual ~Data();
		Data(const Data &src);
		Data &operator=(const Data &src);

		std::string getS1() const;
		int getN() const;
		std::string getS2() const;
};

#endif