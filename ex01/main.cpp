#include "Serializer.hpp"

int main()
{
	Data data("Hello", 42, "World");
	uintptr_t serialized = Serializer::serialize(&data);
	Data *deserialized = Serializer::deserialize(serialized);
	std::cout << "deserialized: " << deserialized << std::endl;
	std::cout << "s1: " << deserialized->getS1() << std::endl;
	std::cout << "n: " << deserialized->getN() << std::endl;
	std::cout << "s2: " << deserialized->getS2() << std::endl;
	std::cout << "serialized: " << serialized << std::endl;
	return 0;
}