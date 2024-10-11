#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"

class Serializer 
{
	public:
		Serializer();
		virtual ~Serializer() = 0;
		Serializer(const Serializer &src);
		Serializer &operator=(const Serializer &src);

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif