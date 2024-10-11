#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::~Serializer()
{
	std::cout << "Serializer default destructor called" << std::endl;
}

Serializer::Serializer(const Serializer &src)
{
	std::cout << "Serializer copy constructor called" << std::endl;
	*this = src;
}

Serializer &Serializer::operator=(const Serializer &src)
{
	std::cout << "Serializer assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}