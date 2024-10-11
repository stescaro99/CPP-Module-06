#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	for (int i = 0; i < 5; i++)
	{
		std::cout << "\033[3" << i + 1 << "m";
		std::cout << "Generate: " << i + 1 << std::endl;
		Base * base = generate();
		std::cout << "Identify from pointer: " << i + 1 << std::endl;
		identify(base);
		std::cout << "Identify from reference: " << i + 1 << std::endl;
		identify(*base);
		delete base;
		std::cout << "\033[0m";
	}	
	return 0;
}